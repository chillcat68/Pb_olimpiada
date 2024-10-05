//100 de puncte, optim
#include<cstdio>
#include<algorithm>
#include<cstring>
#define Nmax 3000
using namespace std;
int n,i,j,s1,s2,nr,p;
char s[Nmax],S[Nmax];
int x[Nmax];
int cmp(const int a,const int b)
{
    return s[a]<s[b];
}
void detp()
{
    int i;
    for (i=1;i<=n;i++)
    if (s[i]>S[i])
    {p=i; break;}
}
void solve()
{
    int aux1,aux2;
    if (s1>s2)
    {
        i=n; if (i%2==0) i++; s[n+1]='0';
         while (s1-s2>s[i]-'0'+(9-s[i-1]+'0'))
        {
            s1-=(s[i]-'0');
            s[i]='0';
            s2+=(9-s[i-1]+'0');
            s[i-1]='9';
            i=i-2;
        }
        if (s[i]-'0'>s1-s2 && s1!=s2)
        {
            s[i]-=(s1-s2-1);
            while (s[i-1]=='9' &&i-1>0) i=i-2;
            s[i-1]+=1;
        }
        else if (s1!=s2)
        {
            aux1=s[i]; aux2=i;
            s1-=s[i]-'0'; s[i]='0';
            if (s1-s2==0) s[i]='1',s1++;
            i--;
            while (s[i]+(s1-s2)>'9' && i>0) i-=2;
            s[i]+=(s1-s2);
            if (i==0)
            {
                s[1]='1';
                for (i=1;i<n;i++) s[i+1]='0';
                s[++n]='1';
            }
        }
    }
    if (s2>s1)
    {
        i=n; if (i%2==1) i++;
        swap(s1,s2); s[n+1]='0';
        while (s1-s2>s[i]-'0'+(9-s[i-1]+'0'))
        {
            s1-=(s[i]-'0');
            s[i]='0';
            s2+=(9-s[i-1]+'0');
            s[i-1]='9';
            i=i-2;
        }
        if (s[i]-'0'>s1-s2 && s1!=s2)
        {
            s[i]-=(s1-s2-1);
            while (s[i-1]=='9' &&i-1>0) i=i-2;
            s[i-1]+=1;
        }
        else if (s1!=s2)
        {
            aux1=s[i]; aux2=i;
            s1-=s[i]-'0'; s[i]='0';
            if (s1-s2==0) s[i]='1',s1++;
            i--;
            while (s[i]+(s1-s2)>'9' && i>0) i-=2;
            s[i]+=(s1-s2);
            if (i==0)
            {
                s[1]='1';
                for (i=1;i<n;i++) s[i+1]='0';
                s[++n]='1';
            }
        }
    }
}
int main()
{
    freopen("ech.in","r",stdin);
    freopen("ech.out","w",stdout);
    gets(s+1);
    n=strlen(s+1); memcpy(S,s,sizeof(S));
    for (i=1;i<=n;i++)
    {
        if (i%2==1) s1=s1+(s[i]-'0');
        else s2=s2+(s[i]-'0');
    }
    solve();
    detp();
    if (!p)
    {
        i=n;
        while (s[i]=='9') i--;
        if (i==0){
        s[1]='1';
        for (i=1;i<=n;i++) s[i+1]='0';
        n++; s1=1; s2=0;}
        else
        {
            s[i]++;
            if (i%2==1) s1++; else s2++;
        }
        solve();
    }
    detp();
    for (i=n;i>p;i--)
    if (i%2==1) x[++x[0]]=i;
    sort(x+1,x+x[0]+1,cmp);
    for (i=p+1;i<=n;i++)
    if (i%2==0)
    {
        nr=min(s[i],s[x[x[0]]]);
        s[i]=s[i]-nr+'0';
        s[x[x[0]]]=s[x[x[0]]]-nr+'0';
        --x[0];
        if (s[x[x[0]]]=='0') break;
    }
    for (i=1;i<=n;i++)
    printf("%c",s[i]);
    return 0;
}
