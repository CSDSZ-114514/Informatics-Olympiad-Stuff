#include <iostream>
#include <algorithm>
using namespace std;
long long a[5010];
const int mod = 998244353;
int main()
{
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	int C, T;
	cin >> C >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		int ans = 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			ans = ans * 2 % mod;
		}
		sort(a + 1, a + n + 1);
		cout << ans << endl;
	}
	return 0;
}
