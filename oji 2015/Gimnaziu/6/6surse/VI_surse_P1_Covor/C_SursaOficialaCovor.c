#include <stdio.h>
FILE *f,*g;

int n,k,r,p,m,c;
int main()
{ f=fopen("covor.in","r");
  g=fopen("covor.out","w");
  fscanf(f,"%d%d%d",&n,&k,&c);
  r=1;
  while(2*(r+1)*(r+2)-r<=n) r++;
  if(c==1)
       fprintf(g,"%d\n",r);
  else
  {
  if(k> 2*r*(r+1)-(r-1))fprintf(g,"0\n");
   else
     { p=1;
       m=1+r*(r+1);
       if(k<=m) { while(k>1+p*(p+1))p++;
                  fprintf(g,"%d\n",p);
                }
         else
         { p=r;
           while(k>(m+2*p-1))
                  { m=m+2*p-1;
                    p--;
                  }
           fprintf(g,"%d\n",p);
         }
     }
  }
    close(f);
    close(g);
    return 0;
}
