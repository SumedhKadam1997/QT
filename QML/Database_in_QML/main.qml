import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Window 2.15
import QtQuick.Layouts 1.11
import QtQuick.Dialogs.qml 1.0
import QtQuick.LocalStorage 2.12
import Database 1.0


Window {
    id: window
    width: 800
    height: 480
    visible: true
    title: qsTr("Databases in QML")


    RowLayout{
        Button{
            id: viewbutton
            text: "View Table"

            onClicked: {
                console.log("Opening View QML")
                pageLoader.source = "view.qml"
            }
        }
        Button{
            id: addbutton
            text: "Add to Table"

            onClicked: {
                console.log("Opening Add QML")
                pageLoader.source = "add.qml"
            }
        }
        Button{
            id: currdatabutton
            text: "View Current Data"

            onClicked: {
                console.log("Opening Curr_Data QML")
                pageLoader.source = "curr_data.qml"
            }
        }
    }
    Rectangle {
        id: rect
        x: 0
        width: parent.width;
        color: "#8c8c8c"
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.topMargin: 40
        anchors.bottomMargin: 0

        Loader {
            id: pageLoader
            anchors.fill: parent
            source: ""
            anchors.rightMargin: 0
            anchors.topMargin: 0

            Text {
                id: text1
                text: "Simple App integrating Databases in Qt QML"
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignTop
                minimumPixelSize: 12
                minimumPointSize: 12
                anchors.rightMargin: 20
                anchors.leftMargin: 20
                anchors.bottomMargin: 20
                anchors.topMargin: 20
                textFormat: Text.RichText
            }
        }
    }
}

