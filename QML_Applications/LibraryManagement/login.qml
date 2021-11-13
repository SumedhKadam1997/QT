import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle {
    id: main_login_rect
    anchors.fill: parent
    Image {
        id: backgroung_image
        anchors.fill: parent
        source: "qrc:/images/assets/login_background.jpg"
    }
    Rectangle {
        id: login_rect
        width: parent.width / 2
        height: parent.height / 2
        color: "gray"
        radius: 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        TextField {
            id: email_rect
            width: parent.width * 0.6
            height: parent.height * 0.1
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: -parent.height * 0.2
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: "E-mail"
        }
        TextField {
            id: pass_rect
            width: parent.width * 0.6
            height: parent.height * 0.1
            anchors.top: email_rect.bottom
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            placeholderText: "Password"
            echoMode: TextInput.Password
        }
        Rectangle {
            id: login_btn
            width: parent.width * 0.3
            height: parent.height * 0.1
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 20
            Text {
                id: login_text
                text: qsTr("Log In")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: login_btn.height / 3
                anchors.horizontalCenter: parent.horizontalCenter
            }

            MouseArea {
                id: login_btn_mouse
                anchors.fill: parent

                onClicked: {
                    if (email_rect.text === "" || pass_rect.text === "") {
                        console.log("Enter Username and Password")
                    } else if(db.loginFunc(email_rect.text) === db.generateHash(pass_rect.text)) {
                        myLogin.setLoginState(true)
                    }else {
                        console.log("Login Failed")
                    }
                }
            }
        }
    }
    Rectangle {
        id: quit_rect
        color: "transparent"
        width: 50
        height: 50
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 50

        Image {
            id: quit_image
            anchors.fill: parent
            source: "qrc:/images/assets/quit.png"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                Qt.callLater(Qt.quit)
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
