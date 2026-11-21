#include <bits/stdc++.h>
using namespace std;
long long n, a[1000005], b[1000005], d[100005];
int main() {
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        long long s;
        char p;
        cin >> s >> p;
        if (p == 'R') {
            a[i] = a[i - 1] + s;
        } else {
            a[i] = a[i - 1] - s;
        }
    }
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
    }
    sort(b, b + n + 1);
    long long m = unique(b, b + n + 1) - b;
    for (int i = 1; i <= n; i++) {
        long long l = lower_bound(b , b + m, a[i - 1]) - b;
        long long r = lower_bound(b , b + m, a[i]) - b;
        if (l > r) {
            swap(l, r);
        }
        d[l]++;
        d[r]--;
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        if (d[i - 1] >= 2) {
            ans += b[i] - b[i - 1];
        }
        d[i] += d[i - 1];
    }
    cout << ans;
}