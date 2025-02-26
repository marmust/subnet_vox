#define ASIO_STANDALONE
#include <iostream>
#include "asio.hpp"

#define BROADCAST_PORT 2223

int main() {
    try {
        asio::io_context io_context;
        asio::ip::udp::socket socket(io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), BROADCAST_PORT));

        char buffer[1024];
        asio::ip::udp::endpoint sender_endpoint;

        std::cout << "Listening for broadcast messages on port " << BROADCAST_PORT << "...\n";

        while (true) {
            std::size_t len = socket.receive_from(asio::buffer(buffer), sender_endpoint);
            std::string received_message(buffer, len);
            
            std::cout << "Received from " << sender_endpoint.address().to_string() << ": " << received_message << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
