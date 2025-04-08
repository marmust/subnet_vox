#pragma once

#include <iostream>
#include "networking.h"
#include "consoleGraphics.h"
#include "protocolOutlines.h"

#define DO_BULLSHIT_INTRO true

class UserInterface
{
private:
    GraphicsEngine& _graphicsEngine;
    Receiver& _receiver;
    Broadcaster& _broadcaster;

    std::string _username;

public:
    // ctor / dtor
    UserInterface(Receiver& receiver, Broadcaster& broadcaster, GraphicsEngine& graphicsEngine);
    virtual ~UserInterface();

    void meetUser();

    void continousRecieve();
    void continousBroadcast();
};
