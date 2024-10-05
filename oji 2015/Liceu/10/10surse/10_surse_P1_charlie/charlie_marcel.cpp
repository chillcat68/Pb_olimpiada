/*
	Sursa 100p !!! (dar care sparge memoria)
	prof. Marcel Dragan, Sibiu
*/
#include <fstream>
#include <cstring>
#include <stack>
using namespace std;
ifstream in("charlie.in");
ofstream out("charlie.out");
char s[100001];
int p;
void afisare(stack <char> st)
{
    if(!st.empty())
    {
        char c=st.top();
        st.pop();
        afisare(st);
        out << c;
    }
}
int main()
{
    in>>p>>s;
    int n=strlen(s);
    if(p==1)
    {
        int ctMax=0;
        for(int i=0;i<n;i++)
        {
            // cauta dif<0
            int dif1=s[i+1]-s[i];
            while(dif1>=0 && i+2<n)
            {
                i++;
                dif1=s[i+1]-s[i];
            }
            // numara dif<0 dif>0
            int dif2=s[i+2]-s[i+1];
            int ct=0;
            while(dif1<0 && dif2>0 && i+2+ct<n)
            {
                ct=ct+2;
                dif1=s[i+1+ct]-s[i+ct];
                dif2=s[i+2+ct]-s[i+1+ct];
            }
//            i=i+ct;
            // verif max
            if(ctMax<ct)
                ctMax=ct;
        }
        out<<ctMax+1<<endl;
    }
    else
    {
        stack <char> st;
        st.push(s[0]);
        char top=s[1];
        int val=0;
        for(int i=2;i<n;i++)
        {
            while(st.size()>0 && s[i] > top && top < st.top())
            {
                val=val+max(s[i]-'a'+1,st.top()-'a'+1);
                top=st.top();
                st.pop();
            }
            st.push(top);
            top=s[i];
        }
        afisare(st);
        out << top<<endl;
        out << val<<endl;
    }
    return 0;
}
