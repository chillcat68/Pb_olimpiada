//PANAETE ADRIAN
//100 p pe evaluatorul lui Alin
//Algoritm: Parsarea expresiilor prin recursivitate inversa
#include<stdio.h>
#include<ctype.h>
int n,cnt,x[1001],comp(),member(),number(),digit();
char L[300],*p;
int main()
{
	freopen("comp.in","r",stdin);
	freopen("comp.out","w",stdout);
	scanf("%ld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",L);p=L;
		x[i]=comp();
	}
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)printf("%d\n",x[i]);
	return 0;
}
int comp()
{
	//evalueaza intreaga expresie
	//cursorul p este la inceputul expresiei
	int left,right;
	char op;
	
	//evalueaza membrul I
	left=member();
	
	//cursorul p ajunge pe semnul de inegalitate
	op=*p;
	
	//daca semnul este < se contorizeaza
	if(op=='<')cnt++;
	
	//avanseaza cursorul la inceputul membrului II
	p++;
	
	//evalueaza membrul II
	right=member();
	
	//decide daca inegalitatea este corecta si returneaza 1/0 pentru adevarat/fals
	if(op=='<'&&(left<right))return 1;
	if(op=='>'&&(left>right))return 1;
	return 0;
}
int member()
{
	//evalueaza un membru de inegalitate
	//cursorul p este pozitionat la inceputul membrului
	
	//initializeaza valoarea membrului cu valoarea termen din membru
	//la final cursorul va fi in spatele termenului
	int ret=number();
	while(*p=='+')
	{
		//cat timp intalnim semnul + membrul mai contine termeni
		
		//avanseaza cursorul pe urmatorul termen
		p++;
		
		//evalueaza termenul si il adauga la rezultat
		ret+=number();
	}
	
	//returneaza rezultatul membrului curent
	return ret;
}
int number()
{
	//evalueaza un numar eudorian 
	//cursorul este pozitionat la inceputul numarului
	//la final el va fi in spatele numarului
	
	//initializeaza valoarea cu valoarea primei cifre eudoriene
	//la final cursorul va fi in spatele cifrei
	int ret=digit();
	
	//cat timp cursorul ajunge pe caracter cifra 
	//numarul mai contine cifre eudoriene
	//deci se adauga cifra la valoarea numarului
	while(isdigit(*p))
		ret+=digit();
	
	//returneaza valoare numar
	return ret;
}
int digit()
{
	//evalueaza o cifra eudoriana
	//se parseaza numarul pana intalnim u,z,s sau m
	int ret=0;
	while(isdigit(*p)){ret*=10;ret+=*p-'0';p++;};
	
	//in functie de codul cifrei eudoriene se multiplica rezultatul cu 1,10,100 sau 1000 
	//si returneaza valoarea
	if(*p=='u'){p++;return ret;}
	if(*p=='z'){p++;return 10*ret;}
	if(*p=='s'){p++;return 100*ret;}
	p++;return 1000*ret;
}

