#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int power(int nr, int p)
{
    int result=nr;
    for (int i=1; i<p; i++)
        result=result*nr;
    return result;
}

int main()
{
    ifstream f("235.in");
    ofstream g("235.out");

    int n, p3, p5, i, a, b, x, ct=0, st, dr, mij;
    int v[31]={0};
    bool gasit;

    i=0;
    p3=1;
    p5=1;
    a=power(3, p3);
    b=power(5, p5);
    while (a<2000000000 && b<2000000000)
    {
        if (a<b)
        {
            v[i]=a;
            i++;
            p3++;
            a=power(3, p3);
            if (a<0)
                a=2000000001;
        }else
        {
            v[i]=b;
            i++;
            p5++;
            b=power(5, p5);
            if (b<0)
                b=2000000001;
        }
    }
    for (i=0; i<31; i++)
        cout<<v[i]<<' ';
    cout<<'\n';

    f>>n;

    for (i=1; i<=n; i++)
    {
        f>>x;
        st=0; dr=31;
        gasit=false;
        while (st<=dr && gasit==false)
        {
            mij=(st+dr)/2;
            if (x==v[mij])
            {
                gasit=true;
                ct++;
            }
            else if (x<v[mij])
                dr=mij-1;
            else
                st=mij+1;
        }
    }

    cout<<ct;

    return 0;
}
