import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    color: "cyan"
    title: "Sample App"

    Rectangle {
        id: rectangle
        x: 56
        y: 32
        width: 200
        height: 200
        color: "#ffff00"
    }

    Rectangle {
        id: rectangle1
        x: 278
        y: 32
        width: 200
        height: 200
        color: "#57ff29"
    }

    Rectangle {
        id: rectangle2
        x: 56
        y: 258
        width: 200
        height: 200
        color: "#ffaa00"
        clip: true
    }

    Rectangle {
        id: rectangle3
        x: 278
        y: 258
        width: 200
        height: 200
        color: "#6ed4ff"
    }
}
