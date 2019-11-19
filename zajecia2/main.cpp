#include <iostream>
#include <vector>
#include <windows.h>

CONSOLE_SCREEN_BUFFER_INFO csbi;



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
class Figure
{
public:
    FIGURE_SHAPE character;
    bool isWihite;
    bool isKing;
    bool isQueen;
    bool isRunner;
    bool isHorse;
    bool isTower;
    bool isSoldier;
    Figure(FIGURE_SHAPE type = NONE)
    {
        if(type == NONE)
        {
            isWihite    = false;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
        }
        if(type == BLACK_KING)
        {
            isWihite    = false;
            isKing      = true;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
        }
        if(type == BLACK_QUEEN)
        {
            isWihite    = false;
            isKing      = false;
            isQueen     = true;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
        }
        if(type == BLACK_RUNNER)
        {
            isWihite    = false;
            isKing      = false;
            isQueen     = false;
            isRunner    = true;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
        }
        if(type == BLACK_HORSE)
        {
            isWihite    = false;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = true;
            isTower     = false;
            isSoldier   = false;
        }
        if(type == BLACK_TOWER)
        {
            isWihite    = false;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = true;
            isSoldier   = false;
        }
        if(type == BLACK_SOLDIER)
        {
            isWihite    = false;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = true;
        }
        if(type == WHITE_KING)
        {
            isWihite    = true;
            isKing      = true;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
        }
        if(type == WHITE_QUEEN)
        {
            isWihite    = true;
            isKing      = false;
            isQueen     = true;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
        }
        if(type == WHITE_RUNNER)
        {
            isWihite    = true;
            isKing      = false;
            isQueen     = false;
            isRunner    = true;
            isHorse     = false;
            isTower     = false;
            isSoldier   = false;
        }
        if(type == WHITE_HORSE)
        {
            isWihite    = true;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = true;
            isTower     = false;
            isSoldier   = false;
        }
        if(type == WHITE_TOWER)
        {
            isWihite    = true;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = true;
            isSoldier   = false;
        }
        if(type == WHITE_SOLDIER)
        {
            isWihite    = true;
            isKing      = false;
            isQueen     = false;
            isRunner    = false;
            isHorse     = false;
            isTower     = false;
            isSoldier   = true;
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
    Figure playboard[8][8];
    std::vector<FIGURE_SHAPE> beat_figures; // POKONANE FIGURY
    bool moveFigure(PositionXY from, PositionXY to) // FALSE = NIE MOZNA    TRUE = MOZNA
    {
        if(to.x < 8 && to.x > -1 && to.y < 8 && to.y > -1)//CZY MIESCI SIE W ZAKRESIE TABLICY
        {
            if(playboard[from.x][from.y].character != NONE)// CZY JEST TAM FIGURA
            {
                if(playboard[from.x][from.y].isWihite != playboard[to.x][to.y].isWihite)// CZY KOLORY FIGUR SA ROZNE
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
                            playboard[from.x][from.y] = Figure(NONE);
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
                            playboard[from.x][from.y] = Figure(NONE);
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
                        if((from.x  == to.x) && (from.y != to.y) ||
                                (from.y  == to.y) && (from.x != to.x) || tak
                          ) // CZY MOZNA SIE TAK RUSZYC KROLOWA
                        {

                            //DAlSZA CZESC

                                if(playboard[to.x][to.y].character != NONE)
                                {
                                    beat_figures.push_back(playboard[to.x][to.y].character);
                                }
                                playboard[to.x][to.y] = playboard[from.x][from.y];
                                playboard[from.x][from.y] = Figure(NONE);
                                return true;
                        }
                        else
                            return false;
                    }
                    else if(playboard[from.x][from.y].isRunner)
                    {

                    }
                    else if(playboard[from.x][from.y].isTower)
                    {

                    }
                    else if(playboard[from.x][from.y].isSoldier)
                    {

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
int main()
{
    Board b1;
    b1.playboard[3][4] = Figure(WHITE_QUEEN);
    if(b1.moveFigure(PositionXY(3,4), PositionXY(8,4)))
        std::cout << "OK";
    else
        std::cout << "NIE";
    if(b1.moveFigure(PositionXY(3,4), PositionXY(2,3)))
        std::cout << "OK";
    else
        std::cout << "NIE";


    return 0;
}
