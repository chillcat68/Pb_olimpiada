//prof. Liliana Chira
#include <fstream>
using namespace std;
ifstream f("covor.in");
ofstream g("covor.out");
int n,k,i,x,y,a,d,b,v;
int main()
{
    f>>n>>k>>v;
    if(v==1)
    {
        for(i=1;;i++)
    {
        if(2*i*(i+1)-i+1>n)
        {
            x=i-1;
            break;
        }
    }
    g<<x<<endl;
    }
   if( v==2)
   { for(i=1;;i++)
    {
        if(2*i*(i+1)-i+1>n)
        {
            x=i-1;
            break;
        }
    }
       d=0;y=2*x*(x+1)-x+1;
    if(k>y)
    {g<<'0';return 0;}
    else
    if(k<=(x+1)*(x+2)-2*x-1)
        {for(i=1;;i++)
            if((i+1)*(i+2)-2*i-1>=k)
            {
                g<<i;return 0;
            }
        }
    else
    {
        for(i=x;i>=1;i--)
        {
            d+=2*(i+1)-3;
            if((x+1)*(x+2)-2*x-1+d>=k)
                {
                    g<<i;break;
                }
        }
    }
    }


    return 0;
}
