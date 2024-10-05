/*
    Constantin Galatan
    Complexitate: O(n*n)
*/
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

#define DIM 1001
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
typedef pair<int, int> PII;

ifstream fin("ai.in");
ofstream fout("ai.out");


int R1[DIM][DIM];                 // distantele minime ale robotului 1
int R2[DIM][DIM];                 // distantele minime ale robotului 2
int t1r1 = INF, t2r1 = INF;       // timpii la care robotul 1 protejeaza tinta de cele doua surse
int t1r2 = INF, t2r2 = INF;       // timpii la care robotul 2 protejeaza tinta de cele doua surse
int n;
int I0, J0, is1, js1, is2, js2,   // tinta, sursele
    ir1, jr1, ir2, jr2;           // robotii
const int di[] = { -1, 0, 1, 0 },
          dj[] = { 0, 1, 0, -1 };
bool obst[DIM][DIM];
queue<PII> Q;                     // coada - retine nodurile in ordinea vizitarii
int robot = 1;
int iv, jv;

void Read();
int LMaxZid();
bool OK(int, int);
void Lee(int, int, int[][DIM]);
bool AnuleazaSursa(int, int);

int main()
{
    Read();
    fout << LMaxZid() << '\n';
    Lee(ir1, jr1, R1);
    robot = 2;
    Lee(ir2, jr2, R2);
    fout << min(max(t1r1, t2r2), max(t2r1, t1r2)) << '\n';
    fout.close();
    return 0;
}

int LMaxZid()
{
	int j1, Lmax = 0, L;
	for ( int i = 1; i <= n; ++i )
		for (int j = 1; j <= n; j++)
			if ( obst[i][j] )
			{
				j1 = j;
				while ( obst[i][j] ) j++;
				L = j - j1;
				if ( L > Lmax ) Lmax = L;
			}

	int i1;
	for ( int j = 1; j <= n; ++j )
		for (int i = 1; i <= n; i++)
			if ( obst[i][j] )
			{
				i1 = i;
				while ( obst[i][j] ) i++;
				L = i - i1;
				if ( L > Lmax ) Lmax = L;
			}
	return Lmax;
}


void Lee(int ir, int jr, int R[][DIM])
{
    bool ok1 = false, ok2 = false;
    R[ir][jr] = 0;
    Q.push(mp(ir, jr));
    int i, j;
    while ( !Q.empty() )
    {
        i = Q.front().first;
        j = Q.front().second;
        Q.pop();
        for ( int d = 0; d < 4; ++d )
        {
            iv = i + di[d];
            jv = j + dj[d];
           if ( OK(iv, jv) && R[i][j] + 1 < R[iv][jv])
            {
				R[iv][jv] = R[i][j] + 1;
                Q.push(mp(iv, jv));

                // daca prima sursa e anulata
                if ( !ok1 && (ok1 = AnuleazaSursa(is1, js1)) )
                {
                    if ( robot == 1 )
                       t1r1 = R[iv][jv];
                    else
                       t1r2 = R[iv][jv];
                }

                // daca a doua sursa e anulata
                if ( !ok2 && (ok2 = AnuleazaSursa(is2, js2)) )
                {
                    if ( robot == 1 )
                        t2r1 = R[iv][jv];
                    else
                        t2r2 = R[iv][jv];
                }
                // daca ambele surse au fost anulate
                if ( ok1 && ok2 )
                    return;
            }
        }
    }
}


bool AnuleazaSursa(int i, int j)
{

    if ( iv == i && jv == j )     return true;  // pe sursa

    if ( iv == i && i == I0 )  // pe aceeasi orizontala sau verticala cu sursa
    {
		if (j <= jv && jv < J0 )  return true;   // SRT
		if ( J0 < jv && jv<= j )  return true;   // TRS
	}

    if ( jv == j && j == J0 )
    {
		if ( I0 < iv && iv <= i ) return true;  // TRS
		if ( i <= iv && iv < I0 ) return true;  // SRT
	}

    if ( i > iv && iv > I0 && jv > j && J0 > jv &&
         (i - I0)*(jv - j) == (i - iv) * (J0 - j) )      //  / S R T
        return true;


    if ( I0 > iv && iv > i && jv > J0 && j > jv &&
         (I0 - i) * (jv - J0) == (I0 - iv) * (j - J0) )  //  / T R S
        return true;

    if ( I0 > iv && iv > i && J0 > jv && jv > j &&
        (I0 - i) * (jv - j) == (J0 - j) * (iv - i) )   //  \ S R T
        return true;

    if ( i > iv && iv > I0 && j > jv && jv > J0 &&
         (j - J0) * (i - iv) == (j - jv) * (i - I0) )    // \ T R S
        return true;

    return false;
}

bool OK(int i, int j)
{
    if ( obst[i][j] ) return false;
    if ( i == I0 && j == J0 ) return false;
    if ( i < 1 || i > n || j < 1 || j > n )
        return false;
    return true;
}

void Read()
{
    fin >> n;
    for ( int i = 1; i <= n; ++i )
        for ( int j = 1; j <= n; ++j )
           R1[i][j] = R2[i][j] = INF;

    fin >> I0 >> J0;                   // tinta
    obst[I0][J0] = true;               // tinta e obstacol
    fin >> is1 >> js1 >> is2 >> js2;   // sursele
    fin >> ir1 >> jr1 >> ir2 >> jr2;   // robotii
    int x, y, K;
    fin >> K;
    for ( int i = 0; i < K; ++i )
    {
        fin >> x >> y;
        obst[x][y] = true;
    }
    fin.close();
}
