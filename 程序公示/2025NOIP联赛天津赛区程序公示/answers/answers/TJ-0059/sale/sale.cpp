#include <bits/stdc++.h>
using namespace std;
int c, t, n, m, a[10000], k;
const int mod = 998244353;
int power(int x)
{
	if (x == 0)
	{
		return 1;
	}
	if (x % 2 == 1)
	{
		return 2*power(x/2)%mod*power(x/2)%mod;
	}
	else
	{
		return power(x/2)*power(x/2)%mod;
	}
}
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout); 
	cin >> c >> t;
	for (int i = 1; i <= t; i++)
	{
		int ans = 0;
		cin >> n >> m;
		memset(a, 0, sizeof(a));
		for (int j = 1; j <= n;  j++)
		{
			cin >> a[j];
		}
		sort(a+1, a+n+1, cmp);
		for (int j = 1; j <= n; j++)
		{
			if (a[j]*2 > a[1] && a[j+1]*2 <= a[1])
			{
				k = j;
				break;
			}
		}
		ans = (power(k)-k)%mod;
		ans = ans*power(n-k)%mod;
		cout << ans << endl;
	}
	return 0;
}
