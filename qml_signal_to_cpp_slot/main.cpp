#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "message.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Message msg;
    auto context = engine.rootContext();
    context->setContextProperty("msgobj", &msg);    // allow usage of object msg under name 'msgobj' in QML code.

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
