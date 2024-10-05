//prof.Carmen Minca - 100 p
#include <fstream>

using namespace std;
ifstream f("vase.in");
ofstream g("vase.out");

long s[100001][2], d[100001][2],ps=-1,pd=-1,x;

int main()
{ long long ns=0, nd=0, fin,i,c,n,echi,dif,ss,sd,es,ed;
  char a;
  f>>n;
  for(i=1;i<=n;i++)
  { f>>c>>a;
    if (a=='S')
		{ ps++;
		  s[ps][1]=c;s[ps][0]=i;
		  ns=ns+c;
		}
	else
		{ pd++;
		  d[pd][1]=c;d[pd][0]=i;
		  nd=nd+c;
		}
  }
  f>>x;  
  echi=(ns+nd)/2;
  es=-1; ss=0;
  for(i=0;i<=ps;i++)
	  if(s[i][0]==x){es=i; break;} 
	  else ss+=s[i][1];
  g<<echi<<endl;
  ed=-1; sd=0;
  for(i=0;i<=pd;i++)
	  if(d[i][0]==x){ed=i; break;} 
	  else sd+=d[i][1];
  if(ns==echi)
	  { 
	   if(es==-1) 
		   g<<sd+d[i][1]<<" D"<<endl<<sd<<" D";
		else 
		   g<<ss+s[i][1]<<" S"<<endl<<ss<<" S";
		}
	else
		if(es>-1)
		   if(ns<echi)
			{ dif=echi-ns;
		      ss+=dif; fin=ss+s[es][1];
			  g<<fin<<" S"<<endl<<ss<<" S";
			}
			else
			{ dif=-echi+ns;
		      ss-=dif; fin=ss+s[es][1];
			  if (ss<0)
				  if(fin==0)g<<-ss<<" D"<<endl<<0<<" D";
			      else
				  if(fin<0){fin=-fin; ss=-ss;
				            if(fin>ss)g<<fin<<" D"<<endl<<ss<<" D";
				                else g<<ss<<" D"<<endl<<fin<<" D";
				           }
			       else
			        g<<fin<<" S"<<endl<<-ss<<" D";
			         
			   else
				   g<<fin<<" S"<<endl<<ss<<" S";
			}
		else			
		    if(nd<echi)
				{ dif=echi-nd;
				  sd+=dif; fin=sd+d[ed][1];
				  g<<fin<<" D"<<endl<<sd<<" D";
				}
				else
				{ dif=-echi+nd;
				  sd-=dif; fin=sd+d[ed][1];
				  if (sd<0)
					  if(fin<=0)g<<-sd<<" S"<<endl<<-fin<<" S";
				      else
					    g<<-sd<<" S"<<endl<<fin<<" D";
				else
					    g<<fin<<" D"<<endl<<sd<<" D";
				}
		   
return 0;
}

