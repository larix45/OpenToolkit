#include <iostream>
#include <vector>
#include <windows.h>

CONSOLE_SCREEN_BUFFER_INFO csbi;

void setColor(int color = 0, int b_color = 15)//ustawianie koloru
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + b_color*15);
}

void gotoXY(int x, int y)
{
    COORD cor;
    cor.X = x;
    cor.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

enum FIGURE_SHAPE
{
    WHITE_KING,
    WHITE_QUEEN,
    WHITE_HORSE,
    WHITE_TOWER,
    WHITE_RUNNER,
    WHITE_SOLDIER,
    BLACK_KING,
    BLACK_QUEEN,
    BLACK_HORSE,
    BLACK_TOWER,
    BLACK_RUNNER,
    BLACK_SOLDIER,
    NONE
};
class Field
{
public:
    FIGURE_SHAPE character;
    bool isWhite;
    bool isKing;
    bool isQueen;
    bool isRunner;
    bool isHorse;
    bool isTower;
    bool isSoldier;
    char icon;
    Field(FIGURE_SHAPE type = NONE)
    {
        if(type == NONE)
        {
            isWhite    = false;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
            icon        = ' ';
        }
        if(type == BLACK_KING)
        {
            isWhite    = false;
            isKing      = true;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
            icon        = 'K';
        }
        if(type == BLACK_QUEEN)
        {
            isWhite    = false;
            isKing      = false;
            isQueen     = true;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
            icon        = 'Q';
        }
        if(type == BLACK_RUNNER)
        {
            isWhite    = false;
            isKing      = false;
            isQueen     = false;
            isRunner    = true;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
            icon        = 'R';
        }
        if(type == BLACK_HORSE)
        {
            isWhite    = false;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = true;
            isTower     = false;
            isSoldier   = false;
            icon        = 'H';
        }
        if(type == BLACK_TOWER)
        {
            isWhite    = false;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = true;
            isSoldier   = false;
            icon        = 'T';
        }
        if(type == BLACK_SOLDIER)
        {
            isWhite    = false;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = true;
            icon        = 'S';
        }
        if(type == WHITE_KING)
        {
            isWhite    = true;
            isKing      = true;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
            icon        = 'K';
        }
        if(type == WHITE_QUEEN)
        {
            isWhite     = true;
            isKing      = false;
            isQueen     = true;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
            icon        = 'Q';
        }
        if(type == WHITE_RUNNER)
        {
            isWhite    = true;
            isKing      = false;
            isQueen     = false;
            isRunner    = true;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
            icon        = 'R';
        }
        if(type == WHITE_HORSE)
        {
            isWhite    = true;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = true;
            isTower     = false;
            isSoldier   = false;
            icon        = 'H';
        }
        if(type == WHITE_TOWER)
        {
            isWhite    = true;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = true;
            isSoldier   = false;
            icon        = 'T';
        }
        if(type == WHITE_SOLDIER)
        {
            isWhite    = true;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = true;
            icon        = 'S';
        }
    }
};

struct PositionXY
{
    PositionXY(short pos_x, short pos_y)
    {
        x = pos_x;
        y = pos_y;
    }
    short x;
    short y;
};



class Board
{

public:

    Board()
    {

    }

    Field playboard[8][8];
    std::vector<FIGURE_SHAPE> beat_figures; // POKONANE FIGURY
    void defaultPositionOfFigures()
    {
        for(int i = 0; i < 8; i++)
            for(int j =0; i < 8; i++)
            {
                playboard[i][j] = Field(NONE);
            }

    //BIALE


         playboard[0][0] = Field(WHITE_TOWER);
         playboard[0][1] = Field(WHITE_RUNNER);
         playboard[0][2] = Field(WHITE_HORSE);
         playboard[0][3] = Field(WHITE_KING);
         playboard[0][4] = Field(WHITE_QUEEN);
         playboard[0][5] = Field(WHITE_HORSE);
         playboard[0][6] = Field(WHITE_RUNNER);
         playboard[0][7] = Field(WHITE_TOWER);
         playboard[1][0] = Field(WHITE_SOLDIER);
         playboard[1][1] = Field(WHITE_SOLDIER);
         playboard[1][2] = Field(WHITE_SOLDIER);
         playboard[1][3] = Field(WHITE_SOLDIER);
         playboard[1][4] = Field(WHITE_SOLDIER);
         playboard[1][5] = Field(WHITE_SOLDIER);
         playboard[1][6] = Field(WHITE_SOLDIER);
         playboard[1][7] = Field(WHITE_SOLDIER);

    //CZARNE
         playboard[7][0] = Field(BLACK_TOWER);
         playboard[7][1] = Field(BLACK_RUNNER);
         playboard[7][2] = Field(BLACK_HORSE);
         playboard[7][3] = Field(BLACK_KING);
         playboard[7][4] = Field(BLACK_QUEEN);
         playboard[7][5] = Field(BLACK_HORSE);
         playboard[7][6] = Field(BLACK_RUNNER);
         playboard[7][7] = Field(BLACK_TOWER);
         playboard[6][0] = Field(BLACK_SOLDIER);
         playboard[6][1] = Field(BLACK_SOLDIER);
         playboard[6][2] = Field(BLACK_SOLDIER);
         playboard[6][3] = Field(BLACK_SOLDIER);
         playboard[6][4] = Field(BLACK_SOLDIER);
         playboard[6][5] = Field(BLACK_SOLDIER);
         playboard[6][6] = Field(BLACK_SOLDIER);
         playboard[6][7] = Field(BLACK_SOLDIER);


    }
    void reset()
    {
        for(int i = 0; i < 8; i++)
            for(int j =0; i < 8; i++)
            {
                playboard[i][j] = Field(NONE);
            }
    }


    bool moveFigure(PositionXY from, PositionXY to) // FALSE = NIE MOZNA    TRUE = MOZNA
    {
        if(to.x < 8 && to.x > -1 && to.y < 8 && to.y > -1)//CZY MIESCI SIE W ZAKRESIE TABLICY
        {
            if(playboard[from.x][from.y].character != NONE)// CZY JEST TAM FIGURA
            {
                if(playboard[from.x][from.y].isWhite != playboard[to.x][to.y].isWhite)// CZY KOLORY FIGUR SA ROZNE
                {
                    if(playboard[from.x][from.y].isHorse)
                    {
                        if((from.x + 1 == to.x && from.y + 3 == to.y) ||
                                (from.x + 1 == to.x && from.y - 3 == to.y) ||
                                (from.x - 1 == to.x && from.y + 3 == to.y) ||
                                (from.x - 1 == to.x && from.y - 3 == to.y) ||
                                (from.x + 3 == to.x && from.y + 1 == to.y) ||
                                (from.x + 3 == to.x && from.y - 1 == to.y) ||
                                (from.x - 3 == to.x && from.y + 1 == to.y) ||
                                (from.x - 3 == to.x && from.y - 1 == to.y)
                          ) // CZY MOZNA SIE TAK RUSZYC KONIEM
                        {
                            if(playboard[to.x][to.y].character != NONE)
                            {
                                beat_figures.push_back(playboard[to.x][to.y].character);
                            }
                            playboard[to.x][to.y] = playboard[from.x][from.y];
                            playboard[from.x][from.y] = Field(NONE);
                            return true;
                        }
                        else
                            return false;
                    }
                    else if(playboard[from.x][from.y].isKing)
                    {
                        if((from.x - 1 == to.x && from.y + 1 == to.y) ||
                                (from.x - 1 == to.x && from.y  == to.y) ||
                                (from.x - 1 == to.x && from.y - 1 == to.y) ||
                                (from.x == to.x && from.y + 1 == to.y) ||
                                (from.x == to.x && from.y - 1 == to.y) ||
                                (from.x + 1 == to.x && from.y + 1 == to.y) ||
                                (from.x + 1 == to.x && from.y == to.y) ||
                                (from.x + 1 == to.x && from.y - 1 == to.y)
                          ) // CZY MOZNA SIE TAK RUSZYC KROLEM
                        {
                            if(playboard[to.x][to.y].character != NONE)
                            {
                                beat_figures.push_back(playboard[to.x][to.y].character);
                            }
                            playboard[to.x][to.y] = playboard[from.x][from.y];
                            playboard[from.x][from.y] = Field(NONE);
                            return true;
                        }
                        else
                            return false;
                    }
                    else if(playboard[from.x][from.y].isQueen)
                    {

                        // CZY MOZNA ISC NA SKOS
                        bool tak = false;
                        for(short i = -8; i < 8; i++)
                        {
                            if(from.x+i == to.x && from.y+i == to.y)
                            {
                                tak = true;
                            }
                        }

                        //
                        if(((from.x  == to.x) && (from.y != to.y)) ||
                                ((from.y  == to.y) && (from.x != to.x)) || tak
                          ) // CZY MOZNA SIE TAK RUSZYC KROLOWA
                        {

                            //DAlSZA CZESC

                                if(playboard[to.x][to.y].character != NONE)
                                {
                                    beat_figures.push_back(playboard[to.x][to.y].character);
                                }
                                playboard[to.x][to.y] = playboard[from.x][from.y];
                                playboard[from.x][from.y] = Field(NONE);
                                return true;
                        }
                        else
                            return false;
                    }
                    else if(playboard[from.x][from.y].isRunner)
                    {
                         // CZY MOZNA ISC NA SKOS
                        bool tak = false;
                        for(short i = -8; i < 8; i++)
                        {
                            if(from.x+i == to.x && from.y+i == to.y)
                            {
                                tak = true;
                            }
                        }
                        if(tak) // CZY MOZNA SIE TAK RUSZYC KROLOWA
                        {

                            //DAlSZA CZESC

                                if(playboard[to.x][to.y].character != NONE)
                                {
                                    beat_figures.push_back(playboard[to.x][to.y].character);
                                }
                                playboard[to.x][to.y] = playboard[from.x][from.y];
                                playboard[from.x][from.y] = Field(NONE);
                                return true;
                        }
                        else
                            return false;

                    }
                    else if(playboard[from.x][from.y].isTower)
                    {
                         if((from.x  == to.x) && (from.y != to.y) ||
                                (from.y  == to.y) && (from.x != to.x)
                          ) // CZY MOZNA SIE TAK RUSZYC KROLOWA
                        {

                            //DAlSZA CZESC

                                if(playboard[to.x][to.y].character != NONE)
                                {
                                    beat_figures.push_back(playboard[to.x][to.y].character);
                                }
                                playboard[to.x][to.y] = playboard[from.x][from.y];
                                playboard[from.x][from.y] = Field(NONE);
                                return true;
                        }
                        else
                            return false;

                    }
                    else if(playboard[from.x][from.y].isSoldier)
                    {
                         if((from.x + 1 == to.x && from.y == to.y && playboard[from.x][from.y].isWhite) ||
                            (from.x + 1 == to.x && from.y + 1 == to.y && playboard[from.x][from.y].isWhite && !playboard[from.x+1][from.y+1].isWhite) ||
                            (from.x + 1 == to.x && from.y - 1 == to.y && playboard[from.x][from.y].isWhite && !playboard[from.x+1][from.y-1].isWhite) ||


                            (from.x - 1 == to.x && from.y == to.y && !playboard[from.x][from.y].isWhite) ||
                            (from.x - 1 == to.x && from.y + 1 == to.y && !playboard[from.x][from.y].isWhite && playboard[from.x-1][from.y+1].isWhite) ||
                            (from.x - 1 == to.x && from.y - 1 == to.y && !playboard[from.x][from.y].isWhite && playboard[from.x-1][from.y-1].isWhite)


                          ) // CZY MOZNA SIE TAK RUSZYC KROLOWA
                        {

                            //DAlSZA CZESC

                                if(playboard[to.x][to.y].character != NONE)
                                {
                                    beat_figures.push_back(playboard[to.x][to.y].character);
                                }
                                playboard[to.x][to.y] = playboard[from.x][from.y];
                                playboard[from.x][from.y] = Field(NONE);
                                return true;
                        }
                        else
                            return false;

                    }
                    else
                        exit(3838); // BRAK FIGURY
                }
                else
                    return false;
            }
        }
        else
            return false;
    }

};
void DisplayBoard(Board board)
{
    for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                gotoXY(j * 2, i * 2);
                if(board.playboard[i][j].isWhite)
                    setColor(0, 15);
                else
                    setColor(1,0);

                std::cout << board.playboard[i][j].icon;
            }

}
/**


  1  2  3  4  5  6  7  8
A[] [] [] [] [] [] [] []
B[] [] [] [] [] [] [] []
C[] [] [] [A][] [] [] []
D[] [] [] [] [] [] [] []
E[] [] [] [] [] [] [] []
F[] [] [] [] [] [] [] []
G[] [] [] [] [] [] [] []
H[] [] [] [] [] [] [] []



**/
int main()
{
    Board b1;
    b1.reset();
    b1.playboard[3][4] = Field(WHITE_QUEEN);
    if(b1.moveFigure(PositionXY(3,4), PositionXY(7,4)))
        std::cout << "OK";
    else
        std::cout << "NIE";
    if(b1.moveFigure(PositionXY(7,4), PositionXY(7,3)))
        std::cout << "OK";
    else
        std::cout << "NIE";
    //std::cout <<  "ZNAK : " << b1.playboard[7][3].icon;
    b1.defaultPositionOfFigures();
    while(b1.beat_figures.pop_back() != WHITE_KING || b1.beat_figures.pop_back() != BLACK_KING)
    {
        DisplayBoard(b1);
        safdfsa//// TU INTERFEJS  + OBSŁUGA UŻYTKOWNIKÓW
    }

    gotoXY(20,20);
    return 0;
}
/**
TODO
AI enemy
interface
error control
testing
**/
