#include <iostream>
#include <string>
#include <windows.h>
#undef __STRICT_ANSI__//BEZ TEGO NIE MOZNA BYLO UZYC "M_PI"
#include <math.h>
/**

Autor: Kamil Warczek
Klasa: 1C


Na poczatku nalezy wybrac nr zadania (1-4)

**/
int main()
{
    int i0;//WYBOR ZADAN NA POCZATKU
start:

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);//KOLOR
    std::cin >> i0;
    if(i0 == 1) //ZADANIE 1
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//KOLOR
        double i1, i2;
        std::cout << "Wprowadz pierwsza liczbe: ";
        std::cin >> i1;
        std::cout << "Wprowadz druga liczbe: ";
        std::cin >> i2;
        if(i1 == i2)
        {
            std::cout << "\nLiczby sa rowne!\n";
        }else if(i1 > i2)
        {

            std::cout << "\nLiczba 1 jest wieksza od 2\n";
        }else if(i1 < i2)
        {

            std::cout << "\nLiczba 2 jest wieksza od 1\n";
        }
    } else
    if(i0 == 2//ZADANIE 2
)    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);//KOLOR
        double i1;
        std::cout << "Wprowadz wartosc: ";
        std::cin >> i1;
        if(i1 == 0)
            std::cout << "rowna zero [BLAD]\n";
        if(i1 < 0)
        {
            i1 = i1-i1-i1;
            std::cout << "Podano wartosc ujemna. Jej wartosc bezwzgledna to: " << i1 << "\n";
        }
        std::cout << "Pole kola o promieniu " << i1 << " jest rowne " << M_PI * pow(i1,2) << char(46);
    } else
    if(i0 == 3) //ZADANIE 3
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//KOLOR
        unsigned short i1;
        int i2;
        bool passed = false;//SPRAWDZENIE POPRAWNOSCI DANYCH
        while(!passed)
        {
            std::cout << "Podaj ocene ucznia(1-6): ";
            std::cin >> i1;
            if(i1 < 7 && i1 > 0)
                passed = true;
            else
                std::cout << "PODAJ LICZBE Z PRZEDZIALU 1-6\n";
        }
        passed = false;//SPRAWDZENIE POPRAWNOSCI DANYCH
        while(!passed)
        {
            std::cout << "Podaj wynik ucznia z egzamiu w procentach: ";
            std::cin >> i2;
            if(i2 < 101 && i2 > -1)
                passed = true;
            else
                std::cout << "PODAJ LICZBE Z PRZEDZIALU 0-100\n";

        }
        if(i1 >= 5 || i2 >= 90)
            std::cout << "grupa zaawansowana";
        else
            std::cout << "grupa podstawowa";

    } else
    if(i0 == 4)//ZADANIE 4
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//KOLOR
        double h,r;
        std::cout << "Podaj promien podstawy walca: ";
        std::cin >> r;

        std::cout << "Podaj wysokosc walca: ";
        std::cin >> h;
        if(h < 0 || r < 0)
        {
            std::cout << "bledne dane\n";
            goto start;//POWROT NA START
        }
        double v = h * M_PI * pow(r,2);
        std::cout << "Objetosc walca jest rowna " << v;

    } else
    {
        std::cout << "wprowadz liczbe od 1 do 4 \n";
        goto start;//POWROT NA START
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);//KOLOR
    return 0;
}
