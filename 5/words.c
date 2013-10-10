#include<stdio.h>
#define abs(x) ((x)<0?-(x):(x))
int out[30],in[30];
char p[30];
char f(char i)
{
	if (p[i]==i)
		return i;
	else
	{
		p[i]=f(p[i]);
		return p[i];
	}
}
int main()
{
	char c,cc,a,b;
	int tot,del,inout,t;
	for(c='a';c<='z';c++) p[c-'a']=c-'a';
	while(1)
	{
		c=getchar();
		if (c==EOF)break;
		out[c-'a']+=1;
		a=c;
		while((c=getchar())!='\n'&& (c!=EOF)) cc=c;
		in[cc-'a']+=1;
		p[a-'a']=f(cc-'a');
	}
	t=-1;
	for(c='a';c<='z';c++) 
	{
		//printf("%c %d",c,p[c-'a']);
		f(c-'a');
		inout=in[c-'a']+out[c-'a'];
		if (inout!=0)
		{
			if (t==-1) t=p[c-'a'];
			if (t!=p[c-'a'])
				{
				printf("no\n");
				return 0;
				}
		}
	}
	tot=0;
	inout=0;
	for (c='a';c<='z';c++)
	{
		//printf("%c %d %d\n",c,in[c-'a'],out[c-'a']);
		del=abs(in[c-'a']-out[c-'a']);
		if (del>1)
			{
				printf("no\n");
				return 0;
			}
		if (del==1) 
			{
				tot=tot+1;
				inout+=in[c-'a']-out[c-'a'];
			}
	}
	if (inout==0 &&(tot==2 || tot==0))
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
