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
    : _recievePort(receivePort), _socket(_io_context) {

    // Open the socket
    _socket.open(asio::ip::udp::v4());

    #ifdef _WIN32
        // Windows requires SO_EXCLUSIVEADDRUSE instead of SO_REUSEADDR
        _socket.set_option(asio::detail::socket_option::boolean<SOL_SOCKET, SO_EXCLUSIVEADDRUSE>(true));
    #else
        // On Linux/macOS, allow multiple sockets to bind
        _socket.set_option(asio::socket_base::reuse_address(true));
    #endif

    _socket.bind(asio::ip::udp::endpoint(asio::ip::udp::v4(), _recievePort));

    std::cout << "Receiver initialized on port " << _recievePort << std::endl;
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

// function to wait for a UDP broadcast and fill a message object with it
// input: message Message
// output: none
void Receiver::catchMessage(Message &message)
{
    char buffer[RECV_BUFFER_SIZE];
    asio::ip::udp::endpoint sender_endpoint;

    std::size_t len = _socket.receive_from(asio::buffer(buffer), sender_endpoint);
    std::string received_message(buffer, len);

    std::cout << "Received from " << sender_endpoint.address().to_string() << ": " << received_message << std::endl;

    message = Message(received_message, "Unknown", sender_endpoint.address().to_string());
}

// function to continously listen for UDP broadcasts and fill a message queue with them (meant to run in thread)
// input: messageQueue queue<Message>
// output: none
void Receiver::listen() {
    char buffer[RECV_BUFFER_SIZE];
    asio::ip::udp::endpoint sender_endpoint;

    while (true)
    {
        std::size_t len = _socket.receive_from(asio::buffer(buffer), sender_endpoint);
        std::string received_message(buffer, len);

        std::cout << "Received from " << sender_endpoint.address().to_string() << ": " << received_message << std::endl;

        std::lock_guard<std::mutex> lock(this->_messageQueueMutex);
        Message* message = new Message(received_message, "Unknown", sender_endpoint.address().to_string());
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