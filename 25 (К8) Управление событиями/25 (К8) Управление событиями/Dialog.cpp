#include "Dialog.h"
#include "Event.h"

//конструктор
Dialog::Dialog(void) :Person(0)
{
	EndState = 0;
}


//деструктор
Dialog::~Dialog(void)
{
}


//получение события
void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "m+-szq"; //строка содержит коды операций
	string s;
	string param;
	char code;
	cout << "Возможные команды:  m+-szq" << endl << "m - создать группу(не создашь группу не сможешь взаимодействовать с людьми)"
		<< endl << "+ - добавать человека в группу" << endl << "-  - удалить человека из группы" << endl
		<< "s - вывести всех людей группы" << endl << "z - срединий возраст по группе" << endl
		<< "q - окончание программы" << endl << "Введите что будем делать" << endl << '>';
	cin >> s; code = s[0];//первый символ команды
	if (OpInt.find(code) >= 0)//является ли символ кодом операции
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm':event.command = cmMake; break;//создать группу
		case '+': event.command = cmAdd; break;//добавить объект в группу
		case '-': event.command = cmDel; break;//удалить объект из группы
		case 's': event.command = cmShow; break;//просмотр группы
		case'z': event.command = cmGet; break; //конец работы
		case'q': event.command = cmQuit; break; //конец работы		
		}
		//выделяем параметры команды, если они есть
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);

			int A = atoi(param.c_str());//преобразуем парметр в число
			event.a = A;//записываем в сообщение
		}
	}
	else event.what = evNothing;//пустое событие
}
int Dialog::Execute()
{
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event); //получить событие
		HandleEvent(event); //обработать событие
	} while (!Valid());
	return EndState;
}
int Dialog::Valid()
{
	if (EndState == 0) return 0;
	else return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;//пустое событие
}


void Dialog::EndExec()
{
	EndState = 1;
}


//обработчик событий
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake://создание группы
			cout << "Вы создали группу" << endl << endl;
			size = 10; //размер группы
			beg = new Object * [size];//выделяем память под массив указателей
			cur = 0; //текущая позиция
			ClearEvent(event);//очищаем событие
			break;
		case cmAdd://добавление
			cout << "Кого добавим в группу" << endl << endl;
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			cout << "Удалили последнего человека добовленного в группу" << endl << endl;
			Del(); //удаление
			ClearEvent(event);
			break;
		case cmShow:
			cout << "На данный момент имеется такая группа" << endl << endl;
			Show(); //просмотр
			ClearEvent(event);
			break;
		case cmQuit:
			cout << "Вы решили закончить с программой" << endl << endl;
			EndExec(); //выход
			ClearEvent(event);
			break;
		case cmGet:	// средний возраст людей
			cout << "Возраст всех людей" << endl << endl;
			Person::HandleEvent(event);
			ClearEvent(event);
			break;
		default:
			cout << "Такого события нет" << endl << endl;
		};
	}
}