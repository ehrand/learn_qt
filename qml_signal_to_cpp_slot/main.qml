import QtQuick 2.9
import QtQuick.Controls 1.2
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Connections {
        target: messenger
        onMessageChanged: textId.text = value; // see void Message::messageChanged(QString value);
    }

    Column {
        Text {
            id: textId
            text: qsTr("Hello New World")
        }
        Button {
            text: "Change Text"
            onClicked: messenger.doMessageChange()
        }
    }
}
