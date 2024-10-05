//serban marinel decembrie 2014
//cu 2 vectori O(2n)
#include <fstream>

using namespace std;

#define DIM 1000001

ifstream fin("ordine.in");
ofstream fout("ordine.out");

int a[DIM], b[DIM];
int n, i, j, tip;

int main()
{
   //citire date de intrare
   fin >> n;
   for (i = 1; i <= n; ++i) fin >> a[i];
   fin >> tip;
   if (tip == 2)   //rezolv cerinta 2
   {
      //refac sirul de mutari in b
      i = 1; j = 1;
      while (i <= n)
      {
         b[i] = a[j];
         i += 2; j++;
      }
      i = 2;
      while (i <= n)
      {
         b[i] = a[j];
         i += 2; j++;
      }
      //afisez rezultatul
      for (i = 1; i <= n; ++i) fout << b[i] << ' ';
   }
   else   //rezolv cerinta 1
      if (n % 2 == 1)         //numar impar de bile
         fout << a[n / 2 + 1];//e bila de la mijloc
      else                    //numar par de bile
         fout << a[n];        //e ultima bila
   fout << '\n';
   return 0;
}
