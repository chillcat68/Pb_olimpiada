# include <fstream>
using namespace std;
ifstream f("covor.in");
ofstream g("covor.out");
int main()
{
    long long n, k, i=1, j=1, x, v;
    f>>n>>k>>v;

    if (n<4) {if(v==1) g<<'1';}
    else
     {
        while (i*(2*i+1)+1<=n)
            i++;
        if(v==1) {g<<i-1;}
    }
if(v==2)
{

     i--;
    x=i*(i+1)+1;
    if ((k>i*(2*i+1)+1) )  g<<'0';
    else
    {
        if (k==1) g<<'1';
        else
        {
            if (k==0) g<<'0';
            else

            {
                for (j=1; j<i; j++)
                    if (k<=1+j*(j+1)) {g<<j; break;}
                if ((k>i*(i+1)+1))
                for (j=i; j>0; j--)
                {
                    if (k<=x+2*j-1) {g<<j; break;}
                    else x+=2*j-1;
                }
            }
        }
    }}
    g<<'\n';
    return 0;
}
