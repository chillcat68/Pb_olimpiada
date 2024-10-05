#include <iostream>
#include <fstream>
#define MOD_MAX 1000000007

using namespace std;
int m, i;
unsigned int p0;
int x;
char tip;

ifstream f("apgreid.in");
ofstream g("apgreid.out");

void CERINTA_1()
{
    int maxc=0, maxp=0, maxn=0;
    while (f>>tip>>x) {
        if(tip=='c' && x>maxc)
            maxc=x;
        else if (tip=='p' && x>maxp)
            maxp=x;
        else if (tip=='n' && x>maxn)
            maxn=x;
    }
    g<<maxc<<' '<<maxp<<' '<<maxn;
}

void CERINTA_2()
{
    int j=0, k=0, l=0;
    int c[35000], p[35000], n[35000];
    for (i=1; i<=m; i++) {
        f>>tip>>x;
        if(tip=='c')
            c[++j]=x;
        else if (tip=='p')
            p[++k]=x;
        else if (tip=='n')
            n[++l]=x;
    }

    for (i=1; i<=k; i++)
        g<<'p'<<' '<<p[i]<<'\n';
    for (i=1; i<=l; i++)
        g<<'n'<<' '<<n[i]<<'\n';
    for (i=1; i<=j; i++)
        g<<'c'<<' '<<c[i]<<'\n';
}

void suma(unsigned int &a, int x)
{
    a = ((a%MOD_MAX) + (x%MOD_MAX)) % MOD_MAX;
}

void produs(unsigned int &a, int x)
{
    a = (1ll *(a%MOD_MAX) * (x%MOD_MAX)) % MOD_MAX;
}

int ridicare(unsigned int a, int x) {
    int rasp = 1;
    while(x > 0) {
        if(x % 2 == 1)
            rasp = 1ll *(rasp%MOD_MAX) * (a%MOD_MAX) % MOD_MAX;
        a = 1ll * (a%MOD_MAX) * (a%MOD_MAX) % MOD_MAX;
        x /= 2;
    }
    return rasp;
}

void CERINTA_3()
{
    int j=0, k=0, l=0;
    int c[35000], p[35000], n[35000];
    for (i=1; i<=m; i++) {
        f>>tip>>x;
        if (tip=='p')
            p[++k]=x;
        else if (tip=='n')
            n[++l]=x;
        else if(tip=='c')
            c[++j]=x;
    }

    for (i=1; i<=k; i++)
        suma(p0, p[i]);
    for (i=1; i<=l; i++)
        produs(p0, n[i]);
    for (i=1; i<=j; i++)
        p0 = ridicare(p0, c[i]);

    g<<p0;
}

int main()
{
    int t; f>>t>>m>>p0;
    if (t==1)
        CERINTA_1();
    else if (t==2)
        CERINTA_2();
    else
        CERINTA_3();
    return 0;
}
