#include<stdio.h>
int main()
{
	int len,k,x,m,n,i;
	long double a,b;
	freopen("sigma.in","r",stdin);
	scanf("%d%d%d%d",&k,&x,&m,&n);
	a=1;
	for (i=1;i<=n+1+m;i++) a*=x;
	b=1;
	for (i=1;i<=m;i++) b*=x;
	printf("%.14llf\n",k*(a-1)/b/(x-1));
	return 0;
}
