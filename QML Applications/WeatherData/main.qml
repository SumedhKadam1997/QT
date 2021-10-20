import QtQuick 2.12
import QtQuick.Window 2.12
import WeatherInfo 1.0
import ForecastWeather 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    WeatherInfo {
        id: weather
    }

    ForecastWeather {
        id: forecastModel
    }
}
