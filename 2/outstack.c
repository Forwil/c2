#include<stdio.h>
int main()
{
	int n,a[20],i,j,k,flag;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	flag=0;
	for (i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			for (k=j+1;k<n;k++)
				if (a[i]>a[j] && a[i]>a[k] && a[j]<a[k])
					flag=1;
	if (flag==0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
