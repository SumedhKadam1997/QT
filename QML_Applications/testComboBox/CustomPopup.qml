import QtQuick 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.15


Popup {
    id: popup
    implicitWidth: 500
    implicitHeight:  300
    modal: true
    visible: false
    focus: true
    padding: 0
    background: Rectangle {
        anchors.fill: parent
        color: "transparent"
    }
    anchors.centerIn: parent
    property string popupText
    property string popupType
    //    manualMode, autoMode, emergencyBrake, emergencyCall, endTrip, switchAuto, switchManual
    property color borderColour
    property color colour
    property string imgSource
    property int btns

    Rectangle {
        id: rectPopup
        anchors.fill: parent
        anchors.centerIn: parent
        color: "#071627"
        radius: 10
        border.color: borderColour

        MouseArea {
            id: maDummy
            anchors.fill: parent
        }
        Image {
            id: imgPopup
            source: imgSource
            width: 80
            height: 80
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 50
            fillMode: Image.PreserveAspectFit
        }
        Text {
            id: txtPopup
            text: popupText
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: imgPopup.bottom
            anchors.topMargin: 33
            color: "white"
            font.pixelSize: 20
        }
        Rectangle {
            id: rectLeftBtn
            width: 120
            height: 40
            radius: 6
            visible: btns === 2 ? true : btns === 1 ? false : btns === 0 ? false : false
            anchors.top: txtPopup.bottom
            anchors.topMargin: 35
            anchors.right: rectRightBtn.left
            anchors.rightMargin: 40
            color: colour
            border.color: borderColour
            Text {
                id: txtLeftBtn
                text: switch (popupType) {
                      case "emergencyCall" : "Cancel"
                          break
                      case "switchAuto" : "No"
                          break
                      case "switchManual" : "No"
                          break
                      case "endTrip" : "No"
                          break
                      }
                anchors.centerIn: parent
                color: "white"
                font.pixelSize: 18

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Cancel")
                        popup.visible = false
                    }
                }
            }
        }
        Rectangle {
            id: rectRightBtn
            width: 120
            height: 40
            radius: 6
            visible: btns === 2 ? true : btns === 1 ? true : btns === 0 ? false : false
            anchors.top: txtPopup.bottom
            anchors.topMargin: 35
            anchors.right: parent.right
            anchors.rightMargin: 40
            color: colour
            border.color: borderColour
            Text {
                id: txtRightBtn
                text: switch (popupType) {
                      case "emergencyCall" : "Call"
                          break
                      case "switchAuto" : "Yes"
                          break
                      case "switchManual" : "Yes"
                          break
                      case "autoMode" : "Cancel"
                          break
                      case "manualMode" : "Cancel"
                          break
                      case "endTrip" : "Yes"
                          break
                      }
                anchors.centerIn: parent
                color: "white"
                font.pixelSize: 18
            }
        }
        //        DropShadow{
        //            anchors.fill: popup
        //            color: "#01A2C3"
        //            source: popup
        //            radius: 8
        //        }
    }
}
