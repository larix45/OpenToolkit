#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
        std::string s;
        std::string args;
        std::string cmdsd;
        x:
        std::cout << "root@user ~# ";
        std::cin >> s;
        std::cout << endl;
        if (s == "ls")
        {
            system("dir");
        }
        if (s == "spam")
        {
            for (int h = 97; h<122; h++)
            {
                for (int j = 97; j<122; j++)
                {
                    for (int i = 97; i<122; i++)
                    {
                        cmdsd = "mkdir " +  char(i) + char(j) + char(h);
                        system(cmdsd.c_str());
                    }
                }
            }

        }
        if (s == "rmd")
        {
            std::cin >> args;
            cmdsd = "rmdir " +  args;
            system(cmdsd.c_str());
        }
        if (s == "mkd")
        {
            std::cin >> args;
            cmdsd = "mkdir " +  args;
            system(cmdsd.c_str());
        }
        if (s == "net")
        {
            system("start chrome");
        }
        if (s == "top")
        {
            system("taskmgr");
        }
        if (s == "change")
        {
            std::cin >> args;
            cmdsd = "cd " +  args;
            system(cmdsd.c_str());
        }
        if (s != "exit")
        {
            goto x;
        }

    std::cout << endl;
    system("pause");
    return 0;
}
