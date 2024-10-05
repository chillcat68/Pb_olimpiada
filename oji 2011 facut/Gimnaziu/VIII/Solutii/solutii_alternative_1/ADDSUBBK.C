//serban marinel - februarie 2011
//solutie de tip backtracking pentru generarea combinatiilor de semne
//100 puncte
#include <stdio.h>
#include <stdlib.h>

FILE * Fin, *Fout;

int N, M, gasit = 0;
int cifre[31], comb[31];

void afiseaza(int care)
{
  int i;
  gasit = 1;                     //marchez ca am gasit o solutie
  if (care == 1 || care == 3)    //primul semn este '+' NU il afisez
    {
      for (i = 1; i < M; i++)
	{
	  fprintf(Fout, "%d", cifre[i]);
	  if (comb[i+1])
	    fprintf(Fout, "-");
	  else
	    fprintf(Fout, "+");
	}
      fprintf(Fout, "%d\n", cifre[M]);
    }
  else                          //primul semn este '-'
    {
      fprintf(Fout, "-");          //il afisez separat
      for (i = 1; i < M; i++)
	{
	  fprintf(Fout, "%d", cifre[i]);
	  if (comb[i+1])
	    fprintf(Fout, "+");
	  else
	    fprintf(Fout, "-");
	}
      fprintf(Fout, "%d\n", cifre[M]);
    }
}

int OK(void)
{
  int i, Sum = 0, Sum_ = 0;

  for (i = 1; i <= M; i++)
    if (comb[i])
      Sum -= cifre[i];     //1 este '-', 0 este '+'
    else
      Sum += cifre[i];
  for (i = 1; i <= M; i++) //invers
    if (comb[i])           //1 este '+', 0 este '-'
      Sum_ += cifre[i];
    else
      Sum_ -= cifre[i];

  if (Sum == N && Sum_ == N) return 3;  //daca sumele sunt egale caz = 3, deci indiferent cum afisez
  if (Sum == N) return 1;               //1 este '-' 
  if (Sum_ == N) return 2;              //1 este '+'
  return 0;                //combinatia NU este buna
}

void back(long k)
{
  int care;
  if (k == M + 1)            //am o combinatie de +/- (0/1)
    {
      care = OK();           //verific daca furnizeaza valoarea N si in ce mod 
      if (care)              //DA, e buna
	{
	  afiseaza(care);       //afiseaza
	  fclose(Fout);         //inchide    
	  exit(0);              //opreste
	}                   //NU, nu e buna - nu fa nimic
    }
  else                      //nu am inca o combinatie de +/- (0/1)
      {
	comb[k] = 0; back(k+1);   //pune pe pozitia curenta 0 (+) si treci mai departe
	comb[k] = 1; back(k+1);   //la revenire pune 1 (-) si treci mai departe
      }
}

unsigned long main(void)
{
  unsigned long i;
  Fin = fopen("adunscad.in", "r");
  Fout = fopen("adunscad.out", "w");

  fscanf(Fin, "%d %d\n", &N, &M);
  for (i = 1; i <= M; i++)
    fscanf(Fin, "%d", &cifre[i]);
  back(2);                        //cand pozitia 1 din vectorul solutie comb devine 1 am terminat
  if (!gasit)                     //nu am gasit nici o combinatie
    fprintf(Fout, "0\n");             //scrie 0
  fclose(Fout);
  return 0;
}
