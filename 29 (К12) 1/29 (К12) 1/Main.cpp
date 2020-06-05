/*������ 1
1 ��������� - set
2 ��� ��������� - float

1) ����� ����������� ������� � �������� ��� �� �������� ������� ����������
2) ����� �������� ������� �������� ��������������� � ������� �� �� ����������
3) ������ ������� ��������� �� ������������ ������� ����������*/




#include <iostream>
#include <iterator>  
#include <set>        
using namespace std;



typedef set<float, less<float>>tset;//����������� ���� tset
tset::iterator it;//��������


//������� ��� ������������ ����������
tset make_set(int n)
{
	tset m;
	float a;
	for (int i = 0; i < n; i++)
	{
		cout << "������� ������ ��������" << endl;
		cin >> a;
		
		m.insert(a);// ��������� ������� � ���������
	}
	cout << endl;
	return m;//���������� ������������ ���������
}

// ����� ����������
void print_set(tset m)
{
	cout << "��� set ���������" << endl;
	for (it = m.begin(); it != m.end(); ++it)
		cout << *it << "   ";
	cout << endl << endl;
}

//������� �������������� ��������
int srednee(tset m)
{
	float sum = 0.0;
	//������� ���� ���������
	for (it = m.begin(); it != m.end(); ++it)
		sum += *it;
	int n = m.size();//���������� ���������
	return sum / n;
}

//��������� ���� ��������� ���������� �� ������������ ������� 
void multiplication(tset& m)
{
	float max;
	max = *m.rbegin();
	cout << "������������ �������: " << max << endl << endl;


	float tmp;
	cout << "�������� �������� �� ������������" << endl;
	for (it = m.begin(); it != m.end(); ++it)
	{
		tmp = *it * max;
		cout << tmp << "   ";
	}
}

//�������� ��������� ����������� ������� �������������� ��������
void delete_set(tset& m, float middle)
{
	if (*m.rbegin() > middle)
	{
		m.erase(*m.rbegin());//�������� ��������	
		delete_set(m, middle);
	}	
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������� ���������� ���������" << endl;
	cin >> n;
	cout << endl;


	tset m = make_set(n);
	print_set(m);


	float min;
	min = *m.begin();
	cout << "����������� �������: " << min << endl ;
	cout << "��������� ����������� ������� ��� ������" << endl << endl;


	cout << "������� �������������� �������� �����" << endl;
	float middle = srednee(m);
	cout << middle << endl;

	cout << "������� ��� �������� ������ �������� ��������������� ��������" << endl;
	delete_set(m, middle);
	print_set(m);


	multiplication(m);
	cout << endl << endl;
}





