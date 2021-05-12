import QtQuick 2.0
import QtQuick.Controls 2.5

Rectangle {
    id: signup_info_rect

    Text {
        id: welcome_text
        text: qsTr("Welcome ! ")
        width: parent.width / 2
        fontSizeMode: Text.Fit
        font.pixelSize: parent.height / 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.topMargin: parent.height / 3
        anchors.horizontalCenter: parent.horizontalCenter
        color: "#34C9E4"
    }
    Text {
        id: go_signup
        width: parent.width / 1.5
        fontSizeMode: Text.Fit
        font.pixelSize: parent.height / 8
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.top: welcome_text.bottom
        anchors.topMargin: parent.height / 16
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Don't Have an Account Yet")
        color: "#34C9E4"
    }
    Button {
        id: signup_
        width: parent.width / 2
        height: signup_.width / 4
        anchors.top: go_signup.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: parent.height / 20
        font.pixelSize: signup_.height / 2
        text: qsTr("Sign up")
        contentItem: Text {
            id: goto_signup_button_text
            anchors.fill: parent
            text: signup_.text
            font: signup_.font
            color: "white"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            fontSizeMode: Text.Fit
        }
        background: Rectangle {
            id: goto_signup_button_rect
            color: "#34C9E4"
            radius: 5
        }
        onPressed: {
            goto_signup_button_rect.color = "#CCF2F9"
            goto_signup_button_rect.border.color = "#34C9E4"
            goto_signup_button_text.color = "#34C9E4"
        }
        onReleased:  {
            goto_signup_button_rect.color = "#34C9E4"
            goto_signup_button_rect.border.color = "#CCF2F9"
            goto_signup_button_text.color = "#CCF2F9"
        }
        onClicked:  {
            login_form_loader.source = "signup.qml"
            info_loader.source = "go_to_login.qml"
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
