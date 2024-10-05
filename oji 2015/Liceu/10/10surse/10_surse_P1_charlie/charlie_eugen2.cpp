/*
    Sursa 43p
    Complexitate: O(n*n) amortizat
    prof. Eugen Nodea
    Colegiul National "Tudor Vladimirescu", Tg-Jiu
*/
# include <fstream>
# include <cstring>
# include <cassert>
using namespace std;
# define max(a, b) ((a) < (b) ? (b) : (a))

ifstream f("charlie.in");
ofstream g("charlie.out");

char s[1000100];
int p, L, ok, k, i, Max, j, mm;
long long S;

int main()
{
    f >> p;
    f.get();
    f.getline(s, 1000100);
    L = strlen(s);
    if (p == 1) //a)
    {
        k = i = 0;
        while ( i < L )
        {
            j = i;
            while (s[j] > s[j+1] && s[j+1] < s[j+2] && j + 2 < L)
                j += 2;
            if (j - i >= 2)
            {
                if ( j - i + 1 > Max ) Max = j - i + 1;
                i = j;
            }
            ++i;
        }
        g << Max << "\n";
    }
    else //b)
    {
        S = 0;
        do
        {
            ok = 0;
            //caut cel mai bun candidat
            Max = 0; j = 0;
            for(i=1; i<L-1; ++i)
                if (s[i-1] > s[i] && s[i] < s[i+1])
                {
                    mm = max(s[i-1], s[i+1]);
                    if (mm >= Max)
                    {
                        Max = mm;
                        j = i;
                    }
                }
            if (Max > 0)
            {
                strcpy(s+j, s+j+1);
                L--;
                ok = 1;
                S += (Max - 'a' + 1);
            }
        }while (ok);
        g << s << "\n";
        g << S << "\n";
    }
    return 0;
}
