#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e4+5;

int n, q;
int a[N];
int pre[N];

int ans;

signed main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i-1] + a[i];
	}
	cin >> q;
	while (q--) {
		int L, R;
		cin >> L >> R;
		ans = 0;
		for(int i = 1; i <= n; i++) {
			int res = -0x3f3f3f3f;
			for(int l = 1; l <= i; l++) {
				for(int r = max(i, L + l - 1); r <= min(n, R + l - 1); r++) {
					res = max(res, pre[r] - pre[l-1]);
				}
			}
//			printf("%lld %lld\n", i, res);
			ans = ans ^ (res * i);
		}
		cout << (unsigned long long)ans << endl;
	}
	return 0;
}
