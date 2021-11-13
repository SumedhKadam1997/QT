import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


Window {
    id: window
    width: 1280
    height: 700
    visible: true
    title: qsTr("Hello World")
    color: "#071627"
//    Image {
//        id: name
//        anchors.fill: parent
//        source: "qrc:/vswSDf.jpeg"
//    }
    Rectangle {
        anchors.fill: parent
        color: "red"
    }

    CustomPopup {
        id: popupEmergencyBrake
        width: 500
        height: 300
        btns: 2
        colour: "skyblue"
        borderColour: "green"
        imgSource: "qrc:/vswSDf.jpeg"
        popupType: "emergencyBrake"
        popupText: "Emergency Brake Applied"
        visible: true
    }
}
