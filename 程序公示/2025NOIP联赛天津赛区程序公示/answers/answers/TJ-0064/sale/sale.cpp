#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector<int64_t> price;
int c, t;
int64_t mod = 998244353;
int main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t) {
		t--;
		cin >> n >> m;
		bool speA = true;
		price.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> price[i];
			if (i != 0 && price[i] != price[i - 1]) {
				speA = false;
			}
		}
		//cout << n << endl;
		if (speA) {
			int64_t ans = 1;
			for (int i = 1; i <= n; i++) {
				ans = (ans * 2) % mod;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
