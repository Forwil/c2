#include <stdio.h>
double po(double a,int n)
{ 
  int i;
  double ans;
  ans=1;
  for (i=1;i<=n;i++)
   ans=ans*a;
  return ans; 
}
main()
{
  double sin,tem,n,sei; 
  int flag,i;
  long long k;
scanf("%lf",&sei);
flag=1;
while (sei>360) sei=sei-360;
while (sei<0) sei=sei+360;
if (sei>180) {sei=sei-180;flag=-1;}
if (sei>90)  sei=180-sei;
sei=sei*0.01745329251994329576923690768489;
n=1;
i=1;
sin=sei;
while (1)
 {
  tem=sin;
  n=n*(i+1)*(i+2);
  sin=sin+po(-1,(i+2)/2 % 2)*po(sei,i+2)/n;
  i=i+2;
  if (((tem-sin)>0? tem-sin: sin-tem)<0.00000000001) break;
 }
sin=sin*flag; 
if ((sin>0? sin:-sin)<0.00000001) sin=0;
printf("%.6lf\n",sin);
//system("pause"); 
}
