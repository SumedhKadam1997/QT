import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: window
    width: 640;
    height: 480;
    visible: true
    title: qsTr("QT World")

    ToolBar{
        anchors.top: parent.top
        anchors.bottom: rect.top
        RowLayout {
            Button {
                id: login
                x: -5
                y: 0
                text: qsTr("Log In")
                onClicked:
                {

                    console.log("login")
                    pageLoader.source = "login_page.qml"
                }
            }
            Button {
                id: register
                x: -5
                y: 0
                text: qsTr("Register")
                onClicked:
                {
                    console.log("register")
                    pageLoader.source = "register_page.qml"
                }
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
                x: 96
                y: 78
                width: 436
                height: 275
                text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Welcome to Simple Login APP.</p>\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This app is integrated with SQL Database and has functionalities for</p>\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> logging in a user, registering a new user and logging out a user.</p></body></html>"
                font.pixelSize: 12
                textFormat: Text.RichText
             }
         }
    }
}



/*##^##
Designer {
    D{i:0;formeditorZoom:1.3300000429153442}D{i:5}
}
##^##*/
