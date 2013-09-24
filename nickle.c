#include<stdio.h>
int main()
{
    int a,b,i,n;
    int ans=0;
    //freopen("nickle.in","r",stdin);
    //freopen("nickle.out","w",stdout);
    scanf("%d",&n);
    n=n*100;
    while(n>=0)
    {
               ans+=n/2+1;
               n-=5;
    }
    printf("%d",ans);
    //system("pause");
    return 0;
}
