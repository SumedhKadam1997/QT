import QtQuick 2.15
import QtQuick.Window 2.15
import QtMultimedia 5.9

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("OpenGL_Image_Processing")

    Loader {
        id: mainLoader
        anchors.fill: parent
        source: "qrc:/HomePage.qml"
    }
}
