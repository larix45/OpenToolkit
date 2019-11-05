#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <windows.h>
#include <SFML/Network.hpp>
#include <SFML/Window/Mouse.hpp>
#include "sfgl.cpp"

void endln()
{
    std::cout << std::endl;
}

int main()
{
    short main_opperand = 7;
    bool ai_play = false;
    bool pvp_play = false;
    bool lan_play = false;
    bool host = false;
    bool join = false;
    bool player = false;// true = 2 gracz               false = 1 gracz
    while(main_opperand != 5)
    {
        /*
        1 -- x win
        2 -- o win
        3 -- draw
        4 -- new game
        5 -- end game
        */
        sf::RenderWindow start(sf::VideoMode(500,200),"nice");
        sf::Text textb;
        sf::Font arial;
        sf::Event event;
        sf::RectangleShape p1;


        p1.setPosition(380,140);
        p1.setOutlineThickness(5);
        p1.setSize(sf::Vector2f(100,40));

        arial.loadFromFile("./arial.ttf");
        textb.setFont(arial);
        textb.setCharacterSize(40);
        textb.setPosition(50,50);
        textb.setOutlineThickness(4);
        textb.setOutlineColor(sf::Color(0,0,0));
        textb.setColor(sf::Color(255,255,255));
        if(main_opperand == 1)
        {
            Sleep(100);
            start.setTitle("X WIN!");
            p1.setFillColor(sf::Color(200,30,40));
            p1.setOutlineColor(sf::Color(240,30,40));
            textb.setString("GRACZ X WYGRAL");
            textb.setColor(sf::Color(200,50,50));
            while(start.isOpen())
            {
                p1.setFillColor(sf::Color(200,30,40));
                if(sf::Mouse::getPosition(start).x > 380 && sf::Mouse::getPosition(start).x < 380+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                    p1.setFillColor(sf::Color(140,30,40));
                while(start.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed)
                    {
                        main_opperand = 5;
                        start.close();
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        if(sf::Mouse::getPosition(start).x > 380 && sf::Mouse::getPosition(start).x < 380+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                        {
                            main_opperand = 4;
                            start.close();
                        }

                }
                start.clear(sf::Color(250,140,140));
                start.draw(textb);
                start.draw(p1);
                start.display();
            }

        }else if(main_opperand == 2)
        {
            Sleep(100);
            start.setTitle("O WIN!");
            start.setTitle("DRAW!");
            p1.setOutlineColor(sf::Color(40,30,240));
            textb.setString("GRACZ O WYGRAL");
            textb.setColor(sf::Color(50,50,200));
            while(start.isOpen())
            {
                p1.setFillColor(sf::Color(40,30,200));
                if(sf::Mouse::getPosition(start).x > 380 && sf::Mouse::getPosition(start).x < 380+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                    p1.setFillColor(sf::Color(40,30,140));
                while(start.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed)
                    {
                        main_opperand = 5;
                        start.close();
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        if(sf::Mouse::getPosition(start).x > 380 && sf::Mouse::getPosition(start).x < 380+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                        {
                            main_opperand = 4;
                            start.close();
                        }

                }
                start.clear(sf::Color(200,200,250));
                start.draw(textb);
                start.draw(p1);
                start.display();
            }
        }else if(main_opperand == 3)
        {
            Sleep(100);
            start.setTitle("DRAW!");
            p1.setOutlineColor(sf::Color(80,80,80));
            textb.setString("REMIS!");
            while(start.isOpen())
            {
                p1.setFillColor(sf::Color(180,180,180));
                if(sf::Mouse::getPosition(start).x > 380 && sf::Mouse::getPosition(start).x < 380+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                    p1.setFillColor(sf::Color(130,130,130));
                while(start.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed)
                    {
                        main_opperand = 5;
                        start.close();
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        if(sf::Mouse::getPosition(start).x > 380 && sf::Mouse::getPosition(start).x < 380+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                        {
                            main_opperand = 4;
                            start.close();
                        }

                }
                start.clear(sf::Color(200,200,200));
                start.draw(textb);
                start.draw(p1);
                start.display();
            }
        }else
        {

            sf::RectangleShape p2;
            sf::RectangleShape p3;
            sf::Text textbutton1, textbutton2, textbutton3;
            start.setTitle("USTAWIENIA");
            textb.setFillColor(sf::Color(100,240,100));
            textb.setString("PLAY");
            p1.setFillColor(sf::Color(30,200,40));
            p1.setOutlineColor(sf::Color(30,240,40));

            textbutton1.setFont(arial);
            textbutton1.setCharacterSize(14);
            textbutton1.setPosition(400,150);
            textbutton1.setOutlineThickness(2);
            textbutton1.setOutlineColor(sf::Color(0,0,0));
            textbutton1.setColor(sf::Color(255,255,255));
            textbutton1.setFillColor(sf::Color(100,240,100));
            textbutton1.setString("2 players");

            p1.setFillColor(sf::Color(30,200,40));
            p1.setOutlineColor(sf::Color(30,240,40));

            textbutton2.setFont(arial);
            textbutton2.setCharacterSize(14);
            textbutton2.setPosition(286,150);
            textbutton2.setOutlineThickness(2);
            textbutton2.setOutlineColor(sf::Color(0,0,0));
            textbutton2.setColor(sf::Color(255,255,255));
            textbutton2.setFillColor(sf::Color(100,240,100));
            textbutton2.setString("A. I.");

            p2.setPosition(250,140);
            p2.setOutlineThickness(5);
            p2.setSize(sf::Vector2f(100,40));
            p2.setFillColor(sf::Color(30,200,40));
            p2.setOutlineColor(sf::Color(30,240,40));


            textbutton3.setFont(arial);
            textbutton3.setCharacterSize(14);
            textbutton3.setPosition(136,150);
            textbutton3.setOutlineThickness(2);
            textbutton3.setOutlineColor(sf::Color(0,0,0));
            textbutton3.setColor(sf::Color(255,255,255));
            textbutton3.setFillColor(sf::Color(100,240,100));
            textbutton3.setString(" LAN ");

            p3.setPosition(100,140);
            p3.setOutlineThickness(5);
            p3.setSize(sf::Vector2f(100,40));
            p3.setFillColor(sf::Color(30,200,40));
            p3.setOutlineColor(sf::Color(30,240,40));

            while(start.isOpen())
            {
                p1.setFillColor(sf::Color(30,200,40));
                if(sf::Mouse::getPosition(start).x > 380 && sf::Mouse::getPosition(start).x < 380+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                    p1.setFillColor(sf::Color(30,140,40));
                p2.setFillColor(sf::Color(30,200,40));
                if(sf::Mouse::getPosition(start).x > 250 && sf::Mouse::getPosition(start).x < 250+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                    p2.setFillColor(sf::Color(30,140,40));
                p3.setFillColor(sf::Color(30,200,40));
                if(sf::Mouse::getPosition(start).x > 100 && sf::Mouse::getPosition(start).x < 100+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                    p3.setFillColor(sf::Color(30,140,40));
                while(start.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed)
                    {
                        main_opperand = 5;
                        start.close();
                    }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        if(sf::Mouse::getPosition(start).x > 380 && sf::Mouse::getPosition(start).x < 380+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                        {
                            main_opperand = 4;
                            ai_play = false;
                            lan_play = false;
                            pvp_play = true;
                            start.close();
                        }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        if(sf::Mouse::getPosition(start).x > 250 && sf::Mouse::getPosition(start).x < 250+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                        {
                            main_opperand = 4;
                            lan_play = false;
                            pvp_play = false;
                            ai_play = true;
                            start.close();
                        }
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        if(sf::Mouse::getPosition(start).x > 100 && sf::Mouse::getPosition(start).x < 100+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                        {
                            main_opperand = 4;
                            pvp_play = false;
                            ai_play = false;
                            lan_play = true;
                            start.close();
                        }

                }
                start.clear(sf::Color(140,250,140));
                start.draw(textb);
                start.draw(p1);
                start.draw(p2);
                start.draw(p3);
                start.draw(textbutton1);
                start.draw(textbutton2);
                start.draw(textbutton3);
                start.display();

            }
            Sleep(250);

// WYBOR LACZA PRZY GRZE SIECIOWEJ
            if (lan_play)
            {
                sf::RenderWindow start(sf::VideoMode(500,200),"nice");
                sf::Text textb;
                sf::Font arial;
                arial.loadFromFile("./arial.ttf");

                sf::Event event;
                sf::RectangleShape p2;
                sf::RectangleShape p1;
                sf::Text textbutton1, textbutton2;
                start.setTitle("USTAWIENIA");
                textb.setFillColor(sf::Color(100,240,100));
                textb.setString("PLAY");

                textbutton1.setFont(arial);
                textbutton1.setCharacterSize(14);
                textbutton1.setPosition(396,150);
                textbutton1.setOutlineThickness(2);
                textbutton1.setOutlineColor(sf::Color(0,0,0));
                textbutton1.setColor(sf::Color(255,255,255));
                textbutton1.setFillColor(sf::Color(100,240,100));
                textbutton1.setString(" JOIN ");

                textbutton2.setFont(arial);
                textbutton2.setCharacterSize(14);
                textbutton2.setPosition(266,150);
                textbutton2.setOutlineThickness(2);
                textbutton2.setOutlineColor(sf::Color(0,0,0));
                textbutton2.setColor(sf::Color(255,255,255));
                textbutton2.setFillColor(sf::Color(100,240,100));
                textbutton2.setString(" HOST ");

                p1.setPosition(380,140);
                p1.setOutlineThickness(5);
                p1.setSize(sf::Vector2f(100,40));
                p1.setFillColor(sf::Color(30,200,40));
                p1.setOutlineColor(sf::Color(30,240,40));

                p2.setPosition(250,140);
                p2.setOutlineThickness(5);
                p2.setSize(sf::Vector2f(100,40));
                p2.setFillColor(sf::Color(30,200,40));
                p2.setOutlineColor(sf::Color(30,240,40));

                while(start.isOpen())
                {
                    p1.setFillColor(sf::Color(30,200,40));
                    if(sf::Mouse::getPosition(start).x > 380 && sf::Mouse::getPosition(start).x < 380+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                        p1.setFillColor(sf::Color(30,140,40));
                    p2.setFillColor(sf::Color(30,200,40));
                    if(sf::Mouse::getPosition(start).x > 250 && sf::Mouse::getPosition(start).x < 250+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                        p2.setFillColor(sf::Color(30,140,40));
                    while(start.pollEvent(event))
                    {
                        if(event.type == sf::Event::Closed)
                        {
                            main_opperand = 5;
                            start.close();
                        }
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                            if(sf::Mouse::getPosition(start).x > 380 && sf::Mouse::getPosition(start).x < 380+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                            {
                                join = true;
                                start.close();
                            }
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                            if(sf::Mouse::getPosition(start).x > 250 && sf::Mouse::getPosition(start).x < 250+100+5+5 && sf::Mouse::getPosition(start).y > 140 && sf::Mouse::getPosition(start).y < 140+40+5+5)
                            {
                                host = true;
                                start.close();
                            }
                    }
                    start.clear(sf::Color(140,250,140));
                    start.draw(textb);
                    start.draw(p1);
                    start.draw(p2);
                    start.draw(textbutton1);
                    start.draw(textbutton2);
                    start.display();

                }
            }
            sf::RenderWindow window(sf::VideoMode(650,650),"Kolko i krzyzyk.");
            short plansza[3][3];
            short plansza_podpowiedzi[3][3];
//OBIEKTY

            sf::RectangleShape ll,lll,llll,lllll;
            ll.setFillColor(sf::Color(120,70,0));
            lll.setFillColor(sf::Color(120,70,0));
            llll.setFillColor(sf::Color(120,70,0));
            lllll.setFillColor(sf::Color(120,70,0));
            ll.setSize(sf::Vector2f(5,610));
            lll.setSize(sf::Vector2f(5,610));
            llll.setSize(sf::Vector2f(610,5));
            lllll.setSize(sf::Vector2f(610,5));
            ll.setPosition(sf::Vector2f(20+200,20));
            lll.setPosition(sf::Vector2f(20+200+5+200,20));
            llll.setPosition(sf::Vector2f(20,20+200));
            lllll.setPosition(sf::Vector2f(20,20+200+5+200));


            sf::RectangleShape k1,k2,kc1,kc2;
            k1.setFillColor(sf::Color(220,20,8));
            k2.setFillColor(sf::Color(220,20,8));
            kc1.setFillColor(sf::Color(120,20,8));
            kc2.setFillColor(sf::Color(120,20,8));
            k1.setSize(sf::Vector2f(280,5));
            k2.setSize(sf::Vector2f(280,5));
            kc1.setSize(sf::Vector2f(280,5));
            kc2.setSize(sf::Vector2f(280,5));
            k1.setRotation(45);
            k2.setRotation(-45);
            kc1.setRotation(45);
            kc2.setRotation(-45);


            sf::CircleShape o,oc;
            o.setOutlineColor(sf::Color(30,90,210));
            oc.setOutlineColor(sf::Color(30,90,110));
            o.setOutlineThickness(5);
            oc.setOutlineThickness(5);
            o.setFillColor(sf::Color(0,0,0,0));
            oc.setFillColor(sf::Color(0,0,0,0));
            o.setRadius(90);
            oc.setRadius(90);

           // ZEROWANIE TABLIC
            for(short i=0;i<3;i++)
            {
                for(short j=0;j<3;j++)
                {
                    plansza_podpowiedzi[i][j] = 0;
                }
                endln();
            }

            for(short i=0;i<3;i++)
            {
                for(short j=0;j<3;j++)
                {
                    plansza[i][j] = 0;
                }
                endln();
            }

           endln();
/*
            if (lan_play && join)
            {
                short data[5][4];
                // UDP socket:
                sf::UdpSocket socket;

                // bind the socket to a port
                if (socket.bind(54000) != sf::Socket::Done)
                {
                // error...
                }
                sf::IpAddress recipient = "10.3.1.56";
                unsigned short port = 54000;
                if (socket.send(data, 100, recipient, port) != sf::Socket::Done)
                {
                    // error...
                }
                player = false;
            }
            if (lan_play && host)
            {
                short data[5][4];
                std::size_t received;
               // UDP socket:
               sf::UdpSocket socket;

                // bind the socket to a port
                if (socket.bind(54000) != sf::Socket::Done)
                {
                    // error...
                }
                sf::IpAddress sender;
                unsigned short port;
                if (socket.receive(data, 100, received, sender, port) != sf::Socket::Done)
                {
                    // error...
                }
                std::cout << data[5][4] << std::endl;

                std::cout << "Received " << received << " bytes from " << sender << " on port " << port << std::endl;
            }*/
            if (lan_play && host)
            {
                player = false;
            } else
            if (lan_play && join)
            {
                player = true;
            }
            if (lan_play && join)
            {
                short data[1];
                data[1] = 342;
                // UDP socket:
                sf::UdpSocket socket;
                if (socket.bind(54000) != sf::Socket::Done)
                {
                    return 5;
                }
                sf::IpAddress recipient = "192.168.1.20";
                unsigned short port = 54000;
                if (socket.send(data, 1, recipient, port) != sf::Socket::Done)
                {
                    return 5;
                }
            }
            if (lan_play && host)
            {
                short data[1];
                std::size_t received;
                // UDP socket:
                sf::UdpSocket socket;
                // bind socket'u na port
                if (socket.bind(55000) != sf::Socket::Done)
                {
                    return 5;
                }
                sf::IpAddress sender;
                unsigned short port;
                if (socket.receive(data, 1, received, sender, port) != sf::Socket::Done)
                {
                    return 5;
                }
                log(data[1]);
            }

            while(window.isOpen())
            {
                if (lan_play && join)
                {

                    short data[5][4];
                    for(short i=0;i<3;i++)
                    {
                        for(short j=0;j<3;j++)
                        {
                            if (data[i][j] == 2)
                            plansza[i][j] = 1;
                            if (data[i][j] == 1)
                            plansza[i][j] = 2;
                        }
                    }

                    // UDP socket:
                    sf::UdpSocket socket;

                    // bind the socket to a port
                    if (socket.bind(54000) != sf::Socket::Done)
                    {
                    // error...
                    }
                    sf::IpAddress recipient = "localhost";
                    unsigned short port = 54000;
                    if (socket.send(data, 1000, recipient, port) != sf::Socket::Done)
                    {
                        // error...
                    }

                }
                if (lan_play && host)
                {
                    short data[5][4];
                    std::size_t received;
                   // UDP socket:
                   sf::UdpSocket socket;

                    // bind socket'u na port
                    if (socket.bind(55000) != sf::Socket::Done)
                    {
                        log(222);
                    }
                    sf::IpAddress sender;
                    unsigned short port;
                    if (socket.receive(data, 1000, received, sender, port) != sf::Socket::Done)
                    {
                        log(321);
                    }
                    std::cout << data[5][4] << std::endl;
                    for(short i=0;i<3;i++)
                    {
                        for(short j=0;j<3;j++)
                        {
                             plansza[i][j] = data[i][j];
                        }
                    }
                    std::cout << "Received " << received << " bytes from " << sender << " on port " << port << std::endl;


                }

                /*
                [1][2][3]
                [4][5][6]
                [7][8][9]


                [0,0][0,1][0,2]
                [1,0][1,1][1,2]
                [2,0][2,1][2,2]
                */

                short masx = sf::Mouse::getPosition(window).x;
                short masy = sf::Mouse::getPosition(window).y;
                // A.I. play
                if(player && ai_play)
                {
                    if(plansza[1][1] == 0)
                    {
                        plansza[1][1] = 2;
                        player = false;
                    } else
            // SPRAWDZANIE CZY MAM SZANSE WYGRAC
                    if(plansza[0][0] == 2 && plansza[0][1] == 2 && plansza[0][2] == 0)
                    {
                        plansza[0][2] = 2;
                        player = false;
                    } else
                    if(plansza[0][0] == 2 && plansza[0][2] == 2 && plansza[0][1] == 0)
                    {
                        plansza[0][1] = 2;
                        player = false;
                    } else
                    if(plansza[0][1] == 2 && plansza[0][2] == 2 && plansza[0][0] == 0)
                    {
                        plansza[0][0] = 2;
                        player = false;
                    }else
                    if(plansza[1][0] == 2 && plansza[1][1] == 2 && plansza[1][2] == 0)
                    {
                        plansza[1][2] = 2;
                        player = false;
                    } else
                    if(plansza[1][0] == 2 && plansza[1][2] == 2 && plansza[1][1] == 0)
                    {
                        plansza[1][1] = 2;
                        player = false;
                    } else
                    if(plansza[1][1] == 2 && plansza[1][2] == 2 && plansza[1][0] == 0)
                    {
                        plansza[1][0] = 2;
                        player = false;
                    }else
                    if(plansza[2][0] == 2 && plansza[2][1] == 2 && plansza[2][2] == 0)
                    {
                        plansza[2][2] = 2;
                        player = false;
                    } else
                    if(plansza[2][0] == 2 && plansza[2][2] == 2 && plansza[2][1] == 0)
                    {
                        plansza[2][1] = 2;
                        player = false;
                    } else
                    if(plansza[2][1] == 2 && plansza[2][2] == 2 && plansza[2][0] == 0)
                    {
                        plansza[2][0] = 2;
                        player = false;
                    }else
                    if(plansza[0][0] == 2 && plansza[1][0] == 2 && plansza[2][0] == 0)
                    {
                        plansza[2][0] = 2;
                        player = false;
                    } else
                    if(plansza[0][0] == 2 && plansza[2][0] == 2 && plansza[1][0] == 0)
                    {
                        plansza[1][0] = 2;
                        player = false;
                    } else
                    if(plansza[1][0] == 2 && plansza[2][0] == 2 && plansza[0][0] == 0)
                    {
                        plansza[0][0] = 2;
                        player = false;
                    }else
                    if(plansza[0][1] == 2 && plansza[1][1] == 2 && plansza[2][1] == 0)
                    {
                        plansza[2][1] = 2;
                        player = false;
                    } else
                    if(plansza[0][1] == 2 && plansza[2][1] == 2 && plansza[1][1] == 0)
                    {
                        plansza[1][1] = 2;
                        player = false;
                    } else
                    if(plansza[1][1] == 2 && plansza[2][1] == 2 && plansza[0][1] == 0)
                    {
                        plansza[0][1] = 2;
                        player = false;
                    }else
                    if(plansza[0][2] == 2 && plansza[1][2] == 2 && plansza[2][2] == 0)
                    {
                        plansza[2][2] = 2;
                        player = false;
                    } else
                    if(plansza[0][2] == 2 && plansza[2][2] == 2 && plansza[1][2] == 0)
                    {
                        plansza[1][2] = 2;
                        player = false;
                    } else
                    if(plansza[1][2] == 2 && plansza[2][2] == 2 && plansza[0][2] == 0)
                    {
                        plansza[0][2] = 2;
                        player = false;
                    }else
                    if(plansza[0][0] == 2 && plansza[1][1] == 2 && plansza[2][2] == 0)
                    {
                        plansza[2][2] = 2;
                        player = false;
                    } else
                    if(plansza[0][0] == 2 && plansza[2][2] == 2 && plansza[1][1] == 0)
                    {
                        plansza[1][1] = 2;
                        player = false;
                    } else
                    if(plansza[1][1] == 2 && plansza[2][2] == 2 && plansza[0][0] == 0)
                    {
                        plansza[0][0] = 2;
                        player = false;
                    }else
                    if(plansza[0][2] == 2 && plansza[1][1] == 2 && plansza[2][0] == 0)
                    {
                        plansza[2][0] = 2;
                        player = false;
                    } else
                    if(plansza[0][2] == 2 && plansza[2][0] == 2 && plansza[1][1] == 0)
                    {
                        plansza[1][1] = 2;
                        player = false;
                    } else
                    if(plansza[1][1] == 2 && plansza[2][0] == 2 && plansza[0][2] == 0)
                    {
                        plansza[0][2] = 2;
                        player = false;
                    }else
            // CZY PRZECIWNIK  WYGRA
                    if(plansza[0][0] == 1 && plansza[0][1] == 1 && plansza[0][2] == 0)
                    {
                        plansza[0][2] = 2;
                        player = false;
                    } else
                    if(plansza[0][0] == 1 && plansza[0][2] == 1 && plansza[0][1] == 0)
                    {
                        plansza[0][1] = 2;
                        player = false;
                    } else
                    if(plansza[0][1] == 1 && plansza[0][2] == 1 && plansza[0][0] == 0)
                    {
                        plansza[0][0] = 2;
                        player = false;
                    }else
                    if(plansza[1][0] == 1 && plansza[1][1] == 1 && plansza[1][2] == 0)
                    {
                        plansza[1][2] = 2;
                        player = false;
                    } else
                    if(plansza[1][0] == 1 && plansza[1][2] == 1 && plansza[1][1] == 0)
                    {
                        plansza[1][1] = 2;
                        player = false;
                    } else
                    if(plansza[1][1] == 1 && plansza[1][2] == 1 && plansza[1][0] == 0)
                    {
                        plansza[1][0] = 2;
                        player = false;
                    }else
                    if(plansza[2][0] == 1 && plansza[2][1] == 1 && plansza[2][2] == 0)
                    {
                        plansza[2][2] = 2;
                        player = false;
                    } else
                    if(plansza[2][0] == 1 && plansza[2][2] == 1 && plansza[2][1] == 0)
                    {
                        plansza[2][1] = 2;
                        player = false;
                    } else
                    if(plansza[2][1] == 1 && plansza[2][2] == 1 && plansza[2][0] == 0)
                    {
                        plansza[2][0] = 2;
                        player = false;
                    }else
                    if(plansza[0][0] == 1 && plansza[1][0] == 1 && plansza[2][0] == 0)
                    {
                        plansza[2][0] = 2;
                        player = false;
                    } else
                    if(plansza[0][0] == 1 && plansza[2][0] == 1 && plansza[1][0] == 0)
                    {
                        plansza[1][0] = 2;
                        player = false;
                    } else
                    if(plansza[1][0] == 1 && plansza[2][0] == 1 && plansza[0][0] == 0)
                    {
                        plansza[0][0] = 2;
                        player = false;
                    }else
                    if(plansza[0][1] == 1 && plansza[1][1] == 1 && plansza[2][1] == 0)
                    {
                        plansza[2][1] = 2;
                        player = false;
                    } else
                    if(plansza[0][1] == 1 && plansza[2][1] == 1 && plansza[1][1] == 0)
                    {
                        plansza[1][1] = 2;
                        player = false;
                    } else
                    if(plansza[1][1] == 1 && plansza[2][1] == 1 && plansza[0][1] == 0)
                    {
                        plansza[0][1] = 2;
                        player = false;
                    }else
                    if(plansza[0][2] == 1 && plansza[1][2] == 1 && plansza[2][2] == 0)
                    {
                        plansza[2][2] = 2;
                        player = false;
                    } else
                    if(plansza[0][2] == 1 && plansza[2][2] == 1 && plansza[1][2] == 0)
                    {
                        plansza[1][2] = 2;
                        player = false;
                    } else
                    if(plansza[1][2] == 1 && plansza[2][2] == 1 && plansza[0][2] == 0)
                    {
                        plansza[0][2] = 2;
                        player = false;
                    }else
                    if(plansza[0][0] == 1 && plansza[1][1] == 1 && plansza[2][2] == 0)
                    {
                        plansza[2][2] = 2;
                        player = false;
                    } else
                    if(plansza[0][0] == 1 && plansza[2][2] == 1 && plansza[1][1] == 0)
                    {
                        plansza[1][1] = 2;
                        player = false;
                    } else
                    if(plansza[1][1] == 1 && plansza[2][2] == 1 && plansza[0][0] == 0)
                    {
                        plansza[0][0] = 2;
                        player = false;
                    }else
                    if(plansza[0][2] == 1 && plansza[1][1] == 1 && plansza[2][0] == 0)
                    {
                        plansza[2][0] = 2;
                        player = false;
                    } else
                    if(plansza[0][2] == 1 && plansza[2][0] == 1 && plansza[1][1] == 0)
                    {
                        plansza[1][1] = 2;
                        player = false;
                    } else
                    if(plansza[1][1] == 1 && plansza[2][0] == 1 && plansza[0][2] == 0)
                    {
                        plansza[0][2] = 2;
                        player = false;
                    }else

            // ROGI
                    if(plansza[0][1] == 1 && plansza[1][0] == 1 && plansza[0][0] == 0)
                    {
                        plansza[0][0] = 2;
                        player = false;
                    }else
                    if(plansza[1][0] == 1 && plansza[2][1] == 1 && plansza[2][0] == 0)
                    {
                        plansza[2][0] = 2;
                        player = false;
                    }else
                    if(plansza[2][1] == 1 && plansza[1][2] == 1 && plansza[2][2] == 0)
                    {
                        plansza[2][2] = 2;
                        player = false;
                    }else
                    if(plansza[1][2] == 1 && plansza[0][1] == 1 && plansza[0][2] == 0)
                    {
                        plansza[0][2] = 2;
                        player = false;
                    }else

            // WOLNE POLA
                    if (plansza[0][1] == 0)
                    {
                        plansza[0][1] = 2;
                        player = false;
                    }else
                    if (plansza[1][0] == 0)
                    {
                        plansza[1][0] = 2;
                        player = false;
                    }else
                    if (plansza[2][1] == 0)
                    {
                        plansza[2][1] = 2;
                        player = false;
                    }else
                    if (plansza[1][2] == 0)
                    {
                        plansza[1][2] = 2;
                        player = false;
                    }else
                    if (plansza[0][0] == 0)
                    {
                        plansza[0][0] = 2;
                        player = false;
                    }else
                    if (plansza[0][2] == 0)
                    {
                        plansza[0][2] = 2;
                        player = false;
                    }else
                    if (plansza[2][2] == 0)
                    {
                        plansza[2][2] = 2;
                        player = false;
                    }else
                    if (plansza[2][0] == 0)
                    {
                        plansza[2][0] = 2;
                        player = false;
                    }
                    /*
                    [0,0][0,1][0,2]
                    [1,0][1,1][1,2]
                    [2,0][2,1][2,2]
                    */

                }

// PO NAJECHANIU NA POLE (EFEKT CIENIA)
        {


                if(masx > 20 && masx < 20+200 && masy > 20 && masy < 20+200)
                    if (plansza_podpowiedzi [0][0] == 0 && plansza[0][0] == 0)
                    {
                        if(player)
                        {
                            plansza_podpowiedzi [0][0] = 2;
                        }else
                        {
                            plansza_podpowiedzi [0][0] = 1;
                        }
                    }

                if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20 && masy < 20+200)
                                if (plansza_podpowiedzi [0][1] == 0 && plansza[0][1] == 0)
                                    if(player)
                                    {
                                        plansza_podpowiedzi [0][1] = 2;
                                    }else
                                    {
                                        plansza_podpowiedzi [0][1] = 1;
                                    }


                if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20 && masy < 20+200)
                        if (plansza_podpowiedzi [0][2] == 0 && plansza[0][2] == 0)
                            if(player)
                            {
                                plansza_podpowiedzi [0][2] = 2;
                            }else
                            {
                                plansza_podpowiedzi [0][2] = 1;
                            }



                if(masx > 20 && masx < 20+200 && masy > 20+200+5 && masy < 20+200+5+200)//4
                        if (plansza_podpowiedzi [1][0] == 0 && plansza[1][0] == 0)
                            if(player)
                            {
                                plansza_podpowiedzi [1][0] = 2;
                            }else
                            {
                                plansza_podpowiedzi [1][0] = 1;
                            }

                if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20+200+5 && masy < 20+200+5+200)
                    if (plansza_podpowiedzi [1][1] == 0 && plansza[1][1] == 0)
                        if(player)
                        {
                            plansza_podpowiedzi [1][1] = 2;
                        }else
                        {
                            plansza_podpowiedzi [1][1] = 1;
                        }

                if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20+200+5 && masy < 20+200+5+200)
                    if (plansza_podpowiedzi [1][2] == 0 && plansza[1][2] == 0)
                            if(player)
                            {
                                plansza_podpowiedzi [1][2] = 2;
                            }else
                            {
                                plansza_podpowiedzi [1][2] = 1;
                            }



                if(masx > 20 && masx < 20+200 && masy > 20+200+5+200+5 && masy < 20+200+5+200+5+200)
                    if (plansza_podpowiedzi [2][0] == 0 && plansza[2][0] == 0)
                            if(player)
                            {
                                plansza_podpowiedzi [2][0] = 2;
                            }else
                            {
                                plansza_podpowiedzi [2][0] = 1;
                            }

                if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20+200+5+200+5  && masy < 20+200+5+200+5+200)
                    if (plansza_podpowiedzi [2][1] == 0 && plansza[2][1] == 0)
                            if(player)
                            {
                                plansza_podpowiedzi [2][1] = 2;
                            }else
                            {
                                plansza_podpowiedzi [2][1] = 1;
                            }



                if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20+200+5+200+5  && masy < 20+200+5+200+5+200)
                    if (plansza_podpowiedzi [2][2] == 0 && plansza[2][2] == 0)
                            if(player)
                            {
                                plansza_podpowiedzi [2][2] = 2;
                            }else
                            {
                                plansza_podpowiedzi [2][2] = 1;
                            }



        }

                while(window.pollEvent(event)) // PO PRZYCIŒNIÊCIU POLA
                {
                    if(event.type == sf::Event::Closed)
                        window.close();

                    if(lan_play && join)
                    {
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            if(masx > 20 && masx < 20+200 && masy > 20 && masy < 20+200)//1
                            {
                               if (plansza [0][0] == 0)
                               {
                                   if(!player)
                                   {
                                       plansza [0][0] = 2;
                                   }
                                    player = !player;
                                }
                            }
                            if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20 && masy < 20+200)//2
                                if (plansza [0][1] == 0)
                                {
                                    if(!player)
                                    {
                                        plansza [0][1] = 2;
                                    }
                                    player = !player;
                                 }
                            if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20 && masy < 20+200)//3
                                if (plansza [0][2] == 0)
                                {
                                    if(!player)
                                    {
                                        plansza [0][2] = 2;
                                    }
                                    player = !player;
                                 }
                            if(masx > 20 && masx < 20+200 && masy > 20+200+5 && masy < 20+200+5+200)//4
                                if (plansza [1][0] == 0)
                                {
                                    if(!player)
                                    {
                                        plansza [1][0] = 2;
                                    }
                                    player = !player;
                                 }
                            if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20+200+5 && masy < 20+200+5+200)//5
                                if (plansza [1][1] == 0)
                                {
                                    if(!player)
                                    {
                                        plansza [1][1] = 2;
                                    }
                                    player = !player;
                                 }
                            if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20+200+5 && masy < 20+200+5+200)//6
                                if (plansza [1][2] == 0)
                                {
                                    if(!player)
                                    {
                                        plansza [1][2] = 2;
                                    }
                                    player = !player;
                                 }
                            if(masx > 20 && masx < 20+200 && masy > 20+200+5+200+5 && masy < 20+200+5+200+5+200)//7
                                if (plansza [2][0] == 0)
                                {
                                    if(!player)
                                    {
                                        plansza [2][0] = 2;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20+200+5+200+5  && masy < 20+200+5+200+5+200)//8
                                if (plansza [2][1] == 0)
                                {
                                    if(!player)
                                    {
                                        plansza [2][1] = 2;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20+200+5+200+5  && masy < 20+200+5+200+5+200)//9
                                if (plansza [2][2] == 0)
                                {
                                    if(!player)
                                    {
                                        plansza [2][2] = 2;
                                    }
                                    player = !player;
                                 }
                        }
                    }






                    if(lan_play && host)
                    {
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            if(masx > 20 && masx < 20+200 && masy > 20 && masy < 20+200)//1
                            {
                               if (plansza [0][0] == 0)
                               {
                                   if(player)
                                   {
                                       plansza [0][0] = 2;
                                   }
                                    player = !player;
                                }
                            }
                            if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20 && masy < 20+200)//2
                                if (plansza [0][1] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [0][1] = 2;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20 && masy < 20+200)//3
                                if (plansza [0][2] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [0][2] = 2;
                                    }
                                    player = !player;
                                 }

                                if(masx > 20 && masx < 20+200 && masy > 20+200+5 && masy < 20+200+5+200)//4
                                if (plansza [1][0] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [1][0] = 2;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20+200+5 && masy < 20+200+5+200)//5
                                if (plansza [1][1] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [1][1] = 2;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20+200+5 && masy < 20+200+5+200)//6
                                if (plansza [1][2] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [1][2] = 2;
                                    }
                                    player = !player;
                                 }



                            if(masx > 20 && masx < 20+200 && masy > 20+200+5+200+5 && masy < 20+200+5+200+5+200)//7
                                if (plansza [2][0] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [2][0] = 2;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20+200+5+200+5  && masy < 20+200+5+200+5+200)//8
                                if (plansza [2][1] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [2][1] = 2;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20+200+5+200+5  && masy < 20+200+5+200+5+200)//9
                                if (plansza [2][2] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [2][2] = 2;
                                    }
                                    player = !player;
                                 }
                        }
                    }





                    if(ai_play || pvp_play)
                    {
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            if(masx > 20 && masx < 20+200 && masy > 20 && masy < 20+200)//1
                            {
                               if (plansza [0][0] == 0)
                               {
                                   if(player)
                                   {
                                       plansza [0][0] = 2;
                                   }else
                                    {
                                        plansza [0][0] = 1;
                                    }
                                    player = !player;
                                }
                            }
                            if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20 && masy < 20+200)//2
                                if (plansza [0][1] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [0][1] = 2;
                                    }else
                                    {
                                        plansza [0][1] = 1;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20 && masy < 20+200)//3
                                if (plansza [0][2] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [0][2] = 2;
                                    }else
                                    {
                                        plansza [0][2] = 1;
                                    }
                                    player = !player;
                                 }

                                if(masx > 20 && masx < 20+200 && masy > 20+200+5 && masy < 20+200+5+200)//4
                                if (plansza [1][0] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [1][0] = 2;
                                    }else
                                    {
                                        plansza [1][0] = 1;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20+200+5 && masy < 20+200+5+200)//5
                                if (plansza [1][1] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [1][1] = 2;
                                    }else
                                    {
                                        plansza [1][1] = 1;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20+200+5 && masy < 20+200+5+200)//6
                                if (plansza [1][2] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [1][2] = 2;
                                    }else
                                    {
                                        plansza [1][2] = 1;
                                    }
                                    player = !player;
                                 }



                            if(masx > 20 && masx < 20+200 && masy > 20+200+5+200+5 && masy < 20+200+5+200+5+200)//7
                                if (plansza [2][0] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [2][0] = 2;
                                    }else
                                    {
                                        plansza [2][0] = 1;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5 && masx < 20+200+5+200 && masy > 20+200+5+200+5  && masy < 20+200+5+200+5+200)//8
                                if (plansza [2][1] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [2][1] = 2;
                                    }else
                                    {
                                        plansza [2][1] = 1;
                                    }
                                    player = !player;
                                 }

                            if(masx > 20+200+5+200+5 && masx < 20+200+5+200+5+200 && masy > 20+200+5+200+5  && masy < 20+200+5+200+5+200)//9
                                if (plansza [2][2] == 0)
                                {
                                    if(player)
                                    {
                                        plansza [2][2] = 2;
                                    }else
                                    {
                                        plansza [2][2] = 1;
                                    }
                                    player = !player;
                                 }
                        }
                    }

                }
                // clear
                window.clear(sf::Color(66,44,66));


                // RYSOWANIE CIENI o i x
                {
                    if(plansza_podpowiedzi[0][0] == 1)
                    {
                        kc1.setPosition(20,20);
                        kc2.setPosition(20,20+200);
                        window.draw(kc1);
                        window.draw(kc2);
                    }
                    if(plansza_podpowiedzi[0][1] == 1)
                    {
                        kc1.setPosition(20+200+5,20);
                        kc2.setPosition(20+200+5,20+200);
                        window.draw(kc1);
                        window.draw(kc2);
                    }
                    if(plansza_podpowiedzi[0][2] == 1)
                    {
                        kc1.setPosition(20+200+5+200+5,20);
                        kc2.setPosition(20+200+5+200+5,20+200);
                        window.draw(kc1);
                        window.draw(kc2);
                    }
                    if(plansza_podpowiedzi[1][0] == 1)
                    {
                        kc1.setPosition(20,20+200+5);
                        kc2.setPosition(20,20+200+5+200);
                        window.draw(kc1);
                        window.draw(kc2);
                    }
                    if(plansza_podpowiedzi[1][1] == 1)
                    {
                        kc1.setPosition(20+200+5,20+200+5);
                        kc2.setPosition(20+200+5,20+200+5+200);
                        window.draw(kc1);
                        window.draw(kc2);
                    }
                    if(plansza_podpowiedzi[1][2] == 1)
                    {
                        kc1.setPosition(20+200+5+200+5,20+200+5);
                        kc2.setPosition(20+200+5+200+5,20+200+5+200);
                        window.draw(kc1);
                        window.draw(kc2);
                    }
                    if(plansza_podpowiedzi[2][0] == 1)
                    {
                        kc1.setPosition(20,20+200+5+200+5);
                        kc2.setPosition(20,20+200+5+200+5+200);
                        window.draw(kc1);
                        window.draw(kc2);
                    }
                    if(plansza_podpowiedzi[2][1] == 1)
                    {
                        kc1.setPosition(20+200+5,20+200+5+200+5);
                        kc2.setPosition(20+200+5,20+200+5+200+5+200);
                        window.draw(kc1);
                        window.draw(kc2);
                    }
                    if(plansza_podpowiedzi[2][2] == 1)
                    {
                        kc1.setPosition(20+200+5+200+5,20+200+5+200+5);
                        kc2.setPosition(20+200+5+200+5,20+200+5+200+5+200);
                        window.draw(kc1);
                        window.draw(kc2);
                    }
                    if(plansza_podpowiedzi[0][0] == 2)
                    {
                        oc.setPosition(20+8,20+8);
                        window.draw(oc);
                    }
                    if(plansza_podpowiedzi[0][1] == 2)
                    {
                        oc.setPosition(20+200+5+8,20+8);
                        window.draw(oc);
                    }
                    if(plansza_podpowiedzi[0][2] == 2)
                    {
                        oc.setPosition(20+200+5+200+5+8,20+8);
                        window.draw(oc);
                    }
                    if(plansza_podpowiedzi[1][0] == 2)
                    {
                        oc.setPosition(20+8,20+200+5+8);
                        window.draw(oc);
                    }
                    if(plansza_podpowiedzi[1][1] == 2)
                    {
                        oc.setPosition(20+200+5+8,20+200+5+8);
                        window.draw(oc);
                    }
                    if(plansza_podpowiedzi[1][2] == 2)
                    {
                        oc.setPosition(20+200+5+200+5+8,20+200+5+8);
                        window.draw(oc);
                    }
                    if(plansza_podpowiedzi[2][0] == 2)
                    {
                        oc.setPosition(20+8,20+200+5+200+5+8);
                        window.draw(oc);
                    }
                    if(plansza_podpowiedzi[2][1] == 2)
                    {
                        oc.setPosition(20+200+5+8,20+200+5+200+5+8);
                        window.draw(oc);
                    }
                    if(plansza_podpowiedzi[2][2] == 2)
                    {
                        oc.setPosition(20+200+5+200+5+8,20+200+5+200+5+8);
                        window.draw(oc);
                    }
                }
                for(short i = 0; i < 3;i++)
                    for(short j = 0; j < 3;j++)
                        plansza_podpowiedzi[i][j] = 0;

        // RYSOWANIE o i x
{
                if(plansza[0][0] == 1)
                {
                    k1.setPosition(20,20);
                    k2.setPosition(20,20+200);
                    window.draw(k1);
                    window.draw(k2);
                }
                if(plansza[0][1] == 1)
                {
                    k1.setPosition(20+200+5,20);
                    k2.setPosition(20+200+5,20+200);
                    window.draw(k1);
                    window.draw(k2);
                }
                if(plansza[0][2] == 1)
                {
                    k1.setPosition(20+200+5+200+5,20);
                    k2.setPosition(20+200+5+200+5,20+200);
                    window.draw(k1);
                    window.draw(k2);
                }
                if(plansza[1][0] == 1)
                {
                    k1.setPosition(20,20+200+5);
                    k2.setPosition(20,20+200+5+200);
                    window.draw(k1);
                    window.draw(k2);
                }
                if(plansza[1][1] == 1)
                {
                    k1.setPosition(20+200+5,20+200+5);
                    k2.setPosition(20+200+5,20+200+5+200);
                    window.draw(k1);
                    window.draw(k2);
                }
                if(plansza[1][2] == 1)
                {
                    k1.setPosition(20+200+5+200+5,20+200+5);
                    k2.setPosition(20+200+5+200+5,20+200+5+200);
                    window.draw(k1);
                    window.draw(k2);
                }
                if(plansza[2][0] == 1)
                {
                    k1.setPosition(20,20+200+5+200+5);
                    k2.setPosition(20,20+200+5+200+5+200);
                    window.draw(k1);
                    window.draw(k2);
                }
                if(plansza[2][1] == 1)
                {
                    k1.setPosition(20+200+5,20+200+5+200+5);
                    k2.setPosition(20+200+5,20+200+5+200+5+200);
                    window.draw(k1);
                    window.draw(k2);
                }
                if(plansza[2][2] == 1)
                {
                    k1.setPosition(20+200+5+200+5,20+200+5+200+5);
                    k2.setPosition(20+200+5+200+5,20+200+5+200+5+200);
                    window.draw(k1);
                    window.draw(k2);
                }
                if(plansza[0][0] == 2)
                {
                    o.setPosition(20+8,20+8);
                    window.draw(o);
                }
                if(plansza[0][1] == 2)
                {
                    o.setPosition(20+200+5+8,20+8);
                    window.draw(o);
                }
                if(plansza[0][2] == 2)
                {
                    o.setPosition(20+200+5+200+5+8,20+8);
                    window.draw(o);
                }
                if(plansza[1][0] == 2)
                {
                    o.setPosition(20+8,20+200+5+8);
                    window.draw(o);
                }
                if(plansza[1][1] == 2)
                {
                    o.setPosition(20+200+5+8,20+200+5+8);
                    window.draw(o);
                }
                if(plansza[1][2] == 2)
                {
                    o.setPosition(20+200+5+200+5+8,20+200+5+8);
                    window.draw(o);
                }
                if(plansza[2][0] == 2)
                {
                    o.setPosition(20+8,20+200+5+200+5+8);
                    window.draw(o);
                }
                if(plansza[2][1] == 2)
                {
                    o.setPosition(20+200+5+8,20+200+5+200+5+8);
                    window.draw(o);
                }
                if(plansza[2][2] == 2)
                {
                    o.setPosition(20+200+5+200+5+8,20+200+5+200+5+8);
                    window.draw(o);
                }
}

                // RYSOWANIE PLANSZY
                window.draw(ll);
                window.draw(lll);
                window.draw(llll);
                window.draw(lllll);
                window.display();
                // SPRAWDZANIE ZWYCIEZCY
{
                if (plansza[0][0] != 0 && plansza[0][1] != 0 && plansza[0][2] != 0 && plansza[1][0] != 0 && plansza[1][2] != 0 && plansza[1][1] != 0 && plansza[2][0] != 0 && plansza[2][1] != 0 && plansza[2][2] != 0)
                {
                    Sleep(1000);
                    main_opperand = 3;
                    window.close();
                }
                if(plansza[0][0] == plansza[0][1] && plansza[0][0] == plansza [0][2] && plansza[0][0] != 0)
                {
                    Sleep(1000);
                    if(player)
                    {
                        main_opperand = 1;
                    }else{
                        main_opperand = 2;
                    }
                window.close();
                }
                if(plansza[1][0] == plansza[1][1] && plansza[1][0] == plansza [1][2] && plansza[1][0] != 0)
                {
                    Sleep(1000);
                    if(player)
                    {
                        main_opperand = 1;
                    }else{
                        main_opperand = 2;
                    }
                window.close();
                }
                if(plansza[2][0] == plansza[2][1] && plansza[2][0] == plansza [2][2] && plansza[2][0] != 0)
                {
                    Sleep(1000);
                    if(player)
                    {
                        main_opperand = 1;
                    }else{
                        main_opperand = 2;
                    }
                window.close();
                }
                if(plansza[0][0] == plansza[1][0] && plansza[1][0] == plansza [2][0] && plansza[0][0] != 0)
                {
                    Sleep(1000);
                    if(player)
                    {
                        main_opperand = 1;
                    }else{
                        main_opperand = 2;
                    }
                window.close();
                }
                if(plansza[0][1] == plansza[1][1] && plansza[1][1] == plansza [2][1] && plansza[0][1] != 0)
                {
                    Sleep(1000);
                    if(player)
                    {
                        main_opperand = 1;
                    }else{
                        main_opperand = 2;
                    }
                window.close();
                }
                if(plansza[0][2] == plansza[1][2] && plansza[1][2] == plansza [2][2] && plansza[0][2] != 0)
                {
                    Sleep(1000);
                    if(player)
                    {
                        main_opperand = 1;
                    }else{
                        main_opperand = 2;
                    }
                window.close();
                }
                if(plansza[0][0] == plansza[1][1] && plansza[1][1] == plansza [2][2] && plansza[2][2] != 0)
                {
                    Sleep(1000);
                    if(player)
                    {
                        main_opperand = 1;
                    }else{
                        main_opperand = 2;
                    }
                window.close();
                }
                if(plansza[2][0] == plansza[1][1] && plansza[1][1] == plansza [0][2] && plansza[0][2] != 0)
                {
                    Sleep(1000);
                    if(player)
                    {
                        main_opperand = 1;
                    }else{
                        main_opperand = 2;
                    }
                window.close();
                }
                if(main_opperand == 5)
                    window.close();
                }
}
        }

    }


    return 0;
}
