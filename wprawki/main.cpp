#include <iostream>

using namespace std;

int main()
{
    int ile;
    cin >>ile;
    cout<< "zmienna ile ma wartosc "<< ile << endl;
    while(ile) {
    cout << "*\n";
    ile=ile-1;
    }
    cout<< "zmienna ma wartosc" << ile;
    return 0;
}
