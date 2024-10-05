#include <fstream>

using namespace std;
ifstream f("2sah.in");
ofstream g("2sah.out");
const int MOD=100003;
int n,t,k,i,ans,t0,t1,t2,t3;
int main()
{
    f>>t>>n>>k;
    if(t==1)
    {
        ans=1;
        for(k--;k;k--)
            ans=(ans*3)%MOD;
        g<<ans;
        return 0;
    }
    k=n+2-k;
    if(k<3){g<<1;return 0;}
    t1=t2=1;
        for(i=3;i<=k;i++)
        {
            t3=(t0+t1+t2)%MOD;
            t0=t1;t1=t2;t2=t3;
        }
    g<<t3;
    return 0;
}
