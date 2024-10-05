//serban marinel - februarie 2011
//100 puncte
//adunare in baza 2 - genereaza TOATE combinatiile
#include <stdio.h>

FILE * Fin, *Fout;

int N, M, gasit;
int cifre[31], comb[31];

void afiseaza(void)
{
  int i;
  gasit = 1;
  if (comb[1]) fprintf(Fout, "-");
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

int OK(void)
{
  int i, Sum = 0;

  for (i = 1; i <= M; i++)
    if (comb[i])
      Sum -= cifre[i];
    else
      Sum += cifre[i];
  return (Sum == N);
}

int main(void)
{
  int i;

  Fin = fopen("adunscad.in", "r");
  Fout = fopen("adunscad.out", "w");

  fscanf(Fin, "%d %d\n", &N, &M);     //citesc N si M
  for (i = 1; i <= M; i++)            //citesc cifrele din sir
    fscanf(Fin, "%d", &cifre[i]);
  fclose(Fin);

  gasit = 0;
  while (!gasit && !comb[0])
    {
      if (OK())
	{
	  afiseaza();
	  break;
	}
      i = M;
      while (comb[i]) comb[i--] = 0;
      comb[i] = 1;
    }
  if (comb[0]) fprintf(Fout, "0\n");

  fclose(Fout);
  return 0;
}
