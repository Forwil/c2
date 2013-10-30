#include<stdio.h>
int count[26],tot,p[26];
void ton(char c)
{
	if (c >= 'a' && c <= 'z') count[c-'a']+=1;
	if (c >= 'A' && c <= 'Z') count[c-'A']+=1;
}
void swap(int *a,int *b)
{
	int i;
	i=*a;
	*a=*b;
	*b=i;
}
int main(void)
{
	char c;
	int i,j,temp;
	freopen("freq.in","r",stdin);
	freopen("freq.out","w",stdout);
	while((c=getchar())!=EOF) ton(c);
	for (i=0;i<26;i++) 
		{
			p[i]=i;
			tot+=count[i];
		}
	for (i=0;i<26;i++)
	for (j=i+1;j<26;j++)
	if (count[i]<count[j] || (count[i]==count[j]&& p[j]<p[i]))
		{
		swap(&count[i],&count[j]);
		swap(&p[i],&p[j]);
		}
	for(i=0;i<10 ||(count[i]==count[i-1] && i<26);i++)
	printf("%c%d ",p[i]+'a',count[i]);
	printf("\n%d\n",tot);
	return 0;
}
