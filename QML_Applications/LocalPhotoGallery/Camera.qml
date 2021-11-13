import QtQuick 2.15
import QtQuick.Controls 2.5
import QtMultimedia 5.9


Rectangle {
    id: camMainRect
    color: "lightgray"
    property string imageName
    property string imagePath
    property date currentTime: new Date()
    signal nameChange()

    onNameChange: {
        imageName = myLogin.getRandomString(10);
    }

    MouseArea {
        anchors.fill: parent
    }

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
                    //                    console.log("Image captured at ", applicationDirPath)
                    imagePath = camera.imageCapture.capturedImagePath
                    console.log(imagePath)
                }
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
                id: mousearea
                anchors.fill: parent
                onClicked: {
                    camera.imageCapture.captureToLocation(applicationDirPath + "/Images/" + imageName)
                    db.addPhotoData(imageName, myLogin.MyEmail)
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
        Component.onCompleted: {
            mousearea.entered.connect(nameChange)
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
