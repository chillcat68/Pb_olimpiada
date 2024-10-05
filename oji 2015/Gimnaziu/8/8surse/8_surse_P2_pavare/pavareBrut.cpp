#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("pavare.in");
ofstream fout("pavare.out");
int v,n,k;
int var1(int n)
{
    int k=0,s=0;
    do
    {
        k++;
        s+=2*k;
    }while(n>s);
    if(s-k>=n)return 2*k-1;
    return 2*k;
}
void var2(int n, int k)
{

}
int main()
{
    fin>>v>>n;
    k=var1(n);
    if(v==1)fout<<k;
     else var2(n,k);

    return 0;
}
