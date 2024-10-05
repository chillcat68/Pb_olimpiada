#include <cstdio>
#include <algorithm>
#include <cassert>
#define MRD 99999999


using namespace std;
int K, N, A, B, N1, N2, Nr, P, first1, first2, cuart1, cuart2, Max, i, Sum, t, p, x,X, cx, d, u, nr;
bool ok;
int main()
{
    freopen("cuart.in", "r",stdin);
    freopen("cuart.out","w",stdout);
    scanf("%d\n%d",&P, &N);
    assert(N<=1000 && N>=1 && P>0 && P<4);
    first1=cuart1=0;
    for(int i=1; i<=N; i++){
        scanf("%d",&X);
        assert(X<100000000 && X>0);
        p=1; x=0; cx=X;
        while(cx){
            if(cx%2) {x=x + cx%10 *p; p*=10;}
            cx/=10;
        }
        if(x){
            if(!first1) first1=x;
            Sum=0; t=1;
            while (Sum + t <= x){
             Sum+=t;
             t+=4;
            }
            if(Sum==x) cuart1++;
        }
        else Max=max(X, Max);
    }
    first2=cuart2=0;
    for(int i=1; i<=N; i++){
        scanf("%d",&X);
        assert(X<100000000 && X>0);
        p=1; x=0; cx=X;
        while(cx){
            if(cx%2==0) {x=x + cx%10 *p; p*=10;}
            cx/=10;
        }
        if(x){
            if(!first2) first2=x;
            Sum=0; t=1;
            while (Sum + t <= x){
             Sum+=t;
             t+=4;
            }
            if(Sum==x) cuart2++;
        }
        else Max=max(X, Max);
    }
    if(P==1)printf("%d\n", Max);
    else{
     if(cuart1>cuart2) {if (P==2) printf("1\n"); else printf("%d\n",cuart1);}
    else
      if(cuart1<cuart2) {if (P==2) printf("2\n"); else printf("%d\n", cuart2);}
      else
        if(first1==0 && first2 ==0)
             {if (P==2) printf("0\n"); else printf("%d\n", 0);}
      else
        if (first1>first2)
            {if (P==2) printf("1\n"); else printf("%d\n",first1);}
        else
            {if (P==2) printf("2\n"); else printf("%d\n",first2);}
      }
      return 0;
}
