import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4


Rectangle {
    id: main_ListViewRect

    Button {
        id: upButton
        anchors.horizontalCenter: parent.horizontalCenter
        text: "UP"
        anchors.bottom: sqlListView.top
        anchors.bottomMargin: 10
        onClicked: {
//            sqlListView.currentRow = 1
            console.log("Up Selected")
        }
    }

    ListView {
        id: sqlListView
        width: parent.width * 0.9
        height: parent.height * 0.9
        anchors.centerIn: parent
        clip: true
        model: myModel
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
        delegate: Rectangle {
            width: sqlListView.width
            height: 30
            color: (sqlListView.currentIndex === index) ? "lightsteelblue" : "white"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    sqlListView.currentIndex = index
                }
            }
            Row {
                id: row
                anchors.fill: parent
                spacing: 10
                Text {
                    id: id_txt
                    text: ROWID
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                Text {
                    id: name_txt
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                Text {
                    id: email_txt
                    text: email
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                Text {
                    id: dob_txt
                    text: dob
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                Text {
                    id: house_number_txt
                    text: house_number
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                Text {
                    id: street_name_txt
                    text: street_name
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                Text {
                    id: city_txt
                    text: city
                    anchors.verticalCenter: parent.verticalCenter
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }
    Button {
        id: downButton
        anchors.horizontalCenter: parent.horizontalCenter
        text: "DOWN"
        anchors.top: sqlListView.bottom
        anchors.topMargin: 10
        onClicked: {
            console.log(sqlListView.currentIndex)
            sqlListView.currentIndex = myModel.rowCount() + 1
            console.log(myModel.rowCount())
            console.log(sqlListView.currentIndex)
            console.log("Down Selected")
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
