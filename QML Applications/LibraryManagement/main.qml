import QtQuick 2.5
import QtQuick.Window 2.15

Window {
    width: 1366
    height: 768
    visible: true
    title: qsTr("Library Management Application")
//    visibility: Window.FullScreen
//    flags: Qt.FramelessWindowHint

    Rectangle {
        id: main_rect
        anchors.fill: parent

        Loader {
            id: main_page_loader
            anchors.fill: parent
            source: myLogin.loginState === true ? "home_page.qml" : "login.qml"
        }
    }
}
