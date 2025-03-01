#include "consoleGraphics.h"

// ctor
// input: none
// output: none
GraphicsEngine::GraphicsEngine(std::string reportedIP)
{
    this->_reportedIP = reportedIP;
    this->updateTime();
    this->updateResolution();
    this->_consoleUIBuffer = "";
}

// dtor
// input: none
// output: none
GraphicsEngine::~GraphicsEngine()
{
    // nothing to delete, only ints in class
}

// clearScreen
// input: none
// output: none
void GraphicsEngine::clearScreen() const
{
    std::cout << "\033[H";
}

// function to empty the string buffer
// input: none
// output: none
void GraphicsEngine::clearBuffer()
{
    _consoleUIBuffer = "";
}

// funciton to change the _length and _width parameters to console's current size
// input: none
// output: none
void GraphicsEngine::updateResolution()
{
    #ifdef _WIN32
        // Windows method: Get console screen buffer info
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        {
            _width = csbi.srWindow.Right - csbi.srWindow.Left;
            _height = csbi.srWindow.Bottom - csbi.srWindow.Top;
        }
    #else
        // Linux/macOS method: Use ioctl to get terminal size
        struct winsize w;
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0)
        {
            _width = w.ws_col;
            _height = w.ws_row;
        }
    #endif
}

// function to update the time string
// input: none
// output: none
void GraphicsEngine::updateTime()
{
    // get current time
    time_t now = time(0);
    tm* ltm = localtime(&now);

    // format time string
    this->_reportedTime = std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec);
}

// function to modify the string buffer at a specific location (supports different colors)
// input: x, y, character, foreground color, background color
// output: none
void GraphicsEngine::setCharAt(int x, int y, char c)
{
    // Ensure x and y are within bounds
    if (x < 0) x = 0;
    if (y < 0) y = 0;

    // Compute required buffer size (without modifying _width and _height)
    int requiredSize = (_width + 1) * (y + 1); // +1 for line breaks

    // Expand the buffer **if needed** without modifying _width or _height
    if (_consoleUIBuffer.size() < requiredSize)
    {
        _consoleUIBuffer.resize(requiredSize, ' '); // Fill missing spaces
        for (int i = _width; i < _consoleUIBuffer.size(); i += _width + 1)
        {
            _consoleUIBuffer[i] = '\n'; // Ensure line breaks
        }
    }

    // Calculate the correct index
    int index = y * (_width + 1) + x;

    // Validate index to prevent crashes
    if (index < 0 || index >= _consoleUIBuffer.size()) return;

    // Store just the character (NO color codes, handled separately)
    _consoleUIBuffer[index] = c;
}

// draws the techno style outline to string buffer (no messages)
// input: none
// output: none
void GraphicsEngine::drawOutlineToBuffer()
{
    // Ensure buffer is resized properly
    int requiredSize = (_width + 1) * _height; // +1 accounts for newlines
    if (_consoleUIBuffer.size() < requiredSize)
    {
        _consoleUIBuffer.resize(requiredSize, ' '); // Fill with spaces
        for (int i = _width; i < _consoleUIBuffer.size(); i += _width + 1)
        {
            _consoleUIBuffer[i] = '\n'; // Ensure line breaks
        }
    }

    // Draw IP in top left
    for (int i = 0; i < _reportedIP.size(); i++)
    {
        setCharAt(i, 0, _reportedIP[i]);
    }

    // Draw label in top middle
    for (int i = 0; i < TECHNO_OUTLINE_LABEL_LENGTH; i++)
    {
        setCharAt((_width - TECHNO_OUTLINE_LABEL_LENGTH) / 2 + i, 0, TECHNO_OUTLINE_LABEL[i]);
    }

    // Draw time in top right (Fixed incorrect calculation)
    for (int i = 0; i < _reportedTime.size(); i++)
    {
        setCharAt(_width - _reportedTime.size() + i - 1, 0, _reportedTime[i]);
    }

    // Draw top border
    for (int i = 0; i < _width - 1; i++)
    {
        setCharAt(i, 1, TECHNO_OUTLINE_HORIZONTAL[0]);
    }

    // Draw bottom border
    for (int i = 0; i < _width - 1; i++)
    {
        setCharAt(i, _height - 1, TECHNO_OUTLINE_HORIZONTAL[0]);
    }

    // Draw left border
    for (int i = 1; i < _height - 1; i++)
    {
        setCharAt(0, i, TECHNO_OUTLINE_VERTICAL[0]);
    }

    // Draw right border
    for (int i = 1; i < _height - 1; i++)
    {
        setCharAt(_width - 1, i, TECHNO_OUTLINE_VERTICAL[0]);
    }

    // Draw corners
    setCharAt(0, 1, TECHNO_OUTLINE_TOP_LEFT[0]);
    setCharAt(_width - 1, 1, TECHNO_OUTLINE_TOP_RIGHT[0]);
    setCharAt(0, _height - 1, TECHNO_OUTLINE_BOTTOM_LEFT[0]);
    setCharAt(_width - 1, _height - 1, TECHNO_OUTLINE_BOTTOM_RIGHT[0]);
}

// function to flush the string buffer to the console
// input: none
// output: none
void GraphicsEngine::drawBuffer()
{
    std::cout << "\033[H"; // Move cursor to top-left

    for (int i = 0; i < _consoleUIBuffer.size(); i++)
    {
        std::cout << _consoleUIBuffer[i];
    }
    std::cout.flush();
}