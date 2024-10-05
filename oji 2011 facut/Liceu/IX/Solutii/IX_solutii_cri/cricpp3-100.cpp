// sursa 100p - problema cri
// prof.Silviu Candale


#include <fstream>
#include <cstdio>
//#define STDIO
//#define DEBUG
using namespace std;

int main(){
	printf("cri\n");
	int n,m,x,y;
	int s1,s2,s3,s4;
	int m1,m2,m3,m4;
	#ifndef STDIO
		ifstream fin("cri.in");
		fin>>n>>m>>x>>y;
	#else
		freopen("cri.in","r",stdin);
		scanf("%d%d%d%d",&n,&m,&x,&y);
	#endif
	s1=s2=s3=s4=0;
	m1=m2=m3=m4=10000;
	int kk1,kk2,kk3,kk4;
	kk1=kk2=kk3=kk4=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			int q;
			#ifndef STDIO
				fin>>q;
			#else
				scanf("%d",&q);
			#endif
			if(i<=x && j<=y){
				s1 += q;
				kk1++;
				if( (i!=x || j!=y) && (i!=1 || j!=1) && (i+j)%2!=(1+1)%2 && q<m1) m1=q;
			}
			if(i<=x && j>=y){
				s2 += q;
				kk2++;
				if( (i!=x || j!=y ) && (i!=1 || j!=m) && (i + j)%2!=(m+1)%2 && q<m2 ) m2 = q;
			}
			if(i>=x && j<=y){
				s3 += q;kk3++;
				if( (i!=x || j!=y) && (i!=n || j!=1) && (i+j)%2 != (n+1)%2 && q<m3 ) m3 = q;
			}
			if(i>=x && j>= y){
				s4 += q;kk4++;
				if((i!=x || j!=y) && (i!=n || j!=m) && (i+j)%2 != (n+m)%2 && q<m4 ) m4 = q;
			}
		}
	int k1=x*y, k2=x*(m-y+1), k3=(n-x+1)*y, k4=(n-x+1)*(m-y+1);
	if(x%2==0 && y%2==0)
		s1-=m1, k1--;
	if(x%2==0 && (m-y+1)%2==0)
		s2-=m2, k2--;
	if((n-x+1)%2==0 && y%2==0)
		s3-=m3, k3--;
	if((n-x+1)%2==0 && (m-y+1)%2==0)
		s4-=m4, k4--;
	#ifdef DEBUG
		printf("%d %d %d %d\n",kk1,kk2,kk3,kk4);
		printf(" zona    suma     min    k\n");
		printf("%d %d %d %d\n",1,s1,m1,k1);
		printf("%d %d %d %d\n",2,s2,m2,k2);
		printf("%d %d %d %d\n",3,s3,m3,k3);
		printf("%d %d %d %d\n",4,s4,m4,k4);
	#endif
	int z=1,k=k1;
	int s=s1;
	if(s2>s)
		z=2,s=s2,k=k2;
	else
		if (s2==s && k2<k)
			z=2,s=s2,k=k2;
	if(s3>s)
		z=3,s=s3,k=k3;
	else
		if (s3==s && k3<k)
			z=3,s=s3,k=k3;
	if(s4>s)
		z=4,s=s4,k=k4;
	else
		if (s4==s && k4<k)
			z=4,s=s4,k=k4;
	#ifndef STDIO
		ofstream fout("cri.out");
		fout<<z<<" "<<s<<" "<<k<<endl;
	#else
		freopen("cri.out","w",stdout);
		printf("%d %d %d\n",z,s,k);
	#endif
	return 0;
}
