//#include <iostream>
#include <fstream>
using namespace std;

int v[500001],n;
ifstream f("ordine.in");
ofstream g("ordine.out");
int main()
{   int i, k, p,j;
    f>>n;
    for(i=1;i<=n;i++)f>>v[i];
    f>>k;
    if(k==1)
      {
          if(n%2)p=(n+1)/2;
          else p=n;
          g<<v[p]<<endl;
      }
    else
    {
       p=(n+1)/2+1;
       i=1;j=p;
       while (i<p && j<=n)
       {
           g<<v[i]<<" "<<v[j]<<" ";
           i++; j++;
       }
       if(i<p)g<<v[i];
       if(j<=n)g<<v[j];
       g<<endl;
    }
return 0;
}
