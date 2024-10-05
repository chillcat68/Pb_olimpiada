/*
	Sursa 100p
	prof. Zoltan Szabo
	isj Mures
*/
#include <fstream>

using namespace std;

ifstream fin("panda.in");
ofstream fout("panda.out");
int b[501][501],c[501][501],coada[3][250000];

int main()
{
    int timp,nr,prim,ultim,ultim1,i,j,l,c,k,x,y,p,n,m,t,a[501][501],gata,acces,lin,col,cheie,timpmin,s,ok;
    fin>>p;
    fin>>n>>m>>t>>l>>c>>k>>s;

    for(i=1;i<=t;++i)
    {
        fin>>x>>y;
        b[x][y]=1;    //coordonatele hranei
    }
    cheie=1;
    for (i=1;i<=s;++i)
        cheie=cheie*2;           // cheia pentru ultimele cifre binare
    acces=0;
    for(i=1;i<=n;++i)
        for (j=1;j<=m;++j)
        {
            fin>>x;
            a[i][j]=(((x%cheie) xor (k%cheie)) == cheie-1);     // conditia ca tarcul sa se deschida
            acces+=a[i][j];                   // adunam casutele cu valori accesibile
        }
    acces-=a[l][c];   // in cazul in care ursuletul este pe o coordonata accesibila, scadem, ca nu trebuie numarat

    if (p==1)    // daca e cerinta p==1 atunci tiparim si ne oprim
    {
        fout<<acces<<"\n";
        fout.close();
        fin.close();
        return 0;
    }


    // cazul p=2
    coada[0][0]=l;   // coada[0] reprezinta linia
    coada[1][0]=c;   // coada[1] reprezinta coloana
    coada[2][0]=0;   // timpul memorat in coada, pornim de la timpul 0
    prim=0;ultim=0;    // secventa din coada care se va prelucra cu Lee, generand o alta secventa
    gata=0;       // dcand se va ajunge la hrana, "gata" va fi 1
    timpmin=300000;
    ok=0;
    b[l][c]=2;
    nr=0;
    while (!gata)
    {
        ultim1=ultim;
        for(i=prim;i<=ultim1;++i)
        {
            lin=coada[0][i];
            col=coada[1][i];
            timp=coada[2][i];
            if (col>1 and a[lin][col-1] and b[lin][col-1]!=2)  // tarc nevizitat la stanga
            {
                coada[0][++ultim]=lin;     // introducem coordonata tarcului in coada
                coada[1][ultim]=col-1;
                coada[2][ultim]=timp+1;    // daca valoarea timpului este >0 atunci este fara salt

                if (b[lin][col-1]==1)     // daca s-a ajuns la hrana
                {
                    gata=1;               // atunci ne pregatim de finish
                    nr++;                 // numaram inca o solutie cu acelasi timp minim
                    b[lin][col-1]=2;      // marcam tarcul ca si vizitat, sa nu numaram inca o data
                }
                else
                    b[lin][col-1]=2;     // marcam tarcul ca si loc vizitat, sa nu trecem inca o data
            }
            if (col<m and a[lin][col+1] and b[lin][col+1]!=2)  // tarc nevizitat la dreapta
            {
                coada[0][++ultim]=lin;     // introducem coordonata tarcului in coada
                coada[1][ultim]=col+1;
                coada[2][ultim]=timp+1;    // daca valoarea timpului este >0 atunci este fara salt

                if (b[lin][col+1]==1)     // daca s-a ajuns la hrana
                {
                    gata=1;               // atunci ne pregatim de finish
                    nr++;                 // numaram inca o solutie cu acelasi timp minim
                    b[lin][col+1]=2;      // marcam tarcul ca si vizitat, sa nu numaram inca o data
                }
                else
                    b[lin][col+1]=2;     // marcam tarcul ca si loc vizitat, sa nu trecem inca o data
            }

            if (lin>1 and a[lin-1][col] and b[lin-1][col]!=2)  // tarcul de sus nevizitat
            {
                coada[0][++ultim]=lin-1;     // introducem coordonata tarcului in coada
                coada[1][ultim]=col;
                coada[2][ultim]=timp+1;    // daca valoarea timpului este >0 atunci este fara salt

                if (b[lin-1][col]==1)     // daca s-a ajuns la hrana
                {
                    gata=1;               // atunci ne pregatim de finish
                    nr++;                 // numaram inca o solutie cu acelasi timp minim
                    b[lin-1][col]=2;      // marcam tarcul ca si vizitat, sa nu numaram inca o data
                }
                else
                    b[lin-1][col]=2;     // marcam tarcul ca si loc vizitat, sa nu trecem inca o data
            }

            if (lin<n and a[lin+1][col] and b[lin+1][col]!=2)  // tarcul de jos nevizitat
            {
                coada[0][++ultim]=lin+1;     // introducem coordonata tarcului in coada
                coada[1][ultim]=col;
                coada[2][ultim]=timp+1;    // daca valoarea timpului este >0 atunci este fara salt

                if (b[lin+1][col]==1)     // daca s-a ajuns la hrana
                {
                    gata=1;               // atunci ne pregatim de finish
                    nr++;                 // numaram inca o solutie cu acelasi timp minim
                    b[lin+1][col]=2;      // marcam tarcul ca si vizitat, sa nu numaram inca o data
                }
                else
                    b[lin+1][col]=2;     // marcam tarcul ca si loc vizitat, sa nu trecem inca o data
            }

        }
        prim=ultim1+1;
    }


    fout<<timp+1<<" "<<nr<<"\n";
    fout.close();
    return 0;
}
