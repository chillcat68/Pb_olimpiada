#include <stdio.h>
FILE *f,*g;
int n,i,j,m,k, v[500001];
int main()
{ f=fopen("ordine.in","r");
  g=fopen("ordine.out","w");
  fscanf(f,"%d",&n);
  for(i=1;i<=n;i++)
    fscanf(f,"%d",&v[i]);
  fscanf(f,"%d",&k);
  if(k==1) if(n%2==0) fprintf(g,"%d\n",v[n]);
                 else fprintf(g,"%d\n",v[n/2+1]);
    else
    { i=1;j=(n+1)/2;
      for(i=1;i<=n/2;i++) fprintf(g,"%d %d ",v[i],v[i+j]);
      if(n%2) fprintf(g,"%d",v[j]);
    }
  close(f); close(g);
    return 0;
}
