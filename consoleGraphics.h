#include <iostream>
#include <string>
#include <algorithm>
#include <map>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

// ui style stuff
#define TECHNO_OUTLINE_TOP_RIGHT "X"
#define TECHNO_OUTLINE_TOP_LEFT "X"
#define TECHNO_OUTLINE_BOTTOM_RIGHT "X"
#define TECHNO_OUTLINE_BOTTOM_LEFT "X"
#define TECHNO_OUTLINE_HORIZONTAL "="
#define TECHNO_OUTLINE_VERTICAL "|"

#define TECHNO_OUTLINE_LABEL "SUBNET_V0X v1.0.0"
#define TECHNO_OUTLINE_PROMPT "BROADCAST >>> "
#define TECHNO_OUTLINE_LABEL_LENGTH 17

class GraphicsEngine
{
private:
    int _width;
    int _height;
    std::string _reportedTime;
    std::string _reportedIP;
    
    
    public:
    std::string _consoleUIBuffer;
    void clearScreen() const;
    void clearBuffer();
    void updateResolution();
    void updateTime();
    void setCharAt(int x, int y, char c);
    void drawOutlineToBuffer();
    // ctor / dtor
    GraphicsEngine(const std::string reportedIP);
    virtual ~GraphicsEngine();

    void drawBuffer();
};