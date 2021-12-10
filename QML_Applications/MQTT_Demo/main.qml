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
}
