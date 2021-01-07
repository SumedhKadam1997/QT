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
    id: main_input_rect
    color: "black"
    width: myQmlProp.body_width
    height: myQmlProp.body_height

    Rectangle {
        id: column_input_rect
        anchors.fill: parent
        anchors.bottomMargin: 50
        color: "black"

        RowLayout {
            id: layout
            anchors.fill: parent
            spacing: 6
            Rectangle {
                color: '#2d2f39'
                Layout.fillWidth: true
                Layout.fillHeight: true


                Rectangle {
                    width: parent.width
                    height: 50
                    color: "transparent"
                    anchors.top: parent.top

                    Text {
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pointSize: 20
                        text: qsTr("Machine Data")
                        color: "white"
                    }
                }
                ColumnLayout {
                    id: machine_data_grid_layout
                    x: 0
                    width: parent.width
                    height: parent.height
                    spacing: 5
                    anchors.top: parent.top
                    anchors.topMargin: 50

                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: mach_id_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Machine ID")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: mach_id_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: mach_id_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Machine ID")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: datetime_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Date")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: datetime_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            Text {
                                id: datetime_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                text : qsTr("Date")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                            MouseArea {
                                id: datetime_input_mousearea
                                anchors.fill: parent

                                onClicked: {
                                    date_popup.open()
                                }
                            }
                            Popup {
                                id: date_popup
                                x: 200
                                y: 200
                                width: 280
                                height: 350
                                Calendar {
                                    id: form_calender_dialog
                                    minimumDate: new Date(2017, 0, 1)
                                    maximumDate: new Date()

                                    onClicked: datetime_input.text = Qt.formatDate(date,"dd/MM/yyyy")
                                }
                                Button {
                                    text: "Submit"
                                    anchors.top: form_calender_dialog.bottom
                                    anchors.topMargin: 20
                                    onClicked: {
                                        date_popup.close()
                                    }
                                }
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: batch__rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Batch")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: batch__input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: batch__input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Batch")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: air_press_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Air Pressure")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: air_press_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: air_press_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Air Pressure")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: lub_press_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Lubrication Pressure")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: lub_press_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: lub_press_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Lubrication Pressure")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: hyd_press_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Hyd. Pressure")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: hyd_press_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: hyd_press_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Hyd. Pressure")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: stroke_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Stroke")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: stroke_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: stroke_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Stroke")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }

                    Button {
                        text: "Submit"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                        Database {
                            id: db
                        }
                        onClicked: {
                            db.insert_machine_data(mach_id_input.text, datetime_input.text, batch__input.text, air_press_input.text, lub_press_input.text, hyd_press_input.text, stroke_input.text)
                            console.log("Machine Data Successfully Inserted")
                            start_page_loader.source = "start_page.qml"
                        }

                    }

                }

            }
            Rectangle {
                color: '#2d2f39'
                Layout.fillWidth: true
                Layout.fillHeight: true

                Rectangle {
                    width: parent.width
                    height: 50
                    color: "transparent"
                    anchors.top: parent.top

                    Text {
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pointSize: 20
                        text: qsTr("Production Data")
                        color: "white"
                    }
                }
                ColumnLayout {
                    x: 0
                    width: parent.width
                    height: parent.height
                    spacing: 5
                    anchors.top: parent.top
                    anchors.topMargin: 50

                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.topMargin: 20
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: machine_id_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Machine ID")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: machine_id_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: machine_id_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Machine ID")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: prod_count_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Production Count")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: prod_count_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: prod_count_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Production Count")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: reject_count_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Rejected Count")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: reject_count_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: reject_count_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Rejected Count")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: date_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Date")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: date_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: date_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Date")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: batch_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Batch")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: batch_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: batch_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Batch")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: run_time_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Stop Time")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: run_time_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: run_time_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Stop Time")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: stop_time_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Stop Time")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: stop_time_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: stop_time_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Stop Time")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: breakdown_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Breakdown Time")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: breakdown_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: breakdown_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Breakdown Time")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: unplanned_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Unplanned Time")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: unplanned_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: unplanned_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Unplanned")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                    Rectangle {
                        Layout.preferredWidth:  parent.width
                        Layout.preferredHeight: 50
                        Layout.alignment: Qt.AlignHCenter
                        Layout.rightMargin: 50
                        color: "#2d2f39"
                        border.color: "white"
                        border.width: 5

                        Rectangle {
                            id: notes_rect
                            width: parent.width / 2
                            height: 50
                            color: "transparent"
                            anchors.top: parent.top
                            anchors.leftMargin: 20
                            anchors.topMargin: 0
                            anchors.left: parent.left

                            Text {
                                anchors.fill: parent
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 12
                                text: qsTr("Notes")
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: notes_input_rect
                            anchors.centerIn: parent
                            width: 155
                            height: 35
                            anchors.left: machine_id_rect.right
                            anchors.verticalCenterOffset: 0
                            anchors.horizontalCenterOffset: 200
                            color: "#ffffff"

                            TextField {
                                id: notes_input
                                x: 224
                                y: 1
                                anchors.fill: parent
                                placeholderText : qsTr("Notes")
                                font.pixelSize: 12
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }

                    Button {
                        text: "Submit"
                        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                        onClicked: {
                            db.insert_prod_data(machine_id_input.text, prod_count_input.text, reject_count_input.text, date_input.text, batch_input.text, run_time_input.text, stop_time_input.text, unplanned_input.text, notes_input.text)
                            console.log("Production Data Successfully Inserted")
                            start_page_loader.source = "start_page.qml"
                        }
                    }

                }
            }
            Rectangle {
                color: '#2d2f39'
                Layout.fillWidth: true
                Layout.fillHeight: true

                Rectangle {
                    width: parent.width
                    height: 50
                    color: "transparent"
                    anchors.top: parent.top

                    Text {
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.pointSize: 20
                        text: qsTr("Lubrication Data")
                        color: "white"
                    }
                }
            }
        }
    }



}


