#include<stdio.h>
void clean()
{
    int c,s[10008],i,j;
    i=0;
    while((c=getchar())!='\n')
        s[i++]=c;
    s[i]=c;
    for(j=i;j>=0;j--)
        if(s[j]!=' ')
            ungetc(s[j],stdin);
}
void get(int *f)
{
    int i,t,an,n;
    for(i=0;i<=400;i++)f[i]=0;
    clean();
    an=1;
    while(1)
    {
        t=getchar();
        if(t=='\n')
        {
            break;
        }
        else if(t=='x')
        {
            t=getchar();
            ungetc(t,stdin);
            if(t>='0' && t<='9')
            {
                scanf("%d",&n);
                f[n]+=an;
                an=1;
            }
            else
            {
                f[1]+=an;
                an=1;
            }
        }
        else
        {
            if(t=='-')an=-1;
            ungetc(t,stdin);
            scanf("%d",&an);
            t=getchar();
            ungetc(t,stdin);
            if(t!='x')
            {
                f[0]+=an;
                an=1;
            }
        }
    }
}
int main(void)
{
    int i,j,c,flag;
    int f1[1000],f2[1000],f[1000];
    freopen("poly.in","r",stdin);
	get(f1);
    get(f2);
    //for(i=0;i<=10;i++)printf("%d %d %d\n",i,f1[i],f2[i]);
    c=getchar();
    if(c=='+')
        for(i=0;i<=200;i++)f[i]=f1[i]+f2[i];
    else if(c=='-')
        for(i=0;i<=200;i++)f[i]=f1[i]-f2[i];
    else
    {
        for(i=0;i<=400;i++)f[i]=0;
        for(i=0;i<=200;i++)
            for(j=0;j<=200;j++)
                f[i+j]+=f1[i]*f2[j];
    }
    
    flag=0;
    for(i=400;i>=2;i--)
        if(f[i]!=0)
        {
            if(flag==0)
            {
                if(f[i]<0)
                    printf("-");
                flag=1;
            }
            else
                printf(" %c ",f[i]>0? '+':'-');
            if(f[i]!=1 && f[i]!=-1)
                printf("%d",f[i]>0? f[i]:-f[i]);
            printf("x%d",i);
        }
    if(f[1]!=0)
    {
        if(flag==0)
        {
            if(f[1]<0)
                printf("-");
            flag=1;
        }
        else
            printf(" %c ",f[1]>0? '+':'-');
        if(f[1]!=1 && f[1]!=-1)
            printf("%d",f[1]>0? f[1]:-f[1]);
        printf("x");
    }
    if(f[0]!=0)
    {
        if(flag==0)
        {
            printf("%d",f[0]);
            flag=1;
        }
        else
            printf(" %c %d",f[0]>0? '+':'-',f[0]>0? f[0]:-f[0]);
    }
    if(flag==0)printf("0");
    printf("\n");
//    system("pause");
    return 0;
}
