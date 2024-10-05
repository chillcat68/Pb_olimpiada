//dana lica - 100 p
//algoritm de tip backtracking nerecursiv

#include <stdio.h>


int c[25],sol[25], ok, N;
long M, nr, ns, i, k;

void afis(){

 int i,s1=0,s2=0;

 nr++;
 for (i=1;i<=M; i++)
	if (sol[i]==1) {s1+=c[i]; s2-=c[i];}
	else {s2+=c[i]; s1-=c[i];}

 if (s1==N) {
	for (i=1;i<=M;i++)
	   if (sol[i]==1) if (i>1) printf("+%d" ,c[i]); else printf("%d", c[i]);
	   else printf("-%d",c[i]);
	printf("\n");
	ok=1;
	return;
 }

 if (s2==N) {
	for (i=1;i<=M;i++)
	   if (sol[i]==1) printf("-%d" ,c[i]);
	   else if (i>1) printf("+%d" ,c[i]); else printf("%d", c[i]);
	printf("\n");
	ok=1;
	return;
 }
 return;
}


void main()
{

 freopen("adunscad.in","r",stdin);
 freopen("adunscad.out","w",stdout);
 scanf("%d%d", &N, &M);
 for (i=1;i<=M; i++) scanf("%d",&c[i]);
 k=1; ns=(long)1<<(M-1);
 while (k && !ok && nr<ns)
	 if (sol[k]<2){
	   sol[k]++;
	   if(k==M) afis();
	   else {
		 k++;
		 sol[k]=0;
	   }

	 }
	 else k--;

 if (!ok) printf("0\n");
 fclose(stdout);
}
