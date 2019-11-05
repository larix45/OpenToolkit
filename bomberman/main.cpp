#include <irrlicht.h>
#include <iostream>
#include <conio.h>
#include <thread>
#include <windows.h>
#include <ctime>


using namespace irr;

using namespace core;
const int X = 10;
const int Y = 10;


endGame()
{
    exit(3);
}
enum area
{
    BOMB,
    NOTHING,
    WALL,
    UNBREAKEBLE_WALL,
    PLAYER
};
area play_table[X][Y];
class Bomb
{
    time_t explode_time = 4000;
    time_t place_time = 999999999999;
    int x,y;
public:
    void placeBomb(int place_x, int place_y)
    {
        play_table[place_x][place_y] = area::BOMB;
        x = place_x;
        y = place_y;
        place_time = clock();
    }
    void check(int range)
    {
        if(place_time + explode_time < clock())
            explode(range);
    }
    void explode(int range)
    {
        bool up    = false;
        bool down  = false;
        bool right = false;
        bool left  = false;

        for(size_t i = 0; i < range; i++)
        {
            if(x-i >= 0)
                up = true;
            if(x+i >= X)
                down = true;
            if(y-i >= 0)
                right = true;
            if(y+i >= Y)
                left = true;
            if(!up)
            {
                if(play_table[x-i][y] == area::PLAYER)
                    endGame();
                if(play_table[x-i][y] == area::UNBREAKEBLE_WALL)
                    up = true;
                if(play_table[x-i][y] == area::WALL)
                {
                    play_table[x-i][y] = area::NOTHING;
                    up = true;
                }
            }
            if(!down)
            {
                if(play_table[x+i][y] == area::PLAYER)
                    endGame();
                if(play_table[x+i][y] == area::UNBREAKEBLE_WALL)
                    down = true;
                if(play_table[x+i][y] == area::WALL)
                {
                    play_table[x+i][y] = area::NOTHING;
                    down = true;
                }
            }
            if(!right)
            {
                if(play_table[x][y-i] == area::PLAYER)
                    endGame();
                if(play_table[x][y-i] == area::UNBREAKEBLE_WALL)
                    right = true;
                if(play_table[x][y-i] == area::WALL)
                {
                    play_table[x][y-i] = area::NOTHING;
                    right = true;
                }
            }
            if(!left)
            {
                if(play_table[x][y+i] == area::PLAYER)
                    endGame();
                if(play_table[x][y+i] == area::UNBREAKEBLE_WALL)
                    left = true;
                if(play_table[x][y+i] == area::WALL)
                {
                    play_table[x][y+i] = area::NOTHING;
                    left = true;
                }
            }
        }
        play_table[x][y] = area::NOTHING; // SIGSSFAULT
    }

};
class Player
{
    int x,y; //position
public:
    Bomb b1;
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void down()
    {
        if(play_table[x+1][y] == area::NOTHING)
            x++;
    }
    void up()
    {
        if(play_table[x-1][y] == area::NOTHING)
        x--;
    }
    void right()
    {
        if(play_table[x][y+1] == area::NOTHING)
        y++;
    }
    void left()
    {
        if(play_table[x][y-1] == area::NOTHING)
        y--;
    }
    Player(int pos_x, int pos_y)
    {
        x = pos_x;
        y = pos_y;
    }
};
void drawAll(Player player)
{
    area bufor_001 = play_table[player.getX()][player.getY()];
    play_table[player.getX()][player.getY()] = area::PLAYER;
    for(size_t x=1; x < 10; x++)
    {
        for(size_t y=1; y < 10; y++)
            switch(play_table[x][y])
            {
            case area::BOMB:
                std::cout << char(193);
                break;
            case area::NOTHING:
                std::cout << char(255);
                break;
            case area::UNBREAKEBLE_WALL:
                std::cout << char(183);
                break;
            case area::WALL:
                std::cout << char(178);
                break;
            case area::PLAYER:
                std::cout << char(179);
                break;
            }
    std::cout << std::endl;
    }
    play_table[player.getX()][player.getY()] = bufor_001;
}


call(int i)
{
    switch(i)
    {
    case 1:
    exit(444);//NACISNIETO PRZYCISK
        break;
    default:
        break;
    }
}
class MyEventReceiver : public irr::IEventReceiver
{
    bool OnEvent(SEvent event)
    {
        if(event.EventType == irr::EET_KEY_INPUT_EVENT)
            call(1);
    }
};
int main(int argc, char** argv)
{
    MyEventReceiver *receiver;
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_OPENGL, core::dimension2d<u32>(100,100), 16, false, false, false,receiver);
  /*  Player p1(4,3);
    for(size_t x=1; x < X; x++)
        for(size_t y=1; y < Y; y++)
            play_table[x][y] = area::NOTHING;
    play_table[4][4] = area:area play_table[X][Y];:WALL;
    play_table[4][3] = area::WALL;
    play_table[3][4] = area::WALL;
    play_table[4][5] = area::WALL;
    play_table[4][8] = area::UNBREAKEBLE_WALL;
    play_table[5][8] = area::UNBREAKEBLE_WALL;
    char input;
    drawAll(p1);
    while(input != 27)
    {
        p1.b1.check(3);
        if(kbhit())
        {
            input = getch();
            system("cls");
            drawAll(p1);
            switch(input)
            {
            case 'w':
                p1.up();
                break;
            case 'a':
                p1.left();
                break;
            case 's':
                p1.down();
                break;
            case 'd':
                p1.right();
                break;
            case 'x':
                p1.b1.placeBomb(p1.getX(),p1.getY());
                break;
            }
        }

    }



*/

    return 0;
}

