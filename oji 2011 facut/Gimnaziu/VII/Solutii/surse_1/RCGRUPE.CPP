#include <fstream.h>
#include <math.h>

ifstream f("grupe.in");
ofstream g("grupe.out");

long int max[200], x[200];

long int nr_div(long int x)
{long int i,nr=2;
 for(i=2;i<=sqrt(x);i++)
  if (x%i==0) nr+=2;
 if ((int)sqrt(x)==sqrt(x)) nr--;
 return nr;
}

int main(){
long int nr,i,max1,max2,poz1,poz2,n,m;
long int a;
	f>>n>>m;
	for(i=1;i<=n*m;i++)
	 {f>>a;
	 nr=nr_div(a);
	  x[nr]++;
	  if (a>max[nr]) max[nr]=a;}
	f.close();
	max1 = x[2];
	poz1 = 2;
	max2=0;
	for(i=3;i<=200;i++)
		if (x[i]>=max1)
		 { max2 = max1;
		   poz2 = poz1;
		   max1 = x[i];
		   poz1 = i;
		} else
		   if (x[i]>=max2)
			 {max2 = x[i];
			  poz2 = i;
			}
	g<<poz1<<" "<<x[poz1]<<" "<<max[poz1]<<endl;
	if (max2==0)
		g<<"0 0 0";
	else
		g<<poz2<<" "<<x[poz2]<<" "<<max[poz2];
	g.close();
	return 0;
}