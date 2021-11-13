import QtQuick 2.0

Item {
    id: item_ScorecardScreen3
    implicitWidth: 1280
    implicitHeight: 800

    MouseArea {
        id: ma_Dummy
        anchors.fill: parent
    }
    Component.onCompleted: {
        console.log("From ScoreView", scorecard.par)
    }

    Image {
        id: img_BG
        anchors.fill: parent
        source: "qrc:/assets/BG.png"
        fillMode: Image.Stretch
    }
    Image {
        id: imgVeGO
        width: (0.06875) * item_ScorecardScreen3.width //88
        height: (0.053) * item_ScorecardScreen3.height //37
        source: "qrc:/assets/VegoLogo.png"
        anchors.topMargin: (0.0458) * item_ScorecardScreen3.height //32
        anchors.leftMargin: (0.03125) * item_ScorecardScreen3.width //40
        anchors.top: parent.top
        anchors.left: parent.left
        fillMode: Image.PreserveAspectFit
    }
    Image {
        id: imgVerolt
        width: (0.046875) * item_ScorecardScreen3.width //60
        height: width
        source: "qrc:/assets/VeroltLogo.png"
        anchors.rightMargin: (0.03125) * item_ScorecardScreen3.width //40
        anchors.topMargin: (0.0286) * item_ScorecardScreen3.height //20
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
        anchors.topMargin: (0.143) * item_ScorecardScreen3.height //100
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        fillMode: Image.Stretch
    }

    Text {
        id: txt_Header
        color: "#ffffff"
        text: qsTr("Online Scorecard")
        anchors.bottom: img_HorizontalSeparator.top
        font.pixelSize: (0.0161) * (item_ScorecardScreen3.width + item_ScorecardScreen3.height ) //32
        anchors.bottomMargin: (0.0143) * item_ScorecardScreen3.height //10
        anchors.horizontalCenter: parent.horizontalCenter
        font.weight: Font.Bold
        font.family: "Roboto"
    }

    Rectangle {
        id: rectBackBtn
        width: item_ScorecardScreen3.width * 0.02
        height: width
        anchors.left: parent.left
        anchors.leftMargin: (0.03125) * item_ScorecardScreen3.width
        anchors.top: img_HorizontalSeparator.bottom
        anchors.topMargin: item_ScorecardScreen3.height * 0.0375
        color: "#00000000"
        Image {
            id: imgBackBtn
            source: "qrc:/Scorecard/assets/backBtn.png"
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }
        MouseArea {
            id: maBackBtn
            anchors.fill: parent

            onClicked: {
                mainLoader.source = "qrc:/Scorecard/qml/ScoreInput.qml"
            }
        }
    }

    Column {
        id: column
        width: (0.15625) * item_ScorecardScreen3.width //200
        height: (0.7) * item_ScorecardScreen3.height //560
        anchors.left: parent.left
        anchors.top: img_HorizontalSeparator.bottom
        anchors.topMargin: (0.10625) * item_ScorecardScreen3.height //85
        anchors.leftMargin: (0.03125) * item_ScorecardScreen3.width //40
        Repeater{
            id:repeater
            model: 14

            Rectangle{
                id:rect_col1
                width: (0.15625) * item_ScorecardScreen3.width //200
                height: (0.05) * item_ScorecardScreen3.height //40
                border.color: "#c5c5c5"
                color: switch(index)
                       {
                       case 0: "#F2F2F2"
                           break
                       case 1: "#2A2A2A"
                           break
                       case 2: "#2DA4D8"
                           break
                       case 3: "#F2F2F2"
                           break
                       case 4: "#F12929"
                           break
                       case 5: "#F2F2F2"
                           break
                       case 6: "#FF560A"
                           break
                       case 7: "#F2F2F2"
                           break
                       case 8: "#AFA8A8"
                           break
                       case 9: "#F2F2F2"
                           break
                       case 10: "#D4D4D4"
                           break
                       case 11: "#F2F2F2"
                           break
                       case 12: "#D4D4D4"
                           break
                       case 13: "#F2F2F2"
                           break
                       }

                Text {
                    id: txt_HeadersCol
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    font.pixelSize: (0.01) * (item_ScorecardScreen3.width + item_ScorecardScreen3.height ) //20
                    verticalAlignment: Text.AlignVCenter
                    anchors.leftMargin: (0.03125) * item_ScorecardScreen3.width //40
                    font.weight: Font.Medium
                    font.family: "Roboto"
                    text: switch(index)
                          {
                          case 0: "Hole"
                              break
                          case 1: "Black"
                              break
                          case 2: "Blue"
                              break
                          case 3: "White"
                              break
                          case 4: "Red"
                              break
                          case 5: "Stroke"
                              break
                          case 6: "Par"
                              break
                          case 7: "Hole Time"
                              break
                          case 8: "Score"
                              break
                          case 9: "Points"
                              break
                          case 10: scoreInput.playerList[0].name
                              break
                          case 11: scoreInput.playerList[1].name
                              break
                          case 12: scoreInput.playerList[2].name
                              break
                          case 13: scoreInput.playerList[3].name
                              break
                          }
                    color: switch(index)
                           {
                           case 0: "#2A2A2A"
                               break
                           case 1: "#F2F2F2"
                               break
                           case 2: "#F2F2F2"
                               break
                           case 3: "#2A2A2A"
                               break
                           case 4: "#F2F2F2"
                               break
                           case 5: "#2A2A2A"
                               break
                           case 6: "#F2F2F2"
                               break
                           case 7: "#2A2A2A"
                               break
                           case 8: "#2A2A2A"
                               break
                           case 9: "#2A2A2A"
                               break
                           case 10: "#2A2A2A"
                               break
                           case 11: "#2A2A2A"
                               break
                           case 12: "#2A2A2A"
                               break
                           case 13: "#2A2A2A"
                               break
                           }
                }
            }
        }
    }
    Flickable{
        id:flickable
        width: (0.8125) * item_ScorecardScreen3.width //1040
        height: (0.7) * item_ScorecardScreen3.height //560
        anchors.left: column.right
        anchors.top: column.top
        clip: true
        anchors.topMargin: 0
        anchors.leftMargin: 0
        flickableDirection: Flickable.HorizontalFlick
        interactive: true
        boundsBehavior: Flickable.StopAtBounds
        contentHeight: (0.7) * item_ScorecardScreen3.height //560
        contentWidth: (2) * item_ScorecardScreen3.width
        Column {
            id: column1
            anchors.fill: parent

            ScorecardDetailDelegate {
                id:row1
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                model: scorecard.hole
            }
            ScorecardDetailDelegate {
                id:row2
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                textColor1: "#f2f2f2"
                rectColor1: "#2a2a2a"
                model: scorecard.black
            }
            ScorecardDetailDelegate {
                id:row3
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                textColor1: "#f2f2f2"
                rectColor1: "#2da4d8"
                model: scorecard.blue
            }
            ScorecardDetailDelegate {
                id:row4
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                rectColor1: "#f2f2f2"
                model: scorecard.white
            }
            ScorecardDetailDelegate {
                id:row5
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                textColor1: "#f2f2f2"
                rectColor1: "#f12929"
                model: scorecard.red
            }
            ScorecardDetailDelegate {
                id:row6
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                model: scorecard.stroke
            }
            ScorecardDetailDelegate {
                id:row7
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                textColor1: "#f2f2f2"
                rectColor1: "#ff560a"
                model: scorecard.par
            }
            ScorecardDetailDelegate {
                id:row8
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                model: scorecard.holeTime
            }
            ScorecardDetailDelegate {
                id:row9
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                rectColor1: "#afa8a8"
                model: scorecard.score
            }
            ScorecardDetailDelegate {
                id:row10
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                model: scorecard.points
            }
            ScorecardDetailDelegate {
                id:row11
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                rectColor1: "#d4d4d4"
                model: scorecard.player1Score
            }
            ScorecardDetailDelegate {
                id:row12
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                model: scorecard.player2Score
            }
            ScorecardDetailDelegate {
                id:row13
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                rectColor1: "#d4d4d4"
                model: scorecard.player3Score
            }
            ScorecardDetailDelegate {
                id:row14
                width: (1.96) * item_ScorecardScreen3.width //2500
                height: (0.05) * item_ScorecardScreen3.height //40
                model: scorecard.player4Score
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.125}D{i:7}D{i:12}
}
##^##*/
