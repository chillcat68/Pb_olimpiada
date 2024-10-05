//vieru ilie

#include<fstream.h>
ifstream f("comp.in");
ofstream g("comp.out");
int m1,s1,z1,u1,m2,z2,s2,u2,i,S,n,k;
char s[251],c;
int main()
{ f>>n;
   f.get();
  for(k=1;k<=n;++k)	
 {	f.getline(s,252);
     i=S=m1=s1=z1=u1=m2=s2=z2=u2=0;
     while(s[i]!='<' && s[i]!='>')
	  if(s[i]>='0' &&s[i]<='9') { S=S*10+s[i]-48;
                                  i++;
                                }
      else if(s[i]=='+') i++;
           else { if(s[i]=='m') m1+=S;
                  else if(s[i]=='s')s1+=S;
		               else if(s[i]=='z') z1+=S;
				            else u1+=S;
			      S=0;
                  i++;
		        }
    c=s[i++];
    while(s[i]!=0)	
	 if(s[i]>='0' &&s[i]<='9') { S=S*10+s[i]-48;
								 i++;
                               }
     else if(s[i]=='+') i++;
          else { if(s[i]=='m') m2+=S;
                  else if(s[i]=='s')s2+=S;
		               else if(s[i]=='z') z2+=S;
				            else u2+=S;
			      S=0;
                  i++;
		       }
	z1+=u1/10; u1=u1%10;
	s1+=z1/10; z1=z1%10;
	m1+=s1/10; s1=s1%10;
	z2+=u2/10; u2=u2%10;
	s2+=z2/10; z2=z2%10;
	m2+=s2/10; s2=s2%10;
	if(c=='<' && (m1<m2 || m1==m2&& s1<s2 || m1==m2&&s1==s2&& z1<z2 ||m1==m2&&s1==s2&&z1==z2&&u1<u2)) g<<"1\n";
	else 	if(c=='>' && (m1>m2 || m1==m2&& s1>s2 || m1==m2&&s1==s2&& z1>z2 ||m1==m2&&s1==s2&&z1==z2&&u1>u2)) g<<"1\n";
	        else g<<"0\n";
 }
   f.close();
   g.close();
   return 0;
} 
