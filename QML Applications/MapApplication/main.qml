import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtLocation 5.12
import QtPositioning 5.12
//import Location 1.0

Window {
    width: 1024
    height: 600
    visible: true
    title: qsTr("Map Application")
    property int mapType: 0
    property double latitude: gps.position.coordinate.latitude
    property double longitude: gps.position.coordinate.longitude
    property variant puneGolfRegion: QtPositioning.rectangle(QtPositioning.coordinate(18.560197708387605, 73.87943025330222), QtPositioning.coordinate(18.551877431743463, 73.89212607934934))

    property variant locationOslo: QtPositioning.coordinate(18.560197708387605, 73.87943025330222)

    PlaceSearchModel {
        id: searchModel

        plugin: mapPlugin

        //        searchTerm: "Pizza"
        searchArea: QtPositioning.circle(locationOslo)

        Component.onCompleted: update()

    }

    Map {
        id: map
        anchors.fill: parent
        zoomLevel: 4
        visibleRegion: puneGolfRegion
        //                activeMapType: supportedMapTypes[mapType]
        //        center: QtPositioning.coordinate(18.554437341937323, 73.88714732139219)
        plugin: Plugin {
            id: mapPlugin
            //            name: "mapboxgl"
            name: "osm"
            locales: "en_IN"
        }
        MapItemView {
            id: searchMarker
            model: searchModel
            visible: false
            delegate: MapQuickItem {
                coordinate: place.location.coordinate
                anchorPoint.x: image.width / 2
                anchorPoint.y: image.height / 2

                sourceItem: Column {
                    Image {
                        id: image
                        width: 20
                        height: 30
                        source: "qrc:/icon_Balloon_.png" }
                    Text { text: title; font.bold: true }
                }
            }
        }
        MapItemView {
            model: assetmodel
            delegate: MapMarker{
                coordinate: assetData
                name: nameData
                transformOrigin: Item.Center
                z:100
            }
        }
    }
    PositionSource {
        id: gps
        updateInterval: 1000
        active: true

        onPositionChanged: {
            var coord = gps.position.coordinate;
            console.log("Coordinate:", coord.longitude, coord.latitude);
            assetmodel.addAsset(gps.position.coordinate, 50, "buggy");
        }
        Component.onCompleted: {
            var coord = gps.position.coordinate;
            console.log("Coordinate:", coord.longitude, coord.latitude);
        }
    }
    Timer {
        id: timer
        repeat: true
        interval: 5000
        running: true
        onTriggered: {
            mapType += 1
            console.log("Map Type Changed")
        }
    }
    Button {
        id: btnCentre
        text: "Centre"
        onClicked: {
            map.center = gps.position.coordinate
            //            map.center = QtPositioning.coordinate(18.554437341937323, 73.88714732139219)
        }
    }
    Button {
        id: btnSearch
        text: "Search"
        anchors.left: btnCentre.right
        onClicked: {
            searchModel.searchTerm = "car"
            searchModel.update()
            searchMarker.visible = true
        }
    }
    Button {
        id: btnSearchCancel
        text: "Cancel"
        anchors.left: btnSearch.right
        onClicked: {
            searchMarker.visible = false
        }
    }
}
