#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

ifstream fok("panda.ok");
ifstream fout("panda.out");
ifstream fin ("panda.in");

void Msg(int pct, string msg );
string Trim(string s);



int main(int argc, char* argv[])
{
    if ( !fout )
        Msg(0, "Nu exista fisierul panda.out!");

    int testNumber, testPoints;

	testNumber =  atoi(argv[1]);          // numarul testului
	testPoints =  atoi(argv[2]);          // nr puncte/test
// doua cerinte
    int a, b, c, x[3], i;     // valori corecte
    char s[30], *s1;
    int total = 0, t1=0, t2=0, p;    // punctajul total
    bool ok1 = false, ok2 = false;

    string z;

    getline(fok, z); //citesc mess VALID

    fin >> p;
    if(p == 1)
    {
        fok >> a;
        fout >> x[0];
        if ( a == x[0])
        {
            t1 = testPoints;
            ok1 = true;
        }

    if ( ok1  )
       Msg(t1+t2, "Corect !");
    else
        Msg(0, "Valoare incorecta cerinta a!" );

    }
	else
	{
	    fok >> a >> b;
        fout >> x[0] >> x[1];
        if(a == x[0])
        {
             t1 = testPoints/4 * 3;
             ok1 = true;
        }

        if ( b == x[1] )
        {
            t2 = testPoints / 4;
            ok2 = true;
        }

    if ( ok1 && ok2  )
           Msg(t1 + t2, "Corect !");
        if (!ok1 && !ok2)
            Msg(0, "Valoare incorecta cerinta b!" );

        if ( ok1 && !ok2)
            Msg(t1, "Valoare incorecta calcul nt!");
       if ( ok2 && !ok1)
            Msg(t1+t2, "Valoare incorecta calcul Smin!");

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
	size_t pos = str.find_last_not_of(" \t");
	if ( pos != string::npos )
		str = str.substr(0, pos + 1);
	return str;
}
