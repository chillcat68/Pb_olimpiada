#include <iostream>
#include <fstream>

using namespace std;

int a[101][361];

int main()
{
    ifstream f("defrag.in");
    ofstream g("defrag.out");
    int v, p, s, c, i, j, linie, coloana, k, b, m;
    f>>v>>p>>s>>c;

    for (i=1; i<=c; i++) {
        f>>linie>>coloana;
        a[linie][coloana]=1;
        a[linie][0]++;
    }


    if (v==1) {
        int ct=0;
        for (i=1; i<=p; i++)
            if (a[i][0]==0)
                ct++;
        g<<ct;
    }
    else {
        for (i=1; i<=p; i++) {
            k=a[i][0];
            if (k==0 || k==1 || k==s || k==s-1)
                g<<0<<' ';
            else {
                b=0;
                for (j=1; j<=k; j++)
                    b=b+a[i][j];
                m=b;
                for (j=2; j<=s-k+1; j++) {
                    b=b-a[i][j-1]+a[i][j+k-1];
                    if (b>m)
                        m=b;
                }
                for (j=1; j<=k-1; j++) {
                    b=b-a[i][s-k+j]+a[i][j];
                    if (b>m)
                        m=b;
                }
                g<<k-m<<' ';
            }
        }
    }
    return 0;
}
