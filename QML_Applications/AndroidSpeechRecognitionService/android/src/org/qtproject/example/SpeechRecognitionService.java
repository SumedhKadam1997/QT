// Copyright 2019 Alpha Cephei Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

package org.qtproject.example;

import android.Manifest;
import android.app.Activity;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.widget.Button;
import android.widget.TextView;
import android.widget.ToggleButton;
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

import java.io.IOException;
import java.io.InputStream;
import java.io.*;

import androidx.annotation.NonNull;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

public class SpeechRecognitionService extends Service implements RecognitionListener {

//    static private final int STATE_START = 0;
//    static private final int STATE_READY = 1;
//    static private final int STATE_DONE = 2;
//    static private final int STATE_FILE = 3;
//    static private final int STATE_MIC = 4;

    /* Used to handle permission request */
//    private static final int PERMISSIONS_REQUEST_RECORD_AUDIO = 1;
    private static native void sendToQt(String message);
    private static final String TAG = "DebugTag";

    private Model model;
    private SpeechService speechService;
    private SpeechStreamService speechStreamService;
//    private TextView resultView;


    @Override
    public void onCreate() {
        super.onCreate();
        Log.i(TAG, "Creating Service");
//        setContentView(R.layout.main);

        // Setup layout
//        resultView = findViewById(R.id.result_text);
//        setUiState(STATE_START);

//        findViewById(R.id.recognize_file).setOnClickListener(view -> recognizeFile());
//        findViewById(R.id.recognize_mic).setOnClickListener(view -> recognizeMicrophone());
//        ((ToggleButton) findViewById(R.id.pause)).setOnCheckedChangeListener((view, isChecked) -> pause(isChecked));

        LibVosk.setLogLevel(LogLevel.INFO);

        // Check if user has given permission to record audio, init the model after permission is granted
//        int permissionCheck = ContextCompat.checkSelfPermission(getApplicationContext(), Manifest.permission.RECORD_AUDIO);
//        if (permissionCheck != PackageManager.PERMISSION_GRANTED) {
//            Log.i(TAG, "sfsfsf");
//            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.RECORD_AUDIO}, PERMISSIONS_REQUEST_RECORD_AUDIO);
//        } else {
        initModel();
        Log.i(TAG, "Model Initialization Complete");
//        recognizeMicrophone();
        Log.i(TAG, "Model Initialization Complete");
//        }
    }

     private void initModel() {
         Log.i(TAG, "Model Initialization Started");
         StorageService.unpack(this, "model-en-in", "model",
                 (model) -> {
                     this.model = model;
                     recognizeMicrophone();
                 }, (exception) -> Log.i("sumedh", "Model failed to load"));
         Log.i(TAG, "Model Initialization Complete");
     }


//    @Override
//    public void onRequestPermissionsResult(int requestCode,
//                                           @NonNull String[] permissions, @NonNull int[] grantResults) {
//        super.onRequestPermissionsResult(requestCode, permissions, grantResults);

//        if (requestCode == PERMISSIONS_REQUEST_RECORD_AUDIO) {
//            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
//                // Recognizer initialization is a time-consuming and it involves IO,
//                // so we execute it in async task
//                initModel();
//            } else {
//                finish();
//            }
//        }
//    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        Log.i(TAG, "Destroying Service");
        if (speechService != null) {
            speechService.stop();
            speechService.shutdown();
        }

        if (speechStreamService != null) {
            speechStreamService.stop();
        }
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        int ret = super.onStartCommand(intent, flags, startId);
        String name = new String(intent.getByteArrayExtra("name"));
        Log.i(TAG, "Service received name: " + name);
        String message = "Hello " + name;
        sendToQt(message);
        Log.i(TAG, "Service sent back message: " + message);
        return ret;
    }

     @Override
     public void onResult(String hypothesis) {

//         resultView.append(hypothesis + "\n");
        sendToQt(hypothesis);
     }

     @Override
     public void onFinalResult(String hypothesis) {
//         resultView.append(hypothesis + "\n");
//         setUiState(STATE_DONE);
//         if (speechStreamService != null) {
//             speechStreamService = null;
//         }
     }

     @Override
     public void onPartialResult(String hypothesis) {
//         resultView.append(hypothesis + "\n");
     }

     @Override
     public void onError(Exception e) {
//         setErrorState(e.getMessage());
     }

     @Override
     public void onTimeout() {
//         setUiState(STATE_DONE);
     }

