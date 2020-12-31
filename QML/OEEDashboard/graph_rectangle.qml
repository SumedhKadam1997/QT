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
    anchors.fill: parent
    color: "#2d2f39"

    GridLayout {
        id: graph_grid
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        transformOrigin: Item.Left
        flow: GridLayout.LeftToRight
        anchors.rightMargin: 80
        anchors.leftMargin: 0
        anchors.bottomMargin: 65
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

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.33;height:480;width:640}
}
##^##*/
