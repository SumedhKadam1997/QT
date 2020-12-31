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


ApplicationWindow {
    id: window
    width: Screen.width
    height: Screen.height
    color: "#131c21"
    visible: true
    title: qsTr("OEE Dashboard")

    Component.onCompleted: {
        window.showFullScreen();
        myQmlProp.setBody_width(Screen.width)
        myQmlProp.setTitlebar_width(Screen.width)
        myQmlProp.setTitlebar_height(100)
        myQmlProp.setBody_height(Screen.height - myQmlProp.titlebar_height)
    }

    Rectangle {
        id: oee_main_rectangle
        color: "#14141a"
        height: myQmlProp.titlebar_height
        width: myQmlProp.titlebar_width
        anchors.top: parent.top
        anchors.topMargin: 0

        Image {
            id: logo
            width: 247
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            verticalAlignment: Image.AlignVCenter
            source: "file:C:\\Users\\uxoriousghost\\Documents\\OEEDashboard\\pics\\smartleaven_logo.png"
            anchors.bottomMargin: 10
            anchors.topMargin: 10
            anchors.leftMargin: 10

            MouseArea {
                id: logo_mousearea
                anchors.fill: parent

                onClicked: {
                    start_page_loader.source = "start_page.qml"
                }
            }
        }

        Rectangle {
            id: date_rect
            x: 1620
            width: 200
            height: 37
            radius: 5
            color: "#2d2f39"
            anchors.right: outer_quit_rect.left
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.rightMargin: 20

            Text {
                text: Qt.formatDateTime(new Date(), "dd/MM/yyyy")
                anchors.fill: parent
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
        Rectangle {
            id: time_rect
            x: 1620
            width: 200
            radius: 5
            color: "#2d2f39"
            anchors.right: outer_quit_rect.left
            anchors.top: date_rect.bottom
            anchors.bottom: parent.bottom
            anchors.topMargin: 6
            anchors.bottomMargin: 10
            anchors.rightMargin: 20

            Text {
                id: timeText
                text: Qt.formatDateTime(new Date(), "hh:mm")
                anchors.fill: parent
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 15
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Timer {
                id: timer
                interval: 60000
                repeat: true
                running: true

                onTriggered:
                {
                    timeText.text =  Qt.formatTime(new Date(),"hh:mm")
                }
            }
        }

        Rectangle {
            id: last_updated_rect
            x: 1420
            width: 177
            radius: 15
            anchors.right: parent.right
            anchors.top: time_rect.bottom
            anchors.bottom: parent.bottom
            anchors.rightMargin: 323
            anchors.bottomMargin: 10
            anchors.topMargin: -77
            color: "#2d2f39"

            Text {
                id: last_updated_Text
                width: 144
                text: "Last Updated"
                color: "white"
                anchors.top: parent.top
                anchors.bottom: last_updated_time.top
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.bottomMargin: 6
                anchors.topMargin: 10
                anchors.horizontalCenterOffset: 0
                font.pointSize: 15
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                id: last_updated_time
                x: 41
                y: 41
                width: 96
                height: 26
                color: "white"
                text: qsTr(Qt.formatDateTime(new Date(), "hh:mm"))
                //                anchors.top: last_updated_Text.bottom
                anchors.bottom: parent.bottom
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.bottomMargin: 10
                anchors.topMargin: 5
                font.pointSize: 20
            }
        }

        Rectangle {
            id: outer_quit_rect
            x: 1835
            width: 60
            height: 60
            radius: 5
            color: "#ffffff"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.rightMargin: 20
            anchors.topMargin: 20

            Rectangle {
                id: inner_quit_rect
                radius: 5
                anchors.left: parent.left
                //                color: "red"
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.leftMargin: 5
                anchors.rightMargin: 5
                anchors.bottomMargin: 5
                anchors.topMargin: 5
            }

            MouseArea {
                anchors.fill: parent
                onClicked: Qt.callLater(Qt.quit)

                Rectangle {
                    id: rectangle1
                    x: 1
                    y: 28
                    width: 60
                    height: 5
                    color: "#ffffff"
                    rotation: 45
                }
                Rectangle {
                    id: rectangle2
                    x: 1
                    y: 28
                    width: 60
                    height: 5
                    color: "#ffffff"
                    rotation: 135
                }
            }
        }

        Rectangle {
            id: machine_location_rect
            width: 219
            radius: 10
            anchors.left: logo.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 30
            anchors.bottomMargin: 10
            anchors.topMargin: 10
            gradient: Gradient {
                GradientStop { position: -2.0; color: "white" }
                GradientStop { position: 1.5; color: "black" }
            }

            Text {
                id: shop_name_text
                x: 21
                y: 8
                width: 181
                height: 32
                color: "white"
                text: qsTr("Shop Name")
                font.pixelSize: 30
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: machine_name_text
                x: 80
                y: 46
                width: 60
                height: 23
                color: "white"
                text: qsTr("M/C Name")
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        Rectangle {
            property bool flash: true
            id: current_alarm_flash_rect
            radius: 10
            anchors.left: machine_location_rect.right
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.rightMargin: 806
            anchors.leftMargin: 20
            anchors.bottomMargin: 10
            anchors.topMargin: 10
            //            border.color: "red"
            border.color: flash ? "red" : "black"
            border.width: 5
            gradient: Gradient {
                GradientStop { position: -2.0; color: "white" }
                GradientStop { position: 1.5; color: "black" }
            }

            Text {
                id: main_alarm_text
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 20
                color: "red"
                text: qsTr("CURRENT ALARM")
            }
            Timer {
                id: alarm_flash_timer
                interval: 500
                running: true
                repeat: true
                onTriggered:
                    current_alarm_flash_rect.flash =! current_alarm_flash_rect.flash

            }
        }

        Rectangle {
            id: insert_new_data
            radius: 5
            anchors.left: current_alarm_flash_rect.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 15
            anchors.topMargin: 10
            anchors.bottomMargin: 10
            width: 78

            Image {
                id: insert_image
                anchors.fill: parent
                source: "file:C:\\Users\\uxoriousghost\\Documents\\OEEDashboard\\pics\\image.png"
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    start_page_loader.source = "input_values.qml"
                }
            }
        }

        Rectangle{
            id: notifications_rect
            y: 10
            radius: 5
            width: 78
            height: 77
            anchors.left: current_alarm_flash_rect.right

            anchors.leftMargin: 113
            Image {
                id: notifications_image
                anchors.fill: parent
                source: "file:C:\\Users\\uxoriousghost\\Documents\\OEEDashboard\\pics\\notifications_logo.png"

            }
        }
        Rectangle{
            id: settings_rect
            x: 1324
            width: 77
            radius: 5
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.topMargin: 10
            Image {
                id: settings_image
                anchors.fill: parent
                source: "file:C:\\Users\\uxoriousghost\\Documents\\OEEDashboard\\pics\\settings_logopng.png"
            }
            MouseArea {
                id: settings_mousearea
                anchors.fill: parent

                onClicked: {
                    start_page_loader.source = "settings.qml"
                    //                    start_page_loader.change =! start_page_loader.change
                }
            }
        }
    }
    Rectangle {
        id: main_rectangle
        color: "black"
        anchors.bottom: parent.bottom
        width: myQmlProp.body_width
        height: myQmlProp.body_height

        Loader {
            property bool change: true
            id:start_page_loader
            anchors.fill: parent
            source: "start_page.qml"
            //            source: (change == true) ? "start_page.qml" : "settings.qml"
        }
    }
}


/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/
