#include "WorkerManager.h"

// 构造函数
WorkerManager::WorkerManager()
{
	// 读文件
	ifstream ifs;		//读文件类
	ifs.open(FILENAME, ios::in);	//文件路径，打开方式

	// 情况1：文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		// 初始化数据
		this->m_workerNumber = 0;		//职工人数为0
		this->m_workerArray = NULL;		//职工指针数组为空
		this->m_fileIsEmpty = true;		//文件为空

		ifs.close();	//关闭文件
		return;
	}

	// 情况2：文件存在，但是无数据
	char ch;
	ifs >> ch;			//读取一个字节数据
	if (ifs.eof())		//如果读取到的是末尾
	{
		cout << "文件为空" << endl;
		// 初始化数据
		this->m_workerNumber = 0;		//职工人数为0
		this->m_workerArray = NULL;		//职工指针数组为空
		this->m_fileIsEmpty = true;		//文件为空

		ifs.close();	//关闭文件
		return;
	}

	// 情况3：文件存在，有数据
	this->m_fileIsEmpty = false;		//文件不为空
			// 初始化职工数量
	int num = this->get_WorkerNum();	//获取职工数量
	cout << "职工数为" << num << endl;
	this->m_workerNumber = num;			//初始化职工数量
		// 初始化职工数组
	this->m_workerArray = new Worker *[this->m_workerNumber];	//初始化数组长度
	this->init_Worker();				//初始化数组，将文件内信息存入数组

}

// 析构函数
WorkerManager::~WorkerManager()
{
	// 释放堆区数据
	// 清空程序内部数据
	if (this->m_workerArray != NULL)	//如果数组不为空
	{
		for (int i = 0; i < this->m_workerNumber; i++)
		{
			delete this->m_workerArray[i];		//删除数组中每个元素指针
			this->m_workerArray[i] = NULL;		//每个元素指针置空
		}

		delete[] this->m_workerArray;		//删除数组指针
		this->m_workerArray = NULL;			//数组指针置空

		this->m_workerNumber = 0;
		this->m_fileIsEmpty = true;

		cout << "清空成功!" << endl;
	}
	
}

//【展示菜单】
void WorkerManager::ShowMenu()
{
	cout << "********************************************************" << endl;
	cout << "***************   欢迎使用职工管理系统   ***************" << endl;
	cout << "******************   0.退出管理程序   ******************" << endl;
	cout << "******************   1.增加职工信息   ******************" << endl;
	cout << "******************   2.显示职工信息   ******************" << endl;
	cout << "******************   3.删除职工信息   ******************" << endl;
	cout << "******************   4.修改职工信息   ******************" << endl;
	cout << "******************   5.查找职工信息   ******************" << endl;
	cout << "******************   6.按照编号排序   ******************" << endl;
	cout << "******************   7.清空所有文档   ******************" << endl;
	cout << "********************************************************" << endl;
	cout << endl;

}

//【0.退出系统】
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");	//让用户按任意键再退出程序
	exit(0);			//退出程序
}

//【1.添加职工】
void WorkerManager::add_Worker()
{
	cout << "请输入添加职工数量" << endl;
	int addNum = 0;		//保存用户输入的数量
	cin >> addNum;


	if (addNum > 0)
	{
		// 开辟新数组
		int newSize = this->m_workerNumber + addNum;	//新职工数量
		Worker ** newSpace = new Worker*[newSize];		//开辟新数组

		// 拷贝原来数据
		if (this->m_workerArray != NULL)
		{
			for (int i = 0; i<this->m_workerNumber; i++)
			{
				newSpace[i] = this->m_workerArray[i];
			}
		}

		// 释放原来数组
		delete[] this->m_workerArray;
		// 更新数组(指向)
		this->m_workerArray = newSpace;

		// 添加新职工
		for (int i = 0; i < addNum; i++)
		{
			int id = 0;		//职工编号
			string name;	//职工姓名
			int did = 0;	//部门选择

			// 输入信息
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;

			while (this->is_repetition(id))	//如果id重复，则重新输入
			{
				cout << "输入的编号重复，请重新输入" << endl;
				cin >> id;
			}

			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> did;

			// 创建职工信息
			Worker *newWorker = NULL;
			switch (did)
			{
			case 1:		//普通员工
				newWorker = new Employee(id, name, 1);
				break;
			case 2:		//经理
				newWorker = new Manager(id, name, 2);
				break;
			case 3:		//总裁
				newWorker = new Boss(id, name, 3);
				break;
			}

			// 添加新职工信息
			this->m_workerArray[this->m_workerNumber] = newWorker;
			// 更新职工数量
			this->m_workerNumber++;
		}

		// 提示
		cout << "成功添加" << addNum << "新职工" << endl;

	}
	else
	{
		cout << "输入有误！" << endl;
	}

	// 保存数据到文件
	this->save();

	// 文件不为空
	this->m_fileIsEmpty = false;

	//按任意键继续后清屏
	system("pause");	//暂停，按任意键继续
	system("cls");		//清屏

}

