#include <iostream>
#include "networking.h"
#include "consoleGraphics.h"
#include "userInterface.h"

int main()
{
    // Create the networking objects
    Receiver receiver(BROADCAST_PORT);
    Broadcaster broadcaster(BROADCAST_PORT);
    GraphicsEngine graphicsEngine(64);

    // Create the user interface object
    UserInterface userInterface(receiver, broadcaster, graphicsEngine);

    // run the user greeting
    userInterface.meetUser();

    // start the format keeper thread
    std::thread formatKeeperThread(&GraphicsEngine::consoleFormatKeeper, &graphicsEngine);
    formatKeeperThread.detach();

    // Start the continous recieve thread
    std::thread recieveThread(&UserInterface::continousRecieve, &userInterface);
    recieveThread.detach();

    // start continous broadcast
    userInterface.continousBroadcast();

    while (true)
    {
        1+1;
    }

    return 0;
}