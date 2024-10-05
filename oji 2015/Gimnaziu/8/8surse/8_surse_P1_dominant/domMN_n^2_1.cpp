//O(N^2)
#include <fstream>
#include <cstring>
#define DIM 300010

using namespace std;

char S[DIM];
int P[DIM];

int N, i, j, L, nr, suma, ok = 0, V;

int main(){
    ifstream fin ("dominant.in");
    ofstream fout("dominant.out");
    fin>>V;
    fin>>S+1;
    N = strlen(S+1);
    suma = 0;
    for (i=1;S[i];i++) {
        if (S[i] == '1')
            suma ++;
        else
            suma --;
        P[i] = suma;
    }

    for (L = N; L>=1 && !ok; L--) {
        for (i=1;i+L-1<=N;i++) {
            j = i+L-1;
            if (P[j] > P[i-1]) {
                ok = 1;
                nr++;
            }
        }
    }
    if (V == 1)
        fout<<L+1<<"\n";
    else
        fout<<nr<<"\n";

    return 0;
}

