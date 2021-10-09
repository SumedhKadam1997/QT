import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button {
        id: btnRecord
        text: "Record"
        anchors.centerIn: parent
        onClicked: {
            recorder.start()
        }
    }
}
