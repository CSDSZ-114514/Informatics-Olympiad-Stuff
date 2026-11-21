#include<bits/stdc++.h>
using namespace std;

namespace z {
const int N = 5e5 + 5, mod = 998244353;
#define int long long
struct o {
	int x, y, s;
} a[N];
bool cmp(o A, o B) {
	return A.x < B.x;
}
int sum[N];
void main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	int n, m; cin >> n >> m;
	int minn = 2e9;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].s = a[i].x + a[i].y;
		minn = min(minn, a[i].s);
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i].x;
	int ans = 0;
	for(int i = 0; i <= n; i++) if(m >= sum[i]) {
		ans = max(ans, 2 * (m - sum[i]) / minn + i);
	}
	cout << ans << '\n';
}

#undef int

} 

int main() {
	z::main();
	return 0;
}
