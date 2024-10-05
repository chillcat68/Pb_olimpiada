/*
	Sursa 48p - O(n*n) amortizat
	prof. Zoltan Szabo
	isj. Mures
*/
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("charlie.in");
ofstream fout("charlie.out");

int main()
{
    int n,p,i,max,l,cresc;
    char cuv[100001];
    fin>>p;
    max=1;
    fin>>cuv;
    n=strlen(cuv);
    if (p==1)
    {
        cresc=0;
        l=1;
        for(i=1;i<n;++i)
        {
            if ((cuv[i-1]>cuv[i] and !cresc) or (cuv[i-1]<cuv[i] and cresc))
            {
                l++;         // creste lungimea
                cresc=1-cresc;   // schimbam conditia pentru relatie
            }
            else
            {
                if (l%2==0) l--;
                if (l>max) max=l;
                if (cuv[i-1]>cuv[i])
                {
                    l=2;
                    cresc=1;
                }
                else
                {
                    l=1;
                    cresc=0;
                }

            }
        }
        if (l%2==0) l--;
        if (l>max) max=l;

        fout<<max<<"\n";
    }
    else
    {
        int cod,s=0;
        do
        {
            cod=0;
            for (i=1;i<strlen(cuv)-1;)
            {
                if (cuv[i]<cuv[i-1] and cuv[i]<cuv[i+1])
                {
                    if(cuv[i-1]>cuv[i+1])
                        s=s+cuv[i-1]-'a'+1;
                    else
                        s=s+cuv[i+1]-'a'+1;
                    strcpy(cuv+i,cuv+i+1);
                    cod=1;
                }
                else
                    ++i;
            }
        }
        while (cod);
        fout<<cuv<<"\n";
        fout<<s<<"\n";
    }
    fout.close();
    fin.close();
    return 0;
}
