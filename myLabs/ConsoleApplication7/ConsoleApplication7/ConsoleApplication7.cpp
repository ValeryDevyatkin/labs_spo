// ConsoleApplication7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream> 
#include <windows.h> 
#include <time.h>
#include <iomanip>
#include <conio.h>
using namespace std;

const int n = 10;
LONG mas[n] = { 0, };

int thread01(){ 
	srand(time(NULL));
	// �������� �������� 
	HANDLE hMutex01 = OpenMutex(SYNCHRONIZE, FALSE, "MyMutex");
	if (hMutex01 == NULL) cout << "Open mutex01 failed" << GetLastError() << endl;

	for (int i = 0; i < 3; i++) 
	{ 
		WaitForSingleObject(hMutex01, INFINITE); // ������ �������� 
		for (int j = 0; j < n; j++) { 
			LONG k = rand() % 19 - 9;
			InterlockedExchange(&mas[j], k);
			cout << setw(3)  << mas[j]; 
			Sleep(100); 
		}
		cout << endl;
		ReleaseMutex(hMutex01); // ������������ �������� 
	} 

	CloseHandle(hMutex01); 
	return 0; 
}

int thread02() { 
	// �������� �������� 
	HANDLE hMutex02 = OpenMutex(SYNCHRONIZE, FALSE, "MyMutex");
	if (hMutex02 == NULL) cout << "Open mutex02 failed" << GetLastError() << endl; 

	for (int i = 0; i < 3; i++) 
	{
		WaitForSingleObject(hMutex02, INFINITE);// ������ �������� 
		for (int j = 0; j < n; j++) { 
			if (mas[j]>0) InterlockedExchange(&mas[j], 0);
			cout << setw(3) << mas[j];
			Sleep(100);
		}
		cout << endl<<endl;
		ReleaseMutex(hMutex02); // ������������ �������� 
	}

	CloseHandle(hMutex02); 
	return 0; 
}

int main()
{ // �������� �������� 
	HANDLE hMutex = CreateMutex(NULL, FALSE, "MyMutex"); 
	if (hMutex == NULL) cout << "Create mutex failed" << GetLastError() << endl;

	HANDLE hTh01 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread01, NULL, 0, NULL);
	if (hTh01 == NULL) return GetLastError();

	Sleep(20);

	HANDLE hTh02 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread02, NULL, 0, NULL);
	if (hTh02 == NULL) return GetLastError();

	_getch(); // �������� �������� 
	CloseHandle(hMutex); // �������� ������� 
	CloseHandle(hTh01); 
	CloseHandle(hTh02); 
	return 0; 
}