#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    int v[20], i, n;
    ifstream f("date.in");
    f>>n;
    for(i=1; i<=n; i++)
        f>>v[i];
    swap(v[1],v[n]);
    sort(v+1,v+n+1);
    for (i=1; i<=n ;i++)
        cout<<v[i]<<' ';
    int x=89, st=1, dr=n, mij;
    while (st<dr)
    {
        mij=(st+dr)/2;
        if(v[mij]==x)
        {
            cout<<v[mij]<<' '<<"pe pozitia "<<mij;
            break;
        }
        else
        {
            if (v[mij]<x)
                st=mij+1;
            else
                dr=mij-1;
        }
    }
    if(st>dr)
        cout<<"Nu exista";

    return 0;
}
