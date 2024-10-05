#include<fstream.h>
ifstream f("numerus.in");
ofstream g("numerus.out");
long n,k;
int main()
{  long lin;
f>>k>>n;
lin=n/5;
//prima cerinta
if(k%2==0) g<<5*k<<' '<<5*k<<' '<<5*k-1<<' '<<5*k-2<<' '<<5*k-3<<' '<<5*k-4<<'\n';
	else g<<5*k-4<<' '<<5*k-3<<' '<<5*k-2<<' '<<5*k-1<<' '<<5*k<<' '<<5*k<<'\n';
//a doua cerinta
if(n%5==0) g<<lin<<'\n';
	else {lin++;g<<lin<<'\n';}
// a treia cerinta
if(lin%2==0) if(n%5==0) g<<'A'<<' '<<'B';
		else g<<(char)('B'+(5-n%5));
else if(n%5==0) g<<'E'<<' '<<'F';
	else g<<(char)('E'-(5-n%5));
g<<'\n';
f.close();
g.close();
return 0;
}

