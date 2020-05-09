/*	������� ����� Time ��� ������ � ���������� �����������.
�������� ������ ���� ����������� � ���� ���� �����: ������ ���� int � ������� ���� int.
��� ������ ������ ���������� �� ������ ����������.

�����������:
��������� ������
��������� ��������� ���������� (==� !=)
�������:
������� ��� ������ ������� ��������� ��������.
��������� ��� ������ � �������� ��������� �� 1 ������ 30 ������.
�������� K ������� ����� ������ � ������� N.*/



#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file_work.h"




int main()
{
	setlocale(LC_ALL, "Russian");
	Time p, p1, p2;
	int k, c;
	char file_name[30];
	do
	{
		//����
		cout << "\n1. ������� ����";						
		cout << "\n2. ������� ���� �� �����";				
		cout << "\n3. ������� �������� �� �����";
		cout << "\n4. �������� �������� � ����";			
		cout << "\n5. ��������� �������(�) �� 1 : 30 � �����";			
		cout << "\n0. �����\n";								
		cin >> c;

		int nom;

		switch (c)
		{
		case 0:
			return 0;

		case 1:
			cout << "��� �����?   ";
			cin >> file_name;

			k = make_file(file_name);
			if (k < 0)cout << "���������� ������� ����";
			break;
			cout << endl;


		case 2:
			cout << "��� �����?   ";
			cin >> file_name;

			k = print_file(file_name);
			if (k == 0)cout << "���� ������\n";
			if (k < 0)cout << "���������� ��������� ����\n";
			break;
			cout << endl;

		case 3:
			cout << "��� �����?   ";
			cin >> file_name;

			nom = 1;

			k = del_file(file_name, nom);

			if (k < 0)cout << "���������� ��������� ����";
			break;
			cout << endl;

		case 4:
			cout << "��� �����?   ";
			cin >> file_name;
			cout << "�����?   ";
			cin >> nom;

			cout << endl;
			int replay;
			cout << "���������� �����������?   ";
			cin >> replay;
			cout << endl;

			for (int i = 0; i < replay; i++)
			{
				cout << "����� �����: ";
				cin >> p1;
				k = add_file(file_name, nom, p1);
				nom++;

				if (k < 0) cout << "���������� ��������� ����";
				if (k == 0) k = add_end(file_name, p1);
				cout << endl;
			}
			break;
			cout << endl;

		case 5:
			cout << "��� �����?   ";
			cin >> file_name;
			nom = 1;

			k = change_file(file_name, nom);

			if (k < 0) cout << "\n���������� ��������� ����";
			break;
			cout << endl;

		default:
			cout << "����� ������ ���" << endl;
		}

	} while (c != 0);
}



