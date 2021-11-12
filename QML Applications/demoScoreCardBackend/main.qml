import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
//import Score 1.0
//import Player 1.0

Window {
    width: 1280
    height: 700
    visible: true
    title: qsTr("Hello World")

    property int index1
    Loader {
        id: mainLoader
        anchors.fill: parent
        source: "qrc:/Scorecard/qml/AddPlayer.qml"
    }

//    Score {
//        id: scoreInput
//    }

//    Player {
//        id: player
//    }
//    Row {
//        anchors.fill: parent
//        Repeater {
//            id: rep
//            model: scoreInput.playerList

//            Column {
//                width: parent.width / 4
//                height: parent.height

//                property int p_index: index
//                Repeater {
//                    model: modelData.score

//                    TextField {
//                        id: txt
//                        text: modelData
//                        onFocusChanged: {
//                            if(focus)
//                            {
//                            console.log("index....", p_index,"...", index)
//                            }


//                        }
//                        onEditingFinished: {
//                            scoreInput.playerList[p_index].score[index] = txt.text
//                        }


//                    }
//                }

//            }
//        }
//    }
}
