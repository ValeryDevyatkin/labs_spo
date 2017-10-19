#include"stdafx.h"
#include"myThread.h"
using namespace std;

Thread::Thread(int time) : duration(time), n(0) { k++; }
Thread::Thread() : duration(500), n(0) { k++; }
Thread::~Thread() { TerminateThread(hTh, 0);  CloseHandle(hTh); }

//Инициализация статической переменной
int Thread::k = 0;

//геттер
int Thread::getK() { return k; }

//START----------------START
DWORD Thread::start() {
	hTh = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)callback, this, 0, &IDTh);
	if (hTh == NULL) return GetLastError();
}

//CALLBACK----------------CALLBACK
void callback(Thread* t) {
	while (true) {
		t->n++;
		Sleep(t->duration);
		if (t->n == 10 && t->k) {
			t->k--;
			if (t->k == 0) return;
		}
	}
}

//TABLE----------------TABBLE
void table(int n, Thread *args[]) {
	for (int i = 0; i < n; i++) {
		args[i]->start();
	}
	for (int i = 0; i < n; i++) {
		cout << setw(9) << "Thread0" << i;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << setw(10) << "########";
	}
	cout << endl;
	while (char c = _getch() != '\r') {
		for (int i = 0; i < n; i++) {
			cout << setw(10) << args[i]->n;
		}
		cout << endl;
	}
}