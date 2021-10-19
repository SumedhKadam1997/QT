import QtQuick 2.12
import QtQuick.Controls 2.12
import QtLocation 5.15
import QtPositioning 5.15
import QtSensors 5.15

Item {
    id: minimap
    implicitWidth: 400
    implicitHeight: 580
    property int selectMapStyle: 10
    property variant puneGolfRegion: QtPositioning.rectangle(QtPositioning.coordinate(18.560197708387605, 73.87943025330222), QtPositioning.coordinate(18.551877431743463, 73.89212607934934))


    MouseArea {
        id: maDummy
        anchors.fill: parent
    }

    Map {
        id: map
        anchors.fill: parent
        bearing: 0
//        visibleRegion: puneGolfRegion
        center: gps.position.coordinate
        zoomLevel: 18
        activeMapType: supportedMapTypes[selectMapStyle]
        plugin: Plugin {
            id: mapPlugin
            name: "mapboxgl"
            locales: "en_IN"
            PluginParameter {
                name: "mapboxgl.access_token"
                value: "pk.eyJ1IjoidXhvcmlvdXNnaG9zdCIsImEiOiJja3UzbjVoMnozMTgzMm9xdGNxa3loamZkIn0.vxT4hXVUJh5-ZClMZRNAtA"
            }
            PluginParameter {
                name: "mapboxgl.mapping.additional_style_urls"
                value: "mapbox://styles/uxoriousghost/cku3ww11k12tp17o5vm4gfvjf"
            }
            Component.onCompleted: {
                console.log("Service Providers: ", mapPlugin.availableServiceProviders)
            }
        }
        MapQuickItem {
            id: locPointer
            anchorPoint.x: imgMarker.width / 2
            anchorPoint.y: imgMarker.height
            sourceItem:
                Image {
                id: imgMarker
                source: "qrc:/assets/mm_20_red.png"
            }
        }
        MapPolyline {
            id: polyLinenav
            line.width: 5
            line.color: "blue"
            visible: map.zoomLevel > 16 ? true : false
            path: navJSON.navPath
        }
    }
    PositionSource {
        id: gps
        updateInterval: 10
        active: true
        onPositionChanged: {
            locPointer.coordinate = gps.position.coordinate
            map.center = gps.position.coordinate
        }
    }
}
