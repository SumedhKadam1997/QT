import QtQuick 2.15
import QtQuick.Window 2.15
import QtCharts 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ChartView {
        width: 400
        height: 300
        theme: ChartView.ChartThemeBrownSand
        antialiasing: true

        PieSeries {
            id: pieSeries
            PieSlice { label: "eaten"; value: 94.9 }
            PieSlice { label: "not yet eaten"; value: 5.1 }
        }
    }
}
