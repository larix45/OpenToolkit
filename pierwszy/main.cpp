
    if(i0 == 3) //ZADANIE 3
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);//KOLOR
        unsigned short i1;
        int i2;
        bool passed = false;//SPRAWDZENIE POPRAWNOSCI DANYCH
        while(!passed)
        {
            std::cout << "Podaj ocene ucznia(1-6): ";
            std::cin >> i1;
            if(i1 < 7 && i1 > 0)
                passed = true;
            else
                std::cout << "PODAJ LICZBE Z PRZEDZIALU 1-6\n";
        }
        passed = false;//SPRAWDZENIE POPRAWNOSCI DANYCH
        while(!passed)
        {
            std::cout << "Podaj wynik ucznia z egzamiu w procentach: ";
            std::cin >> i2;
            if(i2 < 101 && i2 > -1)
                passed = true;
            else
                std::cout << "PODAJ LICZBE Z PRZEDZIALU 0-100\n";

        }
        if(i1 >= 5 || i2 >= 90)
            std::cout << "grupa zaawansowana";
        else
            std::cout << "grupa podstawowa";

    } else
    if(i0 == 4)//ZADANIE 4
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);//KOLOR
        double h,r;
        std::cout << "Podaj promien podstawy walca: ";
        std::cin >> r;

        std::cout << "Podaj wysokosc walca: ";
        std::cin >> h;
        if(h < 0 || r < 0)
        {
            std::cout << "bledne dane\n";
            goto start;//POWROT NA START
        }
        double v = h * M_PI * pow(r,2);
        std::cout << "Objetosc walca jest rowna " << v;

    } else
    {
        std::cout << "wprowadz liczbe od 1 do 4 \n";
        goto start;//POWROT NA START
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);//KOLOR
    return 0;
}
