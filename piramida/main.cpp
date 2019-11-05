#include <iostream>
#include <windows.h>
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
    int i,q,a,m,n,k,z;
    HANDLE out;
    out = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Podaj dlugosc podstawy:";
    cin >> q;
    n = q % 2;
    m = q / 2;
    a = m + n;
    cout << n << "   "  << m ;
    for(i=1;i<a+1;i++)
    {
        Sleep(500);
        for (k=0;k<i;k++)
        {
            if ( n == 0 )
           {
                  SetConsoleTextAttribute(out,BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
                  setCursor(i+2,q+2-i*2+k*4);
                  cout << "    ";
           }
           if ( n == 1 )
           {

                SetConsoleTextAttribute(out,BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
                setCursor(i+2,q+2-i*2+k*2);
                cout << "  ";
                z=k+1;
                if (z>1)
                {
                    while(z>1)
                    {
                        cout << "  ";
                        z--;
                    }
                }
           }

        }
    }
    return 0;
}
