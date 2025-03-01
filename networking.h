#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ip/host_name.hpp>
#include <asio/ip/tcp.hpp>
#include <iostream>
#include <queue>
#include <mutex>
#include "message.h"

#define BROADCAST_PORT 2223
#define BROADCAST_IP "239.255.255.250"
#define RECV_BUFFER_SIZE 8192

class Broadcaster
{
private:
    int _broadcastPort;

public:
    Broadcaster(const int broadcastPort);
    virtual ~Broadcaster();

    void broadcastMessage(const Message message) const;
};

class Receiver
{
private:
    int _recievePort;
    std::queue<Message*> _messageQueue;
    std::mutex _messageQueueMutex;

    asio::io_context _io_context; // Keep io_context alive
    asio::ip::udp::socket _socket; // Single socket for reuse

public:
    Receiver(const int recievePort);
    virtual ~Receiver();
    void parseMessage(const std::string& udpData, std::string& name, std::string& content);
    void catchMessage(Message &message);
    void listen();

    Message* getQueueMessage();
};