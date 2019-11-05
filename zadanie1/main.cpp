#include <iostream>
#include <windows.h>


int main()
{
    HANDLE bOut = GetStdHandle(STD_OUTPUT_HANDLE);

    int input_001;
    std::string input_002;
    while(input_002 != "close")
    {
        SetConsoleTextAttribute(bOut, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        std::cin >> input_002;
        if(input_002 == "close")
        {
            SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
            exit(0);
        }
        bool good = true;
        for(size_t i = 0; i < input_002.length(); i++)
            if(!(input_002.at(i) == '1' || input_002.at(i) == '2' || input_002.at(i) == '3' || input_002.at(i) == '4' || input_002.at(i) == '5' ||
                 input_002.at(i) == '6' || input_002.at(i) == '7' || input_002.at(i) == '8' || input_002.at(i) == '9' || input_002.at(i) == '0' ||
                 input_002.at(i) == '-' ))
                good = false;
            if(good)
            {
                input_001 = atoi(input_002.c_str());
                SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << char(192) << char(196) << char(62)<< input_001 << "          ";
                SetConsoleTextAttribute(bOut, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                if(input_001 < 0)
                    std::cout << "- ";
                else
                if(input_001 > 0)
                    std::cout << "+ ";
                else
                if(input_001 == 0)
                    std::cout << "0 ";
                SetConsoleTextAttribute(bOut, FOREGROUND_RED|FOREGROUND_INTENSITY);
                if(input_001 != 0)
                    if(input_001 % 2 == 0)
                        std::cout << "p" << std::endl;
                    else
                        std::cout << "np" << std::endl;
            }
            else
                std::cout << "WPISZ LICZBE. WPISZ \"close\" ABY ZAKONCZYC" << std::endl;

    }
    SetConsoleTextAttribute(bOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    return 0;
}
