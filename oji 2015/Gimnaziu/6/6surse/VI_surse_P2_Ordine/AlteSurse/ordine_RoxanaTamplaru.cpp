#include <iostream>
#include <fstream>

using namespace std;

ifstream f("ordine.in");
ofstream g("ordine.out");

int n,x[500001],k,y[500001],i,j,m;

int main()
{
    f>>n;
    m=n;
    for (i=1;i<=n;i++)
        f>>x[i];
    f>>k;
    if (k==1)
         if (n%2==1) g<<x[(n+1)/2];
            else g<<x[n];
       else
        { k=1;
            for (i=1;i<=(n+1)/2;i++)
             {
                 y[k]=x[i];
                 k+=2;
             }
             k=2;
             for(i=(n+1)/2+1;i<=n;i++)
               {
                   y[k]=x[i];
                   k+=2;
               }
       for(i=1;i<=m;i++)
         g<<y[i]<<" ";
        }
    return 0;
}
