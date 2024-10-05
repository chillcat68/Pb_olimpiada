#include <fstream>
#include <map>
#include<set>
#define tip long long
#define MOD 100003
using namespace std;
ifstream f("2sah.in");
ofstream g("2sah.out");
map<int,int> T;
set<int> S;
void solve(int);
long long t,n,k,sol,p;
int main()
{
    f>>t>>n>>k;
    if(t==1) for(k--,sol=1,p=3;k;k/=2){ if(k&1)sol=(sol*p)%MOD; p=(p*p)%MOD;}
    else
        {
            T[0]=0;T[1]=1;T[2]=1;T[3]=2;
            for(int i=0;i<4;i++)S.insert(i);
            n=n+2-k;
            solve(n);
            sol=T[n];
        }
    g<<sol<<'\n';
    return 0;
}
void solve(int M)
{
    if(S.find(M)!=S.end())return;
    int m=M/2;

    solve(m+1);solve(m);solve(m-1),solve(m-2);
    S.insert(M);
    if(M%2)
        T[M]=(1LL*T[m]*T[m-1]+1LL*T[m]*T[m-1]+1LL*T[m]*T[m]+1LL*T[m+1]*T[m+1])%MOD;
    else
        T[M]=(1LL*T[m]*T[m+1]+1LL*T[m-1]*T[m]+1LL*T[m-2]*T[m]+1LL*T[m-1]*T[m-1])%MOD;
}
