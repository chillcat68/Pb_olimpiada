#include <fstream>
#define MOD 100003
using namespace std;
ifstream f("2sah.in");
ofstream g("2sah.out");
int t,n,k,i,j,m,s,a[1005][2010];
int main()
{
    f>>t>>n>>k;
    a[1][n+1]=1;

    if(t==1)
    {
        for(i=2;i<=k;i++)
        for(j=1;j<=2*n+1;j++)
            a[i][j]=(a[i-1][j-1]+a[i-1][j]+a[i-1][j+1])%MOD;
        s=0;
        for(j=1;j<=2*n+1;j++)
            s=(s+a[k][j])%MOD;
        g<<s;
        return 0;
    }
    for(i=2;i<=n+1;i++)
        for(j=1;j<=2*n+1;j++)
            a[i][j]=(a[i-1][j-1]+a[i-1][j]+a[i-1][j+1])%MOD;
    i=1;j=k;s=0;m=2*n+1;n++;
    while(i<=n&&j<=m)
    {
        s=(s+a[i][j])%MOD;
        i++;j+=2;
    }
    g<<s;
    return 0;
}
