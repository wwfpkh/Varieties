//Ա����
#include "employee.h"


// ���캯��
Employee::Employee(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepartID = did;
}

// ��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ�����:" << this->m_ID
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDepartID()
		<< "\t��λְ����ɾ�����������" << endl;
}
// ��ȡ��λ����
string Employee::getDepartID()
{
	return string("Ա��");
}