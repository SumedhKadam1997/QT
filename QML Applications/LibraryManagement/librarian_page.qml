import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Rectangle {
    color: "lightgreen"
    width: 1366
    height: 768

    Rectangle {
        id: librarian_header_rect
        width: parent.width
        height: parent.height * 0.1
        color: "cyan"

        RowLayout {
            id: librarian_header_row
            anchors.fill: parent
            anchors.margins: 10
            anchors.bottomMargin: 20

            Rectangle {
                id: welcome_rect
                Layout.preferredWidth: parent.width * 0.07
                Layout.preferredHeight: parent.height
                Layout.alignment: Qt.AlignVCenter
                color: "transparent"

                Text {
                    id: wel_text
                    text: qsTr("Welcome")
                    font.pixelSize: parent.height / 4
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    id: name
                    text: myLogin.Myname
                    anchors.top: wel_text.bottom
                    font.pixelSize: parent.height / 4
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 5
                }
            }
            Rectangle {
                id: home_button_rect
                Layout.preferredWidth: parent.width * 0.05
                Layout.preferredHeight: parent.height
                Layout.alignment: Qt.AlignVCenter
                color: "transparent"

                Image {
                    id: home_image
                    anchors.fill: parent
                    anchors.margins: 10
                    source: "qrc:/images/assets/home.png"

                    MouseArea {
                        id: home_image_mousearea_
                        anchors.fill: parent

                        onClicked: {
                            librarian_body_loader.source = ""
                        }
                    }
                }
            }

            Rectangle {
                id: books_rect
                Layout.preferredWidth: parent.width * 0.2
                Layout.preferredHeight: parent.height
                Layout.alignment: Qt.AlignVCenter
                radius: 10
                Text {
                    text: qsTr("All Books")
                    anchors.fill: parent
                    font.pixelSize: parent.height / 2
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        librarian_body_loader.setSource("qrc:/librarian/all_book_view.qml")
                    }
                }
            }
            Rectangle {
                id: pending_book_rect
                Layout.preferredWidth: parent.width * 0.2
                Layout.preferredHeight: parent.height
                Layout.alignment: Qt.AlignVCenter
                radius: 10
                Text {
                    text: qsTr("Pending Books")
                    anchors.fill: parent
                    font.pixelSize: parent.height / 2
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        librarian_body_loader.setSource("qrc:/librarian/pending_book_view.qml")
                    }
                }
            }
            Rectangle {
                id: issued_book_rect
                Layout.preferredWidth: parent.width * 0.2
                Layout.preferredHeight: parent.height
                Layout.alignment: Qt.AlignVCenter
                radius: 10
                Text {
                    text: qsTr("Issued Books")
                    anchors.fill: parent
                    font.pixelSize: parent.height / 2
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        librarian_body_loader.setSource("qrc:/librarian/issued_book_view.qml")
                    }
                }
            }
            Rectangle {
                id: date_rect
                Layout.preferredWidth: parent.width * 0.15
                Layout.preferredHeight: parent.height
                Layout.alignment: Qt.AlignVCenter
                color: "transparent"

                Text {
                    id: date_text
                    text: Qt.formatDateTime(new Date(), "dd/MM/yyyy")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.verticalCenterOffset: -10
                    font.pixelSize: date_rect.height / 3
                    anchors.horizontalCenter: parent.horizontalCenter

                }
                Text {
                    id: timeText_
                    text: Qt.formatDateTime(new Date(), "hh:mm")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.top: date_text.bottom
                    font.pixelSize: date_rect.height / 4
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Timer {
                    id: timer_
                    interval: 60000
                    repeat: true
                    running: true

                    onTriggered:
                    {
                        timeText_.text =  Qt.formatTime(new Date(),"hh:mm")
                        date_text.text = Qt.formatDate(new Date(), "dd/MM/yyyy")
                    }
                }
            }
            Rectangle {
                id: logout_rect
                color: "transparent"
                Layout.preferredWidth: parent.width * 0.05
                Layout.preferredHeight: parent.width * 0.04
                Layout.alignment: Qt.AlignVCenter

                Image {
                    id: logout_image
                    anchors.fill: parent
                    source: "qrc:/images/assets/logout.png"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        myLogin.setLoginState(false)
                    }
                }
            }
            Rectangle {
                id: quit_rect
                color: "transparent"
                Layout.preferredWidth: parent.width * 0.05
                Layout.preferredHeight: parent.width * 0.05
                Layout.alignment: Qt.AlignVCenter

                Image {
                    id: quit_image
                    anchors.fill: parent
                    source: "qrc:/images/assets/quit.png"
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        Qt.callLater(Qt.quit)
                    }
                }
            }
        }
    }

    Rectangle {
        id: librarian_body_rect
        width: parent.width
        height: parent.height * 0.9
        anchors.top: librarian_header_rect.bottom
        color: "skyblue"

        Rectangle {
            id: rectangle
            anchors.centerIn: parent
            width: parent.width * 0.5
            height: parent.height * 0.8
            color: "lightgreen"

            ColumnLayout {
                anchors.fill: parent
                spacing: 20

                Rectangle {
                    id: name_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height * 0.08
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Text {
                        id: name_text
                        width: parent.width / 4
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("Name : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        color: "black"
                    }
                    Text {
                        id: name__text
                        anchors.top: parent.top
                        text: myLogin.Myname
                        anchors.bottom: parent.bottom
                        anchors.left: name_text.right
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width / 6
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                Rectangle {
                    id: age_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height * 0.08
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Text {
                        id: age_text
                        width: parent.width / 4
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("Age : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        color: "black"
                    }
                    Text {
                        id: age__text
                        anchors.top: parent.top
                        text: myLogin.MyAge
                        anchors.bottom: parent.bottom
                        anchors.left: age_text.right
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width / 6
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                Rectangle {
                    id: email_rect
                    Layout.preferredWidth: parent.width
                    Layout.preferredHeight: parent.height * 0.08
                    color: "transparent"
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Text {
                        id: email_text
                        width: parent.width / 4
                        fontSizeMode: Text.Fit
                        anchors.left: parent.left
                        anchors.leftMargin: parent.width / 10
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        text: qsTr("E-Mail : ")
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        color: "black"
                    }
                    Text {
                        id: email__text
                        anchors.top: parent.top
                        text: myLogin.MyEmail
                        anchors.bottom: parent.bottom
                        anchors.left: email_text.right
                        anchors.right: parent.right
                        anchors.rightMargin: parent.width / 6
                        font.pixelSize: parent.height / 3
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                    }
                }
            }
        }

        Loader {
            id: librarian_body_loader
            anchors.fill: parent
            source: ""
        }
    }
}

