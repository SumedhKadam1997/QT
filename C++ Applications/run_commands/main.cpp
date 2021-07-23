#include <iostream>
#include <QProcess>
#include <QDebug>

using namespace std;

int main()
{
    cout<<"\n * Program to demonstrate the usage of linux commands in qt * \n";

    QProcess process1;
//    QProcess process2;
    //    process1.setStandardOutputProcess(&process2);
    QString Command1;    //Contains the command to be executed
    //    QString Command2;
    QStringList args;   //Contains arguments of the command

    Command1 = "ipconfig";
    //    Command2 = "egrep inet6";
//    QByteArray buffer;
    //    args << "-l";
    process1.start("powershell", QStringList()<<"/c"<<"netsh wlan show networks SSID");
    //    process1.start("bash", QStringList() << "-c" << "/home/uxoriousghost/Desktop/sample.sh");
    //    process1.start("sh", QStringList() << "-c" << "/home/uxoriousghost/Desktop/sample.sh");
//    process1.start(Command1, args, QIODevice::ReadOnly); //Starts execution of command
    //    process2.start(Command2, args, QIODevice::ReadWrite);
    //    process2.setProcessChannelMode(QProcess::ForwardedChannels);
    process1.waitForFinished();                       //Waits for execution to complete
    //    process2.waitForFinished();

    QString StdOut      =   process1.readAllStandardOutput();  //Reads standard output
    QString StdError    =   process1.readAllStandardError();   //Reads standard error

    cout<<"\n Printing the standard output..........\n";
    cout<<endl<<StdOut.toStdString();
    cout<<"\n Printing the standard error..........\n";
    cout<<endl<<StdError.toStdString();

    cout<<"\n\n";
    //    bool retval = false;
    //    while ((retval = process2.waitForFinished()));
    //    buffer.append(process2.readAll());

    //    if (!retval) {
    //        qDebug() << "Process 2 error:" << process2.errorString();
    //        return 1;
    //    }

    //    qDebug() << "Buffer data" << buffer;
    return 0;
}
