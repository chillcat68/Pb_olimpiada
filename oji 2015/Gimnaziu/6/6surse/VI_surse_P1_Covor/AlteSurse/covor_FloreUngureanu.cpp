#include <fstream>
using namespace std;
ifstream f("covor.in");
ofstream g("covor.out");
int n,k,i,l,v;
int main()
{
    f>>n>>k>>v;
    i=1;
    while(2*i*(i+1)-i+1<=n)i++;
    i--;
   if(v==1) {g<<i<<'\n';return 0;}
    l=2*i*(i+1)-i+1;
    if(k>l) g<<"0\n";
    else
    {
        if(k<=(i+1)*(i+2)-2*i-1)
        {
            i=1;
            while((i+1)*(i+2)-2*i-1<k)i++;
            g<<i<<'\n';
        }
        else
        {
            l=i;int p=0;
            while(i>=1)
            {
                p+=2*i-1;
                if((l+1)*(l+2)-2*l-1+p>=k)
                {
                    g<<i<<'\n';return 0;
                }
                i--;
            }
        }
    }
    return 0;
}
