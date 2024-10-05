#include <iostream>

using namespace std;
int v[100001], i, x, q, tip, n;

int main()
{
    cin>>q;
    while (cin>>tip) {

        if (tip==1) {
            cin>>x;
            v[x]++;
            if (x>n)
                n=x;
        }
        else if(tip==2) {
            cin>>x;
            v[x]--;
        }
        else {
            int ct=0;
            for (i=0; i<=n; i++)
                if (v[i]>0)
                    ct++;
            cout<<ct<<'\n';
        }
    }
    return 0;
}
