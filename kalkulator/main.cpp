#include <iostream>

using namespace std;

int main()
{
    int x;
    int y;
    char pt;
    float wynik;
    float resz;
    cout << "Kalkulator" << endl;
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
    if (pt == '/') {
         resz  = x % y;
         wynik = x / y;
                   }
    cout << "Wynik = " << wynik;
    if (pt =='/') {
    cout << "." << resz;
                  }
   // return 0;
}


