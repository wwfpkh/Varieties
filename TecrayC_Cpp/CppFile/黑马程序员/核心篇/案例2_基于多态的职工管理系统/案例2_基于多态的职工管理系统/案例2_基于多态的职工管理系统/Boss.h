//�ϰ���
#pragma once			//��ֹͷ�ļ��ظ�����
#include <iostream>		//�������������ͷ�ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include <string>
#include "Worker.h"

//�ϰ���
class Boss :public Worker
{
public:

	// ���캯��
	Boss(int id, string name, int did);


	// ��ʾ������Ϣ
	virtual void showInfo();
	// ��ȡ��λ����
	virtual string getDepartID();



};