#include <iostream>
#include <fstream>

using namespace std;

ifstream f("spiralmatrix.in");
ofstream g("spiralmatrix.out");

using ull=unsigned long long;

ull n;
//afla care este numarul din colt
ull colt(ull cadran)
{
    return 1+4*(cadran-1)*n-4*(cadran-1)*(cadran-1);
}

int main()
{

    f>>n;
    ull c=n*n/2;
    ull st=1,dr=n/2;
    //cautam binar cadranul in care se afla
    while(st<dr)
    {
        ull mij=(st+dr)/2;
        if(st==mij)
            break;
        if(c<colt(mij))
            dr=mij-1;
        else
            st=mij;
    }

    if(c>colt(dr))
        st=dr;
    //stabilim care sunt colturile in cadranul in care cautam
    ull l=(n-(2*st-1));
    ull st_sus=colt(st);
    ull dr_sus=st_sus+l;
    ull dr_jos=dr_sus+l;
    ull st_jos=dr_jos+l;
    //cautam numarul pe fiecare latura
    if(c<dr_sus)
        g<<st<<' '<<st+c-st_sus<<'\n';
    else if(c<dr_jos)
        g<<st+c-dr_sus<<' '<<st+l<<'\n';
    else if(c<st_jos)
        g<<st+l<<' '<<st+st_jos-c<<'\n';
    else
        g<<st+l-c+st_jos<<' '<<st<<'\n';

    //la fel pentru al doilea numar doar ca el creste cu 1 sau 2 in functie de paritatea lui n
    c+=1+n%2;
    st=1,dr=n/2;
    while(st<dr)
    {
        ull mij=(st+dr)/2;
        if(st==mij)
            break;
        if(c<colt(mij))
            dr=mij-1;
        else
            st=mij;
    }
    if(c>colt(dr))
        st=dr;
    l=(n-(2*st-1));
    st_sus=colt(st);
    dr_sus=st_sus+l;
    dr_jos=dr_sus+l;
    st_jos=dr_jos+l;
    if(c<dr_sus)
        g<<st<<' '<<st+c-st_sus<<'\n';
    else if(c<dr_jos)
        g<<st+c-dr_sus<<' '<<st+l<<'\n';
    else if(c<st_jos)
        g<<st+l<<' '<<st+st_jos-c<<'\n';
    else
        g<<st+l-c+st_jos<<' '<<st<<'\n';

    return 0;
}
