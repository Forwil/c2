#include<stdio.h>
#define NUM 9
int p[] = {2,3,5,7,11,13,17,19,23};
int ans,time;
long long n;

void search(int id,int max,long long value,int num)
{
	int i;
	if (num>time || (num==time && value<ans)) 
		{
		time = num;
		ans = value;
		}
	if(id<NUM)
	for(i = 1;i <= max;i++)
		{
		value *= p[id];
		if (value<=n)
			search(id+1,i,value,num*(i+1));
		else
			return;
		}
}

int main(void)
{
	freopen("antiprime.in","r",stdin);
	freopen("antiprime.out","w",stdout);
	scanf("%lld",&n);
	search(0,30,1,1);
	printf("%d",ans);
	return 0;
}
