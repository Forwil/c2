#include<stdio.h>
int cal(int x)
{
	int tot=0;
	while(x!=0)
	{
		tot = tot+x%10;
		x = x/10;
	}
	return tot;
}
int main()
{
	int i,j,k,n,m,x,xx,val;
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&x,&k,&n);
	for(i=2;i<=n;i++)
	{
		xx = x;
		x = x+1;
		val = cal(k*xx);
		while(val!=cal(x)) x = x+1;
		//printf("%d\n",x);
	}
	printf("%d\n",x);
	return 0;
}
