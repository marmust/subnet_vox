#include "consoleGraphics.h"

// ctor
// input: none
// output: none
GraphicsEngine::GraphicsEngine(int maxMessageLines)
{
    // Set max message lines
    _maxMessageLines = maxMessageLines;
}

// dtor
// input: none
// output: none
GraphicsEngine::~GraphicsEngine()
{
    // nothing to delete, only ints in class
}

// function to update the two internal parameters: _width and _height to the correct values
// input: none
// output: none
void GraphicsEngine::updateResolution()
{
    // Get the current console window size
    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        _width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        _height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    #else
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        _width = w.ws_col;
        _height = w.ws_row;
    #endif
}

// function to print a message to the on a specific line, wihtout touching the others
// input: std::string text to print, int height: which line to print on (0=bottom)
// output: none
void GraphicsEngine::specificLinePrint(const std::string& text, int lineHeight)
{
    this->updateResolution();
    if (lineHeight < 0) return;

    int yPosition = _height - lineHeight - 1;
    if (yPosition < 0) return;

    #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi); // 🚀 Save cursor position
        COORD originalPos = csbi.dwCursorPosition;   // Store original cursor position

        COORD position = {0, static_cast<SHORT>(yPosition)};
        SetConsoleCursorPosition(hConsole, position);

        // Clear the line before printing
        std::cout << "\r" << std::string(_width, ' ') << "\r" << text << std::flush;

        // 🚀 Restore original cursor position
        SetConsoleCursorPosition(hConsole, originalPos);

    #else
        // 🚀 Save cursor position (Linux/macOS)
        std::cout << "\033[s"; // Save cursor position

        // Move to specific line and print
        std::cout << "\033[" << yPosition << ";1H\033[K" << text << std::flush;

        // 🚀 Restore original cursor position
        std::cout << "\033[u"; // Restore cursor position
    #endif
}

// add a new message to the vector, if too big, remove oldest message
// input: message string to add
// output: none
void GraphicsEngine::addMessage(const std::string& message)
{
    this->_messageLines.push_back(message);

    if (this->_messageLines.size() > this->_maxMessageLines)
    {
        this->_messageLines.erase(this->_messageLines.begin());
    }
}

// function to print all messages to the console
// input: none
// output: none
void GraphicsEngine::printAllMessages(bool reserveSpace)
{
    // Update console resolution
    this->updateResolution();

    // reserve the correct amount of space needed to print with \ns
    int totalMessagesLength = this->_messageLines.size();

    if (reserveSpace)
    {
        for (int i = 0; i < totalMessagesLength + START_MESSAGE_LINE - 1; i++)
        {
            std::cout << "\n";
        }
    }

    // fill the blank lines with the messages from the vector
    for (int i = 0; i < totalMessagesLength; i++)
    {
        //std::cout << this->_messageLines[i] << std::endl;
        this->specificLinePrint(this->_messageLines[totalMessagesLength - i - 1], START_MESSAGE_LINE + i);
    }
}