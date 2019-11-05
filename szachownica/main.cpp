#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int g;
pon:
    cout << "Styl szachownicy (1-3)";
    cin >> g;
    if( !cin )
    {
        cin.clear();
        cin.sync();
        cout << "Podaj liczbe!" << std::endl;
        goto pon;
    }

if (g == 1)
    {
    bool b;
    b = true;
    int x,y;
   aponx:
    cout << "Podaj szerokosc szachownicy: ";
    cin >> x;
    if( !cin )
        {
            cin.clear();
            cin.sync();
            cout << "Podaj liczbe!" << std::endl;
            goto aponx;
    }
   apony:
    cout << "Podaj dlugosc szachownicy: ";
    cin >> y;
    if (!cin)
    {
        cin.clear();
        cin.sync();
        cout << "Podaj liczbe!" << endl;
        goto apony;
    }

    //ramka
    cout << char(201);
    for (int i = 0;i<x;i++)
    {
        cout << char(205) << char(205);
    }
    cout << char(187)<< endl;



    //srodek
    for (int i = 0;i<y;i++)
    {
        if (b == true)
        {
            cout << char(186);
            for (int i = 0;i<(x/2);i++)
            {
                cout << char(219) << char(219)<<char(255) << char(255);
            }
            if (x % 2 == 1)
            {
               cout << char(219) << char(219);
            }
            cout << char(186);
            b = false;
        }
        else
        if (b == false)
        {
            cout << char(186);
            for (int i = 0;i<(x/2);i++)
            {
                cout  << char(255) << char(255)<<char(219) << char(219);
            }
            if (x % 2 == 1)
            {
               cout << char(255) << char(255);
            }
            cout << char(186);
            b = true;
        }
        cout << endl;

    }

    //ramka dol
    cout << char(200);
    for (int i = 0;i<x;i++)
    {
        cout << char(205) << char(205);
    }
    cout << char(188)<< endl;

    system("pause");
}
if (g == 2)
{
    bool b;
    b = true;
    int x,y;
   bponx:
    cout << "Podaj szerokosc szachownicy: ";
    cin >> x;
    if( !cin )
        {
            cin.clear();
            cin.sync();
            cout << "Podaj liczbe!" << std::endl;
            goto bponx;
    }
   bpony:
    cout << "Podaj dlugosc szachownicy: ";
    cin >> y;
    if (!cin)
    {
        cin.clear();
        cin.sync();
        cout << "Podaj liczbe!" << endl;
        goto bpony;
    }

    //ramka
    cout << char(201);
    for (int i = 0;i<x;i++)
    {
        cout << char(65+i) << char(205);
    }
    cout << char(187)<< endl;



    //srodek
    for (int i = 0;i<y;i++)
    {
        if (b == true)
        {
            cout << char(49+i);
            for (int i = 0;i<(x/2);i++)
            {
                cout << char(219) << char(219)<<char(255) << char(255);
            }
            if (x % 2 == 1)
            {
               cout << char(219) << char(219);
            }
            cout << char(49+i);
            b = false;
        }
        else
        if (b == false)
        {
            cout << char(49+i);
            for (int i = 0;i<(x/2);i++)
            {
                cout  << char(255) << char(255)<<char(219) << char(219);
            }
            if (x % 2 == 1)
            {
               cout << char(255) << char(255);
            }
            cout << char(49+i);
            b = true;
        }
        cout << endl;

    }

    //ramka dol
    cout << char(200);
    for (int i = 0;i<x;i++)
    {
        cout << char(65+i) << char(205);
    }
    cout << char(188)<< endl;

    system("pause");
}


if (g == 3)
{
    bool b;
    b = true;
    int x,y;
   cponx:
    cout << "Podaj szerokosc szachownicy: ";
    cin >> x;
    if( !cin )
        {
            cin.clear();
            cin.sync();
            cout << "Podaj liczbe!" << std::endl;
            goto cponx;
    }
   cpony:
    cout << "Podaj dlugosc szachownicy: ";
    cin >> y;
    if (!cin)
    {
        cin.clear();
        cin.sync();
        cout << "Podaj liczbe!" << endl;
        goto cpony;
    }

    //ramka
    cout << char(255);
    for (int i = 0;i<x;i++)
    {
        cout << char(65+i) << char(255);
    }
    cout << char(255)<< endl;



    //srodek
    for (int i = 0;i<y;i++)
    {
        if (b == true)
        {
            cout << char(49+i);
            for (int i = 0;i<(x/2);i++)
            {
                cout << char(219) << char(219)<<char(255) << char(255);
            }
            if (x % 2 == 1)
            {
               cout << char(219) << char(219);
            }
            cout << char(49+i);
            b = false;
        }
        else
        if (b == false)
        {
            cout << char(49+i);
            for (int i = 0;i<(x/2);i++)
            {
                cout  << char(255) << char(255)<<char(219) << char(219);
            }
            if (x % 2 == 1)
            {
               cout << char(255) << char(255);
            }
            cout << char(49+i);
            b = true;
        }
        cout << endl;

    }

    //ramka dol
    cout << char(255);
    for (int i = 0;i<x;i++)
    {
        cout << char(65+i) << char(255);
    }
    cout << char(255)<< endl;

    system("pause");
}
    return 0;
}
