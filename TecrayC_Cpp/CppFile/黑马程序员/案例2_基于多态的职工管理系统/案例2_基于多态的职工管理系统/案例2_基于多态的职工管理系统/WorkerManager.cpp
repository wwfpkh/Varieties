#include "WorkerManager.h"

// ���캯��
WorkerManager::WorkerManager()
{
	// ���ļ�
	ifstream ifs;		//���ļ���
	ifs.open(FILENAME, ios::in);	//�ļ�·�����򿪷�ʽ

	// ���1���ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		// ��ʼ������
		this->m_workerNumber = 0;		//ְ������Ϊ0
		this->m_workerArray = NULL;		//ְ��ָ������Ϊ��
		this->m_fileIsEmpty = true;		//�ļ�Ϊ��

		ifs.close();	//�ر��ļ�
		return;
	}

	// ���2���ļ����ڣ�����������
	char ch;
	ifs >> ch;			//��ȡһ���ֽ�����
	if (ifs.eof())		//�����ȡ������ĩβ
	{
		cout << "�ļ�Ϊ��" << endl;
		// ��ʼ������
		this->m_workerNumber = 0;		//ְ������Ϊ0
		this->m_workerArray = NULL;		//ְ��ָ������Ϊ��
		this->m_fileIsEmpty = true;		//�ļ�Ϊ��

		ifs.close();	//�ر��ļ�
		return;
	}

	// ���3���ļ����ڣ�������
	this->m_fileIsEmpty = false;		//�ļ���Ϊ��
			// ��ʼ��ְ������
	int num = this->get_WorkerNum();	//��ȡְ������
	cout << "ְ����Ϊ" << num << endl;
	this->m_workerNumber = num;			//��ʼ��ְ������
		// ��ʼ��ְ������
	this->m_workerArray = new Worker *[this->m_workerNumber];	//��ʼ�����鳤��
	this->init_Worker();				//��ʼ�����飬���ļ�����Ϣ��������

}

// ��������
WorkerManager::~WorkerManager()
{
	// �ͷŶ�������
	// ��ճ����ڲ�����
	if (this->m_workerArray != NULL)	//������鲻Ϊ��
	{
		for (int i = 0; i < this->m_workerNumber; i++)
		{
			delete this->m_workerArray[i];		//ɾ��������ÿ��Ԫ��ָ��
			this->m_workerArray[i] = NULL;		//ÿ��Ԫ��ָ���ÿ�
		}

		delete[] this->m_workerArray;		//ɾ������ָ��
		this->m_workerArray = NULL;			//����ָ���ÿ�

		this->m_workerNumber = 0;
		this->m_fileIsEmpty = true;

		cout << "��ճɹ�!" << endl;
	}
	
}

//��չʾ�˵���
void WorkerManager::ShowMenu()
{
	cout << "********************************************************" << endl;
	cout << "***************   ��ӭʹ��ְ������ϵͳ   ***************" << endl;
	cout << "******************   0.�˳��������   ******************" << endl;
	cout << "******************   1.����ְ����Ϣ   ******************" << endl;
	cout << "******************   2.��ʾְ����Ϣ   ******************" << endl;
	cout << "******************   3.ɾ��ְ����Ϣ   ******************" << endl;
	cout << "******************   4.�޸�ְ����Ϣ   ******************" << endl;
	cout << "******************   5.����ְ����Ϣ   ******************" << endl;
	cout << "******************   6.���ձ������   ******************" << endl;
	cout << "******************   7.��������ĵ�   ******************" << endl;
	cout << "********************************************************" << endl;
	cout << endl;

}

//��0.�˳�ϵͳ��
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");	//���û�����������˳�����
	exit(0);			//�˳�����
}

