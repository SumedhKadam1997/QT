import QtQuick 2.12
import QtQuick.Window 2.12
import MyLang 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("MultiLingualApp")

    Rectangle {
        id: main_rect
        anchors.fill: parent
        color: "teal"

        QtObject {
            id: week_names
            property var daysOfWeek: [qsTr("Monday"), qsTr("Tuesday"),
                qsTr("Wednesday"), qsTr("Thursday"),
                qsTr("Friday"), qsTr("Saturday"), qsTr("Sunday")]
        }
        Repeater {
            model: week_names.daysOfWeek.length
            Rectangle {
                width: parent.width / 3
                height: 30
                color: "skyblue"
                anchors.horizontalCenter: parent.horizontalCenter
                y: parent.height * 0.12 * index
                Text {
                    id: txt_weekdays
                    text: qsTr(week_names.daysOfWeek[index]) + myTranslate.emptyString
                    font.pixelSize: parent.height / 2
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
        Rectangle {
            x: 69
            y: 69
            width: 70
            height: 30
            Text {
                id: txt_Hindi
                anchors.centerIn: parent
                text: qsTr("HINDI")
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    myTranslate.changeLanguage(MyLang.HIN)
                    console.log("Hindi Clicked")
                }
            }
        }
        Rectangle {
            x: 69
            y: 119
            width: 70
            height: 30
            Text {
                id: txt_Japanese
                anchors.centerIn: parent
                text: qsTr("JAPANESE")
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        myTranslate.changeLanguage(MyLang.JAP)
                        console.log("Japanese Clicked")
                    }
                }
            }
        }
        Rectangle {
            x: 69
            y: 169
            width: 70
            height: 30
            Text {
                id: txt_English
                anchors.centerIn: parent
                text: qsTr("ENGLISH")
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        myTranslate.changeLanguage(MyLang.ENG)
                        console.log("English Clicked")
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
