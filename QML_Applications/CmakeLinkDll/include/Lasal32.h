#ifndef __LASAL32_H__
#define __LASAL32_H__


// ++WCE CHANGED START
#define DLL_NAME       _T("LASAL32.DLL")   // DLL-Name
// ++WCE CHANGED END

#ifdef BUILD_LASAL32
	#include "BuildNumber.h"
#endif 

/////////////////////////////////////////////////////////////////////////
// Version braucht in der Version Resource nicht mehr angepasst werden, nur noch hier 2mal.
#define LASAL32_VERSION_MAJOR			1
#define LASAL32_VERSION_MINOR			1
#define LASAL32_VERSION_SUBVERSION		134
#define LASAL32_VERSION_TXT				"01.01.134"
// LASAL32_VERSION_TXT sollte mal automatisch generiert werden.

// Für zukünftigen Build Counter vom Build Rechner
#ifdef CC_BUILD_NUMBER
	#define LASAL32_VERSION_BUILD			CC_BUILD_NUMBER_NR
	#define LASAL32_VERSION_BUILD_TXT		CC_BUILD_NUMBER
#else
	#define LASAL32_VERSION_BUILD			0
	#define LASAL32_VERSION_BUILD_TXT		"dev"
#endif

// aktuelle DLL-Version
#define LASAL32_VERSION		((LASAL32_VERSION_MAJOR << 12) | (LASAL32_VERSION_MINOR << 8) | LASAL32_VERSION_SUBVERSION)

// Wegen Kompatibilität wird DLL_VERSION noch gebraucht.
#define DLL_VERSION			LASAL32_VERSION

//#define TESTVERSION
#undef TESTVERSION

//#################################################################################
// ACHTUNG:
//   neue Funktionen sollten mit Lsl.. beginnen.
//#################################################################################

///////////////////////////////////////////////////////////////////////////////////
// Versionsübersicht
///////////////////////////////////////////////////////////////////////////////////
//  01.01.134	- KoeDom: ~ DS 5367: MemInfoType angepasst
//  			- MalJoh: + CommandWithData : Erweiterung für ARBURG Drive Diagnose Tool.
//  01.01.133	- Schsas: New function LslSafeRmd
//  01.01.132	- Feshar: New function GetInfo
//  01.01.131	- Trnrob: Add NULL-Pointer to initilize pointer variable.
//				- Trnrob: Set of NODELAY for TCP in IPPROTO_TCP not in SOL_SOCKET (Switch only if needed).
//				- Krawol: Verbesserung für DS 5040
//  01.01.130	- Trnrob: Correction in the IsOnline routine of the RefreshList connection.
//				- Trnrob: Bigger Buffer for scope data transfer (temp disable Nagle-Algo). 
//              - AueAnd: Neue Funktion LslGetLastComunicationError hinzugefügt
//  01.01.129	- Schsas: Set environment variable for Read_Timeout (TCP_RD_TIMEOUT) back to seconds unit (milli seconds at version 1.1.128)
//  01.01.128	- Schsas: Environment variable for size of File_Handling packets
//		- Kucsvi: Fehler korrigiert : bIsFirstAttempt==true nur beim 
//			  erstem Aufruf von TcpConnect(), 
//			  alle weitere Aufrufe - mit bIsFirstAttempt==false
//  01.01.127	- Kucsvi: new function FileSetAttributes to use Filehandling with LSL_FILEINFOMASK_SETATTR
//		- LesMax: Bei TCPConnect wird der Eintrag für die Ziel - IP in der ARP Tabelle
//			  erst gelöscht wenn der erste Verbindungsversuch scheitert. Danach wird
//			  ein weiterer Versuch unternommen die Verbindung herzustellen.
//		- LesMax: Logging für TCP Verbindungsaufbau erweitert		  
// 01.01.126	- LesMax: Möglichkeit um TCPConnect() vor Erreichen des Timeouts abzubrechen
// 01.01.125	- BreGer: kopieren von Files mit Groesse 0Byte ermoeglichen
//		- Muhbar: Routing TCP or CAN: LslLoadOSImageNew_I and LslFileTransferToPLC use both
//			  new DBG_CMD_FILEHANDLING when aim CPU is a salamander OS.
// 01.01.124	- TrnRob: MemoryLeak in LslFileCopy und bei LslGetDataListSpecial(ohne TCP/IP) behoben.
//		- NeuKer: LSLOS_ERROR_WRITE_PROTECT bei Filehandling mit Salamander.
// 01.01.122	- Wu: 	  Fehlerbehandlung CANUSB: Handle wurde nicht geschlossen wenn die Verbindung abbricht.
// 01.01.122	- ObeJoh: Verwendet nicht die Filehandling Funktionen, wenn Routing aktiv ist.
// 01.01.122	- ObeJoh: Fix Online to very old PLC with old OS-Version (DCL641, V05.002) over V24 (RS232)
// 01.01.121	- Wu:	  Fehlerbehandlung im TCPBase.cpp verbessert
//						  Projekt Download Wait_load Funktion um CS_READY status erweitert
// 01.01.120	- TrnRob: Erweiterung Zugriff auf Module:
//						  LslHardwaretreeWriteMemoryH(int32_t ocbNum, UINT uiMaster, UINT uiAddress, UINT uiOffset, UINT uiLen, UINT *puiError, void *pBuffer)
//						  LslHardwaretreeReadMemoryH(int32_t ocbNum, UINT uiMaster, UINT uiAddress, UINT uiOffset, UINT uiLen, UINT *puiError, void *pBuffer)
//				- LesMax: TCPConnect() verwendet jetzt um den sehr hohen Timout der synchronen connect() 
//						  Funktion zu umgehen, anstelle des Ping Kommandos, die asynchrone connect()
//						  Funktion mit anschließendem Aufruf von select() unter Verwendung eines Timout. 
//						  Weiters setzt TCPIsOnline(), wenn die letzte gültige Kommunikation das
//						  maximale Alter überschritten hatt, anstelle des Ping Kommandos, jetzt ein
//						  TCPSendSyn() ab, um auf eine gültige Kommunikation zu prüfen.
//						  Dies ist nötig, da bei manchen Netzwerkkonfigurationen
//						  (WLAN, Firewall,...) der Ping von Windows/Treiber überhaupt nicht abgesetzt wird und
//						  somit nicht zur Prüfung der Erreichbarkeit der Gegenstelle verwendet werden kann.
//				- ObeJoh: LslPing enthält nun PID & Timeout als String
//				- Wu:	  Auf einer Route mit Passwort Onlineverbindung aufbauen
// 01.01.119	- ObeJoh: Größeres Timeout beim SetCommand, da bei der serielllen und USB-Device auf Salamander die CMDs ein bischen länger brauchen.
// 01.01.118	- Wu: 	  Struktur BpLst  rauskommentiert da es im code nicht mehr werdendet wird.(Zukünftig bereinigen.)
//						  LslGetBpListEx(uint8_t bpnum, uint8_t *Buf, uint32_t dwBufLen);
//						  LslGetBpListExH(int32_t ocbNum,uint8_t bpnum, uint8_t *Buf, uint32_t dwBufLen);
// 01.01.117	- KoeAnd: Anpassung LoadPrjEx_I Methode
// 01.01.116	- ObeJoh: Größeres Timeout beim Cmd:DBG_CMD_LOAD_PRJ_HEADER mit der seriellen Schnittstelle.
//				- Timeout für den TCP/IP Filetransfer über Repeater erhöht
// 01.01.115	- LesMax: Bei Onlineverbindung über TCP wird zu Optimierungszwecken für die cached 
//						  CPU Status Anfrage der CPU Status einer jeden erfolgreichen TCP Anfrage verwendet.
//				- LesMax: LoadModul2_I muss bei neuen OS Versionen nicht mehr über Polling auf die Fertigstellung 
//						  von DBG_CMD_LOAD_MOD_HEADER und DBG_CMD_LOAD_MOD_CODE warten. Kompatibel mit alten OS Versionen,
//						  da überprüft wird, ob das ausgeführte Kommando bereits den korrekten CPU Status zurückgeliefert hat,
//						  ist dies nicht der Fall,wird wie bisher auf den erwarteten CPU Status gepollt.
// 01.01.114	- fimluc: GetPLCInfo beim Online nur mehr loeschen, wenn PLCInfo nicht korrekt gelesen wurde
// 01.01.113	- fimluc: GetPLCInfo immer direkt auslesen und nicht aus dem Buffer
//				- obejoh: DBG32PID=1 in der Umgebungsvariable, erzeugt für jeden Prozess eine eigene Logdatei
//				- Wu:	  Der Connection String kann jetzt ein susätzlichen Parameter PLCID=******* durch Semikolon getrennt mitgegeben werden.
//						  Wird dieser Parameter verwendet verbindet sich die Lasal32.dll mit einem Repeater und überträgt die BRIDGEID als Identifikation für den PLC welches sich 
//						  auf dem Server angemeldet hat.
// 01.01.112	- LesMax: ExecNewInstrH: Fehler in der Befüllung des Requestbuffers behoben der ab v01.01.111 vorhanden war

// 01.01.111	- obejoh: LslLrsCommand_I kann nun auch die Länge zurückliefern
//				- fimluc: Unterstützung für LREAL (8byte) im Dataanalyzer

// 01.01.110	- Wu: VaranServicetool von der Passwort Prüfung ausschließen
// 01.01.109	- obejoh: Logdatei wird nun im TEMP Verzeichnis angelegt.
//				- obejoh: Funktionen LslFileTransferToPlcBuf und LslFileTransferFromPlcBuf hinzugefügt
//				- obejoh: LslFileTransfer liefert nun die richtigen Fehlernummer
//				- obejoh: Wiederherstellen des Fehlercode nach CBSTATE_ERROR aufruf.

//01.01.108		- Wu: ab os version 01.02.230 kann der Profiler längere Datenblöcke empfangen.
//				- obejoh: fix Linux timeout - error handling in RefreshList
//				- obejoh: fix LslDirectCommunication Send.
//				- Online_I: LslGetOnlPwd_I wird jetzt auch ausgeführt wenn das Passwort leer ist.
//				- Online_I: ERROR_SIGMA32_NO_PASSWORD_SET wenn am Target kein passwort gesetzt ist aber der Online_I befehl mit passwort aufgerufen wurde.

// 01.01.107    - Wu: TCP_PING_RPT Environment-Parameter hinzugefügt, Workaround für 
//				  nicht gesendete Ping Befehle in der Windows API

//				- obejoh: fix für neue GNU Compiler. _cdecl auf __cdecl geändert.

// 01.01.106	- Wu: Anpassung der Online_I methode damit man in der ATLOnline DLL 
//				- Ein Passwort mitgeben kann
//				- Anpassung der LslSetOnlPwd_I Methode. Wenn ein leeres passwort übergeben
//				- wird wird auf dem PCL das File "C:\LSLSYS\ONLPWD.DAT" gelöscht. Grund:
//				- Man kann zwar dass Passwort auf Leer setzten danach funktioniert jedoch 
//				- die Passwortüberprüfung im Betriebssystem nicht mehr.

// 01.01.105	- obejoh: Anpassung für Lasal32 unter Linux.
//				- Neue UnitTests für FileTransfer Funktionen
//				- CpRegs.h entfernt, wurde nun direkt in die Lasal32.h eingefügt.
//				- Typen auf stdard typen umgestellt. unsigned int (LSL_UINT32) auf uint32_t.

// 01.01.104	- Struktur LSL_FILE_INFO für Funktion FileInfo hinzugefügt.
//				- In der Funktion LslClearSram auch die RamEx Files löschen.
//				- enhanced speed testing
//				- FileLoad speed test, GetData speed test
//				- Fortschrittsbalken beim Download OS mittels CAN bzw serieller Schnittstelle wird nun aktualisiert

// 01.01.103	- Neue Funktion LslDownloadOS. Diese ersetzt die alte LslLoadOSImage.
//				- LslLoadOSImage funktioniert auch noch immer.

// 01.01.102	- Neue Funktion LslFileTransfer. (Kopiert direkt Dateien)
//				- Interne Überarbeitung Datenübergabe an die Request Funktionen.
//				- Fix: Download von großen Dateien (mit LslFileTransfer)
//				- Support für Salamander DownloadOS
//				- eigene LSL Datentype, damit man es besser unter Linux verwenden kann

// 01.01.101	- Neue Funktion "ServiceProviderResponse".
//				- Anpassungen für Linux. Damit man es mit verschiedenen Linux Compiler kompilieren kann
//

// 01.01.100	- Nur neu gelabelt.

// 01.01.099	- Version von Lasal32.h und Version.rc angepasst.

// 01.01.098 	- RefreshList Fehler: SESSIONINFO für Cmd-Kanal nicht gesendet. 
//				  Nun kann man per ApplID beliebig viele RefreshListen verwenden.

// 01.01.097	- Neuer Online Parameter TCP_NODELAY_OFF
//				- Unnötige Debugausgaben entfernt, einige Kommentare hinzugefügt.

// 01.01.096	- Neue Funktionen: OnlinePwdH, OnlinePwd
//              Damit kann im OS eine Passwortabfrage realisiert werden

// 01.01.095	- Online mit Kleinschreibung funktioniert nun wieder.
//				- Anpassungen, damit man es mit VS 6.0 kompilieren kann.

// 01.01.094	- Routing funktioniert nun wieder.

// 01.01.093	- LslDirect... Funktionen hinzugefügt
//					This function can communicate direct with a Application class. Send & Receive Data.
//					Receive can also be handle with a callback.
//				- Refactoring parsen des Online String.
//				- Bei LslOszi neue Kanaltypen zum Abfragen von dData (statt Read-Methode).
//				- Neue Funktion: LslSyssernumCommand zum Ermitteln der Seriennummer der CPU.

// 01.01.092	- OUT-Buffer bei LslVaranDiagnoseCounter erhöht

// 01.01.091	- In der Funktion LslReadFromSvrStr die Länge -1 im RESULT abfangen.

// 01.01.090	-	Fehlerbehebung bei den LOG-Makros: Im Makro war eine if-Abfrage enthalten, es fehlten aber die 
//              geschwungenen Klammern. Das konnte eine nicht beabsichtigte Programmausführung bewirken, wenn 
//              das Makro in einer if-else Anweisung im if-Block ohne geschwungene Klammern verwendet wird.
//              Dieser Fehler hat sich bei der Modemkommunikation so ausgewirkt, dass manchmal keine Verbindung 
//              hergestellt werden konnte (V24ModemOnline).
//            - Die Fehlerbehandlung beim Aufbau einer Modemverbindung wurde verbessert (V24ModemOnline)
//            - Diverse Änderungen, damit der Code wieder mit VC6 compiliert werden kann

// 01.01.089	-	Neue Funktionen: LslGetOnlPwd, LslSetOnlPwd

// 01.01.089	-	Neue Funktionen: LslVaran32AddFPRPacketFilter, LslVaran32RemoveFPRPacketFilter, LslVaran32SendRaw, LslVaran32SendRawUDP
//				-	Funktionen für FWUpdate umbenannt

// 01.01.088	-	Wird versucht Daten über eine USB Online Verbindung zu schreiben, und die Schnittstelle der Gegestelle
//							ist nicht initialisiert, wird die Funktion WriteFile nicht mehr beendet.
//							Um dies zu verhindern, wurde eine Schreib Timeout Zeit gesetzt.
//				-	Neue Funktionen: LslVaran32FWUpdateUDPInstallWriteCallback, LslVaran32FWUpdateUDPScan, LslVaran32FWUpdateUDPInfo, LslVaran32FWUpdateUDPWrite

// 01.01.087	- Bei LslClearSram auch Retentive Server File (RETSVR.DAT) löschen.

// 01.01.086	- Callback bei TCP Transfer zum Target wird an anderer Stelle aufgerufen.
//						- sIpAddress in Struktur TCPCB auf 256 Byte vergrößert. (Wegen DNS Namen)

// 01.01.085	- LslSendCommand, Kommando auf uint32_t geändert.
//						- LslPing, alles hinter ';' abschneiden.
//						- Onlinestring - neu Parsefunktion.
// 01.01.084	- Onlinestring mit RUNUC erweitert.
//            - Neue Funktion LslSendCommand (Universelle Funktion)

// 01.01.083	- Bei Verbindungsunterbrechung (USB - RS232 Onlineverbindung) wird Offline aufgerufen.

// 01.01.082	- RefreshListAdd hat zusätzliches Flag LSL_RL_FLAGADD_NOANSWER
//				- Neue Funktionen. (LslGetDataEx, LslSetDataEx, LslGetDataListEx, LslGetCounter..., LslCRC)

// 01.01.081	- Aufruf der Funktion LslBPCommand_I entfernt

// 01.01.080	- in TCPRequest2 Sleep(10) eingebaut (auf Anordnung von Hr. Fessl)

// 01.01.079	- neue Funktion: LslGetPLCInfoFromOnline 
//								 (nach dem Online gehen wird die PLC Info eingelesen. Und diesen kann man abfragen, ohne es von der CPU erneut anfordern zu müssen)
//				- plcInfo buffer vergrößert.

// 01.01.078	- Zugriff auf Varan32 impl.
//				- Prozessor Optimierung beim Build

// 01.01.076	- Neue Funktion. (LslBPCommand_I)

// 01.01.075	- Enh: neue Funktionen. (LslVaranDiagnoseCounter, LslVaranDiagnoseCounterH, LslVaranDiagnoseCounterRH)

// 01.01.074	-  neue Funktionen LslGetServerListH, LslGetServerList,
//				   LslGetDataListSpecialH, LslGetDataListSpecial eingefügt	

// 01.01.073	- Maximale Paketgröße bei ANPSendData von 1024k auf 512k geändert
//					Behebt Timout-Problem unter Windows Vista

// 01.01.072	- Enh: neue Funktion. GetMemInfo (Information über Speicherbereiche)
//				- Bug: LslGetProjectInfo, LslGetProjectInfoByType könnten den Speicher überschreiben.

// 01.01.071	- Enh: neue Funktionen. (LslVaranWatchDogTrigger, LslVaranWatchDogTriggerH, LslVaranWatchDogTriggerRH)

// 01.01.070	- Bug: LslPing funktionierte nicht ohne Admin rechte. (Online gehen schlug fehl)
//				- Enh: Anpassung Linux

// 01.01.069	- Bug: LslReadFromSvrStr & LslWriteToSvrStr Probleme mit PLC-Unicode Strings.

// 01.01.068	- Bug: Beim beenden kann sich das Programm aufhängen, wenn nicht Ordnungsgemäß Offline gegangen wird. (RefreshList)
//						Bei Ping wird nun auch DLL Shutdown erkannt.
//				- Enh: LslGetDllInfo umgebaut.
//				- Enh: RefreshList Logging verbessert.

// 01.01.067	- Bug: LslRefreshListCreateExt Callback wird nun auch gesetzt, wenn kein Table Objekt Name mitgegeben wird.

// 01.01.066	- Einige Funktionen (RefreshListSymTab... ) wurde nicht gelockt.
//				- LslGetObjectID funktionierte nicht mehr.

// 01.01.065	- Eigene Funktionen zum Direkten lesen/schreiben von String-Server
//				- Testfuntionen für String lesen/schreiben
//				- Testfuntionen für FileSave

// 01.01.064	- Neue Funktionen (für interne Verwendung)
//				- Fehler in LslRefreshListSetData & LslRefreshListGetData bei langen Daten
//				- LoadPrj hat nun ein Sleep. Da LoadModule fehlschlug, wenn man zu schnell war.
//

// 01.01.063	- Anpassung an Linux
//				- LslPing für Linux ausgeschaltet, da es unter Linux Root Rechte braucht.
//				- Bei manchen Funktionen (RefreshListAdd, ...) wurde bei einem Fehler ein Locking nicht wieder zurückgesetzt.
//				- RefreshListSetData & RefreshListGetData teilen Daten nun automatisch auf, falls sie zu große sind.
//					Das heist, es werden mehrere Sende & Empfangskommandos gemacht.

// 01.01.062	- TcpPing ist nicht nur Thread Safe sondern auch Process Safe.

// 01.01.061	- Verbessertes Logging in der RefreshList
//					Verbessertes Handling in LslRefreshListCreateExt mit Timeout (weniger GetCpuStatus aufrufe)
//					RefreshList Logging nun in eine eigene Datei.
//					RefreshListConnection Thread Receive: beendet sich nun von selbst, wenn die Verbindung beendet wurde. (Oder Fehler auftratt)
//					TcpPing ist nun Thread Safe (läuft in einem eigenen Thread)

// 01.01.060	- LslRefreshListIsOnline
//					Fehlererkennung verbessert.

// 01.01.059	- LslRefreshListMakeSRLVarInfo
//					Adresse darf auch NULL sein.

// 01.01.058	- Neue Funktion
//					LslRefreshListSupportedFunction
//				- Funktion: LslRefreshListSupportedVarSize wieder entfernt.
//				- Bei RefreshListOnline kann man nun eine ApplicationID mitgeben. ( Online("TCP:10.10.116.104;ApplID=10", ...))
//					Damit können mehrere TCP RefreshList Verbindungen von einem PC aufgebaut werden.

// 01.01.057	- Neue Funktion
//					LslRefreshListMakeSRLVarInfo			(siehe Funktionsdeklaration)
//					LslRefreshListGetLoaderVersion			(siehe Funktionsdeklaration)

// 01.01.056	- Portnummer für den Datenempfang bei Remotemanager geändert

// 01.01.055	- RefreshList Daten können nun Längen bis 255 haben.
//				  Bei Längen größer als 4 Byte wird nur die CRC geliefert. Die daten müssen selbst abgeholt werden.
//				- Neue Funktion:
//					LslRefreshListSupportedVarSize		(siehe Funktionsdeklaration)

// 01.01.054	- Die Bilddaten für den RemoteManager können nun bei einer TCP Verbindung  
//				über einen eigenen Port empfangen werden (sofern eine lrssvr.dlm ab v01.01.013
//				verwendet wird) SA11975

// 01.01.053	- Detailierteres Logging in der RefreshListe.	JO
//				- Bug: Falscher Funktionsname beim Logging beim Senden über die Refresh Liste
//				- Verbesserte Parameterprüfung bei den RefreshList Funktionen.
//				- Bug: 100% CPU Last, wenn bei der RefreshList Verbindung zur CPU abbricht.

// 01.01.052	- Funktion LslRefreshListIsOnline exportiert.	JO
//				- Serial Timeout Werte optimiert.
//				- define für LSL_RL_FLAG_DYNAMIC_LIST
//				- Bug: RefreshList möglicher Absturz wenn beim Datenlesen nocht nicht alle Daten vorhanden sind
//				- Bug: Keine Prüfung von Überlauf bei LslRefreshListAdd
//				- RefreshList ID verbesserte Prüfung auf Gültigkeit.

// 01.01.051	- Neue Funktionen für Oszi
//					LslOsziGetChannels
//					LslOsziGetSampleRate
//					LslOsziSetCRC
//					LslOsziGetCRC
//					LslOsziGetStatus

// 01.01.050	- Neue Funktionen für Hardwaretree und Safety:
//					LslHardwaretreeCommand	
//					LslHardwaretreeGetModuleInfo
//					LslHardwaretreeGetHWPath
//					LslHardwaretreeSafetyCmd
// 				- Umgebungsvariable LASAL32_PARAM, Wert ADD_RD_TIMEOUT wird jetzt auch beim CAN berücksichtigt

// 01.01.049			- Fehlerbehebung bei COM Timeout. ReadTotalTimeoutConstant wurde von 0 auf 100 gesetzt.
//						- Erweiterung: RefreshListe unterstützt nun auch Server mit Object Kanal.
//						- Anpassungen für WinCE, Win Pocket ARM

// 01.01.048			- Fehlerbehebung beim CANUSB Gerät

// 01.01.047			- bacrob: Sleep before TCP connect
//						- obejoh: Loader Bug I_GET_OBJ return len will be now checked.
//						- Fehlerbehebung bei USBCAN
//						- Verbesserung der Übertragungsgeschwindigkeit bei USBCAN

// 01.01.046		  - new function for RefreshList see LslRefreshList* 

// 01.01.045          - Neue Funktionen zum Aufruf von GetState und Kill

// 01.01.044          - Neue LASAL32_PARAM Option: LOGLRM. Wenn diese Option aktiviert ist, dann 
//                      werden genauere Logmeldungen bei LRM Befehlen weggeschrieben.
//                    - Wenn mit der SetCommand Funktion ein Reset Befehl abgesetzt wird, dann 
//                      wird jetzt max. 1 Sek. gewartet, bis der CPU-Status auf tatsächlich RESET ist.

// 01.01.043          - CANUSB:
//                      Für den Zugriff auf das CANUSB Gerät werden jetzt die Low-Level Funktionen 
//                      der FTD2XX.dll verwendet. Bisher waren die Funktionen der canusbdrv.dll in 
//                      Verwendung. Mit den canusbdrv Funktionen gab es einen Fehler in Zusammenhang 
//                      mit Lasal2: Manchmal blockierte ein Treiber Aufruf und die Funktion kehrte 
//                      nicht wieder zum Aufrufer zurück.

