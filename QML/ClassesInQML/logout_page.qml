import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
Rectangle {
    color: "black"

    Button {
        x: parent.width/2
        y: parent.height/2
        text: "Log Out"
        anchors.centerIn: parent.Center
        onClicked:
        {

            console.log("logout")
            pageLoader.source = "login_page.qml"
        }
    }
}
