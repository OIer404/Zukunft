/*
��ǰֻ��������LCA(��󹫹�������)�Ĵ�С,�������Ҫ�����е�LCA��,�Ҳ������ظ���,��ͷ�����.����
n�ó�����n�ְ취��WA.���ֻ��ȥ���Ͽ���ǰ���ǵĽ��ⱨ����,������һ����ⱨ��һֱû���ҵ�,�ѹ�
����AC������ô��.����n������ҵ����CEOI 2003�Ľ��ⱨ�棬����֮��Ż�Ȼ����.������Ҳ������ô
�������������.
(1)���ȷֱ�����������봮��loc[i][j].str1 ��loc[i][j]��ʾ��str1��λ��λ��i�Լ���֮ǰ���Ҿ���i��
������ĸj��λ��,����Եõ�
loc[i][j] = i�� str[i] == j;
            loc[i - 1][j]�� str[i] != j
(2)������Ҫ�����봮����һ��LCA,��LCA[i][j]��ʾ������str1[1...i]��str2[1...j]��LCA�ĳ���
 LCA[i][j] = LCA[i - 1][j - 1], �� str1[i] == str2[j];
             max(LCA[i - 1][j], LCA[i][j - 1]), �� str1[i] != str2[j]
(2)Ȼ�����������ĩβ����,���赱ǰ������������λ�÷ֱ�Ϊn,m
 ��ô
 (1)���str1[n] == str2[m],�򽫵�ǰ�ַ�str1[n]�������ַ���res,ͬʱn,m��λ�÷ֱ���ǰ�ƽ�1��Ϊn - 1, m - 1
 (2)���str1[n] != str2[m],��������е�26����ĸ���ҵ�LCA[loc1[n][k], loc2[m][k]]������Щk��λ�ã�
    ����ǰ�ƽ�����n, m�ֱ����Ϊloc1[n][k], loc2[m][k]
ͨ����һ���LCA����ʶ��������һ��,����ѧϰing
*/
#include <iostream>
#include <string>
#include <algorithm>
#define MAX_N 10005
#define MAX_LEN 100
#define maxv(a, b) ((a) >= (b) ? (a) : (b))
using namespace std;
struct str
{
    string seq;
}strs[MAX_N + 1];
int n, maxLen;
string str1, str2;
int len1, len2;
int lcs[MAX_LEN + 1][MAX_LEN + 1];
int loc1[MAX_LEN + 1][27];
int loc2[MAX_LEN + 1][27];
//����loc
void getLoc(string str, int loc[][27])
{
    int i, j, len = str.length();
    memset(loc, 0, sizeof(loc));
    for(i = 1; i <= len; i++) 
    {
        for(j = 1; j <= 26; j++)
        {
            if(str[i - 1] - 'a' + 1 == j)
                loc[i][j] = i;
            else
            {
                if(loc[i - 1][j] == 0) continue;
                loc[i][j] = loc[i - 1][j];
            }
        }
    }
}
//����LCS
void getLCS()
{
    int i, j;
    memset(lcs, 0xbf, sizeof(lcs));
    for(i = 0; i <= maxv(len1, len2); i++) lcs[i][0] = lcs[0][i] = 0;
    for(i = 1; i <= len1; i++)
    {
        for(j = 1; j <= len2; j++)
        {
            if(str1[i - 1] == str2[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
            {
                if(lcs[i - 1][j] > lcs[i][j - 1]) lcs[i][j] = lcs[i - 1][j];
                else if(lcs[i - 1][j] < lcs[i][j - 1]) lcs[i][j] = lcs[i][j - 1];
                else lcs[i][j] = lcs[i][j - 1];
            }
        }
    }
}
//������
void solve(int p1, int p2, string res)
{
    //����ͷ������Ҫ����ǰ��res�������ַ�������
    if(p1 == -1 || p2 == -1)
    {
        strs[n++].seq = res;
        return;
    }
    //����ǰλ�õ������ַ���ͬʱ,������ַ��������ַ���,����ǰ�ƽ�
    if(str1[p1] == str2[p2]) 
    {
        solve(p1 - 1, p2 - 1, str1[p1] + res);
    }
    else
    {
        //������Ҫ�ҵ���������(���)��LCAֵ��ǰ��λ��
        int maxV = INT_MIN, maxP1, maxP2, i;
        //Ѱ�����ֵmaxV
        for(i = 1; i <= 26; i++)
        {
                        
            int pp1 = loc1[p1 + 1][i], pp2 = loc2[p2 + 1][i];
            //�����ڵ�ǰλ�÷�����ѭ��
            if(pp1 - 1 == p1 && pp2 - 1 == p2) continue;
            if(lcs[pp1][pp2] > maxV)
            {
                maxV = lcs[pp1][pp2];
                maxP1 = pp1;
                maxP2 = pp2;
            }
        }
        //���ҵ�����Щ���ֵ������ǰ�ƽ�
        for(i = 1; i <= 26; i++)
        {
            int pp1 = loc1[p1 + 1][i], pp2 = loc2[p2 + 1][i];
            if(pp1 - 1 == p1 && pp2 - 1 == p2) continue;
            if(lcs[pp1][pp2] == maxV)
                solve(pp1 - 1, pp2 - 1, res);
        }
    }
}
bool compare(const str &s1, const str &s2)
{
    return s1.seq <= s2.seq;
}
int main()
{
    cin>>str1>>str2;
    maxLen = INT_MIN;
    n = 0;
    len1 = str1.length(); len2 = str2.length();
    string res = "";
    getLoc(str1, loc1);
    getLoc(str2, loc2);
    getLCS();
        
    solve(len1 - 1, len2 - 1, res);
    sort(strs, strs + n, compare);
    for(int i = 0; i < n; i++)
    {
        cout<<strs[i].seq<<endl;
        res = strs[i].seq;
    }
    return 0;
}

/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[111],b[111];
int c[111][111];
int d[111][111],xyz;
char ans[10000][111];
char s[111];
int m,n;
int cmp(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}
void dfs(int x,int y,int l)
{
	int i;
	if(l<=0)
	{
		for(i=0;i<xyz;i++)
			if(strcmp(ans[i],s+1)==0)
				return;
		memcpy(ans[xyz++],s+1,c[m-1][n-1]);
		return;
	}
	if(x<0||y<0)
		return;
	if(d[x][y]==4)
	{
		s[l]=a[x];
		dfs(x-1,y-1,l-1);
		s[l]=0;
	}
	if(d[x][y]==3||d[x][y]==1)
		dfs(x-1,y,l);
	if(d[x][y]==3||d[x][y]==2)
		dfs(x,y-1,l);
	return;
}
int main()
{

	int i,j,k;
	scanf("%s %s",a,b);
	m=strlen(a);
	n=strlen(b);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				d[i][j]=4;
			}
			else
			{
				if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					d[i][j]+=1;
				}
				if(c[i-1][j]<=c[i][j-1])
				{
					c[i][j]=c[i][j-1];
					d[i][j]+=2;
				}
			}
		}
	dfs(m-1,n-1,c[m-1][n-1]);
	qsort(ans,xyz,111,cmp);
	for(i=0;i<xyz;i++)
		if(strcmp(ans[i],ans[i+1])==0)
			continue;
		else
			printf("%s\n",ans[i]);
	printf("%d\n",xyz);
	return 0;
}*/