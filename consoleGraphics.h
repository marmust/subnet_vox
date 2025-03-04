#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <mutex>
#include <vector>
#include <thread>
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
#define LOGO_ASCII_ART " _______ _     _ ______  __   _ _______ _______       _    _  _____  _     _\n |______ |     | |_____] | \\  | |______    |           \\  /  |     |  \\___/ \n ______| |_____| |_____] |  \\_| |______    |    _____   \\/   |_____| _/   \\_"
// ^ ascii art saying SUBNET_VOX
#define ONLINE_ASCII_ART "  _____  __   _        _____ __   _ _______\n |     | | \\  | |        |   | \\  | |______\n |_____| |  \\_| |_____ __|__ |  \\_| |______"
// ^ ascii art saying ONLINE

#define START_MESSAGE_LINE 2 // at what line do we start printing / updating the messages
#define USER_INPUT_PROMPT_LENGTH 14 // length of the user input prompt

class GraphicsEngine
{
private:
    int _height;
    int _width;

    // these two are used to detect resolution changes
    int _previousHeight;
    int _previousWidth;

    int _maxMessageLines;
    std::vector<std::string> _messageLines;

    void updateResolution();
    static void clearConsole();
    
    public:
    // ctor / dtor
    GraphicsEngine(int maxMessageLines);
    virtual ~GraphicsEngine();
    
    // cursor control
    void getCursorPosition(int& height, int& width);
    void moveCursor(int height, int width);

    // printers
    void specificLinePrint(const std::string& text, int lineHeight);
    void printAllMessages(bool reserveSpace);
    void printInputPrompt();

    // misc
    static void disableEcho();
    static void enableEcho();

    void addMessage(const Message& message);
    void consoleFormatKeeper();
    static void printLogo();
};