#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

std::string comunicat[16];


std::string GetStdoutFromCommand(std::string cmd) {

std::string data;
FILE * stream;
const int max_buffer = 256;
char buffer[max_buffer];
cmd.append(" 2>&1");

stream = popen(cmd.c_str(), "r");
if (stream) {
while (!feof(stream))
if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
pclose(stream);
}
return data;
}


std::string path_for_rm;
bool state_rm;
using namespace std;
std::fstream file,file2;


bool rm(std::string path)
{
	system(std::string("rm "+path).c_str());
	return true;	
}


int main(int argc, char* argv[])
{
	//CZYTANIE KONFIGURACJI
	file.open("/etc/default/sccrypter");
	if(file.good())
	{
			std::string str;
			std::getline(file,str);
			std::getline(file,str);
			std::getline(file,str);
			std::getline(file,str);
			if(str == "1")
				state_rm = true;
			else
				state_rm = false;
	}
	else
	{
		std::cout << "NO CONFIG FILE!" << std::endl << "STARTING IN DEFAULT MODE" << std::endl;
		state_rm    =1;
	}
	file.close();
	file.open("/etc/default/sccrypter.lang");
	if(file.good())
	{		 
		
		std::getline(file,comunicat[0]);
		std::getline(file,comunicat[1]);
		std::getline(file,comunicat[2]);
		std::getline(file,comunicat[3]);
		std::getline(file,comunicat[4]);
		std::getline(file,comunicat[5]);
		std::getline(file,comunicat[6]);
		std::getline(file,comunicat[7]);
		std::getline(file,comunicat[8]);
		std::getline(file,comunicat[9]);
		std::getline(file,comunicat[10]);
		std::getline(file,comunicat[11]);
		std::getline(file,comunicat[12]);
		std::getline(file,comunicat[13]);
		std::getline(file,comunicat[14]);
		std::getline(file,comunicat[15]);
	}
	else
	{
		comunicat[0]  = "Wczytano plik!";
		comunicat[1]  = "BŁĄD W PLIKU WEJSCIOWYM!";
		comunicat[2]  = "Utworzono plik!";
		comunicat[3]  = "BŁĄD W PLIKU WYJSCIOWYM!";
		comunicat[4]  = "Czekam na kartę...";
		comunicat[5]  = "Karta uszkodzona, niewłaściwa lub włożona złą stroną!";
		comunicat[6]  = "Szyfrowana/Deszyfrowana linia:";
		comunicat[7]  = "Wynikowa linia:";
		comunicat[8]  = "BłĄD ZAPISU DO PLIKU!";
		comunicat[9]  = "UKOŃCZONO SZYFOWANIE / DESZYFOWANIE";
		comunicat[10] = " -f -i --input [file path]    ==:== file to crypt/decrypt";
		comunicat[11] = " -o --output   [file path]    ==:== output file";
		comunicat[12] = " -d --dir     [folder path]   ==:== crypt folder (USE -k FOR DECRYPT)";
		comunicat[13] = " -s -S --scc                  ==:== fast encryption of of directory ''SCC'' in /home (-v -V --vscc for decryption)  ";
		comunicat[14] = " -n --dont-rm                 ==:== do not remove orginall file (chae default state too)";
		comunicat[15] = " -h --help                    ==:== print this help";
	}
	file.close();
	bool wf=false;
	bool wo=false;
	bool dir=false;
	bool ddir=false;
	//PARSOWNAAIE ARGUMENTOW
	
	std::string homedir = GetStdoutFromCommand("less $HOME");
		for(size_t i = 0; i < homedir.length();i++)
		{
			if(homedir.at(i) == 32)
				homedir.resize(i);
				
		}
	
    for(short i=0; i < argc; i++)
    {
        if(std::string(argv[i]) == "-v" || std::string(argv[i]) == "-V" || std::string(argv[i]) == "--vscc")
        {
			wf =true;
			dir=true;
			ddir=true;
			file.open(homedir + "/scc.tt", ios::in|ios::out);
			system(std::string("touch .sccrypter.tar").c_str());
			file2.open(std::string(".sccrypter.tar"), ios::in|ios::out);
			if(file2.good())
				std::cout << comunicat[2] << std::endl;
			else
				std::cerr << comunicat[3] << std::endl;
			if(file.good())
				std::cout << comunicat[0] << std::endl;
			else
				std::cerr << comunicat[1] << std::endl;	
			path_for_rm = ".sccrypter.tar";
		}
		if(std::string(argv[i]) == "-s" || std::string(argv[i]) == "-S" || std::string(argv[i]) == "--scc")
		{
			//TO DO
			wf = true;
			bool good = system(std::string("tar --create " + homedir + "/scc" + " -f .sccrypter.tar").c_str());
			if(!good)
			{
				rm(" -r "+homedir+"/scc/");
				file.open(std::string(".sccrypter.tar"), ios::in|ios::out);
				if(file.good())
					std::cout << comunicat[0] << std::endl;
				else
					std::cerr << comunicat[1] << std::endl;		
				path_for_rm = ".sccrypter.tar";
			}
			else
				std::cerr << "TAR ERROR!!!" << std::endl;
				
				
			wo = true;
			system(std::string("touch "+homedir+"/scc.tt").c_str());
			file2.open(std::string(homedir+"/scc.tt"), ios::in|ios::out);
			
			if(file2.good())
				std::cout << comunicat[2] << std::endl;
			else
				std::cerr << comunicat[3] << std::endl;
		}
		if(std::string(argv[i]) == "-f" || std::string(argv[i]) == "-i" || std::string(argv[i]) == "--input")
        {
			wf = true;
			path_for_rm = argv[i+1];
			file.open(std::string(argv[i+1]), ios::in|ios::out);
            if(file.good())
				std::cout << comunicat[0] << std::endl;
			else
				std::cerr << comunicat[1] << std::endl;
        }
		if(std::string(argv[i]) == "-o" || std::string(argv[i]) == "--output")
        {
			wo = true;
			system(std::string("touch " + std::string(argv[i+1])).c_str());
			file2.open(std::string(argv[i+1]), ios::in|ios::out);
			
			if(file2.good())
				std::cout << comunicat[2] << std::endl;
			else
				std::cerr << comunicat[3] << std::endl;
        }
		if(std::string(argv[i]) == "-n" || std::string(argv[i]) == "--dont-rm" || std::string(argv[i]) == "--dont_rm")
        {
			state_rm = !state_rm;
        }
		if(std::string(argv[i]) == "-k" )
		{
			wf =true;
			dir=true;
			file.open(std::string(argv[i+1]), ios::in|ios::out);
			system(std::string("touch " + std::string(".sccrypter.tar")).c_str());
			file2.open(std::string(".sccrypter.tar"), ios::in|ios::out);
			if(file2.good())
				std::cout << comunicat[2] << std::endl;
			else
				std::cerr << comunicat[3] << std::endl;
			if(file.good())
				std::cout << comunicat[0] << std::endl;
			else
				std::cerr << comunicat[1] << std::endl;		
		}
		if(std::string(argv[i]) == "-d" || std::string(argv[i]) == "--dir")
        {
			wf = true;
			bool good = system(std::string("tar --create " + std::string(argv[i+1]) + " -f .sccrypter.tar").c_str());
			if(!good)
			{
				file.open(std::string(".sccrypter.tar"), ios::in|ios::out);
				if(file.good())
					std::cout << comunicat[0] << std::endl;
				else
					std::cerr << comunicat[1] << std::endl;		
				path_for_rm = ".sccrypter.tar";
			}
			else
				std::cerr << "TAR ERROR!!!" << std::endl;
		}
		if(std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help")
        {
			wo = false;
			wf = false;
        }
    }
	if (!dir)
		if(wf == false || wo == false)
		{
			std::cout << comunicat[10] << std::endl;
			std::cout << comunicat[11] << std::endl;
			std::cout << comunicat[12] << std::endl;
			std::cout << comunicat[13] << std::endl;
			std::cout << comunicat[14] << std::endl;
			std::cout << comunicat[15] << std::endl;
			exit(0);
		}
	//Parsownaie klucza
	int k =37;
	std::cout << comunicat[4] << std::endl;
	std::string key = GetStdoutFromCommand("opensc-tool -a -w");
	std::string crypt_key = "";
	for(int i = 0; i < 36+17; i++)
	{
		crypt_key += key.at(k+i);
	}
	if(key.at(k) == 'F' && key.at(k+1) == 'a'&& key.at(k+2) == 'i'&& key.at(k+3) == 'l'&& key.at(k+4) == 'e'&& key.at(k+5) == 'd')
	std::cerr << comunicat[5]<< std::endl;
	std::cout << crypt_key << std::endl;
	key.clear(); 
	
//SZYFROWANIE
	char bufor,bufor2;
	while(!file.eof())
	{
		for(size_t i = 0; i < crypt_key.length(); i++)
		{
			bufor = file.get();
			bufor2 = bufor ^ crypt_key.at(i);
			if(file2.good())
			{
				std::cout << comunicat[7] << std::endl;
				file2 << bufor2;
			}
			else
				std::cerr << comunicat[8];
		}
	}
	 
	std::cout << comunicat[9] << std::endl;
	
	file.close();
	file2.close();
	
	if(dir)
	{
		key.clear();
		if(ddir)
		{
			key = " -C /";
			rm(homedir + "/scc.tt");
		}	
		bool good = system(std::string("tar -x -f .sccrypter.tar "+key).c_str());
		if(!good)
			system("rm .sccrypter.tar");
		else
			std::cerr << "TAR ERROR!!!" << std::endl;
	}
	rm(path_for_rm);
    return 0;
}