// 保存文件
void WorkerManager::save()
{
	ofstream ofs;			//写文件类
	ofs.open(FILENAME, ios::out);		//文件名，打开方式

	// 将每个职工的信息写入文件
	for (int i = 0; i < this->m_workerNumber; i++)
	{
		ofs << this->m_workerArray[i]->m_ID << " "
			<< this->m_workerArray[i]->m_Name << " "
			<< this->m_workerArray[i]->m_DepartID << endl;
	}
	
	ofs.close();	//关闭文件
}

// 统计文件中人数
int WorkerManager::get_WorkerNum()
{
	ifstream ifs;		//读文件类
	ifs.open(FILENAME, ios::in);	//文件路径，打开方式

	int id;
	string name;
	int did;

	int num = 0;		//职工数量

	while (ifs >> id && ifs >> name && ifs >> did)		//读取一行(以空格为分界），所以格式为 int 字符串 int
	{
		num++;
	}

	ifs.close();	//关闭文件
	return num;
}

// 初始化职工
void WorkerManager::init_Worker()
{
	ifstream ifs;		//读文件类
	ifs.open(FILENAME, ios::in);	//文件路径，打开方式

	int id;
	string name;
	int did;

	int index = 0;		//下标
	Worker * worker = NULL;

	while (ifs >> id && ifs >> name && ifs >> did)	//读取一行(以空格为分界），所以格式为 int 字符串 int
	{
		switch (did)
		{
		case 1:		//普通员工
			worker = new Employee(id, name, did);	//获取职工信息
			break;
		case 2:		//经理
			worker = new Manager(id, name, did);	//获取职工信息
			break;
		case 3:		//总裁
			worker = new Boss(id, name, did);	//获取职工信息
			break;
		}

		this->m_workerArray[index] = worker;	//将职工信息传入数组
		index++;	//下标+1
	}

	ifs.close();	//关闭文件
}

//【2.显示职工】
void WorkerManager::show_Worker()
{
	if (this->m_fileIsEmpty)	//如果文件为空，则不显示
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//利用多态调用不同对象的show函数
		for (int i = 0; i < this->m_workerNumber; i++)
		{
			this->m_workerArray[i]->showInfo();
		}
	}

	//按任意键继续后清屏
	system("pause");	//暂停，按任意键继续
	system("cls");		//清屏
}

//【3.删除职工】
void  WorkerManager::del_Worker()
{
	if (this->m_fileIsEmpty)	//如果文件为空，则不删除
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入想删除的职工编号" << endl;
		int id;
		cin >> id;	//获取输入的id

		int index = this->is_Exist(id);		// 返回职工在数组的位置
		if (index != -1)					// 如果职工存在
		{
			//数据前移
			for (int i = index; i < this->m_workerNumber - 1; i++)
			{
				this->m_workerArray[i] = this->m_workerArray[i + 1];
			}
			//delete this->m_workerArray[this->m_workerNumber - 1];		//删除数组中的数据
			//m_workerArray[this->m_workerNumber - 1] = NULL;

			cout << "删除成功！" << endl;

			this->m_workerNumber--;		//职工人数减一
			if (this->m_workerNumber == 0)	//如果无职工
			{
				this->m_fileIsEmpty = true;
			}
			this->save();				//保存文件
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
		
	}

	//按任意键继续后清屏
	system("pause");	//暂停，按任意键继续
	system("cls");		//清屏
}

// 职工是否存在，存在则返回职工在数组的位置，否则返回-1
int  WorkerManager::is_Exist(int id)
{
	int index = -1;		//下标
	for (int i = 0; i < this->m_workerNumber; i++)	//遍历
	{
		if (this->m_workerArray[i]->m_ID == id)		//如果存在
		{
			index = i;	
			break;
		}
	}

	return  index;

}

//【4.修改职工】
void WorkerManager::modify_Worker()
{
	if (this->m_fileIsEmpty)	//如果文件为空，则不修改
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入想修改的职工编号" << endl;
		int id;
		cin >> id;	//获取输入的id

		int index = this->is_Exist(id);		// 返回职工在数组的位置
		if (index != -1)					// 如果职工存在
		{
			delete this->m_workerArray[index];		//删除数组中的元素
			
			int newid = id;		//职工编号
			string newname;		//职工姓名
			int newdid = 0;		//部门选择

			// 输入信息
			cout << "查找到了编号为"<< newid <<"的职工，请输入新编号" << endl;
			cin >> newid;

			while(this->is_repetition(newid))	//如果id重复，则重新输入
			{
				cout << "输入的编号重复，请重新输入" << endl;
				cin >> newid;
				
			}

			cout << "请输入新姓名" << endl;
			cin >> newname;
			cout << "请选择该职工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.总裁" << endl;
			cin >> newdid;

			// 创建职工信息
			Worker *newWorker = NULL;
			switch (newdid)
			{
			case 1:		//普通员工
				newWorker = new Employee(newid, newname, 1);
				break;
			case 2:		//经理
				newWorker = new Manager(newid, newname, 2);
				break;
			case 3:		//总裁
				newWorker = new Boss(newid, newname, 3);
				break;
			}

			this->m_workerArray[index] = newWorker;		//更新数据
			cout << "修改完成！" << endl;
		}
		else
		{
			cout << "修改失败，未找到该职工" << endl;
		}

		this->save();				//保存文件

	}

	//按任意键继续后清屏
	system("pause");	//暂停，按任意键继续
	system("cls");		//清屏
}

