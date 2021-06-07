import QtQuick 2.0

Rectangle {
    id: home

    Loader {
        id: home_loader
        anchors.fill: parent
        source: myLogin.loaderName === "admin" ? "admin_page.qml" : "other_page.qml"
    }
}
