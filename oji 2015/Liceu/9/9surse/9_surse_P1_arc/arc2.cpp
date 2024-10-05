/*  prof. Constantin Galatan
    Colegiul National "Liviu Rebreanu" Bistrita
*/
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("arc.in");
ofstream fout("arc.out");
int p, n, n1, n2;

struct Secv {
	int v, cnt;
	short pos, prev, next;
};

const int MaxN = 10001;
Secv s[MaxN];
int first, last;

void Add(int val);
void Print();
int GetMax();
void DelSecv(int p);

int main()
{
	int x;
	fin >> p >> n;
	for (int i = 1; i <= n; ++i)
	{
		fin >> x;
		Add(x);
	}

	if (p == 1)
		fout << n1 << '\n';
	else
	{
		n2 = n;
		while (true)
		{
			int p = GetMax(), p1, p2;
			if ( !p || s[p].cnt <= 2 )
				break;
			n2 -= s[p].cnt;
			p1 = s[p].prev; p2 = s[p].next;
			DelSecv(p);

			while ( (p1 && p2) && (s[p1].v == s[p2].v)  )
			{
				s[p1].cnt += s[p2].cnt;
				DelSecv(p2);
				if ( s[p1].cnt > 2 )
				{
					n2 -= s[p1].cnt;
					int q = p1;
					p1 = s[p1].prev;
					DelSecv(q);
				}
				if ( p1 ) p2 = s[p1].next;
			}
		}
		Print();
	}

	fin.close();
	fout.close();
}

void Add(int val)
{
	if ( last && s[last].v == val )
	{
		s[last].cnt++;
		return;
	}

	Secv s1 {0, 0, 0, 0, 0 };
	s1.v = val;
	s1.cnt++;  n1++;

	if ( !first )
	{
		s1.prev = s1.next = 0;
		first = last = 1;
		s[first] = s1;
	}
	else
	{
		s[last].next = last + 1;
		s1.prev = last;
		s1.next = 0;
		last++;
		s[last] = s1;
	}
}

void DelSecv(int p)
{
	if ( p == first )
	{
		if ( p == last )
		{
			first = last = 0;
			return;
		}
		first = s[p].next;
		s[first].prev = 0;
		return;
	}

	if ( p == last )
	{
		last = s[p].prev;
		s[last].next = 0;
		return;
	}

	int p1 = s[p].prev, p2 = s[p].next;
	s[p1].next = p2; s[p2].prev = p1;
}

int GetMax()
{
	int pMax(0);
	int cntMax = 0;
	for (int p = first; p; p = s[p].next)
		if ( s[p].cnt > cntMax )
			cntMax = s[p].cnt, pMax = p;
	return pMax;
}

void Print()
{
	if ( !first )
		fout << "0\n";
	else
	{
		fout << n2 << '\n';
		for (int p = first; p; p = s[p].next)
			while ( s[p].cnt--)
				fout << s[p].v << '\n';
	}
}
