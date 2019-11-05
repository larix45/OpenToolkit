#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <sstream>


void log(std::string dd)
{
    std::cout << "LOG: " << dd << std::endl;
}
void log(int dd)
{
    std::cout << "LOG: " << dd << std::endl;
}

/*
BUTTON
LABEL
IMAGEBOX
CHECKBOX
PROGRESSBAR
TEXTEDIT

*/
namespace sg
{
    class Save
    {
        std::fstream file;
        std::string path;
        std::vector<std::string> vector1;

    public:
        Save(std::string s)
        {
            path = s;
        }
        void add(std::string c)
        {
            vector1.push_back(c);
        }
        std::string get()
        {
            std::string ss = vector1.back();
            vector1.pop_back();
            return ss;

        }
        bool makeSave()
        {
            file.open( path.c_str(), std::ios::out  | std::ios::trunc );
            if( file.good() == true )
            {
                log("File save is good.");
                for(size_t i = 0; i <= vector1.size() -1; i++)
                {
                    file << vector1[i] << std::endl;
                }


            } else
            {
                log("No acces granted! ");
                return false;
            }
            file.close();
            return true;
        }
        bool readSave()
        {
            file.open( path.c_str(), std::ios::in | std::ios::out );
            if( file.good() == true )
            {
                log("File save is good.");
                vector1.clear();
                std::string buf;

                while(!file.eof())
                {
                    getline(file, buf);
                    vector1.push_back(buf);
                }
                vector1.pop_back();
            } else
            {
                log("No acces granted! ");
                return false;
            }
            file.close();
            return true;
        }

    };
    class ImageBox
    {
        public:
            sf::Sprite rect;
            std::string path;
            sf::Texture texture;



            ImageBox(std::string p,sf::Vector2f image_bar_position = sf::Vector2f(100,100), sf::Vector2f image_bar_scale = sf::Vector2f(1, 1))
            {
                path = p;

                rect.setPosition(image_bar_position);
                texture.loadFromFile(path);
                rect.setTexture(texture);
                rect.setScale(image_bar_scale);
            }
    // GET
            sf::Vector2f getPosition()
            {
                return rect.getPosition();
            }
            std::string getPath()
            {
                return path;
            }
    // SET
            void setPosition(sf::Vector2f position)
            {
                rect.setPosition(position);
            }
            void setPosition(unsigned int position_x, unsigned int position_y)
            {
                rect.setPosition(position_x, position_y);
            }
            void setPath(std::string p)
            {
                path = p;
            }

    // SPECIALS
            void draw(sf::RenderWindow &window)
            {
                window.draw(rect);
            }

    };
    class Slider
    {
        public:
            sf::RectangleShape rect;
            sf::RectangleShape sign1;
            sf::RectangleShape line1;
            bool hv;





            Slider(sf::Vector2f slider_position = sf::Vector2f(100,100),float prog = 100 , sf::Vector2f slider_size = sf::Vector2f(100, 30),
                    sf::Color slider_color = sf::Color(100,10,10),  sf::Color slider_border_color = sf::Color(100,100,100), int slider_border_thickness = 0)
            {
                rect.setPosition(slider_position);
                rect.setSize(slider_size);
                rect.setFillColor(slider_color);
                rect.setOutlineColor(slider_border_color);
                rect.setOutlineThickness(slider_border_thickness);

                line1.setSize(sf::Vector2f(rect.getSize().x * 0.8, rect.getSize().y/10));
                line1.setPosition(sf::Vector2f(slider_position.x + slider_size.x * 0.1 ,slider_position.y + slider_size.y/2 - slider_size.y/10));
                line1.setFillColor(sf::Color(0,0,0));


                sign1.setSize(sf::Vector2f(slider_size.x /8, slider_size.y/3));
                sign1.setOrigin(sf::Vector2f((sign1.getSize().x)/2, (sign1.getSize().y)/2));
                sign1.setPosition(sf::Vector2f(line1.getPosition().x + (line1.getSize().x /100 * prog),slider_position.y + slider_size.y/2  ));
                sign1.setFillColor(sf::Color(0,0,100));
                hv = false;
            }
    // GET
            sf::Vector2f getPosition()
            {
                return rect.getPosition();
            }
            float getProgress()
            {
                // (sign1.getPosition().x - rect.getPosition().x  - rect.getSize().x * 0.1) POZYCJA Sign1 WZGLEDEM POCZATKU Rect'a
                return (sign1.getPosition().x - line1.getPosition().x )* 1.25;// - rect.getSize().x ;
            }
    // SET
            void setProgress(float prog)
            {
                sign1.setPosition(sf::Vector2f(line1.getPosition().x + (line1.getSize().x /100 * prog), sign1.getPosition().y));
            }
            void setPosition(sf::Vector2f position)
            {
                rect.setPosition(position);
            }
            void setPosition(unsigned int position_x, unsigned int position_y)
            {
                rect.setPosition(position_x, position_y);
            }


