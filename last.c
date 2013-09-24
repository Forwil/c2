#include <stdio.h> 
void swap(int *a,int *b)
{ int t;
t=*a;*a=*b;*b=t;}

void swapp(char a[],char b[])
{
   char c;
   int i;
  for (i=0;i<=89;i++) 
   { c=a[i];
    a[i]=b[i];
    b[i]=c;}   
}
main()
{
char a[30][90];
int i,j,n,flag,len[30],s[30];
j=n=0;
flag=0;
while ((gets(a[0]))!=NULL)
 {
  printf("%s\n",a[0]); 
  if (n==20) flag=1;    
  n=n % 20+1;
  for (i=0;a[0][i]!=0;i++)
   a[n][i]=a[0][i];
   len[n]=i;
   a[n][i]='\0';
   s[n]=j++;
// printf("%s %d\n",a[0],len[n]);
 }     
if (flag==1)
  {
   for (i=n+1;i<=20;i++)
     printf("%s\n",a[i]);
   for (i=1;i<=n;i++)
     printf("%s\n",a[i]);
     putchar('\n');
    for (i=1;i<=20;i++)
    for (j=i+1;j<=20;j++)
     if  ((len[i]>len[j])||((len[i]==len[j])&&(s[j]<s[i])))
       {
        swap(&len[i],&len[j]); 
        swapp(a[i],a[j]); 
        swap(&s[i],&s[j]);              
       }
       
   for (i=1;i<=20;i++)
      printf("%s\n",a[i]);     
  }  
else
  {
     for (i=1;i<=n;i++)
     printf("%s\n",a[i]);
     putchar('\n');
    for (i=1;i<=n;i++)
    for (j=i+1;j<=n;j++)
     if  ((len[i]>len[j])||((len[i]==len[j])&&(s[j]<s[i])))
       {
        swap(&len[i],&len[j]); 
        swapp(a[i],a[j]); 
        swap(&s[i],&s[j]);  
  //     printf("%d %d %d %d %d %d\n",i,j,len[i],len[j],s[i],s[j]);            
       }
   for (i=1;i<=n;i++)
      printf("%s\n",a[i]);    
  }  
//  getchar();
}
