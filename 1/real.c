#include<stdio.h>
int c[300];
int main()
{
    int i,n,ise;
    char a[40];
    int ans=0,sum=0,len;
    freopen("real.in","r",stdin);
    freopen("real.out","w",stdout);
    fgets(a,40,stdin);
    for (i=0;a[i]!='\n';i++) c[a[i]]+=1;
    for (i=0;i<=9;i++) sum+=c['0'+i];
    len=i;
    if (c['.']>1 || c['E']>1 || c['-']>2 || c['+']>2)  printf("Wrong\n");
    else
        {
        if (sum+c['.']+c['+']+c['-']+c['E']<len) printf("Wrong\n");
        else
            ise=0;
            if (c['.']==1)
            for (i=0;a[i]!='\n';i++)
            {
            if (a[i]=='.')
                if((a[i+1]>'9' || a[i+1]<'0'))
                    {
                    printf("Wrong\n");
                    return 0;
                    }
            if (sum!=0) printf("Format1\n");
            else  printf("Wrong\n");
        }
    return 0;
}
