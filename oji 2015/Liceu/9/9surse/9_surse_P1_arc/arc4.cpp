///prof. Gorea Claudiu-Cristian
#include <fstream>
using namespace std;
ifstream fin ("arc.in");
ofstream fout("arc.out");

int caz,n,u,secv,x,i, v[10001],f[10001],st,dr,l,cauta;

int main()
{
    fin>>caz;
    fin>>n;
    u=0;
    secv=0;
    for(i=1;i<=n;i++)
    {
        fin>>x;
        if (u!=x)
        {
            secv++;
            v[secv]=x;
            f[secv]=1;
        }
        else f[secv]++;
        u=x;
    }
    if (caz==1) fout<<secv<<endl;

    if (caz==2)
    {
        l=0;u=0;
        for(i=1;i<=secv;i++)
        {
            //fout<<v[i]<<" "<<f[i]<<endl;
            if(f[i]>l) l=f[i],u=i;
        }
        i=u; /// plec de la cea mai lunga secventa...
        while(l>=3)
        {
            if(f[i]>=3)
            {
                ///o pot elimina
                v[i]=0;
                n=n-f[i];   ///cate se sterg
                f[i]=0;

                st=i-1;
                dr=i+1;
                while(v[st]==0 && st>1) st--;
                while(v[dr]==0 && dr<secv) dr++;
                if (v[st]==v[dr]) ///verific lipirea
                {
                    f[dr]=f[dr]+f[st];
                    f[st]=0;
                    v[st]=0;
                    i=dr;///ce incerc sa scot
                    cauta=0;
                }
                else cauta=1;
            }
            else cauta=1;
            if (cauta)
            {
                ///caut noua secv maxima
                l=0;u=0;
                for(i=1;i<=secv;i++)
                {
                    //fout<<v[i]<<" "<<f[i]<<endl;
                    if(f[i]>l) l=f[i],u=i;
                }
                i=u; /// plec de la cea mai lunga secventa...
            }
        }


        fout<<n<<endl;
        for(i=1;i<=secv;i++)
            for(x=1;x<=f[i];x++)
                fout<<v[i]<<endl;

    }


    return 0;
}
