#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
double eps=1e-6;
int sgn(double x)
{
	return (x>eps)-(x<-eps);
}
struct P
{
	double x,y;
}p[50020],s[50020];
bool operator<(const P&a,const P&b)
{
	if(sgn(a.y-b.y))
		return a.y<b.y;
	return a.x<b.x;
}
int ss,i,n,l;
double xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
void ch()
{
	sort(p,p+n);
	s[0]=p[0];
	s[1]=p[1];
	ss=1;
	for(i=2;i<n;i++)
	{
		while(ss>0&&xm(s[ss-1],s[ss],p[i])<=0)
			ss--;
		s[++ss]=p[i];
	}
	l=ss;
	for(i=n-2;i>=0;i--)
	{
		while(ss>l&&xm(s[ss-1],s[ss],p[i])<=0)
			ss--;
		s[++ss]=p[i];
	}
	l=ss;
}
double RC(P *s,int n)
{
	int i,j,k;
	double ans=0;
	s[n]=s[0];
	for(i=0;i<n;i++)
	{
		for(j=(i+1)%n,k=(i+2)%n;j<n;j++)
		{
			while(xm(s[i],s[j],s[k+1])>xm(s[i],s[j],s[k]))
				k=(k+1)%n;
			ans=max(ans,xm(s[i],s[j],s[k])/2);
		}
	}
	return ans; 
}
int main()
{
	while(scanf("%d",&n),n+1)
	{
		for(i=0;i<n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		ch();
		printf("%.2lf\n",RC(s,l));
	}
	return 0;
}