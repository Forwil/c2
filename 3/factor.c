#include <stdio.h>
main()
{
int po[40001],i,j,n,c;
freopen("factor.in","r",stdin);
freopen("factor.out","w",stdout);
scanf("%d",&n);
for (i=0;i<=40000;i++) po[i]=0;
po[0]=1;
po[1]=1;
for (i=1;i<=n;i++)
 {
  for (j=1;j<=po[0];j++)
   po[j]=po[j]*i;
  for (j=1;j<=po[0];j++)
   {
   po[j+1]=po[j+1]+po[j]/10;
   po[j]=po[j] % 10;                    
   }  
   
  while (po[po[0]+1]!=0)
   {
    po[0]++;
    po[po[0]+1]=po[po[0]+1]+po[po[0]]/10;
    po[po[0]]=po[po[0]] %10; 
   }
   
 }       
c=0;
for (j=po[0];j>=1;j--)
{
c++;
 printf("%d",po[j]);
if (c %50==0) putchar('\n');
} putchar('\n');
//  printf("%d\n",ans[0]);
// system("pause"); 
} 
