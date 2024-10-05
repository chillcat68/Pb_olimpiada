#include <iostream>
#include<fstream>
#include<cstring>

using namespace std;
char d[300000];
int v;
int lung[300000]= {0};
void citire()
{
    ifstream f("dominant.in");
    f>>v;
    f>>d;
    f.close();
}
int main()
{
    citire();

    int sum=0,sump;
    int i,j,n=strlen(d);
    for (i=0; i<n; i++)
        sum+=d[i]-'0';
    for(i=0; i<n; i++)
    {
        sump=sum;
        for(j=n-1; j>i; j--)
        {

            if(sump==(j-i)/2+1 && (j-i+1)%2==1)
            {
                lung[i]=j-i+1;
                break;
            }
            sump=sump-(d[j]-'0');
        }
        sum-=d[i]-'0';
    }
int    max=0;
  int  mf=0;
    for(i=0; i<n; i++)
      if (max==lung[i]) mf++;
        else if (max<lung[i]) {max=lung[i]; mf=1;}
ofstream g("dominant.out");
if(v==1)
     g<<max;
     else g<<mf;
     g.close();
    return 0;
}
