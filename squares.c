#include <stdio.h>
main()
{
 int i,j,k,n,m,ans;
 char tab[205][205],count[205][205],c;
scanf("%d",&k);
getchar();
n=0;
i=0;
//printf("%d",m);
i=0;
while ((gets(tab[0]))!=EOF)
 {
 for (j=1;j<=204;j++)     
 tab[++i][j]=tab[0][j];
  }
n=i;
m=strlen(tab[1]); 
for (i=0;i<=n;i++) count[i][0]=0;
for (j=0;j<=m;j++) count[0][j]=0;
for (i=1;i<=n;i++)
for (j=1;j<=m;j++)
  count[i][j]=count[i-1][j]+count[i][j-1]-count[i-1][j-1]+(tab[i][j]=='1');

ans=0;  
for (i=1;i<=n;i++)
if (i>=k)
for (j=1;j<=m;j++)
if ((j>=k)&&(count[i][j]-count[i-k][j]-count[i][j-k]+count[i-k][j-k]==k*k))
 ans++;
  
printf("%d\n",ans);
//system("pause"); 
}
