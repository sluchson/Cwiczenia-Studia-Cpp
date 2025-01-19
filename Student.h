#pragma once
#include "Osoba.h"
class Student : public Osoba{
private:
	char* kierunek;
public:
	char* zKierunek();
	void uKierunek(const char* k);
	Student(const char* imie = " ", const char* nazwisko = " ", 
		const Data& data = Data(8,"styczen",2025), const char* pesel = " ", 
		const char* kierunek = " ");
	~Student();
	Student(Student& student);
	void wpisz();
	void wypisz();
};

