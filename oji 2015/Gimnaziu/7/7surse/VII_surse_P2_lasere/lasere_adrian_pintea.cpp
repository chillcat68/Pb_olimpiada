//Pintea Adrian Doru -Inspectoratul Scolar Judetean Cluj
#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("lasere.in");
ofstream fout("lasere.out");

int a[202][202];
int cerinta,i,j,m,n,x,y,z,d;

int N(int x,int y)
{
   int k;
   for(k=1;k<x;k++)
    if(a[k][y]>0) a[k][y]--;
return 0;
}

int S(int x,int y)
{
   int k;
   for(k=x+1;k<=n;k++)
    if(a[k][y]>0) a[k][y]--;
return 0;
}

int V(int x,int y)
{
   int k;
   for(k=1;k<y;k++)
    if(a[x][k]>0) a[x][k]--;
return 0;
}

int E(int x,int y)
{
   int k;
   for(k=y+1;k<=n;k++)
    if(a[x][k]>0) a[x][k]--;
return 0;
}

int groapa(int x,int y)
{
 if(a[x][y]<=a[x][y+1]&&a[x][y]<=a[x][y-1]&&a[x][y]<=a[x+1][y]&&
    a[x][y]<=a[x-1][y]&&a[x][y]<=a[x+1][y+1]&&a[x][y]<=a[x-1][y+1]&&
    a[x][y]<=a[x-1][y-1]&&a[x][y]<=a[x+1][y-1])
  return 1;else return 0;
}

int transee(int l)
{
    int k=0,p=1,q;
    while(p<n)
    {
        q=1;
        while((a[l][p]==a[l][p+q])&&groapa(l,p)&&groapa(l,p+q)) q++;
        if(q>1) k++;
        p=p+q;
    }
    return k;
}

int main()
{

    fin>>cerinta;
    fin>>n>>m;
    int max=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            {fin>>a[i][j];if(a[i][j]>max) max=a[i][j];}
    max++;
    for(i=0;i<=n+1;i++){a[0][i]=max;a[n+1][i]=max;a[i][0]=max;a[i][n+1]=max;}

    for(i=1;i<=m;i++)
    {
        fin>>x>>y>>d;
        if(d==1) N(x,y);
        else if(d==2) E(x,y);
             else if(d==3) S(x,y);
                    else V(x,y);
    }
    fin.close();




    int nrT=0,nrG=0;

    if(cerinta==1)
    {
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
         if(groapa(i,j))nrG++;
      fout<<nrG<<'\n';
    }
    else
    {
        for(i=1;i<=n;i++) nrT+=transee(i);
        fout<<nrT<<'\n';
    }
    fout.close();
    return 0;
}
