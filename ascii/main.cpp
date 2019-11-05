#include <iostream>

int main()
{
    char ascii[256];
    for(size_t i=1; i< 256; i++)
    {
        ascii[i] = i;
    }
    for(size_t i=1; i< 256; i++)
    {
        if(i <= 10)
            std::cout << "  "<< i  << ": " << ascii[i] << "      ";
        if(i > 10 && i < 100)
            std::cout << " " << i  <<": "<< ascii[i] <<"      ";
        if(i >= 100)
            std::cout << i  <<": "<< ascii[i] <<"      ";
        if(i % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << "13"  <<": "<< ascii[13] <<"      ";
    int sizer[2] = {0,1};
    for(size_t i=1; i< 256; i++)
    {
        sizer[0]++;
        std::cout << ascii[i];
        if(sizer[0] == sizer[1])
        {
            sizer[1]++;
            sizer[0] = 0;
            std::cout << std::endl;
        }
    }
    return 0;
}
