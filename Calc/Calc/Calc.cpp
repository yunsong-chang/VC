// Calc.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <Windows.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int a = 4096;

	cout << "dec=" << dec << a << endl;
	cout << "hex=0x" << hex << a << endl;
	cout << "oct=" << oct << a <<endl;

	return 0;
}
