#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int p[8010], a[8010];
bool f[8010];
vector<int> g[8010];
int ans;
void dfs(int x)
{
	if (g[x].size() == 0)
	{
		if (f[p[x]] == false)
		{
			f[p[x]] = true;
			a[x] = 0;
			ans++;
		}
		else a[x] = a[p[x]];
		return;
	}
	for (int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		dfs(y);
		a[x] = max(a[x], a[y] + 1);
	}
	ans += (a[x] + 1);
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		memset(f, false, sizeof(f));
		memset(a, 0, sizeof(a));
		ans = 0;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 2; i <= n; i++)
		{
			cin >> p[i];
			g[p[i]].push_back(i);
		}
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