    // SPECIALS
            void draw(sf::RenderWindow &window)
            {
                window.draw(rect);
                window.draw(line1);
                window.draw(sign1);
            }
            bool isHovered(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y)
                    return true;
                else
                    return false;
            }
            bool isClicked(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    return true;
                else
                    return false;
            }
            bool isClickedRight(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Right))
                    return true;
                else
                    return false;
            }
            void run(sf::RenderWindow &window)
            {
                if(hv)
                {
                    sign1.setPosition(sf::Mouse::getPosition(window).x, sign1.getPosition().y);
                }
                hv = false;
                if(this -> isClicked(window))
                {
                    hv = true;
                }
                if(sign1.getPosition().x  <= line1.getPosition().x)
                {
                    sign1.setPosition(line1.getPosition().x, sign1.getPosition().y);
                }
                if(sign1.getPosition().x  >= line1.getPosition().x + line1.getSize().x)
                {
                    sign1.setPosition(line1.getPosition().x + line1.getSize().x, sign1.getPosition().y);
                }
            }
    } ;

    class CheckBox
    {
        public:
            sf::RectangleShape rect;
            sf::RectangleShape sign1;
            sf::RectangleShape sign2;
            bool checked;





            CheckBox(sf::Vector2f check_position = sf::Vector2f(100,100),bool ch = false, sf::Vector2f check_size = sf::Vector2f(10, 10),
                    sf::Color check_color = sf::Color(100,10,10),  sf::Color check_border_color = sf::Color(100,100,100), int check_border_thickness = 0)
            {
                rect.setPosition(check_position);
                rect.setSize(check_size);
                rect.setFillColor(check_color);
                rect.setOutlineColor(check_border_color);
                rect.setOutlineThickness(check_border_thickness);
                sign1.setFillColor(sf::Color(1,1,1));
                sign1.setPosition(check_position.x + (check_size.x / 4),check_position.y + (check_size.y / 4));
                sign1.setSize(sf::Vector2f(check_size.x /2,check_size.y /2));
                sign1.setOutlineColor(check_border_color);
                sign1.setOutlineThickness(0);
                checked = ch;
            }
    // GET
            sf::Vector2f getPosition()
            {
                return rect.getPosition();
            }
    // SET
            void setPosition(sf::Vector2f position)
            {
                rect.setPosition(position);
                sign1.setPosition(position);
            }
            void setPosition(unsigned int position_x, unsigned int position_y)
            {
                rect.setPosition(position_x, position_y);
                sign1.setPosition(position_x, position_y);
            }
            void setCheck(bool c = true)
            {
                checked = c;
            }
    // SPECIALS
            void draw(sf::RenderWindow &window)
            {
                window.draw(rect);
                if(checked)
                {
                    window.draw(sign1);
                }
                else
                {
                    window.draw(sign2);
                }
            }
            bool isHovered(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y)
                    return true;
                else
                    return false;
            }
            bool isClicked(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    return true;
                else
                    return false;
            }
            bool isClickedRight(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Right))
                    return true;
                else
                    return false;
            }
            void run(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    Sleep(200);
                    checked = !checked;
                }

            }
    } ;
    class ProgressBar
    {
        public:
            sf::RectangleShape rect;
            sf::RectangleShape sign1;
            float progress;



            ProgressBar(sf::Vector2f progress_bar_position = sf::Vector2f(100,100),float prog = 0, sf::Vector2f progress_bar_size = sf::Vector2f(100, 10),
                    sf::Color progress_bar_color = sf::Color(100,10,10), sf::Color progress_bar_border_color = sf::Color(100,100,100), sf::Color progress_bar_fill_color = sf::Color(100,100,100),
                    int progress_bar_border_thickness = 1)
            {
                progress = prog;

                rect.setPosition(progress_bar_position);
                rect.setSize(progress_bar_size);
                rect.setFillColor(progress_bar_color);
                rect.setOutlineColor(progress_bar_border_color);
                rect.setOutlineThickness(progress_bar_border_thickness);

                sign1.setFillColor(progress_bar_fill_color);
                sign1.setPosition(progress_bar_position.x, progress_bar_position.y);
                sign1.setSize(sf::Vector2f(progress*progress_bar_size.x/100,progress_bar_size.y));
                sign1.setOutlineColor(progress_bar_border_color);
                sign1.setOutlineThickness(0);

            }
    // GET
            sf::Vector2f getPosition()
            {
                return rect.getPosition();
            }
            float getProgress()
            {
                return progress;
            }
    // SET
            void setPosition(sf::Vector2f position)
            {
                rect.setPosition(position);
                sign1.setPosition(position);
            }
            void setPosition(unsigned int position_x, unsigned int position_y)
            {
                rect.setPosition(position_x, position_y);
                sign1.setPosition(position_x, position_y);
            }

            void setProgress(float prog)
            {
                if(prog <= 100)
                {
                    progress = prog;
                    sign1.setSize(sf::Vector2f(progress*rect.getSize().x/100,rect.getSize().y));
                }else
                {
                    log("PROGRESS MUST BE LESS THAN 100");
                }
            }

    // SPECIALS
            void draw(sf::RenderWindow &window)
            {
                window.draw(rect);
                window.draw(sign1);
            }
            bool isHovered(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y)
                    return true;
                else
                    return false;
            }
            bool isClicked(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    return true;
                else
                    return false;
            }
            bool isClickedRight(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Right))
                    return true;
                else
                    return false;
            }

    } ;
    class TextEdit
    {
        public:
            sf::Font font;
            sf::Text text;
            sf::RectangleShape rect;
            std::string message;


            TextEdit(sf::Vector2f edit_position = sf::Vector2f(100,100), std::string message = "OK", sf::Vector2f edit_size = sf::Vector2f(100, 50), unsigned int text_size = 20,
                    sf::Color edit_color = sf::Color(100,10,10), sf::Color text_color = sf::Color(100,100,200), sf::Color edit_border_color = sf::Color(100,100,100),
                    sf::Color text_border_color = sf::Color(10,10,20), int edit_border_thickness = 3, int text_border_thickness = 1, std::string font_path = "./arial.ttf")
            {
                font.loadFromFile(font_path);

                rect.setPosition(edit_position);
                rect.setSize(edit_size);
                rect.setFillColor(edit_color);
                rect.setOutlineColor(edit_border_color);
                rect.setOutlineThickness(edit_border_thickness);

                text.setCharacterSize(text_size);
                text.setString(message);
                text.setFont(font);
                text.setOrigin((text_size/ 3 * message.length() ), (text_size/2));
                text.setPosition(edit_position.x + (edit_size.x / 2), edit_position.y + (edit_size.y / 2));
                text.setFillColor(text_color);
                text.setOutlineColor(text_border_color);
                text.setOutlineThickness(text_border_thickness);

            }
    // GET
            std::string getString()
            {
                return text.getString();
            }
            int getCharacterSize()
            {
                return text.getCharacterSize();
            }
            sf::Vector2f getPosition()
            {
                return rect.getPosition();
            }
    // SET
            void setString(std::string new_message = "NULL")
            {
                text.setString(new_message);
                text.setOrigin((text.getCharacterSize()/ 3 * new_message.length() ), (text.getCharacterSize()/2));
                message = new_message;
            }
            void setCharacterSize(int c)
            {
                text.setCharacterSize(c);
                text.setOrigin((text.getCharacterSize()/ 3 * message.length() ), (text.getCharacterSize()/2));
                text.setPosition(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));
            }
            void setPosition(sf::Vector2f position)
            {
                rect.setPosition(position);
                text.setPosition(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));
            }
            void setPosition(unsigned int position_x, unsigned int position_y)
            {
                rect.setPosition(position_x, position_y);
                text.setPosition(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));
            }



    // SPECIALS
            void draw(sf::RenderWindow &window)
            {
                window.draw(rect);
                window.draw(text);
            }
            void run()
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && message.length() != 0)
                    message.erase(message.length() - 1, 1);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  )
                    message += "-";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  )
                    message += "=";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  )
                    message += "[";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  )
                    message += "]";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSlash) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  )
                    message += "\\";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  )
                    message += ";";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  )
                    message += "'";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  )
                    message += ",";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  )
                    message += ".";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  )
                    message += "/";


                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract) &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))  )
                    message += "_";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add) &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))  )
                    message += "+";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket) &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))  )
                    message += "{";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)&&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "}";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSlash) &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "|";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon) &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += ":";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote) &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))  )
                    message += "\"";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma) &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "<";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period) &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += ">";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash)&&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "?";




                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)  )
                    message += "q";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "w";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "e";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "r";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "t";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "y";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "u";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "i";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "o";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "p";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "a";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "s";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "d";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "f";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "g";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "h";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "j";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "k";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "l";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "z";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "x";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "c";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "v";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "b";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "n";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "m";

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))  )
                    message += "Q";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "W";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "E";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "R";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "T";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "Y";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "U";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "I";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "O";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "P";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "A";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "S";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "D";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "F";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "G";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "H";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "J";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "K";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "L";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "Z";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "X";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "C";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "V";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "B";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "N";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)  &&  (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) )
                    message += "M";



                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "0";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "1";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "2";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "3";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "4";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "5";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "6";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "7";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "8";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) &&  !sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) && !sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) )
                    message += "9";

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) && ( sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
                    message += ")";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && ( sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
                    message += "!";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && ( sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
                    message += "@";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && ( sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
                    message += "#";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && ( sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
                    message += "$";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && ( sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
                    message += "%";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && ( sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
                    message += "^";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && ( sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
                    message += "&";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && ( sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
                    message += "*";
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && ( sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
                    message += "(";
                Sleep(90);


                text.setString(message);
                text.setOrigin((text.getCharacterSize()/ 3 * message.length() ), (text.getCharacterSize()/2));
                text.setPosition(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));

            }
            bool isHovered(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y)
                    return true;
                else
                    return false;
            }
            bool isClicked(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    return true;
                else
                    return false;
            }
            bool isClickedRight(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Right))
                    return true;
                else
                    return false;
            }
    };
    class Label
    {
        public:
            sf::Font font;
            sf::Text text;
            sf::RectangleShape rect;
            std::string message;

            Label(sf::Vector2f label_position = sf::Vector2f(100,100), std::string message = "OK", sf::Vector2f label_size = sf::Vector2f(100, 50), unsigned int text_size = 20,
                    sf::Color label_color = sf::Color(100,10,10), sf::Color text_color = sf::Color(100,100,200), sf::Color label_border_color = sf::Color(100,100,100),
                    sf::Color text_border_color = sf::Color(10,10,20), int label_border_thickness = 3, int text_border_thickness = 1, std::string font_path = "./arial.ttf")
            {
                font.loadFromFile(font_path);

                rect.setPosition(label_position);
                rect.setSize(label_size);
                rect.setFillColor(label_color);
                rect.setOutlineColor(label_border_color);
                rect.setOutlineThickness(label_border_thickness);

                text.setCharacterSize(text_size);
                text.setString(message);
                text.setFont(font);
                text.setOrigin((text_size/ 3 * message.length() ), (text_size/2));
                text.setPosition(label_position.x + (label_size.x / 2), label_position.y + (label_size.y / 2));
                text.setFillColor(text_color);
                text.setOutlineColor(text_border_color);
                text.setOutlineThickness(text_border_thickness);
            }
    // GET
            std::string getString()
            {
                return text.getString();
            }
            int getCharacterSize()
            {
                return text.getCharacterSize();
            }
            sf::Vector2f getPosition()
            {
                return rect.getPosition();
            }
    // SET
            void setString(std::string new_message = "NULL")
            {
                text.setString(new_message);
                text.setOrigin((text.getCharacterSize()/ 3 * new_message.length() ), (text.getCharacterSize()/2));
                message = new_message;
            }
            void setCharacterSize(int c)
            {
                text.setCharacterSize(c);
                text.setOrigin((text.getCharacterSize()/ 3 * message.length() ), (text.getCharacterSize()/2));
                text.setPosition(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));
            }
            void setPosition(sf::Vector2f position)
            {
                rect.setPosition(position);
                text.setPosition(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));
            }
            void setPosition(unsigned int position_x, unsigned int position_y)
            {
                rect.setPosition(position_x, position_y);
                text.setPosition(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));
            }



    // SPECIALS
            void draw(sf::RenderWindow &window)
            {
                window.draw(rect);
                window.draw(text);
            }
    };
    class Button
    {
        public:
            sf::Font font;
            sf::Text text;
            sf::RectangleShape rect;
            std::string message;

            Button(sf::Vector2f button_position = sf::Vector2f(100,100), std::string message = "OK", sf::Vector2f button_size = sf::Vector2f(100, 50), unsigned int text_size = 20,
                    sf::Color button_color = sf::Color(100,10,10), sf::Color text_color = sf::Color(100,100,200), sf::Color button_border_color = sf::Color(100,100,100),
                    sf::Color text_border_color = sf::Color(10,10,20), int button_border_thickness = 3, int text_border_thickness = 1, std::string font_path = "./arial.ttf")
            {
                font.loadFromFile(font_path);

                rect.setPosition(button_position);
                rect.setSize(button_size);
                rect.setFillColor(button_color);
                rect.setOutlineColor(button_border_color);
                rect.setOutlineThickness(button_border_thickness);

                text.setCharacterSize(text_size);
                text.setString(message);
                text.setFont(font);
                text.setOrigin((text_size/ 3 * message.length() ), (text_size/2));
                text.setPosition(button_position.x + (button_size.x / 2), button_position.y + (button_size.y / 2));
                text.setFillColor(text_color);
                text.setOutlineColor(text_border_color);
                text.setOutlineThickness(text_border_thickness);
            }
    // GET
            std::string getString()
            {
                return text.getString();
            }
            int getCharacterSize()
            {
                return text.getCharacterSize();
            }
            sf::Vector2f getPosition()
            {
                return rect.getPosition();
            }
    // SET
            void setString(std::string new_message = "NULL")
            {
                text.setString(new_message);
                text.setOrigin((text.getCharacterSize()/ 3 * new_message.length() ), (text.getCharacterSize()/2));
                message = new_message;
            }
            void setCharacterSize(int c)
            {
                text.setCharacterSize(c);
                text.setOrigin((text.getCharacterSize()/ 3 * message.length() ), (text.getCharacterSize()/2));
                text.setPosition(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));
            }
            void setPosition(sf::Vector2f position)
            {
                rect.setPosition(position);
                text.setPosition(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));
            }
            void setPosition(unsigned int position_x, unsigned int position_y)
            {
                rect.setPosition(position_x, position_y);
                text.setPosition(rect.getPosition().x + (rect.getSize().x / 2), rect.getPosition().y + (rect.getSize().y / 2));
            }


    // SPECIALS
            void draw(sf::RenderWindow &window)
            {
                window.draw(rect);
                window.draw(text);
            }
            bool isHovered(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y)
                    return true;
                else
                    return false;
            }
            bool isClicked(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    return true;
                else
                    return false;
            }
            bool isClickedRight(sf::RenderWindow &window)
            {
                if (sf::Mouse::getPosition(window).x >= rect.getPosition().x &&
                     sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition(window).y >= rect.getPosition().y &&
                     sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getSize().y &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Right))
                    return true;
                else
                    return false;
            }
            /*bool isHovered()
            {
                if (sf::Mouse::getPosition().x >= rect.getPosition().x &&
                     sf::Mouse::getPosition().x <= rect.getPosition().x + rect.getSize().x &&
                     sf::Mouse::getPosition().y >= rect.getPosition().y &&
                     sf::Mouse::getPosition().y <= rect.getPosition().y + rect.getSize().y)
                    return true;
                else
                    return false;
            }*/
    };
    enum messageWindowButtonType
    {
        NULL_BUTTON,           // nothing
        OK_BUTTON,             // ok button
        CANCEL_BUTTON,         // cancel button
        BACK_BUTTON,           // back button
        NEXT_BUTTON,           // next button
        YES_BUTTON,            // yes button
        NO_BUTTON,             // no button
        GREEN_BUTTON,          //green button without text
        RED_BUTTON,            //red button without text
        BLUE_BUTTON,           //blue button without text
        YELLOW_BUTTON,         //yellow button without text
        EMPTY_BUTTON,          //empty button (white)
        CUSTOM_BUTTON          //yellow button with text

    };
    messageWindowButtonType messageWindow(messageWindowButtonType o1,messageWindowButtonType o2,messageWindowButtonType o3,messageWindowButtonType o4, std::string title = "Message!",  std::string message = "ERROR", std::string button_message = "OK",
                         sf::Color background_color = sf::Color(100,10,10), sf::Color button_color = sf::Color(100,10,10), sf::Color text_color = sf::Color(100,100,200), sf::Color button_border_color = sf::Color(100,100,100),
                         sf::Color text_border_color = sf::Color(10,10,20), int button_border_thickness = 3, int text_border_thickness = 1, bool efect = true, std::string font_path = "./arial.ttf")
    {

        Button b1(sf::Vector2f(10,300-60-10),"KK",sf::Vector2f(100,60),20,button_color,text_color,button_border_color,text_border_color,button_border_thickness,text_border_thickness,font_path);
        Button b2(sf::Vector2f(10+100+20,300-60-10),"KK",sf::Vector2f(100,60),20,button_color,text_color,button_border_color,text_border_color,button_border_thickness,text_border_thickness,font_path);
        Button b3(sf::Vector2f(10+100+20+100+40,300-60-10),"KK",sf::Vector2f(100,60),20,button_color,text_color,button_border_color,text_border_color,button_border_thickness,text_border_thickness,font_path);
        Button b4(sf::Vector2f(10+100+20+100+40+100+20,300-60-10),"KK",sf::Vector2f(100,60),20,button_color,text_color,button_border_color,text_border_color,button_border_thickness,text_border_thickness,font_path);
        sf::RenderWindow message_box(sf::VideoMode(500,300),title);
        Label l1(sf::Vector2f(30,40),message,sf::Vector2f(420,80),40,sf::Color(1,1,1,0),sf::Color(0,0,0),sf::Color(0,0,0,0),sf::Color(0,0,0,0),0,4,font_path);
        message_box.clear(background_color);
    {
        if (o1 == CUSTOM_BUTTON)
        {
            b1.setString(button_message);
            b1.rect.setFillColor(button_color);
            b1.text.setFillColor(text_color);
            b1.rect.setOutlineColor(button_border_color);
            b1.text.setOutlineColor(text_border_color);
            b1.rect.setOutlineThickness(button_border_thickness);
            b1.text.setOutlineThickness(text_border_thickness);
            b1.font.loadFromFile(font_path);
        }
        if (o1 == OK_BUTTON)
        {
            b1.setString("OK");
            b1.rect.setFillColor(sf::Color(200,200,200));
            b1.text.setFillColor(sf::Color(0,0,0));
            b1.rect.setOutlineColor(sf::Color(100,100,100));
            b1.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o1 == EMPTY_BUTTON)
        {
            b1.setString("");
            b1.rect.setFillColor(sf::Color(200,200,200));
            b1.text.setFillColor(sf::Color(0,0,0));
            b1.rect.setOutlineColor(sf::Color(100,100,100));
            b1.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o1 == CANCEL_BUTTON)
        {
            b1.setString("CANCEL");
            b1.rect.setFillColor(sf::Color(200,200,200));
            b1.text.setFillColor(sf::Color(0,0,0));
            b1.rect.setOutlineColor(sf::Color(100,100,100));
            b1.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o1 == BACK_BUTTON)
        {
            b1.setString("BACK");
            b1.rect.setFillColor(sf::Color(200,200,200));
            b1.text.setFillColor(sf::Color(0,0,0));
            b1.rect.setOutlineColor(sf::Color(100,100,100));
            b1.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o1 == NEXT_BUTTON)
        {
            b1.setString("NEXT");
            b1.rect.setFillColor(sf::Color(200,200,200));
            b1.text.setFillColor(sf::Color(0,0,0));
            b1.rect.setOutlineColor(sf::Color(100,100,100));
            b1.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o1 == YES_BUTTON)
        {
            b1.setString("YES");
            b1.rect.setFillColor(sf::Color(200,200,200));
            b1.text.setFillColor(sf::Color(0,0,0));
            b1.rect.setOutlineColor(sf::Color(100,100,100));
            b1.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o1 == NO_BUTTON)
        {
            b1.setString("NO");
            b1.rect.setFillColor(sf::Color(200,200,200));
            b1.text.setFillColor(sf::Color(0,0,0));
            b1.rect.setOutlineColor(sf::Color(100,100,100));
            b1.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o1 == GREEN_BUTTON)
        {
            b1.setString("");
            b1.rect.setFillColor(sf::Color(100,200,60));
            b1.text.setFillColor(sf::Color(80,180,40));
            b1.rect.setOutlineColor(sf::Color(150,250,110));
            b1.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o1 == RED_BUTTON)
        {
            b1.setString("");
            b1.rect.setFillColor(sf::Color(200,50,50));
            b1.text.setFillColor(sf::Color(170,30,30));
            b1.rect.setOutlineColor(sf::Color(250,100,100));
            b1.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o1 == BLUE_BUTTON)
        {
            b1.setString("");
            b1.rect.setFillColor(sf::Color(50,100,240));
            b1.text.setFillColor(sf::Color(30,80,210));
            b1.rect.setOutlineColor(sf::Color(80,130,255));
            b1.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o1 == YELLOW_BUTTON)
        {
            b1.setString("");
            b1.rect.setFillColor(sf::Color(240,220,80));
            b1.text.setFillColor(sf::Color(220,200,60));
            b1.rect.setOutlineColor(sf::Color(255,255,160));
            b1.text.setOutlineColor(sf::Color(0,0,0));
        }





        if (o2 == CUSTOM_BUTTON)
        {
            b2.setString(button_message);
            b2.rect.setFillColor(button_color);
            b2.text.setFillColor(text_color);
            b2.rect.setOutlineColor(button_border_color);
            b2.text.setOutlineColor(text_border_color);
            b2.rect.setOutlineThickness(button_border_thickness);
            b2.text.setOutlineThickness(text_border_thickness);
            b2.font.loadFromFile(font_path);
        }
        if (o2 == OK_BUTTON)
        {
            b2.setString("OK");
            b2.rect.setFillColor(sf::Color(200,200,200));
            b2.text.setFillColor(sf::Color(0,0,0));
            b2.rect.setOutlineColor(sf::Color(100,100,100));
            b2.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o2 == EMPTY_BUTTON)
        {
            b2.setString("");
            b2.rect.setFillColor(sf::Color(200,200,200));
            b2.text.setFillColor(sf::Color(0,0,0));
            b2.rect.setOutlineColor(sf::Color(100,100,100));
            b2.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o2 == CANCEL_BUTTON)
        {
            b2.setString("CANCEL");
            b2.rect.setFillColor(sf::Color(200,200,200));
            b2.text.setFillColor(sf::Color(0,0,0));
            b2.rect.setOutlineColor(sf::Color(100,100,100));
            b2.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o2 == BACK_BUTTON)
        {
            b2.setString("BACK");
            b2.rect.setFillColor(sf::Color(200,200,200));
            b2.text.setFillColor(sf::Color(0,0,0));
            b2.rect.setOutlineColor(sf::Color(100,100,100));
            b2.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o2 == NEXT_BUTTON)
        {
            b2.setString("NEXT");
            b2.rect.setFillColor(sf::Color(200,200,200));
            b2.text.setFillColor(sf::Color(0,0,0));
            b2.rect.setOutlineColor(sf::Color(100,100,100));
            b2.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o2 == YES_BUTTON)
        {
            b2.setString("YES");
            b2.rect.setFillColor(sf::Color(200,200,200));
            b2.text.setFillColor(sf::Color(0,0,0));
            b2.rect.setOutlineColor(sf::Color(100,100,100));
            b2.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o2 == NO_BUTTON)
        {
            b2.setString("NO");
            b2.rect.setFillColor(sf::Color(200,200,200));
            b2.text.setFillColor(sf::Color(0,0,0));
            b2.rect.setOutlineColor(sf::Color(100,100,100));
            b2.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o2 == GREEN_BUTTON)
        {
            b2.setString("");
            b2.rect.setFillColor(sf::Color(100,200,60));
            b2.text.setFillColor(sf::Color(80,180,40));
            b2.rect.setOutlineColor(sf::Color(150,250,110));
            b2.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o2 == RED_BUTTON)
        {
            b2.setString("");
            b2.rect.setFillColor(sf::Color(200,50,50));
            b2.text.setFillColor(sf::Color(170,30,30));
            b2.rect.setOutlineColor(sf::Color(250,100,100));
            b2.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o2 == BLUE_BUTTON)
        {
            b2.setString("");
            b2.rect.setFillColor(sf::Color(50,100,240));
            b2.text.setFillColor(sf::Color(30,80,210));
            b2.rect.setOutlineColor(sf::Color(80,130,255));
            b2.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o2 == YELLOW_BUTTON)
        {
            b2.setString("");
            b2.rect.setFillColor(sf::Color(240,220,80));
            b2.text.setFillColor(sf::Color(220,200,60));
            b2.rect.setOutlineColor(sf::Color(255,255,160));
            b2.text.setOutlineColor(sf::Color(0,0,0));
        }






        if (o3 == CUSTOM_BUTTON)
        {
            b3.setString(button_message);
            b3.rect.setFillColor(button_color);
            b3.text.setFillColor(text_color);
            b3.rect.setOutlineColor(button_border_color);
            b3.text.setOutlineColor(text_border_color);
            b3.rect.setOutlineThickness(button_border_thickness);
            b3.text.setOutlineThickness(text_border_thickness);
            b3.font.loadFromFile(font_path);
        }
        if (o3 == OK_BUTTON)
        {
            b3.setString("OK");
            b3.rect.setFillColor(sf::Color(200,200,200));
            b3.text.setFillColor(sf::Color(0,0,0));
            b3.rect.setOutlineColor(sf::Color(100,100,100));
            b3.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o3 == EMPTY_BUTTON)
        {
            b3.setString("");
            b3.rect.setFillColor(sf::Color(200,200,200));
            b3.text.setFillColor(sf::Color(0,0,0));
            b3.rect.setOutlineColor(sf::Color(100,100,100));
            b3.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o3 == CANCEL_BUTTON)
        {
            b3.setString("CANCEL");
            b3.rect.setFillColor(sf::Color(200,200,200));
            b3.text.setFillColor(sf::Color(0,0,0));
            b3.rect.setOutlineColor(sf::Color(100,100,100));
            b3.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o3 == BACK_BUTTON)
        {
            b3.setString("BACK");
            b3.rect.setFillColor(sf::Color(200,200,200));
            b3.text.setFillColor(sf::Color(0,0,0));
            b3.rect.setOutlineColor(sf::Color(100,100,100));
            b3.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o3 == NEXT_BUTTON)
        {
            b3.setString("NEXT");
            b3.rect.setFillColor(sf::Color(200,200,200));
            b3.text.setFillColor(sf::Color(0,0,0));
            b3.rect.setOutlineColor(sf::Color(100,100,100));
            b3.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o3 == YES_BUTTON)
        {
            b3.setString("YES");
            b3.rect.setFillColor(sf::Color(200,200,200));
            b3.text.setFillColor(sf::Color(0,0,0));
            b3.rect.setOutlineColor(sf::Color(100,100,100));
            b3.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o3 == NO_BUTTON)
        {
            b3.setString("NO");
            b3.rect.setFillColor(sf::Color(200,200,200));
            b3.text.setFillColor(sf::Color(0,0,0));
            b3.rect.setOutlineColor(sf::Color(100,100,100));
            b3.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o3 == GREEN_BUTTON)
        {
            b3.setString("");
            b3.rect.setFillColor(sf::Color(100,200,60));
            b3.text.setFillColor(sf::Color(80,180,40));
            b3.rect.setOutlineColor(sf::Color(150,250,110));
            b3.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o3 == RED_BUTTON)
        {
            b3.setString("");
            b3.rect.setFillColor(sf::Color(200,50,50));
            b3.text.setFillColor(sf::Color(170,30,30));
            b3.rect.setOutlineColor(sf::Color(250,100,100));
            b3.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o3 == BLUE_BUTTON)
        {
            b3.setString("");
            b3.rect.setFillColor(sf::Color(50,100,240));
            b3.text.setFillColor(sf::Color(30,80,210));
            b3.rect.setOutlineColor(sf::Color(80,130,255));
            b3.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o3 == YELLOW_BUTTON)
        {
            b3.setString("");
            b3.rect.setFillColor(sf::Color(240,220,80));
            b3.text.setFillColor(sf::Color(220,200,60));
            b3.rect.setOutlineColor(sf::Color(255,255,160));
            b3.text.setOutlineColor(sf::Color(0,0,0));
        }



        if (o4 == CUSTOM_BUTTON)
        {
            b4.setString(button_message);
            b4.rect.setFillColor(button_color);
            b4.text.setFillColor(text_color);
            b4.rect.setOutlineColor(button_border_color);
            b4.text.setOutlineColor(text_border_color);
            b4.rect.setOutlineThickness(button_border_thickness);
            b4.text.setOutlineThickness(text_border_thickness);
            b4.font.loadFromFile(font_path);
        }
        if (o4 == OK_BUTTON)
        {
            b4.setString("OK");
            b4.rect.setFillColor(sf::Color(200,200,200));
            b4.text.setFillColor(sf::Color(0,0,0));
            b4.rect.setOutlineColor(sf::Color(100,100,100));
            b4.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o4 == EMPTY_BUTTON)
        {
            b4.setString("");
            b4.rect.setFillColor(sf::Color(200,200,200));
            b4.text.setFillColor(sf::Color(0,0,0));
            b4.rect.setOutlineColor(sf::Color(100,100,100));
            b4.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o4 == CANCEL_BUTTON)
        {
            b4.setString("CANCEL");
            b4.rect.setFillColor(sf::Color(200,200,200));
            b4.text.setFillColor(sf::Color(0,0,0));
            b4.rect.setOutlineColor(sf::Color(100,100,100));
            b4.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o4 == BACK_BUTTON)
        {
            b4.setString("BACK");
            b4.rect.setFillColor(sf::Color(200,200,200));
            b4.text.setFillColor(sf::Color(0,0,0));
            b4.rect.setOutlineColor(sf::Color(100,100,100));
            b4.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o4 == NEXT_BUTTON)
        {
            b4.setString("NEXT");
            b4.rect.setFillColor(sf::Color(200,200,200));
            b4.text.setFillColor(sf::Color(0,0,0));
            b4.rect.setOutlineColor(sf::Color(100,100,100));
            b4.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o4 == YES_BUTTON)
        {
            b4.setString("YES");
            b4.rect.setFillColor(sf::Color(200,200,200));
            b4.text.setFillColor(sf::Color(0,0,0));
            b4.rect.setOutlineColor(sf::Color(100,100,100));
            b4.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o4 == NO_BUTTON)
        {
            b4.setString("NO");
            b4.rect.setFillColor(sf::Color(200,200,200));
            b4.text.setFillColor(sf::Color(0,0,0));
            b4.rect.setOutlineColor(sf::Color(100,100,100));
            b4.text.setOutlineColor(sf::Color(50,50,50));
        }
        if (o4 == GREEN_BUTTON)
        {
            b4.setString("");
            b4.rect.setFillColor(sf::Color(100,200,60));
            b4.text.setFillColor(sf::Color(80,180,40));
            b4.rect.setOutlineColor(sf::Color(150,250,110));
            b4.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o4 == RED_BUTTON)
        {
            b4.setString("");
            b4.rect.setFillColor(sf::Color(200,50,50));
            b4.text.setFillColor(sf::Color(170,30,30));
            b4.rect.setOutlineColor(sf::Color(250,100,100));
            b4.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o4 == BLUE_BUTTON)
        {
            b4.setString("");
            b4.rect.setFillColor(sf::Color(50,100,240));
            b4.text.setFillColor(sf::Color(30,80,210));
            b4.rect.setOutlineColor(sf::Color(80,130,255));
            b4.text.setOutlineColor(sf::Color(0,0,0));
        }
        if (o4 == YELLOW_BUTTON)
        {
            b4.setString("");
            b4.rect.setFillColor(sf::Color(240,220,80));
            b4.text.setFillColor(sf::Color(220,200,60));
            b4.rect.setOutlineColor(sf::Color(255,255,160));
            b4.text.setOutlineColor(sf::Color(0,0,0));
        }

    }
        const sf::Color b1_fillcolor = b1.rect.getFillColor();
        const sf::Color b2_fillcolor = b2.rect.getFillColor();
        const sf::Color b3_fillcolor = b3.rect.getFillColor();
        const sf::Color b4_fillcolor = b4.rect.getFillColor();
        while(message_box.isOpen())
        {
            sf::Event event;
            while (message_box.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    message_box.close();
            }
            if(efect)
            {
                b1.rect.setFillColor(b1_fillcolor);
                b2.rect.setFillColor(b2_fillcolor);
                b3.rect.setFillColor(b3_fillcolor);
                b4.rect.setFillColor(b4_fillcolor);
                if (b1.isHovered(message_box))
                    b1.rect.setFillColor(sf::Color(b1_fillcolor.r - 30, b1_fillcolor.g - 30, b1_fillcolor.b - 30));
                if (b2.isHovered(message_box))
                    b2.rect.setFillColor(sf::Color(b2_fillcolor.r - 30, b2_fillcolor.g - 30, b2_fillcolor.b - 30));
                if (b3.isHovered(message_box))
                    b3.rect.setFillColor(sf::Color(b3_fillcolor.r - 30, b3_fillcolor.g - 30, b3_fillcolor.b - 30));
                if (b4.isHovered(message_box))
                    b4.rect.setFillColor(sf::Color(b4_fillcolor.r - 30, b4_fillcolor.g - 30, b4_fillcolor.b - 30));

                if (b1.isClicked(message_box))
                    return o1;
                if (b2.isClicked(message_box))
                    return o2;
                if (b3.isClicked(message_box))
                    return o3;
                if (b4.isClicked(message_box))
                    return o4;
            }

            if(o1 != NULL_BUTTON)
                b1.draw(message_box);
            if(o2 != NULL_BUTTON)
                b2.draw(message_box);
            if(o3 != NULL_BUTTON)
                b3.draw(message_box);
            if(o4 != NULL_BUTTON)
                b4.draw(message_box);
            l1.draw(message_box);
            message_box.display();
        }




    }
}

/*

int main()
{
    sg::Button b1(sf::Vector2f(100,100));



    sf::RenderWindow window(sf::VideoMode(400,800),"XD");
    sf::Event event;
    sg::Slider s1(sf::Vector2f(100,200), 30);
    //sg::Save newSaveGame("n.txt");
    //newSaveGame.add("fur"); newSaveGame.add("jkdl"); newSaveGame.add("112"); newSaveGame.makeSave();
    //newSaveGame.readSave();
    //log(newSaveGame.get());
    //log(newSaveGame.get());
    //log(newSaveGame.get());

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
                if(event.type ==  sf::Event::Closed)
                    window.close();

        }
        b1.rect.setFillColor(sf::Color(200,100,100));
        if(b1.isHovered(window))
        {
            b1.rect.setFillColor(sf::Color(100,200,100));
        }
        if(b1.isClicked(window))
        {
            window.close();
        }
        s1.run(window);

        b1.draw(window);
        s1.draw(window);
        std::cout << s1.getProgress();
        window.display();
    }
    return 0;
}*/







