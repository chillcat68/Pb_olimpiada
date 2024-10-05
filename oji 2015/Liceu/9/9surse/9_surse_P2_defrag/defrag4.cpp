///prof. Gorea Claudiu-Cristian

#include <fstream>
using namespace std;
ifstream fin ("defrag.in");
ofstream fout("defrag.out");

long long caz,piste,sect,c,i,viz[101],a[101][722],gol,x,y,j,cel,mut;

int main()
{
    fin>>caz;
    fin>>piste>>sect>>c;
    for(i=1;i<=c;i++)
    {
        fin>>x>>y;
        a[x][y]=1;
        viz[x]++;
    }
    gol=0;
    for(i=1;i<=piste;i++)
        gol=gol+(viz[i]==0);
    if (caz==1) fout<<gol<<endl;
    if (caz==2)
    {
        ///obtinem nr consecutive prin mutare
        for(x=1;x<=piste;x++)
            if (viz[x]<=1 || viz[x]>=sect-1) fout<<"0 ";
            else
            {
                i=x;
                cel=viz[x];
                for(j=1;j<=sect;j++)
                {
                    a[i][j+sect]=a[i][j];
                    a[i][j]=a[i][j-1]+a[i][j];//, fout<<a[i][j]<<"_";
                }
                for(j=sect+1;j<=2*sect;j++)
                    a[i][j]=a[i][j-1]+a[i][j];//, fout<<a[i][j]<<"_";
                mut=0;
                for(j=1;j<2*sect-cel;j++)
                    if(a[i][j+cel]-a[i][j]>mut ) mut=a[i][j+cel]-a[i][j];

                fout<<cel-mut<<' ';

            }
    }

    return 0;
}
