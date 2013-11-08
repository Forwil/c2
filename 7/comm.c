#include<stdio.h>
#include<string.h>
#define MAXN 51
#define MAXL 300
FILE *fp1,*fp2;
char l1[MAXN][MAXL],l2[MAXN][MAXL];
int cmp(char a[],char b[])
{
	int i=0,aa,bb;
	aa = strlen(a);
	bb = strlen(b);
	for (i=0;i<aa;++i)
		if(a[i]<b[i]) return 1;
		else
		if(a[i]>b[i]) return -1;
		else
		if(a[i]=='\n'&&b[i]=='\n')	return 0;
}
int main()
{
	char f1[MAXL],f2[MAXL];
	int len1=0,len2=0,t1=0,t2=0,k;
	freopen("comm.in","r",stdin);
	freopen("comm.out","w",stdout);
	scanf("%s%s",f1,f2);
	fp1 = fopen(f1,"r");
	while(fgets(l1[len1],MAXL,fp1)!=NULL && strlen(l1[len1])>1) len1 += 1;
	fp2 = fopen(f2,"r");
	while(fgets(l2[len2],MAXL,fp2)!=NULL && strlen(l2[len2])>1) len2 += 1;
	//printf("%d %d\n",len1,len2);	
	while(t1<len1||t2<len2)
	{
		if(t1<len1)
			{
			if(t2>=len2)
				{
					printf("%s",l1[t1]);
					t1 += 1;
				}
			else
				{
					k = cmp(l1[t1],l2[t2]);
					if (k==0)
						{
						printf("\t\t%s",l1[t1]);
						t1 += 1; t2 += 1;
						}
					else if(k==1)
						{
						printf("%s",l1[t1]);
						t1 += 1;
						}
					else
						{
						printf("\t%s",l2[t2]);
						t2 += 1;
						}
				}
			}
		else
		{
			printf("\t%s",l2[t2]);
			t2 += 1;
		}
	}
	return 0;
}
