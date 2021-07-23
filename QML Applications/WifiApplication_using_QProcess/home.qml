import QtQuick 2.0
import QtQuick.Controls 2.5

Rectangle {
    id: mainRect
    color: "lightgray"
    Rectangle {
        id: allNetworkRect
        width: parent.width / 2
        height: parent.height / 2
        color: "red"
        opacity: 0.5
        clip: true
        Text {
            text: wifi.allAvailable
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    Rectangle {
        id: scanNetworkRect
        width: parent.width / 2
        height: parent.height / 2
        anchors.top: allNetworkRect.bottom
        color: "cyan"
        opacity: 0.5
        Text {
            text: wifi.allScanned
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Button {
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 0
            text: "SCAN"
            onClicked: {
                wifi.scanNetworks()
            }
        }
    }
    Rectangle {
        id: connectWifiRect
        anchors.left: allNetworkRect.right
        width: parent.width / 2
        height: parent.height / 2
        color: "blue"
        opacity: 0.5

        TextField {
            id: connectSSIDText
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: "SSID"
            text: "UXORIOUSGHOST-MOBILE"
        }
        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            text: "CONNECT"
            onClicked: {
                wifi.connectNetwork(connectSSIDText.text)
            }
        }
    }
    Rectangle {
        id: addNewProfile
        width: parent.width / 2
        height: parent.height / 2
        anchors.top: connectWifiRect.bottom
        anchors.left: scanNetworkRect.right
        color: "green"
        opacity: 0.5
        TextField {
            id: addSSIDText
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: -30
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: "SSID"
            text: "UXORIOUSGHOST-MOBILE"
        }
        TextField {
            id: addPassText
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 30
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: "password"
        }
        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            text: "ADD"
            onClicked: {
                wifi.addWifiProfile(addSSIDText.text, addPassText.text)
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
