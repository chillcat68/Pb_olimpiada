#include <stdio.h>


int main()
{   FILE *f=fopen("cuart.in","r"), *g=fopen("cuart.out","w");
    int n,i,x,k1=0,k2=0,c1=0,c2=0,z,y,p,m=0,c;
    fscanf(f,"%d%d\n",&c,&n);
    for(i=1;i<=n;i++)
    {
         fscanf(f,"%d",&x);
         y=0; z=x;p=1;
         while(z!=0)
         {
             if(z%2==1)
             {
                 y=y+z%10*p;
                 p=p*10;
             }
             z=z/10;
         }
         if(y==0&&m<x) m=x;
         if(c1==0&&y!=0) c1=y;
         z=1;p=5;

         while(z<y)
             {
                 z=z+p;
                 p=p+4;
             }

         if(z==y)
             {
                 k1++;

             }
    }
    for(i=1;i<=n;i++)
    {
         fscanf(f,"%d",&x);
         y=0; z=x;p=1;
         while(z!=0)
         {
             if(z%2==0)
             {
                 y=y+z%10*p;
                 p=p*10;
             }
             z=z/10;
         }
         if(y==0&&m<x) m=x;
         if(c2==0&&y!=0) c2=y;
         z=1;p=5;

         while(z<y)
             {
                 z=z+p;
                 p=p+4;
             }

         if(z==y)
             {
                 k2++;

             }
    }
    fclose(f);

    if(c==1) fprintf(g,"%d\n",m);
        else if(c==2)
                {if(k1+k2==0) fprintf(g,"0\n");
                    else
                        {if(k1>k2) fprintf(g,"1\n");
                        if(k1<k2)fprintf(g,"2\n");
                        if(k1==k2)
                            if(c1>c2)fprintf(g,"1\n");
                                    else fprintf(g,"2\n");
                        }
                }
                else
                    {if(k1>k2) fprintf(g,"%d\n",k1);
                         if(k1<k2)fprintf(g,"%d\n",k2);
                         if(k1==k2)
                            if(c1>c2)fprintf(g,"%d\n",c1);
                                else fprintf(g,"%d\n",c2);
                        
                    }
    fclose(g);
    return 0;
}
