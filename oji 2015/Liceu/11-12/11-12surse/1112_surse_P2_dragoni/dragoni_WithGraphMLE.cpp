#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 810
#define maxm 6010
#define inf 1000000000

int cer, n, m, a[maxm], b[maxm], d[maxm], dmax[maxn];
int f[maxn*maxn];
int dist[maxn*maxn];
vector<int> v[maxn*maxn], w[maxn*maxn];
vector<pair<int, int> > h;

int getNode(int nod, int lvl)
{
    return (lvl-1)*n+nod;
}

void addEdge(int a, int l1, int b, int l2, int dst)
{
    int n1=getNode(a, l1), n2=getNode(b, l2);
    v[n1].push_back(n2);
    w[n1].push_back(dst);
}

void buildGraph()
{
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            if(d[i]<=dmax[j])
            {
                addEdge(a[i], j, b[i], j, d[i]);
                addEdge(b[i], j, a[i], j, d[i]);
            }

    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            addEdge(i, j, i, i, 0);
}

void dijkstra()
{
    for(int i=1; i<=n*n; ++i)
        dist[i]=inf;

    dist[1]=0;
    h.push_back(make_pair(0, 1));

    int nod;
    long long cdist;

    while(!h.empty())
    {
        nod=h[0].second;

        if(nod==n*n)
            break;

        cdist=-h[0].first;
        pop_heap(h.begin(), h.end());
        h.pop_back();

        if(f[nod])
            continue;

        f[nod]=1;
        int fiu;

        for(int i=0; i<v[nod].size(); ++i)
        {
            fiu=v[nod][i];
            if(dist[fiu]>cdist+w[nod][i])
            {
                dist[fiu]=cdist+w[nod][i];
                h.push_back(make_pair(-dist[fiu], fiu));
                push_heap(h.begin(), h.end());
            }
        }
    }
}

int cerinta1()
{
    int best=dmax[1];

    for(int i=2; i<=n; ++i)
        if(dist[i]!=inf && dmax[i]>best)
            best=dmax[i];

    return best;
}

int main()
{
    freopen("dragoni.in", "r", stdin);
    freopen("dragoni.out", "w", stdout);

    scanf("%d", &cer);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%d", &dmax[i]);
    for(int i=1; i<=m; ++i)
        scanf("%d%d%d", &a[i], &b[i], &d[i]);

    buildGraph();
    dijkstra();

    if(cer==1)
        printf("%d\n", cerinta1());
    else
        printf("%d\n", dist[n*n]);

    return 0;
}

