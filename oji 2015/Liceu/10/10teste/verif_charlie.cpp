#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

ifstream fok("charlie.ok");
ifstream fout("charlie.out");

void Msg(int pct, string msg );
string Trim(string s);

int main(int argc, char* argv[])
{
    if ( !fout )
        Msg(0, "Nu exista fisierul charlie.out!");

    int testNumber, testPoints;
	testNumber = atoi(argv[1]);          // numarul testului
	testPoints = atoi(argv[2]);          // nr puncte/test
	int total = 0;

    string a;     // valori corecte
    string x;     // valorile concurentului

    getline(fok, a);  // read dummy line

    bool ok1 = true, ok2 = true;
    if ( testNumber < 5 )
    {
        getline(fok, a);  a = Trim(a);         // elimin spatiile de la sfarsit si de la inceput
        getline(fout, x); x = Trim(x);
        if ( a != x )
            ok1 = false;
    }
    else
    {
		getline(fok, a);  a = Trim(a);         // prima linie din fisier
        getline(fout, x); x = Trim(x);
		if ( a != x )
			ok1 = false;
        while ( getline(fok, a) )         // urmatoare linii din fisier
        {
            a = Trim(a);
            getline(fout, x);
            x = Trim(x);
            if ( a != x )
            {
                ok1 = false;
                break;
			}
        }
    }

    if ( ok1 )
    {
		string v = "";
		fout >> v;           // daca mai sunt valori suplimentare in out
		if ( v != "" )
			ok1 = false;
	}

	if ( testNumber < 5 )
    {
        if ( ok1 )
            Msg(testPoints, "Corect !");
        else
            Msg(0, "Incorect !");
    }
    else
    {
        if ( ok1)
            Msg(testPoints, "Corect !");
        else
            Msg(0, "Incorect !");
    }

    return 0;
}

void Msg(int pct, string msg )
{
    cout << pct << ' ' << msg;
    try
    {
        fok.close();
        fout.close();
    }
    catch (string ex) {}
    exit(0);
}

string Trim(string str)
{
	size_t pos2 = str.find_last_not_of(" \t");
	size_t pos1 = str.find_first_not_of(" \t");
	if ( pos1 != string::npos && pos2 != string::npos)
		str = str.substr(pos1, pos2 + 1);
	return str;
}

