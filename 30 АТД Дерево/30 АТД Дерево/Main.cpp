/*��������� ���������, ������� ��������� �����-������� �������.
������� ������ ��������� ���������� �����, ������� ����� � ���������� ��������� � �����.
��������� ������:
-���������� ��������� ���� ������� (�� ��������) � ����������� ���������� ��������� ���������;
-��������� ����� ������, � ������� ����� ������������� �� �� ��������, � �� ���������� ���������.

������������ ������ ����� ����������� ��������� ����� �����, ������� ������������,
��������� ����� ������� �����, ��������� �������� ����� ��������� �������*/




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

    cout << "���������� � ������� 5 ����" << endl;
    cout << "��� ������ ����� �����" << endl;
    cout << "������� ����� �������� :    ";
    cin >> key2;
    cout << "��� �������            :    ";
    cin >> m;
    cout << "���������� ���������   :    ";
    cin >> c;

    root = new treeNode(key2, m, c);
    root2 = new treeNode(key2, m, c);
    cout << endl << endl;


    // ����� ������� ���� ������ �����������
    for (int i = 2; i <= n; i++)
    {

        cout << "������� ����� ����� ��������   :    ";
        cin >> key2;
        cout << "�������� ����� �����           :    ";
        cin >> m;
        cout << "��� ���������� ���������       :    ";
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
        cout << "�������:" << endl;
        cout << "      i ����� �������� �������" << endl;
        cout << "      e ����� �������� �������" << endl;
        cout << "      d ����� ������� �������" << endl;
        cout << "      s ����� �������� ������� �� ��������" << endl;
        cout << "      s2 ����� �������� ������� �� ���������� ���������" << endl;
        cout << "      f ����� ����� �����" << endl;
        cout << "      exit ����� ��������� ��������" << endl << endl;

        cin >> key;

        if (key == "e")
        {
            cout << "�������, ��� �������� :    ";
            cin >> key;
            cout << "�� ��� �������� :    ";
            cin >> key2;
            cout << "�������� ����� ����� :    ";
            cin >> m;
            cout << "��� ���������� ��������� :    ";
            cin >> c;
            Edit(root, key, key2, m, c);
            Edit(root2, key, key2, m, c);
        }
        else if (key == "i")
        {
            cout << "������� ����� ����� � ������� :    ";
            cin >> key2;
            cout << "�������� ����� ����� :    ";
            cin >> m;
            cout << "��� ���������� ��������� :    ";
            cin >> c;
            insert(root, key2, m, c);
            insert2(root2, key2, m, c);
        }
        else if (key == "d")
        {
            cout << "������� ��������, ������� ������ ������� :    ";
            cin >> key;
            if (((root = Delete(root, key2)) != NULL))
                cout << "������� ������ ������� �� ������� �� �������� : " << key2 << endl;
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
            cout << "������� ��������, ������� ������ ����� :    ";
            cin >> key;
            if (!Find(root, key2))
                cout << key2 << " ����� �� �������" << endl;
        }

    } while (key != "exit");

    DeleteDictionary(root);
    DeleteDictionary(root2);
    cout << endl;
    return 0;
}



