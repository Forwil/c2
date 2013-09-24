#include <stdio.h>
char tp=0;

void out(char a[])
{ 
 int i=0; 
 while (a[i]!=0) ++i;
 while (a[i-1]==' ') a[--i]='\0';    
 for (i=1;a[i]!='\0';i++)
 putchar(a[i]);
}

int ischar(char c)
{
if (((c>='0')&&(c<='9'))||
   ((c>='a')&&(c<='z'))||
   ((c>='A')&&(c<='Z'))) return(1);
else return(0);
}

char g()
{
     char i;
if (tp!=0)
 {
  i=tp;
  tp=0;        
 return(i);
 } else 
  return(getchar());
}

void b(char c){tp=c;}

main()
{
char w[100],c,temp;
int i,j,flag;
i=0;
flag=0;
while ((c=g())!=EOF) 
  { 
  if ((c==' ')&&(i==0)&&(flag==1))
    {    
    continue;
     }
   w[++i]=c;
  if ((i==81)&&(ischar(c)==0/*c=='\''||c==','||c=='.'||c==':'||c==';'||c==' '||c=='-')*/))
  { 
   if (c==' ') i--;
    w[i+1]='\n';
    w[i+2]=0;
    out(w);
    i=0;
   flag=1;
   }
  else 
    if (i==81)
   {
  for (j=80;j>=1;j--)
  if (ischar(w[j])==0/*w[j]=='\''||w[j]==','||w[j]=='.'||w[j]==':'||w[j]==';'||w[j]==' '||w[j]=='-'*/)
    {
    temp=w[j];
    w[j]=0;
    out(w);
    flag=1;
    if (temp!=' ') putchar(temp);
    putchar('\n');
    i=0;
    while (j+1<=81) w[++i]=w[++j];
    break;
    }
   }
 if ((i!=0)&&(c=='\n'))
  {
 if ((c=g())==EOF) i--; else b(c);
   w[i+1]=0;
   if (i!=1) out(w);
   i=0;
   flag=0;
  }
  }
}

