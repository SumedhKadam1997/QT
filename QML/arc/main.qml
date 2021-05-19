import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Shape {
        id: trackShape
        anchors.fill: parent
        visible: true

        ShapePath {
            id: trackShapePath
            strokeColor: "red"
            fillColor: "white"
            strokeWidth: 20
            capStyle: Qt.RoundCap

            PathAngleArc {
                id: path_arc
                radiusX: 50
                radiusY: 50
                centerX: trackShape.width / 2
                centerY: trackShape.height / 2
                startAngle: -90
                sweepAngle: my_slider.value
            }
        }
    }
    Slider {
        id: my_slider
        anchors.bottom: parent.bottom
        stepSize: 1
        value: 50
        to: 360
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
