#include <iostream>
#include "protocolOutlines.h"

class Message
{
private:
    std::string _content;
    std::string _senderName;
    std::string _senderIP;

public:
    // ctor / dtor
    Message(const std::string content, const std::string senderName, const std::string senderIP);
    virtual ~Message();

    // getters
    std::string getContent() const;
    std::string getSenderName() const;
    std::string getSenderIP() const;

    // << overload and encodeForBroadcast functions
    friend std::ostream& operator<<(std::ostream& os, const Message& message);
    std::string encodeForBroadcast() const;
};