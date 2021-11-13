import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 480
    height: 320
    property alias resultText: resultField.text
    property alias statusText: statusField.text
    property alias startStopButton: startStopButton
    property alias noGrammar: noGrammar
    property alias mainGrammar: mainGrammar
    property alias yesNoGrammar: yesNoGrammar
    property alias selectedGrammar: grammarGroup.current
    property alias audioLevel: audioLevelBar.value

    RowLayout {
        x: 49
        y: 47
        GroupBox {
            id: grammarGroupBox
            title: qsTr("Grammar")
            ColumnLayout {
                ExclusiveGroup {
                    id: grammarGroup
                }
                RadioButton {
                    id: noGrammar
                    text: qsTr("None")
                    exclusiveGroup: grammarGroup
                    checked: true
                }

                RadioButton {
                    id: mainGrammar
                    text: qsTr("Main")
                    exclusiveGroup: grammarGroup
                }

                RadioButton {
                    id: yesNoGrammar
                    text: qsTr("Yes/no")
                    exclusiveGroup: grammarGroup
                }
            }
        }

        RowLayout {}

        GridLayout {
            id: gridLayout1
            Layout.rowSpan: 1
            Layout.columnSpan: 1

            Button {
                id: startStopButton
                y: 0
                text: qsTr("Start/stop")
                Layout.columnSpan: 1
                Layout.rowSpan: 3
            }

            ProgressBar {
                id: audioLevelBar
                Layout.preferredWidth: 128
                Layout.minimumWidth: 0
                Layout.maximumWidth: 256
                Layout.fillWidth: false

                Label {
                    id: statusField
                    x: 0
                    y: -20
                    width: 200
                    height: 17
                    text: ""
                    Layout.fillWidth: true
                    Layout.preferredWidth: -1
                    Layout.alignment: Qt.AlignLeft
                }

                Text {
                    id: resultField
                    x: 0
                    y: 28
                    width: 200
                    text: ""
                    Layout.rowSpan: 1
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignLeft
                    wrapMode: Text.WordWrap
                }
            }
        }
    }
}
