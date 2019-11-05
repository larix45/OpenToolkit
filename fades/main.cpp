#include <iostream>

using namespace std;

int main()
{
    int xmax=12;
    int tab[xmax];
    int x;
    for (x=0;x<xmax;x++)
    {
        cout << "Podaj " << x << " wartosc tablicy = ";
        cin >> tab[x];
    }
    for (x=0;x<xmax;x++)
    {
        cout << x <<". element tablicy tab to = " << tab[x] << endl;
    }
}
