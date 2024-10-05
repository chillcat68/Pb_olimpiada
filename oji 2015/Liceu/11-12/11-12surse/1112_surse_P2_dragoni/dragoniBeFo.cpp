#include <fstream>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#define tip long long
using namespace std;

ifstream f("dragoni.in");
ofstream g("dragoni.out");

const int N=1005;
int n,m,i,j,x,y,d,ic,t,b,q[N][N],Q1[N],q1[N];
tip Dist[N][N],dist,oo,dc,D[N],sol;
vector<pair<tip,int> > v[N];
vector< int > V[N];
deque<pair<int,int> > Q;
void cerinta1(),cerinta2();


int main()
{
    f>>t>>n>>m;
    for(i=1;i<=n;i++)
        f>>D[i];
    if(t==1)cerinta1();
    else cerinta2();
    return 0;
}
void cerinta1()
{
    for(;m;m--)
    {
        f>>x>>y>>d;
        if(d<=D[1])
        {
            V[x].push_back(y);
            V[y].push_back(x);
        }
    }
    Q1[1]=1;q1[1]=1;t=b=1;
    for(;b<=t;)
    {
        x=Q1[b++];
        for(vector<int>::iterator it=V[x].begin();it!=V[x].end();it++)
            if(!q1[*it])
            {
                Q1[++t]=*it;
                q1[*it]=1;

            }
    }
    sol=D[1];
    for(i=1;i<=n;i++)
        if(q1[i])
            sol=max(sol,D[i]);
    g<<sol;
}
void cerinta2()
{
    //creez listele de vecini ca perechi (distanta,vecin)
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>d;
        v[x].push_back(make_pair(d,y));
        v[y].push_back(make_pair(d,x));
    }
    //sortez listele de vecini dupa distante
    for(i=1;i<=n;i++)
        sort(v[i].begin(),v[i].end());
    //initializez matricea distantelor
    oo=1LL*1000000000*1000000000;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            Dist[i][j]=oo;
    //initializez coada Bellman - Ford
    Q.push_back(make_pair(1,1));
    q[1][1]=1;
    Dist[1][1]=0;
    sol=oo;
    for(;Q.size();)
    {
        //scot primul element din coada , ii memorez insula,dragonul si iau distanta corespunzatoare
        ic=Q.front().first;
        dc=Q.front().second;
        q[ic][dc]=0;
        dist=Dist[ic][dc];
        Q.pop_front();
        //daca gasesc dragon mai bun schimb dragonul
        if(D[ic]>D[dc])dc=ic;
        //parcurg vecinii pe care dragonul ii poate atinge
        for(vector<pair<tip,int> >::iterator it=v[ic].begin();it!=v[ic].end()&&D[dc]>=it->first;it++)
        {
            //daca obtin o distanta mai proasta decat solutia
            //sau mai proasta decaat distanta pentru insula vecina cu dragonul curent
            //atunci renunt sa ma deplasez acolo
            if(dist+it->first>=sol||dist+it->first>=Dist[it->second][dc])continue;
            //daca vecinul e destinatia updatez solutia
            if(it->second==n)
            {
                sol=dist+it->first;
                continue;
            }
            //altfel updatez distanta pentru vecin cu dragonul curent
            Dist[it->second][dc]=dist+it->first;
            //daca prerechea vecin,dragon nu e in coada o adaug
            if(!q[it->second][dc])
            {
                q[it->second][dc]=1;
                Q.push_back(make_pair(it->second,dc));
            }
        }
    }
    g<<sol;
}
