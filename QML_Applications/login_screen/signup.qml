import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.15
import Database 1.0

Rectangle {
    id: signup_screen
    color: "grey"

    Rectangle {
        id: main_signup_rect
        anchors.fill: parent
        color: "#34C9E4"
        opacity: 1


        Rectangle {
            id: column_rect
            width: parent.width / 1.5
            height: parent.height / 1.5
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            color: "transparent"
            radius: 20

            ColumnLayout {
                id: signup_rect
                anchors.fill: parent
                anchors.bottomMargin: parent.height / 40

                Rectangle {
                    id: header_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height / 8
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    Text {
                        id: header_text
                        anchors.fill: parent
                        text: qsTr("Signup")
                        color: "white"
                        font.pixelSize: parent.height / 2
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                Rectangle {
                    id: name_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height / 10
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    Text {
                        id: name_text
                        width: parent.width / 4
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("Name : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        color: "white"
                    }
                    TextField {
                        id: name_input_text
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: name_text.right
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width / 6
                        font.pixelSize: parent.height / 3
                        color: "#34C9E4"
                        background: Rectangle {
                            radius: 10
                        }
                    }
                }
                Rectangle {
                    id: email_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height / 10
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    Text {
                        id: email_text
                        width: parent.width / 4
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("E-Mail : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        color: "white"
                    }
                    TextField {
                        id: email_input_text
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: email_text.right
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width / 6
                        font.pixelSize: parent.height / 3
                        color: "#34C9E4"
                        background: Rectangle {
                            radius: 10
                        }
                    }
                }
                Rectangle {
                    id: username_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height / 10
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Text {
                        id: username_text
                        width: parent.width / 4
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("Username : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        color: "white"
                    }
                    TextField {
                        id: username_input_text
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: username_text.right
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width / 6
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
                    Layout.preferredHeight: parent.height / 10
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Text {
                        id: password_text
                        width: parent.width / 4
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("Password : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        color: "white"
                    }
                    TextField {
                        id: password_input_text
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: password_text.right
                        anchors.right: parent.right
                        echoMode: TextInput.Password
                        anchors.rightMargin: parent.width / 6
                        font.pixelSize: parent.height / 3
                        color: "#34C9E4"
                        background: Rectangle {
                            radius: 10
                        }
                    }
                }
                Rectangle {
                    id: gender_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height / 10
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    Text {
                        id: gender_rect_text
                        width: parent.width / 4
                        text: qsTr("Gender : ")
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font.pixelSize: parent.height / 3
                        color: "white"
                    }

                    RadioButton {
                        id: male_radio_button
                        text: qsTr("Male")
                        width: parent.width / 4
                        height: parent.height
                        font.pixelSize: parent.height / 3
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: gender_rect_text.right
                        anchors.leftMargin: parent.width /20
                        contentItem: Text {
                            anchors.fill: parent
                            text: male_radio_button.text
                            font: male_radio_button.font
                            color: "white"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            fontSizeMode: Text.Fit
                        }
                        indicator: Rectangle {
                            width: male_radio_button.height / 1.5
                            height: male_radio_button.height / 1.5
                            radius: width
                            anchors.verticalCenter: parent.verticalCenter
                            Rectangle {
                                anchors.fill: parent
                                visible: male_radio_button.checked
                                color: "#34C9E4"
                                radius: male_radio_button.height / 1.5
                                anchors.margins: 4
                            }
                        }
                        onClicked: {
                            gender_text.text = "Male"
                        }
                    }

                    RadioButton {
                        id: female_radio_button
                        text: qsTr("Female")
                        width: parent.width / 4
                        height: parent.height
                        font.pixelSize: parent.height / 3
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: male_radio_button.right
                        anchors.leftMargin: parent.width / 20
                        anchors.right: parent.right
                        contentItem: Text {
                            anchors.fill: parent
                            text: female_radio_button.text
                            font: female_radio_button.font
                            color: "white"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            fontSizeMode: Text.Fit
                        }
                        indicator: Rectangle {
                            width: female_radio_button.height / 1.5
                            height: female_radio_button.height / 1.5
                            radius: width
                            anchors.verticalCenter: parent.verticalCenter
                            Rectangle {
                                anchors.fill: parent
                                visible: female_radio_button.checked
                                color: "#34C9E4"
                                radius: female_radio_button.height / 1.5
                                anchors.margins: 4
                            }
                        }
                        onClicked: {
                            gender_text.text = "Female"
                        }
                    }
                }
                Rectangle {
                    id: button_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height / 10
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Text {
                        id: gender_text
                        text: qsTr("None")
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 4
                        color: "#34C9E4"
                    }
                    Button {
                        id: submit_button
                        anchors.fill: parent
                        anchors.leftMargin: parent.width / 4
                        anchors.rightMargin: parent.width / 4
                        text: qsTr("Sign Up")
                        font.pixelSize: parent.height / 3
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        contentItem: Text {
                            id: signup_text
                            anchors.fill: parent
                            text: submit_button.text
                            font: submit_button.font
                            color: "#34C9E4"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            fontSizeMode: Text.Fit
                        }
                        background: Rectangle {
                            id: signup_rect_button
                            color: "#CCF2F9"
                            border.color: "#34C9E4"
                            border.width: 1
                            radius: 5
                        }
                        onPressed: {
                            signup_rect_button.color = "#34C9E4"
                            signup_rect_button.border.color = "#CCF2F9"
                            signup_text.color = "#CCF2F9"
                        }
                        onReleased:  {
                            signup_rect_button.color = "#CCF2F9"
                            signup_rect_button.border.color = "#34C9E4"
                            signup_text.color = "#34C9E4"
                        }
                        Database {
                            id: db
                        }

                        onClicked: {
                            if(name_input_text.text === "" || email_input_text.text === "" || username_input_text.text === "" || password_input_text.text === "" || gender_text.text === "None") {
                                main_signup_rect.opacity = 0.2
                                value_missing_popup.visible = true
                            } else if(db.check_user(email_input_text.text) === email_input_text.text){
                                main_signup_rect.opacity = 0.2
                                existing_user_popup.visible = true
                            } else {
                                db.insertdb(name_input_text.text,email_input_text.text,username_input_text.text,password_input_text.text,gender_text.text)
                                main_signup_rect.opacity = 0.2
                                signupmessage_popup.visible = true
                            }
                        }
                    }
                }
            }
        }
    }
    My_popup {
        id: signupmessage_popup
        width: parent.width / 1.5
        height: parent.height / 4
        visible: false
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        error_message: "Sign Up Successful"

        onClicked: {
            signupmessage_popup.visible = false
            main_signup_rect.opacity = 1
        }
    }
    My_popup {
        id: value_missing_popup
        width: parent.width / 1.5
        height: parent.height / 4
        visible: false
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        error_message: "Please Enter All Values"

        onClicked: {
            value_missing_popup.visible = false
            main_signup_rect.opacity = 1
        }
    }
    My_popup {
        id: existing_user_popup
        width: parent.width / 1.5
        height: parent.height / 4
        visible: false
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        error_message: "User already Registered"

        onClicked: {
            existing_user_popup.visible = false
            main_signup_rect.opacity = 1
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}
}
##^##*/
