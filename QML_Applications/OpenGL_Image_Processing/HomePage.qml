import QtQuick 2.15
import QtQuick.Controls 2.15


Rectangle {
    id: homeRect
    property bool toggle: true

    Rectangle {
        id: headerRect
        width: parent.width
        height: parent.height * 0.05
        color: "lightgray"

        Rectangle {
            id: toggleRect
            width: parent.width * 0.2
            height: parent.height * 0.8
            anchors.centerIn: parent
            radius: width / 2

            Rectangle {
                id: toggleCamRect
                width: parent.width * 0.5
                height: parent.height
                radius: width / 2
                anchors.left: parent.left
                color: toggle === true ? "gray" : "white"

                Text {
                    id: camText
                    text: qsTr("Camera")
                    anchors.fill: parent
                    fontSizeMode: Text.Fit
                    font.pixelSize: parent.height * 0.5
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: toggle === true ? "white" : "gray"

                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        toggle = true
                        bodyLoader.setSource("qrc:/camera.qml")
                    }
                }
            }
            Rectangle {
                id: toggleGalleryRect
                width: parent.width * 0.5
                height: parent.height
                radius: width / 2
                anchors.right: parent.right
                color: toggle === true ? "white" : "gray"

                Text {
                    id: galleryText
                    text: qsTr("Images")
                    anchors.fill: parent
                    fontSizeMode: Text.Fit
                    font.pixelSize: parent.height * 0.5
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: toggle === true ? "gray" : "white"

                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        toggle = false
                        bodyLoader.setSource("qrc:/gallery.qml")
                    }
                }
            }
        }
    }
    Rectangle {
        id: bodyRect
        width: parent.width
        height: parent.height * 0.95
        anchors.top: headerRect.bottom
        color: "white"

        Loader {
            id: bodyLoader
            anchors.fill: parent
            source: "qrc:/camera.qml"
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.25;height:480;width:640}
}
##^##*/
