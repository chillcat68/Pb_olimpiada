#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("cri.in");
    ofstream g("cri.out");
    int n, m, i, j, x, y;
    int mini, ct1=0, ct2=0, ct3=0, ct4=0;
    int zona, ct;
    unsigned long s1=0, s2=0, s3=0, s4=0, total;

    f>>n>>m;
    f>>x>>y;
    int a[n+1][m+1];
    for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			f>>a[i][j];

	//zona 1----------------------
	mini=a[x][y];
	for (i=1; i<=x; i++)
	{
		for (j=1; j<=y; j++)
		{
			s1+=a[i][j];
			ct1++;
			if (a[i][j]<mini)
				mini=a[i][j];
		}
	}
	if (y%2==0 && x%2==0)
	{
		s1=s1-mini;
		ct1--;
	}
	zona=1;
	total=s1;
	ct=ct1;

	//zona 2----------------------
	mini=a[x][y];
	for (i=1; i<=x; i++)
	{
		for (j=y; j<=m; j++)
		{
			s2+=a[i][j];
			ct2++;
			if (a[i][j]<mini)
				mini=a[i][j];
		}
	}
	if ((m-y+1)%2==0 && x+%2==0)
	{
		s2=s2-mini;
		ct2--;
	}
    if (s2>total ||(total==s2 && ct>ct2))
    {
        zona=2;
        total=s2;
        ct=ct2;
    }

	//zona 3----------------------
	mini=a[x][y];
	for (i=x; i<=n; i++)
	{
		for (j=1; j<=y; j++)
		{
			s3+=a[i][j];
			ct3++;
			if (a[i][j]<mini)
				mini=a[i][j];
		}
	}
	if (y%2==0 && (n-x+1)%2==0)
	{
		s3=s3-mini;
		ct3--;
	}
    if (s3>total ||(total==s3 && ct>ct3))
    {
        zona=3;
        total=s3;
        ct=ct3;
    }

	//zona 4----------------------
	mini=a[x][y];
	for (i=x; i<=n; i++)
	{
		for (j=y; j<=m; j++)
		{
			s4+=a[i][j];
			ct4++;
			if (a[i][j]<mini)
				mini=a[i][j];
		}
	}
	if ((m-y+1)%2==0 && (n-x+1)%2==0)
	{
		s4=s4-mini;
		ct4--;
	}
    if (s4>total ||(total==s4 && ct>ct4))
    {
        zona=4;
        total=s4;
        ct=ct4;
    }

    g<<zona<<' '<<total<<' '<<ct;
    return 0;
}
