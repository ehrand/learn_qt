#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

public:
    explicit Message(QObject *parent = nullptr);

    explicit Message(const Message&) = delete;
    Message& operator=(const Message&) = delete;

    QString message() const;
    void setMessage(QString value);

signals:
    void messageChanged();

public slots:
    void doMessageChange();

private:
    int m_counter{0};
    QString m_message;
};

#endif // MESSAGE_H
