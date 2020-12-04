import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Window 2.15
import QtQuick.Layouts 1.11
import QtQuick.Dialogs.qml 1.0
import QtQuick.LocalStorage 2.12

Rectangle {
    id: rectangle
    anchors.fill: parent
    color: "lightgrey"

    Rectangle{
        id: firstnamerect
        x: 14
        y: 39
        width: firstnametext.implicitWidth
        height: firstnametext.implicitHeight
        color: "grey"
        Text {
            id: firstnametext
            text: firstname
            anchors.fill: parent
            anchors.horizontalCenterOffset: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.horizontalCenter: parent.horizontalCenter
            color: "white"
            font.pointSize: 20
        }
    }
    Rectangle{
        id: lastnamerect
        x: 218
        y: 39
        width: firstnametext.implicitWidth
        height: firstnametext.implicitHeight
        color: "grey"
        Text {
            id: lastnametext
            text: lastname
            anchors.fill: parent
            anchors.horizontalCenter: parent.horizontalCenter
            color: "white"
            font.pointSize: 20
        }
    }
    Rectangle{
        id: usernamerect
        x: 14
        y: 124
        width: firstnametext.implicitWidth
        height: firstnametext.implicitHeight
        color: "grey"
        Text {
            id: usernametext
            color: "white"
            text: email
            anchors.fill: parent
            anchors.horizontalCenterOffset: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 20
        }
    }
    Rectangle{
        id: agerect
        x: 133
        y: 206
        width: firstnametext.implicitWidth
        height: firstnametext.implicitHeight
        color: "grey"
        Text {
            id: agetext
            text: age
            anchors.fill: parent
            anchors.horizontalCenterOffset: -39
            anchors.rightMargin: 39
            anchors.bottomMargin: 0
            anchors.leftMargin: -39
            anchors.topMargin: 0
            anchors.horizontalCenter: parent.horizontalCenter
            color: "white"
            font.pointSize: 20
        }
    }
    Rectangle{
        id: genderrect
        x: 321
        y: 124
        width: firstnametext.implicitWidth
        height: firstnametext.implicitHeight
        color: "grey"
        Text {
            id: gendertext
            text: gender
            anchors.fill: parent
            anchors.horizontalCenter: parent.horizontalCenter
            color: "white"
            font.pointSize: 20
        }
    }

    Text {
        id: text1
        x: 457
        y: 39
        width: 119
        height: 40
        text: qsTr("whose email is")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: text2
        x: 243
        y: 124
        width: 52
        height: 40
        text: qsTr("is a")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: text3
        x: 14
        y: 206
        width: 79
        height: 40
        text: qsTr("and is ")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: text4
        x: 218
        y: 206
        width: 59
        height: 40
        text: qsTr("years old")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }


}
