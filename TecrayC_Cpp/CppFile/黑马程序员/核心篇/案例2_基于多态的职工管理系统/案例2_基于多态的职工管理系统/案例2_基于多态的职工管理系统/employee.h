//��ͨԱ����
#pragma once			//��ֹͷ�ļ��ظ�����
#include <iostream>		//�������������ͷ�ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include <string>
#include "Worker.h"

//Ա����
class Employee:public Worker
{
public:

	// ���캯��
	Employee(int id , string name , int did);


	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ��λ����
	virtual string getDepartID();



};