/*
	Sursa 100p
	prof. Radu Visinescu, Ploiesti
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("panda.in");
ofstream fout("panda.out");
int n,m,t,a[501][501],lungime[501][501],tarc[501][501];
int l,c,k,s;
int p;
int ok(int n,int k,int s)
{int vn[10],kn[10],p,o,modulo,i;
    modulo=1;
    for(i=1;i<=s;i++) modulo=modulo*2;
    n=n%modulo;k=k%modulo;
    p=0;
    while (p<s){p++;vn[p]=n%2;n=n/2;}
    p=0;
    while(p<s){p++;kn[p]=k%2;k=k/2;}
    o=1;
    for(p=1;p<=s;p++)
     if (!((vn[p]||kn[p])&&((vn[p]&&kn[p])==0)))
        o=0;
    return o;
}
void lee()
{ int q[2][250000],prim,ultim,i,j;
for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
  lungime[i][j]=-1;
prim=ultim=0;
ultim++;q[0][ultim]=l;q[1][ultim]=c;lungime[l][c]=0;
  while((prim<ultim))
   {prim++;i=q[0][prim];j=q[1][prim];
    if ((i>0)&&ok(a[i-1][j],k,s)){if (lungime[i-1][j]==-1){lungime[i-1][j]=lungime[i][j]+1;
                   ultim++;q[0][ultim]=i-1;q[1][ultim]=j;}}
    if ((i<n)&&ok(a[i+1][j],k,s)){if (lungime[i+1][j]==-1){lungime[i+1][j]=lungime[i][j]+1;
                   ultim++;q[0][ultim]=i+1;q[1][ultim]=j;}}
    if ((j>0)&&ok(a[i][j-1],k,s)){if (lungime[i][j-1]==-1){lungime[i][j-1]=lungime[i][j]+1;
                   ultim++;q[0][ultim]=i;q[1][ultim]=j-1;}}
    if ((j<m)&&ok(a[i][j+1],k,s)){if (lungime[i][j+1]==-1){lungime[i][j+1]=lungime[i][j]+1;
                   ultim++;q[0][ultim]=i;q[1][ultim]=j+1;}}
   }
}
int main()
{long long i,j,x,y,mi,nr;
fin>>p;
fin>>n>>m>>t;
fin>>l>>c>>k>>s;;
for (i=1;i<=t;i++)
 {fin>>x>>y;tarc[x][y]=1;}
for (i=1;i<=n;i++)
 for(j=1;j<=m;j++)
  fin>>a[i][j];
lee();
mi=1000000;
          for(i=1;i<=n;i++)
           for(j=1;j<=m;j++)
            if(tarc[i][j]==1 && mi>lungime[i][j] && lungime[i][j]!=-1)mi=lungime[i][j];
if(p==1){nr=0;
        for(i=1;i<=n;i++)
           for(j=1;j<=m;j++)
		    if((i!=l)||(j!=c)) if (ok(a[i][j],k,s))nr++;
			fout<<nr<<'\n';}
else {nr=0;
      for(i=1;i<=n;i++)
           for(j=1;j<=m;j++)
            if(tarc[i][j]==1 && mi==lungime[i][j])nr++;
       fout<<mi<<" "<<nr<<'\n';}
fin.close();
fout.close();
    return 0;
}
