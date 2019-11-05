#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>
#include <fstream>


/*
0  --- NIC         [ ]
1 ----- JEDZENIE   [$]
2 ----- JEDZENIEx3 [&]


1 ------ GLOWA WEZA[@]
2------- CIALO WEZA[#]


*/
/*
SNAKE COLOR            [   white   ]
BACKGROUND COLOR       [   blue    ]





*change by pressing space
*/
/**
TRYBY:
    1 ---------- NORMALNY
    2 ----------- ENDLESS
    3 --- MIEDZY SCIANAMI
    4 -------------- HARD




**/

struct position {
    int x;
    int y;
    short type;
public:
    position (int vx, int vy, short vtype)
    {
        x = vx;
        y = vy;
        type = vtype;
    }
};

std::vector<position> entities;
std::fstream file;
static short plx = 100;
static short ply = 30;


short win = 0;
short tryb;




char input = '/';
char last_input = input;
size_t food_count;
size_t special_food_count;
size_t walls_count;
enum TColor{
    BLACK             = 0,
    DARKBLUE          = FOREGROUND_BLUE,
    DARKGREEN         = FOREGROUND_GREEN,
    DARKCYAN          = FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARKRED           = FOREGROUND_RED,
    DARKMAGENTA       = FOREGROUND_RED | FOREGROUND_BLUE,
    DARKYELLOW        = FOREGROUND_RED | FOREGROUND_GREEN,
    DARKGRAY          = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    GRAY              = FOREGROUND_INTENSITY,
    BLUE              = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    GREEN             = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    CYAN              = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED               = FOREGROUND_INTENSITY | FOREGROUND_RED,
    MAGENTA           = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW            = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE             = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    BDARKBLUE          = BACKGROUND_BLUE,
    BDARKGREEN         = BACKGROUND_GREEN,
    BDARKCYAN          = BACKGROUND_GREEN | BACKGROUND_BLUE,
    BDARKRED           = BACKGROUND_RED,
    BDARKMAGENTA       = BACKGROUND_RED | BACKGROUND_BLUE,
    BDARKYELLOW        = BACKGROUND_RED | BACKGROUND_GREEN,
    BDARKGRAY          = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    BGRAY              = BACKGROUND_INTENSITY,
    BBLUE              = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
    BGREEN             = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
    BCYAN              = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
    BRED               = BACKGROUND_INTENSITY | BACKGROUND_RED,
    BMAGENTA           = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
    BYELLOW            = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
    BWHITE             = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
  };

TColor background_color = BGREEN;
TColor snake_color = WHITE;
TColor walls_color = BWHITE;

void output(char c) {
    std::cout << c;
}
void gotoxy(int x, int y) {
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
void endgame(std::string s)
{
    system("cls");
    gotoxy(5,5);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 31);
    std::cout << "                                ";
    gotoxy(5,6);
    SetConsoleTextAttribute(hConsole, 31);
    std::cout << "           " << s <<"           ";
    gotoxy(5,7);
    SetConsoleTextAttribute(hConsole, 31);
    std::cout << "                                ";
    gotoxy(5,15);
}
void counter(int &score)
{
    int pos_x = 21;
    int pos_y = 5;
    gotoxy(pos_x,pos_y);
    char a = 201;
    char b = 205;
    std::cout << char(201) << char(205) << char(205) << char(205) << char(187);
    gotoxy(pos_x,pos_y+1);
    std::cout << char(186) << score;
    gotoxy(pos_x+4,pos_y+1);
    std::cout << char(186);
    gotoxy(pos_x,pos_y+2);
    std::cout << char(200) << char(205) << char(205) << char(205) << char(217);
}






class waz {
public:
    std::vector<position> body;

