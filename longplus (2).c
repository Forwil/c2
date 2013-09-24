#include <stdio.h>
void inv(int a[],int n)
{
 int i,temp;
 for(i=1;i<=n/2;i++)
   {
   temp=a[i];
   a[i]=a[n-i+1];
   a[n-i+1]=temp;
   }
}

int com(int a[],int na,int b[],int nb)
{
int i;
//printf("%d %d",na,nb);
if (na>nb) return 1;
if (nb>na) return 0;
for (i=na;i>=1;i--) 
 {
  if (a[i]>b[i]) return 1;
  if (a[i]<b[i]) return 0; 
 }
return 0;
}

main()
{
 int *big,*smo,a[100],b[100],ans[100],i,na=0,nb=0,nans;
 char c;
for (i=0;i<=99;i++) a[i]=b[i]=ans[i]=0;

c=getchar();
if (c=='-') a[0]=-1;else a[0]=1;
if ((c!='-')&&(c!='+')) a[++na]=c-'0';
while ((c=getchar())!='\n') a[++na]=c-'0';

c=getchar();
if (c=='-') b[0]=-1;else b[0]=1;
if ((c!='-')&&(c!='+')) b[++nb]=c-'0';
while ((c=getchar())!='\n') b[++nb]=c-'0';

inv(a,na);
inv(b,nb);
while((a[na]==0)&&(na>1)) na--;
while((b[nb]==0)&&(nb>1)) nb--;

nans=(na>nb)?na:nb; 
if (((a[0]==1)&&(b[0]==1))||((a[0]==-1)&&(b[0]==-1)))
  {
  for (i=1;i<=nans;i++) 
     {
      ans[i+1]=(a[i]+b[i])/10;
      ans[i]=(ans[i]+a[i]+b[i])% 10; 
     }
  if (ans[nans+1]!=0) nans++;
  if ((a[0]==-1)&&(ans[nans]!=0)) putchar('-');
  for (i=nans;i>=1;i--) printf("%d",ans[i]);

  } 
else
 {
 if (com(a,na,b,nb)) 
   {
    big=a;
    smo=b;
   }   
 else 
   {
    big=b;
    smo=a;
   }

 for(i=1;i<=nans;i++)
   {
    ans[i]=big[i]-smo[i];
   if (ans[i]<0) 
    {
    big[i+1]--;
    ans[i]+=10;
    }
   }
 while ((ans[nans]==0)&&(nans>1)) nans--;
 if ((big[0]==-1)&&(ans[nans]!=0)) putchar('-');
 for (i=nans;i>=1;i--)
   printf("%d",ans[i]);
 }
putchar('\n');
}
