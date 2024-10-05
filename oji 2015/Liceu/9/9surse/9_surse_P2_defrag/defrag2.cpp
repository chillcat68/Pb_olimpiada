// prof. Chesca Ciprian
// Liceul Tehnologic "Costin Nenitescu" Buzau



#include <iostream>
#include <fstream>
#define pmax 101
#define smax 361

using namespace std;

short hdd[pmax][2*smax];


// ns  = numar sectoare
// np  = numar piste
// nso = numar sectoare ocupate
// xs = sector curent citit
// xp = pista curenta citita
// po = piste ocupate



int main()
{
    int v,c,np,ns,xp,xs,i,j,po,min,s,nso;
    ifstream f("defrag.in");
    ofstream g("defrag.out");
    // citesc configuratia HDD
    f>>v>>np>>ns;
    // citesc cate clustere sunt ocupate
    f>>c;

    // citesc clusterele ocupate
    for(i=1;i<=c;i++)
        {
         f>>xp>>xs;
         hdd[xp][xs]=1;
         // extindere matrice
         hdd[xp][xs+ns]=1;

         hdd[xp][0]++;
        }

    if (v==1)
    {
    // cate piste nu au clustere ocupate
    po=0;
    for(i=1;i<=np;i++)
        if (hdd[i][0]) po++;
    g<<np-po;
    }

    if (v==2)
    {
    // determin numarul minim de mutari de clusteri, pe fiecare pista,pentru a obtine zone contigue
    for(i=1;i<=np;i++)
        {
        min=ns;nso=hdd[i][0];
        // j = pozitie inceput de secventa
        s=0;
        for(j=1;j<=nso;j++)
            if (hdd[i][j]==0) s++;

        if (s<min) min=s;

        for(j=2;j<=ns;j++)
            {
            if (hdd[i][j-1]==0) s--;

            if (hdd[i][j+nso-1]==0) s++;

            if (s<min) min=s;
            }
        g<<min<<" ";
        }
    }

    g<<"\n";
    f.close();
    g.close();

    return 0;
}
