#include <stdio.h>
main()
{ 
  char c,ans[4][1001];
  int i,j,k,n,m,ansn[4];
scanf("%d",&n);
getchar();
//printf("%d",n);
ansn[1]=ansn[2]=ansn[3]=0;
for (i=1;i<=n;i++)
 {
  k=0;
  while((c=getchar())!=' ') 
  ans[0][++k]=c;
  ans[0][++k]='\0';
  scanf("%d",&ansn[0]);
  getchar();
//  printf("%s",ans[0]);
  if (ansn[0]>ansn[1])
    {
    for (j=1;j<=1000;j++) ans[3][j]=ans[2][j];      
    for (j=1;j<=1000;j++) ans[2][j]=ans[1][j];
    for (j=1;j<=1000;j++) ans[1][j]=ans[0][j];                  
    ansn[3]=ansn[2];
    ansn[2]=ansn[1];
    ansn[1]=ansn[0];    
    } 
  else
     if (ansn[0]>ansn[2])
    {
    for (j=1;j<=1000;j++) ans[3][j]=ans[2][j];        
    for (j=1;j<=1000;j++) ans[2][j]=ans[0][j];              
    ansn[3]=ansn[2];
    ansn[2]=ansn[0]; 
    }  
  else
     if (ansn[0]>ansn[3])
    {
    for (j=1;j<=1000;j++) ans[3][j]=ans[0][j];                    
    ansn[3]=ansn[0];
    }   
 }  
 
for (i=1;i<=3;i++) 
printf("%s\n",ans[i]+1); 
system("pause");
}
