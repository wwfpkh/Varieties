#pragma once
#include <iostream>
using namespace std;

template<class T>
class Myarray
{

public:

	//���캯��,������������
	Myarray(int capacity)		
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_capacity];		//��ʼ�����飬���ݴ�������������ڶ���
	}

	//��������,�������е����顪������������������������4.2������)
	Myarray(const Myarray & arr)
	{
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;

		//�����������
		this->pAddress = new T[this->m_capacity];
		//������������
		for (int i; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//���ظ�ֵ�����=ʹ�ÿ��Կ��ٸ�ֵ�ࡪ��������������������������������������(���������4.5������)
	Myarray& operator=(const Myarray &arr)				//�������ã���ʽ���
	{
		//�ͷ�֮ǰ����������
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_size = 0;
			this->m_capacity = 0;
		}

		// ��ֵ
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		// ���
		this->pAddress = new T[this->m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;		//����thisָ���ֵ
	}

	//β�巨
	void Push_Buck(const T& val)
	{
		if (this->m_size == this->m_capacity)	//�����С�Ѿ�����������,�򲻲���
		{
			return;
		}
		else
		{
			this->pAddress[this->m_size] = val;		//������ĩ�˲�������
			this->m_size++;		//���������С
		}
	}

	//βɾ��
	void Del_Buck()
	{
		if (this->m_size == 0)		//�����СΪ0����ɾ��
		{
			return;
		}
		this->m_size--;		//�����С��һ
	}

	//ͨ���±��������
	//���������[]����Ϊ������[]����ͨ�����飬���ǹ����ϵ��Զ�������
	T& operator[](int index)
	{
		return this->pAddress[index];		//���������е�Ԫ��,Ԫ������T
	}
	
	//������������
	int getCapacity()
	{
		return this->m_capacity;
	}

	//���������С
	int getSize()
	{
		return this->m_size;
	}


	//��������
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

	T *pAddress;		//ָ��ָ��������ٵ�����
	int m_size;			//�����С
	int m_capacity;		//��������
};