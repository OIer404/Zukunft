#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[50020]; // ����
int s[50020]; // s[x]Ϊx�����Ĵ�С
int f[50020]; 
void dfs(int x, int y) {
	s[x] = 1;
	// x�����ڲ��ĵ㵽x����֮�͡�
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i] != y) {
			dfs(a[x][i], x);
			s[x] += s[a[x][i]]; // �ݹ����x�����Ĵ�С 
			f[x] += f[a[x][i]] + s[a[x][i]];
			// x�����ڲ��ĵ㵽x����֮�͡�
			// a[x][i]�����ڲ�ÿ���㣬��x�ľ���ȵ�a[x][i]�ľ����1
			// ���Թ����� a[x][i]�����ڲ�ÿ���㵽a[x][i] ���� s[a[x][i]] 
		}
	}
}
void sfd(int x, int y) {
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i] != y) {
			// f[x] x�Ĵ�
			// -(f[a[x][i]] + s[a[x][i]])  ɾȥa[x][i]��������
			// (n - s[a[x][i]]) Ϊa[x][i]���׷����size
			// x�Ĵ𰸣���ȥa[x][i]�������ֵ�Ӱ�죬����a[x][i]���׷����size
			f[a[x][i]] += f[x] - (f[a[x][i]] + s[a[x][i]]) + (n - s[a[x][i]]);
			// ����f[a[x][i]]Ϊ���е㵽a[x][i]�ľ���֮�� 
			sfd(a[x][i], x);
			// �ݹ鴦��ÿ������ 
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[y].push_back(x);
		a[x].push_back(y);
	}
	dfs(1, 0);
	// ����dfs��f[1]�������е㵽1�ľ����� 
	// ���Ƕ���������i��f[i]ֻ������i�����ڵ�i�����
	// û�п���i�ĸ��׽ڵ㷽��i����� 
	// sfd����ÿ���㸸�׽ڵ㷽��i����� 
	sfd(1, 0);
	int ans = 1;
	// ans��ʼ��Ϊ1
	for (int i = 1; i <= n; i++) {
		if (f[ans] > f[i]) {
			// ���i��ans���ã���ô���� 
			ans = i;
		}
	}
	cout << ans << ' ' << f[ans] << endl;
	return 0;
}