#include <stdio.h>
main()
{
 int i,a,b,ans,ansn;
 ans=ansn=0;
 for (i=1;i<=7;i++)
  {
     scanf("%d%d",&a,&b);
     if (a+b>ans)
       {
                 ans=a+b;
                 ansn=i;
       }              
  }     
 printf("%d\n",ansn); 
}
