#include <iostream>
#include <fstream>

using namespace std;
long n, s=0, a[1000000],i=1;
int v,k;
int main()
{
    fstream f("pavare.in", ios::in);
    f>>v;
    f>>n;
   a[1]=1;
   while(s<n/2)
   {
       i++;
       a[i]=a[i-1]+1;
       s=s+a[i];
   }
   while (a[i]!=1)
   {
       i++;
       a[i]=a[i-1]-1;
   }
    fstream g("pavare.out", ios::out);
   if (v==1)
        g<<i;
    else
        {
        k=s-n;
        for(int j=i/2+i%2; j>i/2+i%2-k; j--)
          {
            a[j]=a[j]-1;
          }
        for(int j=1; j<=i; j++)
          g<<a[j]<<" ";

        }
}
