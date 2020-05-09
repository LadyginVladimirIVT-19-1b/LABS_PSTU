/*������ 1
��������� � ������
��� ��������� � int

������� 1: ����� ����������� ������� � �������� ��� �� �������� ������� ����������
������� 2: ����� �������� � ������� �� ��������� ��������� � ������� �� �� ����������
������� 3: ������ ������� �������� �� ������������ ������� ����������*/



#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


typedef vector<int>Vec;//���������� ��� ��� ������ � ��������
//������� ��� ������������ �������
Vec make_vector(int n)
{
	Vec v;//������ ������
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 101 - 50;
		v.push_back(a);//��������� � � ����� �������
	}
	cout << endl;
	return v;//���������� ������ ��� �������� ������ �������
}


//������� ��� ������ �������
void print_vector(Vec v)
{
	cout << "��� ������" << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "   ";
	cout << endl << endl;
}
//�������� �������



int srednee(Vec v)
{
	int s = 0;
	//������� �������
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();//���������� ��������� � �������
	return s / n;
}



//����� ������������� ��������
int max(Vec v)
{
	int m = v[0],//����������� �������
		n = 0;//����� ������������ ��������
	for (int i = 0; i < v.size(); i++)//������� �������
		if (m < v[i])
		{
			m = v[i];//������������ �������
			n = i;//����� �������������
		}

	cout << "������������ �������   " << m << endl << endl;
	return n;
}



//����� ������������ ��������
int min(Vec v)
{
	int m = v[0],//����������� �������
		n = 0;//����� ������������ ��������
	for (int i = 0; i < v.size(); i++)//������� �������
		if (m > v[i])
		{
			m = v[i];//����������� �������
			n = i;//����� ������������
		}
	return m;
}


void add_elem(Vec& v, int el, int pos)
{
	//��������� �� ����� pos ������� el
	v.insert(v.begin() + pos, el);
}


void delete_vector(Vec& v, int key)
{
	bool answer = false;
	int num = 0;
	for (int i = 0; i < v.size(); i++)//������� �������
	{
		if (v[i] == key)
		{
			v.erase(v.begin() + num);
			answer = true;
			num--;
			i--;
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



void multiplication(Vec& v)
{
	int m = max(v);
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * v[m];
}



void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	try
	{
		vector<int> v;
		vector<int>::iterator vi = v.begin();


		//������������ �������
		int n;
		cout << "���������� ���������?   "; 
		cin >> n;
		v = make_vector(n);//�������� �������
		print_vector(v);//������ �������


		//���������� ������������ ��������
		int el = min(v);
		cout << "����������� �������   ";
		cout << el << endl << endl;

		//������� ��� �������
		cout << "�� ����� ������� ������?   ";
		int pos;
		cin >> pos;

		//���������� ������, ���� ������� ��� ������� ������ ������� �������
		if (pos > v.size())throw 1;
		
		add_elem(v, el, pos);//���������� ��������		
		print_vector(v);



		int key;
		cout << "�������� � ������ ���������� �������?   ";
		cin >> key;
		delete_vector(v, key);//������� �������� �� ��������
		print_vector(v);



		//������ ������� �������� �� ������������ �������� �������
		cout << "�������� ��� �������� �� ������������ �������" << endl << endl;
		multiplication(v);//��������� ���� ���������� �� ������������ �������
		print_vector(v);
	}
	catch (int)//���� ��������� ������
	{
		cout << "������!" << endl;
	}
	cout << endl << endl;
}