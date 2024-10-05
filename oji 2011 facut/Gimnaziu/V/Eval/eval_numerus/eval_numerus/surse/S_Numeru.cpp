#include <fstream.h>
//using namespace std;

int main()
{
	long k, n;
	long i, r, rd;
	ifstream fin("numerus.in");
	ofstream fout("numerus.out");
	fin >> k >> n;
	if(k % 2 == 1)
	{
		for(i = 1; i<= 5; i++)
			fout << (k-1)*5 +i<< " ";
		fout << k *5<<"\n";
	}
	else
	{
		fout << k*5<< " ";
		for(i = 0; i< 5; i++)
			fout << k * 5 - i<< " ";
		fout << "\n";
	}
	if( n%5 == 0)
	{
		rd = n/5;
		fout <<rd<<'\n';
	}
	else
	{
		rd = (n/5 +1);
		fout << rd<< "\n";
	}
	if(n%10 == 0 ) fout << 'A'<<"    "<<'B'<<"\n";
	else 
		if(n%5 == 0) fout << 'E'<<"    "<<'F'<< "\n";
	if(rd % 2 == 1)
	{
		r = n%5;
		switch(r)
		{
			case 1: fout << 'A'<<"\n";break;
			case 2: fout << 'B'<<"\n";break;
			case 3: fout << 'C'<<"\n";break;
			case 4: fout << 'D'<<"\n";break;
		}
	}
	else
	{
		r = n%5;
		switch(r)
		{
			case 1: fout << 'F'<<"\n";break;
			case 2: fout << 'E'<<"\n";break;
			case 3: fout << 'D'<<"\n";break;
			case 4: fout << 'C'<<"\n";break;
		}
	}
	
	fin.close();
	fout.close();
	return 0;
}
	
		