//     private void setUiState(int state) {
//         switch (state) {
//             case STATE_START:
//                 resultView.setText(R.string.preparing);
//                 resultView.setMovementMethod(new ScrollingMovementMethod());
//                 findViewById(R.id.recognize_file).setEnabled(false);
//                 findViewById(R.id.recognize_mic).setEnabled(false);
//                 findViewById(R.id.pause).setEnabled((false));
//                 break;
//             case STATE_READY:
//                 resultView.setText(R.string.ready);
//                 ((Button) findViewById(R.id.recognize_mic)).setText(R.string.recognize_microphone);
//                 findViewById(R.id.recognize_file).setEnabled(true);
//                 findViewById(R.id.recognize_mic).setEnabled(true);
//                 findViewById(R.id.pause).setEnabled((false));
//                 break;
//             case STATE_DONE:
//                 ((Button) findViewById(R.id.recognize_file)).setText(R.string.recognize_file);
//                 ((Button) findViewById(R.id.recognize_mic)).setText(R.string.recognize_microphone);
//                 findViewById(R.id.recognize_file).setEnabled(true);
//                 findViewById(R.id.recognize_mic).setEnabled(true);
//                 findViewById(R.id.pause).setEnabled((false));
//                 break;
//             case STATE_FILE:
//                 ((Button) findViewById(R.id.recognize_file)).setText(R.string.stop_file);
//                 resultView.setText(getString(R.string.starting));
//                 findViewById(R.id.recognize_mic).setEnabled(false);
//                 findViewById(R.id.recognize_file).setEnabled(true);
//                 findViewById(R.id.pause).setEnabled((false));
//                 break;
//             case STATE_MIC:
//                 ((Button) findViewById(R.id.recognize_mic)).setText(R.string.stop_microphone);
//                 resultView.setText(getString(R.string.say_something));
//                 findViewById(R.id.recognize_file).setEnabled(false);
//                 findViewById(R.id.recognize_mic).setEnabled(true);
//                 findViewById(R.id.pause).setEnabled((true));
//                 break;
//             default:
//                 throw new IllegalStateException("Unexpected value: " + state);
//         }
//     }

//     private void setErrorState(String message) {
//         resultView.setText(message);
//         ((Button) findViewById(R.id.recognize_mic)).setText(R.string.recognize_microphone);
//         findViewById(R.id.recognize_file).setEnabled(false);
//         findViewById(R.id.recognize_mic).setEnabled(false);
//     }

//     private void recognizeFile() {
//         if (speechStreamService != null) {
//             setUiState(STATE_DONE);
//             speechStreamService.stop();
//             speechStreamService = null;
//         } else {
//             setUiState(STATE_FILE);
//             try {
//                 Recognizer rec = new Recognizer(model, 16000.f, "[\"one zero zero zero one\", " +
//                         "\"oh zero one two three four five six seven eight nine\", \"[unk]\"]");

//                 InputStream ais = getAssets().open(
//                         "10001-90210-01803.wav");
//                 if (ais.skip(44) != 44) throw new IOException("File too short");

//                 speechStreamService = new SpeechStreamService(rec, ais, 16000);
//                 speechStreamService.start(this);
//             } catch (IOException e) {
//                 setErrorState(e.getMessage());
//             }
//         }
//     }

     private void recognizeMicrophone() {
         if (speechService != null) {
//             setUiState(STATE_DONE);
             speechService.stop();
             speechService = null;
         } else {
//             setUiState(STATE_MIC);
             try {
                 Recognizer rec = new Recognizer(model, 16000.0f);
                 speechService = new SpeechService(rec, 16000.0f);
                 speechService.startListening(this);
             } catch (IOException e) {
//                 setErrorState(e.getMessage());
                 Log.i(TAG, e.getMessage());
             }
         }
     }

//     private void pause(boolean checked) {
//         if (speechService != null) {
//             speechService.setPause(checked);
//         }
//     }
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
}