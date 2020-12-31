import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls 2.15
import QtQuick.Dialogs.qml 1.0
import QtQuick.Extras 1.4
import QtQuick.Layouts 1.11
import QtQuick.Shapes 1.14
import QtCharts 2.3
import Database 1.0


Rectangle {
    id: main_input_rect
    color: "black"

    Rectangle {
        id: oee_input_rect
        x: 44
        y: 46
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: oee_textInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: ava_input_rect
        x: 44
        y: 104
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: ava_textInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: perf_input_rect
        x: 44
        y: 169
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: perf_textInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: qua_input_rect
        x: 44
        y: 223
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: quatextInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: total_count_input_rect
        x: 44
        y: 285
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: total_count_textInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: reject_input_rect
        x: 44
        y: 352
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: reject_textInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: shift_input_rect
        x: 409
        y: 158
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: shift_textInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: stop_time_input_rect
        x: 409
        y: 80
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: stop_time_textInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: breakdown_time_input_rect
        x: 409
        y: 223
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: breakdown_time_textInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: run_time_input_rect
        x: 409
        y: 299
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: runtime_textInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: ideal_cycle_input_rect
        x: 409
        y: 366
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: ideal_cycle_textInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: actual_cycle_input_rect
        x: 409
        y: 420
        width: 155
        height: 35
        color: "#ffffff"

        TextInput {
            id: actual_cycle_textInput
            anchors.fill: parent
            text: qsTr("Text Input")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.66;height:480;width:640}
}
##^##*/
