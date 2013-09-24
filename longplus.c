#include <stdio.h>
void inv(int a[],int n)
{
 int t,i;
 for (i=1;i<=n/2;i++)
   {
     t=a[i];
     a[i]=a[n-i+1];
     a[n-i+1]=t; 
   }    
}

int isn(char c)
{if ((c>='0')&&(c<='9')) return 1; else return 0;}

main()
{
 int na=0,nb=0,nans=0,a[200],b[200],ans[200],i;
 char  c;
 
 for (i=0;i<=199;i++){a[i]=b[i]=ans[i]=0;}
 
 c=getchar();
 if (c=='-') a[0]=-1; else {a[0]=1;a[1]=c-'0';na=1;}
 while ((c=getchar())!='\n') 
 {
   if (isn(c)==0) continue;
   a[++na]=c-'0';
 }
 c=getchar();
 if (c=='-') b[0]=-1; else {b[0]=1;b[1]=c-'0';nb=1;}
 while ((c=getchar())!='\n')
  {
   if (isn(c)==0) continue;    
   b[++nb]=c-'0';
   }
    
 inv(a,na);
 inv(b,nb);    
 
 while((a[na]==0)&&(na>1)) na--;
 while((b[nb]==0)&&(nb>1)) nb--;
 
 nans=(na>nb)? na:nb;
 
 for (i=1;i<=nans;i++) 
  {
  ans[i]=ans[i]+a[0]*a[i]+b[0]*b[i];
  ans[i+1]=ans[i] /10;
  ans[i]=ans[i]% 10;
  }
  
 if (ans[nans+1]!=0) nans++;
while ((ans[nans]==0)&&(nans>1)) nans--;

 if (ans[nans]>0)
 {
  for (i=1;i<=nans;i++)
      if (ans[i]<0)
          {
          ans[i+1]--;
          ans[i]+=10;
          }
 }    
 else
  for (i=1;i<=nans;i++)
      if (ans[i]>0)
       {
       ans[i+1]++;
       ans[i]-=10;
       } 
       
if (ans[nans+1]!=0) nans++;    
while ((ans[nans]==0)&&(nans>1)) nans--;

if (ans[nans]<0)
   {
   putchar('-');
   for (i=nans;i>=1;i--) printf("%d",-ans[i]);
   }
else
   for (i=nans;i>=1;i--) printf("%d",ans[i]);
  
  putchar('\n'); 
  //printf("%d",-9 %10);       
 // getchar();
}
