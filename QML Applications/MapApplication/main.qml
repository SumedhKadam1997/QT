import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtPositioning 5.12
//import Location 1.0

Window {
    width: 1024
    height: 600
    visible: true
    title: qsTr("Map Application")
    property int mapType: 1
    property variant region: QtPositioning.rectangle(QtPositioning.coordinate(18.560197708387605, 73.87943025330222), QtPositioning.coordinate(18.551877431743463, 73.89212607934934))

    Map {
        id: map
        anchors.fill: parent
        activeMapType: supportedMapTypes[mapType]
        //        center: QtPositioning.coordinate(18.554437341937323, 73.88714732139219)
        plugin: Plugin {
            id: mapPlugin
            name: "mapboxgl"
//            name: "osm"
//            name: "googlemaps"
            locales: "en_IN"
//            name: "googlemaps"
//            PluginParameter {
//                name: "googlemaps.maps.apikey "
//                value: "AIzaSyBD-Y0FneqI3BsCs3Qnp7nTntYdSWFmxZQ"
//            }
        }
//        MapItemView {
//            model: locationModel
//            delegate: MapQuickItem {
//                id: marker
//                coordinate:  position
//                property int spatialPointHeight: 60
//                property real transparency: 0.5
//                anchorPoint.x: image.width/4
//                anchorPoint.y: image.height
//                sourceItem: Image {
//                    id: image
//                    sourceSize.width: spatialPointHeight
//                    sourceSize.height: spatialPointHeight
//                    width: spatialPointHeight
//                    height: spatialPointHeight
//                    source: "qrc:/mm_20_red.png"
//                    opacity: 1 - marker.transparency
//                }
//            }
//        }
//        MapItemView {
//            model: locationModel
//            delegate: MapPolyline {
//                path: position
//                line.color: "red"
//                line.width: 10
//            }
//        }
        MapItemView {
            model: assetmodel
            delegate: MapMarker{
                coordinate: assetData
                name: nameData
                transformOrigin: Item.Center
//                rotation: angleData
                z:100
            }
        }
        zoomLevel: 4
        visibleRegion: region
    }
//    LocationModel{
//        id: locationModel
//        locations: [
//            Location {
//                id: loc
//                latitude: 18.555921723127565
//                longitude: 73.88648464933829
//            }
//        ]
//    }
    Timer {
        id: timer
        repeat: true
        interval: 5000
        running: true
        onTriggered: {
//            locationModel.appendLocation(loc.latitude += 0.00001, loc.longitude += 0.00001)
//            loc.latitude += 0.000001
//            loc.longitude += 0.000001
//            console.log("Latitude : ", loc.latitude)
//            console.log("Longitude : ", loc.longitude)
//            map.activeMapType = MapType.StreetMap
//            mapType += 1
            console.log("Map Type Changed")
        }
    }
}
