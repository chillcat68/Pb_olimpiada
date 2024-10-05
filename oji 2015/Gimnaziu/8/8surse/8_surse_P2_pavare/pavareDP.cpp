#include <fstream>
#include <cmath>

using namespace std;

int a[100000];
int V;
int main()
{
    int k, n, i, s;

    ifstream fin("pavare.in");
    fin >> V;
    fin >> s;
    fin.close();

    k = (int)(-1 + sqrt(1.0 + 4 * s)) / 2;

    for (i = 1; i <= k; i++)
        a[i] = i;
    n = k;
    s = s - k * (k + 1);
    if (s > 0)
    {
        if (s >= k + 2)
            {
                a[++n] = k+1;
                s -= (k+1);
            }
    }
    for (i=k; i >= 1; --i)
        a[++n] = i;

    // inserez s
    if (s > 0)
    {
        for (i = n; i >= s; i--)
            a[i+1] = a[i];
        a[s] = s;
        n++;
    }

    ofstream fout("pavare.out");
    if (V == 1) {
        fout << n << "\n";
        return 0;
    }
    for (i = 1; i <= n; i++)
        fout << a[i] << " ";
    fout << "\n";
    fout.close();

    return 0;
}
