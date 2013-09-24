#include <stdio.h>
main()
{
long n,t,i,j,z,m;
scanf("%ld",&n);
t=n;
i=1;
while (t-i>0)
 {
      t=t-i;
      i++;
 }
if (i % 2==0) 
 {
  z=t;
  m=i+1-t;
 }
 else
 {
  z=i+1-t;
  m=t;
 }
printf("%ld/%ld\n",z,m); 
//system("pause");
} 
