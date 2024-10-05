#include <fstream.h>
int x[10002],y[10002],g,n,k,pmax,gmax,aux;
ifstream fin("grad.in");
ofstream fout("grad.out");
void cit(){
 int i;
 fin>>n>>k;
 for(i=1;i<=n;i++)
  fin>>x[i];
 fin.close();
}
void ordonare(int x[10002], int n){
 int i,j,aux;
  for(i=1;i<n;i++)
   for(j=i+1;j<=n;j++)
    if(x[i]>x[j]){
     aux=x[i];x[i]=x[j];x[j]=aux;
    }
}
int main(){
int i,j,gr;
cit();
for(i=1;i<=n;i++)
 y[i]=x[i];
ordonare(y,n);
g=0;
for(i=1;i<=n;i++)
 if(x[i]==y[i])
  g++;
fout<<g<<'\n';
for(i=1;i<=k;i++)
 y[i]=x[i];
ordonare(y,k);
gmax=0;
for(i=1;i<=k;i++)
 if(x[i]==y[i])
  gmax++;
pmax=1;
for(i=2;i<=n-k+1;i++)
 {
  for(j=1;j<=k;j++)
   if(y[j]==x[i-1])
    break;
  y[j]=x[i+k-1];//ducem y[j] pe pozitia corespunzatoare a. i. y sa ramana ord. cresc.
 ordonare(y,k);
  //determin gradul secventei care incepe cu x[i]
  gr=0;
  for(j=1;j<=k;j++)
   if(y[j]==x[i+j-1])
    gr++;
  if (gr>gmax){
   gmax=gr;pmax=i;
  }
 }
fout<<pmax<<" "<<gmax;
fout.close();
return 0;
}