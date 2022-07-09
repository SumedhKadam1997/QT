import QtQuick
import QtCharts
import QtQuick.Controls
import Qt5Compat.GraphicalEffects

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property bool isAdding: false

    property var errorSeries: []
    property var upperPositionList: []
    property var upperThicknessList: []
    property var lowerList: []
    property var previousPosition
    property var previousThickness
    property var newErrorSpline

    Connections {
        id: conn
        target: dg

        function onPositionChanged() {
            console.log("Position : ", dg.position)
            console.log("Thickness : ", dg.thickness)
        }

        function onThicknessChanged() {
            lineseriesN.append(dg.position, dg.thickness)
            if (dg.thickness > 40) {
                upperPositionList.push(dg.position)
                upperThicknessList.push(dg.thickness)
                isAdding = true;
            } else {
                if (isAdding) {
                    newErrorSpline = chart.createSeries(ChartView.SeriesTypeLine, "error", axisX, axisY)
                    newErrorSpline.color = "red"
                    newErrorSpline.append(previousPosition, previousThickness)
                    for (var i = 0; i < upperPositionList.length; i++) {
                        newErrorSpline.append(upperPositionList[i], upperThicknessList[i])
                    }
                    newErrorSpline.append(dg.position, dg.thickness)
                    upperPositionList = []
                    upperThicknessList = []
                }
                isAdding = false
            }
            previousPosition = dg.position
            previousThickness = dg.thickness
        }

        function onPosForwardChanged() {
            console.log("Position Forward Changed")
            lineseriesN.clear()
            for (var i = 0; i < errorSeries.length; i++) {
                if (errorSeries[i] !== lineseriesN) {
                    chart.removeSeries(errorSeries[i])
                }
            }
            errorSeries = []
        }
    }

    ChartView {
        id: chart
        anchors.fill: parent
        animationOptions: ChartView.SeriesAnimations
        dropShadowEnabled: true
        antialiasing: true
        legend.visible: false
        title: ""

        onSeriesAdded: function(series) {
            errorSeries.push(series)
        }


        ValueAxis {
            id: axisY
            min: 0
            max: 50
        }
        ValueAxis {
            id: axisX
            min: 0
            max: 50
        }
        LineSeries {
            id: lineseriesN
            axisX: axisX
            axisY: axisY
            width: 2
            capStyle: Qt.RoundCap
        }
        LineSeries {
            id: lineseriesN_1
            axisX: axisX
            axisY: axisY
            width: 2
            capStyle: Qt.RoundCap
        }
        LineSeries {
            id: lineseriesN_2
            axisX: axisX
            axisY: axisY
            width: 2
            capStyle: Qt.RoundCap
        }
        LineSeries {
            id: lineseriesN_3
            axisX: axisX
            axisY: axisY
            width: 2
            capStyle: Qt.RoundCap
        }
        LineSeries {
            id: lineseriesN_4
            axisX: axisX
            axisY: axisY
            width: 2
            capStyle: Qt.RoundCap
        }
    }
}
