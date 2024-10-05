#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("buldo.in");
    ofstream g("buldo.out");
    int H=1, i, n, h[100001], s[100001]={0};
    f>>n;

    for (i=1; i<=n; ++i)
    {
        f>>h[i];
        s[i]=(s[i-1]+h[i]);
    }
    for(i=1; i<=n; i++)
        s[i]=s[i]/i;
    int mini=s[1];
    for (i=2; i<=n; i++)
        mini=min(mini,s[i]);
    g<<mini;
    return 0;
}
