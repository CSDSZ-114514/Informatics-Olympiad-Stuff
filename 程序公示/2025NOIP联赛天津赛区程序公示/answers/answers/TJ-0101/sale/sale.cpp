#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[10010];
signed main () {
	freopen ("sale.in", "r", stdin);
	freopen ("sale.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int num = 1;
		for (int i = 1; i <= n; i++) {
			num *= 2;
			num %= 998244353;
		}
		cout << num << endl;
	}
	return 0;
}
