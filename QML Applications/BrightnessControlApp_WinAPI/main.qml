import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Brightness Control App")

    Text {
        id: text1
        text: qsTr("Brightness Slider")
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.verticalCenterOffset: -50
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Slider {
        id: slider
        anchors.verticalCenter: parent.verticalCenter
        stepSize: 1
        from: 0
        to: 100
        anchors.horizontalCenter: parent.horizontalCenter
//        value: display.currentBrightnessLevel
        onValueChanged: {
            display.changeBrightnessWinAPI(slider.value)
        }
    }
}
