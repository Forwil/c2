#include <stdio.h>
main()
{
 int a[200][200],i,j,n,x,y,dic,dx[4],dy[4],max,len;
dx[0]=1;dy[0]=0;
dx[1]=0;dy[1]=-1;
dx[2]=-1;dy[2]=0;
dx[3]=0;dy[3]=1;
scanf("%d",&n);

for (i=1;i<=n;i++)
for (j=1;j<=n;j++)
 a[i][j]=0;

for (i=1;i<=n;i++) 
  {
  a[0][i]=-1;
  a[n+1][i]=-1;
  a[i][0]=-1;
  a[i][n+1]=-1;
  } 
max=0;  
x=1;
y=1;
dic=3;
for (i=1;i<=n*n;i++)
 {
   a[x][y]=i;                     
   if (a[x+dx[dic]][y+dy[dic]]!=0) dic=(dic+1) % 4;
   x=x+dx[dic];
   y=y+dy[dic];
  }

for (i=1;i<=n;i++)
for (j=1;j<=n;j++)
 printf("%*d%s",5,a[i][j],(j==n)?"\n":"");
 //printf("%d\n",max[i]);
// system("pause");  
}
