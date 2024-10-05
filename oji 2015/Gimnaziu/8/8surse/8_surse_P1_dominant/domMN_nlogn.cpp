// n log n
#include <fstream>
#include <cstring>
#include <algorithm>


#define INF 1000000
#define DIM 300010
using namespace std;

char S[DIM];
int v[DIM];
pair<int, int> w[DIM];

int n, i, minim1, minim2, maxim, nr, j, m, V;

int main() {
    ifstream fin ("dominant.in");
    ofstream fout("dominant.out");
    fin>>V;
    fin>>S+1;
    m = n = strlen(S+1);

    for (i=1;i<=n;i++) {
        if (S[i] == '1')
            v[i] = v[i-1] + 1;
        else
            v[i] = v[i-1] - 1;
        w[i] = make_pair(v[i], i);
    }

    sort(w, w+n+1);

    j = 1;
    for (i=2;i<=n;i++)
        if (w[i].first != w[j].first) {
            w[++j] = w[i];
        } else
            if (w[i].first == w[j-1].first)
                w[j] = w[i];
            else
                w[++j] = w[i];

    if (w[1].second < w[0].second) {
        minim1 = w[1].second;
        minim2 = w[0].second;
    } else {
        minim1 = w[0].second;
        minim2 = w[1].second;

    }

    n = j;
    maxim = -INF;
    for (i=2;i<=n;i++) {
        if (w[i-1].second != minim1) {
            maxim = max(maxim, w[i].second-minim1);
        } else {
            maxim = max(maxim, w[i].second-minim2);
        }
        if (w[i].second < minim1) {
            minim2 = minim1;
            minim1 = w[i].second;
        } else
            if (w[i].second < minim2)
                minim2 = w[i].second;
    }

    for (i=maxim;i<=m;i++)
        if (v[i] - v[i-maxim] > 0)
            nr++;

    if (V == 1)
        fout<<maxim<<"\n";
    else
        fout<<nr<<"\n";

    return 0;
}
