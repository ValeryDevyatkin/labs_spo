#pragma once

#include"stdafx.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<windows.h>

class Thread {
private:
	static int k; //���-�� ����������� ������
	int n; //�������
	int duration; //��������� �������� ��� ���������� ������ ������
	HANDLE hTh;
	DWORD IDTh;
	friend void callback(Thread*); //����������� ������� �������
	DWORD start(); //������������� ������
public:
	Thread(int); 
	Thread(); 
	~Thread();
	friend void table(int, Thread*[]); //������������ ������ �������
	int getK(); //������
};
