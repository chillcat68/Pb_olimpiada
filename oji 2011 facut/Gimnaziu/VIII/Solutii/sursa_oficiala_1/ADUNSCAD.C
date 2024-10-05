//serban marinel - februarie 2011
//100 puncte
//algoritm de tip succesor pentru generarea combinatiilor de semne
//adunare in baza 2
#include <stdio.h>

FILE * Fin, *Fout;

int N, M, gasit;
int cifre[31], comb[31];

void afiseaza(int care)
{
  int i;
  gasit = 1;
  if (care == 1 || care == 3)
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
  else
    {
      fprintf(Fout, "-");
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
      Sum -= cifre[i];
    else
      Sum += cifre[i];
  for (i = 1; i <= M; i++)
    if (comb[i])
      Sum_ += cifre[i];
    else
      Sum_ -= cifre[i];

  if (Sum == N && Sum_ == N) return 3;
  if (Sum == N) return 1;
  if (Sum_ == N) return 2;
  return 0;
}

int main(void)
{
  int i, care;

  Fin = fopen("adunscad.in", "r");
  Fout = fopen("adunscad.out", "w");

  fscanf(Fin, "%d %d\n", &N, &M);     //citesc N si M
  for (i = 1; i <= M; i++)            //citesc cifrele din sir
    fscanf(Fin, "%d", &cifre[i]);
  fclose(Fin);

  for (i = 0; i < 31; i++) comb[i] = 0;
  gasit = 0;
  while (!gasit && !comb[1])          //cand comb[1] este 1 am terminat
    {
      care = OK();  //verific expresia
      if (care)     //este OK
	{
	  afiseaza(care);  //afisez
	  break;           //opresc ciclul
	}
      i = M;                          //adun 1 in baza 2
      while (comb[i]) comb[i--] = 0;  //caut primul 0
      comb[i] = 1;                    //il fac 1
    }
  if (comb[1]) fprintf(Fout, "0\n");

  fclose(Fout);
  return 0;
}
