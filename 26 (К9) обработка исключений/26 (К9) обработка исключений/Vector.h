#pragma once

#include <iostream>

using namespace std;

const int MAX_SIZE = 30;//������������ ������ �������

class Vector
{
	int size;//������� ������
	int* beg;//��������� �� ������ ������������� ������� public:
public:
	Vector() { size = 0; beg = 0; }//����������� ��� ����������
	Vector(int s, int k);//����������� � ����������
	Vector(int s, int* mas);//����������� � ����������
	Vector(const Vector& v);//����������� �����������
	~Vector();//����������

	const Vector& operator=(const Vector& v);// �������� ������������ 
	int operator[](int i);//������ �� �������

	int operator()();
	int operator +(int i);//������ �� �������
	int operator * ();
	

	//������������� ������� �����-������
	friend ostream& operator<<(ostream& out, const Vector& v);
	friend istream& operator>>(istream& in, Vector& v);
};