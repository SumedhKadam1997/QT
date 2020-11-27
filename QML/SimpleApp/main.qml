import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11
import QtQuick.Extras 1.4
import QtQuick.Shapes 1.14

ApplicationWindow{
    id: window
    width: 700;
    height: 480;
    visible: true
    title: qsTr("QT World")

    ToolBar {
        id: toolbar
        RowLayout {
            Button {
                id: setinfo
                x: -5
                y: 0
                text: qsTr("Set Info")
                onClicked:
                {
                    console.log("Set Info Clicked")
                    pageLoader.source = "setinfo.qml"
                }
            }
            Button {
                id: getinfo
                text: qsTr("Get Info")
                onClicked:
                    {
                        console.log("Get Info Clicked")
                        pageLoader.source = "getinfo.qml"
                    }
                }

        }
    }
    Rectangle {
        id: rect
        height: 440
        color: "#8c8c8c"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: toolbar.bottom
        anchors.bottom: parent.bottom
        anchors.topMargin: 1

        Loader {
            id: pageLoader
            anchors.fill: parent
            source: ""
            anchors.rightMargin: 0
            anchors.topMargin: 0

            Text {
                id: text1
                x: 96
                y: 78
                width: 436
                height: 275
                text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Welcome to Simple APP.</p>\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This app is just a demonstration of setting some data </p>\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">and then, retrieving the same data by using signals and slots.</p></body></html>"

                font.pixelSize: 20
                textFormat: Text.RichText
             }
         }
    }
}


