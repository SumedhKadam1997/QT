import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property int speed: 0
//    color: "black"

    Button {
        id: btnSpeedUp
        text: "speed up"
        onClicked: {
            speed += 1
            mqtt.publishMessage("hmi.verolt.vego/BMD/speed", speed)
        }
    }
    Button {
        id: btnSpeedDown
        text: "speed down"
        anchors.left: btnSpeedUp.right
        onClicked: {
            speed -= 1
            mqtt.publishMessage("hmi.verolt.vego/BMD/speed", speed)
        }
    }
    Button {
        id: btnManual
        anchors.left: btnSpeedDown.right
        text: "manual"
        onClicked: {
            mqtt.publishMessage("hmi.verolt.vego/BMD/driveMode", "Manual")
        }
    }
    Button {
        id: btnAuto
        anchors.left: btnManual.right
        text: "auto"
        onClicked: {
            mqtt.publishMessage("hmi.verolt.vego/BMD/driveMode", "Auto")
        }
    }
    Button {
        id: btnDriving
        anchors.left: btnAuto.right
        text: "Driving"
        onClicked: {
            mqtt.publishMessage("hmi.verolt.vego/BMD/navigationStatus", "Driving")
        }
    }
    Button {
        id: btnStopDriving
        anchors.left: btnDriving.right
        text: "Stop Driving"
        onClicked: {
            mqtt.publishMessage("hmi.verolt.vego/BMD/navigationStatus", "notDriving")
        }
    }
    Button {
        id: btnConnect
        text: "Connect"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        onClicked: {
            mqtt.connectHost()
        }
    }
    Button {
        id: btnDisconnect
        text: "Disconnect"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        onClicked: {
            mqtt.disconnectHost()
        }
    }
    Button {
        id: btnPos1
        text: "Pos 1"
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        onClicked: {
            mqtt.publishMessage("hmi.verolt.vego/BMD/position", "18.33898155410398,74.0460613606794,10,0")
        }
    }
    Button {
        id: btnPos2
        text: "Pos 2"
        anchors.left: btnPos1.right
        anchors.bottom: parent.bottom
        onClicked: {
            mqtt.publishMessage("hmi.verolt.vego/BMD/position", "18.656075119075645,74.97819236379377,20,30")
        }
    }    Button {
        id: btnPos3
        text: "Pos 3"
        anchors.left: btnPos2.right
        anchors.bottom: parent.bottom
        onClicked: {
            mqtt.publishMessage("hmi.verolt.vego/BMD/position", "18.254236836934393,75.69129973363336,30,50")
        }
    }
    Button {
        id: btnPos4
        text: "Pos 4"
        anchors.left: btnPos3.right
        anchors.bottom: parent.bottom
        onClicked: {
            mqtt.publishMessage("hmi.verolt.vego/BMD/position", "19.992981816314447,77.52524943695498,40,70")
        }
    }
    Button {
        id: btnPos5
        text: "Pos 5"
        anchors.left: btnPos4.right
        anchors.bottom: parent.bottom
        onClicked: {
            mqtt.publishMessage("hmi.verolt.vego/BMD/position", "16.85021934985992,74.61753547365119,50,80")
        }
    }

    TextField {
        id: txtInput
        anchors.centerIn: parent
    }

    Button {
        id: btnTextMessage
        anchors.horizontalCenter: txtInput.horizontalCenter
        anchors.top: txtInput.bottom
        anchors.topMargin: 20
        text: "Send Message"
        onClicked: {
            mqtt.publishMessage("hmi.verolt.vego/BMD/notify", txtInput.text)
        }
    }
}
