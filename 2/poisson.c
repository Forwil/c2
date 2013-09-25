#include<stdio.h>
int main()
{
	int m,k,i,j,nm;
	double ans=1;
	double e=2.718281828459;
	freopen("poisson.in","r",stdin);
	freopen("poisson.out","w",stdout);
	scanf("%d%d",&m,&k);
	nm=m;
	for (i=1;i<=k;i++)
		{
		ans=ans*m/i;
		while (nm!=0 && ans>10000)
			{
			ans/=e;
			nm=nm-1;
			}	
		}
	while(nm!=0)
		{
		ans/=e;
		nm-=1;
		}
	printf("%.6e\n",ans);
	return 0;
}
