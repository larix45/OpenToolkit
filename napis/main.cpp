#include <iostream>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
enum COLOR
{
    BLACK            = 0,
    BLUE             = 1,
    GREEN            = 2,
    AQUA             = 3,
    RED              = 4,
    PURPLE           = 5,
    YELLOW           = 6,
    WHITE            = 7,
    GRAY             = 8,
    LIGHT_BLUE       = 9,
    LIGHT_GREEN      = 10,
    LIGHT_AQUA       = 11,
    LIGHT_RED        = 12,
    LIGHT_PURPLE     = 13,
    LIGHT_YELLOW     = 14,
    LIGHT_WHITE      = 15,
};
void show(std::string text,
          unsigned int x = 0,
          unsigned int y = 0,
          int color = 7,
          int background_color = 0)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + background_color*16);
    gotoxy(x,y);
    std::cout << text;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE+BLACK*16);
}

int main()
{
    CONSOLE_SCREEN_BUFFER_INFO buf;
    unsigned int input_1, column, row;
    int color;

    input_1 = 9999999;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buf);
    for(size_t i = 0; i < input_1; i++)
    {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buf);
        if(!((buf.srWindow.Bottom - buf.srWindow.Top + 1)== 0))
        {
            column = rand()%(buf.srWindow.Right - buf.srWindow.Left + 1);
            row    = rand()%(buf.srWindow.Bottom - buf.srWindow.Top + 1);
            // /*
            if(row % 2 == 0)
                show(" ", column, row, RED+RED*16);
            if(column % 2 != 0)
                show(" ", column, row, BLUE+BLUE*16);

           // if(row % 2 == 0 && column % 2 != 0)
           //       show(" ", column, row, YELLOW+YELLOW*16);
            //  */
            /*
            color = rand()%256;
            if(column % 2 == 0)
                if(row % 2 != 0)
                    show(" ", column, row, color);
                else
                    show(" ", column, row, RED+RED*16);
            else if(row % 2 != 0)
                show(" ", column, row, BLUE+BLUE*16);
            else if(rand() % 5 == 0)
                show(" ", column, row, RED+RED*16);
            else
                show(" ", column, row, BLUE+BLUE*16);
             */
        }
    }
    gotoxy(0,(buf.srWindow.Bottom - buf.srWindow.Top + 2));

    /*
    CONSOLE_SCREEN_BUFFER_INFO buf;
    unsigned int input_1;

    if(argc == 1)
    {
        std::cin >> input_1;
        if(input_1 == 0)
            input_1 = 99999999;
    }
    else
        input_1 = 999999;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buf);
    for(size_t i = 0; i < input_1; i++)
    {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buf);
        if(!((buf.srWindow.Bottom - buf.srWindow.Top + 1)== 0))
            show(" ", rand()%(buf.srWindow.Right - buf.srWindow.Left + 1), rand()%(buf.srWindow.Bottom - buf.srWindow.Top + 1), rand()%256);
    }
    gotoxy(0,(buf.srWindow.Bottom - buf.srWindow.Top + 2));

    */
    system("PAUSE");
    return 0;
}
