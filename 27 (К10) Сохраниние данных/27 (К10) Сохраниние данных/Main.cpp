/*	Создать класс Time для работы с временными интервалами.
Интервал должен быть представлен в виде двух полей: минуты типа int и секунды типа int.
при выводе минуты отделяются от секунд двоеточием.

Реализовать:
вычитание секунд
сравнение временных интервалов (==и !=)
Задание:
Удалить все записи большие заданного значения.
Увеличить все записи с заданным значением на 1 минуту 30 секунд.
Добавить K записей после записи с номером N.*/



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
		//Меню
		cout << "\n1. Создать файл";						
		cout << "\n2. Вывести файл на экран";				
		cout << "\n3. Удалить элементы из файла";
		cout << "\n4. Добавить элементы в файл";			
		cout << "\n5. Увеличить элемент(ы) на 1 : 30 в файле";			
		cout << "\n0. Выход\n";								
		cin >> c;

		int nom;

		switch (c)
		{
		case 0:
			return 0;

		case 1:
			cout << "Имя файла?   ";
			cin >> file_name;

			k = make_file(file_name);
			if (k < 0)cout << "Невозможно создать файл";
			break;
			cout << endl;


		case 2:
			cout << "Имя файла?   ";
			cin >> file_name;

			k = print_file(file_name);
			if (k == 0)cout << "Файл пустой\n";
			if (k < 0)cout << "Невозможно прочитать файл\n";
			break;
			cout << endl;

		case 3:
			cout << "Имя файла?   ";
			cin >> file_name;

			nom = 1;

			k = del_file(file_name, nom);

			if (k < 0)cout << "Невозможно прочитать файл";
			break;
			cout << endl;

		case 4:
			cout << "Имя файла?   ";
			cin >> file_name;
			cout << "Номер?   ";
			cin >> nom;

			cout << endl;
			int replay;
			cout << "Количиство добавленний?   ";
			cin >> replay;
			cout << endl;

			for (int i = 0; i < replay; i++)
			{
				cout << "Новое время: ";
				cin >> p1;
				k = add_file(file_name, nom, p1);
				nom++;

				if (k < 0) cout << "Невозможно прочитать файл";
				if (k == 0) k = add_end(file_name, p1);
				cout << endl;
			}
			break;
			cout << endl;

		case 5:
			cout << "Имя файла?   ";
			cin >> file_name;
			nom = 1;

			k = change_file(file_name, nom);

			if (k < 0) cout << "\nНевозможно прочитать файл";
			break;
			cout << endl;

		default:
			cout << "Такой задачи нет" << endl;
		}

	} while (c != 0);
}



