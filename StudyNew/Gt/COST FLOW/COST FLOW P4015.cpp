#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Node
{
	int u, v, w, c;
};

int n, m, s, t;
bool vis[320];
int mf[320];
int d[320];
int pre[320];
int a[110], b[110];
int c[110][110];

vector <Node> e;
vector <int> h[310];

void add(int u, int v, int w, int c)
{
	e.push_back({u, v, w, c});
	h[u].push_back(e.size() - 1);
	e.push_back({v, u, 0, -c});
	h[v].push_back(e.size() - 1);
}

void sofa()
{
	memset(d, 0x3f, sizeof(d));
	memset(mf, 0, sizeof(mf));
	memset(vis, false, sizeof(vis));
	d[s] = 0;
	mf[s] = 1e9;
	
}

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
		}
	}
	s = 0;
	t = n + m + 1;
	for (int i = 1; i <= m; i++)
	{
		add(s, i, a[i], 0);
	}
	for (int i = n + 1; i <= n + m; i++)
	{
		add(i, t, b[i], 0);
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = n + 1; j <= n + m; j++)
		{
			add(i, j, a[i], c[i][j]);
		}
	}
	
	
	return 0;
}