// 01.01.042          - Funktionen aus LslOnline übernommen. Damit braucht man keine LslOnline.DLL mehr.
//                    - Export Funktionen hinzugefügt:
//                          LslGetObject
//                          LslGetObjectEx
//                          LslGetObjCls
//                          LslWriteToSvr
//                          LslWriteToClt
//                          LslReadFromSvr
//                          LslReadFromClt
//                          LslReadNextObj
//                          LslReadNextChannel
//                          LslReadNextClass
//                          LslExecNewInstr
//                          LslExecNewInstrStream
//                          LslLoadProjectSingleObjFileByType
//                          LslLoadProjectSingleObjFile
//                    - Export Funktionen für Linux hinzugefügt:
//							            LslLibraryInit
//							            LslLibraryExit
//                    - CanLL, SEND_RETRIES von 10 auf 20 erhöht; Das Downloaden der Datei
//                      LS0001.MPC (294802 Byte bei verwendetem Testprojekt) eines LSE-Projekts funktionierte
//                      nicht, wenn die Datei bereits existierte. Grund war, dass in diesem Fall die fopen
//                      funktion im OS in diesem Fall lange dauerte und die 10 Retransmits
//                      überschritten wurden. SA 9798
//
// 01.01.041          - Export Funktionen hinzugefügt:
//                          LslLoadModulClsName
//
// 01.01.040          - CANUSB: Die Akzeptanzmaske war falsch eingestellt, das hat Probleme 
//                      bereitet, wenn der CAN Bus sehr ausgelastet war
//
// 01.01.039          - CANUSB: beim Öffnen des CANUSB Geräts wird jetzt eine Akzeptanzmaske 
//                      mitgegeben, damit wird das CANUSB Gerät nicht mehr mit CAN Messages 
//                      überflutet, wenn am CAN Bus viel los ist.
//                    - CANUSB: Die CANUSB Treiber-DLL wird jetzt beim Close mit FreeLibrary fregegeben
//                    - CANUSB: Ins Logfile wird die Versionsnummer des CANUSB Treibers geschrieben
//                    - Export Funktionen hinzugefügt:
//                          LslHoldApplication
//                          LslContinueApplication
//                          LslGetInstructionPointer
//                          LslGetModuleInfoByIp
//
// 01.01.038          - neue Funktionen für den VARAN Analyzer
//                    - Fehler in "GetNodeData" behoben, der bei größeren übertragenen
//                      Datenmengen zum Absturz führte.
//                    - Die DLL's für das CANUSB Gerät werden jetzt dynamisch geladen und sind 
//                      somit nur mehr erforderlich, wenn das CANUSB Gerät auch tatsächlich 
//                      verwendet wird.
// 01.01.037          - Unterstützung für das Lawicel CANUSB Gerät
//                    - Unterstützung von mehr als 4 COM Schnittellen (COM1 bis COM99)
// 01.01.036          - Neue Funktionen LslGetCommonData und LslSetCommonData
// 01.01.035          *** Testversion 20.11.2006***
// 01.01.034          - Fehlerbehebung bei der Threadsicherheitsfunktion beim Logging
// 01.01.033          - neue Export Funktionen:
//                         LslClearLinkerError
//                         LslClearLinkerErrorH
//                    - Fehlerbehebung bei der Threadsicherheitsfunktion beim Logging
// 01.01.032          - Namen werden bei TCP-Verbindungen akzeptiert (statt IP-Adressen)
//                    - neue Funktionen für den Zugriff auf VARAN Bus: 
//                      Read und Write auf Conrol und Memory Bereich
// 01.01.031          - Threadsicherheit beim Logging verbessert. (Fehler von Jimmy gefunden)
//                    - neue Funktion "VaranAnalyzerGetOptions"
// 01.01.030          - Änderungen für die WinCE Version:
//                      Manche Zuweisungen müssen mit memcpy statt mit *(uint32_t*)&var= gemacht werden, 
//                      um einen datatype misalignment fehler auf risc-cpus (arm, mips, sh) zu vermeiden.
// 01.01.029          - Das #define LSL_USE_TAPI war in 01.01.028 irrtümlich nicht gesetzt, was zur 
//                      Folge hatte, daß die Modemfunktionen nicht mehr funktionierten.
// 01.01.028          - VARAN Analyzer Kommandos
// 01.01.027          - Fehlerbehebung bei Oszi: SetSampleRate wurde Rückgabewert nicht richtig zurückgegeben
//                    - Änderungen für die WinCE Version (Änderungen sind mit ++WCE und +MF gekennzeichnet
//                    - neue Export Funktionen:
//                        LslGetChangeIDs
//
// 01.01.026          - Release Kandidat, 06.04.2006
//
// 01.01.025          - Rückgabewert von LslOsziSetSampleRate und LslOsziSetSampleRateH von LSL_BOOL auf int32_t geändert
//                      Wenn die eingestellte SampleRate aufgrund der Ticks nicht realisiert werden kann
//                      (z.B. SampleRate = 1500µs bei Tick = 1000µs) wird die angepasste SampleRate
//                      (hier: 1000µs) zurückgegeben. Rückgabewert LSL_BOOL war daher irreführend!
//                    - Wenn bei Oszikommandos mehr als 1k Daten angefordert werden, wird die entsprechende Funktion
//                      im OS wiederholt (mit max. 1k) aufgerufen und der Buffer zusammengebaut.
// 
// 01.01.024          - Fehlerbehebung beim Export der Varan-Funktionen
//
// 01.01.023          - neue Export Funktionen:
//                        LslGetLoaderflags
//
// 01.01.022          - Einbau der Oszi- und Varan-Kommandos
//
// 01.01.021          - neue Export Funktionen:
//                        LslExecIpr
//                    - Fehlerbehebung:
//                      - in der ExecIpr_Old wurde der Längenwert -1 (SEND_STATE_ONLY) falsch interpretiert
//                    - Der Parameter nPGStation wird jetzt bei einer TCP/IP Verbindung ausgewertet. Wenn 
//                      das oberste Bit gesetzt ist, werden die restlichen Bits als TCP Parameter verwendet:
//                        nPGStation  ..  CAN:
//                                          Stationsnr. des PCs (0..31), nur bei CAN relevant
//                                        TCP:
//                                          Flags:
//                                            76543210
//                                            !!    !!
//                                            !!    ! \_ 1 = not in LAN
//                                            ! \____\__ reserviert (müssen auf 0 gesetzt sein)
//                                             \________ 1 = TCP Flags available (zur Sicherheit, da 
//                                                       der Parameter nPGStation bei TCP bisher 
//                                                       nicht ausgewertet wurde)
//                      Das Flag 'not in LAN' bewirkt, daß z.B. kein Ping zur Überprüfung der 
//                      Verbindung verwendet wird, da bei einem Ping ausserhalb des LANs der 
//                      Timeoutwert nicht abgeschätzt werden kann. In diesem Fall ziehen die 
//                      Timeoutwerte des TCP/IP Protokolls.

// 01.01.020          - neue Export Funktionen:
//                        LslReadDateTime
//                        LslSetDateTime
//                        LslAdjustDateTime
//                    - Fehlerbehebung:
//                        - Den zusätzliche Read-Timeout beim ExecIpr Befehl von 1 Sek. auf 5.1 Sek. 
//                          erhöht (5.1 Sek. entspricht dem 2fachen Wert des max. möglchen Runtime Wertes von 255).
//                          Mit einem kleineren Timeout konnten bei der CAN Verbindung Fehler auftreten, 
//                          wenn der Timeout in der DLL früher als der DEBUGIP Timeout in der SPS abläuft.
//                        - Wenn das in der Online Funktion befindeliche GetPlcInfo einen Fehler lieferte, 
//                          dann lieferte die Online Funktion FALSE zurück ohne die zuvor allokierten 
//                          Ressourcen freizugeben. Das hatte zur Folge, daß bei V24 die Online-Funktion 
//                          nicht mehr funktionierte (das COM-Mutex war nicht freigegeben).
//                    - Timeout in der FileUpdateInfo_I beim Update-Typ 2 von 5 auf 10 Sek. erhöht.
//                    - Das Mutex für die COM Schnittstelle wurde entfernt, da sowieso nur 1 Task das 
//                      File für das COM Device öffnen kann.
//                    - LslClearSram löscht jetzt auch die Files die beim Sram Reorg verwendet werden
//                      (C:\RAMFILE.DAT und C:\RAMFILE.BAK)

// 01.01.019          - neue Export Funktionen:
//                        LslRenameFileDir
//                        LslGetDiskSpace
//                        LslGetDriveListShort
//                        LslCheckDisk
//                        LslTestCmd
//                        LslGetLoaderinfo
//                    - im Tapicode.cpp bei den PeekMessage Schleifen im else-Zweig ein 
//                      Sleep(10) engebaut, damit die CPU nicht so start belastet wird

// 01.01.018          - neue Export Funktionen:
//                        LslFormatDrive
//                        LsFileDelete
//                        LslSetSysTraceBufSize
//                        LslGetSysTraceBufSize

// 01.01.017          - Testversion für Loader-Entkopplung

// 01.01.016          - Unterstützung der LOB-Typ Kennung für Loader-Entkopplung
//                    - neue Export Funktionen:
//                        LoadPrjByType
//                        LslGetModulInfoByType
//                        GetChkByType
//                        LslGetProjectInfoByType
//                        IsModTypeSupportedByOs
//                        LslSetDfltModTypeParams

// 01.01.014          - Beim LslLoadOSImage Befehl wird jetzt sichergestellt, daß vor dem eigentlichen 
//                      Os-Download das Projekt im Reset-Zustand ist.

// 01.01.013          - Fehlerbehebung in der ExecIpr_Old Funktion:
//                        Wenn der BefIpr eine Länge von -1 zurückliefert, dann kam es zu einer 
//                        Schutzverletzung

// 01.01.012          - neue Export Funktion
//                        LslSetSysTrace
//                        LslClearSysTrace
//                        FileUpdateInfo

// 01.01.011          - neue Export Funktion
//                        LslSetAddTvMs - vergibt einen zusätzlichen Read-Timeout (in ms)
//                        LslSetEnvParam - Legt einen Parameter fest, der auch mit der LASAL32_PARAM 
//                          Umgebungsvariable eingestellt werden kann.
//                          z.B. LslSetEnvParam("DBGLEVEL=3") od. LslSetEnvParam("DBGLEVEL=0")
//                        LslSetDbgLevel
//                          Ändert den DebugLevel auf den angegebenen Wert (nur wenn der als Parameter 
//                          übergebene neue Level >= 0 ist). Als Returnwert wird der alte DebugLevel 
//                          zurückgegeben.
//                    - Bei der Online-Funktion wurde bei der ser.Schnittstelle TRUE zurückgegeben 
//                      wenn sich die COM-Schnittstelle öffnen ließ, unabhängig davon ob die SPS 
//                      antwortet. Jetzt wird nur mehr TRUE zurückgegeben, wenn die SPS auch antwortet.
//                    - Die IsOnline-Funktion erkennt jetzt bei TCP/IP eine Verbindungsunterbrechung

// 01.01.010          - neue Export Funktion
//                        LslClearSram

// 01.01.009          - neue Export Funktion
//                        LslGwConnect
//                        LslGwClose
//                        LslGwTransfer
//
// 01.01.008          - Beim ExecIpr_Old wird jetzt der CPU Status geprüft um festzustellen, ob der 
//                      Loader läuft. Wenn er nicht läuft, dann wird gleich ein Fehlercode zurückgegeben 
//                      und nicht der Timeout abgewartet.
//                    - Memory Leaks behoben:
//                      TCP/IP: bei jedem Online 1024 Bytes
//                      CAN: bei jedem Online 96 Bytes

// 01.01.007          - neue Export-Funktionen
//                        LslFindFirst
//                        LslFindNext
//                        LslFindClose

// 01.01.006          - Timeout beim ExecIpr Befehl auf 1 Sek. erhöht, da es länger dauern kann bis ein 
//                      NAK zurückgeschickt wird, wenn der Loader keine Interpreterbefehle abarbeitet.
//                    - ExecIpr_old:
//                      In Ip::WaitForResponse wird jetzt nicht nach 10 Versuchen sondern nach 300ms aufgegeben.
//                      Wenn SpsLock beim Warten auf die Antwort scheitert, dann noch ein SpsUnlock nachgeschickt, 
//                      damit der LOCK Befehl dann nicht mehr abgearbeitet werden kann.

// 01.01.005          - Stresstestfunktionen eingebaut
//                    - neuer Parameter der Umgebungsvariable LASAL32_PARAM:
//                      TCP_NOPING_HOST=<ip-addr>[,<ip-addr>,...]
//                      Bei den angegebenen Ip-Adressen wird vor dem Verbindungsaufbau 
//                      kein ping aufgerufen. 
//                      Manche Firewalls sind nämlich so konfiguriert, daß ein Ping zu einem 
//                      Host nicht möglich ist, ein connect aber schon.

// 01.01.004          - Fehler in DBG_Print behoben.

// 01.01.003          - neuer Parameter der Umgebungsvariable LASAL32_PARAM: LOGAPI
//                      Wenn dieser Parameter vorhanden ist, dann werden alle API Aufrufe 
//                      ins Logfile geschrieben (Entry + Exit)

// 01.01.002          - mehrere Connections pro DLL-Instanz möglich
//                    - neue Export-Funktionen
//                        OcbOpen
//                        OcbClose
//                    - Für alle API Funktionen, die sich auf eine Onlineverbindung 
//                      beziehen, gibt es eine Version, bei der ein Handle auf einen 
//                      OCB (Online Control Block) mitgegeben werden kann.
//                      Der Name der neuen Funktion setzt sich aus dem alten Namen und 
//                      einem angehängten 'H' zusammen.
//                      z.B. OnlineH, GetDataH
//                    - nicht mehr benötigte Funktionen entfernt:
//                        GetCLILineCount
//                        GetCLIStatus
//                        GetCLILineString
//                        LASALCommand
//                        CanLogin
//                        CanLogout
//                        CML_TxCommand
//                        CML_StartStopRefresh
//                        CML_TxUpdp

// 01.01.001          - TCP/IP Default Timeout von r15/w5 auf r30/w15 Sek. erhöht wg. Problemen 
//                      bei Compact Flash vom Typ 101
//                    - neue Export Funktionen:
//                        DBG_Print
//                        ExecIpr
//                        ExecIprRlen
//                        GetProtocolVersion
//                        LslGetModulInfoIP
//                        LslGetProjectInfoEx
//                        StartMeasurementNew
//                        StopMeasurementNew
//                        GetMeasurementDataNew
//                    - Timeouts beim Modem beim Verbindungsaufbau geändert
//                    - Versionsnummernschema geändert y.zz -> xx.yy.zzz
//                      GetDllVersion liefert einen 2 Byte Wert, der folgendermaßen codiert ist:
//                        7654 3210 76543210
//                          !    !        \___ zzz
//                          !    \____________ yy
//                          \_________________ xx
//                    - Mit der Umbegungsvariablen LASAL32_PARAM können der Lasal32.dll Parameter 
//                      übergeben werden. Die einzelnen Parameeter sind durch ein Semikolon getrennt.
//                      Dzt. gibt es folgende Parameter:
//                        TCP_RD_TIMEOUT=<tcp/ip read timeout in sek.>
//                        TCP_WR_TIMEOUT=<tcp/ip write timeout in sek.>
//                      Bsp.: TCP_RD_TIMEOUT=20;TCP_WR_TIMEOUT=5

// 1.40               - Release Version 27.4.2004

// 1.39
//                    - Funktion GetData: maxrxlen von 1450 auf 1000 geändert.
//                      (bei Messungen wurde mit diesem Wert eine höhere Übertragungsrate erzielt)
//                    - Beim CreateMutex der COM-Handles wird ein Security Attribut verwendet.
//                      Grund:
//                      Wenn ein Service die DLL benutzt (z.B. Toms PowerDown Erkennung), dann 
//                      kann ein Anwendungsprogramm das Mutex nicht mehr mit CreateMutex öffnen, 
//                      solange kein Security Descriptor verwendet worden ist.
//                    - Begrenzung des TCP/IP Timeouts auf 20 sek. entfernt.

// 1.38               - Release Version 26.3.2004

// 1.37
//                    - Wenn im Debuglog-File die max. Anzahl von Zeilen erreicht ist, dann wird 
//                      das File auf <file>.BAK umbenannt und ein neues File erstellt.
//                      (bisher wurde das logging angehalten, wenn die max. Anzahl von Einträgen 
//                      erreicht worden ist).
//                    - neue Export-Funktionen:
//                        LslGetModulInfoIDList
//                        GetSramdatLen
//                        GetSramdat
//                        SetSramdat
//                        GetTraceEntries
//                    - Fehlerbehebung:
//                        - In der FileSave Funktion hat das ENTER_CS/LEAVE_CS gefehlt
//                        - StorePLCInfo hat fälschlicherweise PLCInfo.IsValid auf FALSE gesetzt, 
//                          wenn jemand GetPlcInfo mit einem zu kleinen Buffer aufgerufen hat.

// 1.36               - 31.10.03: Release Version

// 1.35               - 16.6.03: Fehlerbehebungen:  Project Download mit TCP und Lasal OS < 5.22
//                                                  funktionierte nicht
//                      -> ANPreadvrec; ANPreadn; TCPOnline angepaßt
//                      -> NAGLE aktiviert wenn OS < 5.22
//                    - neue Export-Funktionen:
//                        FileSaveEx
//                    - Fehlerbehebung:
//                        - CAN: 
//                            CT_createfile hat auf NULL anstatt INVALID_HANDLE_VALUE abgefragt.
//                        - FileSave:
//                            Bei der langsameren Version von FileSave wird bei jedem einzelnen 
//                            Block eine Sendwiederholung gemacht, wenn ein Fehler auftritt, da 
//                            es vor allem bei einem 386er und RS232 Probleme mit größeren Files 
//                            gibt.
//                    - Mutex bei GetAwlBpStatus entfernt, da die Funktion Thread-Safe ist
//                        (es wird kein Online-Befehl abgesetzt)
//                    - Struktur PLC_INFO aus Lasal32.h in System.h gegeben

// 1.34               - 13.3.03: Release Version

// 1.33               - Multithread-Support:
//                      Standardmäßig werden alle Online-Funktionen mit einem Critical-section
//                      Objekt geschützt.
//                      Multithread-Support kann mit der Funktion SetMultiThreadSupport 
//                      deaktiviert werden.
//                    - Übertragungsgeschwindigkeit optimiert

// 0x0084 (1.32)      - 11.2.03: ReleaseVersion 1.32

// 0x0083             - Versionnummer erhöht, da ab jetzt Testversionsnummern immer ungerade sind
//                    - Debug-Log Meldungen werden jetzt nicht mehr ins Arbeitsverzeichnis 
//                      sondern auf C:\ geschrieben. Wenn das nicht möglich ist, dann wird 
//                      wieder das Arbeitsverzeichnis verwendet.

// 0x0082             - CanLL Fehlerbehebungen
//                    - TCP/IP: 
//                        - beim Ping den gethostbyname()-Aufruf entfernt, da dieser ca. 30Sek.
//                          dauert, wenn kein Nameserver vorhanden ist (z.B. bei einer 1 zu 1
//                          Verbindung)
//                        - Übertragungsgeschwindigkeit optimiert
//                    - Modem: Verbindungsaufbau verbessert (fehlertoleranter)
//                    - CAN: 
//                        - Verwendung von IOCTL_STEK_CAN_TXMSG_EX
//                        - SetHardmode ruft jetzt SetPause(0/2) auf
//                    - FileSave:
//                        - Übertragungsgeschwindigkeit optimiert (DBG_CMD_SAVE_FILE2)

// 0x0081 (13.11.02): - neue Export-Funktion: 
//                        GetPowerFailInfo
//                        StartCPUMeasure
//                        StopCPUMeasure
//                        GetCPUMeasureStatus
//                        GetCPUMeasureData
//                    - Verbindungstypabhängige Größenbeschränkungen bei SetData/GetData entfernt 
//                    - Fehlerbehebung bei FileSave/FileWrite:
//                        Bei gewissen Filegrößen wurde am Schluß noch ein Block der Länge 0
//                        übertragen, das OS antwortet in diesem Fall mit NACK, und FileSave 
//                        liefert FALSE (das File wurde aber korrekt übertragen).
//                    - Fehlerbehebung beim CAN: VisualBasic Programme stürzten beim Beenden des 
//                        Programms ab, wenn man zuvor mit CAN Online war und wenn das VB Programm 
//                        aus der VB Entwicklungsumgebung gestartet wurde.
//                        Grund für dieses Verhalten: VB verhält sich beim DLL-Unload scheinbar 
//                        anders, wenn man ein Programm aus der Entw.Umgebung startet.
//                        Lösung: CAN-TimerThread wird jetzt bei jedem Aufruf von Offline() gestoppt.
//                    - V24: Read-Timeouts erhöht
// 0x0080 (19.8.02):  - Fehler bei LslSetBpEx behoben 
//                      (der Funktion SetBreakPoint wurde für die Parameter StackOffset,StackSize 
//                      und Counter der Wert 0 übergeben)
// 0x007f (25.6.02):  - neue Export-Funktion: LslSetDataBp (Datenbreakpoint)
//                    - Export-Funktionen entfernt: LslGetBpEx
//                    - Export-Funktionen geändert: LslGetBpList (war bisher noch nicht in Verwendung)
//                    - CanLL optimiert
//                    - Sigma32.sys/Sigma32.vxd-Treiberaufrufe entfernt 
//                        (Treiber wird jetzt nicht mehr geöffnet)
//                    - pcdias.cpp,sysvxd.cpp,sysvxd.h entfernt
// 0x007e (10.5.02):  - CAN Funktionen
//                    - neue Export-Funktion: 
//                          - ServiceProvider
//                    - Fehler beim Ping (IP) behoben (closesocket wurde nicht durchgeführt)
// 0x007d (7.5.2002): - _SYSNAME von "Lasal32.sys" auf "Sigma32.sys" geändert, da bei
//                       zukünftigen Lasal-Installationen der Treiber mit dem Filenamen 
//                       "Sigma32.sys" anstatt "Lasal32.sys" installiert wird. 
//                       Anm:
//                       Die beiden .sys-Treiber sind identisch. In der DLL wird zum Öffnen
//                       des Treibers nicht der  Filename sondern der Devicename "\\.\SIGMA" 
//                       verwendet. Der Filename wird nur für Fehlermeldungen benötigt.
//                       Unterschiedliche Filenamen haben bisher immer zu einer Systemmeldung
//                       geführt (ein Dienst konnte nicht gestartet werden), wenn PG50 und
//                       Lasal installiert worden ist.
//                     - neue Export-Funktion: 
//                          - LoadModulRMD
//                          - GetGenStatus
//                     - Fehlerbehebung: 
//                        TCP/IP: unter NT blieb der Verbindungsaufbau hängen, wenn 
//                        die Ziel-IP-Adressse nicht existierte (ping bekam beim recvfrom keinen Timeout).
//                        -> mit Socket Attribut WSA_FLAG_OVERLAPPED funktionierts
// 0x007c (6.3.2002):  - neue Export-Funktion: 
//                          - SetRegisterEx
//                          - EditObj
//                          - GetObjectInfo
// 0x007b (21.2.2002): - Fehlerbehebung:
//                          - Callback-Funktion wurde bei TCP-Requests nicht aufgerufen
//                     - TCP/IP Default ReadTimeout von 5 Sek. auf 15 Sek. erhöht
//                        (bei einer DFÜ Verbindung über Modem ins Internet traten beim 
//                        Projektdownload Timeouts auf)
//                     - beim Online mit TCP/IP wird mit einem Ping geprüft, ob die 
//                        Zielstation antwortet
//                     - CanLogin deaktiviert (liefert jetzt immer FALSE), da CanelIO 
//                        aufgerufen wird und CancelIO unter Win95 nicht existiert !
// 0x007a (11.1.2002): - neue Export-Funktion: 
//                          - ModemIsConnected
//                          - CanLogin
//                          - CanLogout
//                          - CanSendObj
//                          - CML_TxCommand
//                          - CML_StartStopRefresh
//                          - CML_TxUpdp
//                          - GetCmdStringStatus
//                     - Read-Timeout bei einer Modemverbindung verdoppelt
// 0x0079 (10.1.2002): - TCP Funktionen
//                     - neue Export-Funktion: 
//                          - GetAwlBpStatus
//                          - SendCmdString
//                     - SetRegister: es werden jetzt für den Register-Wert immer 4 Bytes geschickt
//                          (nicht wie vorher 2 Bytes, wenn Reg.Nr > 13 ist)
//                     - zusätzliche Read-Timeouts für FileXXXX Funktionen: 2 sek.
//                     - folgende nicht mehr benötigte Funktionen entfernt:
//                          - SDE-Funktionen
//                          - GetDataPG()
//                          - SetKopBp()
//                          - GetKopBp()
//                          - GetHeader()
//                          - GetRegister()
//                          - GetRegister32()
//                          - LslGetRegister()
//                     - bei folgenden Funktionen den Returncode von uint32_t auf LSL_BOOL geändert,
//                       da Lasal den Rc auf TRUE und FALSE abfragt (neg.Returncodes wurden bisher vom
//                       Lasal fälschlicherweise als TRUE interpretiert !)
//                          FileInfo ( statt neg.Rc wird jetzt FALSE zurückgegeben)
//                          FileSave
//                          FileLoad ( statt neg.Rc wird jetzt FALSE zurückgegeben)
//                          FileWrite
//                          LASALCommand
//                     - ACSESS_PAUSE von 400L auf 100L geändert
//                          (Abtastzeit fuer wiederholten Aufruf von IsOnline() und GetCpuStatus()
//                     - folgende V24-Funktionen von V24.cpp ins Lasal32.cpp verlagert, dort wird
//                       erst der Sendebuffer aufbereitet und der Empfangsbuffer zur Verfügung 
//                       gestellt und dann eine vom BusType abhängige Sende- + Empfangs- Funktion
//                       aufgerufen.
//                       Dadurch muß das aufbereiten des Sendebuffers und das interpretieren der
//                       Response nicht mehr für jede Kommunikationsart extra gemacht werden.
//                          - SetData
//                          - GetData
//                          - SetCommand
//                          - LslGetPLCInfo
//                          - LslSave
//                          - LslLoad
//                          - FileLoad
//                          - FileInfo
//                          - FileWrite
//                          - FileSave
//                          - LslGetProjectInfo
//                          - GetAwlBp
//                          - ClrBp
//                          - SetRegister
//                          - LoadPrj        
//                          - LoadModul    
//                          - LinkModules    
//                          - LoadEXEModul
//                          - LslSetBpEx    
//                          - LslSetBpRelativ
//                          - LslGetRegisterRelativ
//                          - LslGetModulInfo        
//                          - LslGetModulInfoID    
//                          - LslGetAdressVar        
//                          - LslLoadOSImage        
//                          - LslGetLinkerError    
//                          - SendDataList        
//                          - GetDataList            
// 0x0078 (07.12.01):  - GetBpList entfernt, wird im Lasal nicht verwendet
//                     - V24LslGetBpList so abgeändert, daß nur FALSE zurückgeliefert wird
//                     - Struktur AWLBPINFO geändert (wird in GetAwlBp verwendet):
//                          'uint8_t    Status' entfernt
//                          'CP_REG    CpReg' wird zu 'CP_REGextend    CpReg'
//                     - Struktur PrjHeader geändert (wird im LslGetProjectInfo verwendet):
//                          'uint32_t ModDisabled' wird zu 'ExPrjStatus Status' (Länge unverändert)
//                     - Parameterliste bei LslSetBpEx erweitert: +StackOffset, +Counter
//                     - neue Funktion: LslGetBpEx
//                     - Parameterliste bei GetAwlBp erweitert: +wBufLen
//                     - bV24Direct, und alle V24-VXD Treiberaufrufe entfernt, da 
//                          bV24Direct ohnehin beim OpenComm auf TRUE gesetzt wird, was zur
//                          Folge hat, daß der VXD-Treiber für die V24 Kommunikation nie 
//                          verwendet wird.
//                     - neuer Online-String: COMM (=Modem)
//                          zuvor muß eine Modemverbindung aufgebaut werden:
//                              ModemOpen()         .. TAPI initialisieren
//                              ModemGetNumber()    .. Anzahl Modems im System ermitteln
//                              ModemGetName(...)   .. Namen der Modems abfragen
//                              ModemCall(...)      .. wählen
//                          Modemverbindung beenden:
//                              ModemClose()
// 0x0077 (06.12.01):  Fehlerkorrektur: 
//                      im ReadComm() und WriteComm() wurde beim mitloggen von Debuginfo
//                      über die Größe von linebuf hinausgeschrieben, wenn nCount > 7 ist.
//                      Fehler trat nur auf, wenn DBGLEVEL > 2 ist (Env.Variable DBGLEVEL)
// 0x0076 (04.12.01):  Fehlerkorrektur: 
//                      beim V24Online wurde das COM-Mutex nicht freigegeben, wenn OpenComm scheitert
// 0x0075 (29.11.01):    dll-version wird in Lasal angezeigt ->
//                     abgeglichen mit File-version im RC
// 0x0111 (12.11.01):  pr:
//                     - PLCInfo wird in glob.Variable PLCInfo gespeichert
//                     - neue Export-Funktionen:
//                         LslSave, LslLoad, LslSetBpEx
//                     - geänderte Export-Funktionen
//                         - GetAwlBp( AWLBPINFO *pAwlBpInfo )
//                           - V24LoadPrj schickt in einem 2.Kommando den Projektnamen 
//                           (nur für OS >= 4.xx)
//                     - LslSetBp wird vom OS nicht mehr unterstützt und liefert daher immer
//                         FALSE zurück
//                     - Einbau von Debuglog-Meldungen:
//                        Über Environment Variablen wird festgelegt, ob Debug-Meldungen 
//                        ausgegeben werden:
//                            DBGLEVEL: Wert > 0 = Ausgabe von Debugmeldungen in ein File
//                          DBGFNAME: Name des Files, in das die Meldungen geschrieben werden
//                                      (Default: SIGMA32DBG.TXT im Arbeitsverzeichnis)
//                            DBGMAX:   max. Anzahl von Debugmeldungen, um die Platte, auf der
//                                      sich das Debugfile befindet nicht voll zu machen
//                                    (Default: 100000)
//                        Über ein Preprozessor define (DEBUGLOG - File debug.h) kann der Code
//                        für diese Meldungen aktiviert od. deaktiviert werden.
//                     - CAN-Funktionen tlw.aktiviert. 
//                          Für die Nutzung dieser Funktionen ist der CANLPT-Treiber erforderlich !

