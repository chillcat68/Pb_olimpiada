#include<fstream.h>
#include<ctype.h>
char s;
int n;
int c0,c1,c2,c3,c4,c5,c6,c7,c8,c9;
int main()
{
	int i;
	int nr;
	ifstream f("magic.in");
	ofstream g("magic.out");
	f>>n;
	for (i=1;i<=n;i++)
	{
		f>>s;
		if(isalpha(s))
		{
			s=toupper(s);
			g<<s;
		}
		else
		{
			nr=int(s)-48;
			switch(nr)
			{
			case 0: c0++;break;
			case 1: c1++;break;
			case 2: c2++;break;
			case 3: c3++;break;
			case 4: c4++;break;
			case 5: c5++;break;
			case 6: c6++;break;
			case 7: c7++;break;
			case 8: c8++;break;
			case 9: c9++;break;
			}
		}
	}
	g<<'\n';
	int t=0;
	if(c1)
	{
	   g<<1;
	   if(c0 && t==0)
	   {
	      t=1;
	      g<<0;
	   }
	}
	if(c2)
	{
	   g<<2;
	   if(c0 && t==0)
	   {
	      t=1;
	      g<<0;
	   }
	}
	if(c3)
	{
	   g<<3;
	   if(c0 && t==0)
	   {
	      t=1;
	      g<<0;
	   }
	}
	if(c4)
	{
	   g<<4;
	   if(c0 && t==0)
	   {
	      t=1;
	      g<<0;
	   }
	}
	if(c5)
	{
	   g<<5;
	   if(c0 && t==0)
	   {
	      t=1;
	      g<<0;
	   }
	}
	if(c6)
	{
	   g<<6;
	   if(c0 && t==0)
	   {
	      t=1;
	      g<<0;
	   }
	}
	if(c7)
	{
	   g<<7;
	   if(c0 && t==0)
	   {
	      t=1;
	      g<<0;
	   }
	}
	if(c8)
	{
	   g<<8;
	   if(c0 && t==0)
	   {
	      t=1;
	      g<<0;
	   }
	}
	if(c9)
	{
	   g<<9;
	   if(c0 && t==0)
	   {
	      t=1;
	      g<<0;
	   }
	}
        if(t==0 && c0)
           g<<0;
	f.close();
	g.close();
	return 0;
}
