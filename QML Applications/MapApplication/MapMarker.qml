import QtQuick 2.0
import QtLocation 5.9

MapQuickItem
{
    id: assetMapItem2
    anchorPoint.x: imgLocMarker.width / 2
    anchorPoint.y: imgLocMarker.height / 2
    property string name: ""
    visible: true
    sourceItem: Column {
        Image {
            id: imgLocMarker
            width: 20
            height: 30
            source: "qrc:/mm_20_red.png"
        }
        Text {
            text: name
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            width: imgLocMarker.width + 10
        }
    }
}
