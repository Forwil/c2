#include<stdio.h>
#define MAXN 30
int n,m;
void generate(int ans[],int num,int sel,int begin)
{
	int i;
	if (num!=m)
	{
	for (i=begin;i<n;i++)
	if (((1 << i) & sel) == 0)
	{
		ans[num]=i+1;
		generate(ans,num+1,sel | (1 << i),i+1);
	}
	}
	else
	{
	for (i=0;i<m;i++)
		printf("%d ",ans[i]);
	printf("\n");
	}
}
int main()
{
	int ans[MAXN];
	scanf("%d%d",&n,&m);
	generate(ans,0,0,0);
	return 0;
}
