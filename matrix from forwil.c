#include <stdio.h>
main()
{
int a[210][210],b[210][210],c[210][210],i,j,z,k,n,m;
scanf("%d%d%d",&n,&k,&m);

for (i=1;i<=n;i++)
for (j=1;j<=k;j++)
 scanf("%d",&a[i][j]);

for (i=1;i<=k;i++)
for (j=1;j<=m;j++)
 scanf("%d",&b[i][j]);

for (i=1;i<=n;i++)
for (j=1;j<=m;j++)
{
 c[i][j]=0;
 for (z=1;z<=k;z++)
  c[i][j]=c[i][j]+a[i][z]*b[z][j];  
} 
for (i=1;i<=m;i++)
for (j=1;j<=n;j++)
{
 printf("%8d",c[j][i]);
 if (j==n) putchar('\n');
}
//system("pause");
}
