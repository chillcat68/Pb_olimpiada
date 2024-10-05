#include <fstream.h>

void main() {
	ifstream f("carte.in");
	ofstream g("carte.out");
	int n,v[10000],i,nr,x,k,max=0,zimax;
	f>>n;
	for (i=0; i<n; i++) {
		f>>v[i];
		if (v[i]==1) x=i; 
	}
	x=0; nr=0;
	while (x<n) {
		i=0; k=0; nr++;
		while (i<n) {
			if (v[i]==x+1) {
				k++;
				x++;
			}
			i++;
		}
		if (k>max) {
			max=k;
			zimax=nr;
		}
	}
	g<<nr<<' '<<zimax<<' '<<max<<endl;
	f.close();
	g.close();
}
