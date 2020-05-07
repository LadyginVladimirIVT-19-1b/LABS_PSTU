
/*�����- ��������� ������ � ���������� ���� int.
����������� ��������:
[] � ������� �� �������;
() � ����������� ������� �������;
* ������ � ��������� ��������� �������� a[i]*b[i];
+ n � ������� ������ � �������� � ������� n .
������� ����������: 2 , 3*/


#include "Vector.h"
#include "error.h"
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	try
	{
		int n;
		cout << "������� ���������� ���������" << endl;
		cin >> n;

		Vector a(n, 0);
		Vector b(n, 3);
		int i;
		
		
		cout << "������� �������� ������� a" << endl;
		cin >> a;
		cout << endl;
		cout << "������ a" << endl;
		cout << a << endl << endl;
		cout << "������ b �������� ����� ��������" << endl;
		cout << b << endl << endl;

		cout << "������ ������� a" << endl;
		cout << a() << endl << endl;

		cout << "������� ����� �������� ������� a" << endl;
		cin >> i;
		cout << "������� ��� �������  " << i << endl;
		cout << a[i] << endl << endl;

		cout << "������� � ������ �������� ������� a �������" << endl;
		cin >> i;
		cout << "���� �������" << endl;
		cout << a + i << endl << endl;


		cout << "��������� ��������� �������� a[i]*b[i]" << endl;	
		for (int i = 0; i < n; i++)
		{
			cout << a[i] * b[i] << "  ";
		}
		cout << endl << endl;
	}
	catch (error e)
	{
		e.what();
	}
	return 0;
}