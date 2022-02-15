import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Timer {
        id: popupTimer

    }

    Connections {
        target: speechService

        function onWakeWordDetectedChanged() {
            console.log("Wake word detected")
            console.log(speechService.wakeWordDetected)
            if (speechService.wakeWordDetected) {
                speechPopup.open()

            } else if (!speechService.wakeWordDetected) {
                speechPopup.close()
            }
        }
    }

    Text {
        id: txtSpeechString
        anchors.centerIn: parent
        wrapMode: Text.WordWrap
        text: speechService.speechString
    }

    Button {
        id: startService
        text: "Start"
        anchors.horizontalCenter: txtSpeechString.horizontalCenter
        anchors.top: txtSpeechString.bottom
        anchors.topMargin: 50
        onClicked: {
            speechService.startSpeechService("Sumedh")
        }
    }

    Button {
        id: stopService
        text: "Stop"
        anchors.horizontalCenter: txtSpeechString.horizontalCenter
        anchors.top: startService.bottom
        anchors.topMargin: 50
        onClicked: {
            speechService.stopSpeechService()
        }
    }

    Component.onCompleted: {

    }

    Popup {
        id: speechPopup
        implicitWidth: 500
        implicitHeight:  300
        modal: true
        visible: false
        focus: true
        padding: 0
        background: Rectangle {
            anchors.fill: parent
            color: "red"
        }
        closePolicy: Popup.NoAutoClose
        anchors.centerIn: parent
    }
}
