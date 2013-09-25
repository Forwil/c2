#include<stdio.h>
int a[200001],nu[200001],n;
void sort(int i,int j)
{
	int x,y,z,t;
	x=i;
	y=j;
	z=a[(x+y)/2];
	while(x<=y)
	{
		while(z<a[y]) y--;
		while(z>a[x]) x++;
		if (x<=y)
		{
			t=a[x];
			a[x]=a[y];
			a[y]=t;
			t=nu[x];
			nu[x]=nu[y];
			nu[y]=t;
			x++;y--;
		}
	}
	if (x<j) sort(x,j);
	if (i<y) sort(i,y);
}
void sort2(int i,int j)
{
	int x,y,z,t;
	x=i;
	y=j;
	z=nu[(x+y)/2];
	while(x<=y)
	{
		while(z<nu[y]) y--;
		while(z>nu[x]) x++;
		if (x<=y)
		{
			t=a[x];
			a[x]=a[y];
			a[y]=t;
			t=nu[x];
			nu[x]=nu[y];
			nu[y]=t;
			x++;y--;
		}
	}
	if (x<j) sort2(x,j);
	if (i<y) sort2(i,y);
}

int main()
{
	int i,t,temp;
	while(scanf("%d",&a[n++])!=EOF)
	{
		nu[n-1]=n-1;
	}
	n-=1;
	//printf("%d",n);
	sort(0,n-1);
	t=1;
	for(i=0;i<n;i++)
		{
		temp=a[i];
		a[i]=t;
		if (a[i+1]!=temp)
			t=t+1; 
		}
	sort2(0,n-1);
	for(i=0;i<n;i++) printf("%d ",a[i]);
	putchar('\n');
	return 0;
}
