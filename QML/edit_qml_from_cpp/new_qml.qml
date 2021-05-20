import QtQuick 2.0
import QtQuick.Controls 2.5

Rectangle {
    id: rect

    signal menuClicked(string str)

    Button {
        text: qsTr("Click Me")
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked:  rect.menuClicked(text)
    }

}
