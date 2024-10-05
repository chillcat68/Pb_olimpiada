
#include<fstream>
using namespace std;
int main()
{
    int pp,n,nr1=0,nr2=0,p1=0,p2=0,max1=0,nrcuart1=0,nrcuart2=0,c,y,x,p,i,k,s;
    ifstream f("cuart.in");
    ofstream g("cuart.out");
    f>>pp>>n;
    for (i=1; i<=n; i++)
    {
        f>>c;
        x=c;
        p=1;
        y=0;
        while (x)
        {
            if (x%2==1)
            {
                y=y+x%10*p;
                p=p*10;
            }
            x=x/10;
        }
        if (y!=0)
        {
            nr1++;
            if (nr1==1) p1=y;
            s=1;
            k=5;
            while (s+k<=y)
            {
                s=s+k;
                k=k+4;
            }
            if (s==y) nrcuart1++;

        }
        else if (c>max1) max1=c;
    }
    for (i=1; i<=n; i++)
    {
        f>>c;
        x=c;
        p=1;
        y=0;
        while (x)
        {
            if (x%2==0)
            {
                y=y+x%10*p;
                p=p*10;
            }
            x=x/10;
        }
        if (y!=0)
        {
            nr2++;
            if (nr2==1) p2=y;
            s=1;
            k=5;
            while (s+k<=y)
            {
                s=s+k;
                k=k+4;
            }
            if (s==y) nrcuart2++;
        }
        else if (c>max1) max1=c;
    }
    if (pp==1)
        g<<max1<<'\n';
    else if (pp==2)
    {
        if (nrcuart1>nrcuart2)
            g<<"1\n";
        else if (nrcuart2>nrcuart1)
            g<<"2\n";
        else
        {
            if (p1>p2)g<<"1\n";
            else if (p2>p1)g<<"2\n";
            else g<<"0\n";
        }
    }
    else
    {
        if (nrcuart1>nrcuart2)
            g<<nrcuart1;
        else if (nrcuart2>nrcuart1)
            g<<nrcuart2;
        else
        {
            if (p1>p2)g<<p1<<"\n";
            else if (p2>p1)g<<p2<<"\n";
            else g<<"0\n";
        }
    }
    return 0;
}


