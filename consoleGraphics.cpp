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

// function to move the cursor to a specific position on the console
// input: int height (0=bottom), int width (0=left)
// output: none
void GraphicsEngine::getCursorPosition(int& x, int& y)
{
    #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        x = csbi.dwCursorPosition.X;
        y = csbi.dwCursorPosition.Y;
    #else
        std::cout << "\033[6n"; // ANSI escape sequence to query cursor position
        std::string response;
        char c;
        while (std::cin.get(c) && c != 'R') // Read cursor position response
        {
            response += c;
        }

        // Parse response (Format: ESC[n;mR where n is row and m is column)
        if (sscanf(response.c_str(), "\033[%d;%dR", &y, &x) != 2)
        {
            x = 0;
            y = 0;
        }
        
        // Convert 1-based row index to 0-based for consistency with Windows
        y--;
        x--;
    #endif
}

// Function to move the cursor to a specific position on the console
// input: int height (0=bottom), int width (0=left)
// output: none
void GraphicsEngine::moveCursor(int height, int width)
{
    this->updateResolution(); // Ensure we have the latest console dimensions

    int yPosition = _height - height - 1;
    int xPosition = std::max(0, width); // Ensure width is never negative

    if (yPosition < 0) return;

    #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD position = {static_cast<SHORT>(xPosition), static_cast<SHORT>(yPosition)};
        SetConsoleCursorPosition(hConsole, position);
    #else
        std::cout << "\033[" << yPosition << ";" << (xPosition + 1) << "H" << std::flush;
    #endif
}

// function to print a message to the on a specific line, wihtout touching the others
// input: std::string text to print, int height: which line to print on (0=bottom), bool resetCursor: if true, reset the cursor to the original position after printing
// output: none
// NOTE: doesnt use moveCursor, and getCursorPosition, because for some reason they were very unreliable here :(
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
void GraphicsEngine::addMessage(const Message& message)
{
    std::string messageText = message.getSenderIP() + " >>> " + message.getSenderName() + ": " + message.getContent();
    this->_messageLines.push_back(messageText);

    if (this->_messageLines.size() > this->_maxMessageLines)
    {
        this->_messageLines.erase(this->_messageLines.begin());
    }
}

// function to print all messages to the console
// input: bool reserveSpace: if true, reserve space for the messages in the console with \ns, int displayedMessages: how many messages are to be displayed
// output: none
void GraphicsEngine::printAllMessages(bool reserveSpace)
{
    // Update console resolution
    this->updateResolution();

    // reserve the correct amount of space needed to print with \ns
    int currentBufferVectorSize = this->_messageLines.size();

    if (reserveSpace)
    {
        for (int i = 0; i < this->_maxMessageLines + START_MESSAGE_LINE - 1; i++)
        {
            std::cout << "\n";
        }
    }

    // fill the blank lines with the messages from the vector
    for (int i = 0; i < currentBufferVectorSize; i++)
    {
        //std::cout << this->_messageLines[i] << std::endl;
        this->specificLinePrint(this->_messageLines[currentBufferVectorSize - i - 1], START_MESSAGE_LINE + i);
    }
}

// Disable echoing of input characters on terminal
void GraphicsEngine::disableEcho()
{
    #ifdef _WIN32
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
    #else
        struct termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &term);
    #endif
}

// Restore normal input behavior
void GraphicsEngine::enableEcho()
{
    #ifdef _WIN32
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode | ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
    #else
        struct termios term;
        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag |= (ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &term);
    #endif
}
