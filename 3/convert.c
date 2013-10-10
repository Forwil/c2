#include<stdio.h>
#define MAXN 100
#define MAXL 100
char sq[MAXN][MAXL];
int z[MAXN],l[MAXN],r[MAXN],top;
int isex(char * i)
{
	if (i[0]=='+'||i[0]=='-'||i[0]=='*'||i[0]=='/')
		return 1;
	else
		return 0;
}
int bigger(char *a,char *b)
{
	if ((a[0]=='*' || a[0]=='/')&& (b[0]=='+'|| b[0]=='-'))
		return 1;
	else
	if (((a[0]=='*' || a[0]=='/')&&(b[0]=='*' || b[0]=='/'))||
		((a[0]=='+' || a[0]=='-')&&(b[0]=='+' || b[0]=='-')))
		return 0;
	else
		return -1;
}

int output(int x)
{
	if (l[x]!=-1)
	if (bigger(sq[x],sq[l[x]])==1)
	{
		putchar('(');
		output(l[x]);
		putchar(')');
	}
	else
	{
		output(l[x]);
	}
	printf("%s",sq[x]);
	if (r[x]!=-1)
	if (bigger(sq[x],sq[r[x]])>=0)
	{
		putchar('(');
		output(r[x]);
		putchar(')');
	}
	else
	{
		output(r[x]);
	}
}
int main()
{
	char c;
	int i,j,k,n,m,top;
	n=0;
	while(1)
	{
		i=0;
		do
		{
			c=getchar();
			if (c=='\n' || c==' ' ||c==EOF) break;
			sq[n][i++]=c;
		}while(1);
		sq[n][i]=='\0';
		n++;
		while((c=getchar())==' ');
		ungetc(c,stdin);
		if (c=='\n'|| c==EOF) break;
	}
	top=0;
	for(i=0;i<n;i++)
	{
		l[i]=r[i]=-1;
		if (isex(sq[i]))
		{
			top = top-2;
			l[i] = z[top+1];
			r[i] = z[top+2];
		}
			top = top+1;
			z[top] = i;
	}
	output(n-1);
	putchar('\n');
	//for(i=0;i<n;i++)		printf("%s %d:%d %d\n",sq[i],i,l[i],r[i]);
	return 0;
}
