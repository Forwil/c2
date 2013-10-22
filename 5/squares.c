#include<stdio.h>
#include<string.h>
#define MAXN 2002
char boo[MAXN][MAXN];
int sum[MAXN][MAXN],ans;
int n,m,k;
int main(void)
{
	int i,j;
	freopen("squares.in","r",stdin);
	freopen("squares.out","w",stdout);
	scanf("%d\n",&k);
	n = -1;
	while(fgets(boo[++n],MAXN,stdin)>0);
	//for(i = 0;i < n;++i)	printf("%s",boo[i]);
	m = strlen(boo[0])-1;
	for(i = 1;i <= n;++i)
		for(j = 1;j <= m;++j)
			{
			sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + (boo[i-1][j-1] == '1');
			if (i >= k && j >= k && sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k] ==k*k) ans++;
			}
	printf("%d\n",ans);
	return 0;
}
