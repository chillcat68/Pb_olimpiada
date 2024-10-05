//prof.Carmen Minca - solutie problema cri - implementare fara tablouri

#include<stdio.h>


int main()
{ int a,i0,j0,n,m,i,j,s1=0,s2=0,s3=0,s4=0,ies=1,k1,k2,k3,k4;
  int min1,min2,min3,min4;
  min1=min2=min3=min4=2000000000;
  freopen("cri.in","r",stdin);
  freopen("cri.out","w",stdout);


  scanf("%d%d%d%d",&n,&m,&i0,&j0);

  for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	  { scanf("%d",&a);
	        if((i<=i0)&&(j<=j0))
			{ s1+=a;
			  if((i0-i+j0-j)%2!=0)
			     if(min1>a)min1=a;
			}
	        if((i<=i0)&&(j>=j0))
			{ s2+=a;
			  if((i0-i+j-j0)%2!=0)
			     if(min2>a)min2=a;
			}
	        if((i>=i0)&&(j<=j0))
			{ s3+=a;
			  if((i-i0+j0-j)%2!=0)
			     if(min3>a)min3=a;
			}
                 if((i>=i0)&&(j>=j0))
			{ s4+=a;
			  if((i-i0+j-j0)%2!=0)
			     if(min4>a)min4=a;
			}
	  }
k1=i0*j0;
k2=i0*(m-j0+1);
k3=(n-i0+1)*j0;
k4=(n-i0+1)*(m-j0+1);



if((i0%2==0)&&(j0%2==0))
     {k1--; s1=s1-min1;}
if((i0%2==0)&&((m-j0+1)%2==0))
     {k2--; s2=s2-min2;}
if(((n-i0+1)%2==0)&&(j0%2==0))
     {k3--; s3=s3-min3;}
if(((n-i0+1)%2==0)&&((m-j0+1)%2==0))
     {k4--; s4=s4-min4;}


if(s2>s1){ies=2; k1=k2;s1=s2;}
  else if((s2==s1)&&(k1>k2)){ies=2; k1=k2;}
if(s3>s1){ies=3; k1=k3; s1=s3;}
  else if((s3==s1)&&(k1>k3)){ies=3; k1=k3;}
if(s4>s1){ies=4; k1=k4; s1=s4;}
  else if((s4==s1)&&(k1>k4)){ies=4; k1=k4;}


printf("%d %d %d",ies,s1,k1);

return 0;
}

