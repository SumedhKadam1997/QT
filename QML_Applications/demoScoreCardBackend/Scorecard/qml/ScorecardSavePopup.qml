import QtQuick 2.0

Item {
    id:item_ScorecardSavePopup
    implicitWidth: 500
    implicitHeight: 300

    Rectangle {
        id: rect_BG
        color: "#071627"
        radius: (0.0125) * (item_ScorecardSavePopup.width + item_ScorecardSavePopup.height )//10
        border.color: "#01A2C3"
        anchors.fill: parent
    }

    Image {
        id: img_ScorecardIcon
        width: (0.16 ) * item_ScorecardSavePopup.width //80
        height: width //80
        anchors.top: parent.top
        source: "qrc:/assets/img_Scorecard.png"
        anchors.topMargin: (0.133) * item_ScorecardSavePopup.height //40
        anchors.horizontalCenter: parent.horizontalCenter
        fillMode: Image.PreserveAspectFit
    }

    Text {
        id: txt_Msg
        color: "#F2F2F2"
        text: qsTr("Do you want to save scorecard?")
        anchors.top: img_ScorecardIcon.bottom
        font.pixelSize: (0.025) * (item_ScorecardSavePopup.width + item_ScorecardSavePopup.height ) //20
        anchors.topMargin: (0.11) * item_ScorecardSavePopup.height //33
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Rectangle {
        id: rect_yes
        width: (0.24 ) * item_ScorecardSavePopup.width //120
        height: (0.133) * item_ScorecardSavePopup.height //40
        color: "#00000000"
        radius: (0.0075) * (item_ScorecardSavePopup.width + item_ScorecardSavePopup.height )//6
        border.color: "#01a2c3"
        anchors.right: parent.right
        anchors.top: txt_Msg.bottom
        anchors.topMargin: (0.1167) * item_ScorecardSavePopup.height //35
        anchors.rightMargin: (0.08) * item_ScorecardSavePopup.width //40

        Text {
            id: txt_Yes
            color: "#F2F2F2"
            text: qsTr("Yes")
            anchors.fill: parent
            font.pixelSize: (0.0225) * (item_ScorecardSavePopup.width + item_ScorecardSavePopup.height )//18
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Roboto"
            font.weight: Font.Medium
        }

        MouseArea {
            id: ma_Yes
            anchors.fill: parent
        }
    }

    Rectangle {
        id: rect_No
        width: (0.24 ) * item_ScorecardSavePopup.width //120
        height: (0.133) * item_ScorecardSavePopup.height //40
        color: "#00000000"
        radius: (0.0075) * (item_ScorecardSavePopup.width + item_ScorecardSavePopup.height )//6
        border.color: "#01A2C3"
        anchors.verticalCenter: rect_yes.verticalCenter
        anchors.right: rect_yes.left
        anchors.rightMargin: (0.08) * item_ScorecardSavePopup.width //40

        Text {
            id: txt_No
            color: "#F2F2F2"
            text: qsTr("No")
            anchors.fill: parent
            font.pixelSize: (0.0225) * (item_ScorecardSavePopup.width + item_ScorecardSavePopup.height )//18
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Roboto"
            font.weight: Font.Medium
        }

        MouseArea {
            id: ma_No
            anchors.fill: parent
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}D{i:1}D{i:6}D{i:4}D{i:9}
D{i:7}
}
##^##*/
