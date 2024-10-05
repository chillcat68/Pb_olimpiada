//nodea eugen
# include <fstream>
# include <iostream>
# include <cstring>
using namespace std;

ifstream f("comp.in");
ofstream g("comp.out");

int i,n;
char e[256];
long numar (char t[22])
{
    long x=0,y=0;
    int i=0;
    while (i<strlen(t))
    {
        y=0;
        while (t[i]>='0' && t[i]<='9')
        {
            y=y*10+t[i]-48;
            i++;
        }
        if (t[i]=='m') x+=y*1000,i++;
        if (t[i]=='s') x+=y*100,i++;
        if (t[i]=='z') x+=y*10,i++;
        if (t[i]=='u') x+=y,i++;
    }
    return x;
}
int eval(char s[256])
{
    char *p,dr[256],sm,t[256];
    long xs=0,xd=0,y,j;
    p=strchr(s,'<');
    if (!p) p=strchr(s,'>');
    strcpy(dr,p+1);
    sm=*p; *p='\0';
    p=strtok(s,"+");
    while(p)
    {
        xs+=numar(p);
        p=strtok(NULL,"+");
    }
    p=strtok(dr,"+");
    while(p)
    {
        xd+=numar(p);
        p=strtok(NULL,"+");
    }
    if (sm=='>') return xs>xd;
    if (sm=='<') return xs<xd;
}
int main()
{
    f>>n;f.get();
    for (i=1;i<=n;++i)
    {
        f.getline(e,256);
        g<<eval(e)<<'\n';
    }
    return 0;
}
