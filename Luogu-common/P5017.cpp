#include <bits/stdc++.h>
using namespace std;
long long n, m, cnt[10000005], sum[10000005], f[1000005], q[1000005];
double slope(int i, int j) {
	return 1.0 * (f[i]+sum[i] - (f[j]+sum[j]))/((cnt[i]-cnt[j])==0?1e-9:(cnt[i]-cnt[j]));
}
int main() {
    cin >> n >> m;
    long long last = -1e9;
    for (int i = 1; i <= n; i++) {
        long long a = 0;
        cin >> a;
        cnt[a]++;
        sum[a] += a;
        last = max(a, last);
    }
    for (int i = 1; i < last + m; i++) {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i < m; i++) {
        f[i] = cnt[i] * i - sum[i];
    }
    long long h = 1, t = 0, ans = 1e9;
    for (int i = m ; i < m + last; i++) {
        while (h < t && slope(i - m, q[t]) <= slope(q[t], q[t - 1])) {
            t--;
        }
        q[++t] = i - m;
        while (h < t && slope(q[h + 1], q[h]) <= i) {
            h++;
        }
        int j = q[h];
        f[i] = f[j] + (cnt[i] - cnt[j]) * i - (sum[i] - sum[j]);
        if (i >= last) {
            ans = min(ans, f[i]);
        }
    }

    cout << ans;
}