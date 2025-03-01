#include <iostream>
#include "networking.h"
#include "consoleGraphics.h"

int main()
{
    // create a graphics engine
    GraphicsEngine* testgraphics = new GraphicsEngine("123.123.123.123");
    
    testgraphics->updateResolution();
    testgraphics->updateTime();
    testgraphics->clearBuffer();
    testgraphics->drawOutlineToBuffer();
    testgraphics->drawBuffer();
    // sleep 1 second
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // input str from user
    std::string input;
    std::cin >> input;

    return 0;
}