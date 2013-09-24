#include <stdio.h>
main()
{
int i,j,n;
char c;
scanf("%d\n",&n);
c=getchar();
for (i=1;i<=n;i++)
   {
   for (j=1;j<=n-i;j++) putchar(' ');               
   for (j=1;j<=i;j++)
    printf("%c%s",c,(j==i)? "\n":" ");
   }

for (i=n-1;i>=1;i--)
   {
   for (j=1;j<=n-i;j++) putchar(' ');               
   for (j=1;j<=i;j++)
    printf("%c%s",c,(j==i)? "\n":" ");
   }   
 
}
