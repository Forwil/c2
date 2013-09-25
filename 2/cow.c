#include<stdio.h>
int f[5000000];
int main()
{
	int n,m,k,p,i,j,ans;
	scanf("%d%d%d%d",&m,&n,&p,&k);
	f[0]=1;
	for (i=1;i<=k;i++)
		{
		j=i-m;
		while(j>=i-n && j>=0)
			{
			f[i]+=f[j];
			j-=1;
			}
		}
	i=k;
	ans=0;
	while(i+p>k)
		{
		ans+=f[i];
		i-=1;		
		}
	printf("%d\n",ans);
	return 0;
}
