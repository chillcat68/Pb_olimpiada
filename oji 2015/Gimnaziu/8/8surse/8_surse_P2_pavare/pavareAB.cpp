/* ===================================
 Pavare Alin
=====================================*/
#include <fstream>
#include <iostream>
#define FIN "pavare.in"
#define FOU "pavare.out"
#define NMAX 100001
using namespace std;

long  int N;                            //lungimea drumului;
short int V;                            //tipul testului
short int NrApar[ NMAX ];               //numarul de aparitii pentru fiecare posibila dala
long  int K, i, CN, NrDale, Dala;

int main()
{
    ifstream IN(FIN);
    // citire date de intrare
    IN>>V>>N;
    IN.close();

    //rezolvare
    ofstream OU(FOU);
    if( V == 1)
    {
        //rezolvarea cerintei 1
        CN     = N;
        NrDale = 0;
        // calculez un numar k a.i 1,2,..k,k,k-1,...1 sa fie cel mult N
        for( K = 1; K*(K+1) <= CN ; ++K);
        K--;
        NrDale += 2*K;
        CN = CN - K*(K+1);
        //acum incerc sa asez dale cat mai mari care sa acopere distanta ramasa
        Dala = K+1;
        while(CN && Dala > 0)
        {
            while(CN >= Dala) { CN -= Dala; NrDale++;}
            Dala--;
        }
        OU<<NrDale<<'\n';
    }
    else
    {
        //rezolvarea cerintei 2
        for(i = 1; i < NMAX; ++i) NrApar[i] = 0;
        CN     = N;
        NrDale = 0;
        // calculez un numar k a.i 1,2,..k,k,k-1,...1 sa fie cel mult N
        for( K = 1; K*(K+1) <= CN ; ++K);
        K--;
        NrDale += 2*K;
        CN = CN - K*(K+1);
        for( i = 1; i <= K; ++i) NrApar[i] += 2;

        //acum incerc sa asez dale cat mai mari care sa acopere distanta ramasa
        Dala = K+1;
        while(CN && Dala > 0)
        {
            while(CN >= Dala) { CN -= Dala; NrApar[Dala]++; NrDale++;}
            Dala--;
        }
        for ( i = 1; i<NMAX; ++i)
        {
            if(NrApar[i] % 2 == 1)
            {
                for( K = 1; K <= NrApar[i]/2 + 1; ++K) OU<<i<<' ';
                NrApar[i] /= 2;
            }
            else
            {
                for( K = 1; K <= NrApar[i]/2; ++K) OU<<i<<' ';
                NrApar[i] /= 2;
            }
        }
        for ( i = NMAX - 1; i>0; --i)
        {
            for( K = 1; K <= NrApar[i]; ++K) OU<<i<<' ';
        }
    }
    OU.close();
    return 0;
}
