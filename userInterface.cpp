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
        _graphicsEngine.addMessage(*currentMessage);

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
    GraphicsEngine::disableEcho();  // Prevent automatic newline issues
    while (true)
    {
        std::string input;
        char ch;

        while (true)
        {
            #ifdef _WIN32
                        ch = _getch();  // Windows input without buffering
                        if (ch == '\r') break;  // Enter (carriage return)
            #else
                        ch = getchar();  // Linux/macOS real-time input
                        if (ch == '\n') break;  // Enter (newline)
            #endif

            if (ch == 8 || ch == 127) { // Handle backspace (Windows: 8, Linux: 127)
                if (!input.empty()) {
                    input.pop_back();
                    std::cout << "\b \b" << std::flush; // Erase last char
                }
            } else {
                input += ch;
                std::cout << ch << std::flush; // Print input manually
            }
        }

        // Reset the printing line
        this->_graphicsEngine.specificLinePrint(USER_INPUT_PROMPT, 0);
        this->_graphicsEngine.moveCursor(0, USER_INPUT_PROMPT_LENGTH);

        // Broadcast message
        Message message(input, this->_username, OUTBOUND_MESSAGE_REPORTED_IP);
        _broadcaster.broadcastMessage(message);
    }
    GraphicsEngine::enableEcho(); // Restore terminal settings when exiting loop
}
