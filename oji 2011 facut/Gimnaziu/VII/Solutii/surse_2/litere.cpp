//O(N)
#include <stdio.h>
#include <string.h>

char S[30002];
char c;
char *voc = "AEIOU";
long int a, N, C, k, j, i, T, aux;
char P[130], cod[130];
long int L[30];

int main() {
	FILE *f = fopen("litere.in","r");
	FILE *g = fopen("litere.out","w");
	fscanf(f,"%d",&N);
	fscanf(f,"%s",S+1);
	
	a = 0;
	k = 0;
	for (i=1;i<N;i++) {
		if ((strchr(voc, S[i]) && !strchr(voc, S[i+1])) || 
			(!strchr(voc, S[i]) && strchr(voc, S[i+1]))) {
			a++;
		}
		if (!P[S[i]])
			P[S[i]] = ++k;
	}
	if (!P[S[N]])
		P[S[N]] = ++k;
	fprintf(g,"%d\n",a);
	fscanf(f,"%d",&C);
	
	for (i=1;i<=C;i++) {
		fscanf (f,"%d",&L[i]);
	}
	
	for (i=1;i<=N;i++)
		S[i] = L[P[S[i]]];
	
	for (i=1;i<=N;i++) {
		fprintf(g,"%c",S[i] + '0');
	}
	
	for (i=1,j=N;i<=j;i++,j--) {
		c = S[i];
		S[i] = S[j];
		S[j] = c;
	}
	
	for (i=1, T = 0;i<=N;i++) {
		aux = S[i] * (N-i+1) + T;
		S[i] = aux%10;
		T = aux/10;
	}
	
	while (T) {
		S[++N] = T%10;
		T/=10;
	}
	
	fprintf(g,"\n");
	
	for (i=N;i>=1;i--) {
		fprintf(g,"%c",S[i] + '0');
	}
	
	fclose(f);
	fclose(g);
	return 0;
}