#include <bits/stdc++.h>
using namespace std;
long long n, k, f[30000005], cnt;
long long isqrt(long long n) {
    long long r = (long long)sqrtl((long double)n);
    while ((__int128)(r + 1) * (r + 1) <= n)
        ++r;
    while ((__int128)r * r > n)
        --r;
    return r;
}
int main() {
    cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return 0;
    }
    if (k == 2) {
        long long ans = isqrt(n);
        for (unsigned long long a = 2; a * a * a <= n; a++) {
            unsigned long long x = a * a;
            for (unsigned long long b = 3; b <= 60; b++) {
                if (x > n / a)
                    break;
                x *= a;
                long long r = isqrt(x);
                if ((__int128)r * r != x) {
                    f[++cnt] = x;
                }
            }
        }
        sort(f + 1, f + 1 + cnt);
        cnt = unique(f + 1, f + 1 + cnt) - 1 - f;
        cout << ans + cnt;
        return 0;
    }
    for (unsigned long long a = 2; a * a * a <= n; a++) {
        unsigned long long x = a * a;
        for (unsigned long long b = 3; b <= 60; b++) {
            if (x > n / a)
                break;
            x *= a;
            if (b >= k)
                f[++cnt] = x;
        }
    }
    sort(f + 1, f + 1 + cnt);
    cnt = unique(f + 1, f + 1 + cnt) - 1 - f;
    cout << cnt + 1;
    return 0;
}