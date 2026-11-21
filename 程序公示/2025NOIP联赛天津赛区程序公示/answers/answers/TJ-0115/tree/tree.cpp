// stosto pingceji orzorz
// buyao WA TLE RE a
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),END##i=(b);i<=END##i;++i)
#define pre(i,a,b) for(int i=(a),END##i=(b);i>=END##i;--i)
using namespace std;
typedef long long ll;
// Problem: tree
const int N = 8005;
int T, n, a[N], ans, fans; vector<int> g[N]; bitset<N> b[N];
void getans(int u, int fa)
{
	b[u][a[u]] = 1;
	for (auto v : g[u])
	{
//		if (v == fa) continue;
		getans(v, u);
		b[u] |= b[v];
	}
	rep(i, 0, n) if (!b[u][i]) { ans += i; break; }
}
void dfs(int x)
{
	if (x > n)
	{
		ans = 0;
		rep(i, 1, n) b[i] = 0;
		getans(1, 0);
		fans = max(fans, ans);
		return;
	}
	rep(i, 0, n - 1)
	{
		a[x] = i;
		dfs(x + 1);
	}
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &T);
	while (T --)
	{
	fans = 0;
	rep(i, 1, n) g[i].clear();
	scanf("%d%*d", &n);
	rep(i, 2, n)
	{
		int f; scanf("%d", &f);
		g[f].push_back(i);
//		g[i].push_back(f);
	}
	dfs(1);
	printf("%d\n", fans);
	}
	return 0;
}

