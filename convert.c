#include <stdio.h>
long long po(int a,int n)
{
long long i,z;
z=1;
for (i=1;i<=n;i++) z=z*a;
return z;    
}
long long gys(long long a,long long b)
{
if (b==0) return a;
else
 return(gys(b,a % b));
}
main()
{
 int a,b,i,j,k,n,m,f1,f2;
 long long fz,fm,gc;
 char c;
 k=j=0;
 f1=f2=0;
 a=b=0;
while ((c=getchar())!='\n') 
  {
  if (c=='.') f1=1;
  if (c=='_') f2=1;
  if ((c=='.')||(c=='_')) continue;
  if (f2!=1)
    {
       k=k*10+c-'0';
     if (f1==1) a++;
    }
   else
    {
       j=j*10+c-'0';
       b++ ;
    }      
  }   
 //printf("%d:%d:%d:%d\n",k,a,j,b);  
 if (b==0)
  {
   fz=k;
   fm=po(10,a);       
  }
 else 
 { 
 fz=k*(po(10,a+b)-po(10,a))+j*po(10,a);
 fm=po(10,2*a+b)-po(10,2*a);
 } 
 gc=gys(fz,fm);

 printf("%lld/%lld",fz/gc,fm/gc);
 //system("pause");
} 
