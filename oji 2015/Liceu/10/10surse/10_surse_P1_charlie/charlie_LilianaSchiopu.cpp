//prof. Liliana Schiopu - CNFB-Craiova
//100p
//complexitate O(n)

#include <cstdio>
using namespace std;
FILE *f=fopen("charlie.in","r");
FILE *g=fopen("charlie.out","w");
char a[100003],st[100003];
int i,j,n,p,c,lc,lmax,ok;
int Max(char a,char b,char c)
{
    if(a>=b&&a>=c)
      return int(a)-96;
    else
    if(b>=a&&b>=c)
      return int(b)-96;
    else
    if(c>=b&&c>=a)
      return int(c)-96;
}
int main()
{
    fscanf(f,"%d",&p);
  if(p==1)
  {
       while((c = fgetc(f)) != EOF)
       {
        if (c <= 'z'&&c>='a') {
            n++;
            a[n]=c;
        }
       }
      lmax=0;
      for(i=1;i<=n;i++)
      {
          lc=0;
          ok=1;
          j=i+1;
          while(j<n&&ok)
            {if(a[j-1]>a[j]&&a[j]<a[j+1])
              {lc+=2;j+=2;}
             else {ok=0;}
            }
          if(lc>0) {lc++;i=j-1;}
          if(lc>lmax)
            lmax=lc;
      }
     fprintf(g,"%d",lmax);
  }
  else
  if(p==2)
  {  lmax=0;
     while((c = fgetc(f)) != EOF)
       {
        if (c <= 'z'&&c>='a') {
            n++;
            st[n]=c;
         do{ ok=0;
            if(n>2&&st[n-1]<st[n-2]&&st[n-1]<st[n])
            {
                ok=1;
                lmax+=Max(st[n-2],st[n-1],st[n]);
                st[n-1]=st[n];
                n--;
            }
         }while(ok==1);
        }
       }
       for(i=1;i<=n;i++)
         fprintf(g,"%c",st[i]);
       fprintf(g,"\n%d",lmax);
  }
   return 0;
}
