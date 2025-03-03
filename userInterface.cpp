#include "userInterface.h"

// ctor
// input: receiver, broadcaster, graphicsEngine objects to use
// output: none
UserInterface::UserInterface(Receiver& receiver, Broadcaster& broadcaster, GraphicsEngine& graphicsEngine, std::string username)
    : _receiver(receiver), _broadcaster(broadcaster), _graphicsEngine(graphicsEngine), _username(username)
{
    std::thread recieveThread(&Receiver::listen, &this->_receiver);
    recieveThread.detach();
}

// dtor
// input: none
// output: none
UserInterface::~UserInterface()
{
    // nothing to do here
}

// function to continously recieve messages and write them to console (meant to run on auxillery thread)
// input: none
// output: none
void UserInterface::continousRecieve()
{
    bool reserveSpace = true;

    while (true)
    {
        Message* currentMessage = this->_receiver.getQueueMessage();

        if (currentMessage == NULL)
        {
            continue;
        }

        // add message to graphics engine
        _graphicsEngine.addMessage(currentMessage->getContent());

        // print all messages
        _graphicsEngine.printAllMessages(reserveSpace);
        reserveSpace = false;
    }
}

// function to continously broadcast messages inputted by the user (meant to run on main thread)
// input: none
// output: none
void UserInterface::continousBroadcast()
{
    while (true)
    {
        // input string
        std::string input;
        std::getline(std::cin, input);

        // go up a line
        std::cout << "\033[A";

        // clear the line
        std::cout << "\033[K";

        // broadcast message
        Message message(input, this->_username, OUTBOUND_MESSAGE_REPORTED_IP);
        _broadcaster.broadcastMessage(message);
    }
}