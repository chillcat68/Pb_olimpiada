#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("arc.in");
    ofstream g("arc.out");
    int v;
    f>>v;

    switch(v)
    {
	case 1:
		{
			int n, i, x, ct=1, ant;
			f>>n;
			f>>ant;
			for (i=1; i<=n; i++)
			{
				f>>x;
				if(x!=ant)
					ct++;
				ant=x;
			}
			g<<ct;

		}break;

	case 2:
		{
			int cul[10001], ap[10001]={0}, n, x, i, y, k, maxi=0, poz, ok=1, s=0, j;
			f>>n;
			f>>x;
			cul[1]=x;
			ap[1]=1;
			k=1;
			while (f>>y)
			{
				if(y==x)
					ap[k]++;
				else
				{
					cul[++k]=y;
					ap[k]=1;
				}
				x=y;
			}


			do{
				maxi=0;
				for(i=1; i<=k; i++)
					if(ap[i]>maxi)
					{
						maxi=ap[i];
						poz=i;
					}
				if (maxi>=3)
				{

				//cout<<maxi<<" "<<poz<<endl;
				//intreb de vecini
				if (cul[poz-1]==cul[poz+1])//vecinii au aceeasi culoare
				{
					ap[poz-1]+=ap[poz+1];
					for (int j=poz; j<=k-2; j++)
					{
						cul[j]=cul[j+2];
						ap[j]=ap[j+2];
					}
					k=k-2;
				}
				else
				{
					for (int j=poz; j<=k-1; j++)
					{
						cul[j]=cul[j+1];
						ap[j]=ap[j+1];
					}
					k--;
				}
				}
				else
					ok=0;

			}while (ok==1);

			for (i=1; i<=k; i++)
				s=s+ap[i];
			g<<s<<'\n';

			for (i=1; i<=k; i++)
				for (j=1; j<=ap[i]; j++)
					g<<cul[i]<<'\n';
		}break;
    }

    return 0;
}
