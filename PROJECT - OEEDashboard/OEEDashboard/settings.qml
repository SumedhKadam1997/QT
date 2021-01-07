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
    id: settings_main_rect
    color: "black"
    width: myQmlProp.body_width
    height: myQmlProp.body_height



    Button {
        id: settings_submit_button
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Submit"

        onClicked: {
            start_page_loader.source = "start_page.qml"
        }
    }

    Rectangle {
        id: header_rect
        width: myQmlProp.body_width * 0.3
        height: myQmlProp.body_height
        anchors.left: parent.left
        anchors.right: description_rect.left
        //        color: "black"
        color: "#131c21"

        Rectangle {
            id: rearrange_button
            x: 225
            y: -113
            width: 30
            height: 380
            rotation: 90
            gradient: Gradient {
                GradientStop { position: 0; color: "#131c21" }
                GradientStop { position: 0.5; color: "#2F4F4F" }
                GradientStop { position: 1; color: "#131c21" }
            }

            Text {
                id: rearrange_button_text
                anchors.fill: parent
                color: "white"
                rotation: 270
                text: qsTr("Rearrange the Home Page Tabs")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 12
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    rearrange_dialog.open()
                }
            }
        }
    }

    Rectangle {
        id: description_rect
        color: "#2d2f39"
        width: myQmlProp.body_width * 0.7
        height: myQmlProp.body_height
        anchors.leftMargin: 5
        anchors.left: header_rect.right

        Dialog {
            id: rearrange_dialog
            x: 500
            y: 500
            width: 500
            height: 250

            GridLayout {
                id: dialog_grid_layout
                anchors.fill: parent
                rows: 2
                columns: 4

                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: oee_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: ( myGridProp.oee == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.oee == 1){
                                    myGridProp.setOee(0)
                                } else {
                                    myGridProp.setOee(1)
                                }
                            }
                        }
                        Text {
                            y: 2
                            text: qsTr("OEE")
                            anchors.left: oee_check.right
                            anchors.leftMargin: 23
                            anchors.rightMargin: 20
                        }
                    }
                }
                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: perf_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: (myGridProp.perf == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.perf == 1){
                                    myGridProp.setPerf(0)
                                } else {
                                    myGridProp.setPerf(1)
                                }
                            }
                        }
                    }
                    Text {
                        y: 12
                        text: qsTr("PERF")
                        anchors.left: perf_check.right
                        anchors.leftMargin: 26
                        anchors.rightMargin: 20
                    }
                }
                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: ava_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: (myGridProp.ava == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.ava == 1){
                                    myGridProp.setAva(0)
                                } else {
                                    myGridProp.setAva(1)
                                }
                            }
                        }
                    }
                    Text {
                        y: 12
                        text: qsTr("AVA")
                        anchors.left: ava_check.right
                        anchors.leftMargin: 26
                        anchors.rightMargin: 20
                    }
                }
                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: qua_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: (myGridProp.qua == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.qua == 1){
                                    myGridProp.setQua(0)
                                } else {
                                    myGridProp.setQua(1)
                                }
                            }
                        }
                    }
                    Text {
                        y: 12
                        text: qsTr("QUA")
                        anchors.left: qua_check.right
                        anchors.leftMargin: 26
                        anchors.rightMargin: 20
                    }
                }
                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: total_count_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: (myGridProp.total_count == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.total_count == 1){
                                    myGridProp.setTotal_count(0)
                                } else {
                                    myGridProp.setTotal_count(1)
                                }
                            }
                        }
                    }
                    Text {
                        y: 12
                        text: qsTr("Production")
                        anchors.left: total_count_check.right
                        anchors.leftMargin: 20
                        anchors.rightMargin: 20
                    }
                }
                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: reject_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: (myGridProp.reject_count == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.reject_count == 1){
                                    myGridProp.setReject_count(0)
                                } else {
                                    myGridProp.setReject_count(1)
                                }
                            }
                        }
                    }
                    Text {
                        y: 12
                        text: qsTr("Rejected")
                        anchors.left: reject_check.right
                        anchors.leftMargin: 26
                        anchors.rightMargin: 20
                    }
                }
                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: shift_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: (myGridProp.shift == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.shift == 1){
                                    myGridProp.setShift(0)
                                } else {
                                    myGridProp.setShift(1)
                                }
                            }
                        }
                    }
                    Text {
                        y: 12
                        text: qsTr("Shift")
                        anchors.left: shift_check.right
                        anchors.leftMargin: 26
                        anchors.rightMargin: 20
                    }
                }
                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: stop_time_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: (myGridProp.stop_time == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.stop_time == 1){
                                    myGridProp.setStop_time(0)
                                } else {
                                    myGridProp.setStop_time(1)
                                }
                            }
                        }
                    }
                    Text {
                        y: 12
                        text: qsTr("Stop Time")
                        anchors.left: stop_time_check.right
                        anchors.leftMargin: 26
                        anchors.rightMargin: 20
                    }
                }
                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: breakdown_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: (myGridProp.breakdown_time == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.breakdown_time == 1){
                                    myGridProp.setBreakdown_time(0)
                                } else {
                                    myGridProp.setBreakdown_time(1)
                                }
                            }
                        }
                    }
                    Text {
                        y: 12
                        text: qsTr("Breakdown")
                        anchors.left: breakdown_check.right
                        anchors.leftMargin: 20
                        anchors.rightMargin: 20
                    }
                }
                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: runtime_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: (myGridProp.runtime == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.runtime == 1){
                                    myGridProp.setRuntime(0)
                                } else {
                                    myGridProp.setRuntime(1)
                                }
                            }
                        }
                    }
                    Text {
                        y: 12
                        text: qsTr("Run Time")
                        anchors.left: runtime_check.right
                        anchors.leftMargin: 20
                        anchors.rightMargin: 20
                    }
                }
                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: ideal_cycle_time_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: (myGridProp.ideal_cycle == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.ideal_cycle == 1){
                                    myGridProp.setIdeal_cycle(0)
                                } else {
                                    myGridProp.setIdeal_cycle(1)
                                }
                            }
                        }
                    }
                    Text {
                        y: 12
                        text: qsTr("Ideal Cycle")
                        anchors.left: ideal_cycle_time_check.right
                        anchors.leftMargin: 20
                        anchors.rightMargin: 20
                    }
                }
                Rectangle {
                    Layout.preferredWidth: 40
                    Layout.preferredHeight: 40
                    border.color: "black"

                    Rectangle {
                        id: actual_cycle_time_check
                        anchors.fill: parent
                        anchors.rightMargin: 10
                        anchors.leftMargin: 10
                        anchors.bottomMargin: 10
                        anchors.topMargin: 10
                        color: (myGridProp.actual_cycle == 1) ? "green" : "red"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                if(myGridProp.actual_cycle == 1){
                                    myGridProp.setActual_cycle(0)
                                } else {
                                    actual_cycle_time_check.col = true
                                    myGridProp.setActual_cycle(1)
                                }
                            }
                        }
                    }
                    Text {
                        y: 12
                        text: qsTr("Actual Cycle")
                        anchors.left: actual_cycle_time_check.right
                        anchors.leftMargin: 20
                        anchors.rightMargin: 20
                    }
                }

            }
            Button {
                id: submit_button
                x: 100
                anchors.top: dialog_grid_layout.bottom
                anchors.topMargin: 20
                text: "Submit"
                onClicked: {
                    rearrange_dialog.close()
                }
            }
        }

    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
