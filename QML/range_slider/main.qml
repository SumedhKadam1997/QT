import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    RangeSlider {
        from: 1
        to: 100
        first.value: 25
        second.value: 75
    }
}
