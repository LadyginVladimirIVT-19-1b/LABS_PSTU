#pragma once


#include <iostream>
#include <cstdlib>
#include <vector>
#include "Money.h"
using namespace std;



//������ ������
template<class T>
class Vector
{
	vector <T> v;//���������������� ��������� ��� �������� ��������� �������
	int len;
public:
	Vector(void);//����������� ��� ���������
	Vector(int n);//����������� � ����������
	~Vector(void);//����������

	void Print_vector();//������	
	void Add_elem(T el, int pos);//���������� �������� el �� ������� pos
	int Max();//����� ����� ������������ ��������
	void Delete_vector(Money key);//������� ������� �� ������� pos
	Money Min();//����� ����� ����������� ��������
	void Multiplication();//������� �� �����������
};


//����������� ��� ���������
template <class T>
Vector<T>::Vector()
{
	len = 0;
}


//����������
template <class T>
Vector<T>::~Vector(void)
{
}


//����������� � ����������
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}



//������
template <class T>
void Vector<T>::Print_vector()
{
	cout << "��� ������" << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "     ";
	cout << endl << endl;
}


//���������� ��������
template<class T>
void Vector<T>::Add_elem(T el, int pos)
{
	v.insert(v.begin() + pos, el);
}


//����� ������������� ��������
template <class T>
int Vector<T>::Max()
{
	T m = v[0];
	int n = 0;
	for (int i = 1; i < v.size(); i++)
		if (v[i] > m)
		{
			m = v[i];
			n = i;
		}
	cout << "������������ �������   " << m << endl << endl;
	return n;
}


//�������� �������� �� ������� pos
template<class T>
void Vector<T>::Delete_vector(Money key)
{
	bool answer = false;
	int num = 0;
	for (int i = 0; i < v.size(); i++)//������� �������
	{
		if (v[i] == key)
		{
			v.erase(v.begin() + num);
			answer = true;
			i--;
			num--;
		}
		num++;
	}
	cout << endl;

	if (answer == false)
	{
		cout << "� ������� ��� ��������� � ������ ���������" << endl;
	}
	cout << endl;
}


//����� ������������ ��������
template<class T>
Money Vector<T>::Min()
{
	T m = v[0];
	int n = 0;
	for (int i = 1; i < v.size(); i++)
		if (v[i] < m)
		{
			m = v[i];
			n = i;
		}
	cout << "����������� �������   " << m << endl << endl;
	return m;
}


//������� ���� ��������� ������� �� ����������� �������
template<class T>
void Vector<T>::Multiplication()
{
	int m = Max();
	T max = v[m];
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * max;
}