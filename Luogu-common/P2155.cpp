#include <bits/stdc++.h>
using namespace std;
bool isp[10000005];
long long p[10000005], cnt, g[10000005], a[10000005];
long long n, m, t, r;
void seo(long long n) {
    memset(isp, 1, sizeof(isp));
    isp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (isp[i])
            p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
            isp[i * p[j]] = 0;
            if (i % p[j] == 0)
                break;
        }
    }
}
long long qpow(long long a, long long b, long long m) {
    long long ans = 1;
    while (b) {
        if (b % 2 == 1) {
            ans = ans * a % m;
        }
        b /= 2;
        a = a * a % m;
    }
    return ans;
}
long long f[10000007];
int main() {
    cin >> t >> r; f[0] = 1;
    seo(1e7 + 5);
   
    for (int i = 1; i <= 1e7 + 5; i++) {
        if (i == r) {
            f[i] = f[i - 1];
        } else {
            int x = i;
            while (x % r == 0)
                x /= r; 
            f[i] = f[i - 1] * x % r;
        }
    }
    g[1] = 1;
    for (int i = 2; i <= 1e7 + 5; i++) {
        if (isp[i]) {
            if (i == r) {
                g[i] = g[i - 1] * (r - 1) % r;
            } else {
                g[i] = g[i - 1] * (i - 1) % r * qpow(i, r - 2, r) % r;
            }
        } else {
            g[i] = g[i - 1];
        }
    }
    while (t--) {
        cin >> n >> m;
        if (m < r && n >= r || m >= r && n >= 2 * r) {
            cout << 0 << endl;
        } else {
            if (m >= r) {
                cout << f[n] * g[m] % r % r << endl;
            } else {
                cout << f[n] * g[m] % r << endl;
            }
        }
    }
    return 0;
}