#include <stdio.h>
 int count[2005][2005];
main()
{
 int i,j,k,n,m,ans;
 char tab[2005][2005],c;

scanf("%d",&k);
getchar();
n=0;
i=0;
while ((c=getchar())!='\n')  tab[1][++i]=c;    
m=i;
tab[1][i+1]='\0';
//printf("%d",m);
i=1;
while ((c=getchar())!=EOF)
 {
 i++;     
 tab[i][1]=c;
  for (j=2;j<=m+1;j++)
  tab[i][j]=getchar();
 tab[i][m+1]='\0'; 
 }
n=i; 
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
