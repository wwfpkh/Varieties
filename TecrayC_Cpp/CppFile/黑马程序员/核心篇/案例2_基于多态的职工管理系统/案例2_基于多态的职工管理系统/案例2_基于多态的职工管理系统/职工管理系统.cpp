#include <iostream>
using namespace std;
#include "WorkerManager.h"
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"

int main()
{

	// ʵ���������߶���
	WorkerManager wm;

	int choice = 0;		// �û���ѡ��

	while (true)
	{
		wm.ShowMenu();  // չʾ�˵�
		cout << "����������ѡ��" << endl;
		cin >> choice;	//�����û�ѡ��

		//���û�ѡ��ӿڡ�
		switch (choice)
		{
		case 0:		//�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:		//����ְ��
			wm.add_Worker();
			break;
		case 2:		//��ʾְ��
			wm.show_Worker();
			break;
		case 3:		//ɾ��ְ��
			wm.del_Worker();
			break;
		case 4:		//�޸�ְ��
			wm.modify_Worker();
			break;
		case 5:		//����ְ��
			wm.find_worker();
			break;
		case 6:		//����ְ��
			wm.sort_Worker();
			break;
		case 7:		//����ĵ�
			wm.clean_File();
			break;
		default:
			system("cls");	//������������Ч���֣�
			break;
		}

	}

	system("pause");
	return 0;
}
