#include <fstream>
#define MOD 100003
using namespace std;
ifstream f("2sah.in");
ofstream g("2sah.out");
long long t,n,k,sol,i,j,m,A[3][3],
P[3][3]={{0,1,0},{0,0,1},{1,1,1}},
S[3][3]={{1,0,0},{0,1,0},{0,0,1}};
int main()
{
    f>>t>>n>>k;
    if(t==1)
    {
        sol=1;k--;k%=(MOD-1);//utilizand teorema Fermat
        for(;k;k--)
        {
            sol=(3*sol)%MOD;
        }
        g<<sol;
        return 0;
    }
    k=n+2-k;
    for(;k;k>>=1)
    {
        if(k&1)
        {
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                    for(m=0;m<3;m++)
                        A[i][j]+=S[i][m]*P[m][j];
            for(i=0;i<3;i++)
                for(j=0;j<3;j++)
                {
                    S[i][j]=A[i][j]%MOD;
                    A[i][j]=0;
                }



        }
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                for(m=0;m<3;m++)
                    A[i][j]+=P[i][m]*P[m][j];
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            {
                P[i][j]=A[i][j]%MOD;
                A[i][j]=0;
            }

    }
    g<<S[2][0]<<'\n';
    return 0;
}
