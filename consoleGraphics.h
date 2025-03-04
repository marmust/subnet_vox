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
    #include <conio.h>
#else
    #include <sys/ioctl.h>
    #include <termios.h>
    #include <unistd.h>
#endif

// ui style stuff
#define USER_INPUT_PROMPT "BROADCAST >>> "

#define START_MESSAGE_LINE 2 // at what line do we start printing / updating the messages
#define USER_INPUT_PROMPT_LENGTH 14 // length of the user input prompt

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
    
    void getCursorPosition(int& height, int& width);
    void moveCursor(int height, int width);
    void specificLinePrint(const std::string& text, int lineHeight);
    void addMessage(const Message& message);
    void printAllMessages(bool reserveSpace);

    static void disableEcho();
    static void enableEcho();
};