    void up()
    {
        int xxx = body.at(body.size()-1).x;
        int yyy = body.at(body.size()-1).y;
        for(size_t iterartor = 1; iterartor < body.size() ; iterartor++)
        {
            body.at(body.size()-iterartor).y = body.at(body.size()-iterartor-1).y;
            body.at(body.size()-iterartor).x = body.at(body.size()-iterartor-1).x;
        }
        body.at(0).y -= 1;
        if(body.size() > 1)
            last_input = 'w';
        gotoxy(xxx,yyy);
        std::cout << " ";
    }
    void down()
    {
        int xxx = body.at(body.size()-1).x;
        int yyy = body.at(body.size()-1).y;
        for(size_t iterartor = 1; iterartor < body.size() ; iterartor++)
        {
            body.at(body.size()-iterartor).y = body.at(body.size()-iterartor-1).y;
            body.at(body.size()-iterartor).x = body.at(body.size()-iterartor-1).x;
        }
        body.at(0).y += 1;
        if(body.size() > 1)
            last_input = 's';
        gotoxy(xxx,yyy);
        std::cout << " ";
    }
    void left()
    {
        int xxx = body.at(body.size()-1).x;
        int yyy = body.at(body.size()-1).y;
        for(size_t iterartor = 1; iterartor < body.size() ; iterartor++)
        {
            body.at(body.size()-iterartor).y = body.at(body.size()-iterartor-1).y;
            body.at(body.size()-iterartor).x = body.at(body.size()-iterartor-1).x;
        }
        body.at(0).x -= 1;
        if(body.size() > 1)
            last_input = 'a';
        gotoxy(xxx,yyy);
        std::cout << " ";

    }
    void right()
    {
        int xxx = body.at(body.size()-1).x;
        int yyy = body.at(body.size()-1).y;
        for(size_t iterartor = 1; iterartor < body.size() ; iterartor++)
        {
            body.at(body.size()-iterartor).y = body.at(body.size()-iterartor-1).y;
            body.at(body.size()-iterartor).x = body.at(body.size()-iterartor-1).x;
        }
        body.at(0).x += 1;
        if(body.size() > 1)
            last_input = 'd';
        gotoxy(xxx,yyy);
        std::cout << " ";
    }
    void check()
    {
        // SPRAWDZENIE CZY NIEZJADAM SAM SIEBIE
        {
            for(size_t iterartor = 1; iterartor < body.size() ; iterartor++)
                {
                    if(body.at(0).x == body.at(iterartor).x && body.at(0).y == body.at(iterartor).y)
                    {
                        endgame("  ENDGAME  ");
                        input = 'q';
                    }
                }
        }
        if(body.at(0).y < 0)
        {
            endgame(" ENDGAME  ");
            input = 'q';
        }
        if(body.at(0).x < 0)
        {
            endgame(" ENDGAME  ");
            input = 'q';
        }
        if(body.at(0).x >= plx)
        {
            endgame(" ENDGAME  ");
            input = 'q';
        }
        if(body.at(0).y >= ply)
        {
            endgame(" ENDGAME  ");
            input = 'q';
        }
        win = 0;


        for(size_t iterartor = 0; iterartor < entities.size(); iterartor++)
        {
            // CHECK FOR WIN


            if (entities.at(iterartor).type == 0)
            {
               win++;
            }


            if ((entities.at(iterartor).type == 1) && (entities.at(iterartor).x == body.at(0).x) && (entities.at(iterartor).y == body.at(0).y))
            {
                body.push_back(position(body.at(0).x,body.at(0).y,2));
                entities.at(iterartor).type = 0;
                if(tryb == 2)
                {
                    entities.push_back(position((rand()%plx),(rand()%ply),rand()%2+1));
                }
            }
            if ((entities.at(iterartor).type == 2) && (entities.at(iterartor).x == body.at(0).x) && (entities.at(iterartor).y == body.at(0).y))
            {
                body.push_back(position(body.at(0).x,body.at(0).y,2));
                body.push_back(position(body.at(0).x,body.at(0).y,2));
                body.push_back(position(body.at(0).x,body.at(0).y,2));
                entities.at(iterartor).type = 0;
                if(tryb == 2)
                {
                    entities.push_back(position((rand()%plx),(rand()%ply),rand()%2+1));
                }
             }
             if ((entities.at(iterartor).type == 3) && (entities.at(iterartor).x == body.at(0).x) && (entities.at(iterartor).y == body.at(0).y))
             {
                endgame(" ENDGAME ");
                input = 'q';
             }
        }
        if(tryb == 1 && win >= food_count + special_food_count)
        {
            endgame(" WIN!!! ");
            input = 'q';
        } else if(tryb == 2)
        {
            int pos_x = plx;
            int pos_y = ply/2;
            gotoxy(pos_x,pos_y);
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, snake_color | background_color);
            char a = 201;
            char b = 205;
            std::cout << char(201) << char(205) << char(205) << char(205) << char(187);
            gotoxy(pos_x,pos_y+1);
            std::cout << char(186) << win;
            gotoxy(pos_x+4,pos_y+1);
            std::cout << char(186);
            gotoxy(pos_x,pos_y+2);
            std::cout << char(200) << char(205) << char(205) << char(205) << char(217);
        }
    }
};



