#include<stdio.h>
main()
{
int h,m,s;
float ha,ma,dt;
scanf("%d:%d:%d",&h,&m,&s);
if (h>=12) h-=12;
ha=h + (float) m/60;
ma=(m+ (float) s/60)/5;
ha=ha+ (float) s/3600;
dt=(ha>ma)? ha-ma:ma-ha;
//printf("\n%.3f \n",dt);
if (dt>6) dt=12-dt;
 printf("%.3f",dt*30);  
}
