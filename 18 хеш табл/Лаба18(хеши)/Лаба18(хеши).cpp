// Лаба18(хеши).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


/*Данные:   ФИО, №паспорта, адрес
Ключ:   ФИО
Хеш функция:   H(k) = k mod M
Метод хеширования:   Метод цепочек */

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>

using namespace std;
extern int size = 0;
#define PRIME_SIZE 10    // Использовано просто число



class People // Класс, который содержит немного информации о человеке.
{
public:
    People* next; // При возникновении коллизии элементы будут помещены в односвязный список.
    char* FIO;
    int Passport;
    int Address;

    People()
    {
        this->next = NULL;
    }

    People(char* FIO, int Passport, int Address = 0)
    {
        this->FIO = FIO;
        this->Passport = Passport;
        this->Address = Address;
        this->next = NULL;
    }

    ~People()
    {
        if (this->next != NULL)
        {
            delete this->next;
        }
    }
};



class HashTable
{

    People* table[PRIME_SIZE];

    // Самая простоя хеш-функция. Считает сумму ASCII кодов, делит на константу и
    // получает остаток от деления.
    static int hash(char* FIO)
    {
        int tmp;
        for (int i = 0; i < strlen(FIO); i++)
        {
            tmp = (int)FIO[i];
        }
        return tmp % PRIME_SIZE;
    }

public:
    HashTable()
    {
        for (int i = 0; i < PRIME_SIZE; i++)
        {
            table[i] = NULL;
        }
    }


    ~HashTable()
    {
        //cout << "Delete table\n";
        for (int i = 0; i < PRIME_SIZE; i++)
        {
            delete table[i];
        }
    }


    // Вставляет элемент в таблицу
    void push(char* FIO, int Passport, int Address)
    {
        int hashNumber = hash(FIO);
        People* temp = new  People(FIO, Passport, Address);
        People* place = table[hashNumber];

        if (place == NULL)
        {
            table[hashNumber] = temp;
            return;
        }

        while (place->next != NULL)
        {
            place = place->next;
        }
        place->next = temp;
    }


    // Получает элемент из таблицы по его имени.
    People* find(char* FIO)
    {
        bool a = 1;
        int hashNumber = hash(FIO);
        People* result = table[hashNumber];
        if (!result)
        {
            cout << "Элемент не найден" << endl;
            return NULL;
        }
        while (result->FIO != FIO)
        {
            if (!result->next)
            {
                cout << "Элемент не найден" << endl;
                return NULL;
            }
            result = result->next;
        }
        return result;
    }
};



int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    HashTable newTable;

    char* tmp = new char[30];
    int pasport;
    int address;
    int n;

    cout << "Введите количество элементов" << endl;
    cin >> n;


    cout << "Введите данные людей" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите ФИО" << endl;
        cin >> tmp;
        pasport = rand() % 1000+100;
        address = rand() % 10000 + 100;
        cout << "Его паспорт и адресс" << endl << pasport << "\t" << address << endl;
        newTable.push(tmp, pasport, address);
        cout << endl;
        
    }

   
   
    cout << endl;
    cout << "Введите человека, которого хотите найти" << endl;
    cin >> tmp;
    People* search = newTable.find(tmp);

    if (search)
    {
        cout << "Обнаружен следующий человек:  " << search->FIO << endl << "Паспорт этого человека:  "
            << search->Passport << endl << "Адрес этого человека:  " << search->Address << endl;
    }
    cout << endl << endl;
    return 0;
}





















