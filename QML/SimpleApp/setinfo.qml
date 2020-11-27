import QtQuick 2.4
import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Extras 1.4
import QtQuick.Shapes 1.14
import QtQuick.Controls 2.1



Rectangle {
    id: setinforect
    color: "lightgrey"

    Rectangle {
        id: first_name
        x: 10
        width: 80
        height: 35
        color: "#000000"
        gradient: Gradient {
                GradientStop { position: -0.5; color: "black" }
                GradientStop { position: 1.0; color: "white" }
            }
        radius: 10
        anchors.top: parent.top
        anchors.topMargin: 18
        anchors.left: parent.left
        anchors.leftMargin: 20

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
    TextField {
        anchors.top: parent.top
        anchors.topMargin: 15
        anchors.left: first_name.right
        anchors.leftMargin: 20
        font.pixelSize: 20


        onEditingFinished: {
            setFirstname(text)
        }
    }

    Rectangle {
        id: last_name
        x: 10
        width: 80
        height: 35
        color: "#000000"
        gradient: Gradient {
                GradientStop { position: -0.5; color: "black" }
                GradientStop { position: 1.0; color: "white" }
            }
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: first_name.bottom
        anchors.topMargin: 15


        Text {
            id: text12
            text: qsTr("Last Name")
            anchors.fill: parent
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 0
            anchors.topMargin: 0
        }
    }
    TextField {
        anchors.top: parent.top
        anchors.topMargin: 65
        anchors.left: last_name.right
        anchors.leftMargin: 20
        font.pixelSize: 20

        onEditingFinished: {
            setLastname(text)
        }
    }

    Rectangle {
        id: username
        x: 10
        width: 80
        height: 35
        color: "#000000"
        gradient: Gradient {
                GradientStop { position: -0.5; color: "black" }
                GradientStop { position: 1.0; color: "white" }
            }
        radius: 10
        anchors.top: last_name.bottom
        anchors.topMargin: 15
        anchors.left: parent.left
        anchors.leftMargin: 20

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
    TextField {
        anchors.top: parent.top
        anchors.topMargin: 116
        anchors.left: username.right
        anchors.leftMargin: 20
        font.pixelSize: 20

        onEditingFinished: {
            setUsername(text)
        }
    }
    Rectangle{
        id: agerect
        x: 380
        width: 50
        height: 40
        color: "#000000"
        gradient: Gradient {
                GradientStop { position: -0.5; color: "black" }
                GradientStop { position: 1.0; color: "white" }
            }
        radius: 10
        anchors.top: parent.top
        anchors.topMargin: 92
        anchors.right: agedial.left
        anchors.rightMargin: 20

        Text {
            id: agetext
            width: 50
            height: 40
            text: qsTr("Age")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.centerIn: parent
        }
    }

    Dial {
        id: agedial
        anchors.top: parent.top
        inputMode: Dial.Circular
        stepSize: 1
        anchors.topMargin: 20
        width: 144
        from: 0
        to: 60
        anchors.right: parent.right
        anchors.rightMargin: 50

        onMoved: {
            setAge(value)
        }

        Rectangle {
            color: "lightgrey"
            width: 30
            height: 30
            anchors.centerIn: parent

            Text {
                id: age_text
                x: 0
                y: 0
                width: 30
                height: 30
                text: agedial.value.toPrecision(2)
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter



            }
        }
    }
    RadioButton {
        id: male
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: username.bottom
        anchors.topMargin: 40
        text: qsTr("Male")

        onClicked: {
            setGender("Male")
        }

    }

    RadioButton {
        id: female
        checked: false
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: male.bottom
        anchors.topMargin: 20
        text: qsTr("Female")

        onClicked: {
            setGender("Female")
        }
    }

    Button {
        id: button
        x: 270
        anchors.bottom: parent.bottom
        text: qsTr("Submit")
        onClicked:
            {
                console.log("Info Submitted")
                pageLoader.source = "getinfo.qml"
            }
        }

}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.8999999761581421;height:480;width:640}
}
##^##*/
