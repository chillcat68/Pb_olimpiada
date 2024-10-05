#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream f("oneout.in");
    ofstream g("oneout.out");
    int c;
    f>>c;
    switch (c)
    {
	case 1:
		{
			int ct=0, i, d, n, ok, x;
			f>>n;
			for (i=1; i<=n; i++) {
				ok=1;
				f>>x;
				for (d=2; d<=x/2; d++)
					if (x%d==0 && sqrt(d)==(int)sqrt(d)) {
						ok=0;
						break;
					}
				if (ok==1)
					ct++;
			}
			g<<ct;
		}break;

	case 2:
		{
			int n, m=0, k=0, i, j, t, lmax=0, x;
			bool a[1000001]={0};
			f>>n;
			int poz1[100001], poz2[100001];
			//ciur pt nre libere de patrate
			for (i=2; i*i<1000; i++)
				for (j=i*i; j<=1000000; j=j+i*i)
					a[j]=1;
			bool w[n];//pt valorile din fisier daca is ori nu-s
			for (i=1; i<=n; i++)
			{
				f>>x;
				w[i]=a[x];
			}


			for (i=2; i<=n-1; i++)
			{
				if (w[i]==1 && w[i-1]==0 && w[i+1]==0)
				{
					t=i-1;
					while (w[t-1]==0)
						t--;
					k=i+1;
					while (w[k+1]==0)
						k++;
					if (k-t>lmax)
					{
						lmax=k-t;
						m=0;
						poz1[++m]=t;
						poz2[m]=k;
					}
					else if (k-t==lmax)
					{
						poz1[++m]=t;
						poz2[m]=k;
					}


				}
			}
			if (m==0)
				g<<-1;
			else
			{
				g<<lmax<<' '<<m<<'\n';
				for (i=1; i<=m; i++)
					g<<poz1[i]<<' '<<poz2[i]<<'\n';
			}
			/*
			for (i=1; i<=100; i++)
				if (a[i]==0)
					v[++k]=i;

			for (i=1; i<=n; i++)
				f>>nr[i];

            for (i=1; i<=n; i++) {
				j=nr[i];
				if (a[j]==1) {
					for (t=i; a[nr[t]]==0 && t>=1; t--)
						lcrt++;
					for (k=i; a[nr[k]]==0 && k<=n; k++)
						lcrt++;
					if (lcrt>lmax) {
						lmax=lcrt;
						lcrt=0;
						ctlmax=1;
						poz1[1]=t; poz2[1]=k;
						A=1;
					}
					else if (lcrt==lmax) {
						ctlmax++;
						poz1[A++]=t;
						poz2[A]=k;
					}
				}
            }
            if (ctlmax>1) {
				g<<lmax<<' '<<ctlmax<<'\n';
				for (i=1; i<=A; i++)
					g<<poz1[i]<<' '<<poz2[i]<<'\n';
            }
            else if (ctlmax==1)
				g<<lmax<<' '<<1<<'\n'<<poz1[1]<<' '<<poz2[1];
			*/



		}break;
    }
    return 0;
}
