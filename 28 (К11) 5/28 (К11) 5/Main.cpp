/*������ 5
������������������� ����� � ������
������� ���������� � �������

������� 1: ����� ����������� ������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� � ������� �� ��������� ��������� � ������� �� �� ����������
������� 3: ������ ������� �������� �� ������������ ������� ����������*/



#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"
#include "Time.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int n;

	cout << "������� ���������� ���������?   ";
	cin >> n;
	cout << endl;

	Vector<Money>v(n);
	v.Print_deque();


	Money m = v.Min();
	cout << "�������� ��� �� �������?   ";
	int pos;
	cin >> pos;//������ ������� ��� ����������

	v.Add_to_deque(m, pos);
	v.Print_deque();//������ �������



	Money key;
	cout << "������� ��������, ������� ���� ������?  " << endl;
	cin >> key;

	cout << "������� ��� ��������, ������ ������� ��������    " << key << endl;
	v.Delete_from_deque(key);
	v.Print_deque();



	cout << "�������� ��� �������� �� ������������ �������" << endl;
	v.Multiplication();
	v.Print_deque();
}