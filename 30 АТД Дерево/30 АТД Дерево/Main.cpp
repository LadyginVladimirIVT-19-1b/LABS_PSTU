/*Составить программу, которая формирует англо-русский словарь.
Словарь должен содержать английское слово, русское слово и количество обращений к слову.
Программа должна:
-обеспечить начальный ввод словаря (по алфавиту) с конкретными значениями счетчиков обращений;
-формирует новое дерево, в котором слова отсортированы не по алфавиту, а по количеству обращений.

Пользователь должен иметь возможность добавлять новые слова, удалять существующие,
выполнять поиск нужного слова, выполнять просмотр обоих вариантов словаря*/




#include "tree.h"
#include <Windows.h>


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string key, key2;
    treeNode* root;
    treeNode* root2;
    int n = 5;
    string m;
    int c;

    cout << "Изначально в словаре 5 слов" << endl;
    cout << "Наш корень будет таким" << endl;
    cout << "Введите слово алфавита :    ";
    cin >> key2;
    cout << "Его перевод            :    ";
    cin >> m;
    cout << "Количество обращений   :    ";
    cin >> c;

    root = new treeNode(key2, m, c);
    root2 = new treeNode(key2, m, c);
    cout << endl << endl;


    // можно сделать ввод руками попробовать
    for (int i = 2; i <= n; i++)
    {

        cout << "Введите новое слово алфавита   :    ";
        cin >> key2;
        cout << "Значение этого слова           :    ";
        cin >> m;
        cout << "Его количество обращений       :    ";
        cin >> c;

        insert(root, key2, m, c);
        insert2(root2, key2, m, c);
        cout << endl;
    }

    cout << endl << endl << endl;
    printDictionary(root);

    do
    {
        cout << endl;
        cout << "Нажмите:" << endl;
        cout << "      i чтобы добавить элемент" << endl;
        cout << "      e чтобы изменить элемент" << endl;
        cout << "      d чтобы удалить элемент" << endl;
        cout << "      s чтобы показать словарь по алфавиту" << endl;
        cout << "      s2 чтобы показать словарь по количеству обращений" << endl;
        cout << "      f чтобы найти слово" << endl;
        cout << "      exit чтобы закончить проверку" << endl << endl;

        cin >> key;

        if (key == "e")
        {
            cout << "Введите, что заменить :    ";
            cin >> key;
            cout << "На что заменить :    ";
            cin >> key2;
            cout << "Значение этого слова :    ";
            cin >> m;
            cout << "Его количество обращений :    ";
            cin >> c;
            Edit(root, key, key2, m, c);
            Edit(root2, key, key2, m, c);
        }
        else if (key == "i")
        {
            cout << "Введите новое слово в алфавит :    ";
            cin >> key2;
            cout << "Значение этого слова :    ";
            cin >> m;
            cout << "Его количество обращений :    ";
            cin >> c;
            insert(root, key2, m, c);
            insert2(root2, key2, m, c);
        }
        else if (key == "d")
        {
            cout << "Введите значение, которое хотите удалить :    ";
            cin >> key;
            if (((root = Delete(root, key2)) != NULL))
                cout << "Успешно удален элемент из словаря по алфавиту : " << key2 << endl;
        }
        else if (key == "s")
        {
            printDictionary(root);
        }
        else if (key == "s2")
        {
            printDictionary(root2);
        }
        else if (key == "f")
        {
            cout << "Введите значение, которое хотите найти :    ";
            cin >> key;
            if (!Find(root, key2))
                cout << key2 << " Слово не найдено" << endl;
        }

    } while (key != "exit");

    DeleteDictionary(root);
    DeleteDictionary(root2);
    cout << endl;
    return 0;
}



