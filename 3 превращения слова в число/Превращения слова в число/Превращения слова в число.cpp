// Превращения слова в число.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Дано слово из восьми букв необходимо упоковать в число вида long long int  и вывести на экран

#include <iostream>
using namespace std;

int main()
{
	int n;
	char* ptn = (char*)&n;
	for (int i = 0; i < 4; i++)
	{
		cin >> *(ptn + i);
	}
	cout << n<<endl;;
}