// 0x0110 (09.11.01):  - ???

// 0x010F (21.08.01):  - callback-funktion beim Moduldownload, deleteModule

// 0x010E (23.07.01):  THR: Added the following changes (search for V010E
//                     - V24.cpp: Created defines for Tx and Rx maximum buffer sizes and
//                       increased to 1024 bytes each.  All single calls to SendComm
//                       or ReadComm MUST transfer less than these amounts.  This is
//                       some large file transfers were failing.
//                     - V24.cpp: Modified SetupComm() call to use new definess.
//                     - V24.cpp: Added new V24BootOSFile() function to boot from a file.
//                     - V24.cpp: Added new V24LoadFilePacket() function and modified the
//                       V24LoadFile() function to retry block reads up to 3 times.
//                     - V24.h: Added prototype for V24BootOSFile() function.
//                     - lasal32.cpp, lasal32.h, lasal32.exp: Added LslBootOSFile()
//                       export function.

// 0x010D (20.06.01):  - GetLinkerError, StoreFile,..

// 0x010C (17.04.00):  - Modem Kommunikation optimiert
//                     - CPU Auslastung unter NT verringert
// 0x010B (19.01.00):  - DetectDMx(), ReadDMx(), WriteDMx(), EraseDmx() eingebaut

// 0x010A (10.01.00):  - Fehler im SYS-Treiber behoben (Fehler unter NT im Softmodus)

// 0x0109 (21.12.99):  - Fehler bei CAN-Betrieb unter NT behoben
//                     - Endlosschleife bei OFFLINE über V24 unter NT

// 0x0108 (02.11.99):  - MODEM-Funktion für Windows NT erweitert und getestet

// 0x0107 (07.02.99):  - MODEM-Funktion eingebaut (direkt und Modemprozessor)

// 0x0106 (08.12.98):  - TCP/IP Unterstützung
//                     - GetCpuStatus2() für die PG50 eingebaut

// 0x0105 (27.04.98):  - Probleme beim Oeffnen des SYS-Treibers behoben
//                     - im VXD wird die LPT-Portadresse aus dem BIOS bestimmt

// 0x0104 (24.03.98):  - SetRegister(): erweiterte Register beginnen bei 13 statt 12
//                     - V24SetKopBp() korrigiert

// 0x0103 (18.03.98):  - GetCpuStatus() funktioniert auch wenn es der erste V24-Zugriff ist.

// 0x0102 (17.03.98):  - bei Win95 "harter" Modus fuer PG-Statustest


// Das #define LASAL32_STATIC_LIB muß definiert werden, wenn die DLL als statisch 
// gelinkte Bibliothek eingebunden wird.

typedef int32_t					LSL_BOOL;				//
typedef void *					LSL_HANDLE;				// 

#pragma pack(push, 1)
typedef struct _LSL_SYSTEMTIME
{
	uint16_t wYear;
	uint16_t wMonth;
	uint16_t wDayOfWeek;
	uint16_t wDay;
	uint16_t wHour;
	uint16_t wMinute;
	uint16_t wSecond;
	uint16_t wMilliseconds;
} LSL_SYSTEMTIME;
#pragma pack(pop)


#if defined(LASAL32_STATIC_LIB) || defined(COMPILE_LINUX)
#define LASAL32_EXPORTS
#else
#define LASAL32_EXPORTS WINAPI
#endif


////////////////////////////////////////////////////////////////////////////////
//
// Error-codes from GetLastError
//
////////////////////////////////////////////////////////////////////////////////

#define ERROR_SIGMA32_NO						0				// Kein Fehler
#define ERROR_SIGMA32_ACCESSDENIED				0x20000001L		// Der Treiber wird bereits von einer anderen Software verwendet (z.B.: PG)
#define ERROR_SIGMA32_NOTOPEN					0x20000002L		// Es wurde eine DLL-Funktion aufgerufen, ohne vorher die Kommunikation mit Online() zu initialisieren.
#define ERROR_SIGMA32_ALREADYOPEN				0x20000003L		// Online() wurde noch einmal aufgerufen, ohne die Kommunikation mit Offline() zu beenden.
#define ERROR_SIGMA32_NOTDEFINEDFORV24			0x20000004L		// Es wurde eine CAN-Funktion waehrend der V24-Kommunikation aufgerufen.
#define ERROR_SIGMA32_WRONGPARAMETER			0x20000005L		// Ungueltige Parameter beim Aufruf der letzten Funktion
#define ERROR_SIGMA32_WRITE_TIMEOUT				0x20000006L		// Timeout-Fehler waehrend dem Senden
#define ERROR_SIGMA32_READ_TIMEOUT				0x20000007L		// Timeout-Fehler waehrend dem Empfangen
#define ERROR_SIGMA32_WRITE_FAULT				0x20000008L		// Allgemeiner Fehler beim Senden
#define ERROR_SIGMA32_READ_FAULT				0x20000009L		// Allgemeiner Fehler beim Empfangen
#define ERROR_SIGMA32_CONN_RESET				0x2000000CL		// Online wurde zwar aufgerufen, es besteht inzwischen aber keine Verbindung mehr
#define ERROR_SIGMA32_ABORTED_BY_USER			0x2000000DL		// Callback Funktion hat einen Abbruch verlangt
#define ERROR_SIGMA32_REMOTE_ERROR				0x2000000EL		// Von der Gegenstation wurde ein Fehler angezeigt
#define ERROR_SIGMA32_UNSUPPORTED_CMD			0x2000000FL		// Befehl wird von der Gegenstation nicht unterstützt
#define ERROR_SIGMA32_GENERAL_ERROR				0x20000010L		// unbekannter allgemeiner Fehler
#define ERROR_SIGMA32_CONNECT_FAILED			0x20000011L		// Verbindungsaufbau hat fehlgeschlagen
#define ERROR_SIGMA32_INVALID_FUNCTION			0x20000012L		// Invalid function
#define ERROR_SIGMA32_CPUSTATUS_TIMEOUT			0x20000013L		// Timeout waiting for a specific CPU status
#define ERROR_SIGMA32_OUT_OF_MEM				0x20000014L		// Out of memory
#define ERROR_SIGMA32_MAX_CONN					0x20000015L		// max. Nbr. of connections reached
#define ERROR_SIGMA32_INV_OCB_NBR				0x20000016L		// invalid ocb number
#define ERROR_SIGMA32_INV_PRJ_STATE				0x20000017L		// invalid project state
#define ERROR_SIGMA32_OUT_OF_BUFSIZE			0x20000018L		// Buffer size is too small
#define ERROR_SIGMA32_INVALID_DATA				0x20000019L		// Invalid data for Single Object File
#define ERROR_SIGMA32_INVALID_RLB				0x2000001AL		// Wrong RLB id
#define ERROR_SIGMA32_LENGTH_TO_BIG				0x2000001BL		// Length is to big
#define ERROR_SIGMA32_WRONG_VAR_TYPE			0x2000001CL		// Wrong Variable Type
#define ERROR_SIGMA32_LENGTH_WRONG				0x2000001DL		// Length is wrong
#define ERROR_SIGMA32_INIT_SYMTAB				0x2000001EL		// Call InitSymTab faild
#define ERROR_SIGMA32_TX_COMMAND				0x2000001FL		// TxCommand failed
#define ERROR_SIGMA32_NOT_READY					0x20000020L		// TxCommand returned NOT Ready
#define ERROR_SIGMA32_INVALID_ADDRESS			0x20000021L		// The address is invalid
#define ERROR_SIGMA32_WRONG_CONNECTION_TYPE		0x20000022L		// Wrong Connection (Bus ) Type
#define ERROR_SIGMA32_NO_FREE_DOB				0x20000023L		// no free DOB (DirectOnlineBlock)
#define ERROR_SIGMA32_WRONG_DOB					0x20000024L		// wrong DOB id
#define ERROR_SIGMA32_NO_DOB					0x20000025L		// no DOB for id found
#define ERROR_SIGMA32_CONNECTION_ABORTED		0x20000026L		// Connection Aborted
#define ERROR_SIGMA32_WRONG_RECEIVE_MODE		0x20000027L		// 
#define ERROR_SIGMA32_DO_RECEIVE_NO_DATA		0x20000028L		// No Data for Receive available
#define ERROR_SIGMA32_DO_RECEIVE_TIMEOUT		0x20000029L		// No Data for Receive available
#define ERROR_SIGMA32_DO_UNKNOWN_SET			0x2000002AL		// Unknown DirectOnline Set Type
#define ERROR_SIGMA32_ERROR_STATUS				0x2000002BL		// The correct error are in a other parameter
#define ERROR_SIGMA32_FILE_OPEN					0x2000002CL		// error at open a file
#define ERROR_SIGMA32_FILE_READ					0x2000002DL		// error reading a file
#define ERROR_SIGMA32_FILE_WRITE				0x2000002EL		// error writting a file
#define ERROR_SIGMA32_FILE_CLOSE				0x2000002FL		// error close a file
#define ERROR_SIGMA32_FILE_HANDLE				0x20000030L		// error invalid file handle
#define ERROR_SIGMA32_FILE_SEEK					0x20000031L		// error seek
#define ERROR_SIGMA32_FILE_TELL					0x20000032L		// error tell
#define ERROR_SIGMA32_FILE_SETSIZE				0x20000033L		// error set file size
#define ERROR_SIGMA32_FILE_GETATTRIBUTE			0x20000034L		// error set file attribute
#define ERROR_SIGMA32_FILE_SETATTRIBUTE			0x20000035L		// error set file attribute
#define ERROR_SIGMA32_FILE_SETDATETIME			0x20000036L		// error set file file date/time
#define ERROR_SIGMA32_FILE_NOT_FOUND			0x20000037L		// error find not found
#define ERROR_SIGMA32_WRONG_ONLINE_PWD			0x20000038L		// wrong online pwd
#define ERROR_SIGMA32_NO_SUPPORT_BY_OS_VER		0x20000039L		// Functionality not supported by this OS version
#define ERROR_SIGMA32_NO_PASSWORD_SET			0x20000040L		// If one trys to go online with a password but there 
																// is no password protection on the target the Online command will succeed, but the 
#define ERROR_SIGMA32_CONNCLOSED				0x20000041L		// connection is closed
#define ERROR_SIGMA32_READONLY					0x20000042L		// 
#define ERROR_SIGMA32_SOCKET_ALREADYOPEN		0x20000043L		// socket is already open 
#define ERROR_SIGMA32_SOCKET_INVALID			0x20000044L		// invalid socket

////////////////////////////////////////////////////////////////////////////////
//
// VARAN32.DLL
//
//	needed defines for Varan32.dll using.
////////////////////////////////////////////////////////////////////////////////
#define VARAN32_WFTE_STATE_BUSY		4 //auch in Varan32.h ändern!
#define VARAN32_WFTE_STATE_FINISH	5 //auch in Varan32.h ändern!
#define VARAN32_CONNECTION_STRING   "VARAN32:"

////////////////////////////////////////////////////////////////////////////////
//
// File attributes
//
////////////////////////////////////////////////////////////////////////////////

#define LSL32_ATTR_READ_ONLY      0x0001
#define LSL32_ATTR_HIDDEN         0x0002
#define LSL32_ATTR_SYSTEM         0x0004
#define LSL32_ATTR_VOLUME         0x0008
#define LSL32_ATTR_DIR            0x0010
#define LSL32_ATTR_ARCHIVE        0x0020

#define LSL32_DELETE_FILE            0
#define LSL32_REMOVE_DIR             1

////////////////////////////////////////////////////////////////////////////////
//
// Error-codes from LasalOS
//
////////////////////////////////////////////////////////////////////////////////
#define LSLOS_ERROR_GENERAL                     0xA0008013L			// General Error, not really specified
#define LSLOS_FILE_ERROR_GENERAL                0xA0010000L			// General File Error, not really specified
#define LSLOS_ERROR_INVALID_FILENAME            0xA0018003L			// The filename, directory name, or volume label syntax is incorrect.
#define LSLOS_ERROR_DRIVE_NOT_FOUND             0xA0018004L			// The system cannot find the drive specified.
#define LSLOS_ERROR_FILE_NOT_FOUND              0xA0018009L			// The system cannot find the file specified.
#define LSLOS_ERROR_ACCESS_DENIED               0xA0018010L			// Access is denied.
#define LSLOS_ERROR_PATH_NOT_FOUND              0xA0018013L			// The system cannot find the path specified.
#define LSLOS_ERROR_DISK_FULL                   0xA0018016L			// There is not enough space on the disk.
#define LSLOS_ERROR_MEDIA_CHANGED               0xA001801AL			// The media in the drive may have changed.
#define LSLOS_ERROR_NOT_READY                   0xA001801DL			// The device is not ready.
#define LSLOS_ERROR_WRITE_PROTECT               0xA001801EL			// The media is write protected.
#define LSLOS_ERROR_SYSTEM_OS					0xA0019000			// Base for OS (Salamander) Error

// Routing
#define LASAL32_ADDROUTETIMEOUT                 500000  // This additional timeout is valid for routed communication [ms]
                                                        // The Echo Request Command does not use this (for measurement!)
#define LASAL32_MAXHOPS 10

//Traceroute Interfacetypes
#define LASAL32_INTERFACETYPE_TCP 0
#define LASAL32_INTERFACETYPE_CAN 1
#define LASAL32_INTERFACETYPE_LOOP 2
#define LASAL32_INTERFACETYPE_ROOT 3
#define LASAL32_INTERFACETYPE_UNKNOWN 255

#pragma pack(push, 1)
typedef struct 
{
  uint8_t station;
  uint8_t hop;
  uint8_t type;
  uint8_t state;
  uint32_t time;
} LSL32_T_TRACERECORD;




// Format

typedef struct
{
  char DeviceName[32];

#define LSL32_FORMAT_PROGRESS_READY   0   // READY, ready to format the drive
#define LSL32_FORMAT_PROGRESS_BUSY    1   // BUSY,  format in progress
#define LSL32_FORMAT_PROGRESS_DONE    2   // DONE,  format finished successfully
#define LSL32_FORMAT_PROGRESS_ERROR   3   // ERROR, format finished not successfull

  uint32_t Total;
  uint32_t Completed;
  uint32_t Status;

} LSL32_FORMAT_PROGRESS_INFO;

typedef int32_t __cdecl CB_FORMAT_FUNCTYPE(LSL32_FORMAT_PROGRESS_INFO * pFormatProgressInfo);

// CheckDisk
#define LSL32_CHKDSK_OPTION_CORRECT   0x01

typedef int32_t __cdecl CB_CHKDSK_FUNCTYPE(char * strProgressInfo, uint32_t ProgressInfoLen);


// DriveList

// DriveList Options
#define DRIVELIST_OPT_MOUNTED         0x01
#define DRIVELIST_OPT_MOUNTSTATE      0x02
#define DRIVELIST_OPT_TYPE            0x04
#define DRIVELIST_OPT_DRIVER          0x08

// General Info (Type, Mounted?)
#define DRIVELIST_FLOPPY              0x00000001    // 00000000 00000000 00000000 00000001
#define DRIVELIST_FDISK               0x00000002    // 00000000 00000000 00000000 00000010
#define DRIVELIST_MOUNTED             0x00000004    // 00000000 00000000 00000000 00000100

#define DRIVELIST_GI_MASK             0x00000007    // 00000000 00000000 00000000 00000111

// Mountstate
#define DRIVELIST_MS_INITIALIZED      0x00000100    // 00000000 00000000 00000001 00000000
#define DRIVELIST_MS_MOUNTED          0x00000200    // 00000000 00000000 00000010 00000000
#define DRIVELIST_MS_ACCESSIBLE       0x00000400    // 00000000 00000000 00000100 00000000
#define DRIVELIST_MS_HASFILESYSTEM    0x00000800    // 00000000 00000000 00001000 00000000

#define DRIVELIST_MS_MASK             0x00000F00    // 00000000 00000000 00001111 00000000

// Driver
#define DRIVELIST_DRV_FLOPPY          0x00010000    // 00000000 00000001 00000000 00000000
#define DRIVELIST_DRV_IDE             0x00020000    // 00000000 00000010 00000000 00000000
#define DRIVELIST_DRV_USB             0x00030000    // 00000000 00000011 00000000 00000000
#define DRIVELIST_DRV_CME221          0x00040000    // 00000000 00000100 00000000 00000000
#define DRIVELIST_DRV_SMARTMEDIA      0x00050000    // 00000000 00000101 00000000 00000000
#define DRIVELIST_DRV_UDRAM           0x00060000    // 00000000 00000110 00000000 00000000

#define DRIVELIST_DRIVER_MASK         0x00070000    // 00000000 00000111 00000000 00000000

//==========================================================================================
// previous CpRegs.h
//==========================================================================================


// LASAL - Debug - API
// CPU Registers
typedef struct CP_REG
{
   uint32_t rEDI;  // 12
   uint32_t rESI;  // 16
   uint32_t rEBP;  // 20
   uint32_t rESP;  // 24
   uint32_t rEBX;  // 16
   uint32_t rEDX;  // 20
   uint32_t rECX;  // 24
   uint32_t rEAX;  // 28
   uint32_t rEIP;  // 00
   uint32_t  rCS;  // 04
   uint32_t rEFL;  // 08
   uint32_t  rSS;  // 44
   uint32_t  rGS;  // 48
   uint32_t  rFS;  // 52
   uint32_t  rES;  // 56
   uint32_t  rDS;  // 60
}CP_REG;

// LASAL - Debug - API
// CPU Registers new
typedef struct CP_REGextend
{
   uint32_t rEDI;  // 12
   uint32_t rESI;  // 16
   uint32_t rEBP;  // 20
   uint32_t rESP;  // 24
   uint32_t rEBX;  // 16
   uint32_t rEDX;  // 20
   uint32_t rECX;  // 24
   uint32_t rEAX;  // 28
   uint32_t rEIP;  // 00
   uint32_t  rCS;  // 04
   uint32_t rEFL;  // 08
   uint32_t  rSS;  // 44
   uint32_t  rGS;  // 48
   uint32_t  rFS;  // 52
   uint32_t  rES;  // 56
   uint32_t  rDS;  // 60
	 uint32_t rEIPr;  // 64 realtiv to modul
	 uint32_t mID;    // 68 modul ID 
}CP_REGextend;

typedef struct ExPrjStatus
{
    char MsgCounter;
    char Dummy1;
    char Dummy2;
    char Dummy3;
}ExPrjStatus;

// LASAL - Debug - API
// Project info 
typedef struct PrjHeader
{
   uint32_t Prjchk; 
   uint32_t ModEnabled;
   ExPrjStatus Status;
   char  PrjName[64];
}PrjHeader;


// LASAL - Debug - API
// Modul info 
typedef struct ModHeader
{
   uint32_t ID; 
   uint32_t ModChk;
   uint32_t ModStart; 
}ModHeader;

typedef struct ModHeaderReq
{
  uint32_t Id;
  uint8_t Enable;
}ModHeaderReq;

/* Wu 25.04.2012	Rauskommentiert da es im Code nicht mehr verwendet wird 
falls es noch gebraucht wird Wu bescheidgeben. An sonsten wird es in den zukünftigen Versionen eleminiert
typedef struct BpLst
{
	uint32_t PRGoffset1;
	uint32_t PRGoffset2;
	uint32_t PRGoffset3;
	uint32_t PRGoffset4;
	uint32_t Status;
	uint32_t Control;
	uint32_t ModulID1;
	uint32_t Offset1;
 	uint32_t ModulID2;
	uint32_t Offset2;	
	uint32_t ModulID3;
	uint32_t Offset3;	
	uint32_t ModulID4;
	uint32_t Offset4;	
}BpLst;
*/


// LASAL - Debug - API
// Awl Breakpoint info 
typedef struct AWLBPINFO
{
	CP_REGextend CpRegEx;	// Cpu Register
	uint32_t	     StackLen;	// Größe des nachfolgenden Arrays
	uint8_t	     Stack[1];	// variables Array (Größe = StackLen)
} AWLBPINFO;

typedef struct BPEXTEND_SET_TYPE
{
  uint16_t sizeofheader;  // Größe der Struktur (ohne nachfolgenden Code)
  uint8_t  bpnum;          // Breakpoint Nr.
  uint32_t modid;          // Modul Nr.
  uint32_t offset;         // Breakpoint Adresse
  uint8_t  tobp;           // Type of Breakpoint
  int32_t  stackoffset;    // Offset des Stackbereichs (bezogen auf Basepointer)
  uint32_t stacksize;      // Größe des Stackbereichs, den das Lasal-OS zwischenspeichert
  uint32_t counter;        // Counter, nach wievielen Durchläufen angehalten wird
  uint32_t codelength;     // Länge des Codes (für bed.Bp), der auf diese Struktur folgt
}BPEXTEND_SET_TYPE;

typedef struct BPEXTEND_SET_TYPE_V2
{
  uint16_t sizeofheader;  // Größe der Struktur (ohne nachfolgenden Code)
  uint8_t  bpnum;          // Breakpoint Nr.
  uint32_t modid;          // Modul Nr.
  uint32_t offset;         // Breakpoint Adresse
  uint8_t  tobp;           // Type of Breakpoint
  int32_t  stackoffset;    // Offset des Stackbereichs (bezogen auf Basepointer)
  uint32_t stacksize;      // Größe des Stackbereichs, den das Lasal-OS zwischenspeichert
  uint32_t counter;        // Counter, nach wievielen Durchläufen angehalten wird
  uint32_t codelength;     // Länge des Codes (für bed.Bp), der auf diese Struktur folgt
  uint8_t  lenx;           // Länge der Adresse (Datenbreakpoint) .. ab OS 5.22
}BPEXTEND_SET_TYPE_V2;

typedef struct BPEXTEND_SET_TYPE_V3
{
  uint16_t sizeofheader;  // Größe der Struktur (ohne nachfolgenden Code)
  uint8_t  bpnum;          // Breakpoint Nr.
  uint8_t  tobp;           // Type of Breakpoint
  uint32_t modid;          // Modul Nr.
  uint32_t offset;         // Breakpoint Adresse
  int32_t  stackoffset;    // Offset des Stackbereichs (bezogen auf Basepointer)
  uint32_t stacksize;      // Größe des Stackbereichs, den das Lasal-OS zwischenspeichert
  uint32_t counter;        // Counter, nach wievielen Durchläufen angehalten wird
  uint32_t codelength;     // Länge des Codes (für bed.Bp), der auf diese Struktur folgt
  uint8_t  lenx;           // Länge der Adresse (Datenbreakpoint) .. ab OS 5.22
  uint32_t action;         // ab V3 (1.1.79)
}BPEXTEND_SET_TYPE_V3;

typedef struct BPEXTEND_GET_INFO
{
  uint16_t sizeofheader;  // Größe der Struktur
  uint8_t bpnum;          // Breakpoint Nummer (0..3)
  uint8_t tobp;           // 76543210
                                // ......xx :  00=Instruction Breakpoint
                                //             01=Instruction Breakpoint AWL
                                //             10=Datenbreakpoint Read
                                //             11=Datenbreakpoint Read+Write
                                // ...xxx...:  res. (000)
                                // ..x..... :  1=Stack für AWL-Breakpoint vorhanden
                                // .x...... :  1=Code für bedingten Breakpoint vorhanden
                                // x....... :  0=Breakpoint nicht gesetzt
                                //          :  1=Breakpoint gesetzt
  union {
    struct {                    // Instruction Breakpoint:
      uint32_t modulid;    //  Modul-ID
      uint32_t modulofs;   //  Breakpoint Adresse - Offset im Modul
    };
    struct {                    // Daten Breakpoint
      uint32_t addr;       //  Adresse des Datenbreakpoints
      uint8_t len;        //  Länge des Datenbreakpoints
    };
  };
  uint32_t counter;        // aktueller Counter (verbleibende Anzahl von Durchläufen, bis Breakpoint aktiviert wird)
  uint32_t stacklength;    // Größe des Stacks beim AWL-Breakpoint
  int32_t  stackoffset;    // Stackoffset beim AWL-Breakpoint
  uint32_t codecrc32;      // Checksum des Codes für bedingten Breakpoint
}BPEXTEND_GET_INFO;
  