//��1.���ְ����
void WorkerManager::add_Worker()
{
	cout << "���������ְ������" << endl;
	int addNum = 0;		//�����û����������
	cin >> addNum;


	if (addNum > 0)
	{
		// ����������
		int newSize = this->m_workerNumber + addNum;	//��ְ������
		Worker ** newSpace = new Worker*[newSize];		//����������

		// ����ԭ������
		if (this->m_workerArray != NULL)
		{
			for (int i = 0; i<this->m_workerNumber; i++)
			{
				newSpace[i] = this->m_workerArray[i];
			}
		}

		// �ͷ�ԭ������
		delete[] this->m_workerArray;
		// ��������(ָ��)
		this->m_workerArray = newSpace;

		// �����ְ��
		for (int i = 0; i < addNum; i++)
		{
			int id = 0;		//ְ�����
			string name;	//ְ������
			int did = 0;	//����ѡ��

			// ������Ϣ
			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;

			while (this->is_repetition(id))	//���id�ظ�������������
			{
				cout << "����ı���ظ�������������" << endl;
				cin >> id;
			}

			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cin >> did;

			// ����ְ����Ϣ
			Worker *newWorker = NULL;
			switch (did)
			{
			case 1:		//��ͨԱ��
				newWorker = new Employee(id, name, 1);
				break;
			case 2:		//����
				newWorker = new Manager(id, name, 2);
				break;
			case 3:		//�ܲ�
				newWorker = new Boss(id, name, 3);
				break;
			}

			// �����ְ����Ϣ
			this->m_workerArray[this->m_workerNumber] = newWorker;
			// ����ְ������
			this->m_workerNumber++;
		}

		// ��ʾ
		cout << "�ɹ����" << addNum << "��ְ��" << endl;

	}
	else
	{
		cout << "��������" << endl;
	}

	// �������ݵ��ļ�
	this->save();

	// �ļ���Ϊ��
	this->m_fileIsEmpty = false;

	//�����������������
	system("pause");	//��ͣ�������������
	system("cls");		//����

}

// �����ļ�
void WorkerManager::save()
{
	ofstream ofs;			//д�ļ���
	ofs.open(FILENAME, ios::out);		//�ļ������򿪷�ʽ

	// ��ÿ��ְ������Ϣд���ļ�
	for (int i = 0; i < this->m_workerNumber; i++)
	{
		ofs << this->m_workerArray[i]->m_ID << " "
			<< this->m_workerArray[i]->m_Name << " "
			<< this->m_workerArray[i]->m_DepartID << endl;
	}
	
	ofs.close();	//�ر��ļ�
}

// ͳ���ļ�������
int WorkerManager::get_WorkerNum()
{
	ifstream ifs;		//���ļ���
	ifs.open(FILENAME, ios::in);	//�ļ�·�����򿪷�ʽ

	int id;
	string name;
	int did;

	int num = 0;		//ְ������

	while (ifs >> id && ifs >> name && ifs >> did)		//��ȡһ��(�Կո�Ϊ�ֽ磩�����Ը�ʽΪ int �ַ��� int
	{
		num++;
	}

	ifs.close();	//�ر��ļ�
	return num;
}

// ��ʼ��ְ��
void WorkerManager::init_Worker()
{
	ifstream ifs;		//���ļ���
	ifs.open(FILENAME, ios::in);	//�ļ�·�����򿪷�ʽ

	int id;
	string name;
	int did;

	int index = 0;		//�±�
	Worker * worker = NULL;

	while (ifs >> id && ifs >> name && ifs >> did)	//��ȡһ��(�Կո�Ϊ�ֽ磩�����Ը�ʽΪ int �ַ��� int
	{
		switch (did)
		{
		case 1:		//��ͨԱ��
			worker = new Employee(id, name, did);	//��ȡְ����Ϣ
			break;
		case 2:		//����
			worker = new Manager(id, name, did);	//��ȡְ����Ϣ
			break;
		case 3:		//�ܲ�
			worker = new Boss(id, name, did);	//��ȡְ����Ϣ
			break;
		}

		this->m_workerArray[index] = worker;	//��ְ����Ϣ��������
		index++;	//�±�+1
	}

	ifs.close();	//�ر��ļ�
}

//��2.��ʾְ����
void WorkerManager::show_Worker()
{
	if (this->m_fileIsEmpty)	//����ļ�Ϊ�գ�����ʾ
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//���ö�̬���ò�ͬ�����show����
		for (int i = 0; i < this->m_workerNumber; i++)
		{
			this->m_workerArray[i]->showInfo();
		}
	}

	//�����������������
	system("pause");	//��ͣ�������������
	system("cls");		//����
}

