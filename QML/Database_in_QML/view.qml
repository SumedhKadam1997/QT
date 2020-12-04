import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Window 2.15
import QtQuick.Layouts 1.11
import QtQuick.Dialogs.qml 1.0
import QtQuick.Controls 2.0
import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2
import Database 1.0

Rectangle {
    id: mainrect
//    implicitHeight: 400
//    implicitWidth: 400

    Database {
        id : db
    }

    TableView {
        id: memberstable
        y: 72
        height: 400
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 5
        anchors.rightMargin: 5
        anchors.bottomMargin: 5
        anchors.leftMargin: 5

        TableViewColumn {
            role: "fname"
            title: "First Name"
        }
        TableViewColumn {
            role: "lname"
            title: "Last name"
        }
        TableViewColumn {
            role: "email"
            title: "Email"
        }
        TableViewColumn {
            role: "gender"
            title: "Gender"
        }
        TableViewColumn {
            role: "age"
            title: "Age"
        }
        model: mymodel
        rowDelegate: Rectangle {
            anchors.fill: parent
            color: styleData.selected ? 'skyblue' : (styleData.alternate ? 'whitesmoke' : 'white');
            MouseArea {
                anchors.fill: parent
                acceptedButtons: Qt.RightButton | Qt.LeftButton
                onClicked: {
                    tableView.selection.clear()
                    tableView.selection.select(styleData.row)
                    tableView.currentRow = styleData.row
                    tableView.focus = true

                    switch(mouse.button) {
                    case Qt.RightButton:
                        contextMenu.popup() // Call the context menu
                        break
                    default:
                        break
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
