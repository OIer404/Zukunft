#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
struct P
{
	int x,y;
	bool operator<(const P&a)const
	{
		return y<a.y||y==a.y&&x<a.x;
	};
}p[50020],s[50020];
int ss,i,n,m,l;
double ans;
int xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int dis(P a,P b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
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
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d %d",&p[i].x,&p[i].y);
	ch();
	s[ss+1]=s[0];
	for(i=0;i<=ss;i++)
		ans+=sqrt((double)dis(s[i],s[i+1]));
	printf("%.0lf\n",ans+2*3.1415926535*m);
	return 0;
}