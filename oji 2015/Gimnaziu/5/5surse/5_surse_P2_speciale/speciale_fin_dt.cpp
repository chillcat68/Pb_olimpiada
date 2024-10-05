#include <fstream>
using namespace std;
ifstream f("speciale.in");
ofstream g("speciale.out");

int main()
{int k,n,a,b,x=0,i,pr,nr=0,nr1=0,p1,fin_nr,ok=0,nr2,p;
f>>p>>k>>n>>a>>b;
if(p==1)
{x=0;
for(i=9;i>9-k;i--)
    x=i+x*10;
g<<x<<'\n';}

//cerinta 2
if(p==2)
{pr=n;
while(pr)
    {
        pr=pr/10;
        nr++;
    }
    nr--;
for(i=1;i<=nr;i++)
    nr1=i+nr1*10;
p1=0;pr=n;fin_nr=nr1;
while(pr)
{
    if(pr%10==nr1%10) {pr=pr/10;nr1=nr1/10;}
   else {p1++;pr=pr/10;}
}
if(p1==1) {g<<fin_nr<<'\n';ok=1;}
else
{nr1=0;
    for(i=9;i>9-nr;i--)
    nr1=i+nr1*10;
    p1=0;pr=n;fin_nr=nr1;
while(pr)
{
    if(pr%10==nr1%10) {pr=pr/10;nr1=nr1/10;}
   else {p1++;pr=pr/10;}
}
if(p1==1) {g<<fin_nr<<'\n';ok=1;}
}
if(ok==0) g<<0<<'\n';
}
//cerinta 3
if(p==3)
{
nr=0;
pr=a;nr1=0;
while(pr){pr=pr/10;nr++;}
for(i=1;i<=nr;i++)
    nr1=i+nr1*10;
nr2=0;
for(i=9;i>9-nr;i--)
nr2=i+nr2*10;
x=0;
if(nr1>=a) x++;
if(nr2>=a&&nr2<=b) x++;
nr++;pr=nr2%10-1;
while(nr2<b && nr1<b)
{
    nr2=nr2*10+pr;
    nr1=nr1*10+nr;
    nr++;pr--;
    if(nr1<=b) x++;
    if(nr2<=b) x++;
}
g<<x<<'\n';
}

f.close();
g.close();
    return 0;
}
