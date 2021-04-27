import QtQuick 2.9
import QtQuick.Window 2.15
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.0
import QtQml 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Canvas {
        id: mycanvas
        width: parent.width
        height: parent.height

        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();

            var centerX = width/2;
            var centerY = height/2;

            ctx.beginPath();
            ctx.fillStyle = "black";
            ctx.lineWidth = 5;
            ctx.moveTo(centerX, centerY);
            ctx.arc(centerX, centerY, width/4, -3.14159265, 0, false);
            ctx.lineTo(centerX, centerY);
            ctx.fill();

            ctx.beginPath();
            ctx.fillStyle = "red";
            ctx.lineWidth = 5;
            ctx.moveTo(centerX, centerY);
            ctx.arc(centerX, centerY, width/4, 0, 1.5, false);
            ctx.lineTo(centerX, centerY);
            ctx.fill();

            ctx.beginPath();
            ctx.fillStyle = "black";
            ctx.lineWidth = 5;
            ctx.moveTo(centerX, centerY);
            ctx.arc(centerX, centerY, width/4, 1.5, 2.9, false);
            ctx.lineTo(centerX, centerY);
            ctx.fill();
        }

        Rectangle {
            anchors.centerIn:mycanvas
            width: 250
            height: width;
            color: "white"
            radius: width*0.5
        }
}
}
