import QtQuick 2.15
import QtQuick.Window 2.15



Rectangle {
    width: Screen.width
    height: Screen.height
    color: "cyan"

    MouseArea {
        anchors.fill: parent

        onClicked: {
            screenObject.capture("C:\\Users\\uxoriousghost\\Desktop\\sample.png")
        }
    }
}

