#include "message.h"

Message::Message(QObject *parent)
    : QObject(parent)
    , m_counter(0)
    , m_message("Hello World number [%1]")
{

}

void Message::doMessageChange()
{
    emit messageChanged(m_message.arg(++m_counter));
}
