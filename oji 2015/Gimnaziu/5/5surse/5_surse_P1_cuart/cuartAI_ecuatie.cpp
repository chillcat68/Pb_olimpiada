#include <fstream>
#include <math.h>
using namespace std;
ifstream f("cuart.in");
ofstream g("cuart.out");

int P,N,m1,m2,maxo,A,B,C,M,q1,q2,primul1,primul2,k,i,x,q,p,nr1,nr2;

int main()
{
    //citire-prelucrare
    f>>P>>N;

    //Gina
    for(i=1;i<=N;i++)
    {
        f>>A;x=A;p=1;q=0;
        while(x>0){if(x%2==1){q+=p*(x%10);p*=10;}x/=10;}
        if(q==0){if(A>maxo)maxo=A;}
        else{
                nr1++;
                if(primul1==0)primul1=q;
                //1+5+9+...+(4M+1)=(M+1)(2M+1)
                M=(-3+sqrt(1+8*q))/4;
                //k=M*4+1;
                if(q==(M+1)*(2*M+1))q1++;
             }
    }

    //Mihai
    for(i=1;i<=N;i++)
    {
        f>>A;x=A;p=1;q=0;
        while(x>0){if(x%2==0){q+=p*(x%10);p*=10;}x/=10;}
        if(q==0){if(A>maxo)maxo=A;}
        else {
                nr2++;
                if(primul2==0)primul2=q;
                M=(-3+sqrt(1+8*q))/4;
                //k=M*4+1;
                if(q==(M+1)*(2*M+1))q2++;
             }
    }

    //afisare a)
    if(P==1)g<<maxo<<'\n';
    //afisare b) si c)
    if(q1<q2) B=2,C=q2;
    else if(q1>q2) B=1,C=q1;
         else if(primul1>primul2)B=1,C=primul1;
              else if(primul1<primul2)B=2,C=primul2;
                   else B=C=0;
    if(P==2)g<<B<<'\n';
    if(P==3)g<<C<<'\n';
    f.close();g.close();return 0;
}
