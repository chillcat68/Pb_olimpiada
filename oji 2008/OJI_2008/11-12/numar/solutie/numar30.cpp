//problema numar - stelian ciurea
//generare directa, vector de contorizare = 30 puncte
#include <fstream.h>
long a[1001];
long n,m,i,j,k,h,nr1,lim;
char huge ct[255001];


ifstream fi("numar.in");
ofstream fout("numar.out");


void main()
{ //cout<<endl;
  fi>>n>>m;
  for (i=1;i<=n;i++)
     fi>>a[i];

  lim = m*a[1];  //limita pana la care pot fi valori in sir

  for (k=1;k<=n;k++)
    for (i=1;i*a[k]<=lim;i++)
      ct[i*a[k]]=1;
  j=0;
  for (i=1;j!=m;i++)
    if (ct[i]==1)
    {
//       cout<<i<<' ';
       j++;
    }

  fout<<i-1<<endl;
}