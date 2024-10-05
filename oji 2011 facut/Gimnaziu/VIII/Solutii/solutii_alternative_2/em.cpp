//cerchez emanuela
#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#define LgMax 256

int n, nr;
int r[1001];
char s[LgMax];

long int expresie (char *);
long int numar (char *);

int main()
{
  ifstream fin("comp.in");
  ofstream fout("comp.out");
  char *p;
  int semn, i;
  long int st, dr;

  fin>>n;
  for (i=0; i<n; i++)
      {fin>>s;
       p=strchr(s,'<');
       if (p) {nr++; semn=1;}
          else {p=strchr(s,'>');semn=0;}
       *p=0;
       st=expresie(s);
       dr=expresie(p+1);
       if (semn)
          if (st<dr) r[i]=1; else r[i]=0;
          else
          if (st>dr) r[i]=1; else r[i]=0;
       }
  fout<<nr<<'\n';
  for (i=0; i<n; i++) fout<<r[i]<<'\n';
  fout.close();
  return 0;
}

long int expresie (char *s)
{
char *p;
long int sum=0, x;
p=strtok(s,"+");
while (p)
       {x=numar(p);
        sum+=x;
        p=strtok(NULL, "+");}
return sum;
}


long int numar (char * s)
{
long int sum=0;
char *p;
p=strchr(s,'m');
if (p)
   {*p=0;
    sum+=1000*atol(s);
    s=p+1;}
p=strchr(s,'s');
if (p)
   {*p=0;
    sum+=100*atol(s);
    s=p+1;}
p=strchr(s,'z');
if (p)
   {*p=0;
    sum+=10*atol(s);
    s=p+1;}
p=strchr(s,'u');
if (p)
   {*p=0;
    sum+=atol(s);
   }
return sum;
}