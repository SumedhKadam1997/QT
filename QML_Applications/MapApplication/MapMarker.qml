import QtQuick 2.0
import QtLocation 5.9

MapQuickItem
{
    id: assetMapItem2
    anchorPoint.x: imgLocMarker.width / 2
    anchorPoint.y: imgLocMarker.height
    property string name: ""
    visible: true
    sourceItem: Column {
        Image {
            id: imgLocMarker
            width: 20
            height: 20
            source: "qrc:/car.png"
        }
        Text {
            text: name
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            width: imgLocMarker.width + 10
        }
    }
}
