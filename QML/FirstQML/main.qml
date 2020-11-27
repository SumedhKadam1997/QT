import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true;
    width: 650;
    height: 720;
    title: qsTr("Hello World");

    Rectangle{
        x: 100;
        y: 100;
        height: 400;
        width: height;
        color: "grey";
    }
    Rectangle {
        x: 150;
        y:150;
        height: 200;
        width: 300;
        color: "lightblue"
    }
    Rectangle {
        x: 200;
        y: 200;
        height: 50;
        width: 50;
        color: "white"
    }
    Rectangle {
        x: 150;
        y: 300;
        height: 150;
        width: 300;
        color: "green"
    }
    Rectangle {
        x: 250;
        y: 350;
        height: 50;
        width: 150;
        color: "blue"
    }
}

