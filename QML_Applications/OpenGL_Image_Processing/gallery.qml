import QtQuick 2.15

Rectangle {
    id: imgViewer
    anchors.fill: parent

    Image {
        id: capturedImage
        anchors.centerIn: parent
        source: imgProcessor.imageToUrl(imgProcessor.img)
    }

}
