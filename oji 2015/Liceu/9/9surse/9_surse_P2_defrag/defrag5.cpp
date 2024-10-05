// prof. Carmen Popescu
// Colegiul National "Gheorghe Lazar" Sibiu

#include <fstream>

using namespace std;

ifstream f("defrag.in");
ofstream g("defrag.out");

int a[101][361];

int main()
{
    int v,p,s,c,x,y,i,j,m,b,k;

    f>>v;
    f>>p>>s;
    f>>c;
    for (i=1;i<=c;i++)
    {
        f>>x>>y;
        a[x][y]=1;
        a[x][0]++;
     }
    if (v==1)
    {
        j=0;
        for (i=1;i<=p;i++)
            if (a[i][0]==0)
                j++;
        g<<j<<"\n";
        g.close();
    }
    else
        for (i=1;i<=p;i++)
        {
            k=a[i][0];
            if (k==0 || k==1 || k==s || k==s-1)
		                g<<0<<" ";
            else
            {
                b=0;
                for (j=1;j<=k;j++)
                    b=b+a[i][j];
                m=b;
                for (j=2;j<=s-k+1;j++)
                {
                    b=b-a[i][j-1]+a[i][j+k-1];
                    if (b>m)
                        m=b;
                }

                // zonele de la final de pista care se completeaza la inceptul pistei
                for (j=1;j<=k-1;j++)
                {
                    b=b-a[i][s-k+j]+a[i][j];
                    if (b>m)
                        m=b;
                }
                g<<k-m<<" ";
            }

        }
    g<<"\n";
    g.close();
    return 0;
}
