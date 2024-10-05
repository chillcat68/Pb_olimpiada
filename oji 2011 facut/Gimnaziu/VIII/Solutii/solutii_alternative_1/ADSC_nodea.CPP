//Solutie operatii pe biti - Eugen Nodea
//compilata in MinGW  =100p
//compilate in BC3.11 - 65p (peste 10 cifre!!!)

#include <stdio.h>

int n,m,a[31],i;
unsigned long fin;
int solutie(unsigned long x)
{
    int i,s=0;
    unsigned long b=1<<(m-1);
    for (i=1;i<=m;++i,b>>=1)
    {
	if (x & b)
	    s-=a[i];
	else
	    s+=a[i];
    }
    return (s==n);
}

void afiseaza(unsigned long x)
{
    unsigned long b=1<<(m-1);
    int i;
    for (i=1;i<=m;++i,b>>=1)
    {
	if (x & b)
	    printf("-");
	else if (i!=1)
	    printf("+");
	printf("%d", a[i]);
    }
    printf("\n");
}

int main()
{
    freopen("adunscad.in","r",stdin);
    freopen("adunscad.out","w",stdout);
    scanf("%d %d", &n, &m);
    for (i=1;i<=m;++i)
    {
	scanf("%d", &a[i]);
	fin=(fin<<1)+1;
    }
    for (i=0;i<=fin;++i)
	if (solutie(i))
	{
	    afiseaza(i);
	    return 0;
	}
    printf("0\n");
    return 0;
}
