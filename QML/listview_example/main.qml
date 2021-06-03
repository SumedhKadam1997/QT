import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    id: window
    width: 640
    height: 480
    visible: true
    color: "gray"


    ListModel {
        id: coloursModel
        ListElement { name: "orange"}
        ListElement { name: "red"}
        ListElement { name: "green"}
        ListElement { name: "yellow"}
        ListElement { name: "cyan"}
        ListElement { name: "teal"}
    }

    Button {
        id: up_btn
        anchors.bottom: listview_rect.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20
        text: "GO UP"
        onClicked: {
            if(colours_listview.currentIndex != 0) {
                colours_listview.currentIndex = colours_listview.currentIndex - 1
            }
        }
    }

    Rectangle {
        id: listview_rect
        width: parent.width / 3
        height: parent.height / 2
        anchors.centerIn: parent

        ListView {
            id: colours_listview
            anchors.fill: parent
            model: coloursModel
            currentIndex: 0
            clip: true
            delegate: Rectangle {
                id: delegateRect
                width: colours_listview.width
                height: 40
                color: (colours_listview.currentIndex == index) ? "lightsteelblue" : "white"
                border.color: "black"
                border.width: 1
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        colours_listview.currentIndex = index
                    }
                }
                Rectangle {
                    id:colour_rect
                    width: 20
                    height: 20
                    color: name
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                }

                Text {
                    id: colours_text
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: colour_rect.right
                    anchors.leftMargin: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            onCurrentItemChanged: console.log(coloursModel.get(colours_listview.currentIndex).name + ' selected')
        }
    }

    Button {
        id: down_btn
        anchors.top: listview_rect.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        text: "GO DOWN"
        onClicked: {
            if(colours_listview.currentIndex != coloursModel.count - 1) {
                colours_listview.currentIndex = colours_listview.currentIndex + 1
            }
        }
    }
}
