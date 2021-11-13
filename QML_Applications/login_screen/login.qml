import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.3
import Database 1.0


Rectangle {
    id: login_screen
    color: "grey"
    Rectangle {
        id: main_login_rect
        anchors.fill: parent
        color: "#34C9E4"
        opacity: 1

        Rectangle {
            id: column_rect
            width: parent.width / 2
            height: parent.height / 2
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            color: "transparent"
            radius: 20

            ColumnLayout {
                id: login_layout
                anchors.fill: parent

                Rectangle {
                    id: login_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height / 8
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    Text {
                        id: name
                        anchors.fill: parent
                        text: qsTr("Log In ")
                        color: "white"
                        font.pixelSize: parent.height / 2
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }

                Rectangle {
                    id: email_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height / 8
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    Text {
                        id: email_text
                        width: parent.width / 4
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("E-mail : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        anchors.leftMargin: 0
                        color: "white"
                    }
                    TextField {
                        id: email_input_text
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: email_text.right
                        anchors.right: parent.right
                        font.pixelSize: parent.height / 3
                        color: "#34C9E4"
                        background: Rectangle {
                            radius: 10
                        }
                    }
                }

                Rectangle {
                    id: password_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height / 8
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    Text {
                        id: password_text
                        width: parent.width / 4
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("Password : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        anchors.leftMargin: 0
                        color: "white"
                    }

                    TextField {
                        id: login_pass_text
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: password_text.right
                        anchors.right: parent.right
                        echoMode: TextInput.Password
                        font.pixelSize: parent.height / 3
                        color: "#34C9E4"
                        background: Rectangle {
                            radius: 10
                        }
                    }
                }
                Rectangle {
                    id: button_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height / 8
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    Button {
                        id: login_button
                        anchors.fill: parent
                        anchors.leftMargin: parent.width / 4
                        anchors.rightMargin: parent.width / 4
                        text: qsTr("Log In")
                        font.pixelSize: parent.height / 3
                        contentItem: Text {
                            id: button_text
                            anchors.fill: parent
                            text: login_button.text
                            font: login_button.font
                            color: "#34C9E4"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            fontSizeMode: Text.Fit
                        }
                        background: Rectangle {
                            id: rect_button
                            color: "#CCF2F9"
                            border.color: "#34C9E4"
                            border.width: 1
                            radius: 5
                        }

                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        Database {
                            id: db
                        }
                        onPressed: {
                            rect_button.color = "#34C9E4"
                            rect_button.border.color = "#CCF2F9"
                            button_text.color = "#CCF2F9"
                        }
                        onReleased:  {
                            rect_button.color = "#CCF2F9"
                            rect_button.border.color = "#34C9E4"
                            button_text.color = "#34C9E4"
                        }

                        onClicked: {
                            if (login_pass_text.text === "" || email_input_text.text === "") {
                                main_login_rect.opacity = 0.2
                                promptmessage_popup.visible = true
                            } else if (db.login_func(email_input_text.text) === db.generate_hash(login_pass_text.text)) {
                                main_login_rect.opacity = 0.2
                                successmessage_popup.visible = true
                            } else {
                                main_login_rect.opacity = 0.2
                                failmessage_popup.visible = true
                            }
                        }
                    }
                }
            }
        }
    }
    My_popup {
        id: promptmessage_popup
        width: parent.width / 1.5
        height: parent.height / 4
        visible: false
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        error_message: "Please Enter Username and Password"

        onClicked: {
            promptmessage_popup.visible = false
            main_login_rect.opacity = 1
        }
    }
    My_popup {
        id: successmessage_popup
        width: parent.width / 1.5
        height: parent.height / 4
        visible: false
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        error_message: "Login Successful"

        onClicked: {
            successmessage_popup.visible = false
            main_login_rect.opacity = 1
        }
    }
    My_popup {
        id: failmessage_popup
        width: parent.width / 1.5
        height: parent.height / 4
        visible: false
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        error_message: "Login Unsuccessful"

        onClicked: {
            failmessage_popup.visible = false
            main_login_rect.opacity = 1
        }
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.33;height:480;width:640}
}
##^##*/
