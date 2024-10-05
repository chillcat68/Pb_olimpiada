//problema numar - stelian ciurea
//interclasare optimizata - 50 puncte
#include <fstream.h>
long a[1001];
long n,m,i,j,k,h,nr1,lim;
long huge sir1[10001],sir2[10001];


ifstream fi("numar.in");
ofstream fout("numar.out");


void main()
{ //cout<<endl;
  fi>>n>>m;
  for (i=1;i<=n;i++)
     fi>>a[i];

  lim = m*a[1];  //limita pana la care pot fi valori in sir

  k = n;                //interclasare de la n la 1
  while (a[k]>lim) k--;

  for (i=1;i*a[k]<=lim;i++)
    sir1[i]=i*a[k];
  nr1 = i;
  for (k=k-1;k>=1;k--)
  {i=1;
   j=1;
   h=1;
   while (h<=m && j*a[k]<=lim)
     if (sir1[i]<j*a[k])
       {sir2[h]=sir1[i];i++;h++;}
     else
      if (sir1[i]==j*a[k])
	 {sir2[h]=sir1[i];j++;i++;h++;}
      else
       {sir2[h]=j*a[k];j++;h++;}

   nr1 = h-1;
   for (i=1;i<=nr1;i++)
     sir1[i] = sir2[i];
  }
/*  for (i=1;i<=m;i++)
    cout<<sir1[i]<<' ';
*/
  fout<<sir1[m]<<endl;
  fout.close();


}
