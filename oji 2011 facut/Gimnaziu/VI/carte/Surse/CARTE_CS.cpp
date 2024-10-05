#include<fstream.h>
ifstream f("carte.in");
ofstream g("carte.out");
int n,u[10001],i,p,m,max,imax,z,nr;
int main()
{ f>>n;
  for(i=1;i<=n;i++) {f>>p;u[p]=i;}
  for(i=1;i<=n;i++)if(u[i]!=0){nr=1,p=i,m=u[i],z++;
		          while(p<n && u[p+1]>m)nr++,p++,m=u[p],u[p]=0;
		          if(nr>max)max=nr,imax=z;
		        }
  g<<z<<' '<<imax<<' '<<max<<' '<<'\n';

  return 0;
}
