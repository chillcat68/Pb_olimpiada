#include<fstream.h>
ifstream f("magic.in");
ofstream g("magic.out");
long nr,nr_fin,m; int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9;
int main()
{int n,i; char x;
f>>n;
for(i=1;i<=n;i++)
{f>>x;
if (!(x>='0' && x<='9')) g<<(char)(x-32);
else

switch (x)
{
case '0':x0++;break;
case '1': x1++;break;
case '2': x2++;break;
case '3': x3++;break;
case '4': x4++;break;
case '5': x5++;break;
case '6': x6++;break;
case '7': x7++;break;
case '8': x8++;break;
case '9': x9++;break;
}
}
if(x1!=0 &&x0!=0) {nr=(nr*10+1)*10;x0=0;}
else if(x1!=0) nr=nr*10+1;
if(x2!=0 &&x0!=0) {nr=(nr*10+2)*10;x0=0;}
else if (x2!=0) nr=nr*10+2;
if(x3!=0 &&x0!=0) {nr=(nr*10+3)*10;x0=0;}
else if(x3!=0) nr=nr*10+3;
if(x4!=0 &&x0!=0) {nr=(nr*10+4)*10;x0=0;}
else if(x4!=0) nr=nr*10+4;
if(x5!=0 &&x0!=0) {nr=(nr*10+5)*10;x0=0;}
else if(x5!=0) nr=nr*10+5;
if(x6!=0 &&x0!=0) {nr=(nr*10+6)*10;x0=0;}
else if(x6!=0) nr=nr*10+6;
if(x7!=0 &&x0!=0) {nr=(nr*10+7)*10;x0=0;}
else if(x7!=0) nr=nr*10+7;
if(x8!=0 &&x0!=0) {nr=(nr*10+8)*10;x0=0;}
else if(x8!=0) nr=nr*10+8;
if(x9!=0 &&x0!=0) {nr=(nr*10+9)*10;x0=0;}
else if(x9!=0) nr=nr*10+9;

if(nr==0) g<<'\n'<<0<<'\n';
else g<<'\n'<<nr<<'\n';
f.close();
g.close();
return 0;
}
