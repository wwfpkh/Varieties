//������
#include "Manager.h"

// ���캯��
Manager::Manager(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepartID = did;
}

// ��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ�����:" << this->m_ID
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDepartID()
		<< "\t��λְ������ϰ彻��������,�����·������Ա��" << endl;
}
// ��ȡ��λ����
string Manager::getDepartID()
{
	return string("����");
}