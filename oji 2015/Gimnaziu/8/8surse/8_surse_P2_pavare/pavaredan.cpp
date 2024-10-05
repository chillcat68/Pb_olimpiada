#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("pavare.in");
ofstream fout("pavare.out");

int i,n,k,c,t,p,z;
int main()
{
        fin>>c>>n;
        k=2*sqrt(n)-1+(sqrt(n)!=(int)sqrt(n));
        if(c==1)fout<<k;
           else for(i=1,z=1,p=((k+k%2)/2)*((k+k%2)/2+1-k%2),t=1;i<=k;i++,z+=t)
                {
                    fout<<z-((i>=(k/2+n-p+1+k%2))&&(i<=k/2+k%2))<<" ";
                    if(i>=k/2+k%2)t=-1;
                    if(i==k/2&&(k%2==0))t=0;
                }

    fout.close();
    fin.close();
    return 0;
}
