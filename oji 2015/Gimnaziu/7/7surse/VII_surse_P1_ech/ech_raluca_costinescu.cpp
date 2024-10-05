#include <fstream>

using namespace std;

ifstream f("ech.in");
ofstream g("ech.out");

int main()
{
    char s[50],c;
    int si=0, sp=0, i, x=0;
    while(f>>c)if(c>='0' and c<='9')s[x++]=c;
    x--;
    for(i=0;i<=x;i++)
        if(i%2)
            sp+=s[i]-'0';
        else
            si+=s[i]-'0';

    do
        {
            int ok=0;
            for(i=x;i>=0 && !ok; i=i-1)
                if(s[i]<'9')
                    {s[i]++;ok++;if(i%2)sp++;else si++;}
                else {s[i]='0';if(i%2)sp-=9;else si-=9;}
            if(!ok)
            {
                si=1;sp=0;
                s[0]='1';
                s[x+1]='0';
                x++;
            }
        }while(si!=sp);
    for(i=0;i<=x;i++)
    g<<s[i];
    g<<'\n';
    g.close();
    return 0;
}

