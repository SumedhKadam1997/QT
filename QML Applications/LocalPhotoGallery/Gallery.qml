import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Rectangle {
    id: galleryMainRect
    color: "lightgreen"
    anchors.fill: parent

    MouseArea {
        id: galleryMouse
        anchors.fill: parent
    }
    Rectangle {
        id: galleryHeader
        width: parent.width
        height: parent.height * 0.05
        color: "gray"

        Rectangle {
            id: clearMultipleSelect
            height: parent.height * 0.9
            width: parent.width * 0.2
            color: "white"
            radius: 15
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: - width / 2
            Text {
                id: clearText
                text: qsTr("Clear")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.height * 0.5
                color: "gray"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    bodyLoader.setSource("qrc:/blank.qml")
                    bodyLoader.setSource("qrc:/Gallery.qml")
                    db.clearNames()
                }
                onPressed: {
                    clearText.color = "white"
                    clearMultipleSelect.color = "lightgray"
                }
                onReleased: {
                    clearText.color = "gray"
                    clearMultipleSelect.color = "white"
                }
            }
        }
        Rectangle {
            id: delMultipleSelect
            height: parent.height * 0.9
            width: parent.width * 0.2
            color: "white"
            radius: 15
            anchors.left: clearMultipleSelect.right
            anchors.leftMargin: width / 2
            anchors.verticalCenter: parent.verticalCenter
            Text {
                id: delText
                text: qsTr("Delete")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: parent.height * 0.5
                color: "gray"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    db.delPhotoData()
                    bodyLoader.setSource("qrc:/blank.qml")
                    bodyLoader.setSource("qrc:/Gallery.qml")
                    photosModel.updateModel(myLogin.MyEmail)
                    db.clearNames()
                }
                onPressed: {
                    delText.color = "white"
                    delMultipleSelect.color = "lightgray"
                }
                onReleased: {
                    delText.color = "gray"
                    delMultipleSelect.color = "white"
                }
            }
        }
    }
    Rectangle {
        id: galleryBody
        width: parent.width
        height: parent.height * 0.95
        anchors.top: galleryHeader.bottom
        clip: true
        color: "lightgray"

        Flickable {
            anchors.fill: parent
            flickableDirection: Flickable.VerticalFlick
            contentHeight: photoGrid.height
            contentWidth: photoGrid.width

            Grid {
                id: photoGrid
                width: galleryBody.width
                property int currentIndex: 0
                columns: 3

                Repeater {
                    model: photosModel
                    Rectangle {
                        id: delegateRect
                        width: photoGrid.width / 3
                        property bool selected: false
                        height: width * 0.5625
                        focus: index === photoGrid.currentIndex
                        color: selected ? "lightsteelblue": "transparent"
                        border.color: "black"
                        border.width: 2
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                selected = true
                                photoGrid.currentIndex = index
                                db.populateNames(photoName)
                                console.log(photoName)
                            }
                        }
                        Image {
                            anchors.fill: parent
                            anchors.margins: 30
                            source: "file:///" + applicationDirPath + "/Images/" + photoName
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.66;height:480;width:640}
}
##^##*/
