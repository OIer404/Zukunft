#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<assert.h>
#define fr(i,n) for(int i=0;i<n;i++)
#define fe(i,n) for(auto i=n.begin();i!=n.end();i++)
using namespace std;
//1 dragon
// ��һ����������������ս�������������û��ս�����ͻỶ����
//2 ninja
// ������Ҳ�Ӳ��������ˡ�
//3 iceman
// ÿǰ���������ڵ�2����ɵ�ʱ������ֵ�����9��������������20������������ֵ��9���С�ڵ���0��
//������ֵ����9,���Ǳ�Ϊ1����iceman�������߶��˶�����
//4 lion
// ����ս��������ս��ǰ������ֵ�ͻ�ת�Ƶ��������ϡ�
//5 wolf
// ͨ����������ɱ�����˵Ĵ����ﵽż����ʱ�̣�������1��ʼ�㣩����ս����ɺ󣬸� wolf ����ֵ�͹�����������1����
//�����ɱ���ĵ�����lion,�򹥻���������ֵ�ȼӱ���Ȼ�����ȡlion������ֵ����ȡ�ܲ�������Ԫ�����������ڼӱ�֮��
//ֻ������������ɱ������ʱ�����мӱ������飬����ɱ�������򲻲��ᷢ���ӱ���
int rbo[5]={2,3,4,1,0};
int rbc;
int bbo[5]={3,0,1,2,4};
int bbc;
int rhp;
int bhp;
int nct;
int tmx;
int shp[5];
int sat[5];
char nam[5][20]={"dragon","ninja","iceman","lion","wolf"};
struct sdr
{
	int hp,at,ns,pos;
	sdr(int nt)
	{
		hp=shp[nt];
		at=sat[nt];
		ns=nt;
	}
};
vector<sdr>rls,bls;
int csc,ttt;
int hrs,mns;
int flg[50];
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		printf("Case:%d\n",++ttt);
		scanf("%d %d %d",&rhp,&nct,&tmx);
		bhp=rhp;
		fr(i,5)
			scanf("%d",shp+i);
		fr(i,5)
			scanf("%d",sat+i);
		for(hrs=0;hrs<=tmx;hrs++)
		{
			if(rhp>=shp[rbo[rbc%5]])
			{
				int nt=rbo[rbc%5];
				printf("%03d:00 red %s %d born",nam[nt],rbc);
				rls.push_back(sdr(nt));
				rbc++;
			}
			if(bhp>=shp[bbo[bbc%5]])
			{
				int nt=bbo[bbc%5];
				printf("%03d:00 blue %s %d born",nam[bbo[bbc%5]],bbc);
				bls.push_back(sdr(nt));
				bbc++;
			}
		}
		fe(i,rls)
		{
			
		}
		fe(i,bls)
		end:
	}
	return 0;
}