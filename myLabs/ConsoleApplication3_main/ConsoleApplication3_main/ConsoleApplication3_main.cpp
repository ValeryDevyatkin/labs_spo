// ConsoleApplication3_main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
using namespace std;

struct info {
	char num[10] = ""; //номер поезда
	char des[10] = ""; //пункт назначения
	char t[10] = ""; //время отправления
	char am[10] = ""; //кол-во свободных мест
	char spec[3] = "\r\n";
};

int main()
{
	char nam[300] = "X"; char t[300];
	cout << "Enter file name: ";
	cin >> t;
	strcat_s(t, "X.txt");
	strcat_s(nam, t);
	HANDLE myFile = CreateFile(
		nam, // Имя файла
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (myFile == INVALID_HANDLE_VALUE) cout << "File is not opened." << endl;
	else {
		cout << "File is opened." << endl;
		info line[10];
		int k = GetFileSize(myFile, NULL) / (sizeof(line[0]) - 5);
		for (int i = 0; i < k; i++) {
			ReadFile(myFile, &line[i].num, sizeof(line[i].num) - 1, NULL, NULL);
			ReadFile(myFile, &line[i].des, sizeof(line[i].des) - 1, NULL, NULL);
			ReadFile(myFile, &line[i].t, sizeof(line[i].t) - 1, NULL, NULL);
			ReadFile(myFile, &line[i].am, sizeof(line[i].am) - 1, NULL, NULL);
			ReadFile(myFile, &line[i].spec, sizeof(line[i].spec) - 1, NULL, NULL);
			cout << line[i].num << " " << line[i].des << " " << line[i].t << " " << line[i].am << endl;
		}
		CloseHandle(myFile);

		STARTUPINFO StartupInfo;
		ZeroMemory(&StartupInfo, sizeof(StartupInfo));
		StartupInfo.cb = sizeof(StartupInfo);
		PROCESS_INFORMATION ProcInfo;
		ZeroMemory(&ProcInfo, sizeof(ProcInfo));
		char Args[300] = "c:\\Users\\local-V97\\Documents\\Visual Studio 2015\\Projects\\ConsoleApplication3_daughter\\Debug\\ConsoleApplication3_daughter.exe ";
		char n[300];
		cout << "Enter line number: ";
		cin >> n;
		if (atoi(n) > k) return 1;
		strcat_s(Args, n);
		strcat_s(Args, " ");
		strcat_s(Args, nam);
		if (!CreateProcess(NULL, Args, NULL, NULL, FALSE, 0,
			NULL, NULL, &StartupInfo, &ProcInfo)) cout << "Error!" << endl;
		WaitForSingleObject(ProcInfo.hProcess, INFINITE);
		CloseHandle(ProcInfo.hProcess);
		CloseHandle(ProcInfo.hThread);

		HANDLE myFile = CreateFile(
			nam, // Имя файла
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		);
		if (myFile == INVALID_HANDLE_VALUE) cout << "File is not opened." << endl;
		else {
			cout << "File is opened." << endl;
			info line[10];
			for (int i = 0; i < GetFileSize(myFile, NULL) / (sizeof(line[i]) - 5); i++) {
				ReadFile(myFile, &line[i].num, sizeof(line[i].num) - 1, NULL, NULL);
				ReadFile(myFile, &line[i].des, sizeof(line[i].des) - 1, NULL, NULL);
				ReadFile(myFile, &line[i].t, sizeof(line[i].t) - 1, NULL, NULL);
				ReadFile(myFile, &line[i].am, sizeof(line[i].am) - 1, NULL, NULL);
				ReadFile(myFile, &line[i].spec, sizeof(line[i].spec) - 1, NULL, NULL);
				cout << line[i].num << " " << line[i].des << " " << line[i].t << " " << line[i].am << endl;
			}
			CloseHandle(myFile);
		}
	}
	system("pause");
    return 0;
}

