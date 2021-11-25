#include <iostream>
using namespace std;
#include "MyArray.hpp"
#include <string>

// Person��
class Person
{
public:
	//���캯��
	Person() {}		//�չ��죬����������ʱʹ��
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}


	string m_name;
	int m_age;
};


//��������ӡ������ÿ��Ԫ��ֵ
void PrintArray(Myarray<Person> &arr)	//���鴫������
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "Name��" << arr[i].m_name << "\t Age:  " << arr[i].m_age << endl;
	}
}

void test01()
{
	Myarray<Person> personArray(10);	//TΪPerson���ͣ����캯����ʼ����������Ϊ10

	Person 	p1("������", 13);
	Person 	p2("���L ����", 13);
	Person 	p3("�嵺��", 10);
	Person 	p4("����", 11);

	//��巨��������
	personArray.Push_Buck(p1);
	personArray.Push_Buck(p2);
	personArray.Push_Buck(p3);
	personArray.Push_Buck(p4);

	//��ӡ����
	PrintArray(personArray);
	//��ӡ���������ʹ�С
	cout << "��������" << personArray.getCapacity() << endl;
	cout << "�����С" << personArray.getSize() << endl;

	cout << "------------------------------------" << endl;
	//��ɾ��
	personArray.Del_Buck();
	//��ӡ����
	PrintArray(personArray);
	//��ӡ���������ʹ�С
	cout << "��������" << personArray.getCapacity() << endl;
	cout << "�����С" << personArray.getSize() << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}