#include<stdio.h>
#include<string.h>
#define MAXN 202
int  a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN];
int len(int  x)
{
	int  i=1;
	while(x/=10) i++;
	return i;
}
void readargument(int a[][MAXN],int *m,int *n){
	int i,j,temp,l;
	char s[1000];
	*m=0;
	while(fgets(s,1000,stdin)!=NULL&&(l=strlen(s))>1){
		*n=0;
		for(i=0;i<strlen(s);i++){
			if(s[i]>='0'&&s[i]<='9'){
				temp=0;
				for(j=i;i<=strlen(s);j++){
					if(s[j]>='0'&&s[j]<='9')
						temp=temp*10+s[j]-'0';
					else{
						a[*m][*n]=temp;
						(*n)++;
						i=j;
						break;
					}
				}
			}
		}
		(*m)++;
	}
	return;
}
int main()
{
	int n,m,k,i,j,l,maxl=0;
	char cc,s[1000];
	freopen("arr.in","r",stdin);
	
	readargument(a,&n,&m);
	readargument(b,&m,&k);
	for(i=0;i<n;i++)
		for(j=0;j<k;j++)
		{
			c[i][j]=0;
			for(l=0;l<m;l++)
				c[i][j]+=a[i][l]*b[l][j];
			if (maxl<len(c[i][j]))
				maxl=len(c[i][j]);
		}
	for(i=0;i<n;i++)
		for(j=0;j<k;j++)
			{
				//printf("%*d",maxl+1,c[i][j]);
				printf("%d ",c[i][j]);
				if (j==k-1)printf("\n");
			}
	return 0;
}
