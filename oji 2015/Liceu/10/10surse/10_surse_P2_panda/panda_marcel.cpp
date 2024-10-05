/*
	Sursa 100 p
	prof. Marcel Dragan, Sibiu
*/
#include <fstream>
#include <queue>
#include <cstring>
using namespace std;
ifstream in("panda.in");
ofstream out("panda.out");
int p,n,m,t,l,c,k,s,h[501][501],lee[501][501],x;
void citire()
{
    in>>p>>n>>m>>t;
    in>>l>>c>>k>>s;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            h[i][j]=0;
        }
    }
    int xt,yt;
    for(int i=1;i<=t;i++)
    {
        in>>xt>>yt;
        h[xt][yt]=2000000;
    }
    int cod=1;
    for(int i=1;i<=s;i++)
        cod=cod*2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            in>>lee[i][j];
            if(lee[i][j]%cod+k%cod==cod-1)
                lee[i][j]=1000000;
            else
                lee[i][j]=-1;
        }
        int stop;
        if(i==24)
            stop=1;
    }
}
void afis(int matr[501][501])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(matr[i][j]<100)
                out<<matr[i][j]<<'\t'<<'\t';
            else
                out<<matr[i][j]<<'\t';
        }
        out<<'\n';
    }
    out<<'\n';
}
int parurgereLee()
{
    queue <int> lin,col;
    lee[l][c]=1;
    lin.push(l);
    col.push(c);
    int lu,cu,minT=1000000;
    while(!lin.empty())
    {
        int lc=lin.front();
        int cc=col.front();
        lin.pop();
        col.pop();
        for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
        {
            lu=lc+i;
            cu=cc+j;
            if(i*i!=j*j && 1<=lu && lu<=n && 1<=cu && cu<=m)
            {
                int pas=1;
                if(lee[lu][cu]!=-1 && lee[lc][cc]+1<lee[lu][cu])
                {
                    if(lee[lu][cu]>n*m)
                        x++;
                    lin.push(lu);
                    col.push(cu);
                    lee[lu][cu]=lee[lc][cc]+pas;
                    if(minT>lee[lu][cu] && h[lu][cu]==2000000)
                    {
                        minT=lee[lu][cu];
                    }
                }
            }
        }
//        afis(lee);
    }
//    afis(lee);
//    afis(h);
    return minT;
}
void afis(int minT)
{
    int gasit=0,total=0,total1=0,total2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(lee[i][j]==minT && h[i][j]==2000000)
                gasit++;
            if(1<lee[i][j] && lee[i][j]<1000000)
                total++;
            if(lee[i][j]==1000000)
                total1++;
            if(lee[i][j]==-1)
                total2++;
        }
    }
    if(p==1)
//        out << x << '\n';
        out << n*m-total2-1 << '\n';
    else
        out << minT-1 << ' ' << gasit << '\n';
}
int main()
{
    citire();
    int minT=parurgereLee();
    afis(minT);
    return 0;
}
