#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using ull=unsigned long long;

int main()
{
    ifstream f("3secv.in");
    ofstream g("3secv.out");
    int n, k, t, i, ct1, ct2, ct3;
    ull a, b, c;
    f>>t;
    for (k=1; k<=t; k++) {
        f>>n;
        ct1=ct2=ct3=0;
        int v[n+1];
        for (i=1; i<=n-3; i++)
            f>>v[i];

    }

    return 0;
}
