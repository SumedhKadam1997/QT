import QtQuick 2.15
import QtQuick.Window 2.15
import QtMultimedia 5.9
import QtQuick.Controls 2.5

Window {
    id: window
    width: 1366
    height: 768
    visible: true
    title: qsTr("Camera Application")

    Camera {
        id: camera
        deviceId: camId.activeCamId
    }
    VideoOutput {
        source: camera
        anchors.fill: parent
    }

    ComboBox {
        id: camComboBox
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.leftMargin: 20
        displayText: "Cameras"
        model: QtMultimedia.availableCameras
        delegate: ItemDelegate {
            width: camComboBox.width
            contentItem: Text {
                text: modelData.displayName
                color: "black"
                font: camComboBox.font
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter
            }
        }
        onAccepted: {
            camera.deviceId = modelData.deviceId
        }
    }
    Button {
        id: frontCamButton
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.leftMargin: (parent.width / 3) - (width / 2)
        anchors.bottomMargin: 20
        text: "Front Camera"
        onClicked: {
            camId.setactiveCamera("FRONT")
            camId.setActiveId("FRONT")
        }
    }

    Button {
        id: backCamButton
        anchors.right: parent.right
        anchors.rightMargin: (parent.width / 3) + (width / 2)
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        text: "Back Camera"
        onClicked: {
            camId.setactiveCamera("BACK")
            camId.setActiveId("BACK")
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/
