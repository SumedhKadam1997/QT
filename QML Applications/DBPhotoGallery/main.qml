import QtQuick 2.15
import QtQuick.Window 2.15
import QtMultimedia 5.9

Window {
    width: 1366
    height: 768
    visible: true
    title: qsTr("Photo Gallery")

    Loader {
        id: mainLoader
        anchors.fill: parent
        source: "qrc:/homePage.qml"
    }
}
