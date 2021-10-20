class AndroidSOSFunctions {

    void sendEmergencySMS() {
        QAndroidJniObject message = QAndroidJniObject::fromString("Test Msg");
        QAndroidJniObject::callStaticMethod<void>(
            "org/verolt/hmi/NotificationClient",
            "notify",
            "(Landroid/content/Context;Ljava/lang/String;)V",
            QtAndroid::androidContext().object(),
            message.object<jstring>());
            }
}