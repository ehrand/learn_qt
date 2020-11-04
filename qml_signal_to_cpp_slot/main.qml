import QtQuick 2.9
import QtQuick.Controls 1.2
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        messenger.message = "Startup messaged set from QML [%1]"
    }

    Column {
        Text {
            id: textId
            text: messenger.message
        }
        Button {
            text: "Change Text"
            onClicked: messenger.doMessageChange()
        }
    }
}
