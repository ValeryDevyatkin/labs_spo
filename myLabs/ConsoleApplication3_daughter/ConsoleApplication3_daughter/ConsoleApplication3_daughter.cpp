// ConsoleApplication3_daughter.cpp: определяет точку входа для консольного приложения.
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

int main(int n, char** s)
{
	cout << endl << s[0]  << endl << s[2] << endl;
	HANDLE myFile = CreateFile(
		s[2], // Имя файла
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (myFile == INVALID_HANDLE_VALUE) { 
		cout << "File is not opened." << endl;
	}
	else {
		cout << "File is opened." << endl;
		info line[10];
		int n = GetFileSize(myFile, NULL) / (sizeof(line[0]) - 5);
		for (int i = 0; i < n; i++) {
			ReadFile(myFile, &line[i].num, sizeof(line[i].num) - 1, NULL, NULL);
			ReadFile(myFile, &line[i].des, sizeof(line[i].des) - 1, NULL, NULL);
			ReadFile(myFile, &line[i].t, sizeof(line[i].t) - 1, NULL, NULL);
			ReadFile(myFile, &line[i].am, sizeof(line[i].am) - 1, NULL, NULL);
			ReadFile(myFile, &line[i].spec, sizeof(line[i].spec) - 1, NULL, NULL);
		}
		CloseHandle(myFile);

		cout << "Enter number of train:" << endl;
		cin >> line[atoi(s[1])].num;
		cout << "Enter destination point:" << endl;
		cin >> line[atoi(s[1])].des;
		cout << "Enter departure time:" << endl;
		cin >> line[atoi(s[1])].t;
		cout << "Enter amount of free spaces:" << endl;
		cin >> line[atoi(s[1])].am;

		HANDLE myFile = CreateFile(
			s[2], // Имя файла
			GENERIC_WRITE,
			FILE_SHARE_WRITE,
			NULL,
			TRUNCATE_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		);
		SetFilePointer(myFile, 0, 0, FILE_BEGIN);
		for (int i = 0; i < n; i++) {
			WriteFile(myFile, &line[i].num, sizeof(line[i].num) - 1, NULL, NULL);
			WriteFile(myFile, &line[i].des, sizeof(line[i].des) - 1, NULL, NULL);
			WriteFile(myFile, &line[i].t, sizeof(line[i].t) - 1, NULL, NULL);
			WriteFile(myFile, &line[i].am, sizeof(line[i].am) - 1, NULL, NULL);
			WriteFile(myFile, &line[i].spec, sizeof(line[i].spec) - 1, NULL, NULL);
		}
		FlushFileBuffers(myFile);
		cout << endl << "File is rewrited." << endl;
		CloseHandle(myFile);
	}
	system("pause");
	cout << endl;
    return 0;
}

