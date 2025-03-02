#pragma once

#include <iostream>
#include "networking.h"
#include "consoleGraphics.h"
#include "protocolOutlines.h"

class UserInterface
{
private:
    GraphicsEngine& _graphicsEngine;
    Receiver& _receiver;
    Broadcaster& _broadcaster;

    std::string _username;

public:
    // ctor / dtor
    UserInterface(Receiver& receiver, Broadcaster& broadcaster, GraphicsEngine& graphicsEngine, std::string username);
    virtual ~UserInterface();

    void continousRecieve();
    void continousBroadcast();
};
