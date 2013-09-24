#include <stdio.h>
char mos[40][30];
int ret(char c[])
{
  int i,j,flag;
 for (i=1;i<=36;i++)
  {
  flag=1;
  for (j=0;c[j]!='\0';j++)
   if (mos[i][j+1]!=c[j]) flag=0;
   if (mos[i][j+1]!=0) flag=0;
   if (flag==1)return i; 
  }   
}
main()
{
 char c[30];
 int i,j,k,n,m;
mos[1]="A.-";
mos[2]="B-...";
mos[3]="C-.-.";
mos[4]="D-..";
mos[5]="E.";
mos[6]="F..-.";
mos[7]="G--.";
mos[8]="H....";
mos[9]="I..";
mos[10]="J.---";
mos[11]="K-.-.";
mos[12]="L.-..";
mos[13]="M--";
mos[14]="N-.";
mos[15]="O---";
mos[16]="P.--.";
mos[17]="Q--.-";
mos[18]="R.-.";
mos[19]="S...";
mos[20]="T-";
mos[21]="U..-";
mos[22]="V...-";
mos[23]="W.--";
mos[24]="X-..-";
mos[25]="Y-.--";
mos[26]="Z--..";
mos[27]="0-----";
mos[28]="1.----";
mos[29]="2..---";
mos[30]="3...--";
mos[31]="4....-";
mos[32]="5.....";
mos[33]="6-....";
mos[34]="7--...";
mos[35]="8---..";
mos[36]="9----.";
scanf("%d",m);
for(k=1;k<=m;k++)
 {
 scanf("%d",n);
 for (i=1;i<=n;i++)
  {
   gets(c);
   printf{"%s",mos[ret(c)]};
  }
 }
system("pause"); 
}
