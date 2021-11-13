import QtQuick 2.0

Rectangle {
    id: main_rect

    Rectangle {
        id: login_form_rect
        width: parent.width / 1.5
        height: parent.height

        Loader {
            id: login_form_loader
            anchors.fill: parent
            source: "login.qml"
        }
    }
    Rectangle {
        id: info_rect
        width: parent.width - login_form_rect.width
        height: parent.height
        anchors.left: login_form_rect.right
        color: "black"

        Loader {
            id: info_loader
            anchors.fill: parent
            source: "go_to_signup.qml"
        }
    }
}
