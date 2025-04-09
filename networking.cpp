#include "networking.h"

/////////////////////////////// Broadcaster ///////////////////////////////

// ctor
// input: broadcastPort int
// output: none
Broadcaster::Broadcaster(const int broadcastPort)
{
    this->_broadcastPort = broadcastPort;
}

// dtor
// input: none
// output: none
Broadcaster::~Broadcaster()
{
    // nothing to delete, std handles its own memory (only int in class)
}

// broadcastMessage
// input: message Message
// output: none
void Broadcaster::broadcastMessage(const Message message) const
{
    try
    {
        asio::io_context io_context;
        asio::ip::udp::socket socket(io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0));
        
        // Enable broadcast option
        socket.set_option(asio::socket_base::broadcast(true));
        //socket.set_option(asio::ip::multicast::hops(5));

        asio::ip::udp::endpoint broadcast_endpoint(asio::ip::make_address(BROADCAST_IP), _broadcastPort);

        socket.send_to(asio::buffer(message.encodeForBroadcast()), broadcast_endpoint);
    }
    catch (std::exception& e)
    {
        std::cerr << "UDP BROADCAST FAILED >>> " << e.what() << std::endl;
    }
}

/////////////////////////////// receiver ///////////////////////////////

// ctor
// input: recievePort int
// output: none
Receiver::Receiver(const int receivePort)
    : _recievePort(receivePort), _socket(_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), receivePort)) 
{
    // on linux u can use multiple on the same computer
    #ifndef _WIN32
        _socket.set_option(asio::socket_base::reuse_address(true));
        
        #ifdef __linux__
            int native_socket = _socket.native_handle();
            int reuse = 1;
            if (setsockopt(native_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
                perror("setsockopt(SO_REUSEADDR) failed");
            }
            if (setsockopt(native_socket, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) < 0) {
                perror("setsockopt(SO_REUSEPORT) failed");
            }
        #endif
    #endif

    asio::ip::address multicast_address = asio::ip::make_address(BROADCAST_IP);
    _socket.set_option(asio::ip::multicast::join_group(multicast_address));
}

// dtor
// input: none
// output: none
Receiver::~Receiver()
{
    // delete the queue
    while (!_messageQueue.empty())
    {
        delete _messageQueue.front();
        _messageQueue.pop();
    }
}

// function to parse a received UDP broadcast into its components (thats the part that abides by the protocol)
// input: udpData (the full received broadcast), name (reference to fill with sender's name), content (reference to fill with message content)
// output: none
void Receiver::parseMessage(const std::string& udpData, std::string& name, std::string& content)
{
    if (udpData.empty()) {
        std::cerr << "Received empty message, ignoring." << std::endl;
        name = "Unknown";
        content = "";
        return;
    }

    size_t firstSplit = udpData.find(FIELD_SPLITTER);
    if (firstSplit == std::string::npos) {
        std::cerr << "Message parsing failed: No field splitter found." << std::endl;
        name = "Unknown";
        content = udpData; // Preserve the message if it’s not formatted correctly
        return;
    }

    size_t secondSplit = udpData.find(FIELD_SPLITTER, firstSplit + strlen(FIELD_SPLITTER));
    if (secondSplit == std::string::npos) {
        std::cerr << "Message parsing failed: Only one field splitter found." << std::endl;
        name = "Unknown";
        content = udpData; // Again, preserve the data
        return;
    }

    // Extract name and content safely
    name = udpData.substr(0, firstSplit);
    
    if (secondSplit + strlen(FIELD_SPLITTER) < udpData.size()) {
        content = udpData.substr(secondSplit + strlen(FIELD_SPLITTER));
    } else {
        content = ""; // Avoid out-of-range error
    }
}

// function to wait for a UDP broadcast and fill a message object with it
// input: message Message
// output: none
void Receiver::catchMessage(Message &message)
{
    char buffer[RECV_BUFFER_SIZE];
    asio::ip::udp::endpoint sender_endpoint;

    while (true)
    {
        // note: we dont pass on our own messages (loopback traffic) so they also get shown in the chat

        std::size_t len = _socket.receive_from(asio::buffer(buffer), sender_endpoint);
        std::string received_message(buffer, len);
        std::string senderIP = sender_endpoint.address().to_string();

        std::string senderName, messageContent;
        parseMessage(received_message, senderName, messageContent);
      
        message = Message(messageContent, senderName, senderIP);
        return;
    }
}

// function to continously listen for UDP broadcasts and fill a message queue with them (meant to run in thread)
// input: messageQueue queue<Message>
// output: none
void Receiver::listen()
{
    while (true)
    {
        Message* message = new Message("", "", ""); // Placeholder message

        catchMessage(*message); // This will block until a valid message is received

        std::lock_guard<std::mutex> lock(this->_messageQueueMutex);
        this->_messageQueue.push(message);
    }
}

// function to get the next message from the queue (thread secure with instance's mutex)
// input: none
// output: message Message
Message* Receiver::getQueueMessage()
{
    std::lock_guard<std::mutex> lock(_messageQueueMutex);

    if (_messageQueue.empty())
    {
        return NULL;
    }

    Message* message = _messageQueue.front();
    _messageQueue.pop();

    return message;
}