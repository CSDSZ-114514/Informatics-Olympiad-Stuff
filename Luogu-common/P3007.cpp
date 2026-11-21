#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector <int> e[2010];
bool vs[2010];
bool f[2010];
bool flag = false;

void dfs(int i)
{
	for (int v : e[i])
	{
		if (!vs[v])
		{
			vs[v] = true;
			dfs(v);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		char a, b;
		cin >> u >> a >> v >> b;
		int c, d;
		if (a == 'Y')
		{
			c = 1;
		}
		else
		{
			c = 0;
		}
		if (b == 'Y')
		{
			d = 1;
		}
		else
		{
			d = 0;
		}
		e[u + !c * n].push_back(v + d * n);
		e[v + !d * n].push_back(u + c * n);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(vs, false, sizeof(vs));
		dfs(i);
		f[i] = vs[i + n];
		memset(vs, false, sizeof(vs));
		flag = false;
		dfs(i + n);
		f[i + n] = vs[i];
		if (f[i] && f[i + n])
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!f[i] && !f[i + n])
		{
			cout << '?';
		}
		else if (f[i])
		{
			cout << 'Y';
		}
		else
		{
			cout << 'N';
		}
	}
	return 0;
}