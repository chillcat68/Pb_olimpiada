#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("vase1.in");
    ofstream g("vase1.out");

    int n, v[100001], i, x, nr_lichid;
    long long int s=0;
    int grad1, grad2;
    char dir1, dir2;
    char directie, dir[100001];
    f>>n;
    for (i=1; i<=n; i++)
    {
        f>>x;
        v[i]=x;
        f>>directie;
        dir[i]=directie;
    }
    for (i=1; i<=n; i++)
        s=s+v[i];
    g<<s/2<<'\n';

    f>>nr_lichid;

    s=0;
    for (i=1; i<nr_lichid; i++)
        s=s+v[i];

    grad1=(s+v[nr_lichid])/2;
    grad2=abs((s-v[nr_lichid])/2);

	//Gradatii si directii initiale
    if (dir[nr_lichid]=='S')
    {
        dir1='S';
        if (v[nr_lichid]>s)
            dir2='D';
        else
            dir2='S';
    }
    else
    {
        dir1='D';
        if (v[nr_lichid]>s)
            dir2='S';
        else
            dir2='D';
    }

	// Actualizare gradatii si directii
    for (i=nr_lichid+1; i<=n; i++)
    {
        if (dir[i]=='S')
        {
            if (dir1=='S')
                grad1=grad1-v[i]/2;
            else
                grad1=grad1+v[i]/2;

            if (dir2=='S')
                grad2=grad2-v[i]/2;
            else
                grad2=grad2+v[i]/2;

            if (grad1<=0)
            {
                dir1='D';
                dir2='D';
                grad1=abs(grad1);
                grad2=abs(grad2);
            }
            else if (grad2<=0)
            {
                dir2='D';
                grad2=abs(grad2);
            }
        }
        else
        {
          if (dir1=='D')
                grad1=grad1-v[i]/2;
            else
                grad1=grad1+v[i]/2;

            if (dir2=='D')
                grad2=grad2-v[i]/2;
            else
                grad2=grad2+v[i]/2;

            if (grad1<=0)
            {
                dir1='S';
                dir2='S';
                grad1=abs(grad1);
                grad2=abs(grad2);
            }
            else if (grad2<=0)
            {
                dir2='S';
                grad2=abs(grad2);
            }
        }
    }
    //Afisare
    if (dir1==dir2)
    {
        if(grad1>grad2)
        {
            g<<grad1<<' '<<dir1<<'\n';
            g<<grad2<<' '<<dir2<<'\n';
        }
        else
        {
            g<<grad2<<' '<<dir2<<'\n';
            g<<grad1<<' '<<dir1<<'\n';
        }
    }
    else
    {
        if (dir[nr_lichid]=='S')
        {
            g<<grad1<<' '<<dir1<<'\n';
            g<<grad2<<' '<<dir2<<'\n';
        }
        else
        {
            g<<grad2<<' '<<dir2<<'\n';
            g<<grad1<<' '<<dir1<<'\n';
        }
    }


    return 0;
}
