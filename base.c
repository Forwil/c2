#include <stdio.h>
main()
{
 char ts[70],a,b,c;
 int i,s[5],re;
for (i=0;i<=64;i++)
  ts[i]=getchar();
  re=0;
 a=getchar();
while ((a=getchar())!=EOF) 
  {
   b=getchar();
   if (b!=EOF) c=getchar(); else  c=EOF;
   re=(b==EOF)+(c==EOF);
   if (b==EOF) b=0;
   if (c==EOF) c=0;   
     s[1]=a >> 2;
     s[2]=((a & 3)<< 4) +(b >> 4);
     s[3]=((b & 15)<< 2)+ (c >> 6);
     s[4]=c & 63;
     for (i=1;i<=4-re;i++)
      putchar(ts[s[i]]);
     for (i=1;i<=re;i++)
      putchar(ts[64]);     
  // printf("%d %d %d %d",s[1],s[2],s[3],s[4]);                       
  }         
//  system("pause");
} 
