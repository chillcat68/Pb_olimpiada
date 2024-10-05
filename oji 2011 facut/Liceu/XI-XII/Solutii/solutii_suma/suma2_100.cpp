//stud. Filip Buruiana
#include <stdio.h>

#define INF 999999999
#define NMax 63366
#define MAX_LEV 58

int N, C[NMax];
int pd[NMax], next[NMax], from[MAX_LEV], to[MAX_LEV], lev;

inline void update(int i, int nxt)
{
	if (pd[nxt] + C[i] < pd[i])
	{
		pd[i] = pd[nxt] + C[i];
		next[i] = nxt;
	}
}

int main()
{
	int i, j, sub, l, c;

	freopen("suma.in", "r", stdin);
	freopen("suma.out", "w", stdout);

	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
		scanf("%d", &C[i]);

	for (i = 1; i * (i+1) * (2*i+1) / 6 < N; ++i);
	lev = i;

	from[lev] = N-lev*lev+1; to[lev] = N;
	for (i = lev-1; i; --i)
		to[i]=from[i+1]-1, from[i]=to[i]-i*i+1;

	for (i = from[lev]; i <= to[lev]; ++i)
		pd[i] = C[i];
	for (i = lev-1; i; --i)
	{
		for (j = from[i]; j <= to[i]; ++j)
		{
			l = (j-from[i])/i + 1;
			c = (j-from[i])%i + 1;
			sub = from[i+1]+(l-1)*(i+1)+c-1;

			pd[j] = INF;
			update(j, sub);
			update(j, sub+1);
			update(j, sub+i+1);
			update(j, sub+i+2);
		}
	}

	printf("%d %d\n", lev, pd[1]);
	for (i = 1; i; i = next[i])
		printf("%d ", i);
	printf("\n");

	return 0;
}

