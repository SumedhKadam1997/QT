import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3


Rectangle {
    id: homePageRect
    property bool toggle: true

    Rectangle {
        id: headerRect
        width: parent.width
        height: parent.height * 0.05
        color: "lightgray"

        Rectangle {
            id: homeRect
            width: parent.width * 0.028
            height: width
            color: "transparent"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.02
            Image {
                id: homeImage
                anchors.fill: parent
                source: "qrc:/Images/assets/home.png"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    bodyLoader.setSource("")
                }
            }
        }

        Rectangle {
            id: toggleRect
            width: parent.width * 0.2
            height: parent.height * 0.8
            anchors.centerIn: parent
            radius: width / 2

            Rectangle {
                id: toggleCamRect
                width: parent.width * 0.5
                height: parent.height
                radius: width / 2
                anchors.left: parent.left
                color: toggle === true ? "gray" : "white"

                Text {
                    id: camText
                    text: qsTr("Camera")
                    anchors.fill: parent
                    fontSizeMode: Text.Fit
                    font.pixelSize: parent.height * 0.5
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: toggle === true ? "white" : "gray"

                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        toggle = true
                        bodyLoader.setSource("qrc:/Camera.qml")
                    }
                }
            }
            Rectangle {
                id: toggleGalleryRect
                width: parent.width * 0.5
                height: parent.height
                radius: width / 2
                anchors.right: parent.right
                color: toggle === true ? "white" : "gray"

                Text {
                    id: galleryText
                    text: qsTr("Gallery")
                    anchors.fill: parent
                    fontSizeMode: Text.Fit
                    font.pixelSize: parent.height * 0.5
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: toggle === true ? "gray" : "white"

                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        toggle = false
                        bodyLoader.setSource("qrc:/Gallery.qml")
                        photosModel.updateModel(myLogin.MyEmail)
                    }
                }
            }
        }
        Rectangle {
            id: logoutRect
            width: parent.width * 0.028
            height: width
            color: "transparent"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: parent.width * 0.02
            Image {
                id: logoutImage
                anchors.fill: parent
                source: "qrc:/Images/assets/logout.png"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    bodyLoader.setSource("")
                    myLogin.loginState = false
                }
            }
        }
    }
    Rectangle {
        id: bodyRect
        width: parent.width
        height: parent.height * 0.95
        anchors.top: headerRect.bottom
        color: "gray"

        Rectangle {
            id: addMemberRect
            width: 200
            height: 200
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenterOffset: - width / 2
            anchors.horizontalCenter: parent.horizontalCenter
            Text {
                id: addMemText
                text: qsTr("Add Member")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    add_member_popup.open()
                }
            }
        }
        Rectangle {
            id: delMemberRect
            width: 200
            height: 200
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: addMemberRect.right
            anchors.leftMargin: 50
            Text {
                id: delMemText
                text: qsTr("Delete Member")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    del_member_popup.open()
                }
            }
        }


        Popup {
            id: add_member_popup
            width: parent.width / 4
            height: parent.height / 1.5
            anchors.centerIn: parent

            Rectangle {
                anchors.fill: parent
                color: "cyan"
                ColumnLayout {
                    id: add_member_column
                    anchors.fill: parent

                    Rectangle {
                        id: name_rect
                        Layout.preferredWidth: parent.width
                        Layout.preferredHeight: parent.height * 0.08
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
                            color: "black"
                        }
                        TextField {
                            id: name_input_text
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            anchors.left: name_text.right
                            anchors.right: parent.right
                            anchors.rightMargin: parent.width / 6
                            font.pixelSize: parent.height / 3
                        }
                    }
                    Rectangle {
                        id: age_rect
                        Layout.preferredWidth: parent.width
                        Layout.preferredHeight: parent.height * 0.08
                        color: "transparent"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        Text {
                            id: age_text
                            width: parent.width / 4
                            fontSizeMode: Text.Fit
                            anchors.left: parent.left
                            anchors.leftMargin: parent.width / 10
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            text: qsTr("Age : ")
                            font.pixelSize: parent.height / 3
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignVCenter
                            color: "black"
                        }
                        TextField {
                            id: age_input_text
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            anchors.left: age_text.right
                            anchors.right: parent.right
                            anchors.rightMargin: parent.width / 6
                            font.pixelSize: parent.height / 3
                        }
                    }
                    Rectangle {
                        id: gender_rect
                        Layout.preferredWidth: parent.width
                        Layout.preferredHeight: parent.height * 0.08
                        color: "transparent"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        Text {
                            id: gender_text
                            width: parent.width / 4
                            fontSizeMode: Text.Fit
                            anchors.left: parent.left
                            anchors.leftMargin: parent.width / 10
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            text: qsTr("Gender : ")
                            font.pixelSize: parent.height / 3
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignVCenter
                            color: "black"
                        }
                        TextField {
                            id: gender_input_text
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            anchors.left: gender_text.right
                            anchors.right: parent.right
                            anchors.rightMargin: parent.width / 6
                            font.pixelSize: parent.height / 3
                        }
                    }
                    Rectangle {
                        id: email_rect
                        Layout.preferredWidth: parent.width
                        Layout.preferredHeight: parent.height * 0.08
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
                            text: qsTr("Email : ")
                            font.pixelSize: parent.height / 3
                            horizontalAlignment: Text.AlignLeft
                            verticalAlignment: Text.AlignVCenter
                            color: "black"
                        }
                        TextField {
                            id: email_input_text
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            anchors.left: email_text.right
                            anchors.right: parent.right
                            anchors.rightMargin: parent.width / 6
                            font.pixelSize: parent.height / 3
                        }
                    }
                    Rectangle {
                        id: pass_rect
                        Layout.preferredWidth: parent.width
                        Layout.preferredHeight: parent.height * 0.08
                        color: "transparent"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        Text {
                            id: pass_text
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
                            color: "black"
                        }
                        TextField {
                            id: pass_input_text
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            anchors.left: pass_text.right
                            anchors.right: parent.right
                            anchors.rightMargin: parent.width / 6
                            font.pixelSize: parent.height / 3
                        }
                    }
                    Button {
                        id: submit_btn
                        Layout.alignment: Qt.AlignHCenter |Qt.AlignVCenter
                        text: "Add member"
                        onClicked: {
                            if(name_input_text.text ==="" && age_input_text.text === "" && gender_input_text.text === "" && email_input_text.text === "" && pass_input_text.text === "") {
                                console.log("Please enter all values")
                            } else {
                                db.addMember(name_input_text.text, age_input_text.text, email_input_text.text, pass_input_text.text, gender_input_text.text)
                                console.log("member successfully added")
                                name_input_text.text = ""
                                age_input_text.text = ""
                                gender_input_text.text = ""
                                email_input_text.text = ""
                                pass_input_text.text = ""
                                add_member_popup.close()
                            }
                        }
                    }
                }
            }
        }

        Popup {
            id: del_member_popup
            width: parent.width / 4
            height: parent.height / 1.5
            anchors.centerIn: parent

            Rectangle {
                anchors.fill: parent
                color: "cyan"
                ColumnLayout {
                    id: del_book_column
                    anchors.fill: parent

                    Rectangle {
                        id: del_email_rect
                        Layout.preferredWidth: parent.width
                        Layout.preferredHeight: parent.height * 0.08
                        color: "transparent"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        Text {
                            id: del_email_text
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
                            color: "black"
                        }
                        TextField {
                            id: del_email_input_text
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            anchors.left: del_email_text.right
                            anchors.right: parent.right
                            anchors.rightMargin: parent.width / 6
                            font.pixelSize: parent.height / 3
                        }
                    }
                    Button {
                        id: delete_btn
                        Layout.alignment: Qt.AlignHCenter |Qt.AlignVCenter
                        text: "Delete"
                        onClicked: {
                            if(del_email_input_text.text === "") {
                                console.log("Please enter member email")
                            } else if (db.checkName(del_email_input_text.text)){
                                db.delMember(del_email_input_text.text)
                                console.log("member successfully deleted")
                                del_member_popup.close()
                            } else {
                                console.log("member dosen't exists")
                            }
                        }
                    }
                }
            }
        }

        Loader {
            id: bodyLoader
            anchors.fill: parent
            source: ""
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.25;height:480;width:640}
}
##^##*/
