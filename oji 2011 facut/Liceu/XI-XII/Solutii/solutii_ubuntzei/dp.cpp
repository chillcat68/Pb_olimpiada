// Filip Buruiana
#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

#define minim(a, b) ((a < b) ? a : b)
#define INF 999999999
#define KMAX 15
#define NMAX 10005
#define pii pair<int, int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

int N, M, K, C[KMAX];
int source[NMAX], path[KMAX][NMAX];
vector<pii> G[NMAX];
int pd[1<<KMAX][KMAX];
set<pii> q;

inline int bit(int x, int nr)
{ return (x & (1<<nr)) != 0; }

void dijkstra(int sursa, int *sol)
{
	int i, vec;
	for (i = 1; i <= N; ++i)
		sol[i] = INF;
	sol[sursa] = 0;
	q.clear();
	for (i = 1; i <= N; ++i)
		q.insert(mp(sol[i],i));
	for (i = 1; i < N; ++i)
	{
		pii top = *q.begin();
		q.erase(q.begin());
		int nod = top.s;
		if (sol[nod] < top.f)  continue;
		for (size_t j = 0; j < G[nod].size(); ++j)
			if (sol[vec = G[nod][j].f] > sol[nod] + G[nod][j].s)
			{
				sol[vec] = sol[nod] + G[nod][j].s;
				q.insert(mp(sol[vec], vec));
			}
	}
}

int main()
{
	int i, j, k, newCost;

	freopen("ubuntzei.in", "r", stdin);
	freopen("ubuntzei.out", "w", stdout);

	scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < K; ++i)
		scanf("%d", &C[i]);

	for (; M; --M)
	{
		scanf("%d %d %d", &i, &j, &k);
		G[i].pb(mp(j,k));
		G[j].pb(mp(i,k));
	}

	dijkstra(1, source);
	if (K == 0)
	{
		printf("%d\n", source[N]);
		return 0;
	}

	for (i = 0; i < K; ++i)
		dijkstra(C[i], path[i]);

	for (i = 1; i < (1<<K); ++i)
	{
		for (j = 0; j < K; ++j)
			if (i == (1<<j))
				break;
		if (j < K && i == (1<<j))
		{
			pd[i][j] = source[C[j]];
			continue;
		}

		for (j = 0; j < K; ++j)
		{
			pd[i][j] = INF;
			if (bit(i,j))
				for (k = 0; k < K; ++k)
					if (k != j && bit(i, k))
					{
						newCost = pd[i-(1<<j)][k] + path[k][C[j]];
						pd[i][j] = minim(pd[i][j], newCost);
					}
		}
	}

	int bst = INF;
	for (i = 0; i < K; ++i)
		bst = minim(bst, pd[(1<<K)-1][i] + path[i][N]);

	printf("%d\n", bst);

	return 0;
}

