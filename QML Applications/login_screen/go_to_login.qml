import QtQuick 2.0
import QtQuick.Controls 2.5


Rectangle {
    id: login_info_rect

    Text {
        id: have_account_text
        text: qsTr("Have an Account ! ")
        anchors.top: parent.top
        anchors.topMargin: parent.height / 3
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width / 1.5
        fontSizeMode: Text.Fit
        font.pixelSize: parent.height / 10
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "#34C9E4"
    }


    Text {
        id: go_login
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Don't Worry, go back to")
        anchors.top: have_account_text.bottom
        anchors.topMargin: parent.height / 20
        width: parent.width / 1.5
        fontSizeMode: Text.Fit
        font.pixelSize: parent.height / 10
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "#34C9E4"
    }
    Button {
        id: login_
        width: parent.width / 2
        height: login_.width / 4
        anchors.top: go_login.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: parent.height / 20
        text: "Log In"
        font.pixelSize: login_.height / 2
        contentItem: Text {
            id: goto_login_button_text
            anchors.fill: parent
            text: login_.text
            font: login_.font
            color: "white"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            fontSizeMode: Text.Fit
        }
        background: Rectangle {
            id: goto_login_button_rect
            color: "#34C9E4"
            radius: 5
        }
        onPressed: {
            goto_login_button_rect.color = "#CCF2F9"
            goto_login_button_rect.border.color = "#34C9E4"
            goto_login_button_text.color = "#34C9E4"
        }
        onReleased:  {
            goto_login_button_rect.color = "#34C9E4"
            goto_login_button_rect.border.color = "#CCF2F9"
            goto_login_button_text.color = "#CCF2F9"
        }
        onClicked:  {
            login_form_loader.source = "login.qml"
            info_loader.source = "go_to_signup.qml"
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
