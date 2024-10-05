#include <iostream>
#include <fstream>
#define INF 1000000010

using namespace std;

int v[100002], vminim[100002], minim = INF, k, i, s, n, V;

void back(int k) {
    if (s == 0) {
        int i;
        if (v[k-1] == 1) {
            if (k-1 < minim) {
                minim = k-1;
                for (i=1;i<=k-1;i++) {
                    vminim[i] = v[i];
                }
            } else
                if (k-1 == minim) {
                    for (i=1;i<=k-1;i++)
                        if (v[i] != vminim[i])
                            break;
                    if (v[i] < vminim[i]) {
                        for (i=1;i<=k-1;i++) {
                            vminim[i] = v[i];
                        }
                    }
                }
        }
    } else {
        for (int i=v[k-1]-1;i<=v[k-1]+1;i++) {
            if (i == 0)
                continue;
            if (i <= s) {
                s-=i;
                v[k] = i;
                back(k+1);
                s+=i;
            }
        }
    }
}

ifstream fin ("pavare.in");
ofstream fout("pavare.out");

int main() {
    fin>>V;
    fin>>n;
    minim = INF;
    v[1] = 1;
    s = n-1;
    back(2);
    if (V == 1)
        fout<<minim<<"\n";
    else {
        for (i=1;i<=minim;i++)
            fout<<vminim[i]<<" ";
        fout<<"\n";
    }
}
