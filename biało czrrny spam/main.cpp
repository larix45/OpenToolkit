#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
   HANDLE bout;
   bout = GetStdHandle(STD_OUTPUT_HANDLE);
   int a;
    for(a=0;a<2244;a++)
    {
       SetConsoleTextAttribute(bout,BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED);
       cout << " ";


       SetConsoleTextAttribute(bout,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
       cout << " ";

    }

}
