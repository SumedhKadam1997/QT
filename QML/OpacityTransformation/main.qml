import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    color: "lightblue"
    title: qsTr("Hello World")

    Rectangle {
        x: 50; y:50; width: 200; height: 300;
        color: "white"
        opacity: 0.5

        Rectangle {
            x: 100; y: 25; width: 200; height: 50;
            color: "red"
            opacity: 0.5
            rotation: 45
        }
        Rectangle {
            x: 100; y: 90; width: 200; height: 50;
            color: "red"
        }
    }
    Rectangle {
        x: 150; y: 210; width: 200; height: 50;
        color: "red"
        opacity: 0.5
    }
    Rectangle {
        x: 150; y: 275; width: 200; height: 50
        color: "red"
    }
}
