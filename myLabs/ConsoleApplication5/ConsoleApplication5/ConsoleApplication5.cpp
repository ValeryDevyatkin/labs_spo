// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"myThread.h"
using namespace std;

int main()
{
	Thread t1, t2(222), t3(333), t4(121), t5(501);
	Thread *args[] = { &t1, &t2, &t3, &t4, &t5 };
	int n = t1.getK();
	table(n, args);
	cout << endl;
	system("pause");
	return 0;
    return 0;
}

