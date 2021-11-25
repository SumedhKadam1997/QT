import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtLocation 5.15
import QtPositioning 5.15
import QtSensors 5.15
import "componentCreation.js" as MyScript

Window {
    id: window
    width: 1024
    height: 600
    visible: true
    title: qsTr("Map Application")
    //    3 = terrain
    //    0 = terrain india
    //    4 = satellite
    //    5 = satellite with marking
    //    7 = black plain
    //    9 = black with marking
    //    13 = terrain india

    property var comp
    property var obj
    property variant scaleLengths: [5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000, 2000000]
    property int mapType: 1
    property double mapBearing
    property double mapTilt
    property string mapStyleUrl: "mapbox://styles/uxoriousghost/cku3ww11k12tp17o5vm4gfvjf"
    property double latitude: gps.position.coordinate.latitude
    property double longitude: gps.position.coordinate.longitude
    property variant puneGolfRegion: QtPositioning.rectangle(QtPositioning.coordinate(18.560197708387605, 73.87943025330222), QtPositioning.coordinate(18.551877431743463, 73.89212607934934))
    property variant locationPuneGolf: QtPositioning.coordinate(18.560197708387605, 73.87943025330222)
    property bool pathTrack: false
    property variant doubleClickCoord

    function formatDistance(meters)
    {
        var dist = Math.round(meters)
        if (dist > 1000 ){
            if (dist > 100000){
                dist = Math.round(dist / 1000)
            }
            else {
                dist = Math.round(dist / 100)
                dist = dist / 10
            }
            dist = dist + " km"
        }
        else {
            dist = dist + " m"
        }
        return dist
    }

    function calculateScale()
    {
        var coord1, coord2, dist, text, f
        f = 0
        coord1 = map.toCoordinate(Qt.point(0,scale.y))
        coord2 = map.toCoordinate(Qt.point(0+scaleImage.sourceSize.width,scale.y))
        dist = Math.round(coord1.distanceTo(coord2))

        if (dist === 0) {
            // not visible
        } else {
            for (var i = 0; i < scaleLengths.length-1; i++) {
                if (dist < (scaleLengths[i] + scaleLengths[i+1]) / 2 ) {
                    f = scaleLengths[i] / dist
                    dist = scaleLengths[i]
                    break;
                }
            }
            if (f === 0) {
                f = dist / scaleLengths[i]
                dist = scaleLengths[i]
            }
        }

        text = formatDistance(dist)
        scaleImage.width = (scaleImage.sourceSize.width * f) - 2 * scaleImageLeft.sourceSize.width
        scaleText.text = text
    }
    ListModel {
        id: stopsModel
        ListElement {
            num: 1
            latitude: 18.55392534707373
            longitude: 73.88799441883614
        }
        ListElement {
            num: 2
            latitude: 18.55382534707373
            longitude: 73.88799441883614
        }
        ListElement {
            num: 3
            latitude: 18.55372534707373
            longitude: 73.88699441883614
        }
        ListElement {
            num: 4
            latitude: 18.55362534707373
            longitude: 73.88699441883614
        }
        ListElement {
            num: 5
            latitude: 18.55352534707373
            longitude: 73.88699441883614
        }
        ListElement {
            num: 6
            latitude: 18.55342534707373
            longitude: 73.88799441883614
        }
        ListElement {
            num: 7
            latitude: 18.55332534707373
            longitude: 73.88799441883614
        }
        ListElement {
            num: 8
            latitude: 18.55322534707373
            longitude: 73.88799441883614
        }
        ListElement {
            num: 9
            latitude: 18.55312534707373
            longitude: 73.88799441883614
        }
        ListElement {
            num: 10
            latitude: 18.55302534707373
            longitude: 73.88799441883614
        }
    }

    Item {
        id: root
        anchors.fill: parent

        PlaceSearchModel {
            id: searchModel
            plugin: mapBox_Plugin
            searchArea: QtPositioning.circle(locationPuneGolf)
            Component.onCompleted: update()
        }
        
        GeocodeModel {
            id: geoModel
            plugin: mapBox_Plugin
            
        }

        Plugin {
            id: aPlugin
            name: "osm"
        }

        RouteQuery {
            id: aQuery
        }

        RouteModel {
            id: routeModel
            plugin: mapBox_Plugin
            query: aQuery
            autoUpdate: false
        }
        Plugin{
            id : mapBox_Plugin
            name: "mapbox"
            locales: "en_IN"
            PluginParameter{
                name: "mapbox.access_token"
                value: "pk.eyJ1IjoidXhvcmlvdXNnaG9zdCIsImEiOiJja3R3bzM0bGIwdzJpMnBtbWFhY3c2aTFhIn0.ao2--fEOJlex1FazFs5SoQ"
            }
        }

        Map {
            id: map
            anchors.fill: parent
            zoomLevel: 21
            bearing: 0
            onZoomLevelChanged: {
                calculateScale()
            }

            visibleRegion: puneGolfRegion
            activeMapType: supportedMapTypes[mapType]
            plugin: Plugin {
                id: mapboxglPlugin
                name: "mapboxgl"
                locales: "en_IN"
                PluginParameter {
                    name: "mapboxgl.access_token"
                    value: "pk.eyJ1IjoidXhvcmlvdXNnaG9zdCIsImEiOiJja3UzbjVoMnozMTgzMm9xdGNxa3loamZkIn0.vxT4hXVUJh5-ZClMZRNAtA"
                }
                PluginParameter {
                    name: "mapboxgl.mapping.additional_style_urls"
                    value: mapStyleUrl
                }
            }
            //            Component.onCompleted: {
            //                console.log(map.supportedMapTypes.length)
            //            }
            onBearingChanged: {
                mapBearing = bearing
            }
            onTiltChanged: {
                mapTilt = tilt
            }
            MapCircle {
                center: locationPuneGolf
                radius: 50
                color: 'skyblue'
                opacity: 0.5
                border.color: "blue"
                border.width: 3
            }
            MapQuickItem {
                id: locPointer
//                coordinate: gps.position.coordinate
                coordinate: QtPositioning.coordinate(18.553286, 73.888045)
                anchorPoint.x: imgMarker.width / 2
                anchorPoint.y: imgMarker.height
                visible: false
                sourceItem:
                    Image {
                    id: imgMarker
                    source: "qrc:/assets/mm_20_red.png"
                }
            }
            MapQuickItem {
                id: clickPointer
                coordinate: QtPositioning.coordinate(40.76, -73.984)
                //            coordinate: gps.position.coordinate
                anchorPoint.x: imgClickMarker.width / 2
                anchorPoint.y: imgClickMarker.height
                sourceItem:
                    Image {
                    id: imgClickMarker
                    width: 20
                    height: 30
                    source: "qrc:/assets/icon_Balloon_.png"
                }
            }
            //            MapRoutes {

            //            }
            MapPolyline {
                id: polyLine
                line.width: 5
                line.color: "red"
                visible: true
//                visible: map.zoomLevel > 16 ? true : false
//                path: nav.path
//                path: db.basePath
                path: navJSON.basePath
            }
//            MapPolyline {
//                id: polyLinenav
//                line.width: 5
//                line.color: "blue"
//                visible: true
////                visible: map.zoomLevel > 16 ? true : false
////                path: nav.path
////                path: db.basePath
//                path: navJSON.navPath
//            }

            MapItemView {
                id: stopsMarker
                model: stopsModel
                visible: false
                delegate: MapCircle {
                    center: QtPositioning.coordinate(latitude, longitude)
                    radius: 5
                    color: "white"
                }
            }
            MapItemView {
                id: stopsNumber
                model: stopsModel
                visible: false
                delegate: MapQuickItem {
                    coordinate: QtPositioning.coordinate(latitude, longitude)
                    sourceItem: Text {
                        id: txtNumber
                        text: num
                        color: "black"
                        font.pixelSize: 15
                        anchors.centerIn: parent
                        visible: map.zoomLevel > 18 ? true : false
                    }
                }
            }

            MapItemView {
                id: searchMarker
                model: searchModel
                visible: false
                delegate: MapQuickItem {
                    coordinate: place.location.coordinate
                    anchorPoint.x: image.width / 2
                    anchorPoint.y: image.height

                    sourceItem: Column {
                        Image {
                            id: image
                            width: 20
                            height: 30
                            source: "qrc:/assets/icon_Balloon_.png" }
                        Text { text: title; font.bold: true }
                    }
                }
            }
            MouseArea {
                id: maMap
                anchors.fill: parent
                onPressAndHold: {
//                    clickPointer.coordinate = map.toCoordinate(Qt.point(mouse.x,mouse.y))
                    console.log(map.toCoordinate(Qt.point(mouse.x,mouse.y)))
                }
                onClicked: {
                    clickPointer.visible = false
                }

                onDoubleClicked: {
                    doubleClickCoord = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                    animCentreClick.start()
//                    map.center = map.toCoordinate(Qt.point(mouse.x,mouse.y))
                    animMapDoubleClickZoom.start()
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
        //    }
        Rectangle {
            id: rectStyleSelector
            width: 600
            height: 120
            color: "#858585"
            opacity: 0.5
            radius: 10
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
        }

        Row {
            width: 600
            height: 120
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            leftPadding: 40
            spacing: 40
            Repeater {
                model: 4
                Rectangle {
                    width: 100
                    height: 100
                    radius: 10
                    border.width: 2
                    border.color: "white"
                    anchors.verticalCenter: parent.verticalCenter
                    Image {
                        id: imgStyle
                        anchors.fill: parent
                        anchors.margins: 3
                        fillMode: Image.PreserveAspectFit
                        source: switch (index) {
                                case 0 : "qrc:/assets/LightMapStyle.png"
                                    break
                                case 1 : "qrc:/assets/SatelliteMap Style.png"
                                    break
                                case 2 : "qrc:/assets/TerrainMap Style.png"
                                    break
                                case 3 : "qrc:/assets/DarkMapStyle.png"
                                    break
                                }
                    }
                    Text {
                        id: txtStyle
                        anchors.bottom: parent.bottom
                        anchors.bottomMargin: 15
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: switch (index) {
                              case 0 : "Default"
                                  break
                              case 1 : "Satellite"
                                  break
                              case 2 : "Terrain"
                                  break
                              case 3 : "Dark"
                                  break
                              }
                    }
                    MouseArea {
                        id: maMapStyle
                        anchors.fill: parent
                        onClicked: switch (index) {
                                   case 0 : mapType = 1
                                       break
                                   case 1 : mapType = 6
                                       break
                                   case 2 : mapType = 11
                                       break
                                   case 3 : mapType = 10
                                       break
                                   }
                    }
                }
            }
        }


        PositionSource {
            id: gps
            updateInterval: 10
            active: true
            onPositionChanged: {
                //                if (gps.position.speed == 0 && gps.position.horizontalAccuracy <= 20) {
                //                    gpsAccuracy = gps.position.horizontalAccuracy
                //                    animAccuracyCircle.start()
                //                } else if (gps.position.horizontalAccuracy > 20 && gps.position.horizontalAccuracy <= 30 && gps.position.speed < 5) {
                //                    gpsAccuracy = gps.position.horizontalAccuracy
                //                    animAccuracyCircle.start()
                //                } else if (gps.position.horizontalAccuracy > 20 && gps.position.horizontalAccuracy <= 30 && gps.position.speed > 5) {
                //                    gpsAccuracy = gps.position.horizontalAccuracy
                //                    animAccuracyCircle.start()
                //                    animLocPointer.start()
                //    //                locPointer.coordinate = gps.position.coordinate
                //                    lastKnownCoord = gps.position.coordinate
                //                } else if (gps.position.horizontalAccuracy > 30 && gps.position.horizontalAccuracy <= 30 && gps.position.speed < 5) {
                //                    gpsAccuracy = gps.position.horizontalAccuracy
                //                    animAccuracyCircle.start()
                //                } else if (gps.position.horizontalAccuracy > 30 && gps.position.horizontalAccuracy <= 30 && gps.position.speed > 5) {
                //                    gpsAccuracy = gps.position.horizontalAccuracy
                //                    animAccuracyCircle.start()
                //                    animLocPointer.start()
                //    //                locPointer.coordinate = gps.position.coordinate
                //                    lastKnownCoord = gps.position.coordinate
                //                }
                if (pathTrack) {
                    polyLine.addCoordinate(gps.position.coordinate)
                    //            assetmodel.addAsset(gps.position.coordinate, 50, "buggy");
                }
            }
        }
        Timer {
            id: timer
            repeat: true
            interval: 5000
            running: true
            onTriggered: {
                //            mapType += 1
                //            console.log("Map Type Changed")
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
//                map.zoomLevel
            }
        }
        Button {
            id: btnGolf
            text: "golf"
            anchors.left: btnBearing.right
            onClicked: {
                map.fitViewportToMapItems()
            }
        }
        Button {
            id: btnCreateComp
            text: "Create Comp"
            anchors.left: btnGolf.right
            onClicked: {
//                comp = Qt.createComponent("qrc:/navPathPolyLine.qml")
//                if (comp.status == Component.Ready)
//                    obj = comp.createObject(map);
                console.log("Creating polyline")
                MyScript.createPloyLine()
                console.log("Created Polyline")
            }
        }
        Button {
            id: btnDemComp
            text: "Delete Comp"
            anchors.left: btnCreateComp.right
            onClicked: {
//                obj.destroy()
                MyScript.deletePolyLine()
            }
        }

//        Button {
//            id: btnRemPath
//            text: "Clear Path"
//            anchors.left: btnGolf.right
//            onClicked: {
//                for (var i = 0; i <= polyLine.pathLength() - 1; ++i) {
//                    polyLine.removeCoordinate(i)
//                }
//            }
//        }
//        Button {
//            id: btnAddPath
//            text: "Start Tracking"
//            anchors.left: btnRemPath.right
//            onClicked: {
//                pathTrack = true
//                //                polyLine.addCoordinate(locationPuneGolf)
//            }
//        }
//        Button {
//            id: btnStopPath
//            text: "Stop Tracking"
//            anchors.top: btnAddPath.bottom
//            anchors.left: parent.left
//            onClicked: {
//                pathTrack = false
//                //                polyLine.addCoordinate(locationPuneGolf)
//            }
//        }
        Item {
            id: scale
            z: map.z + 3
            visible: scaleText.text != "0 m"
            anchors.bottom: root.bottom
            anchors.right: root.right
            anchors.margins: 20
            height: scaleText.height * 2
            width: scaleImage.width

            Image {
                id: scaleImageLeft
                source: "qrc:/assets/scale_end.png"
                anchors.bottom: parent.bottom
                anchors.right: scaleImage.left
            }
            Image {
                id: scaleImage
                source: "qrc:/assets/scale.png"
                anchors.bottom: parent.bottom
                anchors.right: scaleImageRight.left
            }
            Image {
                id: scaleImageRight
                source: "qrc:/assets/scale_end.png"
                anchors.bottom: parent.bottom
                anchors.right: parent.right
            }
            Label {
                id: scaleText
                color: "#004EAE"
                anchors.centerIn: parent
                text: "0 m"
            }
            Component.onCompleted: {
                calculateScale();
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
        PropertyAnimation {
            id: animCentreClick
            target: map
            property: "center"
            from: map.center
            to: doubleClickCoord
            duration: 500
//            easing.type: Easing.InOutExpo
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
        PropertyAnimation {
            id: animMapDoubleClickZoom
            duration: 500
            target: map
            property: "zoomLevel"
            from: map.zoomLevel
            to: map.zoomLevel + 1
//            easing.type: Easing.InOutCubic
        }
    }
}
