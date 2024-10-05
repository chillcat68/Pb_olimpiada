#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ifstream f("roata.in");
    ofstream g("roata.out");
    int n, i, p, mini, maxi, ult_cabina, aux, pozmin, j;
    long long s=0;
    //n-cabine
    //p-clienti
    f>>n>>p;
    unsigned long long ture[p+1];
    int nr_ord_client[p+1];
    for(i=1; i<=n; i++)
        nr_ord_client[i]=i;

    for (i=1; i<=p; i++) {
		f>>ture[i];
		s=s+ture[i];
    }
    g<<s<<'\n';

    if (n<p)
    {
        for(i=n+1; i<=p; i++) {
            mini=100000;
            for (j=1; j<=n; j++)
                if (ture[j]<mini) {
                    pozmin=j;
                    mini=ture[j];
                }
            g<<nr_ord_client[pozmin]<<' ';
            nr_ord_client[pozmin]=i;
            ture[pozmin]=ture[pozmin]+ture[i];
        }
        p=n;
    }

    maxi=0;
    for (i=1; i<=p; i++) {
        if (ture[i]>maxi){
            ult_cabina=i;
            maxi=ture[i];
        }
        else if (ture[i]==maxi)
			ult_cabina=i;
    }
    aux=p;
    while (aux!=0) {
        mini=100000;

        for (i=1; i<=p; i++) {
            if (ture[i]<mini) {
                mini=ture[i];
				pozmin=i;
            }

        }
        ture[pozmin]=100001;
        g<<nr_ord_client[pozmin]<<' ';
        aux--;
    }
    g<<'\n'<<ult_cabina;
    return 0;
}
