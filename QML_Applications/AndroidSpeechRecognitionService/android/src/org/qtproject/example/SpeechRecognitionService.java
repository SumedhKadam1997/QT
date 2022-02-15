package org.qtproject.example;

import android.Manifest;
import android.app.Activity;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.util.Log;
import android.app.Service;
import android.os.IBinder;
import android.content.Context;
import android.content.Intent;

import org.vosk.LibVosk;
import org.vosk.LogLevel;
import org.vosk.Model;
import org.vosk.Recognizer;
import org.vosk.android.RecognitionListener;
import org.vosk.android.SpeechService;
import org.vosk.android.SpeechStreamService;
import org.vosk.android.StorageService;

import ai.picovoice.picovoice.*;
import ai.picovoice.rhino.*;

import java.io.IOException;
import java.io.InputStream;
import java.io.*;
import java.util.Map;

public class SpeechRecognitionService extends Service implements RecognitionListener {

    private static native void sendSpeechStringToQT(String message);
    private static native void sendWakeWordDetection(boolean isDetected);
    private static final String TAG = "DebugTag";
    private static final String VOSKTAG = "VOSKTAG";
    private static final String PICOTAG = "PICOTAG";
    private static final String ACCESS_KEY = "";

    private Model model;
    private SpeechService speechService;
    private SpeechStreamService speechStreamService;
    private PicovoiceManager picovoiceManager;

    @Override
    public void onCreate() {
        super.onCreate();
        LibVosk.setLogLevel(LogLevel.INFO);
        initModel();
        initPicovoice();
    }

    private void initModel() {
        StorageService.unpack(this, "vosk-model-small-en-in", "model",
                (model) -> {
                    this.model = model;
                    recognizeMicrophone();
                    pauseVoskService(true);
                }, (exception) -> Log.i(VOSKTAG, "Model failed to load"));
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        Log.i(TAG, "Destroying Service");
        if (speechService != null) {
            Log.i(VOSKTAG, "Destroying Service inside if statement");
            speechService.stop();
            speechService.shutdown();
        }
        speechService = null;
        if (speechStreamService != null) {
            speechStreamService.stop();
        }
        speechStreamService = null;
        try {
            picovoiceManager.stop();
        } catch (PicovoiceException e) {
            Log.e(PICOTAG, e.toString());
        }
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        int ret = super.onStartCommand(intent, flags, startId);
        String name = new String(intent.getByteArrayExtra("name"));
        Log.i(TAG, "Service received name: " + name);
        String message = "Hello " + name;
        sendSpeechStringToQT(message);
        Log.i(TAG, "Service sent back message: " + message);

        return ret;
    }

    private void initPicovoice() {
        String keywordPath = "picofiles/jarvis_android.ppn";
        String contextPath = "picofiles/golf_voice_assistant.rhn";
        try {
            picovoiceManager = new PicovoiceManager.Builder()
                      .setAccessKey(ACCESS_KEY)
                      .setKeywordPath(keywordPath)
                      .setContextPath(contextPath)
                      .setWakeWordCallback(wakeWordCallback)
                      .setInferenceCallback(inferenceCallback)
                      .setPorcupineSensitivity(0.7f)
                      .setRhinoSensitivity(0.5f)
                      .build(getApplicationContext());
            picovoiceManager.start();
        } catch (PicovoiceInvalidArgumentException e) {
            onPicoVoiceError(
                String.format(
                    "%s\nEnsure your AccessKey '%s' is a valid access key.",
                    e.getLocalizedMessage(),
                    ACCESS_KEY));
        } catch (PicovoiceActivationException e) {
            onPicoVoiceError("AccessKey activation error");
        } catch (PicovoiceActivationLimitException e) {
            onPicoVoiceError("AccessKey reached its device limit");
        } catch (PicovoiceActivationRefusedException e) {
            onPicoVoiceError("AccessKey refused");
        } catch (PicovoiceActivationThrottledException e) {
            onPicoVoiceError("AccessKey has been throttled");
        } catch (PicovoiceException e) {
            onPicoVoiceError("Failed to initialize Picovoice " + e.getMessage());
        }
    }

    private PicovoiceWakeWordCallback wakeWordCallback = new PicovoiceWakeWordCallback() {
        @Override
        public void invoke() {
        // keyword detected
            Log.i(PICOTAG, "Wake Word Detected");
            pauseVoskService(false);
            sendWakeWordDetection(true);
        }
    };

    private PicovoiceInferenceCallback inferenceCallback = new PicovoiceInferenceCallback() {
        @Override
        public void invoke(RhinoInference inference) {
            if (inference.getIsUnderstood()) {
                pauseVoskService(true);
                sendWakeWordDetection(false);
                Log.i(PICOTAG, "Inference Detected");
                String voiceIntent = inference.getIntent();
                Log.i(PICOTAG, voiceIntent);

                Map<String, String> slots = inference.getSlots();
//                Log.i(PICOTAG, slots.get("stop"));
                if (voiceIntent.equals("navigation")) {
                    Log.i(PICOTAG, slots.get("stop"));
                } else if (voiceIntent.equals("navigationStop")) {
                    Log.i(PICOTAG, "Navigation Stopped");
                }
            } else {
                // handle unsupported commands
                pauseVoskService(true);
                sendWakeWordDetection(false);
            }
        }
    };

    private void onPicoVoiceError(String message) {
        Log.i(PICOTAG, message);
    }

    @Override
    public void onResult(String hypothesis) {
        Log.i(VOSKTAG, hypothesis);
        sendSpeechStringToQT(hypothesis);
//        pauseVoskService(true);
//        porcupineManager.start();
    }

    @Override
    public void onFinalResult(String hypothesis) {
    }

    @Override
    public void onPartialResult(String hypothesis) {
        Log.i(VOSKTAG, hypothesis);
        sendSpeechStringToQT(hypothesis);
    }

    @Override
    public void onError(Exception e) {
        Log.i(VOSKTAG, "Error : " + e);
    }

    @Override
    public void onTimeout() {
        Log.i(VOSKTAG, "Time Out!!");
    }

    private void recognizeMicrophone() {
        Log.i(TAG, "Recognizing microphone");
        try {
            Recognizer rec = new Recognizer(model, 16000.0f);
            speechService = new SpeechService(rec, 16000.0f);
            speechService.startListening(this);
        } catch (IOException e) {
            Log.i(VOSKTAG, e.getMessage());
        }
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    private void pauseVoskService(boolean checked) {
            speechService.setPause(checked);
    }
}
