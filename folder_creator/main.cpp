#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    for(size_t i=1; i<100;i++)
        system(std::string("mkdir " + i));



    cout << "DUZO TYCH KATALOGOW" << endl;
    return 0;
}
