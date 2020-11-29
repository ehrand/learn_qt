#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext> // to work with QML from C++
#include <QDebug>

#include "message.h"

void testInvoke(QObject* rootObject)
{
    QVariant rv;
    QVariant msg = "This is a C++ parameter";
    QMetaObject::invokeMethod(rootObject,
                              "javaScriptFunction",
                              Q_RETURN_ARG(QVariant, rv),
                              Q_ARG(QVariant, msg));
    qDebug() << "QML returned " << rv;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Message msg;
    auto context = engine.rootContext();
    context->setContextProperty("messenger", &msg);    // allow usage of object msg under name 'msgobj' in QML code.

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    auto rootObject = engine.rootObjects().first();

    testInvoke(rootObject);

    return app.exec();
}
