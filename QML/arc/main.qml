import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("ARC")
    Rectangle {
        anchors.fill: parent

        Shape {
            id: trackShape
            anchors.fill: parent
            visible: true

            ShapePath {
                id: trackShapePath
                strokeColor: "red"
                fillColor: "white"
                strokeWidth: 10
                //            capStyle: Qt.RoundCap
                capStyle: Qt.SquareCap

                PathAngleArc {
                    id: path_arc
                    radiusX: 50
                    radiusY: 50
                    centerX: trackShape.width / 2
                    centerY: trackShape.height / 2
                    startAngle: 144
                    sweepAngle: my_slider.value
                }
            }
        }
        Image {
            id: img_needle
            x: trackShape.width / 2 - 30
            y: trackShape.height / 2 - 30
            source: "qrc:/Path 46.png"
            transform: Rotation {
                id: needle_rotate
                angle: -80 + my_slider.value
                origin.x: img_needle.width
                origin.y: img_needle.height
            }
        }
        Slider {
            id: my_slider
            anchors.bottom: parent.bottom
            stepSize: 1
            value: 0
            to: 250
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
