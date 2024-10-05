//vieru ilie

#include<fstream.h>
ifstream f("adunscad.in");
ofstream g("adunscad.out");
int n,m,t,s,y,a[200],b[200],c[200];
int main()
{ f>>n>>m;
  int i,k;
  for(i=1;i<=m;i++) { f>>c[i];
                      t+=c[i];
                    }
  if((t-n)%2) g<<0<<'\n';
  else { y=(t-n)/2;
         a[0]=1;
         int d=0;
		 for(i=1;i<=m &&!a[y];i++)
			 for(k=d;k>=0&&!a[y];k--)
				 if(a[k] &&k+c[i]<=y && !a[k+c[i]]) { a[k+c[i]]=i;
			                            if(k+c[i]>d) d=k+c[i];
				                      }
		 if(!a[y])g<<0<<'\n';
         else { while(y) { b[a[y]]=1;
		                   y-=c[a[y]];
		                 }
			    if(b[1]) g<<'-';
		        g<<c[1];
                for(i=2;i<=m;i++) { if(b[i])g<<'-';
                                    else g<<'+';
                                    g<<c[i];
				                  }
                g<<'\n';
		       }
        }
    f.close();
    g.close();
    return 0;
}	
				 