import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Shapes 1.14
import QtQuick.Controls.Styles 1.0
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.15

Rectangle {

    Rectangle {
        id: student_pending_books_rect
        width: parent.width * 0.7
        height: parent.height
        color: "skyblue"

        TextField {
            id: filter_textfield
            verticalAlignment: Text.AlignVCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            placeholderText: "Search Books"
            onTextChanged: {
                allissuedmodel.updateModel(filter_textfield.text)
            }
            Component.onCompleted: {
                allissuedmodel.updateModel(filter_textfield.text)
            }
        }

        OldControls.TableView {
            id: pending_books_table_view
            width: parent.width * 0.8
            height: parent.height * 0.8
            anchors.top: filter_textfield.bottom
            anchors.topMargin: 40
            model: allissuedmodel
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
                height: pending_books_table_view.height * 0.08
                width: pending_books_table_view.width
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
                height: pending_books_table_view.height * 0.05
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
            }
            OldControls.TableViewColumn {
                width: pending_books_table_view.width * 0.2
                role: "name"
                title: "Name"
            }
            OldControls.TableViewColumn {
                width: pending_books_table_view.width * 0.3
                role: "student_email"
                title: "Email"
            }
            OldControls.TableViewColumn {
                width: pending_books_table_view.width * 0.3
                role: "date"
                title: "Date"
            }
        }
    }

    Rectangle {
        id: student_books_rect
        width: parent.width * 0.3
        height: parent.height
        anchors.left: student_pending_books_rect.right
        color: "lightgreen"

        Text {
            id: books_text
            text: qsTr("Books Operations")
            anchors.top: parent.top
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 20
        }

//        GridLayout {
//            id: buttonsGrid
//            width: parent.width * 0.8
//            height: parent.height * 0.6
//            anchors.top: books_text.bottom
//            anchors.horizontalCenterOffset: 20
//            anchors.topMargin: 20
//            anchors.horizontalCenter: parent.horizontalCenter
//            columns: 2


//            Button {
//                id: submit_book_btn
//                text: "Submit Book"
//                onClicked: {
//                    submit_book_popup.open()
//                }
//            }
//        }
    }

//    Popup {
//        id: submit_book_popup
//        width: parent.width / 4
//        height: parent.height / 1.5
//        anchors.centerIn: parent

//        Rectangle {
//            anchors.fill: parent
//            color: "cyan"
//            ColumnLayout {
//                id: submit_book_column
//                anchors.fill: parent

//                Rectangle {
//                    id: submit_book_rect
//                    Layout.preferredWidth: parent.width
//                    Layout.preferredHeight: parent.height * 0.08
//                    color: "transparent"
//                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
//                    Text {
//                        id: submit_book_text
//                        width: parent.width / 4
//                        fontSizeMode: Text.Fit
//                        anchors.left: parent.left
//                        anchors.leftMargin: parent.width / 10
//                        anchors.top: parent.top
//                        anchors.bottom: parent.bottom
//                        text: qsTr("Name : ")
//                        font.pixelSize: parent.height / 3
//                        horizontalAlignment: Text.AlignLeft
//                        verticalAlignment: Text.AlignVCenter
//                        color: "black"
//                    }
//                    TextField {
//                        id: submit_book_input_text
//                        anchors.top: parent.top
//                        anchors.bottom: parent.bottom
//                        anchors.left: submit_book_text.right
//                        anchors.right: parent.right
//                        anchors.rightMargin: parent.width / 6
//                        font.pixelSize: parent.height / 3
//                    }
//                }
//                Button {
//                    id: request_btn
//                    Layout.alignment: Qt.AlignHCenter |Qt.AlignVCenter
//                    text: "Request"
//                    onClicked: {
//                        if(submit_book_input_text.text === "") {
//                            console.log("Please enter book name")
//                        } else if (db.checkBook("issued_books", submit_book_input_text.text)){
//                            db.delBook("issued_books", submit_book_input_text.text)
//                            console.log("Book successfully Deleted")
//                            allissuedmodel.updateModel(filter_textfield.text)
//                            submit_book_popup.close()
//                        } else {
//                            console.log("Book dosen't exists")
//                        }
//                    }
//                }
//            }
//        }
//    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.1;height:480;width:640}
}
##^##*/
