#include <iostream>

using namespace std;

int main()
{
    int n, t, a;
    cin>>n>>t>>a;
    if ((n-t-a)+min(t, a)>max(t, a))
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}
