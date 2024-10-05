// prof. Sofia Vitelaru
// Colegiul National "Fratii Buzesti" Craiova
#include <fstream>

using namespace std;
ifstream f("defrag.in");
ofstream g("defrag.out");
int a[101][801],fr[101],n,m,i,j,v,p,s,x,y,c,nr;
int main()
{
    f>>v>>p>>s>>c;
    for(i=1;i<=c;i++){
        f>>x>>y;
        a[x][y]=1;
        a[x][y+s]=1;

        fr[x]++;
    }
    for(i=1;i<=p;i++)
        for(j=1;j<=2*s;j++){
            a[i][j]+=a[i][j-1];

        }
    nr=0;
    if(v==1){
        for(i=1;i<=p;i++)
              if(fr[i]==0)
                   nr++;
        g<<nr;
       return 0;
    }
    for(i=1;i<=p;i++)
    {
        nr=0;
        if(fr[i]==0)
          {
            g<<0<<" ";
            continue;
          }
         int min=fr[i];
         for(j=1;j<=2*s-fr[i]-1;j++)
               if(fr[i]-(a[i][j+fr[i]-1]-a[i][j-1])<min)
                   min=fr[i]-(a[i][j+fr[i]-1]-a[i][j-1]);
         g<<min<<" ";

    }
    return 0;
}
