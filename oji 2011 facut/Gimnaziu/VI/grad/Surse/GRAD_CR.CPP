#include<fstream.h>
ifstream f("grad.in");
ofstream g("grad.out");
int v[10001],w[10001],n,k,i,p,x,y,j,max,t;

void ordo(int m)
{int aux,o,i;
  do{o=1;
     for(i=1;i<m;i++) 
		 if(w[i]>w[i+1])aux=w[i],w[i]=w[i+1],w[i+1]=aux,o=0;
	 m--;}while(!o);	
}

int egale(int d,int n)
{ int i,x=0;
  for(i=1;i<=n;i++) x+=(v[i+d]==w[i]);
  return x;
}

int main()
{ f>>n>>k;
  for(i=1;i<=n;i++) f>>v[i],w[i]=v[i];
  //a
  ordo(n);
  g<<egale(0,n)<<'\n';
  //b
  for(i=1;i<=k;i++) w[i]=v[i];
  ordo(k);
  max=egale(0,k);
  p=1;
  for(i=k+1;i<=n;i++)
  { 
	x=v[i-k],y=v[i],j=1;
	while(w[j]!=x)j++;
	w[j]=y;
	while(j<k && y>w[j+1])w[j]=w[j+1],w[j+1]=y,j++;
	while(j>1 && y<w[j-1])w[j]=w[j-1],w[j-1]=y,j--;
	x=egale(i-k,k);
    if(x>max) max=x,p=i-k+1;	
  }
  g<<p<<' '<<max<<'\n';
  f.close();g.close();
  return 0;  
}