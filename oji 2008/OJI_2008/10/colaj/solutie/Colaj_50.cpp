#include <stdio.h>

int m,p,nl,nc,nr;
int n;
char a[240][240];
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
int ver_l(int l)
{for(int j=0; j<=nc;j++)
 if(a[l-1][j]!=a[l][j])return 0;
 return 1;
}

void sterg_l(int l)
{ int i,j;
  for(i=l;i<nl;i++)
   for(j=0;j<=nc;j++)
   a[i][j]=a[i+1][j];
  nl--;
}

void linii()
{
 int i=1;
 while(i<=nl)
  { if(ver_l(i)) sterg_l(i);
    else i++;}
 }

int ver_c(int c)
{for(int j=0; j<=nl;j++)
 if(a[j][c-1]!=a[j][c])return 0;
 return 1;
}

void sterg_c(int c)
{ int i,j;
  for(j=c;j<nc;j++)
   for(i=0;i<=nl;i++)
   a[i][j]=a[i][j+1];
  nc--;
}
void coloane()
{int j=1;
 while(j<=nc)
  { if(ver_c(j)) sterg_c(j);
    else j++;}
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
  linii();coloane();
  supr();
  g=fopen("colaj.out","w");
  fprintf(g,"%d",nr);
  //cout<<nr<<' ';
  fclose(g);
}