//��3.ɾ��ְ����
void  WorkerManager::del_Worker()
{
	if (this->m_fileIsEmpty)	//����ļ�Ϊ�գ���ɾ��
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ɾ����ְ�����" << endl;
		int id;
		cin >> id;	//��ȡ�����id

		int index = this->is_Exist(id);		// ����ְ���������λ��
		if (index != -1)					// ���ְ������
		{
			//����ǰ��
			for (int i = index; i < this->m_workerNumber - 1; i++)
			{
				this->m_workerArray[i] = this->m_workerArray[i + 1];
			}
			//delete this->m_workerArray[this->m_workerNumber - 1];		//ɾ�������е�����
			//m_workerArray[this->m_workerNumber - 1] = NULL;

			cout << "ɾ���ɹ���" << endl;

			this->m_workerNumber--;		//ְ��������һ
			if (this->m_workerNumber == 0)	//�����ְ��
			{
				this->m_fileIsEmpty = true;
			}
			this->save();				//�����ļ�
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
		
	}

	//�����������������
	system("pause");	//��ͣ�������������
	system("cls");		//����
}

// ְ���Ƿ���ڣ������򷵻�ְ���������λ�ã����򷵻�-1
int  WorkerManager::is_Exist(int id)
{
	int index = -1;		//�±�
	for (int i = 0; i < this->m_workerNumber; i++)	//����
	{
		if (this->m_workerArray[i]->m_ID == id)		//�������
		{
			index = i;	
			break;
		}
	}

	return  index;

}

//��4.�޸�ְ����
void WorkerManager::modify_Worker()
{
	if (this->m_fileIsEmpty)	//����ļ�Ϊ�գ����޸�
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "���������޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;	//��ȡ�����id

		int index = this->is_Exist(id);		// ����ְ���������λ��
		if (index != -1)					// ���ְ������
		{
			delete this->m_workerArray[index];		//ɾ�������е�Ԫ��
			
			int newid = id;		//ְ�����
			string newname;		//ְ������
			int newdid = 0;		//����ѡ��

			// ������Ϣ
			cout << "���ҵ��˱��Ϊ"<< newid <<"��ְ�����������±��" << endl;
			cin >> newid;

			while(this->is_repetition(newid))	//���id�ظ�������������
			{
				cout << "����ı���ظ�������������" << endl;
				cin >> newid;
				
			}

			cout << "������������" << endl;
			cin >> newname;
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ܲ�" << endl;
			cin >> newdid;

			// ����ְ����Ϣ
			Worker *newWorker = NULL;
			switch (newdid)
			{
			case 1:		//��ͨԱ��
				newWorker = new Employee(newid, newname, 1);
				break;
			case 2:		//����
				newWorker = new Manager(newid, newname, 2);
				break;
			case 3:		//�ܲ�
				newWorker = new Boss(newid, newname, 3);
				break;
			}

			this->m_workerArray[index] = newWorker;		//��������
			cout << "�޸���ɣ�" << endl;
		}
		else
		{
			cout << "�޸�ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}

		this->save();				//�����ļ�

	}

	//�����������������
	system("pause");	//��ͣ�������������
	system("cls");		//����
}

// ְ���Ƿ��ظ�1
bool WorkerManager::is_repetition(int id)
{
	for (int i = 0; i < this->m_workerNumber ; i++)
	{
		if (id == this->m_workerArray[i]->m_ID)	//�������di�����ظ�
		{
			return true;
		}
	}
	return false;
}
// ְ���Ƿ��ظ�2
bool WorkerManager::is_repetition(string name)
{
	for (int i = 0; i < this->m_workerNumber; i++)
	{
		if (name == this->m_workerArray[i]->m_Name)	//�������di�����ظ�
		{
			return true;
		}
	}
	return false;
}


