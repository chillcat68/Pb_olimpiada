/*
  Complexitate O(n log n)
  Cautare binara pe lungime secventei
*/

#include <fstream>
#include <cstring>
#define inFile "dominant.in"
#define outFile "dominant.out"
#define Nmax 300005

using namespace std;

char s[Nmax];
int a[Nmax];
int n, v;

void Citire()
{
    ifstream fin(inFile);
    fin >> v;
    fin >> (s + 1);
    n = strlen(s + 1);
    fin.close();
}

void SumePartiale()
{
    int i;
    for (i = 1; i <= n; i++)
        a[i] = a[i-1] + (s[i]-'0');
}

int Secventa(int L)
{
    int i, cnt, x;
    cnt = 0;
    for (i = L; i <= n; ++i)
    {
        x = a[i] - a[i-L];
        if (x > L - x) cnt++;
    }
    return cnt;
}

void CautBin()
{
    int st, dr, mij, sol, x, cnt;
    st = 1; dr = n;
    sol = 0;
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        x = Secventa(mij);
        if (x == 0) dr = mij - 1;
        else
        {
            sol = mij;
            cnt = x;
            st = mij + 1;
        }
    }
    ofstream fout(outFile);
    if (v == 1) fout << sol << "\n";
    else fout << cnt << "\n";
    fout.close();
}

int main()
{
    Citire();
    SumePartiale();
    CautBin();
    return 0;
}
