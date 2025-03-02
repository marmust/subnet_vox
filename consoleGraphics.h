#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <mutex>
#include <vector>
#include "Message.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

// ui style stuff
#define USER_INPUT_PROMPT "BROADCAST >>> "

#define START_MESSAGE_LINE 5 // at what line do we start printing / updating the messages

class GraphicsEngine
{
private:
    int _height;
    int _width;
    
    int _maxMessageLines;
    std::vector<std::string> _messageLines;

    void updateResolution();

public:
    // ctor / dtor
    GraphicsEngine(int maxMessageLines);
    virtual ~GraphicsEngine();

    void specificLinePrint(const std::string& text, int lineHeight);
    void addMessage(const std::string& message);
    void printAllMessages(bool reserveSpace);
};