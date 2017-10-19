// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<Windows.h>
using namespace std;

struct info {
	char num[10]=""; //номер поезда
	char des[10]=""; //пункт назначения
	char t[10]=""; //время отправления
	char am[10]=""; //кол-во свободных мест
	char spec[3]="\r\n";
};

LPCTSTR enterName() {
	//функция для ввода имени файла с клавиатуры
	system("cls");
	char name[10] = "X", t[10];
	cout << "Enter file name: ";
    cin >> t; 
	strcat_s(t, "X.txt");
	strcat_s(name, t);
	LPCTSTR s = name;
	return s;
}

void addLine() {
	info line;
	HANDLE myFile = CreateFile(
		enterName(), // Имя файла
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (myFile == INVALID_HANDLE_VALUE) {
		cout << "File is not opened." << endl;
		goto end;
	}
	else 
		SetFilePointer(myFile, 0, 0, FILE_END);
		cout << "File is opened." << endl;
	
	cout << "Enter number of train:" << endl;
	cin >> line.num; 
	cout << "Enter destination point:" << endl;
	cin >> line.des;
	cout << "Enter departure time:" << endl;
	cin >> line.t;
	cout << "Enter amount of free spaces:" << endl;
	cin >> line.am;

	//записываем в файл поля структуры исключая нуль-терминатор
	WriteFile(myFile, &line.num, sizeof(line.num)-1, NULL, NULL);
	WriteFile(myFile, &line.des, sizeof(line.des)-1, NULL, NULL);
	WriteFile(myFile, &line.t, sizeof(line.t)-1, NULL, NULL);
	WriteFile(myFile, &line.am, sizeof(line.am)-1, NULL, NULL);
	WriteFile(myFile, &line.spec, sizeof(line.spec)-1, NULL, NULL);
	FlushFileBuffers(myFile);
	cout << endl << "Line is added." << endl;
	CloseHandle(myFile);
end:
	system("pause");
}

void readFile() {
	HANDLE myFile = CreateFile(
		enterName(), // Имя файла
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (myFile == INVALID_HANDLE_VALUE) {
		cout << "File is not opened." << endl;
		goto end;
	}
	else
		cout << "File is opened." << endl;

	info line[10]; 
	for (int i = 0; i<GetFileSize(myFile, NULL)/(sizeof(line[i])-5); i++) {
		ReadFile(myFile, &line[i].num, sizeof(line[i].num) - 1, NULL, NULL);
		ReadFile(myFile, &line[i].des, sizeof(line[i].des) - 1, NULL, NULL);
		ReadFile(myFile, &line[i].t, sizeof(line[i].t) - 1, NULL, NULL);
		ReadFile(myFile, &line[i].am, sizeof(line[i].am) - 1, NULL, NULL);
		ReadFile(myFile, &line[i].spec, sizeof(line[i].spec) - 1, NULL, NULL);
		cout << line[i].num << " " << line[i].des << " " << line[i].t << " " << line[i].am  << endl;
	}

	//выполняем поиск поездов, которые имеют свободные места до указанного пункта назначения
	char req[10]=""; 
	cout  << "Enter destination point: ";
	cin >> req;
	for (int i = 0; i<GetFileSize(myFile, NULL) / (sizeof(line[i]) - 5); i++) {
		if (strcmp(line[i].des, req)==0 && atoi(line[i].am)>0) 
			cout << line[i].num << " " << line[i].des << " " << line[i].t << " " << line[i].am << endl;
	}
	CloseHandle(myFile);
end:
	system("pause");
}

void delFile() {
	if (DeleteFile(enterName())) cout << "File is deleted." << endl;
	else cout << "File is not deleted." << endl;
	system("pause");
}

void newFile() {
	LPCTSTR file=enterName();
	HANDLE myFile = CreateFile(
		file, // Имя файла
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (myFile == INVALID_HANDLE_VALUE)
		cout << "Error." << endl; // Файл не создан
	else
		cout << "File is created." << endl; // Файл создан
	CloseHandle(myFile);
	system("pause");
}

void menu() {
	char k[10];
start:
	system("cls");
	cout << "1: create new file," << 
		endl << "2: add new line," << 
		endl << "3: delete file," << 
		endl << "4: read file," <<
		endl << "5: EXIT." << endl;
	cin>>k; 
	if (atoi(k)<1 || atoi(k)>5) 
		goto start; 
	else 
		switch (atoi(k)) {
		case 1: newFile(); goto start;
		case 2: addLine(); goto start;
		case 3: delFile(); goto start;
		case 4: readFile(); goto start;
		case 5: system("cls"); break;
		default: goto start;
		}
}

int main() {
	menu();
	system("pause");
    return 0;
}

