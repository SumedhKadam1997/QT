import QtQuick 2.15
import QtMultimedia 5.9
import QtQuick.Controls 2.5

Rectangle {
    id: camMainRect
    color: "lightgray"


    Rectangle {
        id: camBody
        width: parent.width
        height: parent.height * 0.9
        color: "lightgray"

        Camera {
            id: camera
            captureMode: Camera.CaptureStillImage
            imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash
            exposure {
                exposureCompensation: -1.0
                exposureMode: Camera.ExposurePortrait
            }
            flash.mode: Camera.FlashRedEyeReduction
            imageCapture {
                onImageCaptured: {
                    photoPreview.source = preview
                    photoPreview.grabToImage(function(result) {
                        db.insertPhoto("Screenshot" + Qt.formatDateTime(new Date(), "dd/MM/yyyy_HH:mm:ss") + ".png", result.image, Qt.formatDateTime(new Date(), "dd/MM/yyyy_HH:mm:ss"))
                    });
                }
//                onImageCaptured: {
//                    db.insertPhoto("Screenshot" + Qt.formatDateTime(new Date(), "dd/MM/yyyy_HH:mm:ss") + ".png", preview, Qt.formatDateTime(new Date(), "dd/MM/yyyy_HH:mm:ss"))
//                }
            }
        }
        Image {
            id: photoPreview
            width: video_.width * 0.8
            height: video_.height
            anchors.centerIn: parent
        }
        VideoOutput {
            id: video_
            source: camera
            anchors.fill: parent
            focus : visible
        }
    }

    Rectangle {
        id: camFooter
        width: parent.width
        height: parent.height * 0.1
        anchors.top: camBody.bottom
        color: "grey"

        Rectangle {
            id: captureBtn
            height: parent.height * 0.7
            width: height
            radius: width / 2
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            Rectangle {
                id: innerCapBtn
                height: parent.height * 0.9
                width: height
                radius: width / 2
                border.color: "gray"
                border.width: 2
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    camera.imageCapture.capture()
                }
                onPressed: {
                    innerCapBtn.color = "gray"
                }
                onReleased: {
                    innerCapBtn.color = "white"
                }
            }
        }

        ComboBox {
            id: camComboBox
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
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
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
