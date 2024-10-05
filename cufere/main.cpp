#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool prim(int n)
{
	int d;
	if (n!=2 && n%2==0)
		return false;
	else
	{
		for (d=3; d<=sqrt(n); d++)
			if(n%d==0)
				return false;
	}
	return true;
}

int main()
{
    ifstream f("cufere.in");
    ofstream g("cufere.out");
    int c;
    f>>c;
    switch (c)
    {
	case 1:
		{
			int ap[100]={0}, n, x, i;
			f>>n;
			while (f>>x)
				ap[x%100]=ap[x%100]+x/100;
			for (i=10; i<=99; i++)
				if(ap[i]!=0)
					g<<i<<' '<<ap[i]<<'\n';
		}break;
	case 2:
		{
			int ap[100]={0}, n, x, i, ct=0, ct2=0;
			f>>n;
			while (f>>x)
				ap[x%100]=ap[x%100]+x/100;
			for (i=1; i<=99; i++)
			{
				if (ap[i]!=0)
				{
					if(prim(i)==true)
					{
						while (ap[i]!=0)
						{
							if (ap[i]>16)
							{
								g<<16<<i<<' ';
								ap[i]=ap[i]-16;
								ct++; ct2++;
							}
							else
							{
								g<<ap[i]<<i<<' ';
								ap[i]=0;
								ct++; ct2++;
							}
							if(ct%9==0)
								g<<'\n';
						}
					}
					else
					{
						while (ap[i]!=0)
						{
							if (ap[i]>64)
							{
								g<<64<<i<<' ';
								ap[i]=ap[i]-64;
								ct++; ct2++;
							}
							else
							{
								g<<ap[i]<<i<<' ';
								ap[i]=0;
								ct++; ct2++;
							}
							if(ct%9==0)
								g<<'\n';
						}
					}
				}
			}
			while (ct2%9!=0)
			{
				g<<0<<' ';
				ct2++;
			}

			while (ct2<27*n)
			{
				if (ct2%9==0)
					g<<'\n';
				g<<0<<' ';
				ct2++;
			}
		}break;


    }

    return 0;
}
