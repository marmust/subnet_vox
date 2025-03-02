#define ASIO_STANDALONE
#include <asio.hpp>
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

#define BROADCAST_IP "239.255.255.250"
#define BROADCAST_PORT 2223
#define FIELD_SPLITTER "///"

std::string getRandomString(size_t length) {
    static const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> distrib(0, chars.size() - 1);
    
    std::string result;
    for (size_t i = 0; i < length; ++i) {
        result += chars[distrib(gen)];
    }
    return result;
}

void sendDecoyMessages() {
    try {
        asio::io_context io_context;
        asio::ip::udp::socket socket(io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), 0));
        socket.set_option(asio::socket_base::broadcast(true));
        asio::ip::udp::endpoint broadcast_endpoint(asio::ip::make_address(BROADCAST_IP), BROADCAST_PORT);

        while (true) {
            std::string senderName = getRandomString(8);
            std::string messageContent = getRandomString(20);
            std::string fullMessage = senderName + FIELD_SPLITTER + "000.000.000.000" + FIELD_SPLITTER + messageContent;
            
            socket.send_to(asio::buffer(fullMessage), broadcast_endpoint);
            std::cout << "Sent decoy message: " << fullMessage << std::endl;

            std::this_thread::sleep_for(std::chrono::seconds(2)); // Send every 2 seconds
        }
    } catch (const std::exception& e) {
        std::cerr << "Error in decoy sender: " << e.what() << std::endl;
    }
}

int main() {
    sendDecoyMessages();
    return 0;
}