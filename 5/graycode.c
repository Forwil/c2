#include<stdio.h>
#include<string.h>
#define MAXL 100
void g2b(char a[],char b[])
{
	int i=0;
	b[i] = a[i];
	i = i + 1;
	while(a[i]!='\n') 
	{
		b[i] = (a[i] != a[i-1])? '1':'0';
		i += 1;
	}
	b[i] = '\n';
	b[i+1] ='\0';
}
void b2g(char a[],char b[])
{
	int i=0,s;
	b[i] = a[i];
	s = (a[i] == '1');
	i += 1;
	while(a[i]!='\n') 
		{
			s += (a[i] == '1');
			b[i] = '0' + (s % 2);
			i += 1;
		}
	b[i] = '\n';
	b[i+1] = '\0';
}
int main(void)
{
	char s[MAXL],out[MAXL];
	int i,l;
	//freopen("graycode.in","r",stdin);
	while(fgets(s,MAXL,stdin)>0)
	{
		if(s[0]=='-')
			{
			if (s[1]=='g') g2b(&s[2],out);
			if (s[1]=='b') b2g(&s[2],out);
			}
		else
			b2g(s,out);
		printf("%s",out);
	}
	return 0;
}
