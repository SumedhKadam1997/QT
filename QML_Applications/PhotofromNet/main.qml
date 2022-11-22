import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image {
        id: imgPhoto
        anchors.fill: parent
        source: photoFetcher.photoName
    }
    Button {
        id: btnLoadPhoto
        anchors.centerIn: parent
        text: "Load Photo"
        onClicked: {
            photoFetcher.getPhoto()
        }
    }
}
