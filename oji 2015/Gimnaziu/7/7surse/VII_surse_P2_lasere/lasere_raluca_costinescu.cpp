//Costineanu Veronica Raluca Colegiul National Stefan cel Mare Suceava
#include <fstream>
#define vmax 999999999

using namespace std;
ifstream f("lasere.in");
ofstream g("lasere.out");


int a[210][210],n, m, c,  gr[210][210];

void trage(int x, int y, int d)
{
    int i, j;
    if(d==1)
        for(i=x-1;i>=1;i--)
            a[i][y]--;
    else
    if(d==2)
        for(j=y+1;j<=n;j++)
            a[x][j]--;
    else
        if(d==3)
            for(i=x+1;i<=n;i++)
                a[i][y]--;
        else
            for(j=y-1;j>=1;j--)
                a[x][j]--;
}
int groapa(int x, int y)
{
    if(a[x][y]<=a[x-1][y-1] and a[x][y]<=a[x-1][y] and a[x][y]<=a[x-1][y+1] and a[x][y]<=a[x][y-1] and a[x][y]<=a[x][y+1] and
       a[x][y]<=a[x+1][y-1] and a[x][y]<=a[x+1][y] and a[x][y]<=a[x+1][y+1])
        return 1;
    return 0;
}
int main()
{
    f>>c;
    f>>n>>m;
    int i, j, x, y, d, nr=0,p;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            f>>a[i][j];
    for(i=0;i<=n+1;i++)
        a[0][i]=a[n+1][i]=a[i][0]=a[i][n+1]=vmax;
    for(p=1;p<=m;p++)
    {
        f>>x>>y>>d;
        trage(x,y,d);
    }
     for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(groapa(i,j))
            gr[i][j]=1, nr++;
    int tr=0;
    for(i=1;i<=n;i++)
    {
        j=1;
        while(j<=n)
        {
            while(j<=n and gr[i][j]==0)j++;
            x=0;
            while(j<=n and gr[i][j]==1)j++, x++;
            if(x>1)tr++;
        }
    }
    if(c==1)
    g<<nr<<'\n';
    else
    g<<tr<<'\n';
    return 0;
}
