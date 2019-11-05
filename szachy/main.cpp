#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE bOut;
    int x,y,i;
    i = 9;
    bOut = GetStdHandle(STD_OUTPUT_HANDLE);
     cout << "[]a b c d e f g h [] " << endl;
    for (x=1; x<5 ; x++)
        {
            i--;
            cout<< i << " ";
            for (y=1;y<9;y++)
            {

                if(y % 2  == 0) {

                                SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
                                } else {
                                       SetConsoleTextAttribute(bOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
                                       }

                cout << "  ";
            }
        cout << " " << i<< endl;
        i--;
        cout<< i << " ";
        for (y=1;y<9;y++)
        {


            if (y % 2  == 1)
                {
                SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
                } else {
                       SetConsoleTextAttribute(bOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
                       }

            cout << "  ";
        }
        SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        cout << " " << i<< endl;
        }
    cout << "[]a b c d e f g h []";
    return 23;
}
