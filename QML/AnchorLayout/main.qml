import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: background
        width: 300; height: 100;
        color: "lightblue"

        Rectangle {
            color: "red"
            y: 25
            height: 50; width: 50;
            anchors {
                right: background.right
                top: background.top
                left: background.left
            }
        }
    }
}
