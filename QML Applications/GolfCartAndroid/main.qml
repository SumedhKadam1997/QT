import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 393
    height: 851
    visible: true
    title: qsTr("Golf HMI")
    color: "#F2F2F2"

    Loader {
        id: mainLoader
        anchors.fill: parent
        source: "qrc:/otpScreen.qml"
    }
}
