#include <iostream>
#include<fstream>
#include<cmath>

using namespace std;
ifstream f("dominant.in");
ofstream g("dominant.out");
  int a[300001],b[300001],v,n;
  void afis(int a[],int n)
  {   int i;
       for(i=1;i<=n;i++)
        cout<<a[i]<<' ';
        cout<<endl;
  }

int V;

int main()
{ int i=1,ii,ok,k;
    char x,y;
    f >> V;
    f>>x;
    if(x=='0') x=-1;
    else x=1;
    a[1]=a[1]+x;
    while(f>>y)
    {   if(y=='0')y=-1;
    else y=1;
        if(x!=y)
        { b[i]=abs(a[i]);
        i++;
        }
            a[i]=a[i]+y;
         x=y;
    }
    b[i]=abs(a[i]);
     n=i;
  //   afis(a,n);afis(b,n);
     if(a[1]>0) ii=1;
     else ii=2;
     do{
            ok=0;
      k=ii-1;
     for(i=ii;i<n+1&&a[i+1]<0;)
        if(a[i]+a[i+1]+a[i+2]>0)
       {
           a[++k]=a[i]+a[i+1]+a[i+2];
           b[k]=b[i]+b[i+1]+b[i+2];
           a[++k]=a[i+3];b[k]=b[i+3];
           i=i+4;ok=1;
       }
     else
        {a[++k]=a[i],b[k]=b[i];
        a[++k]=a[i+1],b[k]=b[i+1];
        i=i+2;
        }
        if(i==n) a[++k]=a[n],b[k]=b[n];
        n=k;a[n+1]=a[n+2]=0;
        while(a[n]==0)n--;
  //      afis(a,n);afis(b,n);
     }
     while(ok);
//       afis(a,n);afis(b,n);
    for(i=ii;i<n+1;i=i+2)
    b[i]=b[i]+a[i]-1;

// afis(a,n);afis(b,n);
  int max=0,na=0;
   for(i=ii;i<n+1;i=i+2)
    if(b[i]>max)max=b[i];
    if (V == 1) {
        g<<max<<endl;
        return 0;
    }

   {
          if(b[1]==max) na++,ii=ii+2;
           if(b[n]==max) na++,n=n-2;
  for(i=ii;i<n;i=i+2)
     if(b[i]==max) na=na+a[i];

        g<<na;
   }
    return 0;
}