//��5.����ְ����
void WorkerManager::find_worker()
{
	if (this->m_fileIsEmpty)	//����ļ�Ϊ�գ��򲻲���
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;

		int select;
		cin >> select;

		if (select == 1)			//�����ձ�Ų��ҡ�
		{
			int id;
			cout << "������Ҫ���ҵ�ְ�����" << endl;	
			cin >> id;				//�û�������

			int ret = this->is_Exist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�" << endl;
				this->m_workerArray[ret]->showInfo();	//��ʾְ����Ϣ
				
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}

		}
		else if (select == 2)		//�������������ҡ�
		{
			string name;
			cout << "������Ҫ���ҵ�ְ������" << endl;
			cin >> name;			//�û���������

			bool flag_exist = false;	//�ж������Ƿ����
			for (int i = 0; i < this->m_workerNumber; i++)	
			{
				if (name == this->m_workerArray[i]->m_Name)
				{
					bool flag_exist = true;		//��������
					this->m_workerArray[i]->showInfo();		//��ʾְ����Ϣ
				}
			}
			if (!flag_exist)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}

	}

	//�����������������
	system("pause");	//��ͣ�������������
	system("cls");		//����
}

//��6.����
void WorkerManager::sort_Worker()
{
	if (this->m_fileIsEmpty)	//����ļ�Ϊ�գ�������
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ������ķ�ʽ" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;

		int select;
		cin >> select;		//�û�����ѡ��

		if (select != 1 && select != 2)
		{
			cout << "���ָ������!" << endl;
		}
		else		// ѡ������
		{
			this->select_sort(select);	
			cout << "����ɹ�" << endl;
			this->save();	//�ļ�����
		}
	}

	//�����������������
	system("pause");	//��ͣ�������������
	system("cls");		//����
}

// ѡ������1.����,2.����
void  WorkerManager::select_sort(int select)
{
	
	for (int i = 0; i < this->m_workerNumber; i++)
	{
		int max_or_min_index = i;		//�����Сֵ�±�

		if (select == 1)		//����
		{
			for (int j = i + 1; j < this->m_workerNumber; j++)		 //j����
			{
				if (this->m_workerArray[max_or_min_index]->m_ID > this->m_workerArray[j]->m_ID)	//������ı��С
				{
					max_or_min_index = j;		//��Ÿ���
				}
			}
		}
		else		//����
		{
			for (int j = i + 1; j < this->m_workerNumber; j++)		 //j����
			{
				if (this->m_workerArray[max_or_min_index]->m_ID < this->m_workerArray[j]->m_ID)	//������ı�Ŵ�
				{
					max_or_min_index = j;		//��Ÿ���
				}
			}
		}

		//�����������Ԫ�ء�
		if (i != max_or_min_index)	//��� max_or_min_index �иı䣬�򽻻�
		{
			Worker *temp = NULL;
			temp = this->m_workerArray[i];
			this->m_workerArray[i] = this->m_workerArray[max_or_min_index];
			this->m_workerArray[max_or_min_index] = temp;
		}

	}
}

//��7.����ļ���
void WorkerManager::clean_File()
{
	cout << "�Ƿ�����ļ�?" << endl;
	cout << "1�����" << endl;
	cout << "2������" << endl;

	int select;
	cin >> select;		//�û���ѡ��

	if (select == 1)	//����ļ�
	{
		// ����ļ�
		ofstream ofs(FILENAME, ios::trunc);		//�ù��캯��д�ļ�·�����򿪷�ʽ��   ios::trunc����ɾ���ļ������´���
		ofs.close();		//�ر��ļ�

		// ��ճ����ڲ�����
		if (this->m_workerArray != NULL)	//������鲻Ϊ��
		{
			for (int i = 0; i < this->m_workerNumber; i++)	
			{
				delete this->m_workerArray[i];		//ɾ��������ÿ��Ԫ��ָ��
				this->m_workerArray[i] = NULL;		//ÿ��Ԫ��ָ���ÿ�
			}

			delete[] this->m_workerArray;		//ɾ������ָ��
			this->m_workerArray = NULL;			//����ָ���ÿ�

			this->m_workerNumber = 0;
			this->m_fileIsEmpty = true;
			
			cout << "��ճɹ�!" << endl;
		}

	}

	//�����������������
	system("pause");	//��ͣ�������������
	system("cls");		//����
}