// 职工是否重复1
bool WorkerManager::is_repetition(int id)
{
	for (int i = 0; i < this->m_workerNumber ; i++)
	{
		if (id == this->m_workerArray[i]->m_ID)	//如果出现di出现重复
		{
			return true;
		}
	}
	return false;
}
// 职工是否重复2
bool WorkerManager::is_repetition(string name)
{
	for (int i = 0; i < this->m_workerNumber; i++)
	{
		if (name == this->m_workerArray[i]->m_Name)	//如果出现di出现重复
		{
			return true;
		}
	}
	return false;
}


//【5.查找职工】
void WorkerManager::find_worker()
{
	if (this->m_fileIsEmpty)	//如果文件为空，则不查找
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;

		int select;
		cin >> select;

		if (select == 1)			//【按照编号查找】
		{
			int id;
			cout << "请输入要查找的职工编号" << endl;	
			cin >> id;				//用户输入编号

			int ret = this->is_Exist(id);
			if (ret != -1)
			{
				cout << "查找成功" << endl;
				this->m_workerArray[ret]->showInfo();	//显示职工信息
				
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}

		}
		else if (select == 2)		//【按照姓名查找】
		{
			string name;
			cout << "请输入要查找的职工姓名" << endl;
			cin >> name;			//用户输入姓名

			bool flag_exist = false;	//判断名字是否存在
			for (int i = 0; i < this->m_workerNumber; i++)	
			{
				if (name == this->m_workerArray[i]->m_Name)
				{
					bool flag_exist = true;		//姓名存在
					this->m_workerArray[i]->showInfo();		//显示职工信息
				}
			}
			if (!flag_exist)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误！" << endl;
		}

	}

	//按任意键继续后清屏
	system("pause");	//暂停，按任意键继续
	system("cls");		//清屏
}

//【6.排序】
void WorkerManager::sort_Worker()
{
	if (this->m_fileIsEmpty)	//如果文件为空，则不排序
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择排序的方式" << endl;
		cout << "1、升序" << endl;
		cout << "2、降序" << endl;

		int select;
		cin >> select;		//用户输入选择

		if (select != 1 && select != 2)
		{
			cout << "输出指令有误!" << endl;
		}
		else		// 选择排序
		{
			this->select_sort(select);	
			cout << "排序成功" << endl;
			this->save();	//文件更新
		}
	}

	//按任意键继续后清屏
	system("pause");	//暂停，按任意键继续
	system("cls");		//清屏
}

// 选择排序：1.升序,2.降序
void  WorkerManager::select_sort(int select)
{
	
	for (int i = 0; i < this->m_workerNumber; i++)
	{
		int max_or_min_index = i;		//最大最小值下标

		if (select == 1)		//升序
		{
			for (int j = i + 1; j < this->m_workerNumber; j++)		 //j遍历
			{
				if (this->m_workerArray[max_or_min_index]->m_ID > this->m_workerArray[j]->m_ID)	//若后面的编号小
				{
					max_or_min_index = j;		//编号赋予
				}
			}
		}
		else		//降序
		{
			for (int j = i + 1; j < this->m_workerNumber; j++)		 //j遍历
			{
				if (this->m_workerArray[max_or_min_index]->m_ID < this->m_workerArray[j]->m_ID)	//若后面的编号大
				{
					max_or_min_index = j;		//编号赋予
				}
			}
		}

		//【交换数组的元素】
		if (i != max_or_min_index)	//如果 max_or_min_index 有改变，则交换
		{
			Worker *temp = NULL;
			temp = this->m_workerArray[i];
			this->m_workerArray[i] = this->m_workerArray[max_or_min_index];
			this->m_workerArray[max_or_min_index] = temp;
		}

	}
}

//【7.清空文件】
void WorkerManager::clean_File()
{
	cout << "是否清空文件?" << endl;
	cout << "1、清空" << endl;
	cout << "2、返回" << endl;

	int select;
	cin >> select;		//用户的选择

	if (select == 1)	//清空文件
	{
		// 清空文件
		ofstream ofs(FILENAME, ios::trunc);		//用构造函数写文件路径，打开方式。   ios::trunc——删除文件后重新创建
		ofs.close();		//关闭文件

		// 清空程序内部数据
		if (this->m_workerArray != NULL)	//如果数组不为空
		{
			for (int i = 0; i < this->m_workerNumber; i++)	
			{
				delete this->m_workerArray[i];		//删除数组中每个元素指针
				this->m_workerArray[i] = NULL;		//每个元素指针置空
			}

			delete[] this->m_workerArray;		//删除数组指针
			this->m_workerArray = NULL;			//数组指针置空

			this->m_workerNumber = 0;
			this->m_fileIsEmpty = true;
			
			cout << "清空成功!" << endl;
		}

	}

	//按任意键继续后清屏
	system("pause");	//暂停，按任意键继续
	system("cls");		//清屏
}