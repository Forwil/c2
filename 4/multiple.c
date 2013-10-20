#include<stdio.h>
#define LEN 1 
#define MAXN 100000
int z[MAXN],p[MAXN];
int n,m,nnum,num[MAXN],in[11],maxv;
int tom(int x)
{
	int r=0,b=1,i;
	for(i=0;i<LEN;i++)
	{
		r+=b*(in[x%m]);
		x/=m;
		b=b*10;
	}
	return r;
}

void generate()
{
	int i,b=1;
	maxv=1;
	for(i=0;i<LEN;i++){ b=b*m;maxv*=10;}
	nnum=b;
	for(i=0;i<b;i++) num[i]=tom(i);
}
int can(int x)
{
	int t=0,zero=1,b=1;
	while(x!=0)
	{
	if (z[x]!=0) zero=0;
	t=(t+b*z[x])%n;
	b=b*maxv % n;
	x=p[x];
	}
	if (t==0 && zero==0) return 1;
	else return 0;
}
int dfs()
{
	int t,w,i;
	t=-1;
	w=0;
	z[t]=num[0];
	while(t<w)
	{
		t=t+1;
		for(i=0;i<nnum;i++)
		{
			//printf("%d:%d ",w+1,num[i]);
			w=w+1;
			z[w]=num[i];
			p[w]=t;
			if (can(w)) return w;
		}
	if (w>=MAXN) return 0;
	}
	return 0;
}
void output(int x)
{
	int i;
//	printf("%d %d\n",x,z[x]);
	if (p[x]==0)
	{
		printf("%d",z[x]);
	}
	else
	{
		output(p[x]);
		printf("%0*d",LEN,z[x]);
	}
}
int main()
{
	int i,j,temp,t,w;
	freopen("multiple.in","r",stdin);
	freopen("multiple.out","w",stdout);
	scanf("%d",&n);
	i=0;
	while(scanf("%d",&in[i++])!=EOF);
	m=i-1;
	if(m==0)
		{
		printf("0\n");
		return 0;
		}
	for(i=0;i<m;i++)
		for(j=i+1;j<m;j++)
			if(in[i]>in[j])
			{
				temp=in[i];
				in[i]=in[j];
				in[j]=temp;
			}
	//printf("%d\n\n",m);
	//for(i=0;i<m;i++) printf("%d\n",in[i]);
	generate();
	//for(i=0;i<nnum;i++)printf("%d ",num[i]);
//	printf("\n%d",tom(0));
	temp=dfs();
	//for(i=0;i<temp;i++)printf("%d:%d ",i,z[i]);
	if(temp==0) printf("0");
	else
	output(temp);
	printf("\n");
	return 0;
}
