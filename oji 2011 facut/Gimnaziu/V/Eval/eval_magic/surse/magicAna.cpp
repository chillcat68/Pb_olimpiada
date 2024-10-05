#include <fstream.h>
ifstream f("magic.in");
ofstream g("magic.out");
int n,i;
char c;
int x[10];

int main()
{
	f>>n;
	for(i=1;i<=n;i++)
	{
	   f>>c;
	   if(c>='a' && c<='z')	g<<(char)(c-32);
	   else	x[c-48]=1;
	}  
	g<<'\n';
	if(x[0]!=0)
	{
		i=1;
		while(x[i]==0 && i<=9)i++;
	}
	if(i<=9){g<<i;x[i]=0;}
	for(i=0;i<=9;i++)
		if(x[i]) g<<i;
	f.close();
	g.close();
	return 0;
}