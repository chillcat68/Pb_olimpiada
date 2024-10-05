#include <fstream>
using namespace std;
ifstream f("ordine.in");
ofstream g("ordine.out");
int main()
{ long n,a[50001];
  int i,k,m;
  f>>n;
  for(i=1;i<=n;i++)
      f>>a[i];
  f>>m;
  if(m==1)
      if(n%2==0) g<<a[n];
      else g<<a[(n+1)/2];
  if(m==2) { i=1;
             k=n/2+n%2;
             while(i<=n/2)
             {g<<a[i]<<" "<<a[i+k]<<" ";
              i++;}
             if(n%2==1) g<<a[i];}
  return 0;}

