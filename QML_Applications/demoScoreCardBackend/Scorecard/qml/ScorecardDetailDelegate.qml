import QtQuick 2.12

Item {
    id:item_Delegate
    implicitWidth: 2500
    implicitHeight: 40

    property color rectColor1: "#F5F5F5"
    property color rectColor2: "#071627"
    property color textColor1: "#2A2A2A"
    property color textColor2: "#F2F2F2"
    property alias model: repeater.model
    Row {
        id: row
        width: parent.width
        height: parent.height
        Repeater{
            id:repeater
            model : 24

            Rectangle{
                id:rect_row1
                width: index > 21 ? ((0.06) * item_Delegate.width) : ((0.04) * item_Delegate.width)
                height: item_Delegate.height
                border.color: "#C5C5C5"
                color: switch(index)
                       {
                       case 0 : rectColor1
                           break
                       case 1 : rectColor1
                           break
                       case 2 : rectColor1
                           break
                       case 3 : rectColor1
                           break
                       case 4 : rectColor1
                           break
                       case 5 : rectColor1
                           break
                       case 6 : rectColor1
                           break
                       case 7 : rectColor1
                           break
                       case 8 : rectColor1
                           break
                       case 9 : rectColor2
                           break
                       case 10 : rectColor1
                           break
                       case 11 : rectColor1
                           break
                       case 12 : rectColor1
                           break
                       case 13 : rectColor1
                           break
                       case 14 : rectColor1
                           break
                       case 15 : rectColor1
                           break
                       case 16 : rectColor1
                           break
                       case 17 : rectColor1
                           break
                       case 18 : rectColor1
                           break
                       case 19 : rectColor2
                           break
                       case 20 : rectColor2
                           break
                       case 21 : rectColor2
                           break
                       case 22 : rectColor1
                           break
                       case 23 : rectColor1
                       }
                Text {
                    id: txt_row1
                    text: modelData
                    font.pixelSize: (0.008) * (item_Delegate.width + item_Delegate.height) //20
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.weight: Font.Medium
                    font.family: "Roboto"
                    anchors.centerIn: parent
                    color: switch(index)
                           {
                           case 0 : textColor1
                               break
                           case 1 : textColor1
                               break
                           case 2 : textColor1
                               break
                           case 3 : textColor1
                               break
                           case 4 : textColor1
                               break
                           case 5 : textColor1
                               break
                           case 6 : textColor1
                               break
                           case 7 : textColor1
                               break
                           case 8 : textColor1
                               break
                           case 9 : textColor2
                               break
                           case 10 :
                           case 11 :
                           case 12 :
                           case 13 :
                           case 14 :
                           case 15 :
                           case 16 :
                           case 17 :
                           case 18 : textColor1
                               break
                           case 19 :
                           case 20 :
                           case 21 : textColor2
                               break
                           case 22 :
                           case 23 : textColor1
                           }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.25}
}
##^##*/
