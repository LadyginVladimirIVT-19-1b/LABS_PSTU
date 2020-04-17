// Сортировка массива итог.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


// Отсортировать массив методами: вставки, пузырька и выбора


#include <iostream>
#include <ctime>
using namespace std;

void cout_mass(int mass[], int n) //Вывод массива
{
    int i = 0;
    //Вывод массива
    cout << "Шаг сортировки массива" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << mass[i] << "\t";
    }
    cout << endl;
}

void insert(int mass[], int n, bool answer = false) //Метод вставки
{
    int p;
    int i = 0;
    int j = 0;
    for (int i = 2; i <= n; i++)                    //Перебор всего массива
    {
        j = i;
        answer = false;
        while (j > 0 && answer == false)              //Сортировка массива
        {
            if (mass[j - 1] <= mass[j])
            {
                answer = true;
            }
            else                                    //Перестановка двух элементов с помощью дополнительной переменной
            {
                p = mass[j - 1];
                mass[j - 1] = mass[j];
                mass[j] = p;
                j--;
            }
        }
        //Вывод массива
        cout_mass(mass, n);
    }
    cout << endl << endl;
}


void vial(int mass[], int n)     //Метод пузырька
{
    int p;
    int i = 0;
    int j = 0;
    for (int i = 1; i <= n; i++)		// Перебор всех элементов массива
    {
        j = 1;
        while (j <= n - i)			// Сортировка
        {
            if (mass[j] > mass[j + 1])
            {
                p = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = p;

                //Вывод массива
                cout_mass(mass, n);
            }
            else
            {
                j++;
            }
        }
    }
    cout << endl << endl;
}


void of_choice(int mass[], int n, int min)   //Метод выбора
{
    int p;
    int i = 0;
    int j = 0;
    for (int i = 1; i <= n - 1; i++)		//Проходит все элементы массива и сравнивает их
    {
        min = mass[i];
        p = i;
        for (int j = i + 1; j <= n; j++)		//Соритровка массива
        {
            if (mass[j] < min)
            {
                min = mass[j];
                p = j;
            }
        }
        mass[p] = mass[i];
        mass[i] = min;

        //Вывод массива
        cout_mass(mass, n);
    }
    cout << endl << endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int n = -1;
    int i = 0;
    int min = 0;
    bool answer = false;
    int start1 = 0;
    int work = -1;

    while (n <= 0)              //Длинна массива
    {
        cout << "Введите количество элементов массива" << endl;
        cin >> n;
    }
    cout << endl;

    //Ввод массива
    cout << "Наш массив" << endl;
    int* mass = new int[n];
    for (int i = 1; i <= n; i++)
    {
        mass[i] = rand() % 101 - 50;
        cout << mass[i] << "\t";
    }
    cout << endl << endl;

    while ((work < 1) || (work > 3))
    {
        cout << "Введите с каким массивом будем работать: 1 - Вставка; 2 - Пузырьком; 3 - Выбора" << endl;
        cin >> work;
    }
    cout << endl;


    if (work == 1)
    {
        insert(mass, n, answer);
    }
    else if (work == 2)
    {
        vial(mass, n);
    }
    else
    {
        of_choice(mass, n, min);
    }


    //Вывод массива
    cout << "Отсортированный массив" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << mass[i] << "\t";
    }
    cout << endl;


    clock_t end1 = clock();             //Время работы программы
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    cout << endl << "Затраченное время" << endl << time1;
    cout << endl;

}

