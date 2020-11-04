#include "message.h"

Message::Message(QObject *parent)
    : QObject(parent)
    , m_counter(0)
    , m_message("Startup message")
{
}

QString Message::message() const
{
    return m_message;
}

void Message::setMessage(QString value)
{
    m_message = value.arg(++m_counter);
    emit messageChanged();
}

void Message::doMessageChange()
{
    setMessage("Hello World number [%1]");
}
