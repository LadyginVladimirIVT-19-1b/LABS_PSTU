/*������ 4
������� ���������� � ������� � ������������

������� 1: ����� ����������� ������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� � ������� �� ��������� ��������� � ������� �� �� ����������
������� 3: ������ ������� �������� �� ������������ ������� ����������*/


#include <iostream>
#include <ctime>
#include <vector>
#include<deque>
#include "Money.h"
using namespace std;

typedef deque <Money> Deq;//�������
typedef vector <Money> Vec;//������



//�������� ������� � ������
Vec copy_deque_to_vector(Deq s)
{
	Vec v;
	while (!s.empty())//���� ������� �� �����
	{
		//�������� � ������ ������� �� ������ �������
		v.push_back(s.front());
		s.pop_front();
	}
	return v; //������� ������ ��� ��������� �������
}



//�������� ������ ��������
Deq copy_vector_to_deque(Vec v)
{
	Deq s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push_front(v[i]);//�������� � ������� ������� �������
	}
	return s; //������� ������� ��� ��������� �������
}



Deq make_deque(int n)
{
	Deq d;
	Money t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;//���� ����������
		d.push_back(t);//���������� � �������
	}
	return d;//������� ������� ��� ��������� �������
}


Deq print_deque(int n, Deq s)
{
	cout << "���� �������" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << s.front() << endl;
		s.pop_front();
	}
	cout << endl << endl;
	return s;//������� ������� ��� ��������� �������
}



//����� ������������� �������� � �������
Money Max(Deq s)
{
	Money m = s.front();//���������� m ����������� �������� �� ������� �������
	Vec v = copy_deque_to_vector(s);//�������� ������� � ������

	while (!s.empty())//���� ������� �� �����
	{
		if (s.front() > m)m = s.front();//���������� m � ������� � ������� �������
		s.pop_front();//������� ������� �� �������
	}
	s = copy_vector_to_deque(v);//������� ������ � �������

	cout << "������������ �������   " << m << endl;
	return m; 
}


//����� ������������ �������� � �������
Money Min(Deq s)
{
	Money m = s.front();
	Vec v = copy_deque_to_vector(s);

	while (!s.empty())
	{
		if (s.front() < m)m = s.front();
		s.pop_front();
	}
	s = copy_vector_to_deque(v);
	cout << "����������� �������   " << m << endl;
	return m;
}


//���������� �������� � �������
void Add_to_deque(Deq& s, Money el, int pos, int& n)
{
	Vec v;
	Money t;
	int i = 1;//����� �������� � �������
	while (!s.empty())//���� ������� �� �����
	{
		t = s.front();//�������� ������� �� �������
		//���� ����� ����� ������ �������, �� ������ �������� �������
		if (i == pos)
		{
			v.push_back(el);//�������� ����� ������� � ������
			n++;
		}
		v.push_back(t);//�������� ������� �� ������� � ������
		s.pop_front();//������� ������� �� �������
		i++;
	}
	s = copy_vector_to_deque(v);//�������� ������ � �������
}



//������� �������� ������� ����� �� �������
void Delete_from_deque(Deq& s, int& n, Money key)
{
	Vec v;
	Money t;
	bool answer = false;

	while (!s.empty())//���� ������� �� ������
	{
		t = s.front();//�������� ������� �� ������� �������
		//���� �� �� ����� �������������, ������� ������� � ������
		if (t != key)
		{
			v.push_back(t);
		}
		else
		{
			n--;
			answer = true;
		}
		s.pop_front();//������� ������� �� �������
	}
	s = copy_vector_to_deque(v);//�������� ������ � �������

	if (answer == false)
	{
		cout << "� ������� ��� ��������� � ������ ���������" << endl;
	}
}

//��������� ���������
void multiplication(Deq& s)
{
	Money m = Max(s);//������� ������������ ������� �������
	Vec v;
	Money t;
	while (!s.empty())//����  ������� �� �����
	{
		t = s.front(); //�������� ������� �� �������  �������
		v.push_back(t * m);//�������� t �� ������������ �������  ������� � ��������� � ������
		s.pop_front();//������� ������� �� �������  �������
	}
	s = copy_vector_to_deque(v);//�������� ������ � �������
}


void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	Money t;
	Deq s;
	int n;

	cout << "������� ���������� ���������?   ";
	cin >> n;
	cout << endl;

	s = make_deque(n);//������� �������
	print_deque(n, s);//������ �������


	Money m = Min(s);
	cout << "�������� ��� �� �������?   ";
	int pos;
	cin >> pos;//������ ������� ��� ����������
	Add_to_deque(s, m, pos, n);
	print_deque(n, s);//������ �������
	
	Money key;
	cout << "������� ��������, ������� ���� ������?  " << endl;
	cin >> key;

	cout << "������� ��� ��������, ������ ������� ��������    " << key << endl;
	Delete_from_deque(s, n, key);//��������
	print_deque(n, s);//������ �������

	cout << "�������� ��� �������� �� ������������ �������" << endl;
	multiplication(s);
	print_deque(n, s);

}
