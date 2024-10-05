#include <fstream>
#include <vector>
using namespace std;
ifstream f("ordine.in");
ofstream g("ordine.out");
int n,i,j,m,k;
vector <int> v;
int main()
{ f>>n;
  for(i=1;i<=n;i++){f>>k;v.push_back(k);}
  f>>k;
  if(k==1) if(n%2==0) g<<v[n-1]<<'\n';
                 else g<<v[n/2]<<'\n';
    else
    { i=0;m=(n-1)/2;j=m+1;
      while(j<n) g<<v[i++]<<' '<<v[j++]<<' ';
      if(n%2) g<<v[m]<<' ';
      g<<'\n';
    }
  f.close(); g.close();
    return 0;
}
