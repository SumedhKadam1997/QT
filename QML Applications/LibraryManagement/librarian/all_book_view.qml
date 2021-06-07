import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Shapes 1.14
import QtQuick.Controls.Styles 1.0
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.15

Rectangle {

    Rectangle {
        id: admin_all_books_rect
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
                allbooksmodel.updateModel(filter_textfield.text)
            }
            Component.onCompleted: {
                allbooksmodel.updateModel(filter_textfield.text)
            }
        }

        OldControls.TableView {
            id: all_books_table_view
            width: parent.width * 0.8
            height: parent.height * 0.8
            anchors.top: filter_textfield.bottom
            anchors.topMargin: 40
            model: allbooksmodel
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
                height: all_books_table_view.height * 0.08
                width: all_books_table_view.width
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
                height: all_books_table_view.height * 0.05
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
                        console.log(allbooksmodel.index)
                        allbooksmodel.removeRow()
                        allbooksmodel.updateModel(filter_textfield.text)
                    }
                }
            }
            OldControls.TableViewColumn {
                width: all_books_table_view.width * 0.2
                role: "name"
                title: "Name"
            }
            OldControls.TableViewColumn {
                width: all_books_table_view.width * 0.2
                role: "author"
                title: "Author"
            }
            OldControls.TableViewColumn {
                width: all_books_table_view.width * 0.2
                role: "publication"
                title: "Publication"
            }
            OldControls.TableViewColumn {
                width: all_books_table_view.width * 0.3
                role: "ISBN"
                title: "ISBN Number"
            }
            OldControls.TableViewColumn {
                width: all_books_table_view.width * 0.1
                role: "quantity"
                title: "Quantity"
            }
        }


    }

    Rectangle {
        id: admin_books_rect
        width: parent.width * 0.3
        height: parent.height
        anchors.left: admin_all_books_rect.right
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

        GridLayout {
            id: buttonsGrid
            width: parent.width * 0.8
            height: parent.height * 0.6
            anchors.top: books_text.bottom
            anchors.horizontalCenterOffset: 20
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
            columns: 2


            Button {
                id: add_book
                text: "Add Book"
                onClicked: {
                    add_book_popup.open()
                }
            }
            Button {
                id: del_book
                text: "Delete Book"
                onClicked: {
                    del_book_popup.open()
                }
            }
        }
    }

    Popup {
        id: add_book_popup
        width: parent.width / 4
        height: parent.height / 1.5
        anchors.centerIn: parent

        Rectangle {
            anchors.fill: parent
            color: "cyan"
            ColumnLayout {
                id: add_book_column
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
                    id: isbn_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height * 0.08
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Text {
                        id: isbn_text
                        width: parent.width / 4
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("ISBN : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        color: "black"
                    }
                    TextField {
                        id: isbn_input_text
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: isbn_text.right
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width / 6
                        font.pixelSize: parent.height / 3
                    }
                }
                Rectangle {
                    id: author_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height * 0.08
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Text {
                        id: author_text
                        width: parent.width / 4
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("Author : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        color: "black"
                    }
                    TextField {
                        id: author_input_text
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: author_text.right
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width / 6
                        font.pixelSize: parent.height / 3
                    }
                }
                Rectangle {
                    id: pub_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height * 0.08
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Text {
                        id: pub_text
                        width: parent.width / 4
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("Publication : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        color: "black"
                    }
                    TextField {
                        id: pub_input_text
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: pub_text.right
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width / 6
                        font.pixelSize: parent.height / 3
                    }
                }
                Rectangle {
                    id: quant_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height * 0.08
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Text {
                        id: quant_text
                        width: parent.width / 4
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("Quantity : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        color: "black"
                    }
                    TextField {
                        id: quant_input_text
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        anchors.left: quant_text.right
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width / 6
                        font.pixelSize: parent.height / 3
                    }
                }
                Button {
                    id: submit_btn
                    Layout.alignment: Qt.AlignHCenter |Qt.AlignVCenter
                    text: "Add Book"
                    onClicked: {
                        if(name_input_text.text ==="" && isbn_input_text.text === "" && author_input_text.text === "" && pub_input_text.text === "" && quant_input_text.text === "") {
                            console.log("Please enter all values")
                        } else {
                            db.addBook(name_input_text.text, isbn_input_text.text, author_input_text.text, pub_input_text.text, quant_input_text.text)
                            console.log("Book successfully added")
                            allbooksmodel.updateModel(filter_textfield.text)
                            add_book_popup.close()
                        }
                    }
                }
            }
        }
    }

    Popup {
        id: del_book_popup
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
                            console.log("Please enter book name")
                        } else if (db.checkBook("books", del_name_input_text.text)){
                            db.delBook("books", del_name_input_text.text)
                            console.log("Book successfully deleted")
                            allbooksmodel.updateModel(filter_textfield.text)
                            del_book_popup.close()
                        } else {
                            console.log("Book dosen't exists")
                        }
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.1;height:480;width:640}
}
##^##*/
