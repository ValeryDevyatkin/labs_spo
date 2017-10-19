// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
using namespace std;

void fileOp() {
	STARTUPINFO StartupInfo;
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	PROCESS_INFORMATION ProcInfo;
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));
	char AppName[] = "c:\\Users\\local-V97\\Documents\\Visual Studio 2015\\Projects\\ConsoleApplication1\\x64\\Debug\\ConsoleApplication1.exe";
	if (!CreateProcess(AppName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE,
		NULL, NULL, &StartupInfo, &ProcInfo)) cout << "Error!" << endl;
	WaitForSingleObject(ProcInfo.hProcess, INFINITE);
	CloseHandle(ProcInfo.hProcess);
	CloseHandle(ProcInfo.hThread);
}

void MainProc() {
	STARTUPINFO StartupInfo;
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	PROCESS_INFORMATION ProcInfo;
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));
	char AppName[] = "c:\\Users\\local-V97\\Documents\\Visual Studio 2015\\Projects\\ConsoleApplication3_main\\Debug\\ConsoleApplication3_main.exe";
	if (!CreateProcess(AppName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE,
		NULL, NULL, &StartupInfo, &ProcInfo)) cout << "Error!" << endl;
	WaitForSingleObject(ProcInfo.hProcess, INFINITE);
	CloseHandle(ProcInfo.hProcess);
	CloseHandle(ProcInfo.hThread);
}

bool menu() {
	system("cls");
	cout << "1: file operations," << endl;
	cout << "2: MainProc," << endl;
	cout << "3: Exit."<<endl;
	int k;
	cin >> k;
	switch (k)
	{
	case 1: fileOp();  break;
	case 2: MainProc(); break;
	case 3: return false; break;
	default: break;
	}
	return true;
}

int main()
{
	while (menu()) {}
	system("pause");
	return 0;
}
