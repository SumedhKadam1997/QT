import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

//    Flickable {
//        id: fl
//        width: parent.width; height: parent.height - buttRow.height
//        contentWidth: width * sc
//        contentHeight: list.contentItem.height
//        clip: true

        ListView {
            id: listView
            anchors.centerIn: parent
            width: 110
            height: 160
            orientation: ListView.Horizontal
            flickableDirection: Flickable.HorizontalAndVerticalFlick
            model: ListModel {
                ListElement {
                    name: "Grey"
                    colorCode: "grey"
                }

                ListElement {
                    name: "Red"
                    colorCode: "red"
                }

                ListElement {
                    name: "Blue"
                    colorCode: "blue"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }
            }
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    Rectangle {
                        width: 40
                        height: 40
                        color: colorCode
                    }

                    Text {
                        text: name
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }
                    spacing: 10
                }
            }
        }
//        ScrollBar.horizontal: ScrollBar { active: true; visible: true }
//        ScrollBar.vertical: ScrollBar { active: true; visible: true }
//      }
}
