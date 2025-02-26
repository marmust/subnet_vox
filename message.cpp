#include "message.h"

// ctor
// input: content, senderName, senderIP strings
// output: none
Message::Message(std::string content, std::string senderName, std::string senderIP)
{
    this->_content = content;
    this->_senderName = senderName;
    this->_senderIP = senderIP;
}

// dtor
// input: none
// output: none
Message::~Message()
{
    // nothing to delete, std handles its own memory (only std::strings in class)
}

// getContent
// input: none
// output: content string
std::string Message::getContent() const
{
    return this->_content;
}

// getSenderName
// input: none
// output: senderName string
std::string Message::getSenderName() const
{
    return this->_senderName;
}

// getSenderIP
// input: none
// output: senderIP string
std::string Message::getSenderIP() const
{
    return this->_senderIP;
}

// operator<< overload
// input: os ostream, message Message
// output: os ostream
std::ostream& operator<<(std::ostream& os, const Message& message)
{
    os << message.encodeForBroadcast();
    return os;
}

// function to package a message for broadcast
// input: none
// output: encoded string
std::string Message::encodeForBroadcast() const
{
    return this->_senderName + FIELD_SPLITTER + this->_senderIP + FIELD_SPLITTER + this->_content;
}