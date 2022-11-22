import QtQuick
import QtQuick.Controls
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "cyan"

    TextInput {
        id: txtInput
        width: 150
        height: 30
        text: lv.currentItem.myData.modelData
    }

    Rectangle {
        width: 20
        height: width
        color: "red"
        anchors.left: txtInput.right
        MouseArea {
            anchors.fill: parent
            onClicked: {
                pop.open()
            }
        }
    }

    Popup {
        id: pop
        width: txtInput.width
        background: Rectangle {
            color: "transparent"
        }

        closePolicy: Popup.CloseOnPressOutside

        ListView {
            id: lv
            width: 180; height: 200
            highlight: Rectangle {id:high; color: "lightsteelblue"; radius: 2;width: lv.width}
            model: myClass.name

//            model: ListModel {
//                ListElement {
//                    name: "Bill Smith"
//                    number: "555 3264"
//                }
//                ListElement {
//                    name: "John Brown"
//                    number: "555 8426"
//                }
//                ListElement {
//                    name: "Sam Wise"
//                    number: "555 0473"
//                }
//            }
            delegate: Rectangle {
                property variant myData: model
                width: 150
                height: 50
                color: "transparent"
                Text {
                    text: modelData
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        lv.currentIndex = index
                        console.log(lv.currentItem)
                    }
                }
            }
        }
    }
}
