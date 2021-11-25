//经理类
#include "Manager.h"

// 构造函数
Manager::Manager(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepartID = did;
}

// 显示个人信息
void Manager::showInfo()
{
	cout << "职工编号:" << this->m_ID
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDepartID()
		<< "\t岗位职责：完成老板交给的任务,并且下发任务给员工" << endl;
}
// 获取岗位名称
string Manager::getDepartID()
{
	return string("经理");
}