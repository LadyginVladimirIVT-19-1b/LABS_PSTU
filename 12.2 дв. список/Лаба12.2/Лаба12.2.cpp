// Лаба12.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


//Тип информационного поля int. Удалить из списка все элементы с четными информационными полями.


    #include <iostream>
    #include <string.h>
    using namespace std;

    struct Double_List {//структура данных
        int Data; //информационное поле
        Double_List* Next; //адресное поле
        Double_List* Prior; //адресное поле
    };


    //создание двунаправленного списка (добавления в конец)
    void Make_Double_List(int n, Double_List** Head, Double_List* Prior)
    {

        if (n > 0)
        {
            (*Head) = new Double_List();
            //выделяем память под новый элемент
            cout << "Введите данные" << endl;
            cin >> (*Head)->Data;
            //вводим значение информационного поля
            (*Head)->Prior = Prior;
            (*Head)->Next = NULL;//обнуление адресного поля
            Make_Double_List(n - 1, &((*Head)->Next), (*Head));
        }
        else (*Head) = NULL;

    }


    //печать двунаправленного списка
    void Print_Double_List(Double_List*& Head)
    {
        if (Head != NULL)
        {
            cout << Head->Data << "\t";
            Print_Double_List(Head->Next);
            //переход к следующему элементу
        }
        else
        {
            cout << endl;
        }
    }


    /*удаление элемента с заданным номером из двунаправленного списка*/
    void Delete_Item_Double_List(Double_List*& Head, int& n, int Number)
    {
        Double_List* ptr;//вспомогательный указатель
        Double_List* Current = Head;


        for (int i = 1; i < Number && Current != NULL; i++)
        {
            Current = Current->Next;
        }

        if (Current != NULL)
        {//проверка на корректность
            if (Number == n && n == 1)
            {
                Head = NULL;
            }
            else if (Current->Prior == NULL)
            {//удаляем первый элемент
                Head = Head->Next; 
                delete(Current);
                Head->Prior = NULL;
                Current = Head;
            }
            else
            {//удаляем последний элемент
                if (Current->Next == NULL)
                {
                    //удаляем последний элемент
                    Current->Prior->Next = NULL;
                    delete(Current);
                    Current = Head;
                }
                else
                {//удаляем непервый и непоследний элемент
                    ptr = Current->Next;
                    Current->Prior->Next = Current->Next;
                    Current->Next->Prior = Current->Prior;
                    delete(Current);
                    Current = ptr;
                }
            }
            n--;
        }
    }


    void delere_elem(Double_List*& Head, int& n)
    {
        Double_List* Current = Head;
        bool answer = false;

        for (int Number = 1; Number <= n && Current != 0; Number++)
        {
            if (Current->Data % 2 == 0)
            {
                cout << "Удаляем: " << Current->Data << endl;
                Delete_Item_Double_List(Head, n, Number);
                answer = true;
                if (n == 0)
                {
                    cout << "Элементов в списке не осталось" << endl;
                }
                else
                {
                    cout << "Осталось" << endl;
                    Number--;
                    Print_Double_List(Head);
                }
            }
            Current = Current->Next;       
        }

        if (answer == false)
        {
            cout << "Все элементы списка нечетные" << endl;
        }
    }




    int main()
    {
        setlocale(LC_ALL, "Russian");
        int n;


        cout << "Введите количество элементов списка" << endl;
        cin >> n;
        while (n <= 0)
        {
            cout << "Неправильный ввод, введите заного" << endl;
            cin >> n;
        }
        cout << endl;


        Double_List* Head; //указатель на первый элемент списка
        Double_List* Prior = NULL;


        Make_Double_List(n, &Head, Prior);
        cout << endl;
        cout << "Наш список" << endl;
        Print_Double_List(Head);
        cout << endl;

        cout << "Удаляем все элементы, информационное поле которых кратно 2" << endl;
        delere_elem(Head, n);
        cout << endl << endl;

        if (n != 0)
        {
            cout << "Получившийся список" << endl;
            Print_Double_List(Head);
            cout << endl << endl;
        }
        return 0;

    }
