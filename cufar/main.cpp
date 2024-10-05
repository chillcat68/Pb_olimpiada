#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("cufar.in");
    ofstream g("cufar.out");
    int p;

        /* FORMAM VECTOR CU NR PRIME PANA LA 1 000 000
        FOLOSIND CIURUL LUI ERATOSTENE */

    bool v[1000001]={0};
    int m=1000000, j, i;
    v[0]=v[1]=1;

    for (i=2; i*i<=m; ++i)
        if (v[i]==0)
          for (j=2; j*i<=m; ++j)
                v[i*j]=1;

    int prim[100000], k=0;

    for (i=2; i<=m; i++)
        if (v[i]==0)
            prim[++k]=i;

        /*PROBLEMA PRORPIU ZISA*/
    f>>p;

    switch (p)
    {
    case 1:
        {
            int n, nr, ct;
            f>>n;
            for (i=1; i<=n; i++)
                f>>nr>>ct;
            for (i=1; i<=k && ct!=0; ++i)
                if(nr%prim[i]==0)
                {
                    ct--;
                    while (nr%prim[i]==0)
                        nr=nr/prim[i];
                }
            g<<prim[i-1];
        }break;
    case 2:
        {
            int n, nr, ct, s=0;
            f>>n;
            for (int t=1; t<=n; ++t)
            {
                f>>nr>>ct;
                for (i=1; i<=k && ct!=0; ++i)
                    if(nr%prim[i]==0)
                    {
                        ct--;
                        while (nr%prim[i]==0)
                            nr=nr/prim[i];
                    }
                s+=prim[i-1];
            }
            g<<s;
        }break;
    }


    return 0;
}
