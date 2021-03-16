import QtQuick 2.15
import QtQuick.Window 2.15
import Paint 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Print {
        id: printing
        anchors.fill: parent
    }
}
