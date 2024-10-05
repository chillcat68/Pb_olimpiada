#include<fstream.h>
#include<stdio.h>
//using namespace std;

int a[10002],n,i;
int val,nr_pag,zile,max,poz;
ifstream f("carte.in");
ofstream g("carte.out");

void citire()
{f>>n;
  for(i=1;i<=n;i++)
    f>>a[i];
}

void o_solutie()
{ val=1;zile=0;

  while(val<=n)
   { zile++ ;
     nr_pag=0;
     i=1;
      while(i<=n)
	{ if(a[i]==val)
	     {nr_pag++;
	      val++;
	     }
	  i++;
	}
     if(nr_pag>max)
	 {max=nr_pag;
	  poz=zile;
	 }
   }

 g<<zile<<" ";
 g<<poz<<" ";
 g<<max;
 g.close();
}

int main()
{ citire();
  o_solutie();

return 0;
}
