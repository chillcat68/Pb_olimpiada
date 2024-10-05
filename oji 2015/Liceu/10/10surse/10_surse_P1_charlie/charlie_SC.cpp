/*
	Sursa 100p
	prof. Stelian Ciurea, Sibiu
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <int> a;
ifstream f("charlie.in");
ofstream g("charlie.out");
int tip,maxim=0;

int main()
{
    //cout << "Hello world!" << endl;
    f >> tip;
    char buf;
    while (f>>buf)
    {
        //cout << buf;
        a.push_back(buf - 'a'+1);
        maxim = max(maxim,buf - 'a'+1);
    }
    if (tip == 1)
    {
        int n = a.size();
        a.push_back(a[n-1]);a.push_back(a[n-1]);a.push_back(a[n-1]);a.push_back(a[n-1]);
        int lmaxim = 0, lcrt=0;
        for (int i=1;i<n;i+=2)
        {
                if (a[i]<a[i-1]&&a[i]<a[i+1])
                {
                    if (lcrt==0)
                        lcrt=3;
                    else
                        lcrt +=2;
                    //cout << i << ' ' << lcrt << "   ";
                }
                else
                    lcrt=0;
                lmaxim = max(lmaxim,lcrt);
        }
        for (int i=2;i<n;i+=2)
        {
                if (a[i]<a[i-1]&&a[i]<a[i+1])
                {
                    if (lcrt==0)
                        lcrt=3;
                    else
                        lcrt +=2;
                    //cout << i << ' ' << lcrt << "   ";
                }
                else
                    lcrt=0;
                lmaxim = max(lmaxim,lcrt);
        }
        cout << lmaxim << endl;
        g << lmaxim << endl;
    }
    if (tip == 2)
    {
        int cost=0,i,j;
        for (j=1;j<maxim;j++)
        {
            //cout << j << endl;
            vector <int> b;
            b.push_back(a[0]);
            for (i=1;i<a.size()-1;i++)
                if (a[i]==j&& a[i]<min(a[i-1],a[i+1]))
                    cost +=max(a[i-1],a[i+1]);
                else
                    b.push_back(a[i]);
            b.push_back(a[a.size()-1]);
            a = b;
        }
        cout << cost << endl;
        for (i=0;i<a.size();i++)
            g << char('a'-1+a[i]);
        g << endl << cost << endl;
    }
    return 0;

}
