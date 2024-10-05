//Emanuela Cerchez Colegiul National Emil Racovita 100 puncte
#include <fstream>
#define NMAX 208
#define INF 1000004
using namespace std;
ifstream fin("lasere.in");
ofstream fout("lasere.out");
int T[NMAX][NMAX];
bool G[NMAX][NMAX]; //G[i][j]=true daca in pozitia i j exista o groapa
int n, m;
int gropi, transee;
int c;
int dl[]={0, -1, 0, 1,  0, -1,-1,  1, 1};
int dc[]={0,  0, 1, 0, -1, -1, 1, -1, 1};

bool este_groapa(int lin, int col);
int cauta_gropi();
void bordare();
void trage(int lin, int col, int d);
int cauta_transee();

int main()
{int i, j, lin, col, d;
 fin>>c>>n>>m;
 for (i=1; i<=n; i++)
     for (j=1; j<=n; j++) fin>>T[i][j];

 bordare();
 for (i=1; i<=m; i++)
     {
     	fin>>lin>>col>>d;
        trage(lin,col,d);
     }

 gropi=cauta_gropi();
 /*for (i=1; i<=n; i++)
     {for (j=1; j<=n; j++) fout<<G[i][j]<<' ';
     fout<<'\n';}
*/
 if (c==1)
     fout<<gropi<<'\n';
     else
     fout<<cauta_transee()<<'\n';
 fout.close();
 return 0;
}

bool este_groapa(int lin, int col)
{   int k;
	for (k=1; k<=8; k++)
	    if (T[lin+dl[k]][col+dc[k]]<T[lin][col]) return 0;
	return 1;
}

int cauta_gropi()
{int i, j, nr=0;
 for (i=1; i<=n; i++)
     for (j=1; j<=n; j++)
          if (este_groapa(i, j))
             {
             	nr++; G[i][j]=1;
             }
 return nr;
}

void bordare()
{int i;
 for (i=0; i<=n+1; i++)
     T[0][i]=T[i][0]=T[n+1][i]=T[i][n+1]=INF;
}

void trage(int lin, int col, int d)
{
 do
 {
 	lin+=dl[d]; col+=dc[d];
 	if (T[lin][col]==INF) return;
 	T[lin][col]--;
 }
 while (1);
}

int cauta_transee()
{int i, j, nr=0, lg;
 for (i=1; i<=n; i++)
     for (j=1; j<=n+1; j++)
         if (G[i][j])
             if (!G[i][j-1]) //incepe o transee
                 lg=1;
                 else
                 lg++;
			 else
		     if (G[i][j-1]) //se termina o transee
                if (lg>1) nr++;
  return nr;
}
