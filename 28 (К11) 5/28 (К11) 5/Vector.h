#pragma once


#include <iostream>
#include <ctime>
#include <vector>
#include<deque>
#include "Money.h"
using namespace std;


template<class T>
class Vector
{
	deque <T> s;//���������
	int len;//������ ����������
public:
	Vector();//����������� ��� ����������
	Vector(int n);//����������� � �����������
	Vector(const Vector<T>&);//����������� �����������


	void Print_deque();
	void Add_to_deque(T el, int pos);
	T Max();
	T Min();
	void Delete_from_deque(T key);
	void Multiplication();
};



//����������� ��� ����������
template <class T>
Vector<T>::Vector()
{
	len = 0;
}



//����������� � ����������
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push_back(a);//�������� � ���� ������� �
	}
	len = s.size();
}



//����������� �����������
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	len = Vec.len;
	//�������� �������� ����� Vec.s � ������ v
	Vector v = copy_deque_to_vector(v.s);
	//�������� ������ v � ���� s
	s = copy_vector_to_deque(Vec);
}




//����������� ������� � ������
template <class T>
vector<T> copy_deque_to_vector(deque<T> s)
{
	vector<T> v;
	while (!s.empty())
	{
		v.push_back(s.front());
		s.pop_front();
	}
	return v;
}


//����������� ������� � �������
template <class T>
deque<T> copy_vector_to_deque(vector<T> v)
{
	deque<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push_back(v[i]);
	}
	return s;
}




//������
template <class T>
void Vector<T>::Print_deque()
{
	cout << "���� �������" << endl;
	//�������� ������� � ������
	vector<T> v = copy_deque_to_vector(s);

	while (!s.empty())//���� ������� �� �����
	{
		cout << s.front() << endl;//����� �������� � ������� �������
		s.pop_front();//������� ������� �� ������� �������
	}

	//�������� ������ � �������
	s = copy_vector_to_deque(v);
	cout << endl << endl;
}



//����� ������������� �������� �������
template <class T>
T Vector<T>::Max()
{
	T m = s.front();//m ��������� �������� �� ������� �������
	//� ������ ����������� �������� �������
	vector<T> v = copy_deque_to_vector(s);

	while (!s.empty())//���� ������� �� �����
	{
		//���������� m � ������� � ������� �������
		if (s.front() > m)m = s.front();
		s.pop_front();//������� ������� �� ������� �������
	}

	s = copy_vector_to_deque(v);//�������� ������ � �������
	cout << "������������ �������   " << m << endl;
	return m;
}


//����� ������������ �������� �������
template <class T>
T Vector<T>::Min()
{
	T m = s.front();
	vector<T> v = copy_deque_to_vector(s);

	while (!s.empty())
	{
		if (s.front() < m)m = s.front();
		s.pop_front();
	}

	s = copy_vector_to_deque(v);
	cout << "����������� �������   " << m << endl;
	return m;
}




//���������� �������� key � ������m �� ������� pos
template <class T>
void Vector<T>::Add_to_deque(T key, int pos)
{
	vector <T>v;//��������������� ������
	T t;
	int i = 1;

	while (!s.empty())//���� ������� �� �����
	{
		t = s.front();//�������� ������� �� ������� �������
		//���� ����� �������� ����� pos ��������� � ������ ����� ������� 
		if (i == pos)
		{
			v.push_back(key);
		}
		v.push_back(t);//��������� t � ������
		s.pop_front();//������� ������� �� ������� �������
		i++;
	}

	s = copy_vector_to_deque(v);//�������� ������ � �������
}



//�������� �������� �� �������
template <class T>
void Vector<T>::Delete_from_deque(T key)
{
	vector<T> v;
	T t;
	bool answer = false;

	while (!s.empty())//���� ������� �� �����
	{
		t = s.front();//�������� ������� �� ������� �������
		//���� t �� ����� �����, �� �������� ��� � ������
		if (t != key)
		{
			v.push_back(t);
		}
		else
		{
			answer = true;
		}
		s.pop_front();//������� ������� �� �������
	}

	//�������� ������ � �������
	s = copy_vector_to_deque(v);

	if (answer == false)
	{
		cout << "� ������� ��� ��������� � ������ ���������" << endl;
	}
}




//��������� ���� ��������� �� ������������ ������� �������
template <class T>
void Vector<T>::Multiplication()
{
	vector<T> v;
	T m = Max();
	T t;

	while (!s.empty())
	{
		t = s.front();
		v.push_back(t * m);
		s.pop_front();
	}

	s = copy_vector_to_deque(v);
}
