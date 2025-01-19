#pragma once
#include <iostream>

class Data {
private:
    int dzien;
    char* miesiac;
    int rok;

public:
    // Gettery
    int zDzien() const;
    char* zMiesiac() const;
    int zRok() const;

    // Settery
    void uDzien(int d);
    void uMiesiac(const char* m);
    void uRok(int r);

    // Metody
    void Wpisz();
    void Wypisz() const;

    // Konstruktor i destruktor
    Data(int d = 1, const char* m = "styczen", int r = 2000);
    ~Data();
    Data& operator=(const Data& obiekt);

    // Operatory
    friend std::ostream& operator<<(std::ostream& ekran, const Data& obiekt);
    friend std::istream& operator>>(std::istream& klawiatura, Data& obiekt);
};
