import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 400
    height: 200
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        width: 400; height: 200;
        color: "lightblue"

        Text {
            anchors.centerIn: parent
            text: qsTr("Press Me");
            color: mouseArea.pressed ? "green" : "black"
            MouseArea {
                id: mouseArea
                anchors.fill: parent
            }
        }
    }
}