//INITIALIZE
    waz snake;

short settings()
{
    char menu_input = '/';
    bool choose = false;
    while(!choose)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 31);
        system("cls");
        gotoxy(5,5);
        SetConsoleTextAttribute(hConsole, 31);
        std::cout << "                                ";

        gotoxy(5,6);
        SetConsoleTextAttribute(hConsole, 32);
        std::cout << "1 - Save game                   ";

        gotoxy(5,7);
        SetConsoleTextAttribute(hConsole, 53);
        std::cout << "2 - Read save                   ";

        gotoxy(5,8);
        SetConsoleTextAttribute(hConsole, 74);
        std::cout << "3 - Restart game                ";

        gotoxy(5,9);
        SetConsoleTextAttribute(hConsole, 89);
        std::cout << "4 - Change color                ";


        gotoxy(5,10);
        SetConsoleTextAttribute(hConsole, 105);
        std::cout << "q - quit                        ";

        gotoxy(5,15);
        menu_input = getch();
        if(menu_input == '1')
        {
            file.open("razdat.png", std::ios::in | std::ios::out);
            if(file.good())
            {
                for(size_t iterartor = 0; iterartor < snake.body.size() ; iterartor++)
                {
                    file << snake.body.at(iterartor).x << std::endl;
                    file << snake.body.at(iterartor).y << std::endl;
                    file << snake.body.at(iterartor).type << std::endl;
                }
                std::cout << "SAVED!" << std::endl;
            }   else {
            std::cout << "ERROR!" << std::endl;
            }
            file.close();


            file.open("fazt.png", std::ios::in | std::ios::out);
            if(file.good())
            {
                for(size_t iterartor = 0; iterartor < entities.size() ; iterartor++)
                {
                    file << entities.at(iterartor).x << std::endl;
                    file << entities.at(iterartor).y << std::endl;
                    file << entities.at(iterartor).type << std::endl;
                }
                std::cout << "SAVED!" << std::endl;
            } else {
            std::cout << "ERROR!" << std::endl;
            }
            file.close();
            system("PAUSE");
            choose = true;

        }
        if(menu_input == '2')
        {
            file.open("razdat.png", std::ios::in | std::ios::out);
            if(file.good())
            {
                snake.body.clear();
                position bufor(0,0,0);
                while(!file.eof())
                {
                    file >> bufor.x;      //X
                    file >> bufor.y;      //Y
                    file >> bufor.type;   //TYPE
                    snake.body.push_back(bufor);
                }
                std::cout << "READ!" << std::endl;
            } else
            {
                std::cout << "ERROR!" << std::endl;
            }
            file.close();
            file.open("fazt.png", std::ios::in | std::ios::out);
            if(file.good())
            {
                entities.clear();
                position bufor(0,0,0);
                while(!file.eof())
                {
                    file >> bufor.x;      //X
                    file >> bufor.y;      //Y
                    file >> bufor.type;   //TYPE
                    entities.push_back(bufor);
                }
                std::cout << "READ!" << std::endl;
            } else
            {
                std::cout << "ERROR!" << std::endl;
            }
            file.close();
            system("PAUSE");
            choose = true;

        }
        if(menu_input == '3')
        {

            choose = true;
            return 24;
        }
        if(menu_input == '4')
        {
            SetConsoleTextAttribute(hConsole, 31);
            system("cls");
            gotoxy(5,5);
            SetConsoleTextAttribute(hConsole, 31);
            std::cout << "                                ";

            gotoxy(5,6);
            SetConsoleTextAttribute(hConsole, 32);
            std::cout << "1 ----- SNAKE COLOR          ["<< snake_color <<"] ";

            gotoxy(5,7);
            SetConsoleTextAttribute(hConsole, 53);
            std::cout << "2 ----- BACKGROUND COLOR     ["<< background_color <<"] ";

            gotoxy(5,8);
            SetConsoleTextAttribute(hConsole, 74);
            std::cout << "3 ------ WALLS COLOR          ["<< walls_color <<"] ";
            char nmenu_input = '/';
            bool nchoose = false;
            while(!nchoose)
            {
                nmenu_input = getch();
                if(nmenu_input == '1')
                {
                    SetConsoleTextAttribute(hConsole, 31);
                    system("cls");
                    gotoxy(5,5);
                    SetConsoleTextAttribute(hConsole, 32);
                    std::cout << "b = black; g = gray; G = green; r = red; B = blue";

                    gotoxy(5,6);
                    SetConsoleTextAttribute(hConsole, 35);
                    std::cout << "w = white; m = magenta; y = yellow; c = cyan";


                    char nnmenu_input = '/';
                    bool nnchoose = false;
                    while(!nnchoose)
                    {
                        nnmenu_input = getch();
                        if(nnmenu_input == 'r')
                        {
                            nnchoose = true;
                            snake_color = RED;
                        }
                        switch(nnmenu_input)
                        {
                        case 'b':
                            nnchoose = true;
                            snake_color = BLACK;
                            break;
                        case 'g':
                            nnchoose = true;
                            snake_color = GRAY;
                            break;
                        case 'G':
                            nnchoose = true;
                            snake_color = GREEN;
                            break;
                        case 'r':
                            nnchoose = true;
                            snake_color = RED;
                            break;
                        case 'B':
                            nnchoose = true;
                            snake_color = BLUE;
                            break;
                        case 'w':
                            nnchoose = true;
                            snake_color = WHITE;
                            break;
                        case 'm':
                            nnchoose = true;
                            snake_color = MAGENTA;
                            break;
                        case 'y':
                            nnchoose = true;
                            snake_color = YELLOW;
                            break;
                        case 'c':
                            nnchoose = true;
                            snake_color = CYAN;
                            break;
                        }
                    }
                    if(nmenu_input == '2')
                    {
                        nchoose = true;
                    }
                    if(nmenu_input == '3')
                    {
                        nchoose = true;
                    }
                    if(nmenu_input == 'q')
                    {
                        nchoose = true;
                    }
                }
            }


                choose = true;
            }
        if(menu_input == 'q')
        {
            choose = true;
            input = '/';
            SetConsoleTextAttribute(hConsole, background_color | snake_color);
            // CZYSZCZENIE EKRANU
            system("cls");
            // RYSOWANIE RAMKI
            for(short i=0; i < plx; i++)
            {
                gotoxy(i,ply);
                std::cout << char(205);
            }
            for(short i=0; i < ply; i++)
            {
                gotoxy(plx,i);
                std::cout << char(186);
            }
            gotoxy(plx, ply);
            std::cout << char(188);
                return 0;
            }
    }
}



