//�ϰ���
#include "Boss.h"


// ���캯��
Boss::Boss(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepartID = did;
}

// ��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ�����:" << this->m_ID
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDepartID()
		<< "\t��λְ�𣺹���˾���е�����" << endl;
}
// ��ȡ��λ����
string Boss::getDepartID()
{
	return string("�ܲ�");
}