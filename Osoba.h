#include <iostream>
#include "Data.h"
#pragma once

class Osoba {
private:
    char* imie;
    char* nazwisko;
    const Data dataUr;
    const char* pesel;

public:
    // Gettery
    char* zImie() const;
    char* zNazwisko() const;
    Data zData() const;
    const char* zPesel() const;

    // Settery
    void uImie(const char* imie);
    void uNazwisko(const char* nazwisko);

    // Konstruktor i destruktor
    Osoba(const char* imie, const char* nazwisko, const Data& data, const char* pesel);
    Osoba(const Osoba& wzor);
    ~Osoba();

    // Metody
    void Wypisz() const;
    void Wpisz();

    Osoba& operator=(const Osoba& x);

    // Operatory
    friend std::ostream& operator<<(std::ostream& ekran, const Osoba& x);
    friend std::istream& operator>>(std::istream& klawiatura, Osoba& x);
};
