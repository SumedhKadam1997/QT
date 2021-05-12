import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Signals and Slots")

    /* Using the Connections Object
     * Establish a connection with the application core object
     * */
    Connections {
        target: myclass // Specify the target to connect
        /* Declare and implement the function as a parameter
         * object and with a name similar to the name of the signal
         * The difference is that we add on at the beginning and then write
         * capitalized
         * */
        function onSendToQml(count) {
            labelCount.text = count
        }

//        onSendToQml: {
//            labelCount.text = count // Set the counter to the text label
//        }
    }
    Label {
        id: labelCount
        text: "0"
        anchors.bottom: button.top
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }
    Button {
        id: button
        text: qsTr("Increase counter")
        anchors.verticalCenter: parent.verticalCenter
        onClicked: myclass.receiveFromQml() // calling c++ slot
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
