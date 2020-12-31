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
    id: list_rectangle
    color: "#2d2f39"
    anchors.fill: parent

    GridLayout{
        anchors.fill: parent
        rows: 2
        columns: 4

        Rectangle {
            property double visiblity_of_rect: myGridProp.oee
            visible: visiblity_of_rect == 1.0 ? true : false
            id: oee_text_rect
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 40
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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
            id: perf_text_rect
            property double visiblity_of_rect: myGridProp.perf
            visible: visiblity_of_rect == 1.0 ? true : false
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 20
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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
            id: ava_text_rect
            property double visiblity_of_rect: myGridProp.ava
            visible: visiblity_of_rect == 1.0 ? true : false
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 20
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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
            id: qua_text_rect
            property double visiblity_of_rect: myGridProp.qua
            visible: visiblity_of_rect == 1.0 ? true : false
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 20
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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
            id: total_count_rect
            property double visiblity_of_rect: myGridProp.total_count
            visible: visiblity_of_rect == 1.0 ? true : false
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 40
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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
            id: reject_text_rect
            property double visiblity_of_rect: myGridProp.reject_count
            visible: visiblity_of_rect == 1.0 ? true : false
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 20
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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
            id: shift_text_rect
            property double visiblity_of_rect: myGridProp.shift
            visible: visiblity_of_rect == 1.0 ? true : false
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 20
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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
            id: stop_time_text_rect
            property double visiblity_of_rect: myGridProp.stop_time
            visible: visiblity_of_rect == 1.0 ? true : false
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 20
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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
            id: breakdown_text_rect
            property double visiblity_of_rect: myGridProp.breakdown_time
            visible: visiblity_of_rect == 1.0 ? true : false
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 40
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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
            id: run_time_text_rect
            property double visiblity_of_rect: myGridProp.runtime
            visible: visiblity_of_rect == 1.0 ? true : false
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 20
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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
            id: ideal_cycle_time_text_rect
            property double visiblity_of_rect: myGridProp.ideal_cycle
            visible: visiblity_of_rect == 1.0 ? true : false
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 20
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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
            id: actual_cycle_time_text_rect
            property double visiblity_of_rect: myGridProp.actual_cycle
            visible: visiblity_of_rect == 1.0 ? true : false
            radius: 5
            border.color: "white"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            width: 150; height: 120
            Layout.leftMargin : 20
            Layout.rightMargin: 20
            Layout.topMargin: 40
            Layout.bottomMargin: 20
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


/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.5;height:480;width:640}
}
##^##*/
