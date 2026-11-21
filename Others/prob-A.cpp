#include <iostream>
#include <vector>
using namespace std;

int fa[500010][30], dep[500010];
int a[500010];
vector <int> e[500010];

void dfs(int u, int father) {
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	
	for(int i = 1; i <= 20; i++) 
	{
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	
	for(int v : e[u]) 
	{
		if(v != father) 
		{
			dfs(v, u);
		}
	}
}

int lca(int u, int v) 
{
	if(dep[u] < dep[v]) 
	{
		swap(u, v);
	}
	for(int i = 20; i >= 0; i--) 
	{
		if(dep[fa[u][i]] >= dep[v]) 
		{
			u = fa[u][i];
		}
	}
	if (u == v) 
	{
		return u;
	}
	for(int i = 20; i >= 0; i--) 
	{
		if(fa[u][i] != fa[v][i]) 
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= q; i++)
	{
		int l, r, u;
		cin >> l >> r >> u;
		int maxn = 0;
		for (int j = l; j <= r; j++)
		{
			maxn = max(maxn, lca(a[j], u));
		}
		cout << maxn << '\n';
	}
	return 0;
}
