#include "Osoba.h"
#include <cstring>
#include <iostream>

using namespace std;

// Gettery
char* Osoba::zImie() const { return imie; }
char* Osoba::zNazwisko() const { return nazwisko; }
Data Osoba::zData() const { return dataUr; }
const char* Osoba::zPesel() const { return pesel; }

// Settery
void Osoba::uImie(const char* noweImie) {
    if (imie) delete[] imie; // Zwolnienie starej pamiêci
    imie = new char[strlen(noweImie) + 1];
    strcpy_s(imie, strlen(noweImie) + 1, noweImie);
}

void Osoba::uNazwisko(const char* noweNazwisko) {
    if (nazwisko) delete[] nazwisko; // Zwolnienie starej pamiêci
    nazwisko = new char[strlen(noweNazwisko) + 1];
    strcpy_s(nazwisko, strlen(noweNazwisko) + 1, noweNazwisko);
}

// Konstruktor
Osoba::Osoba(const char* imie, const char* nazwisko, const Data& data, const char* pes)
    : dataUr(data), pesel(pes) {
    this->imie = new char[strlen(imie) + 1];
    strcpy_s(this->imie, strlen(imie) + 1, imie);

    this->nazwisko = new char[strlen(nazwisko) + 1];
    strcpy_s(this->nazwisko, strlen(nazwisko) + 1, nazwisko);
}

// Konstruktor kopiuj¹cy
Osoba::Osoba(const Osoba& wzor)
    : dataUr(wzor.dataUr), pesel(wzor.pesel) {
    imie = new char[strlen(wzor.imie) + 1];
    strcpy_s(imie, strlen(wzor.imie) + 1, wzor.imie);

    nazwisko = new char[strlen(wzor.nazwisko) + 1];
    strcpy_s(nazwisko, strlen(wzor.nazwisko) + 1, wzor.nazwisko);
}

// Destruktor
Osoba::~Osoba() {
    delete[] imie;
    delete[] nazwisko;
}

// Metody
void Osoba::Wypisz() const {
    cout << "Imie: " << imie << endl
        << "Nazwisko: " << nazwisko << endl
        << "Pesel: " << pesel << endl;
    dataUr.Wypisz();
    cout << endl;
}

void Osoba::Wpisz() {
    char temp[30];

    cout << "Podaj imie: ";
    cin.getline(temp, 30);
    uImie(temp);

    cout << "Podaj nazwisko: ";
    cin.getline(temp, 30);
    uNazwisko(temp);

    // PESEL i data s¹ sta³e, wiêc nie mo¿na ich zmieniaæ w tej metodzie
    cout << "PESEL i data urodzenia sa stale i nie moga byc modyfikowane." << endl;
}

Osoba& Osoba::operator=(const Osoba& x) {
    if (this == &x)
        return *this;

    delete[] imie;
    delete[] nazwisko;

    imie = new char[strlen(x.imie) + 1];
    strcpy_s(imie, strlen(x.imie) + 1, x.imie);

    nazwisko = new char[strlen(x.nazwisko) + 1];
    strcpy_s(nazwisko, strlen(x.nazwisko) + 1, x.nazwisko);

    return *this;
}

// Operator <<
ostream& operator<<(ostream& ekran, const Osoba& x) {
    ekran << "Imie: " << x.imie << "\nNazwisko: " << x.nazwisko
        << "\nPesel: " << x.pesel << "\nData urodzenia: " << x.dataUr << endl;
    return ekran;
}

// Operator >>
istream& operator>>(istream& klawiatura, Osoba& x) {
    char temp[30];

    cout << "Podaj imie: ";
    klawiatura.ignore(); // Pomijamy znak nowej linii
    klawiatura.getline(temp, 30);
    x.uImie(temp);

    cout << "Podaj nazwisko: ";
    klawiatura.getline(temp, 30);
    x.uNazwisko(temp);

    // PESEL i data s¹ sta³e, wiêc nie mo¿na ich modyfikowaæ
    cout << "PESEL i data urodzenia sa stale i nie moga byc modyfikowane." << endl;

    return klawiatura;
}