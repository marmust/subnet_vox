#include <iostream>
#include "networking.h"
#include "consoleGraphics.h"
#include "userInterface.h"

int main()
{
    // ask user for his name
    std::string username;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, username);

    // Create the networking objects
    Receiver receiver(BROADCAST_PORT);
    Broadcaster broadcaster(BROADCAST_PORT);
    GraphicsEngine graphicsEngine(10);

    // Create the user interface object
    UserInterface userInterface(receiver, broadcaster, graphicsEngine, username);

    // Start the continous recieve thread
    std::thread recieveThread(&UserInterface::continousRecieve, &userInterface);
    recieveThread.detach();

    // start continous broadcast
    //userInterface.continousBroadcast();

    while (true)
    {
        1+1;
    }

    return 0;
}