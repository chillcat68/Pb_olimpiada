#include <fstream>
#include<math.h>
using namespace std;
ifstream f("cuart.in");
ofstream g("cuart.out");
int n,x;
int main()
{
    int i,max1=0,p=1,nr=0,y,q1=0,q2=0,k,s, prim1=0, prim2=0,max2=0,nr1=0,nr2=0,P;
    f>>P>>n;
    for(i=1; i<=n; i++)
    {
        f>>x;
        y=x;
        while(x!=0)
        {
            if(x%10%2)
            {
                nr=nr+x%10*p;
                p=p*10;
            }
            x=x/10;
        }
        if(nr==0&&max1<y) max1=y;
        if(nr)
        {
            nr1++;
            if(prim1==0) prim1=nr;
            k=1;
            s=0;
            while (s<nr)
            {
                s=s+k;
                k=k+4;
            }
            if(s==nr) q1++;
        }
        nr=0;
        p=1;

    }
    for(i=1; i<=n; i++)
    {
        f>>x;
        y=x;
        while(x!=0)
        {
            if(x%10%2==0)
            {
                nr=nr+x%10*p;
                p=p*10;
            }
            x=x/10;
        }
        if(nr==0&&max2<y) max2=y;
        if(nr)
        {
            nr2++;
            if(prim2==0) prim2=nr;
            k=1;
            s=0;
            while (s<nr)
            {
                s=s+k;
                k=k+4;
            }
            if(s==nr) q2++;
        }
        nr=0;
        p=1;

    }
    if(P==1)
        if(max1>max2) g<<max1<<'\n';
        else g<<max2<<'\n';
    else
    {
        if(nr1==0&&nr2==0) g<<0<<'\n';
        else
        {
            if(q1>q2) if(P==2) g<<1<<'\n'; else g<<q1<<'\n';
            if(q1<q2) if(P==2) g<<2<<'\n'; else g<<q2<<'\n';
            if(q1==q2)
            {
                if(prim1>prim2) if(P==2) g<<1<<'\n'; else g<<prim1<<'\n';
                else if(P==2) g<<2<<'\n'; else g<<prim2<<'\n';
            }
        }
    }
        f.close();
        g.close();
        return 0;
    }
