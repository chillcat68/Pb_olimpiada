#include <iostream>
#include <fstream>

using namespace std;

unsigned long v[10];

//exista cel putin o cifra inafara de 0 care apare de min 2 ori

/*bool exis_min_2x(int a[])
{
    bool exis2_nr=false;
    int i=1;            //0 nu ne intereseaza, pt ca un nr nu poate incepe cu cifra 0
    while (exis2_nr==false && i<=9)
    {
        if(a[i]>=2)
            exis2_nr=true;
        i++;
    }
    return exis2_nr;
}*/


int main()
{
    ifstream f("balba.in");
    ofstream g("balba.out");

    int C;

    f>>C;
    //avem 2 probleme
    switch (C)
    {
    case 1:
        {
            int x, n, i, ant, ct_dif=0, ct_repeta;
            bool nr_egale=false;
            ct_dif=1;
            ct_repeta=0;
            f>>n;
            f>>x;
            //f>>x;f>>x;f>>x;f>>x;f>>x;f>>x;f>>x;

            for(i=2; i<=n; i++)
            {
                ant=x;
                f>>x;

                if(ant!=x)
                {
                    ct_dif++;
                    nr_egale=false;
                }
                else if(nr_egale==false)
                {
                    ct_repeta++;
                    nr_egale=true;
                }
            }

            g<<ct_dif<<'\n'<<ct_repeta;
        }break;

    case 2:
        {
            int x, i, n, jum;
            unsigned long long palilindrom=0;
            bool impar_adaugat=false;
            f>>n;
            //construim vector de frecventa
            for (i=1; i<=n; i++)
                {
                    f>>x;
                    v[x]++;
                }
            // verif daca exista cel putin o cifra cu min 2 aparitii
            bool exis2_nr=false;
            i=1;            //0 nu ne intereseaza, pt ca un nr nu poate incepe cu cifra 0
            while (exis2_nr==false && i<=9)
            {
                if(v[i]>=2)
                    exis2_nr=true;
                i++;
            }
            if(exis2_nr==true)
            {
                // construim prima jum a numarului de la cel mai mare la cel mai mic
                for(i=9; i>=0; i--)
                {
                    if (v[i]%2==0)
                    {
                        jum=v[i]/2;
                        while (jum!=0)
                        {
                            palilindrom=palilindrom*10+i;
                            jum--;
                        }
                    }
                    else
                    {
                        // o aparitie impara este adaugata o singura data de v[i]/2+1
                        if(impar_adaugat==false)
                            jum=v[i]/2+1;
                        else
                            jum=v[i]/2;
                        while (jum!=0)
                        {
                            palilindrom=palilindrom*10+i;
                            jum--;
                        }
                        impar_adaugat=true;
                    }
                }

                // adaugam a doua jum in oglinda de la mic la mare
                for(i=0; i<=9; i++)
                {
                    jum=v[i]/2;
                    while (jum!=0)
                    {
                        palilindrom=palilindrom*10+i;
                        jum--;
                    }
                }
            }
            else
            {
                i=9;
                while (v[i]==0 && i>=0)
                    i--;
                palilindrom=i;
            }
            g<<palilindrom;
        }break;
    }


    return 0;
}
