#include<stdio.h>
int c[300];
int main()
{
    int i,n;
    char a[40];
    int ans=0,sum=0,len;
    freopen("real.in","r",stdin);
    freopen("real.out","w",stdout);
   fgets(a,40,stdin);
   for (i=0;a[i]!='\n';i++) c[a[i]]+=1;
   len=i;
   if (c['.']>1 || c['E']>1)
      {
                 printf("Wrong\n");
                 return 0;
      }
   for (i=0;i<=9;i++)
       sum+=c['0'+i];
   if (sum+c['.']+c['+']+c['-']+c['E']<sum)
      {
                 printf("Wrong\n");
                 return 0;
      }
   if (c['.']==1)
   for (i=0;a[i]!='\n';i++)
   if (a[i]=='.' && (a[i+1]>'9' || a[i+1]<'0'))
      {
                 printf("Wrong\n");
                 return 0;
      }
      
   if (c['+']>=1 || c['-'>=1])
   for (i=1;a[i]!='\n';i++)
   if ((a[i]=='-' || a[i]=='+') &&(a[i-1]!='E'))
      {
                 printf("Wrong\n");
                 return 0;
      }
      
   if (c['E']==1)
      {
                 printf("Format2\n");
      }
      else
      {
                 printf("Format1\n");
      }
    //system("pause");
    return 0;
}
