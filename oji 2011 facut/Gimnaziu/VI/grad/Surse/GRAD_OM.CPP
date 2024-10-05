#include<fstream.h>
#include<stdlib.h>
int a[10005],n,k,i;
ifstream f("grad.in");
ofstream g("grad.out");
int mic[10005],max,poz;

void citire()
{ f>>n>>k;
  for(i=1;i<=n;i++)
    f>>a[i];
}

void mai_mici_egale(int p,int q)
{ int i,j;
  for(i=p;i<=q;i++)
    for(j=p;j<=q;j++)
     if(a[i]<=a[j])
       mic[j]++;

}
int grad(int p,int q)
{ int nr=0;
  for(i=p;i<=q;i++)
    if(i-p+1==mic[i]) nr++;
return nr;
}
void golire()
{ for (int i=1;i<=n;i++)   mic[i]=0;
}
void o_solutie()
{ int val1,val2;
   int p,q;
   int i,j;
  mai_mici_egale(1,n);
  g<<grad(1,n)<<endl;

  golire();
   mai_mici_egale(1,k);
   max=grad(1,k);
   poz=1;

  for(i=2;i<=n-k+1;i++)
   {p=i;
    q=i+k-1;  //secventa noua a[p..q] de lungime k
    val1=a[p-1]; //elementul pierdut din secventa
    val2=a[q]; //elementul nou din secventa
    mic[q]=1;
   for(j=p;j<=q-1;j++)
    {
    if(val1<=a[j]) mic[j]--;
    if(val2<a[j]) mic[j]++;
    else mic[q]++;
    }
   int gr=grad(p,q);

   if(gr>max)
     {max=gr;
      poz=p;
     }
  }
}

int main()
{ citire();
  o_solutie();
  g<<poz<<" "<<max;
  g.close();
return 0;
}

