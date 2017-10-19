// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <time.h>
#include<iomanip>
#include<conio.h>
using namespace std;

CRITICAL_SECTION CrS;
const int n = 6;
LONG mas[n] = { 0, };

void thread01()
{
	srand(time_t(NULL));
	int i = n;
	while (true) {
		if (i == -1) i = n-1;
		EnterCriticalSection(&CrS);
		LONG k = rand()%7-3;
		InterlockedExchange(&mas[i], k);
		Sleep(300);
		LeaveCriticalSection(&CrS);
		i--;
		Sleep(20);
	}
}

void thread02()
{
	int k = n;
	while (true) {
		if (k == -1) k = n-1;
		EnterCriticalSection(&CrS);
		system("cls");
		for (int i = 0; i < n; i++) {
			if (i==k) 	
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			else 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			cout << setw(4) << mas[i];
		}
		cout << endl;
		if (!mas[0]) {
			for (int i = 1; i < n; i++) {
				if (mas[i] > 0) {
					InterlockedExchange(&mas[0], mas[i]);
					break;
				}
			}
		}
		Sleep(300);
		LeaveCriticalSection(&CrS);
		k--;
		Sleep(20);
	}
}

int main()
{
	InitializeCriticalSection(&CrS);

	HANDLE hTh01; DWORD IDTh01;
	hTh01 = CreateThread(NULL, 0,
		(LPTHREAD_START_ROUTINE)thread01, NULL, 0, &IDTh01);
	if (hTh01 == NULL) return GetLastError();

	Sleep(50);

	HANDLE hTh02; DWORD IDTh02;
	hTh02 = CreateThread(NULL, 0,
		(LPTHREAD_START_ROUTINE)thread02, NULL, 0, &IDTh02);
	if (hTh02 == NULL) return GetLastError();

	_getch();
	DeleteCriticalSection(&CrS);
	// Закрытие потока
	CloseHandle(hTh01);
	CloseHandle(hTh02);
	return 0;
}
