//AUTOR SURSA: Panaete Adrian
//COMPILAT: Borland
//PUNCTAJ: 100 puncte
//ALGORITM: PROGRAMARE DINAMICA
#include<stdio.h>
int val,m,i,v[21],st,dr,j;
char y[21][370],*x[21],s[21];
int main()
{
	freopen("adunscad.in","r",stdin);
	freopen("adunscad.out","w",stdout);
	scanf("%d%d",&val,&m);
	for(i=1;i<=m;i++)scanf("%d",&v[i]);
	for(i=0;i<=m;i++)x[i]=y[i]+181;
	x[0][0]=3;
	for(i=1;i<=m;i++)
	{
		for(j=st;j<=dr;j++)
			if(x[i-1][j])
			{
				x[i][j+v[i]]=1;
				x[i][j-v[i]]=2;
			}
		st-=v[i];dr+=v[i];
	}
	if(!x[m][val])
		printf("0\n");
	else
	{
		for(i=m;i>=1;i--)
		{
			if(x[i][val]==1)
			{s[i]='+';val-=v[i];}
			else
			{s[i]='-';val+=v[i];}
		}
		if(s[1]=='-')printf("-");
		for(i=1;i<m;i++)
			printf("%d%c",v[i],s[i+1]);
		printf("%d\n",v[m]);
	}
	return 0;
}

	