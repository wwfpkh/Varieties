//ְ����
#pragma once			//��ֹͷ�ļ��ظ�����
#include <iostream>		//�������������ͷ�ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include <string>

class Worker
{
public:
	
	// ��ʾ������Ϣ
	virtual void showInfo() = 0;

	// ��ȡ��λ����
	virtual string getDepartID() = 0;

	// ְ�����
	int m_ID;
	// ����
	string m_Name;
	// ���ű��
	int m_DepartID;
};