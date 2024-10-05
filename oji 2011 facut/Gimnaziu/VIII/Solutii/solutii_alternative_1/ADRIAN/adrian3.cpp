//AUTOR SURSA: Panaete Adrian
//COMPILAT: Borland
//PUNCTAJ: 100 puncte
//ALGORITM: BACKTRAKING RECURSIV
#include<stdio.h>
int cerut,n,i,Cnt[10],Plus[10],Minus[10],semn[21],x[21],gata,MINUS=-1,PLUS=1;
void read(),solve(),back(int,int);
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("adunscad.in","r",stdin);
	freopen("adunscad.out","w",stdout);
	scanf("%d%d",&cerut,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		Cnt[x[i]]++;
	}
}
void solve()
{
	back(1,0);
	if(!gata){printf("0\n");return;}
	for(i=1;i<=n;i++)
	{
		if(Minus[x[i]])
		{ semn[i]=MINUS;Minus[x[i]]--;}
		else
		{ semn[i]=PLUS;Plus[x[i]]--;}
	}
	semn[1]==MINUS?printf("-%d",x[1]):printf("%d",x[1]);
	for(i=2;i<=n;i++)
		semn[i]==MINUS?printf("-%d",x[i]):printf("+%d",x[i]);
	printf("\n");		
}
void back(int c,int r)
{
	int plus,minus;
	if(c==10)
	{
		if(r==cerut)gata=1;
		return;
	}
	if(!Cnt[c]){back(c+1,r);return;}
	for(plus=0,minus=Cnt[c];minus>=0;plus++,minus--)
	{
		back(c+1,r+(plus-minus)*c);
		if(gata){Plus[c]=plus;Minus[c]=minus;return;}
	}
}

