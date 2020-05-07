#include "Abiturient.h"
#include "Event.h"


Abiturient::Abiturient(void) :People()
{
	points = 0;
	specialty = "";
}


Abiturient::~Abiturient(void)
{
}
Abiturient::Abiturient(int S, string P) :People()			
{
	points = S;
	specialty = P;
}


Abiturient::Abiturient(const Abiturient& L)
{
	Name = L.Name;
	Age = L.Age;
	points = L.points;
	specialty = L.specialty;
}


void Abiturient ::Set_points(int P)
{
	points = P;
}


void Abiturient :: Set_specialty(string S)
{
	specialty = S;
}


Abiturient& Abiturient::operator=(const Abiturient& l)
{
	if (&l == this)return *this;
	Name = l.Name;
	Age = l.Age;
	return *this;
}


void Abiturient::Show()
{
	cout << "\nName : " << Name;
	cout << "\nAge : " << Age;
	cout << "\nPoints : " << points;
	cout << "\nSpecialty : " << specialty;
	cout << endl << endl;
}


void Abiturient::Input()
{
	cout << "\nName:"; cin >> Name;
	cout << "\nAge:"; cin >> Age;
	cout << "\nPoints:"; cin >> points;
	cout << "\nSpecialty : "; cin >> specialty;
	cout << endl << endl;
}

