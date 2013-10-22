#include<stdio.h>
#include<string.h>
#define MAXN 202
#define isdig(c)  (c>='0' && c<='9')
#define c2i(c) (c - '0')
int a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
char s[MAXN*2][ MAXN * 5];
int n,m,k,len;
int conv(char x[],int y[])
{
	int i,j,len,num,numi = 0;
	len = strlen(x);
	for (i = 0;i < len ; i++)
	if isdig(x[i])
	{	
		num = c2i(x[i]);
		for(j = i+1; j < len; j++)		
		if isdig(x[j])
			num = num*10 + c2i(x[j]); 
		else
			break;
		y[numi++] = num;
		i = j;
	}
	return numi;
	//for (i = 0;i < numi;i++)	printf("%d\n",y[i]);
}
void out(int x[][MAXN],int n,int m)
{
	int i,j;
	for(i = 0;i < n;++i)
	{
		for(j = 0;j < m;++j) printf("%d ",x[i][j]);
	printf("\n");
	}			
}
int main(void)
{	
	int i,j,l;
	freopen("arr.in","r",stdin);
	while(fgets(s[len],MAXN *5,stdin)>0) len += 1;
	m = conv(s[0],a[0]);
	n = len - m;
	k = conv(s[n],b[0]);
	for(i = 0; i < n ;++i) conv(s[i],a[i]);
	for(i = 0; i < m ;++i) conv(s[n+i],b[i]);
	
//	out(a,n,m);
//	out(b,m,k);
	
	for(i = 0;i < n; ++i)
		for(j = 0;j < k;++j)
			for (l = 0;l < m;++l)
			c[i][j] += a[i][l] * b[l][j];
	out(c,n,k);
	return 0;
}
