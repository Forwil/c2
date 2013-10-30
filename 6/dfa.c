#include<stdio.h>
#include<string.h>
#define MAXINPUT 1000
#define MAXSTATE 100
struct Node
{
	int to;
	char out;
};
struct Node tran[MAXSTATE][MAXINPUT];
char inp[MAXINPUT],n,m,in;
char s[MAXINPUT],init;
char instream[MAXINPUT];
void getm()
{
	int i,len;
	fgets(s,MAXINPUT,stdin);
	len = strlen(s);
	for(i=5;i<len-1;)
	{
		inp[m] = s[i];
		m += 1;
		i += 2;
	}
}

int gettran()
{
	int i,id,to,out,j;
	char c;
	getchar();
	scanf("%d",&id);
	for(i= 0;i< m;i++)
	{
		c = getchar();
		if (c == '\n')
			{
			init = id;
			return 0;
			}
		c = getchar();
		if(c=='\n' || (j=scanf("%d,%c",&to,&out))== 0)
			{
			init = id;
			return 0;
			}
		tran[id][i].to = to;
		tran[id][i].out = out;	
		//printf("%d %d %c\n",id,to,out);
	}
	while(getchar()!='\n');
	return 1;
}

int geti(char c)
{
	int i;
	for(i=0;i<m;i++)
		if(c == inp[i])
			return i;
	return -1;
}

void outend()
{
	int s,i;
	s = init;
	for(i=0;i<in;i++)
		s = tran[s][geti(instream[i])].to;
	printf("q%d\n",s);
}

void outout()
{
	int s,i,ls;
	s = init;
	for(i=0;i<in;i++)
		{
		ls = s;
		s = tran[s][geti(instream[i])].to;
		printf("%c ",tran[ls][geti(instream[i])].out);
		}
	printf("\n");
}

int main()
{
	int i,temp;
	char c;	
	freopen("dfa.in","r",stdin);
	getm();
	while(gettran() == 1) n += 1;
	//printf("%d\n",init);
	while(1)
	{
		while((c=getchar())==' ');
		if (c == '\n' || c == EOF)
			break;
		instream[in] = c;
		in += 1;
	}
	outend();
	outout();
	return 0;
}
