// Time.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "atltime.h"   
#include <iostream>   
using namespace std;  


int _tmain(int argc, _TCHAR* argv[])   
{   
	CString strTime;  // ���ڽ�CTime�����ʽ��Ϊ�ַ���   
	// ��ȡ��ǰʱ�䲢���浽curTime   
	CTime curTime = CTime::GetCurrentTime();   

	int nYear = curTime.GetYear();  // ��ȡ��ǰ���   
	int nMonth = curTime.GetMonth(); // ��ȡ��ǰ�·�   
	int nDay = curTime.GetDay();   // ��ȡ��ǰ����   
	int nHour = curTime.GetHour();  // ��ȡ��ǰСʱʱ��   
	int nMin = curTime.GetMinute(); // ��ȡ��ǰ����ʱ��   
	int nSec = curTime.GetSecond(); // ��ȡ��ǰ��ʱ��   

	// �����ǰʱ��   
	cout<<"��ǰʱ�䣺"<<endl;   
	cout<<nYear<<"��"<<nMonth<<"��"<<nDay<<"��"<<nHour<<"ʱ"<<nMin<<"��"<<nSec<<"��"<<endl;   

	// Ϊ����ʱ���趨һ����ʼʱ�䲢���   
	CTime startTime = CTime(2010,7,3,10,20,30);   
	cout<<"��ʼʱ�䣺"<<endl;   
	cout<<startTime.GetYear()<<"��"<<startTime.GetMonth()<<"��"<<startTime.GetDay()<<"��"<<startTime.GetHour()<<"ʱ"<<startTime.GetMinute()<<"��"<<startTime.GetSecond()<<"��"<<endl;   

	// ����ʱ���   
	CTimeSpan timeSpan;   
	timeSpan = curTime - startTime;   
	cout<<"��ʱ����"<<endl;   
	cout<<timeSpan.GetDays()<<"��"<<timeSpan.GetHours()<<"Сʱ"<<timeSpan.GetMinutes()<<"��"<<timeSpan.GetSeconds()<<"��"<<endl;   
	cout<<"��Сʱ����"<<timeSpan.GetTotalHours()<<"Сʱ"<<endl;   
	cout<<"�ܷ�������"<<timeSpan.GetTotalMinutes()<<"��"<<endl;   
	cout<<"��������"<<timeSpan.GetTotalSeconds()<<"��"<<endl;      

	// ����ǰʱ��curTime�����ʽ��Ϊ�ַ���   
	strTime = curTime.Format(_T("%Y-%m-%d %H:%M:%S"));   
	//strTime = curTime.Format(_T("%c"));   

	// �����ʽ���ַ����������ַ���ʹ��Unicode�ַ�������Ҫʹ��wcout���   
	wcout<<(LPCTSTR)strTime<<endl;   

	return 0;   
} 

