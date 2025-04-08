#include "userInterface.h"

// ctor
// input: receiver, broadcaster, graphicsEngine objects to use
// output: none
UserInterface::UserInterface(Receiver& receiver, Broadcaster& broadcaster, GraphicsEngine& graphicsEngine)
    : _receiver(receiver), _broadcaster(broadcaster), _graphicsEngine(graphicsEngine)
{
    this->_username = "";

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

        // manual string input, because the normal one doesnt work the the terminal ui
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
        this->_graphicsEngine.printInputPrompt();

        // Broadcast message
        Message message(input, this->_username, OUTBOUND_MESSAGE_REPORTED_IP);
        _broadcaster.broadcastMessage(message);
    }
    GraphicsEngine::enableEcho(); // Restore terminal settings when exiting loop
}

// function to meet the user and ask for his name basically
// input: none
// output: none
void UserInterface::meetUser()
{
    this->_graphicsEngine.printLogo();

    std::cout << "\n\n========================================\n\nyour username: ";
    std::getline(std::cin, this->_username);
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "welcome. joining the subnet..." << std::endl;

    if (DO_BULLSHIT_INTRO)
    {
        // do a bunch of cyberpunk ahh stuff to make the user feel cool
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "RECEIVER    >>> ONLINE!                   LISTENING ON:    " << BROADCAST_IP << ":" << BROADCAST_PORT << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        std::cout << "BROADCASTER >>> ONLINE!                   BROADCASTING ON: " << BROADCAST_IP << ":" << BROADCAST_PORT << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "setting up auxillery networking systems..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(12));
        std::cout << "launching threads..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        std::cout << "jacking in..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        std::cout << "breaking the cyber ice..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(172));
        std::cout << "contacting chatgpt to fix compilation errors..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(7));
        std::cout << "hol up mom said dinner is ready brb..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(165));
        std::cout << "ok im back..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::cout << "chatgpt unable to fix all errors, contacting gemini..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        std::cout << "connecting to imperial vox channels..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
        std::cout << "requesting ip from adeptus mechanicus router..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3));
        std::cout << "negotiating connection terms with NetWatch..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(186));
        std::cout << "determining used device type: Cyberdeck..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        std::cout << "turning on styalized neon japanese advertisement in a filthy back alley..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << ONLINE_ASCII_ART << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    }
}