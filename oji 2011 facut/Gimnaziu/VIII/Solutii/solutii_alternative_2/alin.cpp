//burtza alin
#include <fstream.h>
#include <string.h>
#include <ctype.h>
#define Fin "comp.in"
#define Fou "comp.out"
#define Max 251

//transform numarul reprezentat ca sir de caractere intr-un numar natural
long transforma(char *nr)
{
  long rez;
  int i,nm, ns, nz, nu, rp;
  rez=0; i = nm = ns = nz = nu =rp = 0;
  while(isdigit(nr[i])) { rp = rp * 10 + nr[i] - 48; i++;}
  if(nr[i]=='m') nm = rp;
  if(nr[i]=='s') ns = rp;   
  if(nr[i]=='z') nz = rp;
  if(nr[i]=='u') nu = rp; 
  i++; rp = 0;
  while(i<strlen(nr) && isdigit(nr[i])) { rp = rp * 10 + nr[i] - 48; i++;}
  if(nr[i]=='s') ns = rp; 
  if(nr[i]=='z') nz = rp;
  if(nr[i]=='u') nu = rp; 
  i++; rp = 0;
  while(i<strlen(nr) && isdigit(nr[i])) { rp = rp * 10 + nr[i] - 48; i++;}
  if(nr[i]=='z') nz = rp;
  if(nr[i]=='u') nu = rp; 
  i++; rp = 0;
  while(i<strlen(nr) && isdigit(nr[i])) { rp = rp * 10 + nr[i] - 48; i++;}
  if(nr[i]=='u') nu = rp;
  return nm * 1000 + ns * 100 + nz * 10 + nu;
}

//calculeaza valoarea expresiei reprezentate de parametrul sir
long suma(char *sir)
{ 
  int i = 0, j;
  long rez = 0;
  char *termen = new char[Max];
  while(i<strlen(sir))
  {
    j = 1;
    while('+'!=sir[i+j-1] && i+j-1<strlen(sir)) j++;
    strncpy(termen, sir+i,j-1);
    termen[j-1] = '\0';
    rez += transforma(termen);                    
    strcpy(termen,"");
    i = i + j ;
  }      
  return rez;
}



int rezolva(char *linie)
{
  int i,j;
  char *sleft, *sright, semn;
  long stanga, dreapta;
  sleft  = new char[Max];
  sright = new char[Max];
  //separ cele doua parti ale inegalitatii
  //memorand si operatorul de comparare
  if(strchr(linie,'<'))
  {
    sright = strchr(linie,'<') + 1;
    strncpy(sleft, linie, sright - 1 - linie);
    sleft[sright - 1 - linie] = '\0';
    semn = '<';
  }
   else
  {
    sright = strchr(linie,'>') + 1;
    strncpy(sleft, linie, sright - 1 - linie);
    sleft[sright - 1 - linie] = '\0';
    semn = '>';
  }
  stanga  = suma(sleft);   //calculez valoarea expresiei din stanga inegalitatii
  dreapta = suma(sright);  //calculez valoarea expresiei din dreapta inegalitatii
  //returnez 0 sau 1, in functie de valorile obtinute si de operatorul memorat
  return ( semn=='<' ? stanga < dreapta : stanga > dreapta);
}

int main()
{
  char linie[Max];        
  int N;
  int i;
  ifstream f(Fin);
  ofstream g(Fou);
  f>>N; f.get();
  for(i=1;i<=N;i++)
  {
     f.get(linie,Max-1);            //citesc o linie din fisier
     f.get();                       //"sar" peste caracterul de sfarsit de linie
     g<<rezolva(linie)<<'\n';       //determin si afisez rezultatul     
  } 
  f.close();
  g.close();
  return 0;   
}
