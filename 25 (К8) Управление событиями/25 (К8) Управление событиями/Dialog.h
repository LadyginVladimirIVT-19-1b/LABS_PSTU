#pragma once
#include <iostream>
#include "Object.h"
#include "People.h"
#include "Abiturient.h"
#include "Event.h"
#include "Person.h"
#include "Dialog.h"
using namespace std;


class Dialog :
	public Person
{
public:
	Dialog(void);//контруктор
	virtual ~Dialog(void);//деструктор

	virtual void GetEvent(TEvent& event);//получить событие
	virtual int Execute();//главный цикл обработки событий
	virtual void HandleEvent(TEvent& event); //обработчик
	virtual void ClearEvent(TEvent& event);//очистить событие

	int Valid();//проверка атрибута EndState
	void EndExec();//обработка события «конец работы»
protected:
	int EndState;
};