typedef struct BPEXTEND_GET_INFO_SINGLE
{
  uint8_t tobp;           // 76543210
                                // ......xx :  00=Instruction Breakpoint
                                //             01=Instruction Breakpoint AWL
                                //             10=Datenbreakpoint Read
                                //             11=Datenbreakpoint Read+Write
                                // ...xxx...:  res. (000)
                                // ..x..... :  1=Stack für AWL-Breakpoint vorhanden
                                // .x...... :  1=Code für bedingten Breakpoint vorhanden
                                // x....... :  0=Breakpoint nicht gesetzt
                                //          :  1=Breakpoint gesetzt
  union {
    struct {                    // Instruction Breakpoint:
      uint32_t modulid;    //  Modul-ID
      uint32_t modulofs;   //  Breakpoint Adresse - Offset im Modul
    };
    struct {                    // Daten Breakpoint
      uint32_t addr;       //  Adresse des Datenbreakpoints
      uint8_t len;        //  Länge des Datenbreakpoints
    };
  };
  uint32_t counter;        // aktueller Counter (verbleibende Anzahl von Durchläufen, bis Breakpoint aktiviert wird)
  uint32_t stacklength;    // Größe des Stacks beim AWL-Breakpoint
  int32_t  stackoffset;    // Stackoffset beim AWL-Breakpoint
  uint32_t codecrc32;      // Checksum des Codes für bedingten Breakpoint
}BPEXTEND_GET_INFO_SINGLE;


//==========================================================================================
// Comlink Definitionen
//==========================================================================================

typedef struct ComRegData
{
  uint32_t   LASALID;   // the identifier you get at I_GETOBJ
  uint16_t channel;   // nobody is using this 
  uint16_t VarPos;    // position 
  uint16_t uiTIME;    // updatetime in ms
  uint32_t   VarlistID; // from LSE a number give back at callback (not interpreted)
}ComRegData;                // you can write a value you want  

typedef struct RESULTS
{
    uint16_t uiLng;
    uint8_t aData[256]; 
}RESULTS;

typedef struct _D2LSE
{ 
	uint32_t varlistID;
	int16_t uiOffs;
	int32_t Data;
} D2LSE;

typedef struct SRegisterI386
{
	uint32_t rEDI;  // 12
	uint32_t rESI;  // 16
	uint32_t rEBP;  // 20
	uint32_t rESP;  // 24
	uint32_t rEBX;  // 16
	uint32_t rEDX;  // 20
	uint32_t rECX;  // 24
	uint32_t rEAX;  // 28
	uint32_t rEIP;  // 00
	uint32_t  rCS;  // 04
	uint32_t rEFL;  // 08
	uint32_t  rSS;  // 44
	uint32_t  rGS;  // 48
	uint32_t  rFS;  // 52
	uint32_t  rES;  // 56
	uint32_t  rDS;  // 60
} SRegisterI386;

typedef struct SRegisterI386Float
{
	SRegisterI386 standardRegs;
	uint32_t dFloat[8][2];	// 8 * 8Byte
	uint16_t ctrl;
	uint16_t stat;
	uint16_t tags;
	uint16_t dummy;
} SRegisterI386Float;

typedef struct SRegisterPPC
{
	uint32_t r[32];
	uint32_t pc;
	uint32_t msr;
	uint32_t cr;
	uint32_t xer;
	uint32_t ctr;
	uint32_t lr;
} SRegisterPPC;

typedef struct SRegisterPPCFloat
{
  SRegisterPPC standardRegs;
	uint32_t f[32][2];
} SRegisterPPCFloat;

typedef struct SRegisterARM
{
  uint32_t R0;  // 12
  uint32_t R1;  // 16
  uint32_t R2;  // 20
  uint32_t R3;  // 24
  uint32_t R4;  // 16
  uint32_t R5;  // 20
  uint32_t R6;  // 24
  uint32_t R7;  // 28
  uint32_t R8;  // 00
  uint32_t R9;  // 04
  uint32_t R10;  // 08
  uint32_t R11;  // 44
  uint32_t R12;  // 48
  uint32_t SP;  // 52
  uint32_t LR;  // 56
  uint32_t PC;  // 60
  uint32_t CPSR;
  uint32_t SPSR;
} SRegisterARM;

typedef struct SRegisterARMFloat
{
  SRegisterARM standardRegs;
    uint32_t f[32];
    uint32_t fpsid;
    uint32_t fpscr;
    uint32_t fpexc;
} SRegisterARMFloat;


typedef struct SRegisterCPU
{
  uint32_t lWasHabIchBekommenFlag;
  uint32_t lRelativeIP;
  uint32_t lModuleIP;

  union 
  {
    SRegisterI386 cpu386;
    SRegisterI386Float cpu386Float;
    SRegisterPPC cpuPPC;
    SRegisterPPCFloat cpuPPCFloat;
    SRegisterARM cpuARM;
    SRegisterARMFloat cpuARMFloat;
  };
} SRegisterCPU;

typedef struct CP_REGextendPPC
{
  SRegisterPPC standardRegs;
  uint32_t rEIPr;  // realtiv to modul
  uint32_t mID;    // modul ID 
} CP_REGextendPPC;

typedef struct CP_REGextendARM
{
  SRegisterARM standardRegs;
  uint32_t rEIPr;  // realtiv to modul
  uint32_t mID;    // modul ID 
} CP_REGextendARM;

typedef struct AWLBPINFOPPC
{
  CP_REGextendPPC CpRegEx;
  uint32_t           StackLen;
  uint8_t            Stack[ 1 ];
} AWLBPINFOPPC;

typedef struct AWLBPINFOARM
{
  CP_REGextendARM CpRegEx;
  uint32_t           StackLen;
  uint8_t            Stack[ 1 ];
} AWLBPINFOARM;

typedef struct _SAWLBPINFOCPU
{
  union
  {
    AWLBPINFO pAWLBPcpu386;
    AWLBPINFOPPC pAWLBPcpuPPC;
    AWLBPINFOARM pAWLBPcpuARM;
  };
  //SRegisterCPU sCpuRegs;
	uint32_t	     StackLen;	// Größe des nachfolgenden Arrays
	uint8_t	     Stack[ 1 ];	// variables Array (Größe = StackLen)
} SAWLBPINFOCPU;

		// instruction set for interpreter
typedef enum	
{
	I_GET_OBJ,             // name -> handle
	I_GET_OBJ_CLS,         // name -> handle and class name
	I_READ_CLASS,          // index -> class info
	I_WRITE,               // write to server
	I_WRITE_TO_CLNT,       // write to the server connected to a client
	I_READ_OBJECT,         // class header, index -> object info
	I_READ_CHANNEL,	       // read the channel
	I_READ_METHOD,         // class header, index -> method info
	I_READ,                // handle -> read server channel
	I_STARTPROG,           // program no, label no -> start parallel
	I_RUNPROG,             // program no, label no -> start sequential
	I_CMD,                 // handle, cmd, paras -> execute method
	I_DELAY,               // time -> wait till time elapsed
	I_NOP,                 // ==== not used   
	I_LBL,                 // ==== not used
	I_GOTO,                // goto label
	I_ENDPROG,             // terminates the current ipr program
	I_CALL,                // subroutine call
	I_RET,                 // return from subroutine
	I_FUNCTION,            // ======= not used
	I_ENDFUNCTION,         // ======= not used
	I_INC,                 // handle -> increments data image
	I_DEC,                 // handle -> decrements data image
	I_START_LOAD_PR,       // prepare OPsystem for new program to load
	I_LOAD_PROG,           // load new program code
	I_COMMENT,             // line is not executed
	I_JMPIF,               // jump if condition is true
	I_WAITFOR,             // wait until condition is true
	I_SETFORTIME,          // ======= not used
	I_GETPROG,             // load program code from the PLC
	I_GETPROGSTATE,        // program no -> state
	I_CHECK_FOR_LOAD,      // check if new progs are to load
	I_GET_DESC_CRC,        // CRC of all LASAL-descriptor lists in the PLC
	I_READ_CONNECT,		   // get the client connection
	I_GET_CLS,			   // get the class name from an object's address
	I_GET_OBJ_NAME,		   // get object name from class name and object addr
	I_READ_CLT,			   // call read method of connected server
	I_STOPPROG,				// stops a interpreter program
	I_GET_PROGNR,			// get programnumber of programname
	I_GET_ACT_OFFSET,		// get the actual offset of the program
	I_GET_TRIGGER_COUNT,	// get the count of the trigger
	I_GET_VERSION,			// returns the loader version
	I_NEW_OBJ,				// creates an object of a class
	I_CONNECT,				// connect 2 channels
	I_SET_CYCLE,			// set real- or cyclic time
	I_DEL_OBJ,				// delete an object, remove connections
	I_STOP_IPR_CHEK_FOR_LOAD, //Stop all Interpreterprogs and check for load
	I_REGISTER,				// zum Einloggen und als fortlaufende Bedarfs-Mitteilung
	I_RELEASE,				// beim Offline-Gehen wird der Kommunikationspuffer freigegeben
	I_TRY_SOFTLOAD_IPR,		// Try to load an program from the temporary memory in a soft mode
	I_END_SOFTLOAD_IPR,		// Kill the softload
	I_GET_CFL_CYCLE,		// Get the Cycle time of the CheckForLoad
	I_GET_CALLED_IPR,		// Liefert die Nummer des Interpreters der von diesem Ipr aufgerufen wurde
	I_GET_CALLED_FROM,		// Bringt die Nummer des Iprs von dem dieser Ipr aufgerufen wurde
	I_INIT,					// calls the init-method of a server or an object
	I_GET_CLS_BY_NAME,		// gets a class header pointer for a given class name
	I_GET_NXT_DERIVED,		// get next derived class of a base class
	I_LOCK,                 // 1. KommKanal sperren für ein Tool
	I_UNLOCK,               // 1. KommKanal wieder freigeben
	I_LSLCMD,
	I_CMD_DEBUGIP,      	// gleich wie I_CMD, nur wird für die Serveradresse der this-Pointer (DebugIp Objekt) verwendet
	I_CREATE_PROG,  //*** ++pr:test ***
	I_LOAD_PROG2,			// wie I_LOAD_PROG jedoch ohne den Fehler mit der falschen Länge bei der Checksummenberechnung
	I_START_IPR,    //*** ++pr:test ***
	I_GET_GLOBAL_ADDR,
	I_GET_DATA,
	I_GETPROGSTATE_ALL,        // program state
	I_SET_DATA,
	I_GET_STACKINFO,
	I_ILLEGAL      //
}INSTRSET;

typedef enum 
{
	READY,		// interpreter command processed
	ERROR_IP,		// i.e. wrong parameters
	ERROR_IP_BUSY,	// i.e. stopping movement
	BUSY,			// interpreter command processing
	QUIT,
	STOP_BP,
	SINGLESTEP
}IPRSTATES;

#pragma pack(pop)

//==========================================================================================
// Defines für Runtime Modul Download Status
//==========================================================================================

#define RMDLSLST_NOP        0x00
#define RMDLSLST_WAIT       0x01
#define RMDLSLST_DONE       0x02
#define RMDLSLST_PRELINK    0x03
#define RMDLSLST_LINK       0x04
#define RMDLSLST_LINKDONE   0x05

#define RMDLSLST_NOPROJECT       0x80
#define RMDLSLST_MEMRANGE        0x81
#define RMDLSLST_MEMMAP          0x82
#define RMDLSLST_NOMEM           0x83
#define RMDLSLST_ANYERR          0x84
#define RMDLSLST_LNK_MODUL       0x85
#define RMDLSLST_LNK_MULTMODID   0x86
#define RMDLSLST_LNK_MODNOTFOUND 0x87
#define RMDLSLST_LNK_I_VAR       0x88
#define RMDLSLST_LNK_FIX_TYPE    0x89
#define RMDLSLST_LNK_FIX_UNRES   0x8A
#define RMDLSLST_PRELNK_API      0x90
#define RMDLSLST_LOADER_PRELINK  0x91
#define RMDLSLST_LOADER_APPLY    0x92

//==========================================================================================
// Defines für CPU Typen
//==========================================================================================
#define LSL_CPUMASK       0x000000fful
#define LSL_ISINTEL       0x00ul
#define LSL_ISPPC         0x01ul
#define LSL_ISARM         0x02ul

//==========================================================================================
// Defines für Platform Typen
//==========================================================================================
#define LSL_PLATFORMMASK  0x0000ff00ul
#define LSL_LASALOS       0x00000000ul
#define LSL_WINCE         0x00000100ul

//==========================================================================================
// Defines für (un)supported Features
//==========================================================================================
#define LSL_NO_DATABP     0x00010000ul
#define LSL_NO_FPU		  0x00020000ul
#define LSL_OS_SALAMANDER 0x00040000ul

#define LSL_WANTTOHAVE_FPU  0x00000001ul


//==========================================================================================
// some Callbacks
//==========================================================================================

#define CBRETURN_CONTINUE		0		// Continue transfer
#define CBRETURN_ABORT			1		// Abort Transfer 

#define CBSTATE_INIT			0		// First init call
#define CBSTATE_STATE			1		// data state
#define CBSTATE_FINISHED		2		// transfer finished
#define CBSTATE_ERROR			3		// transfer error
#define CBSTATE_CANCELED		4		// transfer canceled
#define CBSTATE_STATE_BEGIN		5		// Value = count of copy blocks

typedef uint32_t __cdecl CB_FUNCTYPE2(void *,uint32_t val, uint32_t state); // must be "__cdecl" because of FAR PASCAL definitions
typedef uint32_t __cdecl CB_FUNCTYPE(uint32_t); // must be "__cdecl" because of FAR PASCAL definitions

typedef void CAN_CB_FUNCTYPE (D2LSE *d2lse);

//==========================================================================================
// CommandString Status
//==========================================================================================

typedef struct CSTRSTAT_INFO {
    uint16_t Status;
    uint32_t retval;
} CSTRSTAT_INFO, *PCSTRSTAT_INFO;

#define CSTRSTAT_NoActivity   0   // kein Kommando ausständig
#define CSTRSTAT_InQueue      1   // Kommando befindet sich in der Mailbox
#define CSTRSTAT_InProgress   2   // Kommando wird gerade ausgeführt
#define CSTRSTAT_Ended        3   // Kommando wurde ausgeführt, retval ist gültig
#define CSTRSTAT_ExecError    4   // Kommando konnte nicht gestartet werden


//==========================================================================================
// Defines für General Status Abfrage
//==========================================================================================

#define GENSTAT_NONE          0x00 
#define GENSTAT_RMDLSLST      0x01

typedef struct 
{
  uint16_t Type;
  uint8_t Value[1];
} GENSTAT_RESPONSE, *PGENSTAT_RESPONSE;

// Kommunikationsarten
enum
{
	COMMUNICATION_NONE      = 0x0,     // Keine Kommunikation
	COMMUNICATION_V24       ,     // Kommunikation ueber V24
	COMMUNICATION_CAN       ,     // Kommunikation ueber CAN-Bus
	COMMUNICATION_TCP       ,     // Kommunikation ueber TCP/IP
	COMMUNICATION_MODEM     ,     // Kommunikation ueber Modem
	COMMUNICATION_CANUSB    ,     // Kommunikation ueber das Lawicel CANUSB Interface
	COMMUNICATION_CANUSB_FT ,     // Kommunikation ueber das Lawicel CANUSB Interface (mittels FTD2XX Treiber Aufrufen)
	COMMUNICATION_VARAN32   ,     // Kommunikation ueber VARAN32.DLL
	// Achtung BITTE busTypeRequest und busTypeRequest2 anpassen
	COMMUNICATION_LAST	// Muss immer der Letzte sein
};

#define COMMUNICATION_SEPERATOR ';' // Trennzeichen für Routing
#define COMMUNICATION_ROUTE     "ROUTE"

// Bitmasken für LslGetModulInfoIDList
#define MODULINFO_CHK           0x01
#define MODULINFO_START         0x02

#pragma pack(push, 1)

typedef struct GETOBJINFO_STR {
  int32_t fcn_rc;            // Returncode der LSLOBJ_GetObjectInfo-Funktion:
                          //   0  .. o.k.
                          // <>0  .. Fehler:
                          //          -1 = keine Applikation
                          //          -5 = not found
  uint8_t lslobj_info[1];    // Object-Info Struktur
} GETOBJINFO_STR;

typedef struct
{
  uint32_t ulHeaderSize;       // size of header
  uint32_t ulTaskIDListSize;   // size of task id list
  uint32_t ulDataSize;         // size of data
  uint32_t ulBufferSize;       // size of header + task id list + data
} MEAS_RXBUF_HEADER;


typedef struct _DDE_DATIM
{
   uint32_t Second2:5;
   uint32_t Minute:6;
   uint32_t Hour:5;
   uint32_t Day:5;
   uint32_t Month:4;
   uint32_t Year1980:7;
} _DDE_DATIM;

typedef struct _DDE_INFO
{
   char           FileName[8];
   char           Extension[3];
   uint8_t           Attributes;
   uint8_t           NTReserved;
   uint8_t           CreateTimeTenthSecond; // range 0..199, not used
   _DDE_DATIM     CreateDateTime;
   uint16_t           LastAccessDate;        // not used
   uint16_t           FirstClusterHi;        // FAT-32 only
   _DDE_DATIM     DateTime;              // of last modification
   uint16_t           FirstCluster;
   uint32_t          FileSize;
} _DDE_INFO;

typedef struct LSL_FILE_INFO
{
	char			FileName[8]; 
	char			Extension[3]; 
	uint8_t		cAttributes; 
	_DDE_DATIM		dtDateTime; 
	uint32_t		lFileSize; 
} LSL_FILE_INFO;

#pragma pack(pop)

typedef enum
{
	MI_CODE,        // 0 - code area
	MI_DATA,        // 1 - data area
	MI_OS_HEAP,     // 2 - os heap
	MI_USER_HEAP,   // 3 - user heap
	MI_SRAM_USER,   // 4 - sram user area
	MI_SRAM_RETAIN, // 5 - sram retain area
	MI_SRAM_RET_RAM,// 6 - sram retain ram area
	MI_SRAM_SYS,    // 7 - sram system area (Kernel-Log,..)
	MI_SRAM_COMPL,  // 8 - sram complete area (user + retain + system)
}E_MEM_INFO_TYPE;

typedef struct
{
	E_MEM_INFO_TYPE	type;
	uint32_t		start;		// start address
	uint32_t		size;			// length of memory area
	uint32_t		used;			// used data length
	uint32_t		attrib;		// attribute of the memeory area;
}S_MEM_INFO;

#define MI_ATTRIB_START   0x0001  // struct member start is valid
#define MI_ATTRIB_LENGTH  0x0002  // struct member length is valid
#define MI_ATTRIB_USED    0x0004  // struct member used is valid

/////////////////////////////////////////////////////////////////////////////
// Varan32
#define LSL_VARAN_MAX_PORTNAME		256	// max. length of Port Name
#define LSL_VARAN_MAX_PORTDESC		512	// max. length of Port Description
#define LSL_VARAN_MAX_DEVICE		256	// max. length of Device Name

// available Port types
typedef enum { ELslVaran32PortTypePCV, ELslVaran32PortTypeNET } ELslVaran32PortType;
typedef struct SLslVaran32PortInfo
{
	uint32_t cbSize;
	ELslVaran32PortType	ePortType;
	char szName[LSL_VARAN_MAX_PORTNAME];	// PCV01, PCV02, ..., LAN-Verbindung, LAN-Verbindung1, ...
	char szDesc[LSL_VARAN_MAX_PORTDESC];	// PCV same as Name, LAN-Verbindung = Intel...
	char szDevice[LSL_VARAN_MAX_DEVICE];	// Internal Device Name
} SLslVaran32PortInfo;

typedef void (__cdecl *WFTECALLBACK)(void *pData, uint32_t uiState, uint32_t nClients);
typedef void (__cdecl *FWUpdateWriteCallback)(void *pData, int32_t iWritten, int32_t iTotal);
typedef int32_t (__cdecl *FPRPF_CALLBACK)(const uint8_t* pData, uint32_t uiLen, void* pUser);





