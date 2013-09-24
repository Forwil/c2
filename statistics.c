#include<stdio.h>
main()
{
long  n,maxv,maxvs,minv,minvs,data;
double sum;
char c;
scanf("%d",&data);
n=1;
maxv=minv=data;
sum=data;
minvs=maxvs=1;
while ((scanf("%d",&data))!=EOF) 
 {
// printf("%d %d\n",n,data);
 n++;
 if (data>maxv) {maxv=data;maxvs=n;}
 if (data<minv) {minv=data;minvs=n;}
 sum+=data;
 }
printf("%.0f\n%0.2f\n%d %d\n%d %d\n",sum,sum/n,maxv,maxvs,minv,minvs);
}
