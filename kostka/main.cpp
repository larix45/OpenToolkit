#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>

static const int LICZBA_SCIAN = 6;


HANDLE bOut = GetStdHandle(STD_OUTPUT_HANDLE);
int liczba_rzutow = 0;
int rand_kolor = 0;
std::vector<int> liczba_oczek;
class Kostka
{
    short oczko = 0;
    int liczba_scian = 0;
public:
    Kostka(int liczbaScian)
    {
        liczba_scian = liczbaScian;
        for(size_t i = 0; i < liczbaScian+1; i++)
            liczba_oczek.push_back(0);
    }
    void rzucKostka()
    {
        liczba_rzutow++;
        oczko = rand()%liczba_scian+1;
    }
    int wynikRzutu()
    {
        return oczko;
    }
    int liczbaScian()
    {
        return liczba_scian;
    }
};
int main()
{
    srand(GetTickCount());
    rand_kolor = rand();
    Kostka k1(LICZBA_SCIAN);
    int input_1;
    SetConsoleTextAttribute(bOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    std::cout << "Podaj liczbe rzutow: ";
    std::cin >> input_1;
    for(size_t i = 1; i < input_1+1; i++)
    {
        k1.rzucKostka();
        SetConsoleTextAttribute(bOut, (k1.wynikRzutu() + rand_kolor) % 7 + 2);
        std::cout << "Rzut: "<< i << "    Wyrzucono: " << k1.wynikRzutu() << ".\n";
        liczba_oczek.at(k1.wynikRzutu()) += 1;
    }
    SetConsoleTextAttribute(bOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << char(201)<< char(205)<< char(187) << std::endl;

    for(size_t i = 1; i < k1.liczbaScian()+1; i++)
    {

        SetConsoleTextAttribute(bOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        std::cout << char(186);
        SetConsoleTextAttribute(bOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        std::cout << i;
        SetConsoleTextAttribute(bOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        std::cout << char(186);
        SetConsoleTextAttribute(bOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        std::cout << " wylosowano " << liczba_oczek.at(i);
        if(liczba_oczek.at(i) == 1)
            std::cout << " raz.";
        else
            std::cout << " razy.";
        SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "\( " <<  double(liczba_oczek.at(i)) * 100 / liczba_rzutow << " % \) \n";
    }
    SetConsoleTextAttribute(bOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << char(200)<< char(205)<< char(188) << std::endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    system("PAUSE");
    return 0;
}
