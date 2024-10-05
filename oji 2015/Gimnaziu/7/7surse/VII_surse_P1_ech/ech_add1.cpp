//Em. Cerchez 80 puncte
#include <fstream>
#include <cassert>

using namespace std;

ifstream fin("ech.in");
ofstream fout("ech.out");

int a[100];
int lg=0;

void add()
{int i;
 for (i=0; a[i]==9; i++) a[i]=0;
 a[i]++;
 if (i==lg) lg++;
}

int ech()
{ int s1=0, s2=0;
  for (int i=0; i<lg; i+=2)
	   s1+=a[i], s2+=a[i+1];
  return s1==s2;
}

int main()
{char c;
 int st, dr, aux, i;
 while (fin>>c)
       	{assert(c>='0'&& c<='9');
         a[lg++]=c-'0';
        }
 assert(lg<24);

 //inversez a
 for (st=0, dr=lg-1; st<dr; st++, dr--)
      {	aux=a[st]; a[st]=a[dr]; a[dr]=aux;     }
 //incrementez a pana obtin un numar echilibrat.
 while (1)
	{
		add();
		if(ech()) break;
	}
 //afisare
 for (i=lg-1; i>=0; i--)   fout<<a[i];
 fout<<'\n';
 fout.close();
 return 0;
}
