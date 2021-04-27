import QtQuick 2.15
import QtQuick.Window 2.15
import QtLocation 5.12
import QtPositioning 5.12

Window {
    width: Qt.platform.os == "android" ? Screen.width : 512
    height: Qt.platform.os == "android" ? Screen.height : 512
    visible: true

    Plugin {
        id: mapPlugin
        locales: "en_IN"
        name: "osm"
//        name: "here"
//        parameters: [here.app_id = , here.token = ]//"osm" // "mapboxgl", "esri", ...
        // specify plugin parameters if necessary
        // PluginParameter {
        //     name:
        //     value:
        // }
    }

    Map {
        anchors.fill: parent
        plugin: mapPlugin
//        center: QtPositioning.coordinate(59.91, 10.75) // Oslo
        center: QtPositioning.coordinate(19.0760 , 72.8777) // Mumbai

        zoomLevel: 14
    }
}
