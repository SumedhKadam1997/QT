
import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello QML")
    signal menuClicked(string str)

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                shortcut: "Ctrl+Q"
                onTriggered: Qt.quit()
            }
            MenuItem {
                text: qsTr("Click Me")
                onTriggered: window.menuClicked(text)
            }
        }
    }

    Text {
        id: hw
        text: qsTr("Hello World")
        font.capitalization: Font.AllUppercase
        anchors.centerIn: parent
    }

    Label {
        anchors { bottom: hw.top; bottomMargin: 5; horizontalCenter: hw.horizontalCenter }
        text: qsTr("Hello Qt Quick")
    }
}
