#include <fstream>
using namespace std;
ifstream f("ordine.in");
ofstream g("ordine.out");
int n,i,j,m,k, v[500001];
int main()
{ f>>n;
  for(i=1;i<=n;i++)f>>v[i];
  f>>k;
  if(k==1) if(n%2==0) g<<v[n]<<'\n';
                 else g<<v[n/2+1]<<'\n';
    else
    { i=1;j=(n+1)/2;
      for(i=1;i<=n/2;i++) g<<v[i]<<' '<<v[i+j]<<' ';
      if(n%2) g<<v[j]<<' ';
      g<<'\n';
    }
  f.close(); g.close();
    return 0;
}
