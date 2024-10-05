#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int v[300], m, i, j, d, k=1;
    m=50;
    for (i=1; i<=m; i++)
        v[i]=i;

    for (i=1; i<=m; i++)
    {
        k=1;
        for (d=2; d<=v[i]/2; d++)
        {
            if(v[i]%d==0)
            {
                m++;
                for (j=m; j>=i+k; j--)
                    v[j]=v[j-1];
                v[i+k]=d;
                k++;
            }
        }
        i=i+k-1;
    }


    int n, a[11][11], nr, indice;
    cout<<"n=";
    cin>>n;
    for (i=1; i<=n-1; i++)
        for (j=1; j<=n-i; j++)
        {
            indice=pow(n,2)+i+j;
            nr=v[indice];
            a[i][j]=nr%10;
        }

    for (i=2; i<=n; i++)
        for (j=n-i+2; j<=n; j++)
        {
            indice=pow(n,2)+i+j;
            nr=v[indice];
            while (nr>9)
                nr/=10;
            a[i][j]=nr;
        }
    int maxi;
    for (i=1; i<=n; i++)
    {
        maxi=0;
        indice=pow(n,2)+pow(i,2);
        nr=v[indice];
        while (nr!=0)
        {
            if(nr%10>maxi)
                maxi=nr%10;
            nr/=10;
        }
        a[i][n-i+1]=maxi;
    }

    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
            cout<<setw(3)<<a[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
