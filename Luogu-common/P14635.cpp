#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, c = 1e18, s[100005], ans;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        c = min(c, x + y);
        s[i] = x;
    }
    sort(s + 1, s + n + 1);
    for (int i = 0; i <= n; i++) {
        m -= s[i];
        if (m <= 0)
            break;
        ans = max(ans, m / c * 2 + i);
    }
    cout << ans;
    return 0;
}
