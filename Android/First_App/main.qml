import QtQuick 2.12
import QtQuick.Window 2.0

Window {
    width: Screen.width
    height: Screen.height
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        width: 100
        height: 100
        color: "red"
        anchors.horizontalCenter: parent
    }

    ListView {
        id: listView
        anchors.centerIn: parent
        width: 110
        height: 160
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

}
