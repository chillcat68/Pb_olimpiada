#include <fstream.h>
int n,k,j,i,a[10001],ma,nr,b[10001],ind;
int main ()
{
	ifstream f("grad.in");
	f>>n>>k;
	for(i=1;i<=n;i++)
	f>>a[i];
	f.close();

	for(i=1;i<=k;i++)
	{
					 for(j=1;j<i;j++)
									  if(a[i]>a[j])
													b[i]++;
									  else
													b[j]++;
	}
	for(i=1;i<=k;i++)
					 if(b[i]+1==i)
								  ma++;
	ind=1;
	if(k!=n)
	{
			for(i=k+1;i<=n;i++)
			{
					   nr=0;
					   for(j=1;j<k;j++)
                       {
									   if(a[i-j]<a[i])
                                                      b[i]++;
									   else
													  b[i-j]++;
									   if(a[i-j]>a[i-k])
														b[i-j]--;
									   if(b[i-j]+1==k-j)
													   nr++;

					   }
					   if(b[i]+1==k)
									nr++;
					   if(nr>ma)
					   {
								ma=nr;
								ind=i-k+1;
								if(ma==k)
										 break;
					   }
			}
			for(i=1;i<=n;i++)
					 b[i]=0;
			nr=0;
			for(i=1;i<=n;i++)
			{
					 for(j=1;j<i;j++)
									  if(a[i]>a[j])
													b[i]++;
									  else
													b[j]++;
			}
			for(i=1;i<=n;i++)
					 if(b[i]+1==i)
								  nr++;
	}
	ofstream g("grad.out");
	if(k!=n)
			g<<nr<<'\n';
	else
			g<<ma<<'\n';
	g<<ma<<" "<<ind;
	g.close();

	return 0;
}
