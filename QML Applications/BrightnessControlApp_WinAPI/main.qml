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
        id: control
        anchors.verticalCenter: parent.verticalCenter
        stepSize: 10
        from: 0
        to: 100
        value: display.currentBrightnessLevel
        background: Rectangle {
                x: control.leftPadding
                y: control.topPadding + control.availableHeight / 2 - height / 2
                implicitWidth: 200
                implicitHeight: 4
                width: control.availableWidth
                height: implicitHeight
                radius: 2
                color: "#bdbebf"

                Rectangle {
                    width: control.visualPosition * parent.width
                    height: parent.height
                    color: "#21be2b"
                    radius: 2
                }
//                MouseArea {
//                    anchors.fill: parent
//                    onReleased: {
//                        display.changeBrightnessQProcess(control.value)
//                    }
//                }
            }
        onMoved: {
            display.changeBrightnessWinAPI(control.value)
            display.changeBrightnessQProcess(control.value)
        }

        anchors.horizontalCenter: parent.horizontalCenter

//        value: display.currentBrightnessLevel
        onValueChanged: {
//            display.changeBrightnessWinAPI(slider.value)
//            display.changeBrightnessQProcess(control.value)
        }
    }
}
