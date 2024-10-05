//AUTOR SURSA: Panaete Adrian
//COMPILAT: Borland
//PUNCTAJ: 100 puncte
//ALGORITM: Divide et impera
#include<stdio.h>
long v,n,x[25],p[25],VF[185],CF[185],*init();
void read(),solve(),dei(long,long,long*,long*);
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("adunscad.in","r",stdin);
	freopen("adunscad.out","w",stdout);
	scanf("%ld%ld",&v,&n);//citesc valoarea solicitata si nr de cifre
	for(int i=0;i<n;i++)scanf("%ld",&x[i]);//citesc cifrele
}
void solve()
{
	p[0]=1;for(int i=1;i<=20;i++)p[i]=2*p[i-1];
	//GENEREZ PUTERILE LUI 2 pentru a simula operatiile pe biti
	
	dei(0,n-1,VF,CF);
	//Apelul principal DIVIDE ET IMPERA pe intreaga secventa de cifre
	
	if(v<0){v=-v;CF[v]=p[n]-CF[v]-1;}
	//daca valoarea este negativa schimb codul de semne in negatul sau pe biti
	//pentru a schimba fiecare semn al fiecarei cifre
	
	
	if(!VF[v]){printf("0\n");return;}
	//daca valoarea nu este generata nu am solutia
	
	(CF[v]%2)?printf("-%ld",x[0]):printf("%ld",x[0]);CF[v]/=2;
	//AFISAREA PRIMEI CIFRE
	
	for(i=1;i<n;i++)
	{
		(CF[v]%2)?printf("-%ld",x[i]):printf("+%ld",x[i]);
		CF[v]/=2;
	}
	printf("\n");
}
void dei(long st,long dr,long *V,long *C)
{
	//st=indicele stanga al secventei de cifre
	//dr=indicele drepata al secventei de cifre
	//deci o secvanta de L=dr-st+1 cifre
	
	//V[] initializat cu 0 
	//vector de lungime utila de la 0 la 9*L (daca toate cifrele ar fi 9)
	//V[y]=1 daca valoarea y>=0 se genereaza cu cifrele secventei
	
	//C[y]=numar binar cu L biti
	//daca V[y]=1 cei L biti marcheaza de la st la dr 
	//semnul utilizat de cele L cifre bit=1=>semn='-' bit=0=>semn='+'
	long *VS,*CS,*VD,*CD;//vectori analogi cu V , C pentru subsecventele stanga / dreapta
	long L,LS,LD,i,j;
	//L=nr total cifre 
	//LS=nr cifre in prima jumatate ( in subsecventa stanga)
	//LD=nr cifre in a doua jumatate (in subsecventa dreapta)
	if(st==dr)
	{
		V[x[st]]=1;C[x[st]]=0;
		//daca secventa are o singura cifra atunci 
		//singura valoare generata
		//codul este 0 adica cifra e luata cu +
		return;
	}
	
	L=dr-st+1;
	LS=(L+1)/2;VS=init();CS=init();//pregatesc apelul pe prima subsecventa
	LD=L-LS;VD=init();CD=init();//pregatesc apelul pe a doua subsecventa
	
	//DIVIDE apel pe cele doua subsecvente
	//fiecare va returna valorile generate precum si codurile cu care se genereaza
	dei(st,(st+dr)/2,VS,CS);
	dei((st+dr)/2+1,dr,VD,CD);
	
	//IMPERA Se parcurg toate valorile posibile care pot fi generate in stanga si in dreapta
	//OBS pe cele doua subsecvente valoarea maxima generata este de 9 ori lungimea secventei
	for(i=0;i<=9*LS;i++)
		if(VS[i])//DACA VALOAREA i SE OBTINE IN STANGA
		for(j=0;j<=9*LD;j++)
			if(VD[j])//DACA VALOAREA j SE OBTINE IN DREAPTA
			{
				V[i+j]=1;
				//VALOAREA i+j>=0 SE OBTINE PE SECVENTA
				C[i+j]=(CD[j]*p[LS])+CS[i];
				//CODUL SE OBTINE CONCATENAND CODURILE CU CARE S-AU OBTINUT i si j
				if(i>=j)
				{//DACA VALOAREA STANGA > VALOAREA DREAPTA
					V[i-j]=1;//DIFERENTA i-j SE OBTINE PE SECVENTA
					C[i-j]=(p[LD]-CD[j]-1)*p[LS]+CS[i];
					//CODUL DREAPTA VA FI NEGAT DEOARECE j SE SCADE
					//DECI TOATE SEMNELE VOR FI SCHIMBATE
				}
				else
				{//ANALOG DACA VALOAREA DREAPTA > VALOAREA STANGA
					V[j-i]=1;
					C[j-i]=(CD[j]*p[LS])+(p[LS]-CS[i]-1);
					//DAR VOM NEGA CODUL STANGA
				}
			}
	//ELIBEREZ MEMORIA PE VECTORII TEMPORAR UTILIZAT PENTRU A GENERA VALORILE
	//PE SUBSEVCENTE
	delete VS;delete VD;
	delete CS;delete CD;
	
}
long *init()
{
	//initializeaza cu 0 un vector temporar alocat dinamic cu zona utila 0-180
	long *VECT;
	VECT=new long[185];
	for(long i=0;i<=182;i++)VECT[i]=0;
	return VECT;
}
