import QtQuick 2.0
import QtGraphicalEffects 1.15
Item {
    id: item_ScorecardScreen1
    implicitWidth: 1280
    implicitHeight: 700

    property int addPlayerIndex: 0

    MouseArea {
        id: ma_Dummy
        anchors.fill: parent
    }

    Image {
        id: img_BG
        anchors.fill: parent
        source: "qrc:/assets/BG.png"
        fillMode: Image.Stretch
    }
    Image {
        id: imgVeGO
        width: (0.06875) * item_ScorecardScreen1.width //88
        height: (0.053) * item_ScorecardScreen1.height //37
        source: "qrc:/assets/VegoLogo.png"
        anchors.topMargin: (0.0458) * item_ScorecardScreen1.height //32
        anchors.leftMargin: (0.03125) * item_ScorecardScreen1.width //40
        anchors.top: parent.top
        anchors.left: parent.left
        fillMode: Image.PreserveAspectFit
    }
    Image {
        id: imgVerolt
        width: (0.046875) * item_ScorecardScreen1.width //60
        height: width
        source: "qrc:/assets/VeroltLogo.png"
        anchors.rightMargin: (0.03125) * item_ScorecardScreen1.width //40
        anchors.topMargin: (0.0286) * item_ScorecardScreen1.height //20
        anchors.top: parent.top
        anchors.right: parent.right
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: img_HorizontalSeparator
        height: 2
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        source: "qrc:/assets/Rectangle 511.png"
        anchors.topMargin: (0.143) * item_ScorecardScreen1.height //100
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        fillMode: Image.Stretch
    }

    Text {
        id: txt_Header
        color: "#ffffff"
        text: qsTr("Online Scorecard")
        anchors.bottom: img_HorizontalSeparator.top
        font.pixelSize: (0.0161) * (item_ScorecardScreen1.width + item_ScorecardScreen1.height ) //32
        anchors.bottomMargin: (0.0143) * item_ScorecardScreen1.height //10
        anchors.horizontalCenter: parent.horizontalCenter
        font.weight: Font.Bold
        font.family: "Roboto"
    }

    //    ListView {
    //        id: listview_Players
    //        width: (0.836) * item_ScorecardScreen1.width //1070
    //        height: (0.314) * item_ScorecardScreen1.height //220
    //        anchors.top: parent.top
    //        spacing: (0.1286) * item_ScorecardScreen1.height //90
    //        orientation: ListView.Horizontal
    //        interactive: false
    //        flickableDirection: Flickable.HorizontalFlick
    //        anchors.topMargin: (0.328) * item_ScorecardScreen1.height //230
    //        anchors.horizontalCenter: parent.horizontalCenter
    //        model: 4
    Row {
        id: rowAddPlayers
        width: children.width //(0.836) * item_ScorecardScreen1.width //1070
        height: (0.314) * item_ScorecardScreen1.height
        anchors.top: parent.top
        spacing: (0.1286) * item_ScorecardScreen1.height
        anchors.topMargin: (0.328) * item_ScorecardScreen1.height //230
        anchors.left: parent.left
        anchors.leftMargin: item_ScorecardScreen1.width * 0.082

        Repeater {
            id:repeater_PlayerDetails
            model: scoreInput.playerList

            Item {
                id: item2
                width: (0.15625) * item_ScorecardScreen1.width //200
                height: (0.314) * item_ScorecardScreen1.height //220

                Rectangle{
                    id:rect_Delegate
                    width: (0.15625) * item_ScorecardScreen1.width //200
                    height: (0.314) * item_ScorecardScreen1.height //220
                    color: "#071627"
                    radius: (0.004) * (item_ScorecardScreen1.width + item_ScorecardScreen1.height ) //8
                    border.width: 1
                    border.color: "#01A2C3"

                }
                DropShadow {
                    id: dropShadow
                    anchors.fill: rect_Delegate
                    color: "#01A2C3"
                    source: rect_Delegate
                    radius: (0.004) * (item_ScorecardScreen1.width + item_ScorecardScreen1.height ) //8

                }

                Image {
                    id: img_User
                    width: (0.0625) * item_ScorecardScreen1.width //80
                    height: (0.1143) * item_ScorecardScreen1.height //80
                    anchors.top: parent.top
                    source: "qrc:/Scorecard/assets/img_User.png"
                    anchors.topMargin: (0.0571) * item_ScorecardScreen1.height //40
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    id: txt_UserName
                    color: "#ffffff"
                    text: modelData.name
                    anchors.top: parent.top
                    anchors.topMargin: (0.2285) * item_ScorecardScreen1.height //160
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: (0.0121) * (item_ScorecardScreen1.width + item_ScorecardScreen1.height ) //24
                }
            }
        }
    }

    Item {
        id: itemAddPlayer
        width: (0.15625) * item_ScorecardScreen1.width //200
        height: (0.314) * item_ScorecardScreen1.height //220
        anchors.left: rowAddPlayers.right
        anchors.leftMargin: item_ScorecardScreen1.width * 0.07
        anchors.top: parent.top
        anchors.topMargin: (0.328) * item_ScorecardScreen1.height //230
        visible: repeater_PlayerDetails.count <4 ? true : false

        Rectangle{
            id:rectAddPlayer
            width: (0.15625) * item_ScorecardScreen1.width //200
            height: (0.314) * item_ScorecardScreen1.height //220
            color: "#071627"
            radius: (0.004) * (item_ScorecardScreen1.width + item_ScorecardScreen1.height ) //8
            border.width: 1
            border.color: "#01A2C3"
            MouseArea {
                id: maAddPlayer
                anchors.fill: parent

                onClicked: {
                    popupAddPlayer.visible = true
                }
            }
        }
        DropShadow {
            id: dsAddPlayer
            anchors.fill: rectAddPlayer
            color: "#01A2C3"
            source: rectAddPlayer
            radius: (0.004) * (item_ScorecardScreen1.width + item_ScorecardScreen1.height ) //8

        }

        Image {
            id: imgAddPlayer
            width: (0.0625) * item_ScorecardScreen1.width //80
            height: (0.1143) * item_ScorecardScreen1.height //80
            anchors.top: parent.top
            source: "qrc:/Scorecard/assets/addPlayer.png"
            anchors.topMargin: (0.0571) * item_ScorecardScreen1.height //40
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Text {
            id: txtAddPlayer
            color: "#ffffff"
            text: qsTr("Add Player")
            anchors.top: parent.top
            anchors.topMargin: (0.2285) * item_ScorecardScreen1.height //160
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: (0.0121) * (item_ScorecardScreen1.width + item_ScorecardScreen1.height ) //24
        }
    }

    DropShadow {
        id: dropShadowBtn
        anchors.fill: rect_Btn
        color: "#01A2C3"
        source: rect_Btn
        radius: (0.004) * (item_ScorecardScreen1.width + item_ScorecardScreen1.height ) //8
    }

    Rectangle {
        id: rect_Btn
        width: (0.1954) * item_ScorecardScreen1.width //250
        height: (0.0857) * item_ScorecardScreen1.height //60
        color: "#ffffff"
        radius: (0.005) * (item_ScorecardScreen1.width + item_ScorecardScreen1.height ) //10
        border.color: "#01a2c3"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: (0.1) * item_ScorecardScreen1.height //70
        anchors.horizontalCenter: parent.horizontalCenter
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#01A2C3" }
            GradientStop { position: 0.65; color: "#06293C" }
            GradientStop { position: 1.0; color: "#071627" }
        }

        Text {
            id: txt_StartRound
            color: "#01a2c3"
            text: qsTr("Start Round")
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: img_Golfer.right
            font.pixelSize: (0.0121) * (item_ScorecardScreen1.width + item_ScorecardScreen1.height ) //24
            anchors.leftMargin: (0.01) * item_ScorecardScreen1.width //12
        }

        Image {
            id: img_Golfer
            width: (0.01875) * item_ScorecardScreen1.width //24
            height: (0.0342) * item_ScorecardScreen1.height //24
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            source: "qrc:/Scorecard/assets/img_Golfer.png"
            anchors.leftMargin: (0.03) * item_ScorecardScreen1.width //38
            fillMode: Image.PreserveAspectFit
        }

        MouseArea {
            id: ma_StartRoundBtn
            anchors.fill: parent
            onClicked: {
//                playersAdded = true
                mainLoader.source = "qrc:/Scorecard/qml/ScoreInput.qml"
            }
        }
    }
    PlayerDetailsInput {
        id: popupAddPlayer
        visible: false
        anchors.centerIn: parent
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.25}D{i:1}D{i:2}D{i:5}D{i:19}D{i:20}D{i:21}
}
##^##*/
