#pragma once			//防止头文件重复包含
#include <iostream>		//包含输入输出流头文件
using namespace std;	//使用标准命名空间
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"
#include <fstream>					    //文件操作头文件
#define FILENAME "WorkerFile.txt"		//宏定义：文件名

class WorkerManager		
{
public:
	// 构造函数声明
	WorkerManager();
	// 析构函数声明
	~WorkerManager();

	//【展示菜单】
	void ShowMenu();

	//【0.退出系统】
	void ExitSystem();

	//【1.添加职工】
	void add_Worker();

	// 保存文件
	void save();

	// 统计文件中人数
	int get_WorkerNum();

	// 初始化职工
	void init_Worker();

	//【2.显示职工】
	void show_Worker();

	//【3.删除职工】
	void del_Worker();

	// 职工是否存在，存在则返回职工编号。否则返回-1
	int is_Exist(int id);

	//【4.修改职工】
	void modify_Worker();

	// 职工是否重复
	bool is_repetition(int id);
	bool is_repetition(string name);

	//【5.查找职工】
	void find_worker();

	//【6.排序】
	void sort_Worker();

	// 选择排序：1.升序,2.降序
	void select_sort(int select);

	//【7.清空文件】
	void clean_File();

public:
	//【记录职工人数】
	int m_workerNumber;

	//【职工数组指针】
	Worker ** m_workerArray;

	//【文件是否为空】
	bool m_fileIsEmpty;



};