#pragma once			//��ֹͷ�ļ��ظ�����
#include <iostream>		//�������������ͷ�ļ�
using namespace std;	//ʹ�ñ�׼�����ռ�
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"
#include <fstream>					    //�ļ�����ͷ�ļ�
#define FILENAME "WorkerFile.txt"		//�궨�壺�ļ���

class WorkerManager		
{
public:
	// ���캯������
	WorkerManager();
	// ������������
	~WorkerManager();

	//��չʾ�˵���
	void ShowMenu();

	//��0.�˳�ϵͳ��
	void ExitSystem();

	//��1.���ְ����
	void add_Worker();

	// �����ļ�
	void save();

	// ͳ���ļ�������
	int get_WorkerNum();

	// ��ʼ��ְ��
	void init_Worker();

	//��2.��ʾְ����
	void show_Worker();

	//��3.ɾ��ְ����
	void del_Worker();

	// ְ���Ƿ���ڣ������򷵻�ְ����š����򷵻�-1
	int is_Exist(int id);

	//��4.�޸�ְ����
	void modify_Worker();

	// ְ���Ƿ��ظ�
	bool is_repetition(int id);
	bool is_repetition(string name);

	//��5.����ְ����
	void find_worker();

	//��6.����
	void sort_Worker();

	// ѡ������1.����,2.����
	void select_sort(int select);

	//��7.����ļ���
	void clean_File();

public:
	//����¼ְ��������
	int m_workerNumber;

	//��ְ������ָ�롿
	Worker ** m_workerArray;

	//���ļ��Ƿ�Ϊ�ա�
	bool m_fileIsEmpty;



};