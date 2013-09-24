#include <stdio.h>
main()
{
int ans[40001],po[40001],i,j,n;
scanf("%d",&n);
for (i=0;i<=40000;i++) ans[i]=po[i]=0;
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
   
  ans[0]=(ans[0]>po[0])?ans[0]:po[0];
  for (j=1;j<=ans[0];j++)
   {
   ans[j]=ans[j]+po[j];
   ans[j+1]=ans[j+1]+ans[j]/10;
   ans[j]=ans[j] %10;
   } 
   
   if (ans[ans[0]+1]!=0) ans[0]++;
  // for (j=ans[0];j>=1;j--)
//  printf("%d",ans[j]);
 // putchar('\n');
 }       

for (j=ans[0];j>=1;j--)
 printf("%d",ans[j]);
 putchar('\n');
//  printf("%d\n",ans[0]);
 system("pause"); 
} 
