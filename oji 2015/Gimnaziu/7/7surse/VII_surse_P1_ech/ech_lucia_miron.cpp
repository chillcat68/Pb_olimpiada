//Lucia Miron
//numerele echilibrate sunt divizibile cu 11, verific doar aceste numere
#include <fstream>
using namespace std;
ifstream fin("ech.in");
ofstream fout("ech.out");
int n,v[50],r;
void citire()
{
    char ch;
    int i,aux;
    while(fin>>ch)
      n++,v[n]=ch-'0';
    for(i=1;i<=n/2;i++)
        aux=v[i],v[i]=v[n+1-i],v[n-i+1]=aux;
    v[0]=n;
}
void aduna11(int r)
{
    int i,t,aux;
    t=r;
    for(i=1;i<=v[0];i++)
    {
        aux=v[i]+t;
        v[i]=aux%10;
        t=aux/10;
    }
    if(t)v[++v[0]]=t;
}
int ech()
{
   int i,sp=0,si=0;
   for (i=1;i<=v[0];i++)
    if(i%2)si+=v[i];
   else sp+=v[i];
   if(si==sp)return 1;
   else return 0;
}
int rest11()
{
    int i,r=0;
    for(i=v[0];i>=1;i--)
        r=(r*10+v[i])%11;
    return r;
}
void afis()
{
    int i;
    for(i=v[0];i>=1;i--)
        fout<<v[i];
    fout<<'\n';
}
int main()
{
    citire();
    r=rest11();
    if(r)aduna11(11-r);
    else aduna11(11);
    while(!ech())aduna11(11);
    afis();
    fout.close();
    return 0;
}
