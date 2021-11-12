import QtQuick 2.12
import QtQuick.Controls 2.12


Item {
    id: item_ScorecardScreen2
    implicitWidth: 1280
    implicitHeight: 700

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
        width: (0.06875) * item_ScorecardScreen2.width //88
        height: (0.053) * item_ScorecardScreen2.height //37
        source: "qrc:/assets/VegoLogo.png"
        anchors.topMargin: (0.0458) * item_ScorecardScreen2.height //32
        anchors.leftMargin: (0.03125) * item_ScorecardScreen2.width //40
        anchors.top: parent.top
        anchors.left: parent.left
        fillMode: Image.PreserveAspectFit
    }
    Image {
        id: imgVerolt
        width: (0.046875) * item_ScorecardScreen2.width //60
        height: width
        source: "qrc:/assets/VeroltLogo.png"
        anchors.rightMargin: (0.03125) * item_ScorecardScreen2.width //40
        anchors.topMargin: (0.0286) * item_ScorecardScreen2.height //20
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
        anchors.topMargin: (0.143) * item_ScorecardScreen2.height //100
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        fillMode: Image.Stretch
    }

    Text {
        id: txt_Header
        color: "#ffffff"
        text: qsTr("Online Scorecard")
        anchors.bottom: img_HorizontalSeparator.top
        font.pixelSize: (0.0161) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //32
        anchors.bottomMargin: (0.0143) * item_ScorecardScreen2.height //10
        anchors.horizontalCenter: parent.horizontalCenter
        font.weight: Font.Bold
        font.family: "Roboto"
    }

    Text {
        id: text7
        color: "#f2f2f2"
        text: new Date().toLocaleDateString(Qt.locale(), "ddd, dd MMM")
        anchors.verticalCenter: rect_ScorecardView.verticalCenter
        anchors.left: parent.left
        font.pixelSize: (0.0101) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //20
        anchors.leftMargin: (0.03125) * item_ScorecardScreen2.width //40
        font.family: "Roboto"
    }

    Rectangle {
        id: rect_Finish
        width: (0.07813) * item_ScorecardScreen2.width //100
        height: (0.0571) * item_ScorecardScreen2.height //40
        color: "#00000000"
        radius: (0.003) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //6
        border.color: "#afa8a8"
        anchors.right: parent.right
        anchors.top: img_HorizontalSeparator.bottom
        anchors.rightMargin: (0.03125) * item_ScorecardScreen2.width //40
        anchors.topMargin: (0.02857) * item_ScorecardScreen2.height //20

        Text {
            id: txt_Finish
            color: "#afa8a8"
            text: qsTr("Finish")
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: (0.007) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //14
            anchors.horizontalCenter: parent.horizontalCenter
            font.weight: Font.Medium
        }

        MouseArea{
            id:ma_Finish
            anchors.fill: parent
            onClicked: {
                //onclick save score send to customer
            }
        }
    }

    Rectangle {
        id: rect_ScorecardView
        width: (0.1094) * item_ScorecardScreen2.width //140
        height: (0.0571) * item_ScorecardScreen2.height //40
        color: "#00000000"
        radius: (0.003) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //6
        border.color: "#01a2c3"
        anchors.right: rect_Finish.left
        anchors.top: img_HorizontalSeparator.bottom
        anchors.rightMargin: (0.02344) * item_ScorecardScreen2.width //30
        anchors.topMargin: (0.02857) * item_ScorecardScreen2.height //20

        Text {
            id: text8
            color: "#f2f2f2"
            text: qsTr("View Scorecard")
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: (0.007) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //14
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.weight: Font.Medium
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Roboto"
        }
        MouseArea{
            id:ma_scorecardView
            anchors.fill: parent
            onClicked: {
                //onclick goes to fullscorecard Page
                mainLoader.source = "qrc:/Scorecard/qml/FinalScoreView.qml"
            }
        }
    }

    Row{
        id:row_headings
        width: (0.9375) * item_ScorecardScreen2.width //1200
        height: (0.103) * item_ScorecardScreen2.height //72
        anchors.top: parent.top
        anchors.topMargin: (0.26) * item_ScorecardScreen2.height //182
        anchors.horizontalCenter: parent.horizontalCenter

        Rectangle{
            id:rect_Hole
            width: (0.15625) * item_ScorecardScreen2.width //200
            height: (0.103) * item_ScorecardScreen2.height //72
            color: "#071627"
            border.color: "#C5C5C5"

            Text {
                id: txt_Hole
                color: "#F2F2F2"
                text: "Hole"
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //24
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "Roboto"
                font.weight: Font.Medium
            }
        }
        Rectangle{
            id:rect_Par
            width: (0.15625) * item_ScorecardScreen2.width //200
            height: (0.103) * item_ScorecardScreen2.height //72
            color: "#FF560A"
            border.color: "#C5C5C5"

            Text {
                id: txt_Par
                color: "#F2F2F2"
                text: "Par"
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //24
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "Roboto"
                font.weight: Font.Medium
            }
        }
        Rectangle{
            id:rect_Player1
            width: (0.15625) * item_ScorecardScreen2.width //200
            height: (0.103) * item_ScorecardScreen2.height //72
            color: "#F2F2F2"
            border.color: "#C5C5C5"

            Text {
                id: txt_Player1
                color: "#2A2A2A"
                text: "Player1"
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //24
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "Roboto"
                font.weight: Font.Medium
            }
        }
        Rectangle{
            id:rect_Player2
            width: (0.15625) * item_ScorecardScreen2.width //200
            height: (0.103) * item_ScorecardScreen2.height //72
            color: "#D4D4D4"
            border.color: "#C5C5C5"

            Text {
                id: txt_Player2
                color: "#2A2A2A"
                text: "Player2"
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //24
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "Roboto"
                font.weight: Font.Medium
            }
        }
        Rectangle{
            id:rect_Player3
            width: (0.15625) * item_ScorecardScreen2.width //200
            height: (0.103) * item_ScorecardScreen2.height //72
            color: "#F2F2F2"
            border.color: "#C5C5C5"

            Text {
                id: txt_Player3
                color: "#2A2A2A"
                text: "Player3"
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //24
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "Roboto"
                font.weight: Font.Medium
            }
        }
        Rectangle{
            id:rect_Player4
            width: (0.15625) * item_ScorecardScreen2.width //200
            height: (0.103) * item_ScorecardScreen2.height //72
            color: "#D4D4D4"
            border.color: "#C5C5C5"

            Text {
                id: txt_Player4
                color: "#2A2A2A"
                text: "Player4"
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //24
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "Roboto"
                font.weight: Font.Medium
            }
        }
    }

    Flickable{
        id:flickable
        width: (0.9375) * item_ScorecardScreen2.width //1200
        anchors.top: row_headings.bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.topMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter
        interactive: true
        boundsBehavior: Flickable.StopAtBounds
        contentHeight: parent.height * 2
        contentWidth: (0.9375) * item_ScorecardScreen2.width //
        clip: true
        Row {
            id: row
            width: (0.9375) * item_ScorecardScreen2.width //1200
            height: (0.618) * item_ScorecardScreen2.height //432
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 0

            Column {
                id: column1
                width: (0.15625) * item_ScorecardScreen2.width //200
                height: (0.618) * item_ScorecardScreen2.height //432

                Repeater{
                    id:repeater_1
                    //                    model: scorecard.hole
                    model: scoreInput.hole

                    Rectangle{
                        id:rect_Col1
                        width: (0.15625) * item_ScorecardScreen2.width //200
                        height: (0.103) * item_ScorecardScreen2.height //72
                        color: "#071627"
                        border.color: "#C5C5C5"

                        Text {
                            id: text1
                            color: "#F2F2F2"
                            text: index == 18 ? "Total" : modelData
                            anchors.verticalCenter: parent.verticalCenter
                            font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //24
                            horizontalAlignment: Text.AlignHCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            font.family: "Roboto"
                            font.weight: Font.Medium
                        }
                    }
                }
            }
            Column {
                id: column2
                width: (0.15625) * item_ScorecardScreen2.width //200
                height: (0.618) * item_ScorecardScreen2.height //432

                Repeater{
                    id:repeater_2
                    //                    model: scorecard.par
                    model: scoreInput.par

                    Rectangle{
                        id:rect_Col2
                        width: (0.15625) * item_ScorecardScreen2.width //200
                        height: (0.103) * item_ScorecardScreen2.height //72
                        color: "#FF560A"
                        border.color: "#C5C5C5"

                        Text {
                            id: text2
                            color: "#F2F2F2"
                            text: modelData
                            anchors.verticalCenter: parent.verticalCenter
                            font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //24
                            horizontalAlignment: Text.AlignHCenter
                            anchors.horizontalCenter: parent.horizontalCenter
                            font.family: "Roboto"
                            font.weight: Font.Medium
                        }
                    }
                }
            }
            Row{
                width: 4 * (0.15625) * item_ScorecardScreen2.width //200
                height: (0.618) * item_ScorecardScreen2.height //432
                Repeater{
                    id:repeater_Player
                    model: scoreInput.playerList

//                    model: 1
                    Component.onCompleted: {
                        console.log(repeater_Player.model)
                    }

                    Column {
                        id: column3
                        width: (0.15625) * item_ScorecardScreen2.width //200
                        height: (0.618) * item_ScorecardScreen2.height //432
                        property int p_index: index

                        Repeater{
                            id:repeater_3
                            model: modelData.score

                            Rectangle{
                                id:rect_Col3
                                width: (0.15625) * item_ScorecardScreen2.width //200
                                height: (0.103) * item_ScorecardScreen2.height //72
                                color: "#F2F2F2"
                                border.color: "#C5C5C5"
                                //                        MouseArea{
                                //                            id:ma_3
                                //                            anchors.fill: parent
                                //                            onClicked: {
                                //                                parent.focus = true
                                //                            }
                                //                        }
                                TextField {
                                    id: text3
                                    color: "#2A2A2A"
                                    //                            text: scorecard.player1Score[index]
                                    text: modelData
                                    placeholderText: "-"
                                    anchors.fill: parent
                                    font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height )
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter //24
                                    font.family: "Roboto"
                                    font.weight: Font.Medium
                                    maximumLength: index == 18 ? 2 : 1
                                    readOnly: index == 18 ? true : false
                                    selectByMouse : readOnly
                                    validator: IntValidator {
                                        bottom:0
                                        top: 9
                                    }

                                    onTextChanged: {
                                        scoreInput.playerList[p_index].score[index] = text3.text
                                        scorecard.addScore(p_index, index, text3.text)
                                        console.log("Score Added")
                                    }
                                    inputMethodHints: Qt.ImhFormattedNumbersOnly
                                    background: Rectangle {
                                        anchors.fill: parent
                                        color: "#F2F2F2"
                                        border.color: "#C5C5C5"
                                    }
                                }
                            }
                        }
                    }
                }
            }

            //            Column {
            //                id: column3
            //                width: (0.15625) * item_ScorecardScreen2.width //200
            //                height: (0.618) * item_ScorecardScreen2.height //432

            //                Repeater{
            //                    id:repeater_3
            //                    model: 19

            //                    Rectangle{
            //                        id:rect_Col3
            //                        width: (0.15625) * item_ScorecardScreen2.width //200
            //                        height: (0.103) * item_ScorecardScreen2.height //72
            //                        color: "#F2F2F2"
            //                        border.color: "#C5C5C5"
            ////                        MouseArea{
            ////                            id:ma_3
            ////                            anchors.fill: parent
            ////                            onClicked: {
            ////                                parent.focus = true
            ////                            }
            ////                        }
            //                        TextField {
            //                            id: text3
            //                            color: "#2A2A2A"
            ////                            text: scorecard.player1Score[index]
            //                            text: scoreInput.player[0].score[index]
            //                            placeholderText: "-"
            //                            anchors.fill: parent
            //                            font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height )
            //                            horizontalAlignment: Text.AlignHCenter
            //                            verticalAlignment: Text.AlignVCenter //24
            //                            font.family: "Roboto"
            //                            font.weight: Font.Medium
            //                            maximumLength: 1
            //                            readOnly: index == 18 ? true : false
            //                            selectByMouse : readOnly
            //                            validator: IntValidator {
            //                                bottom:0
            //                                top: 9
            //                            }
            //                            onEditingFinished: {
            ////                                scorecard.player1Score[index] = text3.text
            //                                scoreInput.player[0].score[index] = text3.text
            //                            }
            //                            inputMethodHints: Qt.ImhFormattedNumbersOnly
            //                            background: Rectangle {
            //                                anchors.fill: parent
            //                                color: "#F2F2F2"
            //                                border.color: "#C5C5C5"
            //                            }
            //                        }
            //                    }
            //                }
            //            }
            //            Column {
            //                id: column4
            //                width: (0.15625) * item_ScorecardScreen2.width //200
            //                height: (0.618) * item_ScorecardScreen2.height //432

            //                Repeater{
            //                    id:repeater_4
            //                    model: 19

            //                    Rectangle{
            //                        id:rect_Col4
            //                        width: (0.15625) * item_ScorecardScreen2.width //200
            //                        height: (0.103) * item_ScorecardScreen2.height //72
            //                        color: "#D4D4D4"
            //                        border.color: "#C5C5C5"
            //                        focus: index == 18 ? false : true
            ////                        MouseArea{
            ////                            id:ma_4
            ////                            anchors.fill: parent
            ////                            onClicked: {
            ////                                parent.focus = true
            ////                            }
            ////                        }
            //                        TextField {
            //                            id: text4
            //                            color: "#2A2A2A"
            //                            text: scorecard.player2Score[index]
            //                            placeholderText: "-"
            //                            anchors.fill: parent
            //                            font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //24
            //                            horizontalAlignment: Text.AlignHCenter
            //                            verticalAlignment: Text.AlignVCenter
            //                            font.family: "Roboto"
            //                            font.weight: Font.Medium
            //                            maximumLength: 1
            //                            readOnly: index == 18 ? true : false
            //                            selectByMouse : readOnly
            //                            validator: IntValidator {
            //                                bottom:0
            //                                top: 9
            //                            }
            //                            onEditingFinished: {
            //                                scorecard.player2Score[index] = text4.text
            //                            }
            //                            inputMethodHints: Qt.ImhFormattedNumbersOnly
            //                            background: Rectangle {
            //                                anchors.fill: parent
            //                                color: "#D4D4D4"
            //                                border.color: "#C5C5C5"
            //                            }
            //                        }
            //                    }
            //                }
            //            }
            //            Column {
            //                id: column5
            //                width: (0.15625) * item_ScorecardScreen2.width //200
            //                height: (0.618) * item_ScorecardScreen2.height //432

            //                Repeater{
            //                    id:repeater_5
            //                    model: 19

            //                    Rectangle{
            //                        id:rect_Col5
            //                        width: (0.15625) * item_ScorecardScreen2.width //200
            //                        height: (0.103) * item_ScorecardScreen2.height //72
            //                        color: "#F2F2F2"
            //                        border.color: "#C5C5C5"
            //                        focus: index == 18 ? false : true
            ////                        MouseArea{
            ////                            id:ma_5
            ////                            anchors.fill: parent
            ////                            onClicked: {
            ////                                parent.focus = true
            ////                            }
            ////                        }
            //                        TextField {
            //                            id: text5
            //                            color: "#2A2A2A"
            //                            text: scorecard.player3Score[index]
            //                            placeholderText: "-"
            //                            anchors.fill: parent
            //                            font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //24
            //                            horizontalAlignment: Text.AlignHCenter
            //                            verticalAlignment: Text.AlignVCenter
            //                            font.family: "Roboto"
            //                            font.weight: Font.Medium
            //                            maximumLength: 1
            //                            readOnly: index == 18 ? true : false
            //                            selectByMouse : readOnly
            //                            validator: IntValidator {
            //                                bottom:0
            //                                top: 9
            //                            }
            //                            onEditingFinished: {
            //                                scorecard.player3Score[index] = text5.text
            //                            }
            //                            inputMethodHints: Qt.ImhFormattedNumbersOnly
            //                            background: Rectangle {
            //                                anchors.fill: parent
            //                                color: "#F2F2F2"
            //                                border.color: "#C5C5C5"
            //                            }
            //                        }
            //                    }
            //                }
            //            }
            //            Column {
            //                id: column6
            //                width: (0.15625) * item_ScorecardScreen2.width //200
            //                height: (0.618) * item_ScorecardScreen2.height //432

            //                Repeater{
            //                    id:repeater_6
            //                    model: 19

            //                    Rectangle{
            //                        id:rect_Col6
            //                        width: (0.15625) * item_ScorecardScreen2.width //200
            //                        height: (0.103) * item_ScorecardScreen2.height //72
            //                        color: "#D4D4D4"
            //                        border.color: "#C5C5C5"
            //                        focus: index == 18 ? false : true
            ////                        MouseArea{
            ////                            id:ma_6
            ////                            anchors.fill: parent
            ////                            onClicked: {
            ////                                parent.focus = true
            ////                            }
            ////                        }
            //                        TextField {
            //                            id: text6
            //                            color: "#2A2A2A"
            //                            text: scorecard.player4Score[index]
            //                            placeholderText: "-"
            //                            anchors.fill: parent
            //                            font.pixelSize: (0.0121) * (item_ScorecardScreen2.width + item_ScorecardScreen2.height ) //24
            //                            horizontalAlignment: Text.AlignHCenter
            //                            verticalAlignment: Text.AlignVCenter
            //                            font.family: "Roboto"
            //                            font.weight: Font.Medium
            //                            readOnly: index == 18 ? true : false
            //                            selectByMouse : readOnly
            //                            maximumLength: 1
            //                            validator: IntValidator {
            //                                bottom:0
            //                                top: 9
            //                            }
            //                            onEditingFinished: {
            //                                scorecard.player4Score[index] = text6.text
            //                            }
            //                            inputMethodHints: Qt.ImhFormattedNumbersOnly
            //                            background: Rectangle {
            //                                anchors.fill: parent
            //                                color: "#D4D4D4"
            //                                border.color: "#C5C5C5"
            //                            }
            //                        }
            //                    }
            //                }
            //            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.33}
}
##^##*/
