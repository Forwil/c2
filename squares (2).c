#include <stdio.h>
main()
{
 int i,j,k,n,m,ans;
 char tab[201][201],c;
 int count[2002],sum[2002];
scanf("%d",&k);
getchar();
n=0;
i=0;
ans=0;
while ((c=getchar())!='\n')  
 tab[1][++i]=c;
m=i;
//printf("%d",m);
i=1;
sum[0]=0;
while ((c=getchar())!=EOF)
 {
 i++;     
 tab[i][1]=c;
  for (j=2;j<=m;j++)
   tab[i][j]=getchar();
 getchar(); 
 }
  printf("%d\n",ans);
//system("pause"); 
}
