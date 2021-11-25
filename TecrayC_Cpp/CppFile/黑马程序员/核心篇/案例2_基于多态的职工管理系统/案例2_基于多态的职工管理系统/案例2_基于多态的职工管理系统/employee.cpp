//员工类
#include "employee.h"


// 构造函数
Employee::Employee(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepartID = did;
}

// 显示个人信息
void Employee::showInfo()
{
	cout << "职工编号:" << this->m_ID
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDepartID()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}
// 获取岗位名称
string Employee::getDepartID()
{
	return string("员工");
}