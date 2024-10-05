/*
	Sursa 100 p
	prof. Adriana Simulescu
	Liceul Teoretic GRIGORE MOISIL Timisoara
*/
#include<fstream>
#include<iostream>
#include<string.h>

using namespace std;
ifstream in("charlie.in");
ofstream out("charlie.out");
int n,p,suma;
char s[100001],s1[1000001];
int main()
{ int i,L=0,l,j=0;
    in>>p; in.get();
    in>>s;

   if(p==1)
   {
    i=1;
    while (s[i-1]<=s[i]&&s[i]) i++;
    l=2;
    n=strlen(s);
    for(++i;i<n;i++)
        if((s[i]-s[i-1])*(s[i-1]-s[i-2])<0)
                 {l++; if(s[i]>s[i-1]) if(l>L) L=l;}
        else { while (s[i-1]<=s[i]&&s[i]) i++;
                l=2;
              }

 out<<L<<endl;
  }
  else{
        i=2;
        s1[0]=s[0];
        s1[1]=s[1]; j=1;
        while(s[i])
        {
            while(j>=1&&s1[j]<s1[j-1]&&s1[j]<s[i])
                {
                    suma+=(max(s1[j-1],s[i])-'a'+1);
                    j--;
                }
            j++;
            s1[j]=s[i];
          //  s1[j+1]=0;
           // out<<s1<<endl;
            i++;
        }
        s1[j+1]=0;
        out<<s1<<endl<<suma<<endl;

        }

}
