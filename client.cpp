#include <iostream>
#include "networking.h"

int main()
{
    Broadcaster* testbroadcaster = new Broadcaster(2223);
    Receiver* testreceiver = new Receiver(2223);

    // launch a thread with testreciever's listen
    std::thread listenThread(&Receiver::listen, testreceiver);

    // send messages based on user's input
    std::string input;
    while (true)
    {
        std::cout << "Enter a message to broadcast: ";
        std::getline(std::cin, input);

        Message message(input, "TestUser", "123.123.123.123");
        testbroadcaster->broadcastMessage(message);
    }

    return 0;
}