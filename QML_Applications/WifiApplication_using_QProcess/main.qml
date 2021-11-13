import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 1280
    height: 640
    visible: true
    title: qsTr("Hello World")

    Loader {
        anchors.fill: parent
        source: "qrc:/Home.qml"
    }
}
