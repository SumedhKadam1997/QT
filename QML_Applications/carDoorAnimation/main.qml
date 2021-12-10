import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: Screen.width
    height: Screen.height
    visible: true
    visibility: "FullScreen"
    title: qsTr("Car Door Animation")

    property string position: "close"

    Image {
        id: imgBG
        source: "qrc:/background.jpg"
        anchors.fill: parent
        fillMode: Image.Stretch

        Image {
            id: imgDoorlessVehicle
            source: "qrc:/doorlessCar.png"
            anchors.horizontalCenterOffset: 0
            width: parent.width / 1.5
            height: parent.height / 2
            fillMode: Image.PreserveAspectFit
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Image {
            id: imgDoor
            source: "qrc:/door.png"
            anchors.verticalCenterOffset: 5
            anchors.horizontalCenterOffset: imgDoorlessVehicle.width * 0.07968
            width: imgDoorlessVehicle.width * 0.25781
            height: width
            transformOrigin: Item.Right
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: imgDoorlessVehicle
            rotation: 0

            MouseArea {
                id: maDoor
                width: parent.width / 4
                height: width
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.verticalCenterOffset: -imgDoorlessVehicle.height * 0.0834
                onClicked: {
                    if (position === "close") {
                        position = "partialOpen"
                        partialRotationAnim.start()
//                        txtReq1.opacity = 1
                    } else if (position === "partialOpen") {
                        rotationAnimationPartialDown.start()
                        position = "close"
//                        txtReq1.opacity = 0
                    }
                }
                pressAndHoldInterval: 1000
                onPressAndHold: {
                    if (position === "partialOpen") {
                        rotationAnimationPartialUp.start()
                        position = "open"
//                        txtReq2.opacity = 1
                    } else if (position === "close") {
                        rotationAnimationUp.start()
                        position = "open"
//                        txtReq2.opacity = 1
                    } else if (position === "open") {
                        rotationAnimationDown.start()
                        position = "close"
//                        txtReq2.opacity = 0
                    }
                }
            }
        }

        Text {
            id: txtReq1
            text: qsTr("Requirement 1: On Single Tap of the Door Handle, the door will partially open i.e. in 45 Degrees.")
            anchors.left: parent.left
            font.pixelSize: 20
            opacity: 1
            anchors.leftMargin: 50
            anchors.topMargin: 100
            anchors.top: parent.top
            color: "#F2F2F2"
        }
        Text {
            id: txtReq2
            text: qsTr("Requirement 2: On Press and Hold of the Door Handle, the door will fully open.")
            anchors.left: parent.left
            font.pixelSize: 20
            anchors.leftMargin: 50
            anchors.topMargin: 200
            anchors.top: parent.top
            color: "#F2F2F2"
        }
    }

    //    Button {
    //        id: btnTap
    //        text: "Tap"
    //        onClicked: {
    //            if (position === "close") {
    //                position = "partialOpen"
    //                partialRotationAnim.start()
    //            }
    //        }
    //    }

    //    Button {
    //        id: btnSwipe
    //        text: "Swipe"
    //        anchors.left: btnTap.right
    //        onClicked: {
    //            if (position === "partialOpen") {
    //                rotationAnimationPartialUp.start()
    //                position = "open"
    //            } else if (position === "close") {
    //                rotationAnimationUp.start()
    //                position = "open"
    //            }
    //        }
    //    }

    Rectangle {
        id: btnClose
        color: "red"
        width: 200
        height: 100
        visible: false
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 50
        radius: width / 2
        Text {
            id: txtClose
            text: qsTr("Close")
            anchors.centerIn: parent
            font.pixelSize: 16
            color: "#FFFFFF"
        }
        MouseArea {
            anchors.fill: parent

            onClicked: {
                if (position === "partialOpen") {
                    rotationAnimationPartialDown.start()
                    position = "close"
                } else if (position === "open") {
                    rotationAnimationDown.start()
                    position = "close"
                }
            }
        }
    }

    RotationAnimation {
        id: partialRotationAnim
        duration: 1000
        targets: imgDoor
        from : 0
        to : 20
    }
    PropertyAnimation {
        id: rotationAnimationUp
        target: imgDoor
        property: "rotation"
        duration: 2000
        from: 0
        to: 60
    }
    PropertyAnimation {
        id: rotationAnimationPartialUp
        target: imgDoor
        property: "rotation"
        duration: 2000
        from: 20
        to: 60
    }
    PropertyAnimation {
        id: rotationAnimationDown
        target: imgDoor
        property: "rotation"
        duration: 2000
        from: 60
        to: 0
    }
    PropertyAnimation {
        id: rotationAnimationPartialDown
        target: imgDoor
        property: "rotation"
        duration: 1000
        from: 20
        to: 0
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.33}
}
##^##*/
