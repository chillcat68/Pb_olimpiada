#include <fstream>
using namespace std;
ifstream fin("speciale.in");
ofstream fout("speciale.out");
int main()
{
   unsigned P,N,K,A,B,x,special,i,p,NN,Ncif;
   x=special=Ncif=0;
   fin>>P>>K>>N>>A>>B; NN=N;
   if(P==1)
   {
       for(i=9;i>=10-K;i--) fout<<i;
        fout<<'\n';
        return 0;
   }
   if(P==2)
   {
       ///cerinta 2
       while(NN)
       { NN/=10;special=special*10+Ncif;Ncif++;}
       if(N%10==Ncif-1||N/10%10==Ncif-1)///verific daca N este de forma 1234...
       {
           NN=N;i=Ncif-1;p=1;
           while(NN)
           {
               if(NN%10!=i)
                {
                    if(N/(p*10)*p+N%p==special) x=special;
                    break;
                }
               else {i--;p*=10;NN/=10;}
           }
           if(NN==0)x=special;
       }
       if(x==0&&(N%10==11-Ncif||N/10%10==11-Ncif))///verific daca N este de forma 987...
       {
           NN=N;i=11-Ncif;p=1;
           while(NN)
           {
               if(NN%10!=i)
                {
                    if(N/(p*10)*p+N%p==special*8+Ncif-1) x=special*8+Ncif-1;
                    break;
                }
               else {i++;p*=10;NN/=10;}
           }
           if(NN==0)x=special*8+Ncif-1;
       }
       fout<<x<<'\n';
       return 0;
   }
   if(P==3)
   {

       ///cerinta 3
       for(x=special=0,i=1;special<=B;i++)
       {
           special=special*10+i;
           if(special>=A&&special<=B) x++;
           if(special*8+i>=A&&special*8+i<=B) x++;
       }
       fout<<x<<'\n';
       return 0;
   }
   return 0;
}
