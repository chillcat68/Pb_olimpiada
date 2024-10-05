#include <stdio.h>
#include <conio.h>
#include <iostream.h>

int m,p,nl,nc,nr;
int n;
char a[230][230];
FILE *f,*g;


void citire()
{                                      //citire date
  f=fopen("colaj.in","r");
  fscanf(f,"%d%d%d",&n,&m,&p);
  nl=p-1;
  nc=m-1;
  int i,j;
  for(i=0;i<=nl;i++)
    for(j=0;j<=nc;j++)
     a[i][j]=0;
  int xa,ya,xb,yb,l,c;
  for(i=1;i<=n;i++)
  { fscanf(f,"%d%d%d%d",&xa,&ya,&xb,&yb);
    for(l=ya;l<yb;l++)
      for(c=xa;c<xb;c++)
	a[l][c]=1;
   }
fclose(f);
}

void fill(int i,int j)
{
     a[i][j]=1;
     if((j>0)&&(a[i][j-1]==0))fill(i,j-1);
     if((j<nc)&&(a[i][j+1]==0))fill(i,j+1);
     if((i>0)&&(a[i-1][j]==0))fill(i-1,j);
     if((i<nl)&&(a[i+1][j]==0))fill(i+1,j);

}

void supr()
{ int i,j;
  for(i=0;i<=nl;i++)
    for(j=0;j<=nc;j++)
     if(a[i][j]==0){nr++;fill(i,j);}
}


void main()
{ citire();
  supr();
  g=fopen("colaj.out","w");
  fprintf(g,"%d",nr);
  fclose(g);
}




