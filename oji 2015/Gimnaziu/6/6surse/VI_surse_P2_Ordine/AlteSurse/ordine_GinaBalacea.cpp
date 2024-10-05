#include<fstream>
using namespace std;
int o[250001],n,i,c,k,N,b1,b2;
ifstream f("ordine.in");
ofstream g("ordine.out");
int main()
{
    f>>n;
    k=1;
    if(n==1)
    {f>>o[1];b1=o[1];
    }
    else
    {
    for(i=1; i<=n; i++,k=k+2)
    {
        if(k>n)
        {
            b1=o[k-2];
            k=2;
        }
        f>>o[k];
    }
    }
    b2=o[n];
    f>>c;
    if(n%2) N=b1;
    else N=b2;
    if(c==2)
        for(i=1; i<=n; i++) g<<o[i]<<' ';
    else
        g<<N;
    f.close();
    g.close();
    return 0;
}

