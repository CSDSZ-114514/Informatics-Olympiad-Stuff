#include <bits/stdc++.h>
using namespace std;
int n, m, x[10001], y[10001], f[100001], ans; 

int main()
{
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	long long w, t;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		y[i]+=x[i];
	}
	for (int i = 1; i <= n; i++)
	{
		/*for (int j = m; j >= 0; j--)
		{
			w = 0;
			for (int k = 0; k <= m; k++)
			{
				if (k % 2 == 0)
				{
					w = (x[i]+y[i])*k/2;
				}
				else
				{
					w = x[i]*(k+1)/2+y[i]*(k-1)/2;
				}
				if (w > j)
				{
					break;
				}
				f[j] = max(f[j], f[j-w]+k);
			}
			ans = max(ans, f[j]);
		}*/
		for (int j = m; j >= x[i]; j--)
		{
			f[j] = max(f[j], f[j-x[i]]+1);
			ans = max(ans, f[j]);
		}
		for (int j = y[i]; j <= m; j++)
		{
			f[j] = max(f[j], f[j-y[i]]+2);
			ans = max(ans, f[j]);
		}
	}
	cout << ans;
	return 0;
 } 