int main()
{
    restart:
        input = '/';
        snake.body.clear();
        entities.clear();


    // START MENU
    {
        system("cls");
        gotoxy(5,5);
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 31);
        std::cout << "                                ";
        gotoxy(5,6);
        SetConsoleTextAttribute(hConsole, 31);
        std::cout << "     " << "Press 'w' to strat... "<<"     ";
        gotoxy(5,7);
        SetConsoleTextAttribute(hConsole, 31);
        std::cout << "                                ";
        gotoxy(5,15);
        getch();
    }

    Sleep(100);
    char menu_input = '/';
    bool choose = false;
    while(!choose)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 31);
        system("cls");
        gotoxy(5,5);
        SetConsoleTextAttribute(hConsole, 31);
        std::cout << "                                ";

        gotoxy(5,6);
        SetConsoleTextAttribute(hConsole, 32);
        std::cout << "1 - level mode                  ";

        gotoxy(5,7);
        SetConsoleTextAttribute(hConsole, 53);
        std::cout << "2 - endless mode                ";

        gotoxy(5,8);
        SetConsoleTextAttribute(hConsole, 74);
        std::cout << "3 - walls mode                  ";

        gotoxy(5,9);
        SetConsoleTextAttribute(hConsole, 105);
        std::cout << "q - quit                        ";

        gotoxy(5,15);
        menu_input = getch();
        if(menu_input == '1')
        {
            choose = true;
            tryb = 1;
        }
        if(menu_input == '2')
        {
            choose = true;
            tryb = 2;
        }
        if(menu_input == '3')
        {
            choose = true;
            tryb = 3;
        }
        if(menu_input == 'q')
        {
            choose = true;
            return 0;
        }
    }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, background_color | snake_color);

    //INITIALIZE
    snake.body.push_back(position(5,5,1));


    // LOSOWANIE
    if (tryb == 1)
    {
        food_count = 10;
        special_food_count = 3;
        ///entities.push_back(position(x,y,type));
        srand(time(NULL));
        for (size_t i = 0; i < food_count; i++)
        {
            entities.push_back(position((rand()%plx),(rand()%ply),1));
        }
        for (size_t i = 0; i < special_food_count; i++)
        {
            entities.push_back(position((rand()%plx),(rand()%ply),2));
        }
    }else if(tryb == 2)
            entities.push_back(position((rand()%plx),(rand()%ply),rand()%1+1));
     else if(tryb == 3)
     {
        food_count = 10;
        special_food_count = 3;
        walls_count = 18;

        srand(time(NULL));
        for (size_t i = 0; i < food_count; i++)
        {
            entities.push_back(position((rand()%plx),(rand()%ply),1));
        }
        for (size_t i = 0; i < special_food_count; i++)
        {
            entities.push_back(position((rand()%plx),(rand()%ply),2));
        }
        for (size_t i = 0; i < walls_count; i++)
        {
            entities.push_back(position((rand()%plx),(rand()%ply),3));
        }
     }





    // CZYSZCZENIE EKRANU
    system("cls");
    // RYSOWANIE RAMKI
    for(short i=0; i < plx; i++)
        {
            gotoxy(i,ply);
            std::cout << char(205);
        }
        for(short i=0; i < ply; i++)
        {
            gotoxy(plx,i);
            std::cout << char(186);
        }
        gotoxy(plx, ply);
        std::cout << char(188);
    //gra
    while(input != 'q')
    {

        Sleep(130);
        if(kbhit())
            input = getch();

        if (input == 'w' && last_input != 's')
            snake.up();
        if (input == 's' && last_input != 'w')
            snake.down();
        if (input == 'd' && last_input != 'a')
            snake.right();
        if (input == 'a' && last_input != 'd')
            snake.left();


        if (input == 'w' && last_input == 's')
            snake.down();
        if (input == 's' && last_input == 'w')
            snake.up();
        if (input == 'd' && last_input == 'a')
            snake.left();
        if (input == 'a' && last_input == 'd')
            snake.right();




        if (input == 27 && last_input != 27)
             if(settings() == 24)
                goto restart;



        // RYSOWANIE
        for(size_t iterartor = 0; iterartor < entities.size(); iterartor++)
        {
            if (entities.at(iterartor).type == 1)
            {
                gotoxy(entities.at(iterartor).x,entities.at(iterartor).y);
                output('$');

            }
            if (entities.at(iterartor).type == 2)
            {
                gotoxy(entities.at(iterartor).x,entities.at(iterartor).y);
                output('&');

            }
            if (tryb == 3 && entities.at(iterartor).type == 3)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, walls_color);
                gotoxy(entities.at(iterartor).x,entities.at(iterartor).y);
                std::cout << " ";
                SetConsoleTextAttribute(hConsole, background_color | snake_color);
            }
        }
        for(size_t iterartor = 0; iterartor < snake.body.size(); iterartor++)
        {
            if (snake.body.at(iterartor).type == 1)
            {
                gotoxy(snake.body.at(iterartor).x,snake.body.at(iterartor).y);
                output('@');

            }
             if (snake.body.at(iterartor).type == 2)
            {
                gotoxy(snake.body.at(iterartor).x,snake.body.at(iterartor).y);
                output('#');

            }
        }

        // SPRAWDZANIE
        snake.check();
    }







    return 0;
}
