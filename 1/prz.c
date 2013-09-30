#include<stdio.h>
int ent[1000010],out[1000010];
int main()
{
    int a,b,i,maxv=0,now=0,enter=0;
   freopen("prz.in","r",stdin);
   freopen("prz.out","w",stdout);
    i=0;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
       // if (a>b) continue;
        ent[a]++;
        out[b]--;    
        if (a>maxv) maxv=a;
        if (b>maxv) maxv=b;                  
    }
    a=0;
    b=0;
    for (i=1;i<=maxv;i++)
    {
        now=now+ent[i];
        //printf("%d ",now);
        if (now>0 && enter==0)
           {
           enter=1;
           a=i;
           }
       
        now=now+out[i];
        if (now==0 && enter==1)
           {
           enter=0;
           b=i;
           printf("%d %d\n",a,b);
           }
        //printf("%d\n",now);
    }
  //  system("pause");
    return 0;
}
