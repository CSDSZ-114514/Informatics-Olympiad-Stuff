#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MOD = 998244353;
int c, t, n, m, ans, a[5005], w[5005], dp[5005];
struct node
{
	int xjb, id, yj, xj;
};
node x[5005];

bool cmp(node a, node b)
{
	if(a.xjb != b.xjb) return a.xjb > b.xjb;
	if(a.yj != b.yj) return a.yj > b.yj;
	return a.id < b.id;
}
int cal()
{
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + a[i]);
	return dp[m];
}
void dfs(int step)
{
	if(step == n + 1)
	{
		for(int i = 1; i <= n; i++)
		{
			x[i].xjb = a[i] * 2 / w[i];
			x[i].yj = a[i];
			x[i].id = i;
			x[i].xj = w[i];
		}
		sort(x + 1, x + n + 1, cmp);
		int left = m, res = 0, ress = 0;
		for(int i = 1; i <= n; i++)
		{
			if(left == 1 && x[i].xj == 2) continue;
			if(left == 0) break;
			left -= x[i].xj;
			res += x[i].yj;
		}
		ress = cal();
		if(res == ress) ans++;
		return ;
	}
	w[step] = 1;
	dfs(step + 1);
	w[step] = 2;
	dfs(step + 1);
}

int main()
{
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		bool flag = true;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for(int i = 1; i < n; i++)
			if(a[i] != a[i + 1]) flag = false;
		if(flag == true)
		{
			ans = 1;
			for(int i = 1; i <= n; i++) ans = (ans * 2) % MOD;
			cout << ans << endl;
			return 0;
		}
		ans = 0;
		dfs(1);
		cout << ans % MOD << endl;
	}
	return 0;
}
