// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h> 
#include <time.h>
#include <conio.h>
using namespace std;

HANDLE hSemaphore;
int mas[20];

int thread01() { 
	// Поток, заполняющий массив
	srand(time(NULL));
	for (int i = 0; i < 21; i++) {
		mas[i] = rand()%20+1;
		Sleep(100);
		ReleaseSemaphore(hSemaphore,1,NULL);
	} 
	return 0;
}

int thread02() { 
	// Поток, извлекающий элементы массива 
	for (int i = 0; i < 21; i++) { 
		WaitForSingleObject(hSemaphore, INFINITE);
		Sleep(50);
		cout << "mas[" << i << "]= ";
		if ((i + 1) % 2 == 0) {
			mas[i] = 0;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		}		
		cout << mas[i];
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout << endl;
	} 
	return 0; 
}

int main() { 
	// Создание семаформа 
	hSemaphore=CreateSemaphore(NULL, 0, 21, "MySemaphore");
	if (hSemaphore == NULL) 
		cout << "Create semaphore failed" << GetLastError() << endl;

	HANDLE hTh01 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread01, NULL, 0, NULL); 
	if (hTh01 == NULL) return GetLastError();

	HANDLE hTh02 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread02, NULL, 0, NULL);
	if (hTh02 == NULL) return GetLastError();

	_getch(); // Закрытие семафора 
	CloseHandle(hSemaphore); // Закрытие потоков
	CloseHandle(hTh01);
	CloseHandle(hTh02); 
	return 0; 
}

