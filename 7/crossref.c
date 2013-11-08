#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXN 510
#define MAXL 22
char words[MAXN][MAXL],ans[MAXN][MAXL+500];
int n,line[MAXN],ansn;

int isc(char c)
{
if (c>='a'&&c<='z' || c>='A' && c<='Z' || c=='-' || c=='\'')
	return 1;
else
	return 0;
}

int iss(char a[])
{
	return (strcmp(a,"a")!=0 && strcmp(a,"an")!=0 && strcmp(a,"and")!=0 && strcmp(a,"the")!=0);
}

int main(void)
{
	int stat = 0,l,i,j,h=0,exist,ll;
	char c,temp[MAXL];
	char *p[MAXN],*tt;
	while((c=getchar())!=EOF)
	{
	if(stat==0)
		{
		if (isc(c))
			{
			words[n][0] = c;
			l = 1;
			}
		}
	else
	if(stat==1)
		{
		if (isc(c))
			{
			words[n][l] = c;
			l += 1;
			}
		else
			{
			if(c>='0' && c<='9')
				{
				stat = isc(c);
				continue;
				}
			words[n][l] = '\0';
			if (iss(words[n]))
				{
				line[n] = h+1;
				n += 1;
				}
			}
		}
	if (c=='\n') h += 1;
	stat = isc(c);
	}
	for(i=0;i<n;i++)
		{
		exist = 0;
		for(j=0;j<i;j++)
			if (strcmp(words[i],words[j])==0)
				exist = 1;
		if (exist==1)
			continue;
		sprintf(ans[ansn],"%s:%d",words[i],line[i]);
		ll = line[i];
		for(j=i+1;j<n;j++)
			if(strcmp(words[i],words[j])==0 && ll!=line[j])
			{
			sprintf(temp,",%d",line[j]);
			strcat(ans[ansn],temp);
			ll = line[j];
			}
		strcat(ans[ansn],"\n");
		ansn += 1;
		}
	for (i=0;i<ansn;i++) p[i] = ans[i];
	for (i=0;i<ansn;i++)
		for(j=i+1;j<ansn;j++)
		if(strcmp(p[i],p[j])>0)
		{
			tt = p[i];
			p[i] = p[j];
			p[j] = tt;
		}
	for (i=0;i<ansn;i++)
		printf("%s",p[i]);
	return 0;
}
