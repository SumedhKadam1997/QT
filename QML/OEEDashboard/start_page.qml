import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls 2.15
import QtQuick.Dialogs.qml 1.0
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.11
import QtQuick.Shapes 1.14
import QtCharts 2.3
import Database 1.0


Rectangle {
    id: start_page_rect
    width: myQmlProp.body_width
    height: myQmlProp.body_height

    Rectangle {
        id: list_rectangle
        height: 600
        color: "#2d2f39"
        anchors.left: parent.left
        anchors.right: graph_rectangle.left
        anchors.top: parent.top
        anchors.bottom: alarm_rectangle.top
        anchors.bottomMargin: 5
        anchors.rightMargin: 5
        anchors.topMargin: 0
        anchors.leftMargin: 0

        Loader {
            id: list_rectangle_loader
            source: "list_rectangle.qml"
        }
    }

    Rectangle {
        id: graph_rectangle
        x: 848
        y: 0
        width: 1147
        height: 1055
        color: "black"

        Loader {
            id: graph_loader
            anchors.fill: parent
            source: "graph_rectangle.qml"
        }
    }

    Rectangle {
        id: alarm_rectangle
        y: 604
        height: 451
        color: "#2d2f39"
        anchors.left: parent.left
        anchors.right: graph_rectangle.left
        anchors.leftMargin: 0
        anchors.rightMargin: 5

        Rectangle {
            id: alarms_rect
            color: "#2d2f39"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
        }

        Row {
            id: alarm_buttons_row
            height: 60
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.leftMargin: 0

            Rectangle {
                property bool iswhite: true
                id: alarm_button
                width: 200
                radius: 10
                color: "#172d44"
                anchors.left: alarm_buttons_row.left
                anchors.right: layout_button.left
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.rightMargin: 20
                anchors.leftMargin: 10
                anchors.topMargin: 10
                anchors.bottomMargin: 0
                border.color: iswhite ? "blue" : "black"
                border.width: 5

                Text {
                    id: alarm_button_text
                    anchors.fill: parent
                    text: "Alarms"
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 20
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        alarm_button.iswhite =! alarm_button.iswhite
                        layout_button.iswhite =! layout_button.iswhite

                    }
                }
            }
            Rectangle {
                property bool iswhite: false
                id: layout_button
                width: 200
                radius: 10
                color: "#172d44"
                anchors.left: alarm_button.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.leftMargin: 20
                anchors.topMargin: 10
                anchors.bottomMargin: 0
                border.color: iswhite ? "blue" : "black"
                border.width: 5

                Text {
                    id: layout_button_text
                    anchors.fill: parent
                    text: "Layout"
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 20

                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        layout_button.iswhite =! layout_button.iswhite
                        alarm_button.iswhite =! alarm_button.iswhite

                    }
                }
            }
        }

        Rectangle {
            id: view_rect
            y: 126
            height: 186
            color: "#14141a"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: alarm_buttons_row.bottom
            anchors.bottom: parent.bottom
            anchors.rightMargin: 8
            anchors.leftMargin: 8
            anchors.bottomMargin: 8
            anchors.topMargin: 13

            Column {
                id: alarms_column
                anchors.fill: parent
                anchors.bottomMargin: -406737
                spacing: 5

                Rectangle {
                    height: 40
                    width: parent.width
                    border.color: "black"
                    border.width: 3
                    radius: 5
                    gradient: Gradient {
                        GradientStop { position: -1.0; color: "white" }
                        GradientStop { position: 1.5; color: "black" }
                    }
                }
                Rectangle {
                    height: 40
                    width: parent.width
                    border.color: "black"
                    border.width: 3
                    radius: 5
                    gradient: Gradient {
                        GradientStop { position: -1.0; color: "white" }
                        GradientStop { position: 1.5; color: "black" }
                    }
                }
                Rectangle {
                    height: 40
                    width: parent.width
                    border.color: "black"
                    border.width: 3
                    radius: 5
                    gradient: Gradient {
                        GradientStop { position: -1.0; color: "white" }
                        GradientStop { position: 1.5; color: "black" }
                    }
                }
                Rectangle {
                    height: 40
                    width: parent.width
                    border.color: "black"
                    border.width: 3
                    radius: 5
                    gradient: Gradient {
                        GradientStop { position: -1.0; color: "white" }
                        GradientStop { position: 1.5; color: "black" }
                    }
                }
                Rectangle {
                    height: 40
                    width: parent.width
                    border.color: "black"
                    border.width: 3
                    radius: 5
                    gradient: Gradient {
                        GradientStop { position: -1.0; color: "white" }
                        GradientStop { position: 1.5; color: "black" }
                    }
                }
                Rectangle {
                    height: 40
                    width: parent.width
                    border.color: "black"
                    border.width: 3
                    radius: 5
                    gradient: Gradient {
                        GradientStop { position: -1.0; color: "white" }
                        GradientStop { position: 1.5; color: "black" }
                    }
                }
                Rectangle {
                    height: 40
                    width: parent.width
                    border.color: "black"
                    border.width: 3
                    radius: 5
                    gradient: Gradient {
                        GradientStop { position: -1.0; color: "white" }
                        GradientStop { position: 1.5; color: "black" }
                    }
                }
                Rectangle {
                    height: 40
                    color: "#ffffff"
                    width: parent.width
                    border.color: "black"
                    border.width: 3
                    radius: 5
                    gradient: Gradient {
                        GradientStop { position: -1.0; color: "white" }
                        GradientStop { position: 1.5; color: "black" }
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.25}
}
##^##*/
