#include <iostream>
#include <fstream>
using namespace std;
ifstream in("speciale.in");
ofstream out("speciale.out");
int main()
{
    int P,k,n,A,B,m,nr=0,nrm=0,mr=0,i,l,sw1,sw2;
    in>>P;
    in>>k>>n>>A>>B;
    if(P==1)
    {
    //a
    for(i=1;i<=k;i++)
       nrm=nrm*10+10-i;
    out<<nrm<<'\n';
    }
    else
    if(P==2)
    {
    //b
    nr=0;
    m=n,l=0;
    while(m)
        l++,m/=10;
    for(i=1;i<l;i++)
        nr=nr*10+i;
    mr=nr,sw1=0,m=n;
    while(n)
    {
        if(n%10!=nr%10)
            n/=10, sw1++;
        else
            n/=10,nr/=10;
    }
    n=m;
    if(sw1==1&&nr==0)
        out<<mr<<'\n';
    else
        if(sw1==0 && n/10==0)
            out<<mr<<'\n';
        else
        {
        nr=0;
         for(i=9;i>10-l;i--)
            nr=nr*10+i;
         mr=nr,sw2=0,m=n;
        while(n)
        {
            if(n%10!=nr%10)
                n/=10, sw2++;
            else
                n/=10,nr/=10;
        }
        if(sw2==1&&n==0)
            out<<mr<<'\n';
        else
            if(sw2==0 && n/10==0)
                 out<<mr<<'\n';
        if(sw1!=1 && sw2!=1)
                out<<0<<'\n';
    }
    }
    else
    {
    //c
    m=A,l=0,nr=0,k=0;
    while(m)
        l++,m/=10;
    for(i=1;i<=l;i++)
        nr=nr*10+i;
    if(nr<A)
         {
            m=nr*8+l;
            if(m>=A && m<=B)
                k++;
            l++, nr=nr*10+l;
         }
    i=l;
    while(nr>=A && nr<=B)
        {
            k++;
            if(nr*8+i>=A && nr*8+i<=B)
                k++;
            i++;
            nr=nr*10+i;
        }
    out<<k;
    }
    return 0;
}
