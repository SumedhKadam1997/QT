import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Rectangle {
    id: rectangle
    color: "lightgrey"

    Rectangle {
        id: last_name_input
        x: 401
        width: 150
        height: 40
        color: "#ffffff"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.rightMargin: 90

        TextField {
            id: textInputusername
            placeholderText: "Last Name"
            anchors.fill: parent
            font.pixelSize: 20
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
        }
    }

    Rectangle {
        id: first_name_input
        x: 135
        width: 150
        height: 40
        color: "#ffffff"
        anchors.right: last_name_input.left
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.rightMargin: 90

        TextField {
            id: textInputfirstname
            placeholderText: "First Name"
            anchors.fill: parent
            font.pixelSize: 20
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
        }
    }

    Rectangle {
        id: username_input
        x: 391
        y: 117
        width: 200
        height: 40
        color: "#ffffff"

        TextField {
            id: textusername
            placeholderText: "Username"
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
        x: 391
        y: 192
        width: 200
        height: 40
        color: "#ffffff"
        anchors.right: parent.right
        anchors.rightMargin: 50

        TextField {
            id: textpass
            placeholderText: "Password"
            anchors.fill: parent
            font.pixelSize: 20
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
        }
    }

    Rectangle {
        id: first_name
        x: 160
        width: 150
        height: 25
        color: "#000000"
        gradient: Gradient {
                GradientStop { position: -0.5; color: "black" }
                GradientStop { position: 1.0; color: "white" }
            }
        radius: 10
        anchors.right: last_name.left
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.rightMargin: 90

        Text {
            id: text1
            text: qsTr("First Name")
            anchors.fill: parent
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 0
            anchors.topMargin: 0
        }
    }

    Rectangle {
        id: last_name
        x: 400
        width: 150
        height: 25
        color: "#ffffff"
        gradient: Gradient {
                GradientStop { position: -0.5; color: "black" }
                GradientStop { position: 1.0; color: "white" }
            }
        radius: 10
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.rightMargin: 90

        Text {
            id: text2
            text: qsTr("Last Name")
            anchors.fill: parent
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 0
            anchors.topMargin: 0
        }
    }

    Rectangle {
        id: username
        x: 240
        y: 125
        width: 130
        height: 25
        color: "#ffffff"
        gradient: Gradient {
                GradientStop { position: -0.5; color: "black" }
                GradientStop { position: 1.0; color: "white" }
            }
        radius: 10

        Text {
            id: text3
            text: qsTr("Username")
            anchors.fill: parent
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 0
            anchors.topMargin: 0
        }
    }

    Rectangle {
        id: password
        x: 240
        y: 200
        width: 130
        height: 25
        color: "#000000"
        gradient: Gradient {
                GradientStop { position: -0.5; color: "black" }
                GradientStop { position: 1.0; color: "white" }
            }
        radius: 10

        Text {
            id: text4
            text: qsTr("Password")
            anchors.fill: parent
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Dial {
        id: agedial
        x: 447
        width: 144
        from: 18
        to: 100
        value: 18

        anchors.right: parent.right
        anchors.top: password_input.bottom
        anchors.bottom: parent.bottom
        anchors.topMargin: 20
        anchors.bottomMargin: 100
        anchors.rightMargin: 50

        Rectangle {
            color: "white"
            width: 20
            height: 20
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.left: parent.left
            anchors.leftMargin: 60

            Text {
                id: age_text
                text: agedial.value.toPrecision(2)
            }
        }
    }

    RadioButton {
        id: male
        x: 160
        y: 267
        text: qsTr("Male")
    }

    RadioButton {
        id: female
        x: 160
        y: 313
        text: qsTr("Female")
    }

    Button {
        id: reg_usr
        y: 392
        text: qsTr("Submit")
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.leftMargin: 270
        anchors.rightMargin: 270
        anchors.bottomMargin: 50

        onClicked:
        {

            console.log(" user registered")
            pageLoader.source = "login_page.qml"
        }
    }

    Rectangle {
        id: age
        y: 313
        height: 25
        color: "#ffffff"
        anchors.left: parent.left
        anchors.right: agedial.left
        anchors.bottom: reg_usr.top
        anchors.bottomMargin: 50
        anchors.leftMargin: 320
        anchors.rightMargin: 6
        gradient: Gradient {
                GradientStop { position: -0.5; color: "black" }
                GradientStop { position: 1.0; color: "white" }
        }
        radius: 10

        Text {
            id: text5
            text: qsTr("Select Age")
            anchors.fill: parent
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 0
            anchors.topMargin: 0
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1}D{i:2}D{i:9}D{i:5}D{i:14}D{i:10}D{i:19}
D{i:24}D{i:25}D{i:28}D{i:33}D{i:29}
}
##^##*/
