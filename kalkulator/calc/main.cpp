#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;
int main()
{
    float x;
    float y;
    char pt;
    double wynik;
    cout <<                                            "Kalkulator" << endl;
    cout << " + dodawanie\n - odejmowanie \n * mnozenie \n / dzielenie\n ^ potegowanie\n % pierwiastkowanie" << endl;
    cout << "Podaj wartosc x" << endl;
    cin >> x;
    cout << "Podaj co chcesz zrobic" <<endl;
    cin >> pt;
    cout << "Podaj wartosc y" << endl;
    cin >> y;
    if (pt == '+') {
         wynik = x + y;
    }
    if (pt == '-') {
         wynik = x - y;
    }
    if (pt == '*') {
         wynik = x * y;
    }
    if (pt == '/'){
         wynik = x / y;
    }
    if (pt == '^'){
        wynik = pow(x,y);
    }
    if (pt == '%'){
        wynik = pow( x,( 1 / y ) );
    }
    cout << "Wynik = " << wynik;
    getch();
}



