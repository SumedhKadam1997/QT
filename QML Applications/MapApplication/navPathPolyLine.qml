import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtLocation 5.15
import QtPositioning 5.15
import QtSensors 5.15

MapPolyline {
//    id: polyLinenav
    line.width: 5
    line.color: "blue"
//    visible: true
//                visible: map.zoomLevel > 16 ? true : false
//                path: nav.path
//                path: db.basePath
    path: navJSON.navPath
}
//Rectangle {
//    width: 100
//    height: 100
//    anchors.centerIn: parent
//    color: "red"
//}
