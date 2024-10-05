//Genoiu Nicolae
//implementare cu arbori binari
//40 puncte - Borland
//nu merge sub MingW


#include <fstream.h>

const char numei[15]="adunscad.in",
      	  numeo[15]="adunscad.out";

struct nod{
	short nr;
	nod * st,*dr;
	nod * tata;
};

void createnod(nod*&p,int s1){
	p=new(nod);
	p->nr=s1;
	p->st=p->dr=NULL;
}

void inord(nod*&p,int a){
	if(p->st==NULL&&p->dr==NULL){
		createnod(p->st,p->nr+a);p->st->tata=p;
		createnod(p->dr,p->nr-a);p->dr->tata=p;
	}
	else{
		inord(p->st,a);
		inord(p->dr,a);
	}
}

nod * afis(nod*p,int s){
	nod* t = NULL;
	if(p){
		t = afis(p->st,s);
		if(p->st==NULL&&p->dr==NULL&&t==NULL)
			if(p->nr==s)
				return p;
		if(t==NULL)
			t = afis(p->dr,s);
	}
	return t;
}

int main(){
	ifstream f(numei);
	ofstream g(numeo);
	int n,m,i,a,v[21],nr;
	char s[21];
	nod *x;

	f>>n>>m;
	createnod(x,0);
	x->tata=NULL;
	for(i=1;i<=m;i++){
		f>>a ;
		inord(x,a);
		v[i]=a;
	}
	f.close();
	x=afis(x,n);
	if(x==NULL)
		g<<0;
	else{
		i=m;
		while(x->tata!=NULL){
				nr=x->nr;
				x=x->tata;

				if(x->nr+v[i]==nr)
					s[i]='+';
				else
					s[i]='-';
				i--;
		}
		if(x->nr+v[1]==nr)
					s[1]='+';
				else
					s[1]='-';
		if(s[1]=='+')
			g<<' ';
		else
			g<<'-';
		g<<v[1];
		for(i=2;i<=m;i++)
			g<<s[i]<<v[i];
	}
	g.close();
	return 1;
}
