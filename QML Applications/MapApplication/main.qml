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

    PlaceSearchModel {
        id: searchModel
        plugin: mapPlugin
        searchArea: QtPositioning.circle(locationPuneGolf)
        Component.onCompleted: update()
    }

    Map {
        id: map
        anchors.fill: parent
        zoomLevel: 10
        bearing: 0
        visibleRegion: puneGolfRegion
        activeMapType: supportedMapTypes[mapType]
        plugin: Plugin {
            id: mapPlugin
            name: "mapboxgl"
            //            name: "osm"
            locales: "en_IN"
            //            PluginParameter {
            //                name: "googlemaps.maps.apikey "
            //                value: ""
            //            }
        }
        onBearingChanged: {
            mapBearing = bearing
        }
        onTiltChanged: {
            mapTilt = tilt
        }
        MapQuickItem {
            id: locpOinter
            coordinate: gps.position.coordinate
            anchorPoint.x: imgMarker.width / 2
            anchorPoint.y: imgMarker.height
            sourceItem:
                Image {
                id: imgMarker
                source: "qrc:/mm_20_red.png"
            }
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
//        MapItemView {
//            model: assetmodel
//            delegate: MapMarker{
//                coordinate: assetData
//                name: nameData
//                transformOrigin: Item.Center
//                z:100
//            }
//        }
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
            animCentreLoc.start()
            //            map.fitViewportToGeoShape(puneGolfRegion, 20)
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
            map.bearing < 180 ? animTiltBearLeft.start() : animTiltBearRight.start()
        }
    }
    PropertyAnimation {
        id: animCentreLoc
        target: map
        property: "center"
        from: map.center
        to: gps.position.coordinate
        duration: 1000
        easing.type: Easing.InOutExpo
    }

    ParallelAnimation {
        id: animTiltBearLeft
        PropertyAnimation {
            id: animBearingLeft
            duration: 500
            target: map
            property: "bearing"
            from: mapBearing
            to: 0
            easing.type: Easing.InOutExpo
        }
        PropertyAnimation {
            id: animTiltLeft
            duration: 5000
            target: map
            property: "tilt"
            from: mapTilt
            to: 0
            easing.type: Easing.InOutExpo
        }
    }
    ParallelAnimation {
        id: animTiltBearRight
        PropertyAnimation {
            id: animBearingRight
            duration: 500
            target: map
            property: "bearing"
            from: mapBearing
            to: 359.99
            easing.type: Easing.InOutExpo
        }
        PropertyAnimation {
            id: animTiltRight
            duration: 500
            target: map
            property: "tilt"
            from: mapTilt
            to: 0
            easing.type: Easing.InOutExpo
        }
    }
}
