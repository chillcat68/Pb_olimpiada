//adriana simulescu - 100 puncte
//bactracking
#include<fstream.h>
#include<stdlib.h>

ifstream f("adunscad.in");
ofstream g("adunscad.out");

int N,M,x[21],s[21];

void testare_afisare()
{int i,E=0;
 for(i=1;i<=M;i++)
	 if(s[i]==1)
		 E=E+x[i];
	 else
		 E=E-x[i];
if(E==N)
{if(s[1]==2) g<<"-";
g<<x[1];
for(i=2;i<=M;i++)
	{if(s[i]==1) g<<"+";
	 else g<<"-";
	g<<x[i];
	}
        g<<'\n';
	g.close();
exit(0);
}
}

void gen(int i)
{ if(i<=M)
	{s[i]=1;
	 gen(i+1);
	 s[i]=2;
	 gen(i+1);
	}
else{
    testare_afisare();
    }
}

int main()
{ int i;

	f>>N>>M;
	for(i=1;i<=M;i++)
		f>>x[i];
	gen(1);
        g<<0<<'\n';
	g.close();
	return 0;
}

