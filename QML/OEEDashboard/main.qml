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
    width: 1920
    height: 1080
    color: "#131c21"
    visible: true
    title: qsTr("OEE Dashboard")

    Loader {
        id: newloader
        anchors.fill: parent
        source: "mode_one.qml"
    }

    Component.onCompleted: {
        window.showFullScreen();
    }

    Rectangle {
        id: oee_main_rectangle
        color: "#14141a"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.bottomMargin: 983

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
            anchors.rightMargin: 736
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
        Rectangle{
            id: notifications_rect
            y: 10
            radius: 5
            width: 77
            height: 77
            anchors.left: current_alarm_flash_rect.right

            anchors.leftMargin: 30
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
        }
    }

    Rectangle {
        id: list_rectangle
        color: "#2d2f39"
        anchors.left: parent.left
        anchors.right: graph_rectangle.left
        anchors.top: oee_main_rectangle.bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 400
        anchors.rightMargin: 5
        anchors.leftMargin: 0
        anchors.topMargin: 0
        GridLayout{
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.topMargin: 20
            anchors.bottomMargin: 20
            rows: 2
            columns: 4

            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }

                Text {
                    id: oee_text_
                    width: 254
                    text: qsTr("OEE")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: oee_perc_text_
                    width: 254
                    text: qsTr("80 %")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
            }
            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                Text {
                    id: perf_text_
                    width: 254
                    text: qsTr("PERF")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: perf_perc_text_
                    width: 254
                    text: qsTr("80 %")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
            }
            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                Text {
                    id: ava_text_
                    width: 254
                    text: qsTr("AVA")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: ava_perc_text_
                    width: 254
                    text: qsTr("80 %")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
            }
            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                Text {
                    id: qua_text_
                    width: 254
                    text: qsTr("QUA")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: qua_perc_text_
                    width: 254
                    text: qsTr("80 %")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
            }
            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                Text {
                    id: total_count_text
                    width: 254
                    text: qsTr("Production")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: total_count_num_text
                    width: 254
                    text: myProp.production_count
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }

            }
            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                Text {
                    id: reject_text
                    width: 254
                    text: qsTr("Rejected")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: reject_num_text
                    width: 254
                    text: myProp.rejection_count
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
            }
            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                Text {
                    id: shift_text
                    width: 254
                    text: qsTr("Shift")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: shift_num_text
                    width: 254
                    text: qsTr("1st")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
            }
            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                Text {
                    id: stop_time_text
                    width: 254
                    text: qsTr("Stop Time")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: stop_time_num_text
                    width: 254
                    text: qsTr("1 hr")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
            }
            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                Text {
                    id: breakdown_text
                    width: 254
                    text: qsTr("Breakdown")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: breakdown_num_text
                    width: 254
                    text: qsTr("2 hrs")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
            }
            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                Text {
                    id: run_time_text
                    width: 254
                    text: qsTr("Run Time")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: run_time_num_text
                    width: 254
                    text: qsTr("6 hrs")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
            }
            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                Text {
                    id: ideal_cycle_time_text
                    width: 254
                    text: qsTr("Ideal Cycle")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: ideal_cycle_time_num_text
                    width: 254
                    text: qsTr("45 min")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
            }
            Rectangle {
                radius: 5
                border.color: "white"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                width: 150; height: 120
                gradient: Gradient {
                    GradientStop { position: -1.0; color: "white" }
                    GradientStop { position: 1; color: "black" }
                }
                Text {
                    id: actual_cycle_time_text
                    width: 254
                    text: qsTr("Actual Cycle")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 25
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 15
                    anchors.bottomMargin: 71
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
                Text {
                    id: actual_cycle_time_num_text
                    width: 254
                    text: qsTr("55 min")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.topMargin: 66
                    anchors.bottomMargin: 20
                    anchors.leftMargin: 35
                    anchors.rightMargin: 35
                    color: "white"
                }
            }
        }
    }
    Rectangle {
        id: graph_rectangle
        color: "#2d2f39"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: oee_main_rectangle.bottom
        anchors.bottom: parent.bottom
        anchors.leftMargin: 860
        anchors.bottomMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0

        GridLayout {
            id: graph_grid
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            transformOrigin: Item.Left
            flow: GridLayout.LeftToRight
            anchors.rightMargin: 0
            anchors.leftMargin: 0
            anchors.bottomMargin: 20
            anchors.topMargin: 0
            rows: 2
            columns: 2

            Rectangle {
                id: prod_graph_rectangle
                width: 450
                height: 350
                color: "#14141a"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                transformOrigin: Item.Center

                ChartView {
                    anchors.fill: parent
                    legend.alignment: Qt.AlignBottom
                    antialiasing: true
                    theme: ChartView.ChartThemeDark

                    BarSeries {
                        id: mySeries
                        labelsAngle : 10
                        axisX: BarCategoryAxis { categories: ["01-11-2020", "02-11-2020", "03-11-2020", "04-11-2020"] }
                        BarSet { label: "Total Production"; values: [myProp.production_count, 540, 300, 450] }
                        BarSet { label: "Accepted"; values: [myProp.production_count - myProp.rejection_count, 540, 280, 400] }
                    }
                }
                Text {
                    id: prod_graph_text
                    x: 170
                    y: 15
                    color: "#ffffff"
                    text: qsTr("Production Count")
                    font.pointSize: 8
                    font.bold: true
                }
            }
            Rectangle {
                width: 450
                height: 350
                color: "#14141a"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                transformOrigin: Item.Center
                ChartView {
                    id: time_chart
                    anchors.fill: parent
                    transformOrigin: Item.Center
                    layer.textureMirroring: ShaderEffectSource.NoMirroring
                    layer.wrapMode: ShaderEffectSource.ClampToEdge
                    layer.enabled: false
                    legend.alignment: Qt.AlignBottom
                    antialiasing: true
                    animationDuration : 2
                    theme: ChartView.ChartThemeDark

                    PieSeries {
                        id: pieSeries
                        PieSlice { label: "Machining Time"; value: 90 }
                        PieSlice { label: "Stop Time"; value: 10 }
                        PieSlice { label: "Unplanned Stop Time"; value: 50 }
                    }
                }
                Component.onCompleted: {
                    pieSeries.find("Unplanned Stop Time").exploded = true;
                    pieSeries.find("Stop Time").exploded = true;
                    pieSeries.find("Machining Time").exploded = true;

                }
                Text {
                    id: pie_chart_text
                    x: 200
                    y: 20
                    color: "#ffffff"
                    text: qsTr("Pie Series")
                    font.pointSize: 8
                    font.bold: true
                }
            }
            Rectangle {
                id: data_rect
                width: 450
                height: 350
                color: "#14141a"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                ChartView {
                    anchors.fill: parent
                    legend.alignment: Qt.AlignBottom
                    antialiasing: true
                    theme: ChartView.ChartThemeDark

                    StackedBarSeries {

                        axisX: BarCategoryAxis { categories: ["2007", "2008", "2009", "2010", "2011", "2012" ] }
                        BarSet { label: "Bob"; values: [2, 2, 3, 4, 5, 6] }
                        BarSet { label: "Susan"; values: [5, 1, 2, 4, 1, 7] }
                        BarSet { label: "James"; values: [3, 5, 8, 13, 5, 8] }
                    }
                }
                Text {
                    id: _graph_text
                    x: 170
                    y: 15
                    color: "#ffffff"
                    text: qsTr("Production Count")
                    font.pointSize: 8
                    font.bold: true
                }
            }
            Rectangle {
                id: line_graph_rect
                width: 450
                height: 350
                color: "#14141a"
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                ChartView {
                    anchors.fill: parent
                    anchors.topMargin: 0
                    dropShadowEnabled : true
                    theme: ChartView.ChartThemeDark
                    antialiasing: true
                    legend.alignment: Qt.AlignBottom

                    LineSeries {
                        name: "LineSeries"
                        XYPoint { x: 1.1; y: 2.1 }
                        XYPoint { x: 1.9; y: 3.3 }
                        XYPoint { x: 2.1; y: 2.1 }
                        XYPoint { x: 2.9; y: 4.9 }
                        XYPoint { x: 3.4; y: 3.0 }
                        XYPoint { x: 4.1; y: 3.3 }
                    }
                }
                Text {
                    id: line_graph_text
                    x: 200
                    y: 15
                    color: "#ffffff"
                    text: qsTr("Line Series")
                    font.pointSize: 8
                    font.bold: true
                }
            }
        }
        RadioButton {
            id: quick_text
            y: 435
            text: qsTr("Quick Select")
            anchors.left: parent.left
            anchors.leftMargin: 40
            contentItem: Text {
                text: quick_text.text
                color: "white"
                leftPadding: quick_text.indicator.width + quick_text.spacing
                verticalAlignment: Text.AlignVCenter
            }

            onClicked: {
                profileDialog.open()
            }
        }
        Dialog {
            id: profileDialog
            x: 316
            y: 422
            width: quick_combo.width + 25
            ComboBox {
                id: quick_combo
                width: 200;
                model: [ "1 Day", "1 Week", "1 Month" ]
//                onCurrentValueChanged: console.log("Model Changed!")
            }
        }
        RadioButton {
            id: date_select_text
            y: 435
            text: qsTr("Date Select")
            anchors.left: quick_text.right
            anchors.leftMargin: 20
            contentItem: Text {
                text: date_select_text.text
                color: "white"
                leftPadding: date_select_text.indicator.width + date_select_text.spacing
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                calender_popup.show()
            }
        }


        Window {
            id: calender_popup
            x: 600
            y: 400
            width: 150
            height: 150

            Rectangle {
                id: from_date_rect
                width:  100
                height: 30
                color: "white"
                border.color: "black"
                Text {
                    id: from_date_text
                    anchors.fill: parent
                    text: qsTr("From")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                Rectangle {
                    width: 30
                    height: 30
                    anchors.left: from_date_text.right
                    anchors.leftMargin: 5
                    color: "cyan"

                    MouseArea {
                        anchors.fill: parent
                        onClicked: from_popup.show()                    }

                }

                Window {
                    id: from_popup
                    x: 200
                    y: 200
                    width: form_calender_dialog.width
                    height: form_calender_dialog.height
                    Calendar {
                        id: form_calender_dialog
                        minimumDate: new Date(2017, 0, 1)
                        maximumDate: new Date()

                        onClicked: from_date_text.text = Qt.formatDate(date,"dd MM yyyy")
                    }
                }
            }
            Rectangle {
                id: to_date_rect
                width:  100
                height: 30
                anchors.top: from_date_rect.bottom
                anchors.topMargin: 10
                color: "white"
                border.color: "black"
                Text {
                    id: to_date_text
                    anchors.fill: parent
                    text: qsTr("To")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                Rectangle {
                    width: 30
                    height: 30
                    anchors.left: to_date_text.right
                    anchors.leftMargin: 5
                    color: "cyan"

                    MouseArea {
                        anchors.fill: parent
                        onClicked: to_popup.show()                    }

                }

                Window {
                    id: to_popup
                    x: 200
                    y: 200
                    width: to_calender_dialog.width
                    height: to_calender_dialog.height
                    Calendar {
                        id: to_calender_dialog
                        minimumDate: new Date(2017, 0, 1)
                        maximumDate: new Date()

                        onClicked: to_date_text.text = Qt.formatDate(date,"dd MM yyyy")
                    }
                }
            }
            Button {
                id: date_submit_button
                anchors.top: to_date_rect.bottom
                anchors.topMargin: 20
                text: "Submit"

                onClicked: {
                    calender_popup.close()
                }
            }
        }
    }

    Rectangle {
        id: alarms_rect
        color: "#2d2f39"
        anchors.left: parent.left
        anchors.right: graph_rectangle.left
        anchors.top: list_rectangle.bottom
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.topMargin: 5
        anchors.rightMargin: 5
        anchors.bottomMargin: 0

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
            color: "#14141a"
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: alarm_buttons_row.bottom
            anchors.bottom: parent.bottom
            anchors.rightMargin: 10
            anchors.leftMargin: 10
            anchors.bottomMargin: 10
            anchors.topMargin: 10

            Column {
                id: alarms_column
                anchors.fill: parent
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
    D{i:0;formeditorZoom:0.2}
}
##^##*/
