import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.11

ApplicationWindow {
    id: window
    width: 1024
    height: 768
    visible: true
    title: qsTr("Hello World")
    color: "#2d2f39"

    Loader {
        id: main_loader
        anchors.fill: parent
        source: "home_screen.qml"
    }
}
