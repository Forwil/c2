#include<stdio.h>
#include<string.h>
long long gcd(long long a,long long b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a % b);
}
int main(void)
{
	char s[100];
	int p = 0, cc = 0,i,n;
	long long a = 0,b = 1,c = 0,d = 1,aa = 1,t,ansu,ansd;
	fgets(s,100,stdin);
	n = strlen(s)-1;
	for (i = 0;i<n;++i) if (s[i]=='.') break;
	p = i;
	for (i = 0;i<n;++i) if (s[i]=='_') break;
	cc = i;
	for (i = 0;i<p;++i) a = a*10 + s[i]-'0';
	//printf("%lld,%lld\n",a,b);
	for (i = p+1;i<cc;++i)
	{
		a = a*10 + s[i]-'0';
		b = b*10;
		d = d*10;
	}
	//printf("%lld,%lld\n",a,b);
	if(a!=0&&b!=0)
	{
		t = gcd(a,b);
		a /=t;
		b /=t;
	}
	//printf("%lld,%lld\n",a,b);
	if(c!=0&&d!=0)
	{
		t = gcd(c,d);
		c /=t;
		d /=t;
	}
	//printf("%lld,%lld\n",c,d);
	for (i = cc+1;i<n;++i)
	{
		c = c*10 + s[i]-'0';
		d = d*10;
		aa = aa * 10;
	}
	//printf("%lld,%lld\n",c,d);
	if(aa!=1)
	{
		c = c *aa;
		d = d *(aa-1);	
	}
	//printf("%lld,%lld\n",c,d);
	if(c!=0&&d!=0)
	{
		t = gcd(c,d);
		c /=t;
		d /=t;
	}
	ansd = b*d;
	ansu = a*d+b*c;
	if(ansd!=0&&ansu!=0)
	{
		t = gcd(ansu,ansd);
		ansu /= t;
		ansd /= t;
	}
	printf("%lld/%lld\n",ansu,ansd);
	return 0;
}
