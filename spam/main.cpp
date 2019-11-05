#include <iostream>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>

using namespace std;

void setCursor(int y, int x)
{
     COORD c;
     c.X = x-1;
     c.Y = y-1;
     SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}
int main()
{
    int i;
    int p;
    int l;
    char kk;
    int zn;
    char j;
    while (getch() != 27){
    for (i = 1; i < 301; i++)
    {
        for (p = 1; p < 121; p++)
        {

            setCursor(i,p);
            l=i+p;
            if (l > 255){
                l=l-254;
            }
            kk = (char)l;
            cout << kk;

        }
    }
        }
    zn = p * i;
    cout << "Liczba znakow:" << zn;
    cin >> kk;

}
