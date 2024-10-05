#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int x[300001],y[300001];
char s[300001];
int n;

int main()
{
    int V,h,i,j;
    freopen("dominant.in","r",stdin);
    freopen("dominant.out","w",stdout);
    cin>>V;
    cin>>s;
    n=strlen(s);
    for(i=0;i<n;i++)
    {
       if(s[i]=='1')
       {
           x[i+1]=x[i]+1;
           y[i+1]=y[i];
       }
       else
       {
           x[i+1]=x[i];
           y[i+1]=y[i]+1;
       }
    }

    int maxx=0,nr=0;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(x[j]-x[i-1]>y[j]-y[i-1])
            {
                if(j-(i-1)>maxx)
                {
                    maxx=j-(i-1);
                    nr=0;
                }
                if(j-(i-1)==maxx)
                    nr++;
            }
    if(V==1)
    {
        cout<<maxx<<"\n";
    }
    else
    {
        cout<<nr<<"\n";
    }
    return 0;
}
