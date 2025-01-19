#include "Student.h"
#include <iostream>

using namespace std;

char* Student::zKierunek() {
	return kierunek;
}

void Student::uKierunek(const char* k) {
	delete[] kierunek; // Zwolnij star¹ pamiêæ
	kierunek = new char[strlen(k) + 1];
	strcpy_s(kierunek, strlen(k) + 1, k); // Bezpieczne kopiowanie
}


Student::Student(const char* imie, const char* nazwisko, const Data& data, const char* pesel, const char* kierunek)
	: Osoba(imie, nazwisko, data, pesel), kierunek(nullptr) {
	uKierunek(kierunek);
}


Student::~Student() {
	delete[] kierunek;
}

Student::Student(Student& student): 
	Osoba(student.zImie(), student.zNazwisko(), student.zData(), student.zPesel())
{
	uKierunek(student.zKierunek());
}
void Student::wpisz() {
	Osoba::Wpisz();
	cout << "Podaj kierunek: ";
	char k[20];
	cin >> k;
	uKierunek(k);

}

void Student::wypisz() {
	Osoba::Wypisz();
	cout << "Kierunek: " << kierunek << endl;

}