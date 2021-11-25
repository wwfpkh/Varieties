//老板类
#include "Boss.h"


// 构造函数
Boss::Boss(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepartID = did;
}

// 显示个人信息
void Boss::showInfo()
{
	cout << "职工编号:" << this->m_ID
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDepartID()
		<< "\t岗位职责：管理公司所有的事务" << endl;
}
// 获取岗位名称
string Boss::getDepartID()
{
	return string("总裁");
}