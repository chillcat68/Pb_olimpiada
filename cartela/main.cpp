#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("cartele.in");
    ofstream g("cartele.out");
    short n, c, i, j, k, ok, l;
    f>>n>>c;

    bool sablon[n+1][n+1], a[n+1][n+1], b[n+1][n+1];
    //citire sablon
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            f>>sablon[i][j];
    //verificare fiecare cartela
    for (k=1; k<=c; k++)
    {
        //citire cartela
        for (i=1; i<=n; i++)
            for (j=1; j<=n; j++)
                f>>a[i][j];
        //cartela are 8 combinatii posibile
        for (l=1; l<=8; l++)
        {
            //verificare egalitate sablon
            ok=1;
            for (i=1; i<=n; i++)
                for (j=1; j<=n; j++)
                    if(a[i][j]!=sablon[i][j])
                        ok=0;
            if(ok==1)
            {
                g<<1<<'\n';
                break;
            }
            //daca nu este egala trebuie rotita cu 90 grade in sens trigonometric
            else
            {
                for (i=1; i<=n; i++)
                    for (j=1; j<=n; j++)
                        b[i][j]=a[j][n-i+1];
                for (i=1; i<=n; i++)
                    for (j=1; j<=n; j++)
                        a[i][j]=b[i][j];
            }
            //daca suntem la a patra iteratie cartela trebuie intoarsa
            if (l==4)
            {
                for (i=1; i<=n; i++)
                    for (j=1; j<=n; j++)
                        b[i][j]=a[n-i+1][j];
                for (i=1; i<=n; i++)
                    for (j=1; j<=n; j++)
                        a[i][j]=b[i][j];
            }
        }
        if(ok==0)
            g<<0<<'\n';
    }
    return 0;
}
