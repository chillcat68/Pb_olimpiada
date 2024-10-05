/*
	Sursa 38p - idee asemanatoare bouble-sort
	prof. Radu Visinescu, Ploiesti
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("charlie.in");
ofstream fout("charlie.out");

long long v,p,i,m=0;
long long p2,p3,u,save_p,save_u,d,dmax,ok;
char st[1000000];
char t[1000000];
char s[1000000];
int main()
{
 fin>>p;fin>>s;
 if (p==2){
           do{ok=0;
                i=0;    while(i<=strlen(s)-3)
             if ((s[i]>s[i+1])&&(s[i+1]<s[i+2]))
	              {
	                  m=(int)(s[i])-(int)('a')+1;
                      if (m<(int)(s[i+2])-(int)('a')+1)
                         m=(int)(s[i+2])-(int)('a')+1;
                      strcpy(t,s+i+2);
                      strcpy(s+i+1,t);
                      v += m; ok=1;
	              }
             else i++;
             }while(ok);
            fout<<s<<'\n';
            fout<<v<<'\n';
}
else {dmax=1;save_p=0;save_u=0;
     p2=0;u=0;
     d=1;
     i=0;
     while (i<=strlen(s)-3)
      if ((s[i]>s[i+1]) && (s[i+1]<s[i+2]))
       {
           u=i+2;i=i+2;
           d=u-p2+1;
           if (dmax<d) {save_p=p2;save_u=u;dmax=save_u-save_p+1; }
       }
      else { i=i+2;p2=i;u=i;}
      p2=1;u=1;
      d=1;
      i=1;
     while (i<=strlen(s)-3)
      if ((s[i]>s[i+1]) && (s[i+1]<s[i+2]))
       {
           u=i+2;i=i+2;
           d=u-p2+1;
           if (dmax<d) {save_p=p2;save_u=u;dmax=save_u-save_p+1; }
       }
      else { i=i+2;p2=i;u=i;}
     fout<<save_u-save_p+1<<'\n';
}
fin.close();
fout.close();
    return 0;
}
