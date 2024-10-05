#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

ifstream f("cifre.in");
ofstream g("cifre.out");
int m, n, optiune, nr_cifre, i;
int cifra[]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, v[20];



int main()
{
    f>>n;
    char c[21];
    f.get(c, 20);
    for (int i=1; i<=4; i++)
        cout<<c[i];
    return 0;
}
