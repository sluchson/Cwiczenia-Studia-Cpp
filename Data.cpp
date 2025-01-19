#include "Data.h"
#include <cstring>
#include <iostream>

using namespace std;

// Gettery
int Data::zDzien() const { return dzien; }
char* Data::zMiesiac() const { return miesiac; }
int Data::zRok() const { return rok; }

// Settery
void Data::uDzien(int d) {
    dzien = d;
}

void Data::uMiesiac(const char* m) {
    delete[] miesiac; // Zwolnij star¹ pamiêæ
    miesiac = new char[strlen(m) + 1];
    strcpy_s(miesiac, strlen(m) + 1, m);
}

void Data::uRok(int r) {
    rok = r;
}

// Metoda Wpisz
void Data::Wpisz() {
    cout << "Podaj dzien: ";
    cin >> dzien;
    cin.ignore();

    cout << "Podaj miesiac: ";
    char temp[50];
    cin.getline(temp, 50);
    uMiesiac(temp);

    cout << "Podaj rok: ";
    cin >> rok;
}

// Metoda Wypisz
void Data::Wypisz() const {
    cout << dzien << " " << miesiac << " " << rok << endl;
}

// Konstruktor
Data::Data(int d, const char* m, int r) {
    dzien = d;
    rok = r;
    miesiac = new char[strlen(m) + 1];
    strcpy_s(miesiac, strlen(m) + 1, m); // Kopiowanie nazwy miesi¹ca
}

// Destruktor
Data::~Data() {
    delete[] miesiac;
}


// Operator przypisania
Data& Data::operator=(const Data& obiekt) {
    if (this == &obiekt)
        return *this; // Zabezpieczenie przed samoprzypisaniem

    delete[] miesiac; // Zwolnij star¹ pamiêæ
    miesiac = new char[strlen(obiekt.miesiac) + 1];
    strcpy_s(miesiac, strlen(obiekt.miesiac) + 1, obiekt.miesiac);

    dzien = obiekt.dzien;
    rok = obiekt.rok;

    return *this;
}


// Operator <<
ostream& operator<<(ostream& ekran, const Data& obiekt) {
    ekran << obiekt.dzien << " " << obiekt.miesiac << " " << obiekt.rok;
    return ekran;
}

// Operator >>
istream& operator>>(istream& klawiatura, Data& obiekt) {
    cout << "Podaj dzien: ";
    klawiatura >> obiekt.dzien;
    klawiatura.ignore();

    cout << "Podaj miesiac: ";
    char temp[50];
    klawiatura.getline(temp, 50);
    obiekt.uMiesiac(temp);

    cout << "Podaj rok: ";
    klawiatura >> obiekt.rok;

    return klawiatura;
}
