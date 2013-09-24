//
//  main.c
//  sinedegree
//
//  Created by 冠扬 薛 on 12-4-18.
//  Copyright (c) 2012年 BUAA. All rights reserved.
//

#include <stdio.h>
int main(int argc, const char * argv[])
{
    long double a;
    long double e,b,d;
    int i,f;
    long long c;
    f=1;
    scanf("%Lf",&a);
    while(a<0)
    {
        a=a+360;
    }
    while(a>=360)
    {
        a=a-360;
    }
    switch ((int)(a/90))
    {
        case 0:
            f=1;
            break;
        case 1:
            a=180-a;
            f=1;
            break;
        case 2:
            a=a-180;
            f=-1;
            break;
        case 3:
            a=360-a;
            f=-1;
            break;
    }
    switch ((int)(a/45))
    {
        case 0:
            e=a*0.017453292519943;
            d=e*e;
            b=e;
            c=1;
            for (i=1;i<=5;i++)
            {
                e=e*d;
                c=c*(4*i-2)*(4*i-1);
                b=b-e/c;
                e=e*d;
                c=c*(4*i)*(4*i+1);
                b=b+e/c;
            }
            break;
        case 1:
            a=90-a;
            e=a*0.017453292519943;
            d=e*e;
            e=1;
            b=1;
            c=1;
            for (i=1;i<=5;i++)
            {
                e=e*d;
                c=c*(4*i-3)*(4*i-2);
                b=b-e/c;
                e=e*d;
                c=c*(4*i-1)*(4*i);
                b=b+e/c;
            }
            break;
    }
    b=b*f;
    printf("%.6Lf",b);
    return 0;
}

