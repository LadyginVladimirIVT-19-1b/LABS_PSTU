#include "Object.h"
#include "People.h"
#include "Abiturient.h"
#include "Person.h"
#include "Event.h"



//����������
Person::~Person(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}


//����������� � �����������
Person::Person(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}


//���������� �������, �� ������� ��������� ��������� p � Person
void Person::Add()
{
	Object* p;
	//����� �� �������� ���� ��������� �������
	cout << "1.People" << endl;
	cout << "2.Abiturient" << endl;
	int y;
	cin >> y;
	if (y == 1)//���������� ������� ������ People
	{
		People* a = new (People);
		a->Input();//���� �������� ���������
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//���������� � Person
			cur++;
		}
	}
	else
	{
		if (y == 2) //���������� ������� ������ Abiturient
		{
			Abiturient* b = new Abiturient;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}

		else return;
	}
}


//�������� Person
void Person::Show()
{
	if (cur == 0) cout << "Empty" << endl << endl;
	Object** p = beg;//��������� �� ��������� ���� Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//����� ������ Show() (������� ����������)
		p++;//����������� ��������� �� ��������� ������
	}
}



//��������, ������� ���������� ������ Person
int Person::operator ()()
{
	return cur;
}


//�������� �������� �� Person, ������ �� �������������!
void Person::Del()
{
	if (cur == 0)return;//������
	cur--;
}



void Person::HandleEvent(const TEvent& e)
{
	if (cur == 0)
	{
		cout << "Empty" << endl << endl;
	}
	else
	{
		if (e.what == evMessage)
		{
			Object** p = beg;
			for (int i = 0; i < cur; i++)
			{
				(*p)->HandleEvent(e);//����� ������ (������� ����������)
				p++;//����������� ��������� �� ��������� ������				
			}
			p = beg;
			(*p)->average_age(e);//����� ������ (������� ����������)
		}
	}
}

