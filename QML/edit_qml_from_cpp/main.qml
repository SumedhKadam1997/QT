import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello QML")
    signal menuClicked(string str)

    Button {
        text: qsTr("Click Me")
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked:  window.menuClicked(text)
    }
//    Loader {
//        anchors.fill: parent
//        source: "new_qml.qml"
//    }
}
