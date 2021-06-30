import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    id: window
    width: 640
    height: 480
    visible: true
    color: "#b59797"
    title: qsTr("Hello World")

    Slider {
        id: slide
        anchors.bottom: rectangle.top
        anchors.bottomMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        from: 0
        to: 360
    }

    Rectangle {
        id: rectangle
        width: 200
        height: 200
        anchors.centerIn: parent
        color: "#ffffff"
        transform: Rotation {
            id: rotate
            origin.x: 0
            origin.y: 0
            angle: slide.value
        }
    }
    Button {
        id: parsebtn
        anchors.top: rectangle.bottom
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Parse CSV"

        onClicked: {
            runner.run()
            console.log("Parsing...")
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
