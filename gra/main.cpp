#include "sfgl.cpp"

enum gamemode
{
    null = 0,
    pvp = 1,
    ai = 2,
    lan = 3,
    internet = 4,
    menu = 5
};

int main()
{
    // GLOBAL
    gamemode choose = null;// zmienna przechowujaca aktualnie wybrany tryb gry
    short mode = 1;
    /*
    MODE:
        1 == PvP
        2 == AI
        3 == LAN
        4 == INTERNET
    */
    short init2;
// START GRY
start:
    short init1 = sg::messageWindow(sg::NULL_BUTTON, sg::NULL_BUTTON, sg::CANCEL_BUTTON, sg::OK_BUTTON, "PLAY", "PLAY", "ok", sf::Color(40,240,40));
    Sleep(100);
    if(init1 == 1)
    {
        while(choose == null)
        {
            if(mode == 1)
                init2 = sg::messageWindow(sg::BACK_BUTTON, sg::CANCEL_BUTTON, sg::OK_BUTTON, sg::NEXT_BUTTON, "PLAY", "PvP", "ok", sf::Color(40,240,40));
            if (init2 == 1)
            {
                choose = pvp;
            }
            if (init2 == 2)
            {
                goto start;
            }
        }
    }
    if(init1 == 2)
    {

    }

    return 0;
}

