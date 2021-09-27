import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtLocation 5.12
import QtPositioning 5.12
import QtSensors 5.15

Window {
    width: 1024
    height: 600
    visible: true
    title: qsTr("Map Application")
    property int mapType: 0
    property double mapBearing
    property double mapTilt
    property double latitude: gps.position.coordinate.latitude
    property double longitude: gps.position.coordinate.longitude
    property variant puneGolfRegion: QtPositioning.rectangle(QtPositioning.coordinate(18.560197708387605, 73.87943025330222), QtPositioning.coordinate(18.551877431743463, 73.89212607934934))

    property variant locationPuneGolf: QtPositioning.coordinate(18.560197708387605, 73.87943025330222)
    //    onMapBearingChanged: {
    //        console.log(mapBearing)
    //    }

    PlaceSearchModel {
        id: searchModel
        plugin: mapPlugin
        //        searchTerm: "Pizza"
        searchArea: QtPositioning.circle(locationPuneGolf)
        Component.onCompleted: update()

    }
    ParallelAnimation {
        id: paraAnimLeft

        PropertyAnimation {
            id: animBearingLeft
            duration: 500
            target: map
            property: "bearing"
            from: mapBearing
            to: 0
        }
        PropertyAnimation {
            id: animTiltLeft
            duration: 5000
            target: map
            property: "tilt"
            from: mapTilt
            to: 0
        }
    }
    ParallelAnimation {
        id: paraAnimRight

        PropertyAnimation {
            id: animBearingRight
            duration: 500
            target: map
            property: "bearing"
            from: mapBearing
            to: 359.99
        }
        PropertyAnimation {
            id: animTiltRight
            duration: 500
            target: map
            property: "tilt"
            from: mapTilt
            to: 0
        }
    }

    //    Compass {
    //        id: compass
    //        active: true
    //        CompassReading {
    //            id: reading
    //        }

    //        onCurrentOrientationChanged: {
    //           console.log("Compass orientation: ", currentOrientation)
    //        }
    //    }

    Map {
        id: map
        anchors.fill: parent
        zoomLevel: 10
        onBearingChanged: {
            console.log(bearing)
            mapBearing = bearing
        }
        onTiltChanged: {
            mapTilt = tilt
        }

        bearing: 0
        visibleRegion: puneGolfRegion
        //                activeMapType: supportedMapTypes[mapType]
        //        center: QtPositioning.coordinate(18.554437341937323, 73.88714732139219)
        plugin: Plugin {
            id: mapPlugin
            name: "mapboxgl"
            //            name: "osm"
            locales: "en_IN"
            //            name: "googlemaps"
            //            PluginParameter {
            //                name: "googlemaps.maps.apikey "
            //                value: ""
            //            }
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
            map.fitViewportToGeoShape(puneGolfRegion, 20)
            //            map.center = gps.position.coordinate
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
    Button {
        id: btnBearing
        text: "North"
        anchors.left: btnSearchCancel.right
        onClicked: {
            //            map.bearing = 0
            map.bearing < 180 ? paraAnimLeft.start() : paraAnimRight.start()
//            paraAnim.start()
        }
    }
}
