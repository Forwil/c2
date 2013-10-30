#include<stdio.h>
int table[10][10];
int h[10][10],s[10][10],o[10][10];

void output()
{
	int i,j;
	for(i=1;i<10;i++)
		{
		for(j=1;j<10;j++) printf("%d",table[i][j]);
		printf("\n");
		}
	return ;
}

int getspc(int x, int y)
{
	return ((x-1)/3*3 + (y-1)/3 + 1);
}

int set(int x,int y,int v,int flag)
{
	h[x][v] = flag;
	s[y][v] = flag;
	o[getspc(x,y)][v] = flag;
	if(flag == 0)
		table[x][y] = 0;
	else
		table[x][y] = v;
}

int canset(int x, int y ,int v)
{
	return (h[x][v]==0 && s[y][v]==0 && o[getspc(x,y)][v]==0);
}

int getnum(int x,int y)
{
	int i,k,count=0;
	for(i=1;i<10;i++)
	if(canset(x,y,i))
		count += 1;
	return count;
}

int getmin(int *x,int *y)
{
	int i,j,k,min=20,c;
	for(i=1;i<10;i++)
		for(j=1;j<10;j++)
		if(table[i][j] == 0)
			{
			c = getnum(i,j);
			if(c < min)
				{
				min = c;
				*x = i;
				*y = j;
				}
			}
	if(min != 20)
		return 1;
	else 
		return 0;
}

int go()
{
	int x,y,k;
	if(getmin(&x,&y) == 1)
		{
		for(k=1;k<10;k++)
		if(canset(x,y,k))
			{
			set(x,y,k,1);
			go();
			set(x,y,k,0);
			}
		}
	else
		output();
}
int main(void)
{
	int i,j;
	char s[20];
	freopen("shudu.in","r",stdin);
	freopen("shudu.out","w",stdout);
	for(i=1;i<10;i++)
		{
		scanf("%s",s);
		for(j=1;j<10;j++)
			{
			table[i][j]=s[j-1]-'0';
			if(table[i][j] != 0)
				set(i,j,table[i][j],1);
			}
		}
	go();
	return 0;
}
