#pragma once

#include <iostream>
#include "People.h"
#include "Abiturient.h"
#include "Event.h"
using namespace std;



class Abiturient :
	public People
{
public:
	Abiturient(void);
	~Abiturient(void);
	void Show();
	void Input();

	Abiturient(int, string);
	Abiturient(const Abiturient&);

	int Get_points() { return points; }
	string Get_specialty() { return specialty; }

	void Set_points(int);
	void Set_specialty(string);

	Abiturient& operator=(const Abiturient&);
protected:
	int points;
	string specialty;
};

