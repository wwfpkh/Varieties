#include <iostream>
using namespace std;
#include "WorkerManager.h"
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"

int main()
{

	// 实例化管理者对象
	WorkerManager wm;

	int choice = 0;		// 用户的选择

	while (true)
	{
		wm.ShowMenu();  // 展示菜单
		cout << "请输入您的选择" << endl;
		cin >> choice;	//接收用户选项

		//【用户选择接口】
		switch (choice)
		{
		case 0:		//退出系统
			wm.ExitSystem();
			break;
		case 1:		//增加职工
			wm.add_Worker();
			break;
		case 2:		//显示职工
			wm.show_Worker();
			break;
		case 3:		//删除职工
			wm.del_Worker();
			break;
		case 4:		//修改职工
			wm.modify_Worker();
			break;
		case 5:		//查找职工
			wm.find_worker();
			break;
		case 6:		//排序职工
			wm.sort_Worker();
			break;
		case 7:		//清空文档
			wm.clean_File();
			break;
		default:
			system("cls");	//清屏（输入无效数字）
			break;
		}

	}

	system("pause");
	return 0;
}
