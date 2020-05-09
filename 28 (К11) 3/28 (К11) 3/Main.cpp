/*������������������� ����� � ������ (��. �� � 24 (7�))

������� 1: ����� ����������� ������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� � ������� �� ��������� ��������� � ������� �� �� ����������
������� 3: ������ ������� �������� �� ������������ ������� ����������*/



#include <iostream>
#include <cstdlib>
#include <vector>
#include "Vector.h"
#include "Money.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	int n;

	cout << "���������� ���������?   ";
	cin >> n;
	Vector<Money>v(n);

	v.Print_vector();//������ �������

	Money m = v.Min();
	cout << "�������� ��� �� �������?   ";
	int p;
	cin >> p;//������ ������� ��� ����������
	v.Add_elem(m, p);//�������� ������� � ������
	v.Print_vector();//������ �������

	Money key;
	cout << "������� ��������, ������� ���� ������?  " << endl;
	cin >> key;

	cout << "������� ��� ��������, ������ ������� ��������    " << key << endl;
	v.Delete_vector(key);//��������
	v.Print_vector();//������

	cout << "�������� ��� �������� �� ������������ �������" << endl;
	v.Multiplication();//�������
	v.Print_vector();

}

