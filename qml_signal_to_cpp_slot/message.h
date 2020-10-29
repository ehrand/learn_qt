#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class Message : public QObject
{
    Q_OBJECT
public:
    explicit Message(QObject *parent = nullptr);

signals:
    void messageChanged(QString value);

public slots:
    void doMessageChange();

private:
    int m_counter{0};
    QString m_message;
};

#endif // MESSAGE_H
