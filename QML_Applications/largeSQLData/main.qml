import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import Qt.labs.qmlmodels 1.0


Window {
    id: window
    width: 1366
    height: 768
    visible: true
    title: qsTr("Large SQL Data")

    Loader {
        id: load
        anchors.fill: parent
        source: "qrc:/table.qml"
    }
}
