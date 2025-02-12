import QtQuick
import QtCharts


Item {

    ChartView {
        anchors.fill: parent
        BoxPlotSeries {
                id: plotSeries
                name: "Income"
                BoxSet { label: "Jan"; values: [3, 4, 6, 6, 8.5]; modified: true }
                BoxSet { label: "Feb"; values: [5, 6, 7.5, 8.6, 11.8] }
                BoxSet { label: "Mar"; values: [3.2, 5, 5.7, 8, 9.2] }
                BoxSet { label: "Apr"; values: [3.8, 5, 6.4, 7, 8] }
                BoxSet { label: "May"; values: [4, 5, 5.2, 6, 7] }
            }
    }

}
