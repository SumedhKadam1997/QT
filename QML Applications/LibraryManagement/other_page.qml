import QtQuick 2.0

Rectangle {
    id: other_home

    Loader {
        id: home_loader
        anchors.fill: parent
        source: myLogin.loaderName === "student" ? "student_page.qml" : "librarian_page.qml"
    }
}
