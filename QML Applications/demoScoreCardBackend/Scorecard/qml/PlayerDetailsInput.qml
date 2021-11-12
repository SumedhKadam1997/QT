import QtQuick 2.12
import QtQuick.Controls 2.12
import QtGraphicalEffects 1.15

Popup {
    id:item_PlayerDetails
    implicitWidth: 500
    implicitHeight: 450
    modal: true
    visible: false
    focus: true
    padding: 0
    background: Rectangle {
        anchors.fill: parent
        color: "#00000000"
    }
    closePolicy: Popup.NoAutoClose
    anchors.centerIn: parent

    Rectangle {
        id: rect_BG
        color: "#071627"
        radius: (0.009) * (item_PlayerDetails.width + item_PlayerDetails.height ) //8
        anchors.fill: parent
    }
    DropShadow {
        id: dropShadowBG
        anchors.fill: rect_BG
        color: "#01A2C3"
        source: rect_BG
        radius: (0.009) * (item_PlayerDetails.width + item_PlayerDetails.height ) //8
    }

    Text {
        id: txt_Header
        color: "#f2f2f2"
        text: qsTr("Player Information")
        anchors.top: parent.top
        font.pixelSize: (0.025) * (item_PlayerDetails.width + item_PlayerDetails.height ) //24
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.topMargin: (0.063) * item_PlayerDetails.height //28
        font.weight: Font.Medium
        font.family: "Roboto"
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Column {
        id: column
        width: (0.5) * item_PlayerDetails.width //250
        height: (0.54) * item_PlayerDetails.height //240
        anchors.top: parent.top
        anchors.topMargin: (0.21) * item_PlayerDetails.height //95
        spacing: (0.067) * item_PlayerDetails.height //30
        anchors.horizontalCenter: parent.horizontalCenter

        Item {
            id: item_PlayerName
            width: parent.width
            height: (0.133) * item_PlayerDetails.height //60


            TextInput {
                id: txtInput_PlayerName
                width: parent.width
                height: (0.045) * item_PlayerDetails.height //20
                color: "#f2f2f2"
//                text: qsTr("Pavan")
                anchors.left: parent.left
                anchors.bottom: rect_Separator1.top
                font.pixelSize: (0.017) * (item_PlayerDetails.width + item_PlayerDetails.height ) //16
                verticalAlignment: Text.AlignTop
                anchors.leftMargin: (0.01) * item_PlayerDetails.width //5
                anchors.bottomMargin: 1
            }
            Rectangle {
                id: rect_Separator1
                height: 2
                color: "#707070"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.leftMargin: 0
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
            }

            Text {
                id: txt_PlayerName
                height: (0.058) * item_PlayerDetails.height //26
                color: "#f2f2f2"
                text: qsTr("Player Name")
                anchors.left: parent.left
                anchors.top: parent.top
                font.pixelSize: (0.021) * (item_PlayerDetails.width + item_PlayerDetails.height ) //20
                verticalAlignment: Text.AlignVCenter
                anchors.topMargin: 0
                anchors.leftMargin: 0
            }
        }

        Item {
            id: item_MemID
            width: parent.width
            height: (0.133) * item_PlayerDetails.height //60
            TextInput {
                id: txtInput_MemId
                width: parent.width
                height: (0.045) * item_PlayerDetails.height //20
                color: "#f2f2f2"
//                text: qsTr("12345")
                anchors.left: parent.left
                anchors.bottom: rect_Separator2.top
                font.pixelSize: (0.017) * (item_PlayerDetails.width + item_PlayerDetails.height ) //16
                verticalAlignment: Text.AlignTop
                anchors.bottomMargin: 1
                anchors.leftMargin: (0.01) * item_PlayerDetails.width //5
            }

            Rectangle {
                id: rect_Separator2
                height: 2
                color: "#707070"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.rightMargin: 0
            }

            Text {
                id: txt_MemID
                height: (0.058) * item_PlayerDetails.height //26
                color: "#f2f2f2"
                text: qsTr("Membership ID")
                anchors.left: parent.left
                anchors.top: parent.top
                font.pixelSize: (0.021) * (item_PlayerDetails.width + item_PlayerDetails.height ) //20
                verticalAlignment: Text.AlignVCenter
                anchors.topMargin: 0
                anchors.leftMargin: 0
            }
        }

        Item {
            id: item_Handicap
            width: parent.width
            height: (0.133) * item_PlayerDetails.height //60
            TextInput {
                id: txtInput_Handicap
                width: parent.width
                height: (0.045) * item_PlayerDetails.height //20
                color: "#f2f2f2"
//                text: qsTr("5")
                anchors.left: parent.left
                anchors.bottom: rect_Separator3.top
                font.pixelSize: (0.017) * (item_PlayerDetails.width + item_PlayerDetails.height ) //16
                verticalAlignment: Text.AlignTop
                anchors.bottomMargin: 1
                anchors.leftMargin: (0.01) * item_PlayerDetails.width //5
            }

            Rectangle {
                id: rect_Separator3
                height: 2
                color: "#707070"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.rightMargin: 0
            }

            Text {
                id: txt_Handicap
                height: (0.058) * item_PlayerDetails.height //26
                color: "#f2f2f2"
                text: qsTr("Handicap")
                anchors.left: parent.left
                anchors.top: parent.top
                font.pixelSize: (0.021) * (item_PlayerDetails.width + item_PlayerDetails.height ) //20
                verticalAlignment: Text.AlignVCenter
                anchors.topMargin: 0
                anchors.leftMargin: 0
            }
        }
    }
    DropShadow {
        id: dropShadowBtn
        anchors.fill: rect_Btn
        color: "#01A2C3"
        source: rect_Btn
        radius: (0.008) * (item_PlayerDetails.width + item_PlayerDetails.height ) //10
    }
    Rectangle {
        id: rect_Btn
        width: (0.5) * item_PlayerDetails.width //250
        height: (0.111) * item_PlayerDetails.height //50
        color: "#ffffff"
        radius: (0.008) * (item_PlayerDetails.width + item_PlayerDetails.height ) //10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: (0.036) * item_PlayerDetails.height //16
        anchors.horizontalCenter: parent.horizontalCenter
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#01A2C3" }
            GradientStop { position: 0.65; color: "#06293C" }
            GradientStop { position: 1.0; color: "#071627" }
        }

        Text {
            id: txt_Btn
            color: "#01a2c3"
            text: qsTr("Add Player")
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: (0.021) * (item_PlayerDetails.width + item_PlayerDetails.height ) //20
            font.family: "Roboto"
            font.weight: Font.Medium
            anchors.horizontalCenter: parent.horizontalCenter
        }

        MouseArea {
            id: ma_Btn
            anchors.fill: parent
            onClicked: {
                switch (addPlayerIndex) {
                case 0 : scorecard.player1Name = txtInput_PlayerName.text
                    break
                case 1 : scorecard.player2Name = txtInput_PlayerName.text
                    break
                case 2 : scorecard.player3Name = txtInput_PlayerName.text
                    break
                case 3 : scorecard.player4Name = txtInput_PlayerName.text
                    break
                }
                addPlayerIndex += 1
                scoreInput.addPlayer(txtInput_PlayerName.text, txtInput_MemId.text, txtInput_Handicap.text)
                item_PlayerDetails.visible = false
                txtInput_PlayerName.text = txtInput_MemId.text = txtInput_Handicap.text = ""
            }
        }
    }

    Image {
        id: image
        width: (0.032) * item_PlayerDetails.width //16
        height: width
        anchors.right: parent.right
        anchors.top: parent.top
        source: "qrc:/assets/img_Cross.png"
        anchors.topMargin: (0.044) * item_PlayerDetails.height //20
        anchors.rightMargin: (0.04) * item_PlayerDetails.width //20
        fillMode: Image.PreserveAspectFit
        MouseArea {
            id: maClosePopup
            anchors.fill: parent
            onClicked: {
                item_PlayerDetails.visible = false
            }
        }
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:6}D{i:7}D{i:8}D{i:9}D{i:13}D{i:4}
}
##^##*/
