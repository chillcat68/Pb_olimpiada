#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

long long n, i, r, x, k, V;

ifstream fin ("pavare.in");
ofstream fout("pavare.out");


int main() {
    fin>>V;
    fin>>x;

    r = (long long)((1 + sqrt(4*x))/2);
    //cout<<r;

    if (x <= (r*(r-1) + r) ) {
/*
        if (V == 1) {
            fout<<2*r-1<<"\n";
            return 0;
        }
        if (x == r*(r-1)) {
            for (i = 1; i<=r-1; i++)
                fout<<i<<" ";
            for (i=r-1;i>=1;i--)
                fout<<i<<" ";
        } else {
            k = x - (r*(r-1));
            for (i=1;i<=k;i++)
                fout<<i<<" ";
            for (i=k;i<=r-1;i++)
                fout<<i<<" ";
            for (i=r-1;i>=1;i--)
                fout<<i<<" ";
        }
*/

    } else {
        if (V == 1) {
            fout<<2*r<<"\n";
            return 0;
        }
        k = x - (r*(r-1)) - r;

        for (i=1;i<=k;i++)
            fout<<i<<" ";
        for (i=k;i<=r;i++)
            fout<<i<<" ";
        for (i=r-1;i>=1;i--)
            fout<<i<<" ";
    }
    return 0;
}

