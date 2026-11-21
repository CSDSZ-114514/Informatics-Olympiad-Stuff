#include <bits/stdc++.h>
using namespace std;
int n, m, p[5000], nxt[5000][5000], ans, maxn;
bool check()
{
	return true;
}
int main()
{
	/*freopen("tree.in", " r", stdin);
	freopen("tree.out", "w", stdout);*/
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		ans = 0;
		memset(p, 0, sizeof(p));
		memset(nxt, 0, sizeof(nxt));
		cin >> n >> m;
		if (m == 1)
		{
			cout << n+1;
			return 0;
		}
		for (int i = 2; i <= n; i++)
		{
			cin >> p[i];
			nxt[p[i]][i] = 1;
		}
		for (int i = 2; i <= n; i++)
		{
			if (nxt[1][i] == 1)
			{
				int cnt = 0;
				for (int j = 2; j <= n; j++)
				{
					if (i == j)
					{
						continue;
					}
					if (nxt[i][j] == 1)
					{
						cnt++;
					}
				}
				if (cnt == 0)
				{
					ans += 1;
					continue;
				}
				ans += 2+cnt;
				maxn = max(maxn, cnt+2);
			}
		}
		ans += maxn;
		cout << ans;
	}	
	return 0;
} 
