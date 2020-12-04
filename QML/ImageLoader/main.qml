import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 1000
    height: 1080
    title: qsTr("Image Loader")

    Rectangle {
        width: 1000;
        height: 1000;
        color: "lightblue"

        property int frames: 1;

        Image {
            id: myself
            x: 100
            y: 100
            source: "me.jpg"
            width: sourceSize.width / 2
            height: sourceSize.height /2

        }
    }
}