#ifndef LASAL32_EXCLUDE_EXPFUNCS
#ifdef __cplusplus
extern "C"
{
#endif

// GetDllVersion: Bringe DLL-Versionsnummer
uint32_t LASAL32_EXPORTS LslGetDllVersion(void);
#ifndef WINCE
uint32_t LASAL32_EXPORTS GetDllVersion(void);
#endif
const char * LASAL32_EXPORTS LslGetDllInfo(void);

// Get a handle to a OCB (online control block)
int32_t LASAL32_EXPORTS OcbOpen();
// Release the OCB
void LASAL32_EXPORTS OcbClose(int32_t ocbNum);

// GetBusType: Bringe die momentan eingestellte Kommunikationsart
uint32_t LASAL32_EXPORTS GetBusType(void);
uint32_t LASAL32_EXPORTS GetBusTypeH(int32_t ocbNum);

//--- Online schalten --------------------------------------------------------------------
//
//->      szPort: "LPT1" ... CAN-Adapter an LPT1
//                "LPT2" ... CAN-Adapter an LPT2
//                "COM1" ... RS232 ueber COM1
//                "COM2" ... RS232 ueber COM2
//                "COM3" ... RS232 ueber COM3
//                "COM4" ... RS232 ueber COM4
//                "TCP:nr.nr.nr.nr" ... TCP/IP mit Angabe der IP-Adresse
//
//     die restlichen Parameter sind nur bei CAN-Betrieb notwendig (sonst 0 übergeben)!
//->   uBaudrate: 0 = 615 KBaud
//                1 = 500 KBaud
//                2 = 250 KBaud
//                3 = 125 KBaud
//                4 = 100 KBaud
//                5 =  50 KBaud
//                6 =  20 KBaud
//
//->  uPcStation: 0-30 (eigen Stationsnummer)
//-> uSpsStation: 0-30 (auf der SPS eingestellte CAN-Stationsnummer)
//->   uAutoInit: 1 = automatische Neuinitialisierung bei Störung (z.B: durch ein Dongle)
// Hinweis: Zwischen 2 Aufrufen von Online() muß jedenfalls die Funktion Offline()
//            aufgerufen werden!

#define LSL_ONLINE_CAN_BAUD615K		0
#define LSL_ONLINE_CAN_BAUD500K		1
#define LSL_ONLINE_CAN_BAUD250K		2
#define LSL_ONLINE_CAN_BAUD125K		3
#define LSL_ONLINE_CAN_BAUD100K		4
#define LSL_ONLINE_CAN_BAUD50K		5
#define LSL_ONLINE_CAN_BAUD20L		6
#define LSL_ONLINE_CAN_BAUD1M		7

LSL_BOOL LASAL32_EXPORTS Online(const char* szComm, uint8_t uBaudRate, uint8_t uPcStation, uint8_t uSpsStation, uint8_t uAutoInit);
LSL_BOOL LASAL32_EXPORTS OnlineH(int32_t ocbNum, const char* szComm, uint8_t uBaudRate, uint8_t uPcStation, uint8_t uSpsStation, uint8_t uAutoInit);

LSL_BOOL LASAL32_EXPORTS OnlinePwd(const char* szComm, uint8_t uBaudRate, uint8_t uPcStation, uint8_t uSpsStation, uint8_t uAutoInit, const char *onlPwd);
LSL_BOOL LASAL32_EXPORTS OnlinePwdH(int32_t ocbNum, const char* szComm, uint8_t uBaudRate, uint8_t uPcStation, uint8_t uSpsStation, uint8_t uAutoInit, const char *onlPwd);

//--- Optionale Funktionalitäten beim Aufbau der Verbindung setzen ----------------------

typedef enum
{
	LSL_ONLINE_TCP_CANCEL_CONNECT_FLAG,	// Setzt eine Abbruchbedingung für das TCP_Connect Kommando (const volatile BOOL* const)
}E_ONLINE_OPTIONS;

LSL_BOOL LASAL32_EXPORTS OnlineOptions(void* pData, uint32_t dOption);
LSL_BOOL LASAL32_EXPORTS OnlineOptionsH(int32_t ocbNum, void* pData, uint32_t dOption);

//--- Die Pausenzeit zwischen zwei Packeten am Can-Bus ändern ----------------------------
// Fuer schnelle Datenuebertragung kann auch 1 gewaehlt werden (bis zu
// 20% schnellere Datenbuebertragung).
// Wenn es sich um eine exklusive Verbindung zwischen PC und nur einer SPS
// handelt, kann 'dPause' sogar auf 0 gesetzt werden (bis zu 40% schneller).
//
//-> dPause:  2 (2 ms) = default
LSL_BOOL LASAL32_EXPORTS SetPause(uint32_t dPause);
LSL_BOOL LASAL32_EXPORTS SetPauseH(int32_t ocbNum, uint32_t dPause);

//--- für bestimmte Befehle (z.b.Modul-Download) CAN-Pause ausschalten -------------------
//-> fOnOff: TRUE(=default) .. für bestimmte Befehle keine CAN-Pause einhalten
//           FALSE          .. für alle Befehle CAN-Pause einhalten
LSL_BOOL LASAL32_EXPORTS SetFaststore(LSL_BOOL fOnOff);
LSL_BOOL LASAL32_EXPORTS SetFaststoreH(int32_t ocbNum, LSL_BOOL fOnOff);


//--- Offline schalten -------------------------------------------------------------------
// Hinweis: auch wenn Online() fehlschlägt, muß danach Offline() aufgerufen werden
void LASAL32_EXPORTS Offline(void);
void LASAL32_EXPORTS OfflineH(int32_t ocbNum);

//--- Routing ----------------------------------------------------------------------------
//
LSL_BOOL LASAL32_EXPORTS LslSetRoute( uint8_t bUseRouting, uint8_t bToStation );
LSL_BOOL LASAL32_EXPORTS LslSetRouteH( int32_t ocbNum, uint8_t bUseRouting, uint8_t bToStation );
LSL_BOOL LASAL32_EXPORTS LslTraceRoute( uint8_t bToStation, void* pHopList, uint8_t* bHopListLen );
LSL_BOOL LASAL32_EXPORTS LslTraceRouteH( int32_t ocbNum, uint8_t bToStation, void* pHopList, uint8_t* bHopListLen );
LSL_BOOL LASAL32_EXPORTS LslEchoRequest( uint8_t bToStation, uint32_t dTimeout, uint8_t* bFromStation, uint8_t* bOk );
LSL_BOOL LASAL32_EXPORTS LslEchoRequestH( int32_t ocbNum, uint8_t bToStation, uint32_t dTimeout, uint8_t* bFromStation, uint8_t* bOk );
LSL_BOOL LASAL32_EXPORTS LslVEchoRequest( uint8_t bToStation, uint8_t* bFromStation, uint8_t* bOk );
LSL_BOOL LASAL32_EXPORTS LslVEchoRequestH( int32_t ocbNum, uint8_t bToStation, uint8_t* bFromStation, uint8_t* bOk );

//--- Online-Status abfragen -------------------------------------------------------------
//<- TRUE  = ONLINE
//   FALSE = OFFLINE
LSL_BOOL LASAL32_EXPORTS IsOnline(void);
LSL_BOOL LASAL32_EXPORTS IsOnlineH(int32_t ocbNum);

/*------------------------------------------------------------------------------
  SetMultiThreadSupport

  This function can be used to enable or disable the multithread-support for 
  the online-functions. When multithread-support is enabled, all online-
  functions are protected with a critical-section object.

  Disabling the multithread-support reduces the overhead for protecting the 
  online-functions, but then you have to ensure that no online-function is 
  called before any other online-function has finished !

  Initially the multithread-support is enabled.

  Parameters:

    val:    0 .. disable multithread-support
            1 .. enable multithread-support

------------------------------------------------------------------------------*/
void LASAL32_EXPORTS SetMultiThreadSupport(uint32_t val);

//--- Daten and die SPS senden -----------------------------------------------------------
//->    pData:  Puffer mit den zu sendenden Daten (Sendepuffer)
//-> wSegment:  Segmentadresse der Daten in der SPS (0 = default)
//->  wOffset:  Offsetadresse der Daten in der SPS
//              D0001   = 0x1000
//              D0001:H = 0x1001
//              D0002   = 0x1002
//              D0002:H = 0x1003
//              usw.
//->  wAnzahl:  Anzahl der zu sendenden Bytes
LSL_BOOL LASAL32_EXPORTS SetData(const void *pBuffer, uint32_t addr0, uint16_t nCount);
LSL_BOOL LASAL32_EXPORTS SetDataH(int32_t ocbNum, const void *pBuffer, uint32_t addr0, uint16_t nCount);

//--- Daten aus der SPS anfordern --------------------------------------------------------
//->    pData:  Puffer mit den zu empfangenden Daten (Epfangspuffer)
//-> wSegment:  Segmentadresse der Daten in der SPS (0 = default)
//->  wOffset:  Offsetadresse der Daten in der SPS
//              D0001   = 0x1000
//              D0001:H = 0x1001
//              D0002   = 0x1002
//              D0002:H = 0x1003
//              usw.
//->  wAnzahl:  Anzahl der zu empfangenden Bytes
LSL_BOOL LASAL32_EXPORTS GetData(void *pBuffer, uint32_t addr0, uint16_t nCount);
LSL_BOOL LASAL32_EXPORTS GetDataH(int32_t ocbNum, void *pBuffer, uint32_t addr0, uint16_t nCount);

//========================================================================================
// PG - Funktionen
//========================================================================================

//--- Befehl an die CPU senden -----------------------------------------------------------
// Moegliche Befehle:
// uCommand:    3...RESET CPU    (CPU in RESET)
//              4...RESTART CPU  (Programm in der CPU starten)
LSL_BOOL LASAL32_EXPORTS SetCommand(uint8_t uCommand);
LSL_BOOL LASAL32_EXPORTS SetCommandH(int32_t ocbNum, uint8_t uCommand);

//--- SetHardMode: CAN-Hardmode ein (keine Pause) oder aus (2ms Pause) -------------------
void LASAL32_EXPORTS SetHardMode(uint8_t uMode);
void LASAL32_EXPORTS SetHardModeH(int32_t ocbNum, uint8_t uMode);

LSL_BOOL LASAL32_EXPORTS GetChk(void* pChk);
LSL_BOOL LASAL32_EXPORTS GetChkH(int32_t ocbNum, void* pChk);
//--- Defines for ChkByType ------------
#define LSLMODTYPE_LOADER    0x00000001
#define LSLMODTYPE_APPL      0x00010000
LSL_BOOL LASAL32_EXPORTS GetChkByType(void* pChk, 
                         uint32_t modTypeMask,
                         uint32_t modTypeEq);
LSL_BOOL LASAL32_EXPORTS GetChkByTypeH(int32_t ocbNum, 
                          void* pChk, 
                          uint32_t modTypeMask,
                          uint32_t modTypeEq);
LSL_BOOL LASAL32_EXPORTS GetBpList(void *pBpList);
LSL_BOOL LASAL32_EXPORTS GetAwlBp( AWLBPINFO *pAwlBpInfo, uint32_t dwBufLen );
LSL_BOOL LASAL32_EXPORTS GetAwlBpH( int32_t ocbNum, AWLBPINFO *pAwlBpInfo, uint32_t dwBufLen );
LSL_BOOL LASAL32_EXPORTS SetBp(uint8_t nNr, uint16_t wAddress, uint16_t wCount);
LSL_BOOL LASAL32_EXPORTS SetBpH(int32_t ocbNum, uint8_t nNr, uint16_t wAddress, uint16_t wCount);
LSL_BOOL LASAL32_EXPORTS ClrBp(uint8_t nNr);
LSL_BOOL LASAL32_EXPORTS ClrBpH(int32_t ocbNum, uint8_t nNr);
LSL_BOOL LASAL32_EXPORTS SetRegister(uint8_t nIndex, uint32_t dValue);
LSL_BOOL LASAL32_EXPORTS SetRegisterH(int32_t ocbNum, uint8_t nIndex, uint32_t dValue);
LSL_BOOL LASAL32_EXPORTS SetRegisterEx(uint8_t nIndex, const void* pBuffer, uint16_t nCount );
LSL_BOOL LASAL32_EXPORTS SetRegisterExH(int32_t ocbNum, uint8_t nIndex, const void* pBuffer, uint16_t nCount );
LSL_BOOL LASAL32_EXPORTS GetCpuStatus(uint8_t *pStatus);
LSL_BOOL LASAL32_EXPORTS GetCpuStatusH(int32_t ocbNum, uint8_t *pStatus);
LSL_BOOL LASAL32_EXPORTS GetCpuStatus2(uint8_t *pStatus, uint8_t direct);
LSL_BOOL LASAL32_EXPORTS GetCpuStatus2H(int32_t ocbNum, uint8_t *pStatus, uint8_t direct);
LSL_BOOL LASAL32_EXPORTS GetAwlBpStatus(uint8_t *pAwlBpStatus);
LSL_BOOL LASAL32_EXPORTS GetAwlBpStatusH(int32_t ocbNum, uint8_t *pAwlBpStatus);
LSL_BOOL LASAL32_EXPORTS GetGenStatus( uint16_t Type, uint8_t *Buf, uint32_t BufSize, uint32_t *NumRead);
LSL_BOOL LASAL32_EXPORTS GetGenStatusH( int32_t ocbNum, uint16_t Type, uint8_t *Buf, uint32_t BufSize, uint32_t *NumRead);
LSL_BOOL LASAL32_EXPORTS LoadPrj(const void* pProg);
LSL_BOOL LASAL32_EXPORTS LoadPrjH(int32_t ocbNum, const void* pProg);
LSL_BOOL LASAL32_EXPORTS LoadPrjByType( const void* Prjname, 
                              uint32_t modTypeMask,
                              uint32_t modTypeEq);
LSL_BOOL LASAL32_EXPORTS LoadPrjByTypeH(int32_t ocbNum, 
                              const void* Prjname, 
                              uint32_t modTypeMask,
                              uint32_t modTypeEq);
LSL_BOOL LASAL32_EXPORTS LoadModul(const void* pProg, uint32_t wCount, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LoadModulH(int32_t ocbNum, const void* pProg, uint32_t wCount, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LoadModulRMD(const void* pProg, uint32_t nCount, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LoadModulRMDH(int32_t ocbNum, const void* pProg, uint32_t nCount, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LslLoadModulClsNameH(int32_t ocbNum, const void* pProg, uint32_t nCount, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LslLoadModulClsName(const void* pProg, uint32_t nCount, CB_FUNCTYPE* callback);

// 2007-08-06 Jimmy Add this 4 functions
LSL_BOOL LASAL32_EXPORTS LslLoadProjectSingleObjFileByTypeH(int32_t ocbNum, const char *lpProjectName, void *pData, uint32_t modTypeMask, uint32_t modTypeEq, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LslLoadProjectSingleObjFileByType(const char *lpProjectName, void *pData, uint32_t modTypeMask, uint32_t modTypeEq, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LslLoadProjectSingleObjFileH(int32_t ocbNum, const char *lpProjectName, void *pData, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LslLoadProjectSingleObjFile(const char *lpProjectName, void *pData, CB_FUNCTYPE* callback);

LSL_BOOL LASAL32_EXPORTS LoadEXEModul(const void* pProg, uint32_t wCount, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LoadEXEModulH(int32_t ocbNum, const void* pProg, uint32_t wCount, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LinkModules(void);
LSL_BOOL LASAL32_EXPORTS LinkModulesH(int32_t ocbNum);
LSL_BOOL LASAL32_EXPORTS GetLasalData(void* data);
LSL_BOOL LASAL32_EXPORTS GetLasalDataH(int32_t ocbNum, void* data);
LSL_BOOL LASAL32_EXPORTS LslClearSram();
LSL_BOOL LASAL32_EXPORTS LslClearSramH(int32_t ocbNum);
LSL_BOOL LASAL32_EXPORTS LslSetSysTraceH(int32_t ocbNum, uint32_t startCondition,
                                        uint32_t stopCondition,
                                        uint32_t typeMask);
LSL_BOOL LASAL32_EXPORTS LslSetSysTrace(uint32_t startCondition,
                           uint32_t stopCondition,
                           uint32_t typeMask);
LSL_BOOL LASAL32_EXPORTS LslClearSysTraceH(int32_t ocbNum);
LSL_BOOL LASAL32_EXPORTS LslClearSysTrace();
LSL_BOOL LASAL32_EXPORTS GetTraceEntries( uint32_t src_pos, 
                             uint8_t *pData, 
                             uint32_t len,
                             uint32_t *nread,
                             uint32_t *new_pos);
LSL_BOOL LASAL32_EXPORTS GetTraceEntriesH( int32_t ocbNum, uint32_t src_pos, 
                             uint8_t *pData, 
                             uint32_t len,
                             uint32_t *nread,
                             uint32_t *new_pos);
LSL_BOOL LASAL32_EXPORTS LslSetSysTraceBufSize(uint32_t bufSize);
LSL_BOOL LASAL32_EXPORTS LslSetSysTraceBufSizeH(int32_t ocbNum, uint32_t bufSize);
LSL_BOOL LASAL32_EXPORTS LslGetSysTraceBufSize(uint32_t *pBufSize, uint32_t *pMaxBufSize);
LSL_BOOL LASAL32_EXPORTS LslGetSysTraceBufSizeH(int32_t ocbNum, uint32_t *pBufSize, uint32_t *pMaxBufSize);
LSL_BOOL LASAL32_EXPORTS LslSetAddTvMs(uint32_t addTv_ms);
LSL_BOOL LASAL32_EXPORTS LslSetAddTvMsH(int32_t ocbNum, uint32_t addTv_ms);
LSL_BOOL LASAL32_EXPORTS LslSetEnvParam(const char *szParam);
int32_t LASAL32_EXPORTS LslSetDbgLevel(int32_t level);
int32_t LASAL32_EXPORTS LslSetDbgLevelEx(int32_t level, uint32_t dwFlags);

LSL_BOOL LASAL32_EXPORTS IsModTypeSupportedByOs();
LSL_BOOL LASAL32_EXPORTS IsModTypeSupportedByOsH(int32_t ocbNum);
LSL_BOOL LASAL32_EXPORTS LslSetDfltModTypeParamsH(int32_t ocbNum, 
                                     uint32_t modTypeMask,
                                     uint32_t modTypeEq);
LSL_BOOL LASAL32_EXPORTS LslSetDfltModTypeParams(uint32_t modTypeMask, uint32_t modTypeEq);
LSL_BOOL LASAL32_EXPORTS LslGetLoaderinfo(char *buf, uint32_t bufSize);
LSL_BOOL LASAL32_EXPORTS LslGetLoaderinfoH(int32_t ocbNum, char *buf, uint32_t bufSize);

LSL_BOOL LASAL32_EXPORTS LslReadDateTime(LSL_SYSTEMTIME *pSysTime);
LSL_BOOL LASAL32_EXPORTS LslReadDateTimeH(int32_t ocbNum, LSL_SYSTEMTIME *pSysTime);
LSL_BOOL LASAL32_EXPORTS LslSetDateTime(LSL_SYSTEMTIME *pSysTime);
LSL_BOOL LASAL32_EXPORTS LslSetDateTimeH(int32_t ocbNum, LSL_SYSTEMTIME *pSysTime);
LSL_BOOL LASAL32_EXPORTS LslAdjustDateTime(uint64_t *pRelTimestamp);
LSL_BOOL LASAL32_EXPORTS LslAdjustDateTimeH(int32_t ocbNum, uint64_t *pRelTimestamp);

/*
// S_MEM_INFO.type
typedef enum
{
  MI_CODE,        // 0 - code area
  MI_DATA,        // 1 - data area
  MI_OS_HEAP,     // 2 - os heap
  MI_USER_HEAP,   // 3 - user heap
  MI_SRAM_USER,   // 4 - sram user area
  MI_SRAM_RETAIN, // 5 - sram retain area
  MI_SRAM_RET_RAM,// 6 - sram retain ram area
  MI_SRAM_SYS,    // 7 - sram system area (Kernel-Log,..)
  MI_SRAM_COMPL,  // 8 - sram complete area (user + retain + system)
}E_MEM_INFO_TYPE;

// S_MEM_INFO.attrb
#define MI_ATTR_START   0x0001  // struct member start is valid
#define MI_ATTR_LENGTH  0x0002  // struct member length is valid
#define MI_ATTR_USED    0x0004  // struct member used is valid

// pData at #LslGetMemInfo is filled with a return field - 4 Bytes (count of elements or failure)
   and afterwards an array of type #S_MEM_INFO with the count written in the first field
typedef struct
{
  union {
    E_MEM_INFO_TYPE type;
    unsigned long ul_type;
  };
  unsigned long start;  // start address
  unsigned long length; // length of memory area
  unsigned long used;   // used data length
  unsigned long attrib; // attribute of the memeory area;
}S_MEM_INFO;
*/
LSL_BOOL LASAL32_EXPORTS LslGetMemInfo(uint8_t* pData, uint32_t len);
LSL_BOOL LASAL32_EXPORTS LslGetMemInfoH(int32_t ocbNum, uint8_t* pData, uint32_t len);

LSL_BOOL LASAL32_EXPORTS LslSendCommand(uint32_t cmd, const uint8_t* pTX, uint32_t lenTX, uint8_t* pRX, uint32_t maxLenRX, uint32_t* pLenRX);
LSL_BOOL LASAL32_EXPORTS LslSendCommandH(int32_t ocbNum, uint32_t cmd, const uint8_t* pTX, uint32_t lenTX, uint8_t* pRX, uint32_t maxLenRX, uint32_t* pLenRX);

#define LOADERFLAGS_ISINITIALIZED 0x0001
#define LOADERFLAGS_ISAPPLVALID   0x0002
LSL_BOOL LASAL32_EXPORTS LslGetLoaderflags(uint16_t *pFlags);
LSL_BOOL LASAL32_EXPORTS LslGetLoaderflagsH(int32_t ocbNum, uint16_t *pFlags);

#define CHANGE_ID_RUNSTATUS       1   // bei Änderung von sysvar->runStatus
#define CHANGE_ID_LINK_DONE       2   // wenn das Linken erfolgreich war
#define CHANGE_ID_MODUL_CHANGED   3   // wenn ein Modul hinzugefügt oder entfernt wird
#define CHANGE_ID_AWLBP           4   // beim Auftreten eines AWL Breakpoints
#define CHANGE_ID_BPLIST_CHANGED  5   // bei Änderung der BP-Liste
#define CHANGE_ID_REGS_CHANGED    6   // bei Änderung der Register in sysvar->reg
                                      // (beinhaltet nicht die Registerwerte, die mit DBG_CMD_GETAWLBP 
                                      // abgeholt werden)
#define CHANGE_ID_MEMLAYOUT       7   // wenn sich die Speicheraufteilung ändert
LSL_BOOL LASAL32_EXPORTS LslGetChangeIDs(uint8_t *pBuffer, uint32_t size, uint32_t *pReturnedSize);
LSL_BOOL LASAL32_EXPORTS LslGetChangeIDsH(int32_t ocbNum, uint8_t *pBuffer, uint32_t size, uint32_t *pReturnedSize);

LSL_BOOL LASAL32_EXPORTS LslSetBp(uint8_t nNr, uint16_t nModnr, uint32_t nAddress);
/*-----------------------------------------------------------------------------
    LslSetBpEx - setzt Instruction-Breakpoint

    Parameter
        Nr            .. Breakpoint Nr.  (0..3)
        Id            .. Modul Nr.
        Address       .. Instruction-Pointer Adresse
        Type          .. Breakpoint Typ 
                            0=Instr.Bp
                            1=Instr.Bp AWL
        StackOffset   .. Offset des Stackbereichs (bezogen auf Basepointer) und ...
        StackSize     .. Größe des Stackbereichs, den das Lasal-OS zwischenspeichert.
                          Dieser Stackinhalt ist dann bei GetAwlBp-Liste enthalten.
        Counter       .. Counter, nach wievielen Durchläufen angehalten wird
        CodeLen       .. Länge des Codes für einen bedingten Breakpoint
                            0=kein Code
        pCode         .. Code für einen bedingten Breakpoint
-----------------------------------------------------------------------------*/
LSL_BOOL LASAL32_EXPORTS LslSetBpEx(uint8_t Nr, uint32_t Id, uint32_t Address, uint8_t Type, 
                         int32_t StackOffset, uint32_t StackSize, uint32_t Counter, uint32_t CodeLen, uint8_t *pCode);
LSL_BOOL LASAL32_EXPORTS LslSetBpExH(int32_t ocbNum, uint8_t Nr, uint32_t Id, uint32_t Address, uint8_t Type, 
                         int32_t StackOffset, uint32_t StackSize, uint32_t Counter, uint32_t CodeLen, uint8_t *pCode);

/*-----------------------------------------------------------------------------
    LslSetDataBp - setzt Daten-Breakpoint

    Parameter
        Nr            .. Breakpoint Nr. (0..3)
        Address       .. Daten Adresse
        AddrLen       .. DatenLänge
                            1=1 Byte
                            2=2 Bytes, Adresse muß durch 2 teilbar sein
                            4=4 Bytes, Adresse muß durch 4 teilbar sein
        Type          .. Breakpoint Typ 
                            2=DataBp W  (Break on data writes only)
                            3=DataBp RW (Break on data reads or writes but not instruction fetches)
        CodeLen       .. Länge des Codes für einen bedingten Breakpoint
                            0=kein Code
        pCode         .. Code für einen bedingten Breakpoint

    Anm.:
        Systemtasks werden bei einem Datenbreakpoint nicht angehalten.
        SetData kann beispielsweise Daten an der Adresse des Datenbreakpoints 
        ändern ohne daß das Betriebssystem in den StopBreakpoint-Status geht !
-----------------------------------------------------------------------------*/
LSL_BOOL LASAL32_EXPORTS LslSetDataBp(uint8_t Nr, uint32_t Address, uint8_t AddrLen, uint8_t Type, 
                         uint32_t CodeLen, uint8_t *pCode);
LSL_BOOL LASAL32_EXPORTS LslSetDataBpH(int32_t ocbNum, uint8_t Nr, uint32_t Address, uint8_t AddrLen, uint8_t Type, 
                         uint32_t CodeLen, uint8_t *pCode);
/*------------------------------------------------------------------------------
  LslGetBpList - Information über gesetzte Breakpoints abholen

  Parameter:
    bpnum_bits  .. für jeden Breakpoint, für den die Informationen abgeholt
                   werden sollen, muß ein Bit gesetzt werden:
                    76543210
                    .......x:  1=Breakpoint 0
                    ......x.:  1=Breakpoint 1
                    .....x..:  1=Breakpoint 2
                    ....x...:  1=Breakpoint 3
    Buf         .. Zeiger auf den Pufferbereich, auf den die Breakpoint-
                   Informationen kopiert werden.
                   Eine Breakpointinfo hat die Struktur BPEXTEND_GET_INFO.
                   Im Feld sizeofstruct ist die Größe dieser Struktur angegeben.
                   Damit kann man den Beginn der nächsten Breakpointinfo
                   ermitteln.
                   Das Ende wird durch sizeofstruct = 0 angezeigt.
                   
                   !!! ACHTUNG !!!
                   Der Anfang der nächsten Breakpointinfo darf nicht mit 
                   sizeof(BPEXTEND_GET_INFO) ermittelt werden, da sich die 
                   Größe der Struktur bei zukünftigen Betriebssystemversionen 
                   erhöhen kann
                   
                   Wenn die BPEXTEND_GET_INFO-Struktur bei zukünftigen 
                   Betriebssystemen erweitert wird, so werden die zusätzlichen
                   Elemente ans Ende angehängt.
                   
    dwBufLen    .. Größe des übergebenen Pufferbereichs
    
                   !!! ACHTUNG !!!
                   Der Pufferbereich muß ausreichend dimensioniert werden, 
                   damit eine alte Anwendung mit einem neuen Betriebssystem, 
                   (bei dem die Struktur erweitert wurde) funktioniert.
------------------------------------------------------------------------------*/  
LSL_BOOL LASAL32_EXPORTS LslGetBpList(uint8_t bpnum_bits, uint8_t *Buf, uint32_t dwBufLen); //Veraltet LslGetBpListEx verwnden
LSL_BOOL LASAL32_EXPORTS LslGetBpListH(int32_t ocbNum, uint8_t bpnum_bits, uint8_t *Buf, uint32_t dwBufLen);//Veraltet LslGetBpListEx verwnden

/*------------------------------------------------------------------------------
  LslGetBpList - Information über gesetzte Breakpoints abholen

  Parameter:
    bpnum		   wenn bp numm != 0xFF dann wird nur ein breakpoint zurückgeliefert/abgefragt ansonsten alle
    Buf         .. Zeiger auf den Pufferbereich, auf den die Breakpoint-
                   Informationen kopiert werden.
                   Eine Breakpointinfo hat die Struktur BPEXTEND_GET_INFO.
                   Im Feld sizeofstruct ist die Größe dieser Struktur angegeben.
                   Damit kann man den Beginn der nächsten Breakpointinfo
                   ermitteln.
                   Das Ende wird durch sizeofstruct = 0 angezeigt.
                   
                   !!! ACHTUNG !!!
                   Der Anfang der nächsten Breakpointinfo darf nicht mit 
                   sizeof(BPEXTEND_GET_INFO) ermittelt werden, da sich die 
                   Größe der Struktur bei zukünftigen Betriebssystemversionen 
                   erhöhen kann
                   
                   Wenn die BPEXTEND_GET_INFO-Struktur bei zukünftigen 
                   Betriebssystemen erweitert wird, so werden die zusätzlichen
                   Elemente ans Ende angehängt.
                   
    dwBufLen    .. Größe des übergebenen Pufferbereichs
    
                   !!! ACHTUNG !!!
                   Der Pufferbereich muß ausreichend dimensioniert werden, 
                   damit eine alte Anwendung mit einem neuen Betriebssystem, 
                   (bei dem die Struktur erweitert wurde) funktioniert.
------------------------------------------------------------------------------*/  
LSL_BOOL LASAL32_EXPORTS LslGetBpListEx(uint8_t bpnum, uint8_t *Buf, uint32_t dwBufLen);
LSL_BOOL LASAL32_EXPORTS LslGetBpListExH(int32_t ocbNum,uint8_t bpnum, uint8_t *Buf, uint32_t dwBufLen);

LSL_BOOL LASAL32_EXPORTS LslSetBpRelativ(uint8_t nr,uint32_t id, uint32_t adresse, uint16_t anzahl);
LSL_BOOL LASAL32_EXPORTS LslSetBpRelativH(int32_t ocbNum, uint8_t nr,uint32_t id, uint32_t adresse, uint16_t anzahl);
LSL_BOOL LASAL32_EXPORTS LslGetRegisterRelativ(CP_REGextend *preg);
LSL_BOOL LASAL32_EXPORTS LslGetRegisterRelativH(int32_t ocbNum, CP_REGextend *preg);
LSL_BOOL LASAL32_EXPORTS LslGetProjectInfo(PrjHeader* pRetData0);
LSL_BOOL LASAL32_EXPORTS LslGetProjectInfoH(int32_t ocbNum, PrjHeader* pRetData0);
LSL_BOOL LASAL32_EXPORTS LslGetProjectInfoEx(PrjHeader* pRetData0, uint32_t bufferSize, uint32_t *nRead);
LSL_BOOL LASAL32_EXPORTS LslGetProjectInfoExH(int32_t ocbNum, PrjHeader* pRetData0, uint32_t bufferSize, uint32_t *nRead);
LSL_BOOL LASAL32_EXPORTS LslGetProjectInfoByType( PrjHeader* pRetData0,
                                     uint32_t modTypeMask,
                                     uint32_t modTypeEq);
LSL_BOOL LASAL32_EXPORTS LslGetProjectInfoByTypeH(int32_t ocbNum, 
                                     PrjHeader* pRetData0,
                                     uint32_t modTypeMask,
                                     uint32_t modTypeEq);
LSL_BOOL LASAL32_EXPORTS LslGetModulInfo(ModHeader* pRetData0, uint32_t Modulnr, uint8_t Enable);
LSL_BOOL LASAL32_EXPORTS LslGetModulInfoH(int32_t ocbNum, ModHeader* pRetData0, uint32_t Modulnr, uint8_t Enable);
LSL_BOOL LASAL32_EXPORTS LslGetModulInfoID(ModHeader* pRetData0, uint32_t Id, uint8_t Enable);
LSL_BOOL LASAL32_EXPORTS LslGetModulInfoIDH(int32_t ocbNum, ModHeader* pRetData0, uint32_t Id, uint8_t Enable);
LSL_BOOL LASAL32_EXPORTS LslGetModulInfoIP(ModHeader* pRetData0, uint32_t Eip, uint8_t Enable);
LSL_BOOL LASAL32_EXPORTS LslGetModulInfoIPH(int32_t ocbNum, ModHeader* pRetData0, uint32_t Eip, uint8_t Enable);
LSL_BOOL LASAL32_EXPORTS LslGetModulInfoIDList(uint32_t numHdrs, uint32_t reqMask, ModHeaderReq* reqList, uint8_t* respList);
LSL_BOOL LASAL32_EXPORTS LslGetModulInfoIDListH(int32_t ocbNum, uint32_t numHdrs, uint32_t reqMask, ModHeaderReq* reqList, uint8_t* respList);
LSL_BOOL LASAL32_EXPORTS LslGetModulInfoByType(ModHeader* pRetData0,
                                  uint32_t Modulnr, 
                                  uint8_t Enable, 
                                  uint32_t modTypeMask,
                                  uint32_t modTypeEq);
LSL_BOOL LASAL32_EXPORTS LslGetModulInfoByTypeH(int32_t ocbNum, 
                                   ModHeader* pRetData0,
                                   uint32_t Modulnr, 
                                   uint8_t Enable, 
                                   uint32_t modTypeMask,
                                   uint32_t modTypeEq);
LSL_BOOL LASAL32_EXPORTS LslGetAdressVar(const char *name,int32_t* adresse);
LSL_BOOL LASAL32_EXPORTS LslGetAdressVarH(int32_t ocbNum, const char *name,int32_t* adresse);
LSL_BOOL LASAL32_EXPORTS LslGetObjectID(const char *name,int32_t* adresse);
LSL_BOOL LASAL32_EXPORTS LslGetObjectIDH(int32_t ocbNum, const char *name,int32_t* adresse);

LSL_BOOL LASAL32_EXPORTS LslLoadOSImage(uint8_t* data, uint32_t len, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LslLoadOSImageH(int32_t ocbNum, uint8_t* data, uint32_t len, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS LslBootOSImage(void);
LSL_BOOL LASAL32_EXPORTS LslBootOSImageH(int32_t ocbNum);
LSL_BOOL LASAL32_EXPORTS LslBootOSFile(char* src);
LSL_BOOL LASAL32_EXPORTS LslBootOSFileH(int32_t ocbNum, char* src);

LSL_BOOL LASAL32_EXPORTS ExecIpr(void *paras, void *result, uint32_t resultSize);
LSL_BOOL LASAL32_EXPORTS ExecIprH(int32_t ocbNum, void *paras, void *result, uint32_t resultSize);
LSL_BOOL LASAL32_EXPORTS ExecIprRlen(void *paras, void *result, uint32_t resultSize);
LSL_BOOL LASAL32_EXPORTS ExecIprRlenH(int32_t ocbNum, void *paras, void *result, uint32_t resultSize);
LSL_BOOL LASAL32_EXPORTS LslExecIpr(void *paras, 
                       void *result, 
                       uint32_t resultSize, 
                       LSL_BOOL resuLenWorkaround,
                       int32_t overrideReqLen);
LSL_BOOL LASAL32_EXPORTS LslExecIprH(int32_t ocbNum, 
                        void *paras, 
                        void *result, 
                        uint32_t resultSize, 
                        LSL_BOOL resuLenWorkaround,
                        int32_t overrideReqLen);
LSL_BOOL LASAL32_EXPORTS GetProtocolVersion(uint32_t *protocolVersion);
LSL_BOOL LASAL32_EXPORTS GetProtocolVersionH(int32_t ocbNum, uint32_t *protocolVersion);

//LSL_BOOL LASAL32_EXPORTS LslGetDirList(uint8_t* dirlist);
LSL_BOOL LASAL32_EXPORTS LslGetPLCInfo(uint8_t* infostr, uint32_t maxsize0);
LSL_BOOL LASAL32_EXPORTS LslGetPLCInfoH(int32_t ocbNum, uint8_t* infostr, uint32_t maxsize0);
LSL_BOOL LASAL32_EXPORTS LslGetPLCInfoFromOnline(uint8_t* infostr, uint32_t maxsize0);
LSL_BOOL LASAL32_EXPORTS LslGetPLCInfoFromOnlineH(int32_t ocbNum, uint8_t* infostr, uint32_t maxsize0);
LSL_BOOL LASAL32_EXPORTS LslGetLinkerError(uint32_t num0, char* infostr, uint32_t maxsize0);
LSL_BOOL LASAL32_EXPORTS LslGetLinkerErrorH(int32_t ocbNum, uint32_t num0, char* infostr, uint32_t maxsize0);
LSL_BOOL LASAL32_EXPORTS LslClearLinkerError();
LSL_BOOL LASAL32_EXPORTS LslClearLinkerErrorH(int32_t ocbNum);


LSL_BOOL LASAL32_EXPORTS FileSave(const char* dest, char* pData, uint32_t len, CB_FUNCTYPE* callback, uint32_t attrib);
LSL_BOOL LASAL32_EXPORTS FileSaveH(int32_t ocbNum, const char* dest, char* pData, uint32_t len, CB_FUNCTYPE* callback, uint32_t attrib);
LSL_BOOL LASAL32_EXPORTS FileSaveEx(const char* dest, const char* pData, uint32_t len, CB_FUNCTYPE* callback, int32_t *errCodeRemote);
LSL_BOOL LASAL32_EXPORTS FileSaveExH(int32_t ocbNum, const char* dest, const char* pData, uint32_t len, CB_FUNCTYPE* callback, int32_t *errCodeRemote);
LSL_BOOL LASAL32_EXPORTS FileWrite(const char* dest, const char* pData, uint32_t len, CB_FUNCTYPE* callback, uint32_t attrib, int32_t offs);
LSL_BOOL LASAL32_EXPORTS FileWriteH(int32_t ocbNum, const char* dest, const char* pData, uint32_t len, CB_FUNCTYPE* callback, uint32_t attrib, int32_t offs);
LSL_BOOL LASAL32_EXPORTS FileInfo(char* RXbuf, const char* dest, uint32_t buflen);
LSL_BOOL LASAL32_EXPORTS FileInfoH(int32_t ocbNum, char* RXbuf, const char* dest, uint32_t buflen);
LSL_BOOL LASAL32_EXPORTS FileSetAttributes(const char* dest, const uint32_t iAttrib);
LSL_BOOL LASAL32_EXPORTS FileSetAttributesH(int32_t ocbNum, const char* dest, const uint32_t iAttrib);
LSL_BOOL LASAL32_EXPORTS FileLoad(char* RXbuf, const char* dest, uint32_t datalen, CB_FUNCTYPE* callback, int32_t offs);
LSL_BOOL LASAL32_EXPORTS FileLoadH(int32_t ocbNum, char* RXbuf, const char* dest, uint32_t datalen, CB_FUNCTYPE* callback, int32_t offs);
LSL_BOOL LASAL32_EXPORTS FileUpdateInfo(uint32_t type);
LSL_BOOL LASAL32_EXPORTS FileUpdateInfoH(int32_t ocbNum, uint32_t type);

LSL_BOOL LASAL32_EXPORTS LslFindFirstH(int32_t ocbNum, 
                          const char     *namePattern, 
                          uint8_t            attr, 
                          uint8_t            attrMask, 
                          int32_t            *pResult,
                          _DDE_INFO      *fileInfo, 
                          char           *fileName, 
                          uint32_t            maxLength);
LSL_BOOL LASAL32_EXPORTS LslFindFirst(const char     *namePattern, 
                         uint8_t            attr, 
                         uint8_t            attrMask, 
                         int32_t            *pResult,
                         _DDE_INFO      *fileInfo, 
                         char           *fileName, 
                         uint32_t            maxLength);
LSL_BOOL LASAL32_EXPORTS LslFindNextH(int32_t ocbNum, 
                         int32_t            *pResult,
                         _DDE_INFO      *fileInfo, 
                         char           *fileName, 
                         uint32_t            maxLength);
LSL_BOOL LASAL32_EXPORTS LslFindNext(int32_t            *pResult,
                        _DDE_INFO      *fileInfo, 
                        char           *fileName, 
                        uint32_t            maxLength);
LSL_BOOL LASAL32_EXPORTS LslFindCloseH(int32_t ocbNum, int32_t *pResult);
LSL_BOOL LASAL32_EXPORTS LslFindClose(int32_t *pResult);

LSL_BOOL LASAL32_EXPORTS LslFormatDriveH(int32_t ocbNum, uint8_t ucDriveLetter, uint32_t ulOption, int32_t * pResult, CB_FORMAT_FUNCTYPE FormatInfoCallback);
LSL_BOOL LASAL32_EXPORTS LslFormatDrive(uint8_t ucDriveLetter, uint32_t ulOption, int32_t * pResult, CB_FORMAT_FUNCTYPE FormatInfoCallback);

LSL_BOOL LASAL32_EXPORTS LslFileDeleteH(int32_t ocbNum, const char * ccFileDirectoryName, uint32_t ulOption, int32_t * pResult);
LSL_BOOL LASAL32_EXPORTS LslFileDelete(const char * ccFileDirectoryName, uint32_t ulOption, int32_t * pResult);

LSL_BOOL LASAL32_EXPORTS LslFileCopyH(int32_t ocbNum, const char *src, const char *dest, LSL_BOOL isDir);
LSL_BOOL LASAL32_EXPORTS LslFileCopy(const char *src, const char *dest, LSL_BOOL isDir);

#define LSL_OPENFLAGS_RDONLY						0x00000001
#define LSL_OPENFLAGS_WRONLY						0x00000002
#define LSL_OPENFLAGS_CREATE						0x00000004
// #define LSL_OPENFLAGS_CREATE_ALWAYS				0x00000010
// #define LSL_OPENFLAGS_APPEND						0x00000020

#define LSL_FILETRANSFER_DIRECTION_TOPLC			0x01
#define LSL_FILETRANSFER_DIRECTION_FROMPLC			0x02

LSL_BOOL LASAL32_EXPORTS LslFileTransferH(int32_t ocbNum, uint32_t direction, const char *fileSrc, const char *fileDest, uint32_t flags, CB_FUNCTYPE2 *callback, void *pUser);
LSL_BOOL LASAL32_EXPORTS LslFileTransfer(uint32_t direction, const char *fileSrc, const char *fileDest, uint32_t flags, CB_FUNCTYPE2 *callback, void *pUser);
LSL_BOOL LASAL32_EXPORTS LslFileTransferToPlcBufH(int32_t ocbNum, const void *srcData, uint32_t size, const char *fileDest, uint32_t flags, CB_FUNCTYPE2 *callback, void *pUser);
LSL_BOOL LASAL32_EXPORTS LslFileTransferToPlcBuf(const void *srcData, uint32_t size, const char *fileDest, uint32_t flags, CB_FUNCTYPE2 *callback, void *pUser);
LSL_BOOL LASAL32_EXPORTS LslFileTransferFromPlcBufH(int32_t ocbNum, const char *fileSrc, uint8_t *destBuf, uint32_t size, uint32_t *getsize, CB_FUNCTYPE2 *callback, void *pUser);
LSL_BOOL LASAL32_EXPORTS LslFileTransferFromPlcBuf(const char *fileSrc, uint8_t *destBuf, uint32_t size, uint32_t *getsize, CB_FUNCTYPE2 *callback, void *pUser);

LSL_BOOL LASAL32_EXPORTS LslDownloadOSH(int32_t ocbNum, const char *fileSrc, CB_FUNCTYPE2 *callback, void *pUser);
LSL_BOOL LASAL32_EXPORTS LslDownloadOS(const char *fileSrc, CB_FUNCTYPE2 *callback, void *pUser);


LSL_BOOL LASAL32_EXPORTS LslLrsCommandH(int32_t ocbNum, int32_t ID, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);
LSL_BOOL LASAL32_EXPORTS LslLrsCommand(int32_t ID, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);

LSL_BOOL LASAL32_EXPORTS LslQueryOSPwH(int32_t ocbNum, char *username, char *pwd);
LSL_BOOL LASAL32_EXPORTS LslQueryOSPw(char *username, char *pwd);

LSL_BOOL LASAL32_EXPORTS LslGetOnlPwdH(int32_t ocbNum, char *username, char *pwd);
LSL_BOOL LASAL32_EXPORTS LslGetOnlPwd(char *username, char *pwd);

LSL_BOOL LASAL32_EXPORTS LslSetOnlPwdH(int32_t ocbNum, char *username, char *pwd, char *newpwd);
LSL_BOOL LASAL32_EXPORTS LslSetOnlPwd(char *username, char *pwd, char *newpwd);


LSL_BOOL LASAL32_EXPORTS LslSyssernumCommandH(int32_t ocbNum, int32_t iCmd, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);
LSL_BOOL LASAL32_EXPORTS LslSyssernumCommand(int32_t iCmd, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);


LSL_BOOL LASAL32_EXPORTS LslSetCommonDataH(int32_t ocbNum, const char *lpKennung, const char *pBuffer);
LSL_BOOL LASAL32_EXPORTS LslSetCommonData(const char *lpKennung, const char *pBuffer);

LSL_BOOL LASAL32_EXPORTS LslGetCommonDataH(int32_t ocbNum, const char *lpKennung, char *pBuffer, uint32_t ulBufferSize);
LSL_BOOL LASAL32_EXPORTS LslGetCommonData(const char *lpKennung, char *pBuffer, uint32_t ulBufferSize);

LSL_BOOL LASAL32_EXPORTS LslHoldApplicationH( int32_t ocbNum );
LSL_BOOL LASAL32_EXPORTS LslHoldApplication( void );
LSL_BOOL LASAL32_EXPORTS LslContinueApplicationH( int32_t ocbNum );
LSL_BOOL LASAL32_EXPORTS LslContinueApplication( void );
LSL_BOOL LASAL32_EXPORTS LslGetInstructionPointerH( int32_t ocbNum, int32_t task0, uint32_t **pInstPtr );
LSL_BOOL LASAL32_EXPORTS LslGetInstructionPointer( int32_t task0, uint32_t **pInstPtr );
LSL_BOOL LASAL32_EXPORTS LslGetModuleInfoByIp( uint32_t *pInstPtr, char *pModuleName, uint32_t ulModuleNameLen, char *pFuncName, uint32_t ulFuncNameLen, uint32_t *pModuleOffset);
LSL_BOOL LASAL32_EXPORTS LslGetModuleInfoByIpH( int32_t ocbNum, uint32_t *pInstPtr, char *pModuleName, uint32_t ulModuleNameLen, char *pFuncName, uint32_t ulFuncNameLen, uint32_t *pModuleOffset);

// OSZI intern
LSL_BOOL LASAL32_EXPORTS LslOsziCommandH(int32_t ocbNum, int32_t iCmd, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);
LSL_BOOL LASAL32_EXPORTS LslOsziCommand(int32_t iCmd, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);

//
// OSZI User
//

// IM BS DEFINIERT:
// LSLOS_OSZI_UNKNOWN_COMMAND              0xA0020001L

// Channel managment
#define LSLOS_OSZI_CHANNEL_SERVER         0  //use Read-Methode to get value
#define LSLOS_OSZI_CHANNEL_CLIENT         1  //use Read-Methode to get value
#define LSLOS_OSZI_CHANNEL_MEM_1          2
#define LSLOS_OSZI_CHANNEL_MEM_2          3
#define LSLOS_OSZI_CHANNEL_MEM_4          4
#define LSLOS_OSZI_CHANNEL_SERVER_DD      5  //get value from dData
#define LSLOS_OSZI_CHANNEL_CLIENT_DD      6  //get value from dData
#define LSLOS_OSZI_CHANNEL_MEM_8          7
#define LSLOS_OSZI_CHANNEL_VALUE_UNSIGNED 0
#define LSLOS_OSZI_CHANNEL_VALUE_SIGNED   1
#define LSLOS_OSZI_CHANNEL_VALUE_REAL     2
LSL_BOOL LASAL32_EXPORTS LslOsziAddChannelH(int32_t ocbNum, uint32_t uiChannelType, uint32_t uiChannelValueType, void *pChannelDescriptor );
LSL_BOOL LASAL32_EXPORTS LslOsziAddChannel(uint32_t uiChannelType, uint32_t uiChannelValueType, void *pChannelDescriptor );
LSL_BOOL LASAL32_EXPORTS LslOsziReplaceChannelH(int32_t ocbNum, uint32_t uiChannel, uint32_t uiChannelType, uint32_t uiChannelValueType, void *pChannelDescriptor );
LSL_BOOL LASAL32_EXPORTS LslOsziReplaceChannel( uint32_t uiChannel, uint32_t uiChannelType, uint32_t uiChannelValueType, void *pChannelDescriptor );
LSL_BOOL LASAL32_EXPORTS LslOsziRemoveAllChannelsH(int32_t ocbNum );
LSL_BOOL LASAL32_EXPORTS LslOsziRemoveAllChannels( void );
LSL_BOOL LASAL32_EXPORTS LslOsziGetChannelsH( int32_t ocbNum, uint32_t *puiChannels );
LSL_BOOL LASAL32_EXPORTS LslOsziGetChannels( uint32_t *puiChannels );

// Buffer managment
LSL_BOOL LASAL32_EXPORTS LslOsziSetBufferSizeH(int32_t ocbNum, uint32_t uiBufferSize );
LSL_BOOL LASAL32_EXPORTS LslOsziSetBufferSize( uint32_t uiBufferSize );
LSL_BOOL LASAL32_EXPORTS LslOsziResetBufferH(int32_t ocbNum );
LSL_BOOL LASAL32_EXPORTS LslOsziResetBuffer( void );
LSL_BOOL LASAL32_EXPORTS LslOsziIsBufferEmptyH(int32_t ocbNum, LSL_BOOL *pbEmpty );
LSL_BOOL LASAL32_EXPORTS LslOsziIsBufferEmpty( LSL_BOOL *pbEmpty );
LSL_BOOL LASAL32_EXPORTS LslOsziGetUsedBufferSizeH(int32_t ocbNum, uint32_t *puiUsedBufferSize );
LSL_BOOL LASAL32_EXPORTS LslOsziGetUsedBufferSize( uint32_t *puiUsedBufferSize );
LSL_BOOL LASAL32_EXPORTS LslOsziGetUsedBufferH(int32_t ocbNum, uint32_t uiMaxSize, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslOsziGetUsedBuffer( uint32_t uiMaxSize, void *pBuffer );

// Sample
LSL_BOOL LASAL32_EXPORTS LslOsziStartH(int32_t ocbNum );
LSL_BOOL LASAL32_EXPORTS LslOsziStart( void );
LSL_BOOL LASAL32_EXPORTS LslOsziStopH(int32_t ocbNum );
LSL_BOOL LASAL32_EXPORTS LslOsziStop( void );
int32_t LASAL32_EXPORTS LslOsziSetSampleRateH(int32_t ocbNum, uint32_t uiSampleRateMuSec );
int32_t LASAL32_EXPORTS LslOsziSetSampleRate( uint32_t uiSampleRateMuSec );
LSL_BOOL LASAL32_EXPORTS LslOsziGetSampleRateH( int32_t ocbNum, uint32_t *puiSampleRate );
LSL_BOOL LASAL32_EXPORTS LslOsziGetSampleRate( uint32_t *puiSampleRate );

// Trigger
#define LSLOS_OSZI_TRIGGER_START      0
#define LSLOS_OSZI_TRIGGER_STOP       1
#define LSLOS_OSZI_TRIGGER_COND_EQ    0
#define LSLOS_OSZI_TRIGGER_COND_NEQ   1
#define LSLOS_OSZI_TRIGGER_COND_GT    2
#define LSLOS_OSZI_TRIGGER_COND_GTE   3
#define LSLOS_OSZI_TRIGGER_COND_LT    4
#define LSLOS_OSZI_TRIGGER_COND_LTE   5
LSL_BOOL LASAL32_EXPORTS LslOsziSetTriggerH(int32_t ocbNum, uint32_t uiTriggerType, uint32_t uiChannel, uint32_t uiTriggerCond, const void *pValue );
LSL_BOOL LASAL32_EXPORTS LslOsziSetTrigger( uint32_t uiTriggerType, uint32_t uiChannel, uint32_t uiTriggerCond, const void *pValue );
LSL_BOOL LASAL32_EXPORTS LslOsziClearTriggerH(int32_t ocbNum, uint32_t uiTriggerType );
LSL_BOOL LASAL32_EXPORTS LslOsziClearTrigger( uint32_t uiTriggerType );
LSL_BOOL LASAL32_EXPORTS LslOsziSetCRCH( int32_t ocbNum, uint32_t uiLasalCRC );
LSL_BOOL LASAL32_EXPORTS LslOsziSetCRC( uint32_t uiLasalCRC );
LSL_BOOL LASAL32_EXPORTS LslOsziGetCRCH( int32_t ocbNum, uint32_t *puiCRC );
LSL_BOOL LASAL32_EXPORTS LslOsziGetCRC( uint32_t *puiCRC );
LSL_BOOL LASAL32_EXPORTS LslOsziGetStatusH( int32_t ocbNum, uint32_t *puiStatus );
LSL_BOOL LASAL32_EXPORTS LslOsziGetStatus( uint32_t *puiStatus );
// puiStatus
// Bit 0,1
// LSLOSZI_STOPPED           0
// LSLOSZI_WAIT_FOR_TRIGGER  1
// LSLOSZI_RUNNING           2
// Bit 2,3
// LSLOSZI_STOP_REASON_NOT_STOPPED     0
// LSLOSZI_STOP_REASON_TRIGGER_START   1
// LSLOSZI_STOP_REASON_TRIGGER_STOP    2
// LSLOSZI_STOP_REASON_OSZI_STOP       3

// VARAN intern
LSL_BOOL LASAL32_EXPORTS LslVaranCommandH(int32_t ocbNum, int32_t iCmd, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);
LSL_BOOL LASAL32_EXPORTS LslVaranCommand(int32_t iCmd, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);

//
// VARAN User
//
typedef struct tagNodeAddress
{
	uint32_t uiMaster;
	uint32_t uiAddress;
} NodeAddress, *PNodeAddress;

LSL_BOOL LASAL32_EXPORTS LslVaranGetNodeInfoRH( int32_t ocbNum, uint32_t uiEntries, PNodeAddress paAddress, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranGetNodeInfoH( int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddress, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranGetNodeInfo( uint32_t uiMaster, uint32_t uiAddress, void *pBuffer );

LSL_BOOL LASAL32_EXPORTS LslVaranGetNodeDataRH( int32_t ocbNum, uint32_t uiEntries, PNodeAddress paAddress, uint32_t uiID, uint32_t uiMaxSize, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranGetNodeDataH( int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddress, uint32_t uiID, uint32_t uiMaxSize, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranGetNodeData( uint32_t uiMaster, uint32_t uiAddress, uint32_t uiID, uint32_t uiMaxSize, void *pBuffer );

LSL_BOOL LASAL32_EXPORTS LslVaranReadControlRH( int32_t ocbNum, uint32_t uiEntries, PNodeAddress paAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranReadControlH( int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranReadControl( uint32_t uiMaster, uint32_t uiAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );

LSL_BOOL LASAL32_EXPORTS LslVaranWriteControlRH( int32_t ocbNum, uint32_t uiEntries, PNodeAddress paAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranWriteControlH( int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranWriteControl( uint32_t uiMaster, uint32_t uiAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );

LSL_BOOL LASAL32_EXPORTS LslVaranReadMemoryRH( int32_t ocbNum, uint32_t uiEntries, PNodeAddress paAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranReadMemoryH( int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranReadMemory( uint32_t uiMaster, uint32_t uiAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );

LSL_BOOL LASAL32_EXPORTS LslVaranWriteMemoryRH( int32_t ocbNum, uint32_t uiEntries, PNodeAddress paAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranWriteMemoryH( int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranWriteMemory( uint32_t uiMaster, uint32_t uiAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );

// dwZyklusZeit in ms max 2 Byte (in welchen abstand der Watchdog gesendet werden soll )
// dwCount max. 2 Byte ( Wie oft der Watchdog gesendet werden soll )
LSL_BOOL LASAL32_EXPORTS LslVaranWatchDogTriggerRH( int32_t ocbNum, uint32_t uiEntries, PNodeAddress paAddress, uint32_t dwZyklusZeit, uint32_t dwCount, uint32_t *puiError );
LSL_BOOL LASAL32_EXPORTS LslVaranWatchDogTriggerH( int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddress, uint32_t dwZyklusZeit, uint32_t dwCount, uint32_t *puiError );
LSL_BOOL LASAL32_EXPORTS LslVaranWatchDogTrigger( uint32_t uiMaster, uint32_t uiAddress, uint32_t dwZyklusZeit, uint32_t dwCount, uint32_t *puiError );

LSL_BOOL LASAL32_EXPORTS LslVaranDiagnoseCounterRH( int32_t ocbNum, uint32_t uiEntries, PNodeAddress paAddress, void *pBuffer, uint32_t *puiError );
LSL_BOOL LASAL32_EXPORTS LslVaranDiagnoseCounterH( int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddress, void *pBuffer, uint32_t *puiError );
LSL_BOOL LASAL32_EXPORTS LslVaranDiagnoseCounter( uint32_t uiMaster, uint32_t uiAddress, void *pBuffer, uint32_t *puiError );

const char * LASAL32_EXPORTS LslVaran32GetInfo();
LSL_BOOL LASAL32_EXPORTS LslVaran32PortInfoCount(uint32_t* pResult);
LSL_BOOL LASAL32_EXPORTS LslVaran32PortInfoGetAt(uint32_t nIndex, SLslVaran32PortInfo *pPortInfo);
// Additional Varan32 Function
LSL_BOOL LASAL32_EXPORTS LslVaran32SetWaitForTreeEnumCallbackH(int32_t ocbNum, WFTECALLBACK pCallback, void *pData);
LSL_BOOL LASAL32_EXPORTS LslVaran32SetWaitForTreeEnumCallback(WFTECALLBACK pCallback, void *pData);

LSL_BOOL LASAL32_EXPORTS LslVaran32FWUpdateSetWriteCallback(FWUpdateWriteCallback pCallback);
int32_t  LASAL32_EXPORTS LslVaran32FWUpdateScan(uint32_t ulSubnetIp, void* buf, uint32_t bufSize, uint32_t* uiReplies, uint32_t uiUpdateType);
int32_t  LASAL32_EXPORTS LslVaran32FWUpdateInfo(uint32_t ulIP, void *buf, uint32_t bufSize, uint32_t* uiDevices, uint32_t uiUpdateType);
int32_t  LASAL32_EXPORTS LslVaran32FWUpdateWrite(uint32_t ulIP, char* pFilename, char dev_nr, void* pCookie, uint32_t uiUpdateType);
int32_t  LASAL32_EXPORTS LslVaran32AddFPRPacketFilter(FPRPF_CALLBACK pCallBack, void* pUser);
int32_t  LASAL32_EXPORTS LslVaran32RemoveFPRPacketFilter(int32_t iID);
int32_t  LASAL32_EXPORTS LslVaran32SendRaw(const uint8_t *pData, uint32_t nLen);
int32_t  LASAL32_EXPORTS LslVaran32SendRawUDP(uint32_t ulIP, const uint8_t *pData, uint32_t nLen);

// VARAN Analyzer intern
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerCommandH(int32_t ocbNum, int32_t iCmd, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerCommand(int32_t iCmd, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);

//
// VARAN Analyzer User
//
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerStartH( int32_t ocbNum );
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerStart( void );

LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerStopH( int32_t ocbNum );
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerStop( void );

// Options
#define LSLOS_VARANANALYZER_TRIGGER_START           0
#define LSLOS_VARANANALYZER_TRIGGER_STOP            1
#define LSLOS_VARANANALYZER_CAPTURE                 2
#define LSLOS_VARANANALYZER_PACKETS_AFTER_TRIGGER   3
#define LSLOS_VARANANALYZER_FPGA_VERSION            4
#define LSLOS_VARANANALYZER_DIRECT_READ_BYTE      100
#define LSLOS_VARANANALYZER_DIRECT_WRITE_BYTE     101
#define LSLOS_VARANANALYZER_DIRECT_READ_DWORD     102
#define LSLOS_VARANANALYZER_DIRECT_WRITE_DWORD    103

LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerSetOptionH( int32_t ocbNum, uint32_t uiType, uint32_t uiControl, uint32_t uiCmd, uint32_t uiAddrStart, uint32_t uiAddrStop );
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerSetOption( uint32_t uiType, uint32_t uiControl, uint32_t uiCmd, uint32_t uiAddrStart, uint32_t uiAddrStop );

LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetStatusH( int32_t ocbNum, uint32_t *puiStatus, uint32_t *puiLastWritten, uint32_t *puilastPacket );
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetStatus( uint32_t *puiStatus, uint32_t *puiLastWritten, uint32_t *puilastPacket );

LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetUsedBufferSizeH( int32_t ocbNum, uint32_t *puiUsedBufferSize );
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetUsedBufferSize( uint32_t *puiUsedBufferSize );

LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetUsedBufferH( int32_t ocbNum, uint32_t uiMaxSize, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetUsedBuffer( uint32_t uiMaxSize, void *pBuffer );

LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetOptionH( int32_t ocbNum, uint32_t uiType, uint32_t *puiControl, uint32_t *puiCmd, uint32_t *puiAddrStart, uint32_t *puiAddrStop );
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetOption( uint32_t uiType, uint32_t *puiControl, uint32_t *puiCmd, uint32_t *puiAddrStart, uint32_t *puiAddrStop );

LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerSetByteH( int32_t ocbNum, uint32_t uiOff, uint8_t ucD );
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerSetByte( uint32_t uiOff, uint8_t ucD );

LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerSetDwordH( int32_t ocbNum, uint32_t uiOff, uint32_t uiD );
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerSetDword( uint32_t uiOff, uint32_t uiD );

LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetByteH( int32_t ocbNum, uint32_t uiOff, uint8_t *pucD );
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetByte( uint32_t uiOff, uint8_t *pucD );

LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetDwordH( int32_t ocbNum, uint32_t uiOff, uint32_t *puiD );
LSL_BOOL LASAL32_EXPORTS LslVaranAnalyzerGetDword( uint32_t uiOff, uint32_t *puiD );


LSL_BOOL LASAL32_EXPORTS LslRenameFileDirH(int32_t ocbNum, const char * ccFileDirectoryName, const char * ccNewName, uint32_t ulOption, int32_t * pResult);
LSL_BOOL LASAL32_EXPORTS LslRenameFileDir(const char * ccFileDirectoryName, const char * ccNewName, uint32_t ulOption, int32_t * pResult);

LSL_BOOL LASAL32_EXPORTS LslGetDiskSpaceH(int32_t ocbNum, const char * ccDrive, uint32_t * pBytesPerSector, uint32_t * pSectorsPerCluster, uint32_t * pTotalClusters, uint32_t * pFreeClusters, uint32_t ulOption, int32_t * pResult);
LSL_BOOL LASAL32_EXPORTS LslGetDiskSpace(const char * ccDrive, uint32_t * pBytesPerSector, uint32_t * pSectorsPerCluster, uint32_t * pTotalClusters, uint32_t * pFreeClusters, uint32_t ulOption, int32_t * pResult);

LSL_BOOL LASAL32_EXPORTS LslGetDriveListShortH(int32_t ocbNum, uint32_t * pDriveList, uint32_t ulSize, uint32_t ulOption, int32_t * pResult);
LSL_BOOL LASAL32_EXPORTS LslGetDriveListShort(uint32_t * pDriveList, uint32_t ulSize, uint32_t ulOption, int32_t * pResult);

LSL_BOOL LASAL32_EXPORTS LslCheckDiskH(int32_t ocbNum, const char * DriveName, uint32_t ulOption, uint32_t ulFlags, CB_CHKDSK_FUNCTYPE CheckDiskProgressInfo, uint32_t * pErrors, int32_t * pResult);
LSL_BOOL LASAL32_EXPORTS LslCheckDisk(const char * DriveName, uint32_t ulOption, uint32_t ulFlags, CB_CHKDSK_FUNCTYPE CheckDiskProgressInfo, uint32_t * pErrors, int32_t * pResult);

LSL_BOOL LASAL32_EXPORTS DeleteModul(uint32_t ModuleID);
LSL_BOOL LASAL32_EXPORTS DeleteModulH(int32_t ocbNum, uint32_t ModuleID);

LSL_BOOL LASAL32_EXPORTS SetNewBreakpoint(uint32_t num0, uint32_t bptype0, void* bpcode0, uint32_t len0);
LSL_BOOL LASAL32_EXPORTS ActivateBreakpoint(uint32_t num0, uint32_t status0);
LSL_BOOL LASAL32_EXPORTS ActivateBreakpointH(int32_t ocbNum, uint32_t num0, uint32_t status0);

LSL_BOOL LASAL32_EXPORTS GetObjectInfo(void* thisobj0, 
                   uint8_t tasktype0, 
                   GETOBJINFO_STR *getobjinfo_buf, 
                   uint32_t bufsize,    // Große von getobjinfo_buf
                   uint32_t *nReceived  // Anzahl empfanger Bytes in getobjinfo_buf (NULL=uninteressant)
                   );
LSL_BOOL LASAL32_EXPORTS GetObjectInfoH(int32_t ocbNum, void* thisobj0, 
                   uint8_t tasktype0, 
                   GETOBJINFO_STR *getobjinfo_buf, 
                   uint32_t bufsize,    // Große von getobjinfo_buf
                   uint32_t *nReceived  // Anzahl empfanger Bytes in getobjinfo_buf (NULL=uninteressant)
                   );
LSL_BOOL LASAL32_EXPORTS EditObj(void* thisobj0, 
             uint8_t objtask0, 
             uint8_t action0, 
             uint8_t debugobj0,
             uint32_t objtime0,
             int32_t *fcn_rc     // Returncode der LSLDBG_EditObj Funktion:
                              //   0 .. o.k.
                              // <>0 .. Fehler:
                              //      -5 = not found
             );
LSL_BOOL LASAL32_EXPORTS EditObjH(int32_t ocbNum, void* thisobj0, 
             uint8_t objtask0, 
             uint8_t action0, 
             uint8_t debugobj0,
             uint32_t objtime0,
             int32_t *fcn_rc);
/*------------------------------------------------------------------------------
  ServiceProvider -  Schickt einen String an den ServiceProvider
  cmd   .. String, nicht case-sensitive
            Bsp.: "Reset"
                  "Reset & REBOOT"
                  "EXEC LSLLOAD"
                  "EXEC LSLSAVE"
------------------------------------------------------------------------------*/
LSL_BOOL LASAL32_EXPORTS ServiceProvider(char *cmd);
LSL_BOOL LASAL32_EXPORTS ServiceProviderH(int32_t ocbNum, char *cmd);
LSL_BOOL LASAL32_EXPORTS ServiceProviderResponse(char *cmd, char *pResponse, uint32_t respLen);
LSL_BOOL LASAL32_EXPORTS ServiceProviderResponseH(int32_t ocbNum, char *cmd, char *pResponse, uint32_t respLen);

// OS Terminal
LSL_BOOL LASAL32_EXPORTS PutKey(uint8_t key0, uint8_t scancode0);
LSL_BOOL LASAL32_EXPORTS PutKeyH(int32_t ocbNum, uint8_t key0, uint8_t scancode0);
LSL_BOOL LASAL32_EXPORTS PutString(char* string0);
LSL_BOOL LASAL32_EXPORTS PutStringH(int32_t ocbNum, char* string0);

LSL_BOOL LASAL32_EXPORTS SendDataList(uint16_t length0, char* data0, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS SendDataListH(int32_t ocbNum, uint16_t length0, char* data0, CB_FUNCTYPE* callback);
LSL_BOOL LASAL32_EXPORTS GetDataList(char* data0);
LSL_BOOL LASAL32_EXPORTS GetDataListH(int32_t ocbNum, char* data0);
LSL_BOOL LASAL32_EXPORTS LslSave( void );
LSL_BOOL LASAL32_EXPORTS LslSaveH( int32_t ocbNum );
LSL_BOOL LASAL32_EXPORTS LslSaveRmd( void );
LSL_BOOL LASAL32_EXPORTS LslSaveRmdH( int32_t ocbNum );
LSL_BOOL LASAL32_EXPORTS LslLoad( void );
LSL_BOOL LASAL32_EXPORTS LslLoadH( int32_t ocbNum );
LSL_BOOL LASAL32_EXPORTS SendCmdString( char* string );
LSL_BOOL LASAL32_EXPORTS SendCmdStringH( int32_t ocbNum, char* string );
LSL_BOOL LASAL32_EXPORTS GetCmdStringStatus( PCSTRSTAT_INFO pRetdat, uint32_t buflen );
LSL_BOOL LASAL32_EXPORTS GetCmdStringStatusH( int32_t ocbNum, PCSTRSTAT_INFO pRetdat, uint32_t buflen );

//==========================================================================================
// CAN - Funktionen 
//==========================================================================================
LSL_BOOL LASAL32_EXPORTS CanSendObj( uint32_t dwCanIdentifier, uint8_t len, uint8_t *data );
LSL_BOOL LASAL32_EXPORTS CanSendObjH( int32_t ocbNum, uint32_t dwCanIdentifier, uint8_t len, uint8_t *data );

//==========================================================================================

//==========================================================================================
// MODEM - Funktionen 
//==========================================================================================

/*
//-- Modem initialisieren ------------------------------------------------------------------
// -> dIndex ... Index des Modems aus der Systemliste (mit 0 beginnend!)
//-> szComm: Schnittstelle z.B: "COM1"  (bis "COM4" möglich)
//-> szInit: Initstring (AT-Befehele)
//<- TRUE/FALSE
LSL_BOOL LASAL32_EXPORTS ModemInit(const char* pszComm, const char * pszInit);
*/

//--- Modem oeffnen ----------------------------------------------------------------------
// Im System sind unter Umstaenden mehrere Modem installiert.
// Aus der Systemsteuerung kann der Index (=Nummer mit 0 beginnend) des gewuenschten Modems 
// ermittelt werden.
LSL_BOOL LASAL32_EXPORTS ModemOpen(void);


//--- Den Namen des aktuellen Modems bestimmen ---------------------------------------------
// Nur moeglich wenn ModemOpen() bereits aufgerufen wurde.
// -> dModemID: Index des Modems aus der Systemliste (mit 0 beginnend!)
// <- TRUE .... in szName steht der Name des Modems
//    FALSE.... Fehler z.B.: ModemOpen() noch nicht aufgerufen.
LSL_BOOL LASAL32_EXPORTS ModemGetName(uint32_t dModemID, char *pszName, uint16_t maxsize);

//--- Anzahl der Modem aus der Systemliste ermittelen ------------------------------------
// <- Anzahl der Modems
uint32_t LASAL32_EXPORTS ModemGetNumber(void);

//--- Modem - Anruffunktion ----------------------------------------------------------------
//->  dModemID: Index des Modems aus der Systemliste (mit 0 beginnend!)
//->     bType: 0 = Sigmatek ModemLink über CAN mit SPS verbunden
//              1 = Modem direkt an der SPS über RS232 verbunden

//->dConfigBaud: Folgende Bits können angegeben werden:
//               LoWord: Bit 0 .... 0 = Tonwahl, 1 = Pulswahl
//-> wBaudrate: 0 = automatische Anpassung (= default)
//->   szTelNr: Telefonnummer als ASCII-0-String
//->  nTimeOut: Timeout in [s] für Verbindungsaufbau
//<- TRUE/FALSE
// dConfigBaudrate: LoWord: Bit 0...1 = Pulsewahl
// szTelNr...Telefonnummer
LSL_BOOL LASAL32_EXPORTS ModemCall(uint32_t dModemID, uint8_t uType, uint32_t dConfigBaud, char *szTelNr, uint8_t nTimeout);
//--- Modem Status abfragen --------------------------------------------------------------
//<- Status:
        #define    LINECALLSTATE_IDLE                      0x00000001
        #define    LINECALLSTATE_OFFERING                  0x00000002
        #define    LINECALLSTATE_ACCEPTED                  0x00000004
        #define    LINECALLSTATE_DIALTONE                  0x00000008
        #define    LINECALLSTATE_DIALING                   0x00000010
        #define    LINECALLSTATE_RINGBACK                  0x00000020
        #define    LINECALLSTATE_BUSY                      0x00000040
        #define    LINECALLSTATE_SPECIALINFO               0x00000080
        #define    LINECALLSTATE_CONNECTED                 0x00000100
        #define    LINECALLSTATE_PROCEEDING                0x00000200
        #define    LINECALLSTATE_ONHOLD                    0x00000400
        #define    LINECALLSTATE_CONFERENCED               0x00000800
        #define    LINECALLSTATE_ONHOLDPENDCONF            0x00001000
        #define    LINECALLSTATE_ONHOLDPENDTRANSFER        0x00002000
        #define    LINECALLSTATE_DISCONNECTED              0x00004000
        #define    LINECALLSTATE_UNKNOWN                   0x00008000
uint32_t LASAL32_EXPORTS ModemStatus(void);

//--- Modem - prüfen, ob Modemverbindung besteht -------------------------------------------
LSL_BOOL LASAL32_EXPORTS ModemIsConnected( void );

//--- Modem - Sende und Empfangspuffer leeren ----------------------------------------------
void  LASAL32_EXPORTS ModemFlush(void);


//--- Modem schließen ----------------------------------------------------------------------
void  LASAL32_EXPORTS ModemClose(void);

LSL_BOOL LASAL32_EXPORTS LslGwConnect(int32_t port, char *serviceName, int32_t *phConn);
LSL_BOOL LASAL32_EXPORTS LslGwConnectH(int32_t ocbNum, int32_t port, char *serviceName, int32_t *phConn);
LSL_BOOL LASAL32_EXPORTS LslGwClose(int32_t hConn);
LSL_BOOL LASAL32_EXPORTS LslGwCloseH(int32_t ocbNum, int32_t hConn);
LSL_BOOL LASAL32_EXPORTS LslGwTransfer( int32_t hConn, 
                              char *txBuf,
                              uint32_t txLen,
                              uint32_t *pBytesSent,
                              char *rxBuf,
                              uint32_t rxBufSize,
                              uint32_t *bytesRcvd
                              );
LSL_BOOL LASAL32_EXPORTS LslGwTransferH(int32_t ocbNum, 
                              int32_t hConn, 
                              char *txBuf,
                              uint32_t txLen,
                              uint32_t *pBytesSent,
                              char *rxBuf,
                              uint32_t rxBufSize,
                              uint32_t *bytesRcvd
                              );

//==========================================================================================

/*------------------------------------------------------------------------------
  GetPowerFailInfo

    info    ..  0 = kein PowerFail aufgetreten oder PowerFailInfo konnte nicht 
                    ermittelt werden (rc=FALSE)
                1 = PowerFail ist aufgetreten
    errcode .. Fehlercode, wenn PowerFailInfo nicht ermittelt werden konnte (rc=FALSE)
                0 = kein Fehler
                1 = SIGMA-Treiber konnte nicht geöffnet werden
                2 = falsche Version des SIGMA-Treibers
                3 = kein Sigmatek PC
                4 = UPS ist nicht enabled
               99 = System error (out of memory, system-call failed, ...)

  Return:
    TRUE    .. PowerFailInfo konnte ermittelt werden
    FALSE   .. PowerFailInfo konnte nicht ermittelt werden
    
------------------------------------------------------------------------------*/
LSL_BOOL LASAL32_EXPORTS GetPowerFailInfo( uint8_t *info, uint8_t *errcode );

// Measurement
LSL_BOOL LASAL32_EXPORTS StartCPUMeasure( uint32_t duration_ms );
LSL_BOOL LASAL32_EXPORTS StartCPUMeasureH( int32_t ocbNum, uint32_t duration_ms );
LSL_BOOL LASAL32_EXPORTS StopCPUMeasure(void);
LSL_BOOL LASAL32_EXPORTS StopCPUMeasureH(int32_t ocbNum);
LSL_BOOL LASAL32_EXPORTS GetCPUMeasureStatus(uint8_t *pCPUMeasureStatus);
LSL_BOOL LASAL32_EXPORTS GetCPUMeasureStatusH(int32_t ocbNum, uint8_t *pCPUMeasureStatus);
LSL_BOOL LASAL32_EXPORTS GetCPUMeasureData(char *Buffer, uint32_t Buflen);
LSL_BOOL LASAL32_EXPORTS GetCPUMeasureDataH(int32_t ocbNum, char *Buffer, uint32_t Buflen);

LSL_BOOL LASAL32_EXPORTS StartMeasurementNew(uint32_t duration_ms, uint32_t type);
LSL_BOOL LASAL32_EXPORTS StartMeasurementNewH(int32_t ocbNum, uint32_t duration_ms, uint32_t type);
LSL_BOOL LASAL32_EXPORTS StopMeasurementNew();
LSL_BOOL LASAL32_EXPORTS StopMeasurementNewH(int32_t ocbNum);
LSL_BOOL LASAL32_EXPORTS GetMeasurementDataNew(char *buffer, uint32_t buflen);
LSL_BOOL LASAL32_EXPORTS GetMeasurementDataNewH(int32_t ocbNum, char *buffer, uint32_t buflen);
//==========================================================================================

LSL_BOOL LASAL32_EXPORTS GetInfo(uint32_t infoID, void *pBuffer, uint32_t sizeBuffer, uint32_t *pBytesReceived);
LSL_BOOL LASAL32_EXPORTS GetInfoH(int32_t ocbNum, uint32_t infoID, void *pBuffer, uint32_t sizeBuffer, uint32_t *pBytesReceived);

void LASAL32_EXPORTS DBG_Print( int32_t level, const char *fmt, ... );


//==========================================================================================
//=== LslOnline begin
//==========================================================================================

#ifndef LSL32_DEFINE_CHMODE
#define LSL32_DEFINE_CHMODE

#pragma pack(push, 4)

typedef enum
{
    _CH_OBJ,                // object
    _CH_CMD,                // command server
    _CH_SVR,                // data server
    _CH_CLT_CMD,            // command client
    _CH_CLT_DATA,            // data client
    _CH_CLT_OBJ,            // object client
    _CH_OBJ_DIR,
    _CH_CNST,
    _CH_NONE,
    _CH_CLT_EMB,
} ChMode;


#pragma pack(pop)

#endif // LSL32_DEFINE_CHMODE



//!    have an identifier evaluated by the PLC
/*!    The name of an object is sent to the PLC. If it's realy an object name, then
    the address is returned, and if it identifies an object or a channel.
    \param    objName        identifier to check    (ASCII-string)
    \param    objAddr        returns the address of the object or channel (if found)
    \param    pMode        returns the type of channel (if found, see ChMode)
    \param    pszClsName    returns the class name if pMode is _CH_OBJ
    \return                true ... name is a valid identifier in the LASAL application
                        false... the identifier is no object or channel name
*/
LSL_BOOL LASAL32_EXPORTS LslGetObject(const char  *    objName, 
								  uint32_t  *    objAddr, 
								  ChMode      *    pMode,
								  char        *    pszClsName = NULL);
LSL_BOOL LASAL32_EXPORTS LslGetObjectH(int32_t             ocbNum,
								   const char *    objName, 
								   uint32_t *    objAddr, 
								   ChMode     *    pMode,
								   char       *    pszClsName = NULL);

LSL_BOOL LASAL32_EXPORTS LslGetObjectEx(const char * objName, 
									uint32_t * objAddr, 
									ChMode     * pMode,
									char       * pszClsName = NULL,
									uint8_t *pDataBufferFlag = NULL );
LSL_BOOL LASAL32_EXPORTS LslGetObjectExH(int32_t          ocbNum,
									 const char * objName, 
									 uint32_t * objAddr, 
									 ChMode     * pMode,
									 char       * pszClsName = NULL,
									 uint8_t *pDataBufferFlag = NULL );

//!    Get the class name of an object with known address
/*!    The address of an object is sent to the PLC, if the address is valid the name
    of the class of the object is returned.
    \param    objAddr        Name of the object you want to know the class name from.
    \return    className    Name of the class if the address was valid
    \return                true className is valid, false on any error
*/
LSL_BOOL LASAL32_EXPORTS LslGetObjCls(const uint32_t    objAddr, 
								  char        *  className);
LSL_BOOL LASAL32_EXPORTS LslGetObjClsH(int32_t           ocbNum,
								   const uint32_t   objAddr, 
								   char        * className);

//!    calls the write method of a server to set a value
/*!    The write method of a server with a given address is called. This should be the 
    only way, how internal data of an object is changed.
    \param    objAddr        Address of a server channel
    \param    dValue        value to write to the server
    \return                true... Write-method was called, false... any error
*/
LSL_BOOL LASAL32_EXPORTS LslWriteToSvr(uint32_t	objAddr, 
								   uint32_t	dValue);
LSL_BOOL LASAL32_EXPORTS LslWriteToSvrH(int32_t				ocbNum,
									uint32_t	objAddr, 
									uint32_t	dValue);
//!    calls the write method of a server to set a value
/*!    The write method of a server with a given address is called. This should be the 
only way, how internal data of an object is changed.
\param    objAddr		Address of a server channel
\param    dValue		value to write to the server
\param    pResult		the ExecIpr workState
\return                true... Write-method was called, false... any error
*/
LSL_BOOL LASAL32_EXPORTS LslWriteToSvrEx(uint32_t	objAddr, 
									 uint32_t	dValue,
									 uint32_t   *pResult);
LSL_BOOL LASAL32_EXPORTS LslWriteToSvrExH(int32_t			ocbNum,
									uint32_t	objAddr, 
									uint32_t	dValue,
									uint32_t   *pResult);

//!    Calls the NewInst of a String Server and write String
/*!    The NewInst of a server with a given address is called.
\param    objAddr        : address of the server channel
\param    pString        : Pointer to the String, that will set into String Server
\param    iLen           : len of the String ( -1 make internal stringLen )
\return                  : true ... NewInst-method was called / false on any error
*/
LSL_BOOL LASAL32_EXPORTS LslWriteToSvrStr(uint32_t objAddr, const char *pString, int32_t iLen);
LSL_BOOL LASAL32_EXPORTS LslWriteToSvrStrH(int32_t ocbNum, uint32_t objAddr, const char *pString, int32_t iLen);

//!    Calls the NewInst of a String Server and Read String & StringLen
/*!    The NewInst of a server with a given address is called and retrive the String
\param    objAddr        : address of the server channel
\param    pString        : Pointer to the String Puffer.
\param    iLen           : len of the String Puffer. One byte must be calculate for 0 string termination.
\param    pStringLen     : return the real length of the string. Can be NIL.
\return                  : true ... NewInst-method was called / false on any error
if iLen is zero, only pStringLen is returned.
*/
LSL_BOOL LASAL32_EXPORTS LslReadFromSvrStr(uint32_t objAddr, char *pString, uint32_t dwLen, uint32_t *pStringLen);
LSL_BOOL LASAL32_EXPORTS LslReadFromSvrStrH(int32_t ocbNum, uint32_t objAddr, char *pString, uint32_t dwLen, uint32_t *pStringLen);


//!    Calls the write method of a server which is connected to the given client
/*!    The server wich is connected to the given client should be set to a 
    different value. Therfore the write method of it has to be called.
    Instead of getting the address of the server first and calling WriteToSvr
    afterwards, this function should be called for better performance.
    \param    objAddr        : address of the client channel
    \param    dValue        : data that should be written onto the connected server
    \return                : true ... Write-method was called / false on any error
*/
LSL_BOOL LASAL32_EXPORTS LslWriteToClt(uint32_t            objAddr, 
								   uint32_t            dValue);
LSL_BOOL LASAL32_EXPORTS LslWriteToCltH(int32_t              ocbNum,
									uint32_t            objAddr, 
									uint32_t            dValue);

//!    call the read method to get a value from a server
/*    this function should not be called frequently, as it may change the contents
    of the channel, or cause some additional CPU load
    \param    objAddr        address of the server channel
    \return    dValue        contains the channel contents if successfull
    \return                : true ... Read-method was called / false on any error
*/
LSL_BOOL LASAL32_EXPORTS LslReadFromSvr(uint32_t            objAddr, 
									uint32_t        *   dValue);
LSL_BOOL LASAL32_EXPORTS LslReadFromSvrH(int32_t              ocbNum,
									 uint32_t            objAddr, 
									 uint32_t        *   dValue);

//!    call the read method to get a value from a server connected to a client
/*    this function should not be called frequently, as it may change the contents
    of the channel, or cause some additional CPU load. It calles the read method for
    the server connected to the given client.
    \param    objAddr        address of the client channel
    \return    dValue        contains the channel contents if successfull
    \return                : true ... Read-method was called / false on any error
*/
LSL_BOOL LASAL32_EXPORTS LslReadFromClt(uint32_t            objAddr, 
									uint32_t        *   dValue);
LSL_BOOL LASAL32_EXPORTS LslReadFromCltH(int32_t              ocbNum,
									 uint32_t            objAddr, 
									 uint32_t        *   dValue);

LSL_BOOL LASAL32_EXPORTS LslReadNextObj( void *pClassDesc, 
									 void **pObjectDesc, 
									 char *objectName );
LSL_BOOL LASAL32_EXPORTS LslReadNextObjH(int32_t ocbNum, 
									 void *pClassDesc, 
									 void **pObjectDesc, 
									 char *objectName );

LSL_BOOL LASAL32_EXPORTS LslReadNextChannel( void *pClassDesc, 
										 void **pChannelDesc, 
										 ChMode * pMode,
										 char *channelName );
LSL_BOOL LASAL32_EXPORTS LslReadNextChannelH( int32_t ocbNum,
										  void *pClassDesc, 
										  void **pChannelDesc, 
										  ChMode * pMode,
										  char *channelName );

LSL_BOOL LASAL32_EXPORTS LslReadNextClass( void **pClassDesc, 
									   void **pBaseClassDesc, 
									   GUID *ClsGuid, 
									   uint16_t *uiType, 
									   char *className );
LSL_BOOL LASAL32_EXPORTS LslReadNextClassH( int32_t ocbNum,
										void **pClassDesc, 
										void **pBaseClassDesc, 
										GUID *ClsGuid, 
										uint16_t *uiType, 
										char *className );

LSL_BOOL LASAL32_EXPORTS LslExecNewInstr(uint32_t dwSrvAddress, 
									 uint16_t wCmd, 
									 uint32_t adwParas[],
									 uint32_t dwParaCnt,
									 uint8_t* pResult/*= NULL*/, 
									 uint32_t dwResultCnt/*=0*/,
									 uint32_t useLenField );
LSL_BOOL LASAL32_EXPORTS LslExecNewInstrH(int32_t ocbNum,
									  uint32_t dwSrvAddress, 
									  uint16_t wCmd, 
									  uint32_t adwParas[],
									  uint32_t dwParaCnt,
									  uint8_t* pResult/*= NULL*/, 
									  uint32_t dwResultCnt/*=0*/,
									  uint32_t useLenField );

LSL_BOOL LASAL32_EXPORTS LslExecNewInstrEx(uint32_t dwSrvAddress, 
									 uint16_t wCmd, 
									 uint32_t adwParas[],
									 uint32_t dwParaCnt,
									 uint8_t* pResult/*= NULL*/, 
									 uint32_t dwResultCnt/*=0*/,
									 uint32_t useLenField,
                   uint32_t returnState );

LSL_BOOL LASAL32_EXPORTS LslExecNewInstrExH(int32_t ocbNum,
									  uint32_t dwSrvAddress, 
									  uint16_t wCmd, 
									  uint32_t adwParas[],
									  uint32_t dwParaCnt,
									  uint8_t* pResult/*= NULL*/, 
									  uint32_t dwResultCnt/*=0*/,
									  uint32_t useLenField,
                    uint32_t returnState );

LSL_BOOL LASAL32_EXPORTS LslExecGetState(uint32_t dwSrvAddress, 
									 uint16_t wCmd, 
									 uint32_t adwParas[],
									 uint32_t dwParaCnt,
									 uint8_t* pResult/*= NULL*/, 
									 uint32_t dwResultCnt/*=0*/,
									 uint32_t useLenField,
                   uint32_t returnState );

LSL_BOOL LASAL32_EXPORTS LslExecGetStateH(int32_t ocbNum,
									  uint32_t dwSrvAddress, 
									  uint16_t wCmd, 
									  uint32_t adwParas[],
									  uint32_t dwParaCnt,
									  uint8_t* pResult/*= NULL*/, 
									  uint32_t dwResultCnt/*=0*/,
									  uint32_t useLenField,
                    uint32_t returnState );

LSL_BOOL LASAL32_EXPORTS LslExecKill(uint32_t dwSrvAddress, 
									 uint8_t* pResult/*= NULL*/, 
									 uint32_t dwResultCnt/*=0*/,
									 uint32_t useLenField,
                   uint32_t returnState );

LSL_BOOL LASAL32_EXPORTS LslExecKillH(int32_t ocbNum,
									  uint32_t dwSrvAddress, 
									  uint8_t* pResult/*= NULL*/, 
									  uint32_t dwResultCnt/*=0*/,
									  uint32_t useLenField,
                    uint32_t returnState );

LSL_BOOL LASAL32_EXPORTS LslExecNewInstrStream(uint32_t dwSrvAddress, 
											uint16_t wCmd, 
											uint8_t *pData,
											uint32_t dataLen,
											uint8_t* pResult/*= NULL*/, 
											uint32_t dwResultCnt/*=0*/,
											uint32_t useLenField );
LSL_BOOL LASAL32_EXPORTS LslExecNewInstrStreamH(int32_t ocbNum,
											uint32_t dwSrvAddress, 
											uint16_t wCmd, 
											uint8_t *pData,
											uint32_t dataLen,
											uint8_t* pResult/*= NULL*/, 
											uint32_t dwResultCnt/*=0*/,
											uint32_t useLenField );

LSL_BOOL LASAL32_EXPORTS LslGetCpuRegister( uint32_t lThreadID, 
                      uint32_t lWasWillIchHabenFlag, 
                      void *pRC, 
                      uint32_t lSizeBuffer );
LSL_BOOL LASAL32_EXPORTS LslGetCpuRegisterH( int32_t ocbNum,
                      uint32_t lThreadID, 
                      uint32_t lWasWillIchHabenFlag, 
                      void *pRC, 
                      uint32_t lSizeBuffer );

LSL_BOOL LASAL32_EXPORTS LslSingleStep( uint32_t ulThreadID, uint32_t ulNextAbsoluteAddress );
LSL_BOOL LASAL32_EXPORTS LslSingleStepH( int32_t ocbNum, uint32_t ulThreadID, uint32_t ulNextAbsoluteAddress );
LSL_BOOL LASAL32_EXPORTS LslGetMaxBP( uint32_t *ulMaxBP );
LSL_BOOL LASAL32_EXPORTS LslGetMaxBPH( int32_t ocbNum, uint32_t *ulMaxBP );


// Forwarding struct definition. Struct is in File CpRegs.h
typedef struct _SAWLBPINFOCPU SAWLBPINFOCPU;

LSL_BOOL LASAL32_EXPORTS LslGetCpuAwlBp( SAWLBPINFOCPU *pAwlBpInfo, uint32_t dwBufLen );
LSL_BOOL LASAL32_EXPORTS LslGetCpuAwlBpH( int32_t ocbNum, SAWLBPINFOCPU *pAwlBpInfo, uint32_t dwBufLen );

//==========================================================================================
//=== LslPing
//==========================================================================================

// Return Values for LslTcpPing
#define LSL_PING_ERROR_NO					0
#define LSL_PING_ERROR_TIMEOUT				-1
#define LSL_PING_ERROR_ICMP_CREATE			-2
#define LSL_PING_ERROR_INIT					-4
#define LSL_PING_ERROR_HOST_NOT_FOUND		-5
#define LSL_PING_ERROR_WSA					-6
#define LSL_PING_ERROR_GETSTATE				-7
#define LSL_PING_ERROR_SHUTDOWN				-8
#define LSL_PING_ERROR_RECEIVE_DATA			-9
#define LSL_PING_ERROR_RECEIVE_STATUS		-10
#define LSL_PING_ERROR_RECEIVE_SIZE			-11
#define LSL_PING_ERROR_RECEIVE_PACKETS		-12

typedef struct
{
	uint32_t dwSize;	// Must bes et before call TcpPing
	uint32_t dwNeedTime;
	uint32_t dwTTL;
} SLslPingInfo;

int32_t LASAL32_EXPORTS LslPing( const char *host, uint32_t dwReadTimeout, SLslPingInfo *pInfo );

//==========================================================================================
//=== Wird nur für Linux gebraucht
//==========================================================================================

#ifdef COMPILE_LINUX
LSL_BOOL LslLibraryInit();
void LslLibraryExit();

#endif // COMPILE_LINUX
//==========================================================================================


//==========================================================================================
//=== Refresh List function
//=== 2007-10-24 by Obermayr
//==========================================================================================

int32_t LASAL32_EXPORTS LslRefreshListCreate();
int32_t LASAL32_EXPORTS LslRefreshListDestroy(int32_t iRLB);
LSL_BOOL LASAL32_EXPORTS LslRefreshListOnline(int32_t iRLB, const char* szComm, uint8_t uBaudRate, uint8_t uPcStation, uint8_t uSpsStation);
LSL_BOOL LASAL32_EXPORTS LslRefreshListOffline(int32_t iRLB);
LSL_BOOL LASAL32_EXPORTS LslRefreshListIsOnline(int32_t iRLB);


typedef void __cdecl CB_RLADD_FUNCTYPE(void *pCallbackData, uint32_t dwAddr, uint32_t dwVarID, int32_t nData); // must be "__cdecl" because of FAR PASCAL definitions

LSL_BOOL LASAL32_EXPORTS LslRefreshListSetCallback(int32_t iRLB, CB_RLADD_FUNCTYPE *pCallback, void *pCallbackData);

// Flag for different List or handling
#define LSL_RL_FLAG_DYNAMIC_LIST		0x00000000		// Dynamic RL
#define LSL_RL_FLAG_PERMANENT_LIST		0x00000001		// Permanent RL

// Don't wait for Answer (faster)
#define LSL_RL_FLAGADD_NOANSWER			0x00010000

LSL_BOOL LASAL32_EXPORTS LslRefreshListClear(int32_t iRLB, uint32_t dwFlag);
LSL_BOOL LASAL32_EXPORTS LslRefreshListStart(int32_t iRLB, uint32_t dwFlag);
LSL_BOOL LASAL32_EXPORTS LslRefreshListGetCount(int32_t iRLB, uint32_t dwFlag, uint32_t *pCount);

// Type of the Variable
#define LSL_RL_TYPE_SERVER				0x00000000	// Type: Variable is Server
#define LSL_RL_TYPE_STRINGSERVER		0x00000001	// Type: Variable is Stringserver
#define LSL_RL_TYPE_CLIENT				0x00000002	// Type: Variable is Client
#define LSL_RL_TYPE_GLOBAL				0x00000003	// Type: Variable is Globalvariable
#define LSL_RL_TYPE_OBJECT				0x00000004	// Type: Variable is Object

#define LSL_RL_TYPE_MASK				0x0000000F	// Mask: for general Variable Typeinfo

#define LSL_RL_TYPE_COMMAND				0x00000010	// Flag: Variable is a Command Server/Client
#define LSL_RL_TYPE_SYMTAB				0x00000020	// Flag: Information come from SmbolTable
#define LSL_RL_TYPE_REPARSE				0x00000040	// Flag: Have Pointer, must be parse new before access

#define LSL_RL_TYPE_T_MASK				0x00FF0000	// Mask: for LSL_TYPE_T_NONE, LSL_TYPE_T_BOOL, ...

#define LSL_RL_TYPE_BITNO_MASK			0xFF000000	// Number of bit, if LSL_RL_TYPE_T_MASK == LSL_TYPE_T_BIT

// Types of Symboltable Entrys
#define  LSL_TYPE_T_NONE         0
#define  LSL_TYPE_T_BOOL         1
#define  LSL_TYPE_T_SINT         2
#define  LSL_TYPE_T_INT          3
#define  LSL_TYPE_T_DINT         4
//#define LSL_TYPE_T_LINT        5
#define  LSL_TYPE_T_USINT        6
#define  LSL_TYPE_T_UINT         7
#define  LSL_TYPE_T_UDINT        8
//#define LSL_TYPE_T_ULINT       9
#define  LSL_TYPE_T_REAL        10
#define  LSL_TYPE_T_LREAL       11
//#define LSL_TYPE_T_TIME       12
//#define LSL_TYPE_T_DATE       13
//#define LSL_TYPE_T_TOD        14
//#define LSL_TYPE_T_DT         15
//#define LSL_TYPE_T_BYTE       16
//#define LSL_TYPE_T_WORD       17
//#define LSL_TYPE_T_DWORD      18
//#define LSL_TYPE_T_LWORD      19
#define  LSL_TYPE_T_CHAR        20
#define  LSL_TYPE_T_HSINT       21
#define  LSL_TYPE_T_HINT        22
#define  LSL_TYPE_T_HDINT       23
#define  LSL_TYPE_T_BSINT       24
#define  LSL_TYPE_T_BINT        25
#define  LSL_TYPE_T_BDINT       26
#define  LSL_TYPE_T_ENUMERATED  27
#define  LSL_TYPE_T_ARRAY       28
#define  LSL_TYPE_T_STRUCTURE   29
#define  LSL_TYPE_T_POINTER     30
//#define LSL_TYPE_T_BITFELD    31
#define  LSL_TYPE_T_BIT         32
#define  LSL_TYPE_T_CLASS       33
//#define LSL_TYPE_T_FORWARD    34
//#define LSL_TYPE_T_TEMP_INT   35
//#define LSL_TYPE_T_TEMP_DINT  36
//#define LSL_TYPE_T_TEMP_LINT  37
//#define LSL_TYPE_T_TEMP_UINT  38
//#define LSL_TYPE_T_TEMP_UDINT 39
//#define LSL_TYPE_T_TEMP_ULINT 40
#define  LSL_TYPE_T_CHARARRAY   41


#pragma pack(push, 1)
typedef struct
{
	uint32_t dwAddr;	// Address of the Variable or Server
	uint32_t dwType;	// Have LSL_RL_TYPE_
	uint32_t dwSize;	// must be Zero (for future)
} SRLVarInfo;
#pragma pack(pop)
// Fügt eine Variable zur RefreshListe hinzu
LSL_BOOL LASAL32_EXPORTS LslRefreshListAdd(int32_t iRLB, const SRLVarInfo *pVarInfo, uint32_t dwVarID, uint32_t dwRefreshTime, uint32_t dwFlag);
// Ermittelt Informationen über eine RefreshList Variable
LSL_BOOL LASAL32_EXPORTS LslRefreshListGetVarInfo(int32_t iRLB, const char *lpcName, SRLVarInfo *pVarInfo);
// Liest Daten von einer RefreshList Variable
LSL_BOOL LASAL32_EXPORTS LslRefreshListGetData(int32_t iRLB, const SRLVarInfo *pVarInfo, uint8_t *pData, uint32_t dwSize );
// Schreibt Daten auf eine RefreshList Variable
LSL_BOOL LASAL32_EXPORTS LslRefreshListSetData(int32_t iRLB, const SRLVarInfo *pVarInfo, const uint8_t *pData, uint32_t dwSize );

// Kiefert Flags zurück, über die Unterstüzten Funktionen
#define LSL_RL_SF_APPLID				0x00000001			// RefreshList unterstützt Application ID (Mehrere RL von einem PC)
#define LSL_RL_SF_VARSIZE_1_255			0x00000002			// RefreshList unterstützt unterschiedliche Variablengrößen (1 - 255 Byte). Default ist die Größe 4 Byte
LSL_BOOL LASAL32_EXPORTS LslRefreshListSupportedFunction(int32_t iRLB, uint32_t *pSupportedFunction );

/////////////////////////////////////////////////////////////////////////
// RefreshListEx
// Erweitere RefreshList Create Function
int32_t LASAL32_EXPORTS LslRefreshListCreateExt(const char* szComm, uint8_t uBaudRate, uint8_t uPcStation, uint8_t uSpsStation, const char *lpcName, CB_RLADD_FUNCTYPE *pCallback, void *pCallbackData, uint32_t dwTimeoutMS);
// Initialisiert die SymbolTabelle in der RefreshListe
uint32_t LASAL32_EXPORTS LslRefreshListSymbolTableInit(int32_t iRLB, const char *lpcName);
#pragma pack(push, 1)
typedef struct
{
	uint32_t dwSize;		// Size of SymbolTable
	uint32_t dwVersion;	// Version of Symbol Table
	uint32_t dwCRC;		// CRC about SymbolTable
} SRLSymTabInfo;
#pragma pack(pop)
// Ermittelt Informationen über dir Symbol Tabelle
LSL_BOOL LASAL32_EXPORTS LslRefreshListSymbolTableGetInfo(int32_t iRLB, SRLSymTabInfo *pSymTabInfo);

// Callback für die Funktion LslRefreshListSymbolTableLoad
typedef LSL_BOOL __cdecl CB_RL_FUNCTYPE(void *pData, uint32_t nCurrent, uint32_t nMax); // must be "__cdecl" because of FAR PASCAL definitions
// Ladet die SymbolTabelle in den PC
LSL_BOOL LASAL32_EXPORTS LslRefreshListSymbolTableLoad(int32_t iRLB, uint8_t *pData, uint32_t dwLen, CB_RL_FUNCTYPE *pCallback, void *pCallbackData);

// Füllt die SRLVarInfo mit den entsprechenden Daten
LSL_BOOL LASAL32_EXPORTS LslRefreshListMakeSRLVarInfo(SRLVarInfo *pVarInfo, uint32_t dwAddr, uint32_t dwSize, uint8_t byInfo, uint8_t byType);

// Returniert die Loader Version 0x00002255	-> V02.02.85 oder 0 wenn Fehler
uint32_t LASAL32_EXPORTS LslRefreshListGetLoaderVersion(int32_t iRLB);

// Internal use Only
LSL_BOOL LASAL32_EXPORTS LslRefreshListAddPos(int32_t iRLB, const SRLVarInfo *pVarInfo, uint32_t dwVarID, uint32_t dwRefreshTime, uint32_t dwPos, uint32_t dwFlag);
LSL_BOOL LASAL32_EXPORTS LslRefreshListStartCount(int32_t iRLB, uint32_t dwCount, uint32_t dwFlag);

//==========================================================================================

// Only for Debugging to test some output, work only under WinCE
int32_t LASAL32_EXPORTS LslMessageBox(const char *lpText);


//==========================================================================================
//=== Hardwaretree functions
//==========================================================================================
// Hardwaretree commands
LSL_BOOL LASAL32_EXPORTS LslHardwaretreeCommandH(int32_t ocbNum, int32_t iCmd, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);
LSL_BOOL LASAL32_EXPORTS LslHardwaretreeCommand(int32_t iCmd, void *pInput, int32_t inLen, void *pOutput, int32_t outLen);

//
// get module info
//
LSL_BOOL LASAL32_EXPORTS LslHardwaretreeGetModuleInfoH( int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddressID, uint32_t uiLengthBuffer, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslHardwaretreeGetModuleInfo( uint32_t uiMaster, uint32_t uiAddressID, uint32_t uiLengthBuffer, void *pBuffer );

//
// get hardware path
//
LSL_BOOL LASAL32_EXPORTS LslHardwaretreeGetHWPathH( int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddressID, uint32_t uiLengthBuffer, void *pBuffer );
LSL_BOOL LASAL32_EXPORTS LslHardwaretreeGetHWPath( uint32_t uiMaster, uint32_t uiAddressID, uint32_t uiLengthBuffer, void *pBuffer );
//
// send safety commands and receive response
//
LSL_BOOL LASAL32_EXPORTS LslHardwaretreeSafetyCmdH(	int32_t ocbNum, 
																								uint32_t uiMaster, 
																								uint32_t uiAddressID, 
																								uint32_t uiLenRequest, 
																								void *pRequestBuffer, 
																								uint32_t uiLenResponse,
																								void *pResponseBuffer,
																								uint32_t *puiError );
LSL_BOOL LASAL32_EXPORTS LslHardwaretreeSafetyCmd(	uint32_t uiMaster, 
																								uint32_t uiAddressID, 
																								uint32_t uiLenRequest, 
																								void *pRequestBuffer, 
																								uint32_t uiLenResponse,
																								void *pResponseBuffer,
																								uint32_t *puiError );

/* Write databuffer to a module address
\param ocbNum communication number
\param uiMaster id to the master
\param uiAddress logical address of module
\param uiOffset address in the module memory
\param uiLen length of write-buffer
\param puiError pointer to a integervalue where the errorcode will be set
\param pBuffer pointer to the buffer which should be written
\return 0 if no error 
*/
LSL_BOOL LASAL32_EXPORTS LslHardwaretreeWriteMemoryH(int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );
/* Read databuffer from a module address
\param ocbNum communication number
\param uiMaster id to the master
\param uiAddress logical address of module
\param uiOffset address in the module memory
\param uiLen length of read-buffer
\param puiError pointer to a integervalue where the errorcode will be set
\param pBuffer pointer to the buffer which will be filled with data
\return 0 if no error 
*/
LSL_BOOL LASAL32_EXPORTS LslHardwaretreeReadMemoryH (int32_t ocbNum, uint32_t uiMaster, uint32_t uiAddress, uint32_t uiOffset, uint32_t uiLen, uint32_t *puiError, void *pBuffer );

//==========================================================================================
//=== Funktionen, die mehrere Kommandos in einem zusammenfassen
//==========================================================================================
LSL_BOOL LASAL32_EXPORTS  LslGetServerListH(	int32_t			ocbNum,
											const char* pData,
											uint32_t*		pResult);
LSL_BOOL LASAL32_EXPORTS  LslGetServerList( const char* pData,
										uint32_t*		pResult);

LSL_BOOL LASAL32_EXPORTS LslGetDataListSpecialH(int32_t ocbNum,
											const uint32_t	dwCount,
											const uint32_t* pAddr,
											const uint32_t* pLen,
											char* pResult);
LSL_BOOL LASAL32_EXPORTS LslGetDataListSpecial(	const uint32_t	dwCount,
											const uint32_t* pAddr,
											const uint32_t* pLen,
											char* pResult);

//////////////////////////////////////////////////////////////////////////
// Liest mehrere Daten von der CPU herauf.
//   Versucht dabei das optimum an Geschwindigkeit heraus zu holen. 
//   dabei verwendent es SendDataList / GetDataList / GetData
LSL_BOOL LASAL32_EXPORTS LslGetDataListExH(int32_t ocbNum, const uint32_t dwCount, const uint32_t* pAddr, const uint32_t* pLen, uint8_t *pResult);
LSL_BOOL LASAL32_EXPORTS LslGetDataListEx(const uint32_t dwCount, const uint32_t* pAddr, const uint32_t* pLen, uint8_t *pResult);

//////////////////////////////////////////////////////////////////////////
// Wie GetData, aber nur ohne Längenbeschränkung. 
LSL_BOOL LASAL32_EXPORTS LslGetDataExH(int32_t ocbNum, uint8_t* pBuffer, uint32_t addr0, uint32_t nCount);
LSL_BOOL LASAL32_EXPORTS LslGetDataEx(uint8_t* pBuffer, uint32_t addr0, uint32_t nCount);
// Wie SetData, aber nur ohne Längenbeschränkung. 
LSL_BOOL LASAL32_EXPORTS LslSetDataExH(int32_t ocbNum, const uint8_t* pBuffer, uint32_t addr0, uint32_t nCount);
LSL_BOOL LASAL32_EXPORTS LslSetDataEx(const uint8_t* pBuffer, uint32_t addr0, uint32_t nCount);

// Verschiedene andere Funktionen
uint32_t LASAL32_EXPORTS LslGetCounterMS();
uint64_t LASAL32_EXPORTS LslGetCounterMS64();
uint32_t LASAL32_EXPORTS LslGetCounterUS();
uint64_t LASAL32_EXPORTS LslGetCounterUS64();
LSL_BOOL LASAL32_EXPORTS LslCRC(const uint8_t *pData, uint32_t dwSize);
LSL_BOOL LASAL32_EXPORTS LslCRC_S(const uint8_t *pData, uint32_t dwSize, uint32_t dwCRCStart);
uint32_t LASAL32_EXPORTS LslGetLastError();

/*########################################################################
 ### LslDirect Communication
 ########################################################################*/

#define LSL_DOCALLBACK_TYPE_DATA					0
#define LSL_DOCALLBACK_TYPE_CONNECT_ABORTED			1
// Callback prototype
// param:	pCookie			a user paramter
//			nType			type a the callback (DOCALLBACK_TYPE_DATA, DOCALLBACK_TYPE_CONNECT_ABORTED)
//			nCmd			the receive Command id
//			pData			pointer to the receive data
//			nLen			length of the receive data
typedef void __cdecl DO_CALLBACK_FUNCTYPE(void *pCookie, uint32_t nType, uint32_t nCmd, const uint8_t *pData, uint32_t nLen); // must be "__cdecl" because of FAR PASCAL definitions


// function: LslDirectCreateDOB
// return:	-1				a error occurred (use LslGetLastError function)
//			>= 0			a valid DOB
int32_t LASAL32_EXPORTS LslDirectCreateDOB();

// function: LslDirectDestroyDOB
// param:	nDOB			the nDOB from LslDirectCreateDOB
// return:	0				no error
//			not 0			the error number
int32_t LASAL32_EXPORTS LslDirectDestroyDOB(int32_t nDOB);

// function: LslDirectOnline
// param:	lpTcp			string format "TCP:10.10.115.43"
//			nPort			if nPort 0 , default Port is used.
//			pCallback		pointer to a callback function
//			pCookie			user data, that will put with the callback
// return:	-1				a error occurred 
//			>= 0			a valid DOB
int32_t LASAL32_EXPORTS LslDirectOnline(int32_t nDOB, const char *lpTcp, uint32_t nPort, DO_CALLBACK_FUNCTYPE *pCallback, void *pCookie);

// function: LslDirectOffline
// param:	bDOB			a valid DOB from LslDirectCreateDOB
// return:	0				no error
//			not 0			the error number
int32_t LASAL32_EXPORTS LslDirectOffline(int32_t nDOB);

// function: LslDirectIsOnline
// param:	bDOB			a valid DOB from LslDirectCreateDOB
// return:	FALSE (0)		not online or error
//			TRUE (1)		online ok
LSL_BOOL LASAL32_EXPORTS LslDirectIsOnline(int32_t nDOB);

// function: LslDirectSend
// param:	bDOB			a valid DOB from LslDirectCreateDOB
//			nCmd			command id for send
//			pSend			pointer to send data
//			nSendLen		length of the send data
// return:	0				no error
//			not 0			the error number
int32_t LASAL32_EXPORTS LslDirectSend(int32_t nDOB, uint32_t nCmd, const uint8_t *pSend, uint32_t nSendLen);

// function: LslDirectReceiveCount
// param:	bDOB			a valid DOB from LslDirectCreateDOB
//			pCount			datapackage counter
// return:	0				no error
//			not 0			the error number
int32_t LASAL32_EXPORTS LslDirectReceiveCount(int32_t nDOB, uint32_t *pCount);

// function: LslDirectReceive
// param:	bDOB			a valid DOB from LslDirectCreateDOB
//			pnType			datapackage counter
//			pnCmd			datapackage counter
//			pBuffer			datapackage counter
//			nBufSize		datapackage counter
//			pSize			datapackage counter
//			dwFlags			datapackage counter
// return:	0				no error
//			not 0			the error number
#define LSL_DO_RECEIVE_NOWAIT				0x00000001		// return ERROR_SIGMA32_DO_RECEIVE_NO_DATA if are no data available
#define LSL_DO_RECEIVE_NOTIMEOUT			0x00000002		// wait for data with no timeout (default 10 sec)
int32_t LASAL32_EXPORTS LslDirectReceive(int32_t nDOB, uint32_t *pnCmd, uint32_t *pnRealSize, uint8_t *pBuffer, uint32_t nBufSize, uint32_t dwFlags);

// function: LslDirectSetParam
// param:	bDOB			a valid DOB from LslDirectCreateDOB
//			nType			Type of Parameter (see LSL_DO_SET_TYPE_ )
//			nData			Data of Parameter
// return:	0				no error
//			not 0			the error number
#define LSL_DO_SET_TYPE_TIMEOUT_RECEIVE		0		// Data us timeout value in milli seconds
int32_t LASAL32_EXPORTS LslDirectSetParam(int32_t nDOB, uint32_t nType, uint32_t nData);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // LASAL32_EXCLUDE_EXPFUNCS

#endif // __LASAL32_H__
