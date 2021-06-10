import QtQuick 2.15
import QtQuick.Layouts 1.3

Rectangle {
    id: galleryMainRect
    color: "white"
    anchors.fill: parent

    Flickable {
        anchors.fill: parent
        flickableDirection: Flickable.VerticalFlick
        contentHeight: photoGrid.height
        contentWidth: photoGrid.width
        Grid {
            id: photoGrid
            width: galleryMainRect.width
            columns: 3

            Repeater {
                model: myGalleryModel
                focus: true
                Rectangle {
                    id: delegateRect
                    width: photoGrid.width / 3
                    height: width * 0.5625
                    color: "white"
                    border.color: "black"
                    Image {
                        id: name
                        asynchronous: true
                        anchors.fill: parent
                        anchors.margins: 20
                        source: filename
                    }
                }
            }
        }
    }
}
