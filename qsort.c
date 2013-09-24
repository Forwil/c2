#include<stdio.h>
int a[2000001];
void qsort(int i,int j)
{
     int x,y,z;
     x=i;y=j;
     z=a[(x+y)/2];
     while(x<=y)
     {
                while(z<a[y]) y--;
                while(z>a[x]) x++;
                if (x<=y)
                {
                         a[0]=a[x];
                         a[x]=a[y];
                         a[y]=a[0];
                         x++;
                         y--;
                }
     }
     if (i<y) qsort(i,y);
     if (x<j) qsort(x,j);
}
int main()
{
    int n,i;
    scanf("%d",&n);
  
    while(n)
    {
            for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
            qsort(1,n);
            for(i=1;i<n;i++)
            printf("%d ",a[i]);
            printf("%d\n",a[n]);
            scanf("%d",&n);
    }

    return 0;
}
