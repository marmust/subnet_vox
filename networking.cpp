#include "networking.h"

/////////////////////////////// Broadcaster ///////////////////////////////

// ctor
// input: broadcastPort int
// output: none
Broadcaster::Broadcaster(const int broadcastPort)
{
    this->_broadcastPort = broadcastPort;
    std::cout << "BROADCASTER >>> ONLINE!         PORT: " << this->_broadcastPort << std::endl;
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
    determineLocalIP(); // Get local IP

    #ifndef _WIN32
        _socket.set_option(asio::socket_base::reuse_address(true));
    #endif

    asio::ip::address multicast_address = asio::ip::make_address(BROADCAST_IP);
    _socket.set_option(asio::ip::multicast::join_group(multicast_address));

    std::cout << "RECEIVER >>> ONLINE!         PORT: " << this->_recievePort << " MULTICAST: " << BROADCAST_IP << std::endl;
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

void Receiver::determineLocalIP()
{
    try
    {
        asio::io_context io_context;
        asio::ip::tcp::resolver resolver(io_context);
        asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(asio::ip::host_name(), "");

        for (const auto& entry : endpoints)
        {
            asio::ip::address addr = entry.endpoint().address();
            if (addr.is_v4() && !addr.is_loopback()) // Filter out IPv6 and loopback
            {
                _localIP = addr.to_string();
                break;
            }
        }

        if (_localIP.empty()) // Fallback to loopback if no valid IP found
            _localIP = "127.0.0.1";

        std::cout << "LOCAL IP DETERMINED >>> " << _localIP << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "FAILIURE TO DETERMINE LOCAL IP >>> " << e.what() << std::endl;
        _localIP = "127.0.0.1"; // Default fallback
    }
}

// function to parse a received UDP broadcast into its components (thats the part that abides by the protocol)
// input: udpData (the full received broadcast), name (reference to fill with sender's name), content (reference to fill with message content)
// output: none
void Receiver::parseMessage(const std::string& udpData, std::string& name, std::string& content)
{
    size_t firstSplit = udpData.find(FIELD_SPLITTER);
    size_t secondSplit = udpData.find(FIELD_SPLITTER, firstSplit + 3);

    if (firstSplit != std::string::npos && secondSplit != std::string::npos)
    {
        name = udpData.substr(0, firstSplit);
        content = udpData.substr(secondSplit + 3);
    }
    else
    {
        std::cerr << "Message parsing failed: invalid format." << std::endl;
        name = "Unknown";
        content = udpData;
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
        std::size_t len = _socket.receive_from(asio::buffer(buffer), sender_endpoint);
        std::string received_message(buffer, len);
        std::string senderIP = sender_endpoint.address().to_string();

        if (senderIP == _localIP) // Ignore own broadcasts
            continue;

            
        std::string senderName, messageContent;
        parseMessage(received_message, senderName, messageContent);
            
        std::cout << "Received from " << sender_endpoint.address().to_string()
                  << " [" << senderName << "]: " << messageContent << std::endl;
      
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