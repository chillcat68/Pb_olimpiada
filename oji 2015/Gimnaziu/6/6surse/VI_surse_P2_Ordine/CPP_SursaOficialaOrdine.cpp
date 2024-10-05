//serban marinel decembrie 2014
//cu 1 vector - direct din citire O(n)
#include <fstream>

using namespace std;

#define DIM 1000001

ifstream fin("ordine.in");
ofstream fout("ordine.out");

int b[DIM];
int n, i, j, tip;

int main()
{
   //citire date de intrare
   fin >> n;
   j = 1;
   for (i = 1; i <= n; ++i)
   {
      fin >> b[j];
      j += 2;
      if (j > n) j = 2;
   }
   fin >> tip;
   if (tip == 2)   //rezolv cerinta 2
      //afisez rezultatul
      for (i = 1; i <= n; ++i) fout << b[i] << ' ';
   else   //rezolv cerinta 1
      fout << b[n];        //e ultima bila
   fout << '\n';
   return 0;
}
