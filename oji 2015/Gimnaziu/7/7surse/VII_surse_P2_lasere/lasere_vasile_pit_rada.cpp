//PIT-RADA IONEL-VASILE COLEGIUL NATIONAL TRAIAN
#include<fstream>
using namespace std;

ifstream  fin("lasere.in");
ofstream fout("lasere.out");

int n,m,nrg,nrt,i,j,k,c,caz,li,co,dir;

short int a[203][203], b[203][203];
short int dl[8]={-1,-1, 0,+1, 0,-1,+1,+1};
short int dc[8]={-1, 0,+1, 0,-1,+1,+1,-1};
int main()
{
    fin>>caz>>n>>m;
    for(i=0;i<=n+1;i++)
    {
        a[i][0]=10000;
        a[0][i]=10000;
        a[n+1][i]=10000;
        a[i][n+1]=10000;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            fin>>a[i][j];
        }
    }
    for(i=1;i<=m;i++)
    {
        fin>>li>>co>>dir;
        switch(dir)
        {
            case 1 :
            {
                for(j=li-1;j>=1;j--)
                {
                    a[j][co]--;
                }
                break;
            }
            case 3 :
            {
                for(j=li+1;j<=n;j++)
                {
                    a[j][co]--;
                }
                break;
            }
            case 4 :
            {
                for(j=co-1;j>=1;j--)
                {
                    a[li][j]--;
                }
                break;
            }
            case 2 :
            {
                for(j=co+1;j<=n;j++)
                {
                    a[li][j]--;
                }
                break;
            }
        }
    }
    nrg=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            c=0;
            for(k=0;k<=7;k++)
            {
                li=i+dl[k];
                co=j+dc[k];
                if(a[li][co]<a[i][j])
                {
                    c++;
                    break;
                }
            }
            if(c==0)
            {
                nrg++;
                b[i][j]=1;
            }
            else
            {
                b[i][j]=0;
            }
        }
    }
    nrt=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=n-2;j++)
        {
            if(b[i][j]==0 && b[i][j+1]==1 && b[i][j+2]==1)
            {
                nrt++;
            }
        }
    }
    if(caz==1)fout<<nrg;
    else fout<<nrt;
    fout.close();
    fin.close();
    return 0;
}
