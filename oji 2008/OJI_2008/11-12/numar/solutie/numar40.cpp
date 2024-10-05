//problema numar - stelian ciurea
//avl = 40 puncte
#include<fstream.h>
#include<stdlib.h>
struct nod {int info; int hi;
		nod *st, *dr;
		};
long a[1000],ct,n,m,sol,lim,mult;
int max2(int a, int b)
{ if (a>b) return a; return b;}

int high(nod *p)
{ if (p==NULL) return -1;
	return p->hi;
}

void rotst(nod*&x)
{ nod *y = x->dr;
  x->dr = y->st;
  y->st = x;
  x->hi = 1+max2(high(x->st),high(x->dr));
  y->hi = 1+max2(high(y->st),high(y->dr));
  x = y;
}

void rotdr(nod*&y)
{ nod *x = y->st;
  y->st = x->dr;
  x->dr = y;
  y->hi = 1+max2(high(y->st),high(y->dr));
  x->hi = 1+max2(high(x->st),high(x->dr));
  y = x;
}

void rotdst(nod*&x)
{
 rotdr(x->dr);
 rotst(x);
}

void rotddr(nod*&y)
{
  rotst(y->st);
  rotdr(y);
}

void ins(nod*&p, int vl)
{
  if (p==NULL)
    { p = new nod;
      p->info = vl;
      p->st=p->dr=NULL;
      p->hi = 0;
      return;
    }
  if (p->info == vl) return;
  if (p->info < vl)
  { ins(p->dr,vl);
    if (high(p->dr) - high(p->st) > 1)
       if ( high(p->dr->dr) >= high(p->dr->st) )
	  rotst(p);
	else
	  rotdst(p);
    else
      p->hi = 1 + max2(high(p->st), high(p->dr));

  }
  else
   { ins(p->st,vl);

     if (high(p->st) - high(p->dr) > 1)
       if ( high(p->st->st) >= high(p->st->dr) )
	  rotdr(p);
	else
	  rotddr(p);
    else
      p->hi = 1 + max2(high(p->st), high(p->dr));

  }
}
int ad(nod *p)
{ if (p==NULL) return -1;
  int a1 = ad(p->st);
  int a2 = ad(p->dr);
  return 1 + max2(a1,a2);
}

void inord(nod* p)
{ if (p!=NULL)
   { inord(p->st);
     ct++;
//     cout<<p->info<<' ';
     if (ct==m)
       sol = p->info;
     inord(p->dr);
   }
}

int main()
{ int i;
  nod *root=NULL;
  ifstream f("numar.in");
  ofstream fout("numar.out");
  f>>n>>m;
  for (i=0;i<n;i++)
     f>>a[i];
  lim = a[1]*m;
  for (i=0;i<n;i++)
    { mult = a[i];
      while (mult<=lim)
	{ ins(root,mult);
	  mult += a[i];
	}
    }

  inord(root);
  fout<<sol<<endl;
  fout.close();

  return 0;
}
