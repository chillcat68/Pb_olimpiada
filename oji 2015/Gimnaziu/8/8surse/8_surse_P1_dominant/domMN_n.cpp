//O(N)
#include <fstream>
#include <cstring>

#define DIM 300010
using namespace std;

char S[DIM];

int d[2*DIM + 22];
int f[2*DIM + 22];
int *D = d + DIM + 4, *F = f + DIM + 4, V;

int n, i, maxim, sc, nr, sum;

int main() {
    ifstream fin ("dominant.in");
    ofstream fout("dominant.out");
    fin>>V;
    memset(f, -1, sizeof(f));

    fin>>S+1;
    F[0] = 0;   // F[i] = indicele primei aparitii a sumei i
    D[0] = 0;   // D[i] = pozitia de inceput a unei secvente ce se termina cu suma i

    sum = 0;
    for (i=1;S[i];i++) {
        if (S[i] == '1')
            sum++;
        else
            sum--;

        if (F[sum] == -1) {
            F[sum] = i;

            if (F[sum - 1] != -1)
                D[sum] = D[sum-1] + i - F[sum-1];
            else
                D[sum] = 0;

        }

        if (F[sum-1] != -1) {
            sc = D[sum-1] + i - F[sum-1];
            if (sc > maxim) {
                maxim = sc;
                nr = 1;
            } else
                if (sc == maxim)
                    nr++;
        }

    }
    if (V == 1)
        fout<<maxim<<"\n";
    else
        fout<<nr<<"\n";

    return 0;
}
