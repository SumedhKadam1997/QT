import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Shapes 1.14
import QtQuick.Controls.Styles 1.0
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.15

Rectangle {

    Rectangle {
        id: admin_all_librarians_rect
        width: parent.width * 0.7
        height: parent.height
        color: "skyblue"


        TextField {
            id: filter_textfield
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            placeholderText: "Search librarians"
            onTextChanged: {
                alllibrariansmodel.updateModel(filter_textfield.text)
            }
            Component.onCompleted: {
                alllibrariansmodel.updateModel(filter_textfield.text)
            }
        }

        OldControls.TableView {
            id: all_librarians_table_view
            width: parent.width * 0.8
            height: parent.height * 0.8
            anchors.top: filter_textfield.bottom
            anchors.topMargin: 40
            model: alllibrariansmodel
            sortIndicatorVisible: true
            anchors.horizontalCenter: parent.horizontalCenter
            flickableItem.flickableDirection : Flickable.VerticalFlick
            style: TableViewStyle {
                handle: Rectangle {
                    implicitHeight: 17
                    color: "gray"
                }
            }
            headerDelegate: Rectangle {
                height: all_librarians_table_view.height * 0.08
                width: all_librarians_table_view.width
                radius: 5
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "lightgray" }
                    GradientStop { position: 1.5; color: "white" }
                }
                Text {
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 10
                    text: styleData.value
                }
            }
            rowDelegate:
                Rectangle {
                id: rectangle
                height: all_librarians_table_view.height * 0.05
                width: parent.width
                radius: 5
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1.5; color: "lightgray" }
                }
                Text {
                    id: row_text
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pointSize: 10
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log(alllibrariansmodel.index)
                        alllibrariansmodel.removeRow()
                        alllibrariansmodel.updateModel(filter_textfield.text)
                    }
                }
            }
            OldControls.TableViewColumn {
                width: all_librarians_table_view.width * 0.2
                role: "name"
                title: "Name"
            }
            OldControls.TableViewColumn {
                width: all_librarians_table_view.width * 0.1
                role: "age"
                title: "Age"
            }
            OldControls.TableViewColumn {
                width: all_librarians_table_view.width * 0.1
                role: "gender"
                title: "Gender"
            }
            OldControls.TableViewColumn {
                width: all_librarians_table_view.width * 0.3
                role: "email"
                title: "Email"
            }
            OldControls.TableViewColumn {
                width: all_librarians_table_view.width * 0.3
                role: "password"
                title: "Password"
            }
        }
    }

    Rectangle {
        id: admin_librarians_rect
        width: parent.width * 0.3
        height: parent.height
        anchors.left: admin_all_librarians_rect.right
        color: "lightgreen"

        Text {
            id: librarians_text
            text: qsTr("librarians Operations")
            anchors.top: parent.top
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 20
        }

        GridLayout {
            id: buttonsGrid
            width: parent.width * 0.8
            height: parent.height * 0.6
            anchors.top: librarians_text.bottom
            anchors.horizontalCenterOffset: 20
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            columns: 2

            Button {
                id: add_librarian
                text: "Add librarian"
                onClicked: {
                    add_librarian_popup.open()
                }
            }
            Button {
                id: del_librarian
                text: "Delete librarian"
                onClicked: {
                    del_librarian_popup.open()
                }
            }
        }
    }



    Popup {
        id: add_librarian_popup
        width: parent.width / 4
        height: parent.height / 1.5
        anchors.centerIn: parent

        Rectangle {
            anchors.fill: parent
            color: "cyan"
            ColumnLayout {
                id: add_librarian_column
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
                Button {
                    id: submit_btn
                    Layout.alignment: Qt.AlignHCenter |Qt.AlignVCenter
                    text: "Add librarian"
                    onClicked: {
                        if(name_input_text.text ==="" && age_input_text.text === "" && email_input_text.text === "" && pass_input_text.text === "" && gender_input_text.text === "") {
                            console.log("Please enter all values")
                        } else {
                            db.addMember(name_input_text.text, age_input_text.text, email_input_text.text, pass_input_text.text, gender_input_text.text, "librarian")
                            console.log("librarian successfully added")
                            alllibrariansmodel.updateModel(filter_textfield.text)
                            add_librarian_popup.close()
                        }
                    }
                }
            }
        }
    }

    Popup {
        id: del_librarian_popup
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
                    id: del_name_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height * 0.08
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Text {
                        id: del_name_text
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
                        id: del_name_input_text
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: del_name_text.right
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
                        if(del_name_input_text.text === "") {
                            console.log("Please enter librarian name")
                        } else if (db.checkName(del_name_input_text.text)){
                            db.delMember(del_name_input_text.text)
                            console.log("Librarian successfully deleted")
                            alllibrariansmodel.updateModel(filter_textfield.text)
                            del_librarian_popup.close()
                        } else {
                            console.log("librarian dosen't exists")
                        }
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.66;height:480;width:640}
}
##^##*/
