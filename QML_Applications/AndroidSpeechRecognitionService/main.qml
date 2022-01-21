import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: txtSpeechString
        anchors.centerIn: parent
        wrapMode: Text.WordWrap
        text: speechService.speechString
    }

    Component.onCompleted: {
        speechService.sendToService("Sumedh")
    }
}
