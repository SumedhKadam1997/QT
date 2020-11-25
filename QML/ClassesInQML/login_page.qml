import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Rectangle {
    id: loginpage
    color: "lightgrey"

    Rectangle {
        id: username_input
        y: 90
        height: 40
        color: "#ffffff"
        anchors.left: username.right
        anchors.right: parent.right
        anchors.leftMargin: 50
        anchors.rightMargin: 80

        TextField {
            id: textInput
            placeholderText: "username"
            anchors.fill: parent
            font.pixelSize: 20
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
        }
    }

    Rectangle {
        id: password_input
        y: 160
        height: 40
        color: "#ffffff"
        anchors.left: password.right
        anchors.right: parent.right
        anchors.leftMargin: 50
        anchors.rightMargin: 80

        TextField {
            id: textInput1
            placeholderText : "password"
            anchors.fill: parent
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            text: ""

        }
    }

    Button {
        id: login_button
        x: 460
        text: qsTr("Log In")
        anchors.right: parent.right
        anchors.top: password_input.bottom
        anchors.rightMargin: 80
        anchors.topMargin: 30
        onClicked:
        {
            textInput1.data = textInput1.text
            console.log("logout")
            pageLoader.source = "logout_page.qml"
        }
    }

    Rectangle {
        id: username
        y: 90
        height: 40
        color: "#ffffff"
        gradient: Gradient {
            GradientStop { position: -0.5; color: "black" }
            GradientStop { position: 1.0; color: "white" }
        }
        radius: 10
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: 150
        anchors.rightMargin: 373

        Text {
            id: user
            text: qsTr("Username")
            anchors.fill: parent
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
        }
    }

    Rectangle {
        id: password
        x: 147
        y: 160
        width: 120
        height: 40
        gradient: Gradient {
            GradientStop { position: -0.5; color: "black" }
            GradientStop { position: 1.0; color: "white" }
        }
        color: "#ffffff"
        radius: 10
        anchors.right: parent.right
        anchors.rightMargin: 373
        anchors.left: parent.left
        anchors.leftMargin: 150

        Text {
            id: pass
            text: qsTr("Password")
            anchors.fill: parent
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}
}
##^##*/
