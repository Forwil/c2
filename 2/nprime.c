#include<stdio.h>
#define abs(i) (((i)<0)?-(i):(i))
int p[]={1,2,3,5,7,9};
int prime[60000],bo[60000],np=0;
int sqrt(int n)
{
	int i=1,t;
	//printf("%d %d\n",n,i);
	t=-1;
	while(abs(i-t)>1)
		{
		t=i;
		i=((n/i)+i)/2;
//		printf("%d \n",abs(i-t));
		}
	return i;
}
int isprime(int n)
{
	int i;
	if (n<=1)
		return 0;
	for(i=1;prime[i]<=sqrt(n);i++)
		if (n % prime[i]==0)
			return 0;
	return 1;
}
void doit(int n,int number)
{
	int i,j,base=1;
	if (!isprime(number)&& number!=0)
		return;
	if (n==-1)
		{
		printf("%d\n",number);
		return ;
		}
	for (i=0;i<6;i++)
		doit(n-1,number*10+p[i]);
}
int main()
{
	int n;
	int i,t,maxv;
	maxv=sqrt(99999999);
	//printf("maxv=%d\n",maxv);
	for (i=2;i<=maxv;i++)
	if (bo[i]==0)
		{
		t=i+i;
		//printf("%d %d\n",i,t);
		while(t<=maxv)
			{
			bo[t]=1;
			t=t+i;
			}
		prime[++np]=i;	
		}
	//printf("%d %d\n",maxv,np);
	scanf("%d",&n);
	doit(n-1,0);
	return 0;
}
