#include<stdio.h>
#define MAXN 202
int  a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
int len(int  x)
{
	int  i=1;
	while(x/=10) i++;
	return i;
}
int main()
{
	int n,m,k,i,j,l,maxl=0;
	char cc;
	freopen("arr.in","r",stdin);
	i=0;
	j=0;
	while(scanf("%d",&a[i][j])!=EOF)
	{
		j=j+1;
		if(getchar()=='\n')
			{
			m=j;
			break;
			}
	}
	while(1)
	{
		i=i+1;
		cc=getc(stdin);
		if (cc=='\n')
			{
				n=i;
				break;
			}
		else ungetc(cc,stdin);
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}
	i=0;
	j=0;
	while(scanf("%d",&b[i][j])!=EOF)
	{
		j=j+1;
		if(getchar()=='\n')
		{
			k=j;
			break;
		}
	}
	for(i=1;i<m;i++)
		for(j=0;j<k;j++)
			scanf("%d",&b[i][j]);
	
	for(i=0;i<n;i++)
		for(j=0;j<k;j++)
		{
			c[i][j]=0;
			for(l=0;l<m;l++)
				c[i][j]+=a[i][l]*b[l][j];
			if (maxl<len(c[i][j]))
				maxl=len(c[i][j]);
		}
	for(i=0;i<n;i++)
		for(j=0;j<k;j++)
			{
				printf("%*d",maxl+1,c[i][j]);
				if (j==k-1)printf("\n");
			}
}
