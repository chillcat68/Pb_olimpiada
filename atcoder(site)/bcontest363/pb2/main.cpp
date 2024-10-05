#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int v[101], n, t, p , i;
    cin>>n>>t>>p;
    for (i=1; i<=n; i++)
        cin>>v[i];
    int ct=0;
    for (i=1; i<=n; i++) {
        if (v[i]>=t)
            ct++;

    }

    if (ct>=p)
        cout<<0;
    else {
        sort(v+1, v+n+1);
        cout<<t-v[n-p+1];
    }

    return 0;
}
