//Miron Lucia Colegiul  "C. Negruzzi", Iasi
#include <fstream>
using namespace std;
ifstream fin("lasere.in");
ofstream fout("lasere.out");
struct el
{
    int v,g;
} a[202][202];
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int n,m,i,j,k,nrg,nrt,c,l;
void bordare()
{
    int i;
    for(i=0;i<=n+1;i++)
        a[i][0].v=a[i][n+1].v=10000;
    for(i=0;i<=n+1;i++)
        a[0][i].v=a[n+1][i].v=10000;
}
int groapa(int i,int j)
{
    int k;
    for(k=0;k<8;k++)
        if(a[i+dx[k]][j+dy[k]].v<a[i][j].v)
            return 0;
    return 1;
}
void citire()
{
    int i,j,k,x,y,d;
    fin>>c;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fin>>a[i][j].v;
    for(i=1;i<=m;i++)
    {
        fin>>x>>y>>d;
        if(d==1)
            for(j=x-1;j>=1;j--)
                    a[j][y].v--;
        if(d==2)
            for(j=y+1;j<=n;j++)
                    a[x][j].v--;
        if(d==3)
            for(j=x+1;j<=n;j++)
                    a[j][y].v--;
       if(d==4)
            for(j=y-1;j>=1;j--)
                    a[x][j].v--;
    }

}
int main()
{
    citire();
    bordare();
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(groapa(i,j)==1)
            {
                nrg++;
                a[i][j].g=1;
            }
    if(c==1)fout<<nrg<<'\n';
    else
    {
        for(i=1;i<=n;i++)
        {
            l=0;
            for(j=1;j<=n;j++)
                if(a[i][j].g==1)l++;
                else
                {
                    if(l>=2)nrt++;
                    l=0;
                }
           if(l>=2)nrt++;


        }
        fout<<nrt<<'\n';

    }
    return 0;
}
