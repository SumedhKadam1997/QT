import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
//    width: Screen.width
//    height: Screen.height
    width: 250
    height: 200
    visible: true
    title: qsTr("CSV Writer")

    Button {
        id: btn
        text: "Add"
        anchors.centerIn: parent
        onClicked: {
            csv.setPlayer1Score(2, "34")
        }
    }
    Button {
        id: btn2
        text: "Get"
        anchors.left: btn.right
        anchors.verticalCenter:  btn.verticalCenter
        onClicked: {
            csv.getPlayer1Score()
        }
    }
}
