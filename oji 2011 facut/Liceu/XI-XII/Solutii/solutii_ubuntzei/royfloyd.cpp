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
const int INF = 0x3F3F3F3F;

vector <int> subset;
int d[MAX_N][MAX_N];

int main(void) {
	int nodeCount, edgeCount, subsetCount, u, v, cost;

	ifstream in(iname);
	in >> nodeCount >> edgeCount >> subsetCount;
	subset.resize(subsetCount);
	for (int i = 0; i < subsetCount; ++ i) {
		in >> subset[i];
		subset[i] --;
	}
	memset(d, INF, sizeof d);
	for (int i = 0; i < nodeCount; ++ i)
		d[i][i] = 0;
	for (int i = 0; i < edgeCount; ++ i) {
		in >> u >> v >> cost;
		-- u, -- v;
		d[u][v] = d[v][u] = cost;
	}
	in.close();

	for (int k = 0; k < nodeCount; ++ k) {
		for (int i = 0; i < nodeCount; ++ i) {
			for (int j = 0; j < nodeCount; ++ j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}

	if (subsetCount > 0) {
		sort(subset.begin(), subset.end());
		int src = 0, sink = nodeCount - 1;
		int answer = INF;
		do {
			int temp = d[src][subset.front()] + d[subset.back()][sink];

			for (int i = 0; i < (int) subset.size() - 1; ++ i)
				temp += d[subset[i]][subset[i + 1]];

			answer = min(answer, temp);
		} while (next_permutation(subset.begin(), subset.end()));

		ofstream(oname) << answer << "\n";
	}
	else
		ofstream(oname) << d[0][nodeCount - 1] << "\n";

	return 0;
}
