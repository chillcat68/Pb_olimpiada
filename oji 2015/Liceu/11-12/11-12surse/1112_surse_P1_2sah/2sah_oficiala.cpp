//Problema 2sah - solutia oficiala O(log N)
//Sursa: Panaete Adrian

#include <fstream>
#define tip long long
#define MOD 100003

using namespace std;

ifstream f("2sah.in");
ofstream g("2sah.out");

tip t,n,k,A[3][3],S[3][3],C[3][3];

void sol1(),sol2();

int main()
{
    f>>t>>n>>k;
    if(t==1)sol1();
    else sol2();
    return 0;
}
void sol1()
{
    tip ans=1,p=3;
    for(k--;k;k>>=1)
    {
        if(k%2)ans=(ans*p)%MOD;
        p=(p*p)%MOD;
    }
    g<<ans;
}
void sol2()
{
    int i,j,q;
    k=n+2-k;
    for(i=0;i<3;i++)
    {
        S[i][i]=1;
        A[2][i]=1;
    }
    A[0][1]=A[1][2]=1;
    for(;k;k>>=1)
    {
        if(k%2)
        {
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                {
                    C[i][j]=0;
                    for(q=0;q<3;q++)
                        C[i][j]=(C[i][j]+S[i][q]*A[q][j])%MOD;
                }
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    S[i][j]=C[i][j];

        }
        for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                {
                    C[i][j]=0;
                    for(q=0;q<3;q++)
                        C[i][j]=(C[i][j]+A[i][q]*A[q][j])%MOD;
                }
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    A[i][j]=C[i][j];
    }
    g<<S[1][2];
}
