#pragma once

#include"stdafx.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<windows.h>

class Thread {
private:
	static int k; //кол-во экземпляров класса
	int n; //счетчик
	int duration; //временной интервал для вычислений внутри потока
	HANDLE hTh;
	DWORD IDTh;
	friend void callback(Thread*); //исполняемая потоком функция
	DWORD start(); //инициализация потока
public:
	Thread(int); 
	Thread(); 
	~Thread();
	friend void table(int, Thread*[]); //визуализация работы потоков
	int getK(); //геттер
};
