import QtQuick
import QtCharts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Connections {
        target: graphData

        function onDataUpdated(time, value) {
//            axisX.max = new Date()
//            axisX.min = toMsecsSinceEpochMinus(new Date())
            lineS.append(toMsecsSinceEpoch(new Date()), value)
        }
    }

    function toMsecsSinceEpoch(date) {
        var msecs = date.getTime();
        return msecs;
    }

    ChartView {
        id: chart
        anchors.fill: parent
        antialiasing: true
        smooth: true

        DateTimeAxis {
            id: axisX
            format: "hh:mm"
            min: new Date()
            max: graphData.minDateTime
        }
        ValuesAxis {
            id: axisY
            min: 0
            max: 60
        }
        LineSeries {
            id: lineS
            axisX: axisX
            axisY: axisY
//            XYPoint { x: toMsecsSinceEpoch(new Date(1950, 2, 15)); y: 5 }
//            XYPoint { x: toMsecsSinceEpoch(new Date(1970, 0, 1)); y: 50 }
//            XYPoint { x: toMsecsSinceEpoch(new Date(1987, 12, 31)); y: 102 }
//            XYPoint { x: toMsecsSinceEpoch(new Date(1998, 7, 1)); y: 100 }
//            XYPoint { x: toMsecsSinceEpoch(new Date(2012, 8, 2)); y: 110 }
        }
    }
}
