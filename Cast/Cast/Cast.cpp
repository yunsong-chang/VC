// Cast.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define TEST_INT_UINT_CMP	0
#define TEST_INT_UINT_ADD	0
#define TEST_CHAR_UCHAR		0
#define TEST_CHAR_255		0
#define TEST_CHAR_255_2		0
#define TEST_CHAR_255_3		1


#if TEST_INT_UINT_CMP
int _tmain(int argc, _TCHAR* argv[])
{
	int a = -1;
	unsigned int b = 16;

	if(a > b)			// ��Ϊ�޷��űȽϵĻ��ָ�� jbe�� �з��űȽ� jle
		cout<<"������Ȼ���������ˣ�\n";


	return 0;
}
#endif

#if TEST_INT_UINT_ADD
int main()
{

	int a = -1;
	unsigned int b = 16;
	unsigned int ret = 0;

	cout<<a+b<<endl;
	ret = a + b;

	int c = -16;
	unsigned int d = 15;

	cout<<c+d<<endl;
	ret = c + d;

	return 0;

}
#endif

#if TEST_CHAR_UCHAR
int main()
{
	char a = -16;
	unsigned char b = 14;
	unsigned int ret = 0;

	if(a > b)
		cout<<"�������������ˣ�\n";

	cout<<a+b<<endl;
	ret = a+b;

	return 0;
}
#endif

#if TEST_CHAR_255
int main()
{
	char a = -16;
	unsigned char b = 255;
	char c = 255;

	cout<<a+b<<endl;
	cout<<a+c<<endl;

	return 0;

}
#endif

#if TEST_CHAR_255_2
int main()
{
	char a = 255;
	unsigned int b = a;

	cout<<b<<endl;

	char c = 15;
	unsigned int d = c;

	cout<<d<<endl;

	return 0;
}
#endif

#if TEST_CHAR_255_3
int main()
{
	unsigned char a = 255;
	int b = a;

	cout<<b<<endl;

	unsigned char c = 15;
	int d = c;

	cout<<d<<endl;

	return 0;
}
#endif

