//O(N^3)
#include <fstream>
#include <cstring>
#define DIM 300010

using namespace std;

char S[DIM];
int P[DIM];

int N, i, j, nr, maxim, suma, k, V;

int main(){
    ifstream fin ("dominant.in");
    ofstream fout("dominant.out");
    fin>>V;
    fin>>S+1;
    N = strlen(S+1);

    for (i=1;i<=N;i++)
        for (j=i;j<=N;j++) {
            suma = 0;
            for (k=i;k<=j;k++)
                if (S[k] == '1')
                    suma ++;
                else
                    suma --;
            if (suma > 0) {
                if (j-i+1 > maxim) {
                    maxim = j-i+1;
                    nr = 1;
                } else
                    if (j-i+1 == maxim)
                        nr++;
            }

        }
    if (V == 1)
        fout<<maxim<<"\n";
    else
        fout<<nr<<"\n";
    return 0;
}

