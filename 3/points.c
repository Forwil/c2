#include<stdio.h>
double p[20][2];
double cha(int x1,int y1,int x2,int y2)
{
	return (x1*y2-x2*y1);
}
int main()
{
	int n=0,i;
	double x,y;
	double ans=0;
	while(scanf("%lf%lf",&x,&y)!=EOF)
		{
		p[n][0]=x;
		p[n][1]=y;
	//	printf("%f,%f\n",x,y);
		n++;
		}
	for (i=0;i<n;i++)
		{
		ans=ans+cha(p[i][0],p[i][1],p[(i+1)%n][0],p[(i+1)%n][1]);
		//printf("%.2f\n",ans);
		}
	ans/=2;
	printf("%.2f\n",(ans>=0)?ans:-ans);
	return 0;
}
