//O(N^2)
#include <fstream>
#define DIM 300010

using namespace std;

char S[DIM];
int P[DIM];

int n, suma, maxim, nr, i, j, V;

int main(){
    ifstream fin ("dominant.in");
    ofstream fout("dominant.out");
    fin>>V;
    fin>>S+1;
    suma = 0;
    for (i=1;S[i];i++) {
        if (S[i] == '1')
            suma ++;
        else
            suma --;
        P[i] = suma;
        for (j=0;j<i;j++)
            if (P[j] < P[i])
                break;

        if (j < i) {
            if (i-j > maxim) {
                maxim = i-j;
                nr = 1;
            } else
                if (i-j == maxim)
                    nr++;
        }
    }
    if (V==1)
        fout<<maxim<<"\n";
    else
        fout<<nr<<"\n";

    return 0;
}
