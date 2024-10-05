/* prof. Sofia Vitelaru
   Colegiul National "Fratii Buzesti" Craiova
*/
#include <fstream>

using namespace std;
ifstream f("arc.in");
ofstream g("arc.out");
struct secv{
int c,st,nr;
}v[10001];
int n,i,j,p,x,y,Max,poz,nr,t;
int main()
{
    f>>p>>n;
    f>>x;nr=1;
    v[1].c=x;
    v[1].st=1;
    for(i=2;i<=n;i++){
        f>>y;
        if(x!=y){
            v[nr].nr=i-v[nr].st;
            nr++;
            v[nr].c=y;
            v[nr].st=i;
        }
      x=y;
    }
v[nr].nr=n-v[nr].st+1;
    if(p==1){
       g<<nr;
        return 0;
    }
    Max=0;poz=0;
      for(i=1;i<=nr;i++){
            if(v[i].nr>=3&&v[i].nr>Max)
            {
                Max=v[i].nr;
                poz=i;
            }
            t=t+v[i].nr;
        }
    while(1<2){
      if(poz==0)
            break;
     if(poz>1&&poz<nr&&v[poz-1].c==v[poz+1].c&&v[poz-1].nr+v[poz+1].nr>=3){
                v[poz-1].nr+=v[poz+1].nr;
                for(j=poz+2;j<=nr;j++)
                    v[j-2]=v[j];
                nr-=2;
                poz--;
                continue;
     }
     if(poz>1&&poz<nr&&v[poz-1].c==v[poz+1].c){
        v[poz-1].nr+=v[poz+1].nr;
                for(j=poz+2;j<=nr;j++)
                    v[j-2]=v[j];
                nr-=2;

     }
     else{
     for(j=poz+1;j<=nr;j++)
        v[j-1]=v[j];
     nr--;
     }
      Max=0;poz=0;t=0;
   for(i=1;i<=nr;i++){
            if(v[i].nr>=3&&v[i].nr>Max)
            {
                Max=v[i].nr;
                poz=i;
            }
            t=t+v[i].nr;
        }

    }
    g<<t<<'\n';
  for(i=1;i<=nr;i++)
      for(j=1;j<=v[i].nr;j++)
        g<<v[i].c<<"\n";
    return 0;
}
