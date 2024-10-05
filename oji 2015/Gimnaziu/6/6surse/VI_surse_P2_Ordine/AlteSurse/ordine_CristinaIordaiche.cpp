#include<fstream>
#include<vector>
using namespace std;
ifstream fin("ordine.in");
ofstream fout("ordine.out");
int main()
{
    vector <int> endstring;
    vector <int> startstring;
    int n;
    int option;

        fin >> n;
    for (int i=0; i<n; ++i)
    {
        int x;
        fin >> x;
        endstring.push_back(x);
    }
    fin >> option;
    fin.close();

    if (1==option)
    {

        if(n%2==1) fout << endstring[n/2];
        else fout << endstring[n-1];
    }
    else
    {
        int aux=n;
        while(aux)
        {
            if (aux%2==1)
            {
                startstring.insert(startstring.begin(), endstring[aux/2]);
                endstring.erase(endstring.begin()+aux/2);
                aux--;
            }
            else
            {
                startstring.insert(startstring.begin(), endstring[aux-1]);
                endstring.erase(endstring.begin()+aux-1);
                aux--;
            }
        }
        for (int j=0; j<n; ++j)
        {
            fout << startstring[j] <<' ';
        }
    }
    fout<<'\n';
    return 0;
}
