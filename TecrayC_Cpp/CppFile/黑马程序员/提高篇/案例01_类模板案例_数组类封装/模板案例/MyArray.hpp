#pragma once
#include <iostream>
using namespace std;

template<class T>
class Myarray
{

public:

	//构造函数,传入数组容量
	Myarray(int capacity)		
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_capacity];		//初始化数组，根据传入的容量开辟在堆区
	}

	//拷贝构造,拷贝现有的数组————————（拷贝构造4.2节内容)
	Myarray(const Myarray & arr)
	{
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;

		//堆区数据深拷贝
		this->pAddress = new T[this->m_capacity];
		//传入数组数据
		for (int i; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//重载赋值运算符=使得可以快速赋值类————————————————————(重载运算符4.5节内容)
	Myarray& operator=(const Myarray &arr)				//返回引用：链式编程
	{
		//释放之前堆区的数据
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_size = 0;
			this->m_capacity = 0;
		}

		// 赋值
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		// 深拷贝
		this->pAddress = new T[this->m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;		//返回this指针的值
	}

	//尾插法
	void Push_Buck(const T& val)
	{
		if (this->m_size == this->m_capacity)	//如果大小已经等于容量了,则不插入
		{
			return;
		}
		else
		{
			this->pAddress[this->m_size] = val;		//在数组末端插入数据
			this->m_size++;		//更新数组大小
		}
	}

	//尾删法
	void Del_Buck()
	{
		if (this->m_size == 0)		//如果大小为0，则不删除
		{
			return;
		}
		this->m_size--;		//数组大小减一
	}

	//通过下标访问数组
	//重载运算符[]，因为中括号[]是普通的数组，不是广义上的自定义数组
	T& operator[](int index)
	{
		return this->pAddress[index];		//返回数组中的元素,元素类型T
	}
	
	//返回数组容量
	int getCapacity()
	{
		return this->m_capacity;
	}

	//返回数组大小
	int getSize()
	{
		return this->m_size;
	}


	//析构函数
	~Myarray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_size = 0;
			this->m_capacity = 0;
		}

	}




private:

	T *pAddress;		//指针指向堆区开辟的数组
	int m_size;			//数组大小
	int m_capacity;		//数组容量
};