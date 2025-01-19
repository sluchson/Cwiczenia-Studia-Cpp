#include "Data.h"
#include "Osoba.h"
#include "Student.h"
#include <iostream>

using namespace std;

int main() {
    /*Data pierwsza;
    Data* druga = new Data();

    pierwsza.uDzien(2);
    pierwsza.uMiesiac("luty");
    pierwsza.uRok(2002);
    pierwsza.Wypisz();
    pierwsza.Wpisz();
    pierwsza.Wypisz();

    druga->uDzien(3);
    druga->uMiesiac("marzec");
    druga->uRok(2003);
    druga->Wypisz();
    druga->Wpisz();
    druga->Wypisz();
    delete druga;*/



    /*Data data1(11, "listopad", 1111);  // Stw�rz poprawny obiekt Data
    Data data2(22, "luty", 2222);

    // Tworzenie obiekt�w Osoba
    Osoba osoba("Maciej", "Pere�lucha", data1, "10101010101");
    Osoba* druga = new Osoba("Mateusz", "Pokrywka", data2, "20202020202");

    // Statyczne dodanie osoby
    Data data3(5, "maj", 1995);
    static Osoba trzy("Anna", "Kowalska", data3, "30303030303");

    // Wy�wietlanie informacji
    osoba.Wypisz();
    druga->Wypisz();
    trzy.Wypisz();

    // Modyfikowanie danych
    osoba.Wpisz();
    osoba.Wypisz();

    druga->Wpisz();
    druga->Wypisz();

    trzy.Wpisz();
    trzy.Wypisz();

    delete druga; // Zwolnienie dynamiczni alokowanej pami�ci*/

    /*
    Data data1(11, "listopad", 1111);
    Data data2;

    cout << "Wprowadz nowa date: " << endl;
    cin >> data2;
    cout << "Wprowadzona data: " << data2 << endl;

    Osoba osoba1("Jan", "Kowalski", data1, "12345678901");
    cout << osoba1;

    cout << "Wprowadz dane nowej osoby:" << endl;
    Osoba osoba2("Placeholder", "Placeholder", data1, "00000000000");
    cin >> osoba2;
    cout << "Wprowadzona osoba: " << osoba2 << endl;*/


    // Tworzenie obiektu Student
    Student* student = new Student("Anna", "Nowak", Data(15, "grudzien", 2000), "12345678901", "Informatyka");

    // Wy�wietlenie danych studenta
    cout << "Dane studenta po inicjalizacji:" << endl;
    student->wypisz();

    // Modyfikowanie danych studenta za pomoc� metody wpisz()
    cout << "\nWprowadz nowe dane dla studenta:" << endl;
    student->wpisz();

    // Wy�wietlenie zmodyfikowanych danych studenta
    cout << "\nDane studenta po modyfikacji:" << endl;
    student->wypisz();

    // Usuni�cie dynamicznie alokowanego obiektu
    delete student;

    return 0;
}
