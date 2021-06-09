import QtQuick 2.15

Rectangle {
    id: galleryMainRect
    color: "lightgreen"
    anchors.fill: parent

    GridView {
        id: galleryGridView
        anchors.fill: parent
        model: myGalleryModel
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        focus: true
        flow: GridView.TopToBottom
        delegate: Rectangle {
            id: delegateRect
            width: 300
            height: width
            color: "skyblue"

            //            Image {
            //                id: delImage
            //                source: photo
            //                width: 0
            //                height: 0
            //                anchors.horizontalCenter: parent.horizontalCenter
            //            }
            Image {
                id: name
                anchors.fill: parent
                source: delText.text
            }
            Text {
                id: delText
                text: filename
                visible: false
                anchors.centerIn: parent
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                id: dateText
                text: date
                visible: false
                anchors.centerIn: parent
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }


    //    Image {
    //        id: name
    //        source: db.getPhoto()
    //        anchors.fill: parent
    //    }
}
