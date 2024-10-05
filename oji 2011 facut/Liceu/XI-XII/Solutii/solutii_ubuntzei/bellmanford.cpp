#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <cassert>
#include <memory.h>
#include <algorithm>
using namespace std;

const char iname[] = "ubuntzei.in";
const char oname[] = "ubuntzei.out";

const int MAX_N = 205;
const int MAX_K = 15;
const int INF = 0x3F3F3F3F;

int dist[MAX_N][1 << MAX_K];
bitset<(1 << MAX_K)> inque[MAX_N];
queue < pair <int, int> > que;
int rf[MAX_N][MAX_N];

vector <int> adj[MAX_N], subset, idxSubset; bitset <MAX_N> inSubset;


int main(void) {
	int nodeCount, edgeCount, subsetCount, u, v, cost;

	ifstream in(iname);
	in >> nodeCount >> edgeCount >> subsetCount;

	subset.resize(subsetCount);
	idxSubset.resize(nodeCount);
	idxSubset.assign(idxSubset.size(), -1);
	for (int i = 0; i < subsetCount; ++ i) {
		in >> u; -- u;
		assert(0 < u && u < nodeCount - 1);
		subset[i] = u;
		idxSubset[u] = i;
		inSubset[u] = true;
	}

	memset(rf, INF, sizeof rf);
	for (int i = 0; i < nodeCount; ++ i)
		rf[i][i] = 0;
	for (int i = 0; i < edgeCount; ++ i) {
		in >> u >> v >> cost;
		-- u, -- v;
		assert(0 <= u && u < nodeCount);
		assert(0 <= v && v < nodeCount);
		rf[u][v] = rf[v][u] = cost;
	}
	in.close();

	for (int k = 0; k < nodeCount; ++ k) {
		for (int i = 0; i < nodeCount; ++ i) {
			for (int j = 0; j < nodeCount; ++ j) {
				rf[i][j] = min(rf[i][j], rf[i][k] + rf[k][j]);
			}
		}
	}

	if (subsetCount > 0) {
		for (int i = 0; i < nodeCount; ++ i) {
			for (int j = i + 1; j < nodeCount; ++ j) {
				assert(rf[i][j] < INF);
				if ((inSubset[i] || !i || i == nodeCount - 1) && (inSubset[j] || !j || j == nodeCount - 1)) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		memset(dist, INF, sizeof dist);
		dist[0][0] = 0;
		que.push(make_pair(0, 0)), inque[0][0] = true;
		while (!que.empty()) {
			int u = que.front().first;
			int s = que.front().second;
			que.pop();
			inque[u][s] = false;

			for (vector <int>::iterator it = adj[u].begin(); it != adj[u].end(); ++ it) {
				int v = *it;

				if (!inSubset[v]) {
					if (dist[v][s] > dist[u][s] + rf[u][v]) {
						dist[v][s] = dist[u][s] + rf[u][v];
						if (inque[v][s] == false) {
							que.push(make_pair(v, s));
							inque[v][s] = true;
						}
					}
				}
				else if (!(s & (1 << idxSubset[v]))) {
					int t = s | (1 << idxSubset[v]);

					if (dist[v][t] > dist[u][s] + rf[u][v]) {
						dist[v][t] = dist[u][s] + rf[u][v];
						if (inque[v][t] == false) {
							que.push(make_pair(v, t));
							inque[v][t] = true;
						}
					}
				}
			}
		}

		int sink = nodeCount - 1;
		int conf = (1 << subset.size()) - 1;
		assert(dist[sink][conf] < INF);

		ofstream(oname) << dist[sink][conf] << "\n";
	}
	else
		ofstream(oname) << rf[0][nodeCount - 1] << "\n";

	return 0;
}
