#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("elicop.in");
    ofstream g("elicop.out");

    int m, n, i, j, k, elicop, ct, N1=0, N2=0, v[41], c=0, ok;
    int nr_afectate;
    f>>m>>n;
    bool a[m+1][n+1];
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            f>>a[i][j];

    f>>elicop;
    int l1, c1, c2, l2, p;
    for (k=1; k<=elicop; k++) {
        ct=0;
        ok=1;
      f>>l1>>c1>>l2>>c2>>p;
      if (l1>l2){
            swap (l1, l2);
            swap (c1, c2);
          }
      //deasupra diagonalei secundare
      if (c1>c2 && p==1){
        for (i=l1; i<=l2; i++)
            for (j=c2; j<=c1-i+l1; j++)
                if (a[i][j]==0)
                {
                    ct++;
                    ok=0;
                }
      }
      //sub diagonala secundara
      else if (c1>c2 && p==-1) {
        for (i=l1; i<=l2; i++)
            for (j=c1-i+l1; j<=c1; j++)
                if (a[i][j]==0)
                {
                    ct++;
                    ok=0;
                }
      }
      //deasupra diagonalei principale
      else if (c1<c2 && p==1) {
        for (i=l1; i<=l2; i++)
            for (j=c1-l1+i; j<=c2; j++)
                if (a[i][j]==0)
                {
                    ct++;
                    ok=0;
                }
      }
       //sub diagonala principale
      else if (c1<c2 && p==-1) {
        for (i=l1; i<=l2; i++)
            for (j=c1; j<=c1-l1+i; j++)
                if (a[i][j]==0)
                {
                    ct++;
                    ok=0;
                }
      }
      nr_afectate=(abs(c1-c2)+1)*(abs(c1-c2)+1)/4;
      if (ok==1)
        N1++;
      else if (ct>nr_afectate) {
            N2++;
            v[++c]=k;
      }
    }
    g<<N1<<'\n';
    g<<N2<<' ';
    for (i=1; i<=c; i++)
        g<<v[i]<<' ';

    return 0;
}
