#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int x[100010], y[100010], c[100010];
signed main () {
	freopen ("candy.in", "r", stdin);
	freopen ("candy.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n, m;
	cin >> n >> m;
	int z = m;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		c[i] = x[i] + y[i];
	}
	sort (c + 1, c + n + 1);
	sort (x + 1, x + n + 1);
	int num = 0;
	for (int i = 0; i < n; i++) {
		int cs = 1, kum = 0;
		z = m;
		z -= i * c[cs];
		while (1) {
			if (z >= c[cs] && z > 0) {
				kum += 2;
				z -= c[cs];
			} else {
				break;
			}
		}
		z += i * c[cs];
		while (1) {
			if (z >= x[cs] && cs <= n) {
				kum += 1;
				z -= x[cs];
				cs++;
			} else {
				break;
			}
		}
		if (kum > num) {
			num = kum;
		}
	}
	cout << num;
	return 0;
}
