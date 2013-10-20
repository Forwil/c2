#define MAXL 105
#include<stdio.h>
int count[MAXL],n,len;
char p[MAXL],ans[MAXL];
void gen(int x,int begin)
{
	int i;
	//printf("%s\n",ans);
	if (x>=n)
	{
		printf("%s\n",ans);
		return;
	}
	for(i = begin; i < len-count[x]+1; i++)
	if (ans[i] == 0)
	{
		count[x] -= 1;
		ans[i] = p[x];
		if (count[x]==0)
			gen(x + 1,0);
		else
			gen(x,i + 1);
		ans[i] = 0;
		count[x] += 1;
	}
}
int main(void)
{
	char c;
	int i,j,find;
	while((c = getchar()) != '\n' && c!=EOF)
	{
		find = 0;
		for (i = 0;i < n;i++) 
			if (p[i] == c)
				{
				find = 1;
				count[i] += 1;
				break;
				}
		if (find == 0)
			{
			p[n] = c;
			count[n] = 1;
			n = n + 1;
			}
		len += 1;
	}
	//for(i=0;i<n;i++)printf("%c %d\n",p[i],count[i]);
	ans[n] = '\0';
	gen(0,0);
	return 0;
}
