#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    HANDLE bOut;
    bOut = GetStdHandle(STD_OUTPUT_HANDLE);




    SetConsoleTextAttribute(bOut, FOREGROUND_BLUE);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_RED);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_GREEN);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_RED);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_GREEN);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_GREEN | FOREGROUND_RED);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Hello World" << endl;




    SetConsoleTextAttribute(bOut, BACKGROUND_BLUE);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_RED);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_GREEN);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_RED | BACKGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_BLUE | BACKGROUND_RED);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_BLUE | BACKGROUND_GREEN);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_GREEN | BACKGROUND_RED);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    cout << "Hello World" << endl;
    SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    cout << "Hello World" << endl;
    int x;
    int y;
    SetConsoleTextAttribute(bOut, BACKGROUND_BLUE | BACKGROUND_GREEN |BACKGROUND_RED | BACKGROUND_INTENSITY);
    cout << "  ";
    system("pause");


    return 0;
}
