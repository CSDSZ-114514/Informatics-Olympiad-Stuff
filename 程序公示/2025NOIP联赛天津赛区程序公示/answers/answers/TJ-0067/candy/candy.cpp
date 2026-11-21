#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6+5;

int n, m;
vector<int> a, c;
int dp[N];
int ans;
bool flag_A;

signed main() {
	flag_A = 1;
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		if (x != y) flag_A = 0;
		a.push_back(x+y);
		c.push_back(x);
	}
	if (flag_A) {
		sort(c.begin(), c.end());
		cout << m / c[0];
		return 0;
	}
	
	sort(a.begin(), a.end());
	sort(c.begin(), c.end());
	
	int k = lower_bound(c.begin(), c.end(), a[0]) - c.begin() - 1;
	
	for(int i = 0; i <= k; i++) {
		for(int j = m; j >= c[i]; j--) {
			dp[j] = max(dp[j], dp[j - c[i]] + 1);
		}
	}

	for(int i = 0; i <= m; i++) {
		ans = max(ans, dp[i] + (m - i) / a[0] * 2);
	}
	
	cout << ans;
	return 0;
}
