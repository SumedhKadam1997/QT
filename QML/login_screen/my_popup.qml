import QtQuick 2.0
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.15

Item {
    id: popup_item

    property string error_message : ""

    signal clicked()

    Rectangle {
        id: popup_rect
        anchors.fill: parent
        border.color: "#34C9E4"
        border.width: 2
        color: "#CCF2F9"
        radius: 20
        Text {
            id: name
            text: popup_item.error_message
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.verticalCenterOffset: - parent.height / 4
            anchors.horizontalCenter: parent.horizontalCenter
            fontSizeMode: Text.Fit
            color: "#34C9E4"
            font.pixelSize: parent.height / 10
        }
        Button {
            id: ok_button
            width: parent.width / 4
            height: parent.height / 6
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: parent.height / 6
            text: "OK"
            font.pixelSize: parent.height / 12
            contentItem: Text {
                id: custom_popup_text
                anchors.fill: parent
                text: ok_button.text
                font: ok_button.font
                color: "#34C9E4"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                fontSizeMode: Text.Fit
            }
            background: Rectangle {
                id: custom_popup_button
                color: "#CCF2F9"
                border.color: "#34C9E4"
                border.width: 1
                radius: 5
            }
            onPressed: {
                custom_popup_button.color = "#34C9E4"
                custom_popup_button.border.color = "#CCF2F9"
                custom_popup_text.color = "#CCF2F9"
            }
            onReleased:  {
                custom_popup_button.color = "#CCF2F9"
                custom_popup_button.border.color = "#34C9E4"
                custom_popup_text.color = "#34C9E4"
            }
            onClicked: {
                popup_item.clicked()
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.33;height:480;width:640}
}
##^##*/
