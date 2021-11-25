#include <iostream>
using namespace std;
#include "MyArray.hpp"
#include <string>

// Person类
class Person
{
public:
	//构造函数
	Person() {}		//空构造，供创建数组时使用
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}


	string m_name;
	int m_age;
};


//函数：打印数组中每个元素值
void PrintArray(Myarray<Person> &arr)	//数组传入引用
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "Name：" << arr[i].m_name << "\t Age:  " << arr[i].m_age << endl;
	}
}

void test01()
{
	Myarray<Person> personArray(10);	//T为Person类型，构造函数初始化数组容量为10

	Person 	p1("四糸乃", 13);
	Person 	p2("香風 智乃", 13);
	Person 	p3("五岛润", 10);
	Person 	p4("しろ", 11);

	//后插法插入数据
	personArray.Push_Buck(p1);
	personArray.Push_Buck(p2);
	personArray.Push_Buck(p3);
	personArray.Push_Buck(p4);

	//打印数组
	PrintArray(personArray);
	//打印数组容量和大小
	cout << "数组容量" << personArray.getCapacity() << endl;
	cout << "数组大小" << personArray.getSize() << endl;

	cout << "------------------------------------" << endl;
	//后删法
	personArray.Del_Buck();
	//打印数组
	PrintArray(personArray);
	//打印数组容量和大小
	cout << "数组容量" << personArray.getCapacity() << endl;
	cout << "数组大小" << personArray.getSize() << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}