// Лаба 17 (сортировка).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


// Сортировки: быстрая и подсчета


#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cmath>
using namespace std;


void CountingSort(int mass[], int n) // сортировка подсчетом
{
    int max = 0, min = 0;
    for (int i = 0; i < n; i++)
    {
        if (mass[i] > max)
            max = mass[i];
        if (mass[i] < min)
            min = mass[i];
    }
    int* tmp = new int[max + 1 - min];
    for (int i = 0; i < max + 1 - min; i++)
    {
        tmp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        tmp[mass[i] - min] = tmp[mass[i] - min] + 1;
    }
    int i = 0;
    for (int j = min; j < max + 1; j++)
    {
        while (tmp[j - min] != 0)
        {
            mass[i] = j;
            tmp[j - min]--;
            i++;
        }
    }
}

void qsortRecursive(int* mass, int n) // сортировка быстрая
{
    //Указатели в начало и в конец массива
    int i = 0;
    int j = n - 1;

    //Центральный элемент массива
    int mid = mass[n / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (mass[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (mass[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mass[i];
            mass[i] = mass[j];
            mass[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        qsortRecursive(mass, j + 1);
    }
    if (i < n) {
        //"Првый кусок"
        qsortRecursive(&mass[i], n - i);
    }
}


void cin_mass(int n, int mass[])
{ 
    for (int i = 0; i < n; i++)
    {
        cin >> mass[i];
    }

    cout << endl << endl;
}

void cout_mass(int n, int mass[])
{
    for (int i = 0; i < n; i++)
    {
        cout << mass[i] << "\t";
    }
    cout << endl << endl;
}




int main() 
{
    setlocale(LC_ALL, "Russian");
    int work;
    int n;

    cout << "Введите количество элементов" << endl;
    cin >> n;
    while (n < 2)
    {
        cout << "Неправильный ввод, пожалуйста введите заного" << endl;
        cin >> n;
    }
    int* mass = new int[n];
    cout << endl;
    
    cout << "Введите элементы массива" << endl;
    cin_mass(n, mass);
    cout << "Наш массив" << endl;
    cout_mass(n, mass);

    cout << "Введите, каким методом будем сортировать массив:" << endl;
    cout << "1 - сортировка бысроая; "  " 2 - сортировка подсчётом ;" << endl;
    cout << "Выбрали сортировку номер:" << endl;
    cin >> work;

    while ((work < 1) || (work > 2))
    {
        cout << "Таких номеров у сортировок нет, пожалуйста введите заного" << endl;
        cout << "Есть только цифры 1 и 2" << endl;
        cout << "Выбрали сортировку номер:" << endl;
        cin >> work;
    }
    cout << endl;


    if (work == 1)
    {
        cout << "Вы выбрали сортировку быстрая" << endl << "Сортируем массив" << endl;
        qsortRecursive(mass, n);
    }
    else
    {
        cout << "Вы выбрали сортировку подсчетом" << endl << "Сортируем массив" << endl;
        CountingSort(mass, n);
    }
    

    cout << "Получившийся массив" << endl;
    cout_mass(n, mass);
    cout << endl << endl;
}