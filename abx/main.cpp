#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
using ull = unsigned long long int ;

ifstream f("abx.in");
ofstream g("abx.out");
int n;
ull m, x, i;

ull ridicare(int a, int n) {
    ull rasp = 1;
    while(n > 0) {
        if(n%2==1)
            rasp=rasp*a;
        a=a*a;
        n/=2;
    }
    return rasp;
}

bool este_putere(ull y) {
    int ok=0;

    for (int j=2; j<=sqrt(y) && ok==0; j++) {
        for (int l=2; l<=sqrt(y)/2 && ok==0; l++)
            if (ridicare(j, l)==y)
                ok=1;
    }
    if (ok==1)
        return true;
    else
        return false;
}

int main()
{
    f>>n>>m;

    bool ok=false;
    for (int k=1; k<=n; k++) {
        f>>x;
        if (sqrt(x)==(int)sqrt(x))
            g<<x<<'\n';
        else {
            i=1; ok=false;
            while (ok==false && x+i<=m && x-i>=1) {
                if (este_putere(x-i)==true) {
                    g<<x-i<<'\n';
                    ok=true;
                }
                else if (este_putere(x+i)==true) {
                    g<<x+i<<'\n';
                    ok=true;
                }
                i++;
            }
        }
    }
    return 0;
}
