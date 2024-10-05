/*
    Sursa 100p - implementare stack-STL
    prof. Eugen Nodea
    Colegiul National "Tudor Vladimirescu", Tg-Jiu
*/
# include <fstream>
# include <cstring>
# include <stack>
using namespace std;

# define max(a, b) ((a) < (b) ? (b) : (a))
# define Lmax 100001

ifstream f("charlie.in");
ofstream g("charlie.out");

char s[Lmax], vf_a, vf, sol[Lmax];
int p, L, semn, k, i, Max, j;
stack <char> st;
long long S;

void afis()
{
    int i = st.size();
    sol[i] = '\0';
    while (!st.empty())
    {
        sol[--i] = st.top();
        st.pop();
    }
    g << sol << "\n";
}

int main()
{
    f >> p; f.get();
    f.getline(s, 100001);
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
        vf_a = s[0]; vf = s[1];
        st.push(s[0]); st.push(s[1]);
        i = 2;
        while ( i < L )
        {
            while (s[i] > vf && vf < vf_a && st.size() > 1)
                {
                    S += max(s[i] - 'a' + 1, vf_a - 'a' + 1);
                    if (st.size() <= 2)
                    {
                        st.pop();
                        vf = st.top();
                    }
                    else
                    {
                        vf = vf_a;
                        st.pop(); // sterg vf
                        st.pop(); // sterg vf_anterior
                        vf_a = st.top(); // actualize vf_a
                        st.push(vf); // adaug vf
                    }
                }
            vf_a = vf; vf = s[i];
            st.push(s[i]);
            ++i;
        }
        afis();
        g << S << "\n";
    }
    return 0;
}
