//AUTOR SURSA: Panaete Adrian
//COMPILAT: Borland
//PUNCTAJ: 100 puncte
//ALGORITM: BACKTRAKING RECURSIV
#include<stdio.h>
char *ver(int,int),*sol,SOL[45];
int c,n,i,x[21];
void read(),solve();
int main()
{
	freopen("adunscad.in","r",stdin);
	freopen("adunscad.out","w",stdout);
	scanf("%d%d",&c,&n);
	for(i=1;i<=n;i++)scanf("%d",&x[i]);
	sol=ver(1,c);
	if(!sol){printf("0\n");return 0;}
	if(*sol=='+')sol++;
	printf("%s\n",sol);	
	return 0;	
}
char *ver(int p,int v)
{
	char *ret;ret=0;
	if(p==n)
	{
		if(v== x[n]){ret=SOL+2*n-1;*ret='0'+x[n];ret--;*ret='+';}
		if(v==-x[n]){ret=SOL+2*n-1;*ret='0'+x[n];ret--;*ret='-';}
		return ret;
	}
	if(ver(p+1,v-x[p])){ret=SOL+2*p-1;*ret='0'+x[p];ret--;*ret='+';return ret;}
	if(ver(p+1,v+x[p])){ret=SOL+2*p-1;*ret='0'+x[p];ret--;*ret='-';return ret;}
	return ret;
}

