#include<stdio.h>
void out(int a[])
{
	int i,j;
	i=200;
	while(a[i]==0&&i>100)i--;
	for(j=i;j>=100;j--)
		printf("%d",a[j]);
	printf(".");
	for(j=1;j<=14;j++)
		printf("%d",a[100-j]);
	printf("\n");
}
int main()
{
	int len,k,x,m,n,i,j,z,t=0;
	int a[201]={0},b[201]={0};
	freopen("sigma.in","r",stdin);
	scanf("%d%d%d%d",&k,&x,&m,&n);
	if(x==1)
	{
		printf("%d.",(n+m+1)*k);
		for(i=1;i<=14;i++)printf("0");
		printf("\n");
		return 0;
	}
	a[100]=1;
	b[100]=1;
	for(i=1;i<=n+1;i++)
	{
		for(j=0;j<=199;j++) a[j]=a[j]*x;
		for(j=0;j<=199;j++) 
		{
			a[j+1]+=a[j]/10;
			a[j]%=10;
		}
	}
	if(t)out(a);
	for(i=1;i<=m;i++)
	{
		z=0;
		for(j=199;j>=0;j--)
		{
			z=z*10+b[j];
			b[j]=z/x;
			z=z%x;
		}
	}
	if(t)out(b);
	for(i=0;i<=200;i++) a[i]=a[i]-b[i];
	for(i=0;i<=200;i++)
		if (a[i]<0)
		{
			a[i]+=10;
			a[i+1]-=1;
		}
	if(t)out(a);
	for(i=0;i<=200;i++)a[i]*=k;
	for(i=0;i<=200;i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	if(t)out(a);
	z=0;
	for(j=199;j>=0;j--)
	{
		z=z*10+a[j];
		a[j]=z/(x-1);
		z=z%(x-1);
	}
	if(a[100-15]>=5)
	{
		a[100-14]+=1;
		i=100-14;
		while(a[i]>10)
		{
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	}
	out(a);
	return 0;
}
