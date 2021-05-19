import QtQuick 2.15
import QtQuick.Window 2.15
import QtMultimedia 5.15

Window {
    width: 640
    height: 480
    visible: true
//    title: qsTr("Hello World")

    Rectangle {
        width: 320
        height: 480

        Radio {
            id: radio
            band: Radio.FM
        }

        MouseArea {
            x: 0; y: 0
            height: parent.height
            width: parent.width / 2

            onClicked: radio.scanDown()
        }

        MouseArea {
            x: parent.width / 2; y: 0
            height: parent.height
            width: parent.width / 2

            onClicked: radio.scanUp()
        }
    }
}
