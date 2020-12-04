import QtQuick 2.15
import QtQuick.Window 2.15
import QtCharts 2.3
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Extras 1.4



Window {
    width: 1280
    height: 640
    visible: true
    title: qsTr("Hello World")

//    ChartView {
//        id: chart
//        title: "Top-5 car brand shares in Finland"
//        anchors.fill: parent
//        legend.alignment: Qt.AlignBottom
//        antialiasing: true
//        theme: ChartView.ChartThemeDark

//        PieSeries {
//            id: pieSeries
//            PieSlice { label: "Volkswagen"; value: 13.5 }
//            PieSlice { label: "Toyota"; value: 10.9 }
//            PieSlice { label: "Ford"; value: 8.6 }
//            PieSlice { label: "Skoda"; value: 8.2 }
//            PieSlice { label: "Volvo"; value: 6.8 }

//        }
//    }

//    Component.onCompleted: {
//        // You can also manipulate slices dynamically, like append a slice or set a slice exploded
////        othersSlice = pieSeries.append("Others", 52.0);
//        pieSeries.find("Volkswagen").exploded = true;
//    }
    ChartView {
        title: "Line"
        anchors.fill: parent
        antialiasing: true

        LineSeries {
            name: "LineSeries"
            XYPoint { x: 0; y: 0 }
            XYPoint { x: 1.1; y: 2.1 }
            XYPoint { x: 1.9; y: 3.3 }
            XYPoint { x: 2.1; y: 2.1 }
            XYPoint { x: 2.9; y: 4.9 }
            XYPoint { x: 3.4; y: 3.0 }
            XYPoint { x: 4.1; y: 3.3 }
            pointsVisible: true
        }
//        LineSeries {
//            name: "LineSeries2"
//            XYPoint { x: 0; y: 0 }
//            XYPoint { x: 2.1; y: 2.1 }
//            XYPoint { x: 1.9; y: 3.3 }
//            XYPoint { x: 3.1; y: 2.1 }
//            XYPoint { x: 1.9; y: 4.9 }
//            XYPoint { x: 3.4; y: 3.0 }
        //            XYPoint { x: 3.1; y: 3.3 }
        //        }
    }
    ChartView {
        title: "Line"
        anchors.fill: parent
        antialiasing: true
        ValueAxis {
            id: xAxis
            min: 0
            max: 10
        }
    }
    ChartView {
        title: "Line"
        anchors.fill: parent
        antialiasing: true
        PieSeries {
            id: pieSeries
            startAngle: -90
            endAngle: 90

            PieSlice { label: "eaten"; value: slider.value}
            //            PieSlice { label: "not yet eaten"; value: 30.0 }
        }

        ChartView {
            id: percent
            x: 291
            y: 282
            width: 300
            height: 300
            PercentBarSeries {
                name: "PercentBarSeries"
                BarSet {
                    label: "Set1"
                    values: [2, 2, 3]
                }

                BarSet {
                    label: "Set2"
                    values: [5, 1, 2]
                }

                BarSet {
                    label: "Set3"
                    values: [3, 5, 8]
                }
            }
        }
//    Component.onCompleted: {
////             You can also manipulate slices dynamically, like append a slice or set a slice exploded
//            othersSlice = pieSeries.append("Others", 20.0);
////            pieSeries.find("Volkswagen").exploded = true;
//        }
    }
    Slider {
        id: slider
        value: 100.0
        maximumValue : 180
        minimumValue : 0
        activeFocusOnPress : true
    }
    Text {
        id: slider_value
        text: slider.value
    }
    Gauge {
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 480
        minimumValue: 0
        value: 50
        maximumValue: 100
        anchors.centerIn: parent
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
