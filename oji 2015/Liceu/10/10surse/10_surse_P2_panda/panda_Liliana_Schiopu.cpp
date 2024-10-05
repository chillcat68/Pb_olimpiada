// prof. Liliana Schiopu - C.N.F.B., Craiova
// complexitate O(nxm)
// algoritmul Lee

#include <stdio.h>
using namespace std;
FILE *f=fopen("panda.in","r");
FILE *g=fopen("panda.out","w");
int n,m,t,i,j,p,a[510][510],b[510][510],x,y,viz[510][510];
int l,c,k,s,nr,coada[3][250001],ic,sc,timp[250001];
int i1[5]={-1,0,1,0},j1[5]={0,1,0,-1};
int smin=300000,nt;
int acc(int x1,int x2)
{
    int i=s;
    while(i>0)
    {
        if((x1%2)^(x2%2)==1)
        {
           x1/=2;
           x2/=2;
           i--;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    fscanf(f,"%d",&p);
    fscanf(f,"%d%d%d",&n,&m,&t);
    fscanf(f,"%d%d%d%d",&l,&c,&k,&s);
    for(i=1;i<=t;i++)
    {
        fscanf(f,"%d%d",&x,&y);
        b[x][y]=1;
    }
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        fscanf(f,"%d",&a[i][j]);
    if(p==1)
    {
        for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)
            if(i!=l||j!=c)
             if(acc(a[i][j],k))
               nr++;
        fprintf(g,"%d",nr);
    }
    else
    if(p==2)
    {
      ic=1;sc=1;
      coada[1][ic]=l;
      coada[2][ic]=c;
      viz[coada[1][ic]][coada[2][ic]]=1;
      timp[ic]=0;
      while(ic<=sc)
      {
        for(i=0;i<=3;i++)
          if(acc(a[coada[1][ic]+i1[i]][coada[2][ic]+j1[i]],k)&&a[coada[1][ic]+i1[i]][coada[2][ic]+j1[i]]!=0)
           if(viz[coada[1][ic]+i1[i]][coada[2][ic]+j1[i]]==0)
          {
            sc++;
            coada[1][sc]=coada[1][ic]+i1[i];
            coada[2][sc]=coada[2][ic]+j1[i];
            viz[coada[1][sc]][coada[2][sc]]=1;
            timp[sc]=timp[ic]+1;
            if(b[coada[1][sc]][coada[2][sc]]==1)
             {
              if(smin>timp[sc])
              {
                  smin=timp[sc];
                  nt=1;
              }
              else
               if(smin==timp[sc])
                {
                  nt++;
                }
             }
          }
          ic++;
      }
     fprintf(g,"%d %d",smin,nt);
    }
    fclose(f);
    fclose(g);
    return 0;
}

