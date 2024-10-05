#include <iostream>
#include <fstream>
using namespace std;

ifstream f("covor.in");
ofstream g("covor.out");
int n,k,v;

void calcul()
{  long long i,nr,t,r, s;
    //numar romburi complete
       nr=1;
       while ((nr+1)*(nr+2)/2+nr*(nr-1)+nr*(nr+1)/2<=n)
        nr++;
       if (v==1)g<<nr-1;
       else
       {
         t=0;
        s=1;
        while (s+2*t<k && t<=nr-1)
            { s=s+2*t;
            t++;
            }
        if (t<=nr-1)
          g<<t;
          else
          {
            t--;
            while (s+t+t-1<k && t>=1)
          {
              s=s+t+t-1;
              t--;
          }
          if (s+2*t-1<k) g<<0;
          else
          g<<t;
       }
       }
}
int main()
{
    f>>n>>k>>v;
    calcul();
    return 0;
}
