import QtQuick 2.15
import QtQuick.Window 2.15
import verolt.charts 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    CandleStickSeries {
        id: myCandleStickSeries
        anchors.fill: parent

        sticks: [
            CandleStick {
                id: stickOne
                width: 100
                height: 100
                anchors.left: parent.left
                anchors.leftMargin: 70
                anchors.top: parent.top
                anchors.topMargin: 150
            },
            CandleStick {
                id: stickTwo
                width: 100
                height: 100
                anchors.left: stickOne.right
                isIncreasing: false
                upperLimit: 20
                lowerLimit: 90
                anchors.top: parent.top
                anchors.topMargin: 150
                color: "#555555"
            },
            CandleStick {
                id: stickThree
                width: 200
                height: 300
                anchors.left: stickTwo.right
                anchors.top: parent.top
                anchors.topMargin: 150
            }

        ]
    }
}

//    ChartView {
//        title: "Candlestick Series"
////        width: 400
////        height: 300
//        anchors.fill: parent

//        CandlestickSeries {
//            name: "Acme Ltd."
//            increasingColor: "green"
//            decreasingColor: "red"

//            CandlestickSet { timestamp: 1435708800000; open: 790; high: 694; low: 599; close: 660 }
//            CandlestickSet { timestamp: 1435795200000; open: 669; high: 800; low: 500; close: 669 }
//            CandlestickSet { timestamp: 1436140800000; open: 485; high: 623; low: 485; close: 600 }
//            CandlestickSet { timestamp: 1436227200000; open: 589; high: 615; low: 377; close: 569 }
//            CandlestickSet { timestamp: 1436313600000; open: 464; high: 464; low: 254; close: 254 }
//        }
//    }
