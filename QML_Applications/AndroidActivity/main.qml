import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: txt
        text: qsTr("QT Activity")
        anchors.centerIn: parent
    }

    Button {
        id: btn
        text: "Second Activity"
        anchors.horizontalCenter: txt.horizontalCenter
        anchors.top: txt.bottom
        anchors.topMargin: 50
        onClicked: {
            activityHandler.startSecondActivity()
        }
    }
    Component.onCompleted: {
//        activityHandler.startSecondActivity()
    }
}
