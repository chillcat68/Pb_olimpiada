// prof. Galatan Constantin
// Colegiul National "Liviu Rebreanu" Bistrita

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cassert>
using namespace std;

ifstream fin("defrag.in");
ofstream fout("defrag.out");

const int Pmax = 100, Smax = 360;
int V, P, S, C;
bitset<Smax> d[Pmax];
bitset<Pmax> pista;
int cnt[Pmax], sp[Smax];
int pisteLibere;

int main()
{
	fin >> V;
	fin >> P >> S >> C;
	pisteLibere = P;
	int p, s;
	for (int c = 0; c < C; ++c )
	{
		fin >> p >> s;
	//	assert(p >= 1);
	//	assert(s >= 1);
		p--; s--;
		cnt[p]++; d[p][s] = true;
		if ( !pista[p] )
		{
			pista[p] = true;
			pisteLibere--;
		}
	}

	if (V == 1)
		fout << pisteLibere << '\n';
	else
	{
		int k, sum;
		for (int p = 0; p < P; ++p)
		{
			k = cnt[p];
			if ( k == 0 )
			{
				fout << 0 << ' ';
				continue;
			}
            sum = 0;
			for (int i = 0; i < k; ++i)
				sum += d[p][i];
            sp[k - 1] = sum;
			for (int i = k; i < S + k; ++i )
				sp[i % S] = sp[(i - 1)% S] + d[p][i % S] - d[p][i - k];

			int maxim = 0;
            for (int i = 0; i < S; ++i)
                maxim = max(maxim, sp[i]);
			fout << k - maxim << ' ';
		}
	}
	fin.close();
	fout.close();
}


