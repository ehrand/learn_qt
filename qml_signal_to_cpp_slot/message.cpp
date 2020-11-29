#include <QDebug>
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

int Message::sendMessageFromCpp(const QString value)
{
    qDebug() << "This is C++ speaking. I heard QML say:" << value;
    return m_counter;
}

void Message::doMessageChange()
{
    setMessage("Hello World number [%1]");
}
