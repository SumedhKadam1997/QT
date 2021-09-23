import QtQuick 2.15
import QtQuick.Controls 2.5

Item {
    id: item1
    width: 393
    height: 851

    Text {
        id: txtVerify
        text: qsTr("Verify Your Account")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 140
        font.pixelSize: 24
        font.weight: Font.Medium
    }
    Text {
        id: txtEnterOtp
        text: qsTr("Please Enter OTP")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: txtVerify.bottom
        anchors.topMargin: 40
        font.pixelSize: 16
        font.weight: Font.Normal
        color: "#858585"
    }
    Text {
        id: txtOtp
        text: qsTr("OTP")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: txtEnterOtp.bottom
        anchors.topMargin: 50
        font.pixelSize: 16
        font.weight: Font.Normal
        color: "#858585"
    }
    TextInput {
        id: txtOtpInput
        width: 244
        height: 20
        anchors.bottom: colDash.top
        anchors.bottomMargin: 2
        font.letterSpacing: 30.3
        font.pixelSize: 16
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        cursorVisible: true
        maximumLength: 6
        anchors.horizontalCenterOffset: 17
        anchors.horizontalCenter: parent.horizontalCenter
        font.weight: Font.Medium
        echoMode: TextInput.Password
        validator: IntValidator {
            bottom: 0
            top: 999999
        }
    }

    Row {
        id: colDash
        width: 220
        height: 2
        anchors.top: txtOtp.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 45
        spacing: 20

        Repeater {
            model: 6

            Rectangle {
                width: 20
                height: 2
                color: "#858585"
            }
        }
    }
    Text {
        id: txtResendOtp
        text: qsTr("Resend OTP?")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: colDash.bottom
        anchors.topMargin: 210
        font.pixelSize: 16
        font.weight: Font.Normal
        color: "#858585"
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
