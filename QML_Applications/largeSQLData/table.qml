import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4 as OldControls
import QtQuick.Controls 2.15
import Qt.labs.qmlmodels 1.0


Rectangle {
    id: main_TableViewRect

    Button {
        id: upButton
        anchors.horizontalCenter: parent.horizontalCenter
        text: "UP"
        anchors.bottom: sqlTableView.top
        anchors.bottomMargin: 10
        onClicked: {
            sqlTableView.currentRow = 1
            console.log("Up Selected")
        }
    }

    //    HorizontalHeaderView {
    //        id: horizontalHeader
    //        syncView: sqlTableView
    //        anchors.bottom: sqlTableView.top
    //        width: sqlTableView.width
    //    }

    OldControls.TableView {
        id: sqlTableView
        width: parent.width * 0.9
        height: parent.height * 0.8
        anchors.centerIn: parent
        clip: true
        model: myModel


        //        delegate: Rectangle {
        //            width: 100
        //            height: 50
        //            Text {
        //                id: name
        //                text: student.name
        //            }
        //        }

        //        property alias tableVerticalBar: tableVerticalBar
        //        ScrollBar.vertical: ScrollBar {
        //            id: tableVerticalBar;
        //            policy:ScrollBar.AlwaysOn
        //        }

        OldControls.TableViewColumn {
            width: sqlTableView.width * 0.07
            role: "ROWID"
            title: "ID"
        }
        OldControls.TableViewColumn {
            width: sqlTableView.width * 0.15
            role: "name"
            title: "Name"
        }
        OldControls.TableViewColumn {
            width: sqlTableView.width * 0.3
            role: "email"
            title: "Email"
        }
        OldControls.TableViewColumn {
            width: sqlTableView.width * 0.05
            role: "dob"
            title: "DOB"
        }
        OldControls.TableViewColumn {
            width: sqlTableView.width * 0.3
            role: "street_name"
            title: "Street Name"
        }
        OldControls.TableViewColumn {
            width: sqlTableView.width * 0.15
            role: "city"
            title: "City"
        }
    }
    Button {
        id: downButton
        anchors.horizontalCenter: parent.horizontalCenter
        text: "DOWN"
        anchors.top: sqlTableView.bottom
        anchors.topMargin: 10
        onClicked: {
//            sqlTableView.currentRow = sqlTableView.currentRow + 1
            sqlTableView.currentRow = myModel.rowCount() - 1
            //            sqlTableView.tableVerticalBar.setPosition(1 - tableVerticalBar.size)
//            sqlTableView.flick(-1, -1000)
            console.log(myModel.rowCount())
            console.log("Down Selected")
        }
    }

}
