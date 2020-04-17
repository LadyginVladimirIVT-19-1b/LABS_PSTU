// Лаба19(дерево).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// Тип информационного поля char. Найти высоту дерева.


#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;



struct Node
{
    Node* left, * right;
    char  data;
};



//вставка
void Add_elem(Node*& wood, char data) 
{
    if (wood == NULL) 
    {
        wood = new (nothrow) Node();
        if (wood != NULL) 
        {
            wood->left = wood->right = NULL;
            wood->data = data;
        }
    }
    else if (data < wood->data)
    {
        Add_elem(wood->left, data);
    }
    else
    {
        Add_elem(wood->right, data);
    }
}

//удаление всех
void Clear_wood(Node* wood)
{
    if (wood != NULL)
    {
        if (wood->left != NULL)
        {
            Clear_wood(wood->left);
        }
        if (wood->right != NULL)
        {

            Clear_wood(wood->right);
        }
    
        delete wood;
    }
}

//высота дерева
int Height(const Node* wood) 
{
    int left, right, height = 0;
    if (wood != NULL) 
    {
        left = Height(wood->left);
        right = Height(wood->right);
        height = ((left > right) ? left : right) + 1;
    }
    return height;
}




int main() 
{

    Node* wood = NULL;

    setlocale(LC_ALL, "Russian");
    int n, how_much;
    char data;

    cout << "Сколько элементов будет в дереве ?" << endl;
    for (int menu = 0; menu == 0;)
    {
        cin >> n;
        if (n > 1)
        {
            menu++;
        }
        else
        {
            cout << "Неправильный ввод, пожалйста введите заного" << endl;
        }
    }
    cout << endl;

    char* tmp = new char[n];   

    for (int count = 0; count < n; count++)
    {
        cout << "Введите элемент #" << count + 1 << " : " << endl;
        cin >> tmp[count];
        Add_elem(wood, tmp[count]);
    }
    cout << endl;

    cout << "Высота дерева равна" << endl << Height(wood) << endl;
    Clear_wood(wood);
    delete[]tmp;
    cout << endl;
}

