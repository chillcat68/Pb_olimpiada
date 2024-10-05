#include <fstream>
#include <vector>
#include <utility>
#include <deque>

#define tip long long
#define mp make_pair
#define IN first
#define DR second
using namespace std;

ifstream f("dragoni.in");
ofstream g("dragoni.out");

int t,n,m,P[1005][1005],D[1005],Q1[1005],q1[1005],b,LH,T[1005][1005];
vector<int> V[1005];
vector<pair<int,int> > v[1005];
deque<int> Q;
void cerinta1(),cerinta2();
int main()
{
    f>>t>>n>>m;
    for(int i=1;i<=n;i++)f>>D[i];
    if(t==1)cerinta1();else cerinta2();
    return 0;
}
void cerinta1()
{
    int x,y,d,sol;
    for(;m;m--){f>>x>>y>>d;if(d<=D[1]){V[x].push_back(y);V[y].push_back(x);}}
    Q1[1]=1;q1[1]=1;t=b=1;
    for(;b<=t;){x=Q1[b++];for(vector<int>::iterator it=V[x].begin();it!=V[x].end();it++)if(!q1[*it]){Q1[++t]=*it;q1[*it]=1;}}
    sol=D[1];for(int i=1;i<=n;i++)if(q1[i])sol=max(sol,D[i]);g<<sol;
}
void cerinta2()
{
    int x,y,d,i,j,k,oo=1000000000;
    pair<int,int> Per;
    for(int i=1;i<=m;i++)
    {
        f>>x>>y>>d;
        v[x].push_back(make_pair(d,y));
        v[y].push_back(make_pair(d,x));
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)T[i][j]=oo;
        T[i][i]=0;Q.push_back(i);q1[i]=1;
        for(;Q.size();)
        {
            j=Q.front();
            Q.pop_front();q1[j]=0;
            for(vector<pair<int,int> >::iterator it=v[j].begin();it!=v[j].end();it++)
                if(D[i]>=it->first)
                    if(T[i][it->second]>T[i][j]+it->first)
                    {
                        T[i][it->second]=T[i][j]+it->first;
                        if(!q1[it->second])
                        {
                            q1[it->second]=1;
                            Q.push_back(it->second);
                        }

                    }
        }

    }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i!=k&&i!=j&&k!=j&&T[i][j]>T[i][k]+T[k][j])
                    T[i][j]=T[i][k]+T[k][j];

    g<<T[1][n];
}
