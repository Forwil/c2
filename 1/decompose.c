#include <stdio.h>
main()
{
  int i,j,k,n,m,t,p[5000],count[5000],flag[30001];
 scanf("%d",&n);
 t=0;
for (i=1;i<=n;i++) flag[i]=1;
for (i=2;i<=n;i++)
if (flag[i]) 
 {
  p[++t]=i;
  k=i;
  while (k+i<=n)
   {
    flag[k+i]=0;
    k=k+i;
    }                   
  count[t]=0;  
 }   
for (i=1;i<=t;i++)
 {
  k=p[i];
  while (n/k>0)
  {
  count[i]=count[i]+n/k;
  k=k*p[i];
  }                
 }   
for (i=1;i<=t;i++)
{
printf("%d",p[i]);
if (count[i]>1) printf("^%d",count[i]);
if (i<t) printf("*"); else printf("\n");
} 
//system("pause");
} 
