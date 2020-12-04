import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Window 2.15
import QtQuick.Layouts 1.11
import QtQuick.Dialogs.qml 1.0
import QtQuick.Controls 2.0
import Database 1.0

Rectangle {
    id: rectangle
    anchors.fill: parent
    color: "lightgrey"


    Rectangle{
        id: rectFirstName
        width: 100; height: 40
        radius: 5
        color: "red"
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 20

        gradient: Gradient {
            GradientStop { position: 0; color: Qt.darker("gray") }
            GradientStop { position: 1; color: Qt.lighter("gray") }
        }


        Text {
            id: textfirstname
            color: "white"
            font.pixelSize: 15
            font.letterSpacing: 0.9
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            text: qsTr("First Name")
        }
        TextField {
            id: textfirst
            width: 100
            height: 40
            anchors.left: parent.right
            anchors.top: parent.top
            font.pixelSize: 0
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.topMargin: 0
            anchors.leftMargin: 40
            placeholderText : "First Name"

            onEditingFinished: {
                setFirstname(text)
            }
        }
    }


    Rectangle{
        id: rectLastName
        width: 100; height: 40
        radius: 5
        color: "red"
        anchors.top: rectFirstName.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20

        gradient: Gradient {
            GradientStop { position: 0; color: Qt.darker("gray") }
            GradientStop { position: 1; color: Qt.lighter("gray") }
        }

        Text {
            id: textlastname
            color: "white"
            font.pixelSize: 15
            font.letterSpacing: 0.9
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            text: qsTr("Last Name")
        }
        TextField {
            id: textlast
            width: 100
            height: 40
            anchors.left: parent.right
            anchors.top: parent.top
            font.pixelSize: 0
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.topMargin: 0
            anchors.leftMargin: 40
            placeholderText : "Last Name"

            onEditingFinished: {
                setLastname(text)
            }
        }
    }
    Rectangle{
        id: rectemail
        width: 100; height: 40
        radius: 5
        color: "red"
        anchors.top: rectLastName.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20

        gradient: Gradient {
            GradientStop { position: 0; color: Qt.darker("gray") }
            GradientStop { position: 1; color: Qt.lighter("gray") }
        }

        Text {
            id: textemail
            color: "white"
            font.pixelSize: 15
            font.letterSpacing: 0.9
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            text: qsTr("Email")
        }
        TextField {
            id: textforemail
            width: 200
            height: 40
            anchors.left: parent.right
            anchors.top: parent.top
            font.pixelSize: 0
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.topMargin: 0
            anchors.leftMargin: 40
            placeholderText : "Email"

            onEditingFinished: {
                setEmail(text)
            }
        }
    }
    Rectangle{
        id: rectAge
        width: 100; height: 40
        radius: 5
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: rectemail.bottom
        anchors.topMargin: 80

        gradient: Gradient {
            GradientStop { position: 0; color: Qt.darker("gray") }
            GradientStop { position: 1; color: Qt.lighter("gray") }
        }

        Text {
            id: textage
            color: "white"
            font.pixelSize: 15
            font.letterSpacing: 0.9
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            text: qsTr("Age")
        }
        Dial {
            id: dial
            anchors.left: parent.right
            anchors.leftMargin: 50
            anchors.top: parent.top
            anchors.topMargin: -50
            from: 0
            to: 60
            stepSize: 1

            onMoved: {
                setAge(value)
            }

            Rectangle {
                color: "white"
                width: 30
                height: 30
                anchors.centerIn: parent

                Text {
                    id: age_text
                    x: 0
                    y: 0
                    width: 30
                    height: 30
                    text: dial.value.toPrecision(2)
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter



                }
            }
        }

    }
    Rectangle{
        id: rectgender
        width: 100; height: 40
        radius: 5
        color: "red"
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 400

        gradient: Gradient {
            GradientStop { position: 0; color: Qt.darker("gray") }
            GradientStop { position: 1; color: Qt.lighter("gray") }
        }

        Text {
            id: textgender
            color: "white"
            font.pixelSize: 15
            font.letterSpacing: 0.9
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            text: qsTr("Gender")
        }
        RadioButton {
            id: radioButtonmale
            anchors.left: parent.right
            anchors.leftMargin: 10
            text: qsTr("Male")

            onClicked: {
                gendertext.text = "Male"
                setGender("Male")
            }
        }

        RadioButton {
            id: radioButtonfemale
            anchors.left: parent.right
            anchors.leftMargin: 10
            anchors.top: radioButtonmale.bottom
            text: qsTr("Female")

            onClicked: {
                gendertext.text = "Female"
                setGender("Female")
            }
        }
        TextArea{
            id: gendertext
            x: 134
            width: 80
            height: 30
            anchors.right: parent.right
            anchors.top: radioButtonfemale.bottom
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: -100
            anchors.topMargin: 20

        }
    }

    Button {
        id: button
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        text: qsTr("Submit")

        Database {
            id: db
        }

        onClicked: {
            db.insertdb(textfirst.text, textlast.text, textforemail.text, gendertext.text, dial.value)
            mymodel.updateModel()
            console.log("Info Submitted")
            pageLoader.source = "view.qml"
        }
    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:34}
}
##^##*/
