import QtQuick 2.12
import QtQuick.Controls 2.12
import QtLocation 5.15
import QtPositioning 5.15
import QtSensors 5.15

MapPolyline {
    id: route1
    line.width: 3
    line.color: "red"
    visible: true
    path: [
        { latitude: 18.553925347073736, longitude: 73.88799441883614 },
        { latitude: 18.553886123883544, longitude: 73.8856200551377 },
        { latitude: 18.554803765002095, longitude: 73.88614125106714 },
        { latitude: 18.555784129677242, longitude: 73.8843211442432 }
    ]
}
