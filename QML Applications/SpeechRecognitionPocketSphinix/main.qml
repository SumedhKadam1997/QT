import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
//import QtSpeechRecognition 0.1

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

//    SpeechRecognition {
//        id: speech
//        property string resourceDir: homeDir + "/speechres"
//        property url dictionaryFile: "file:lexicon.dict"
//        property url mainGrammarFile: "qrc:grammar/main"
//        property url yesNoGrammarFile: "qrc:grammar/yesno"
//        property var engine: createEngine("local", "pocketsphinx",
//                                        { "Locale" : Qt.locale("en_US"),
//                                          "ResourceDirectory" : resourceDir,
//                                          //"DebugAudioDirectory" : "/tmp",
//                                          "Dictionary" : dictionaryFile })
//        property var mainGrammar: createGrammar(engine, "main", mainGrammarFile)
//        property var yesNoGrammar: createGrammar(engine, "yesno", yesNoGrammarFile)

//        Component.onCompleted: {
//            console.log("Available plugins: " + availablePlugins)
//        }

//        onResult: {
//            mainForm.resultText = grammarName + ": " + resultData["Transcription"]
//            mainForm.statusText = "Ready"
//        }
//        onError: {
//            var errorText = "Error " + errorCode
//            if (parameters["Reason"] !== undefined)  {
//                errorText += ": " + parameters["Reason"]
//            }
//            mainForm.resultText = ""
//            mainForm.statusText = errorText
//            console.log(errorText)
//        }
//        onListeningStarted: {
//            mainForm.statusText = "Listening..."
//        }
//        onListeningStopped: {
//            if (expectResult)
//                mainForm.statusText = "Hold on..."
//            else
//                mainForm.statusText = "Ready"
//        }
//        onAttributeUpdated: {
//            if (key == "AudioLevel")
//                mainForm.audioLevel = value
//        }
//        onStateChanged: {
//            console.log("State: " + speech.state)
//        }
//        onMessage: {
//            console.log("Message: " + message)
//        }
//    }

//    Connections {
//        target: speech.engine
//        onCreated: {
//            console.log("Engine " + speech.engine.name + " created")
//            var supportedParameters = speech.engine.supportedParameters()
//            console.log("Supported engine parameters: " + supportedParameters)
//            // Switch to "pulse" audio device if available
//            if (supportedParameters.indexOf("AudioInputDevices") !== -1) {
//                var inputDevices = speech.engine.parameter("AudioInputDevices")
//                if (inputDevices.indexOf("pulse") !== -1)
//                    speech.engine.setParameter("AudioInputDevice", "pulse")
//            }
//            // Example: recognize audio clip instead of live audio:
//            //if (supportedParameters.indexOf("AudioInputFile") !== -1) {
//            //    speech.engine.setParameter("AudioInputFile", homeDir + "/asr_input_1.wav")
//            //}
//        }
//    }
//    MainForm {
//        id: mainForm
//        anchors.fill: parent
//        onSelectedGrammarChanged: {
//            switch (selectedGrammar) {
//                case mainGrammar:
//                    speech.activeGrammar = speech.mainGrammar
//                    break;
//                case yesNoGrammar:
//                    speech.activeGrammar = speech.yesNoGrammar
//                    break;
//                default:
//                    speech.activeGrammar = null
//                    break;
//            }
//        }
//        startStopButton.onClicked: {
//            speech.dispatchMessage("Start/stop");
//            switch (speech.state) {
//                case SpeechRecognition.IdleState:
//                case SpeechRecognition.ProcessingState:
//                    //speech.muted = true
//                    speech.startListening()
//                    //speech.unmuteAfter(500);
//                    break;
//                default:
//                    speech.stopListening()
//                    break;
//            }
//            mainForm.resultText = ""
//        }
//    }
}
