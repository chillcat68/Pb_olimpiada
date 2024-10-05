//Em. Cerchez 40 puncte
#include <fstream>
#include <cassert>

using namespace std;

ifstream fin("ech.in");
ofstream fout("ech.out");

long long int a;


int ech()
{ int s1=0, s2=0;
  long long int x=a;
  for (int i=0; x; i++, x/=10)
      if (i%2) s1+=x%10;
         else s2+=x%10;
  return s1==s2;
}

int main()
{
 fin>>a;
 //incrementez a pana obtin un numar echilibrat.
 while (1)
	{
		a++;
		if(ech()) break;
	}
 //afisare
 fout<<a<<'\n';
 fout.close();
 return 0;
}
