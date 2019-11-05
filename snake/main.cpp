#include <iostream>
#include <vector>
#include <conio.h>


struct Position
{
    unsigned int x;
    unsigned int y;
    Position(int c1, int c2)
    {
        x = c1;
        y = c2;
    }
    Position getPosition()
    {
        return Position(x, y);
    }
    void setPosition(int c1, int c2)
    {
        x = c1;
        y = c2;
    }
};

class Snake
{
    std::vector<Position> waz;


};
int main()
{
    bool play = true;
    char input;
    char input2;
    while(play)
    {

        input = getch();

        if(input == 'a')
            play = false;
    }
    input2 = getch();
    std::cout << input2;
    return 0;
}
