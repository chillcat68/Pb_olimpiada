//panaete adrian

#include<stdio.h>
long n,i,k,val,T[2];
char L[300],ORD;
int main()
{
	freopen("comp.in","r",stdin);
	freopen("comp.out","w",stdout);
	scanf("%d",&n);
	for(;n;n--)
	{
		k=0;
		T[0]=T[1]=0;
		scanf("%s",L);
		for(i=0;L[i];i++)
		{
			if(L[i]=='+')continue;
			if(L[i]=='<'||L[i]=='>'){k=1;ORD=L[i];continue;}
			if(L[i]=='m'){T[k]+=val*1000;val=0;continue;}
			if(L[i]=='s'){T[k]+=val*100 ;val=0;continue;}
			if(L[i]=='z'){T[k]+=val*10  ;val=0;continue;}
			if(L[i]=='u'){T[k]+=val;    ;val=0;continue;}
			val*=10;val+=L[i]-'0';
		}
		if(ORD=='>')
			T[0]>T[1]?printf("1\n"):printf("0\n");
		else
			T[0]>T[1]?printf("0\n"):printf("1\n");
	}
	return 0;
}

