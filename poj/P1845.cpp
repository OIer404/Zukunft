#include<stdio.h>
#include<math.h>
#include<string.h>
long long a[20];
long long b[20];
long long f[10000];
int i,j,k=0;
long long c,d;
long long n,x,y,z;
long long fs,sum,ans;
int sqrt(long long x)
{
	return (int)sqrt((double)x);
}
void exgcd(long long a,long long b,long long &d,long long &x,long long &y)//��չGCD d=gcd(a,b) ���a��bʹax+by=d��
{
	if(b==0)
	{
		d=a;
		x=1;
		y=0;
		return;
	}
	long long xx,yy,dd;
	exgcd(b,a%b,dd,xx,yy);
	d=dd;
	x=yy;
	y=xx-yy*(a/b);
	return;
}
int mod(int a,int b)//������ a��b�η�mod 9901��
{
	int i,r=1,y=a%9901;
	while(b)
	{
		if(b&1)
			r*=y;
		r%=9901;
		y*=y;
		y%=9901;
		b>>=1;
	}
	return r;
}
int main()
{
	scanf("%I64d %I64d",&c,&d);//�ֽ�������a[]Ϊ�ף�b[]Ϊָ��
	for(i=2;i<=sqrt(c);i++)
	{
		if(c%i==0)
		{
			a[k]=i;
			while(c%i==0)
			{
				b[k]++;
				c/=i;
			}
			k++;
		}
	}
	if(c!=1)
	{
		a[k]=c,b[k]=1;
		k++;
	}
	ans=1;//�ֽ��������ꣻ
	/*
	����ֻ����ans���γ���a[i]��(b[i]*d+1)����(a[i]-1)���ɣ�
	��������������
	���((a[i]-1)mod 9901=0)
	����ζ������ȱ����е�ÿһ��mod 9901 ֮����1ֻ����ans=ans*(b[i]*d+1)mod 9901;����
	���((a[i]-1)mod 9901<>0)
	������(a[i]-1)����9901�ĳ˷���Ԫx��
	�˷���Ԫ��ָ����ʹ(a[i]-1)*x mod 9901=0��x��
	���(a[i]-1)��9901���ʣ�
	��ôx��1��9900֮��ֻ��һ������������
	��˷���Ԫ����չŷ�����
	ʹ�ó˷���ԪҲ�ܼ򵥣����籾����Ҫ����(a[i]-1)��ֻ�����(a[i]-1)�ĳ˷���Ԫx���ɡ�
	*/
	for(i=0;i<k;i++)//����ÿ������
	{
		if((a[i]-1)%9901==0)//��һ�����
			ans=ans*(b[i]*d+1)%9901;
		else
		{
			ans=ans*(mod(a[i],(b[i]*d+1)%9900)-1)%9901;//���ԵȲ����еķ���
			exgcd(a[i]-1,9901,z,x,y);//��˷���Ԫ
			ans=ans*x%9901;//����ȥ
		}
	}
	printf("%I64d\n",(ans+9901)%9901);
	return 0;
}
/*



__int64 sum(__int64 p,__int64 n)//��1+p+p^2+...+p^n;
{
	if(n==0)
		return 1;
	if(n&1)//ż����
		return (((1+pow(p,n/2+1))%mod)*(sum(p,n/2)%mod))% mod;
	else//������
		return (((1+pow(p,n/2+1))%mod)*(sum(p,(n-1)/2)%mod)+pow(p,n/2)%mod)%mod;
}


*/