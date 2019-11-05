#include <iostream>
#include <cstdlib>
#include <ctime>


int main()
{
    int u,bp,tp;
    std::cout << "Podaj ile liczb ma zostaæ porownanych: " ;
    std::cin >> u;
    std::cout << "Podaj zakres liczb: " <<  std::endl << "Dolna granica:" ;
    std::cin >> tp;
    std::cout << "  Gorna granica:";
    std::cin >> bp;

    int x[u],i,t = 0;
    srand(time(NULL));
    srand( u + (rand() % u) + (u-rand()) );
    std::cout << "Liczby wylosowane:   ";
    for (i=0;i<u;i++)
    {
        x[i]= (rand() % tp-bp)+bp;
        std::cout << "     " <<x[i];
        t++;
    }
    std::cout << std::endl << "Wylosowano " << t << " liczb."<< std::endl<< std::endl;
    t = 0;
    std::cout << std::endl << "Liczby parzyste:   ";
    for (i=0;i<u;i++)
    {
        if (x[i] % 2!=1)
        {
           std::cout << "    " <<x[i];
           t++;
        }
    }
    std::cout << std::endl << "Wylosowano " << t << " liczb parzystych."<< std::endl<< std::endl;
    t = 0;
    std::cout << std::endl << "Liczby nie parzyste:   ";
    for (i=0;i<u;i++)
    {
        if (x[i] % 2==1)
        {
           std::cout << "    " <<x[i];
           t++;
        }
    }
    std::cout << std::endl << "Wylosowano " << t << " liczb nie parzystych."<< std::endl<< std::endl;
    t = 0;
    std::cout << std::endl << "Liczby podzielne przez 3:   ";
    for (i=0;i<u;i++)
    {
        if (x[i] % 3==0)
        {
           std::cout << "    " <<x[i];
           t++;
        }
    }
    std::cout << std::endl << "Wylosowano " << t << " liczb podzielnych przez 3"<< std::endl<< std::endl;
    return 0;
}
