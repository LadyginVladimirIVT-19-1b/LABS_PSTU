// Лаба13(строки).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


//Отсортировать слова в строке в лексикографическом порядке(по алфавиту).


#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char** mass = new char* [20];

    cout << "Введите 5 слов" << endl;
    for (int i = 0; i < 5; i++)
    {
        mass[i] = new char[20];
        cin >> mass[i];
    }


    cout << endl << "Сортируем слова по алфавиту (сортировка идет: сначало английский, потом русский)" << endl;
    for (int i = 0; i < 5; i++) 
    {
        for (int j = i + 1; j < 5; j++)
            if (strcmp(mass[i], mass[j]) > 0) 
            {
                char* tmp = mass[i];
                mass[i] = mass[j];
                mass[j] = tmp;
            }
    }


    cout << endl << "Получившийся набор слов" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << mass[i] << "\t";
    }
    cout << endl << endl;
}