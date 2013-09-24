#include<stdio.h>
void reverse(char a[],int n)
{
     int i,t;
     for (i=0;i<=n/2;i++)
     {
         t=a[i];
         a[i]=a[n-i];
         a[n-i]=t;
     }
}
main()
{
      char a[100],b[100];
      int i,j;
      freopen("invertsub.in","r",stdin);
      freopen("invertsub.out","w",stdout);
      fgets(a,99,stdin);
      fgets(b,99,stdin);
      for (i=0;a[i]!='\n';i++)
          {
          for (j=0;b[j]!='\n';j++)
              if (a[i+j]!=b[j] || a[i+j]=='\n')
                 break;
          if (b[j]=='\n')
             {
                         reverse(&a[i],j-1);
                         break;
             }
          }
      i=0;
      while(a[i]!='\n') putchar(a[i++]);
      putchar('\n');
  //    system("pause");
}
