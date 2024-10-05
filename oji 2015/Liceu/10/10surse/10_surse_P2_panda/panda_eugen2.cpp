/*
	Sursa 100 p Lee + verif. compl.
	prof. Eugen Nodea, Tg-Jiu
*/
# include <fstream>
# include <queue>
# define inf 1000000
using namespace std;

ifstream f("panda.in");
ofstream g("panda.out");

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int p, n, m, t, k, l, c, i, j, x, y, s, Min = inf, nr = -1;
bool key[501][501], food[501][501];
int T[501][501];

struct cel
{
    short l, c;
};
queue < cel > q;

void lee()
{
    cel x, y;
    int i;
    x.l = l; x.c =c;
    q.push(x); T[l][c] = 0;
    while (!q.empty())
    {
        x = q.front(); q.pop();
        for(i=0; i<4; ++i)
        {
            y.l = x.l + dx[i];
            y.c = x.c + dy[i];
            if (key[y.l][y.c] && T[y.l][y.c] > T[x.l][x.c] + 1)
            {
                q.push(y);
                T[y.l][y.c] = T[x.l][x.c] + 1;
                if (food[y.l][y.c])
                {
                    if (Min > T[y.l][y.c]) Min = T[y.l][y.c];
                }
            }
        }
    }
}

bool verif(int x, int y, int s)
{
    for (int i=1; i<=s; ++i)
    {
        if (x % 2 == y % 2) return 0;
        x /= 2; y /= 2;
    }
    return 1;
}
int main()
{
    f >> p;
    f >> n >> m >> t;
    f >> l >> c >> k >> s;

    for(i=1; i<=t; ++i)
    {
        f >> x >> y;
        food[x][y] = 1;
    }

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            T[i][j] = inf;
            f >> x;
            key[i][j] = verif(k, x, s);
            nr += key[i][j];
        }

    lee();

    if (p == 1)
    {
        g << nr << "\n";
    }
    else
    {
        if (inf == Min)
        {
            g << "Nu am solutie!";
            return 0;
        }
        g << Min << " ";
        for(i=1, nr = 0; i<=n; ++i)
            for(j=1; j<=m; ++j)
                if (food[i][j] && T[i][j] == Min) ++nr;
        g << nr << "\n";
    }
    return 0;
}
