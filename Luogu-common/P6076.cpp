#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long n, m, c, cc[405][405];
long long f[505];
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
int main() {
    cin >> n >> m >> c;
    for (int i = 0; i <= 402; i++) {
        cc[i][0] = 1;
    }
    for (int i = 1; i <= 402; i++) {
        for (int j = 1; j <= i; j++) {
            cc[i][j] = (cc[i - 1][j] + cc[i - 1][j - 1]) % mod;
        }
    }
    for (int i = 1; i <= c; i++) {
        for (int j = 0; j <= m; j++) {
            f[i] += cc[m][j] * ((j & 1) ? -1 : 1) * qpow((qpow((i + 1), m - j, mod) - 1), n, mod);
            f[i] %= mod;
        }
    }
    long long ans = 0;
    for (int i = 0; i <= c; i++) {
        ans = (ans + cc[c][i] * (i % 2 == 0 ? 1 : -1) * f[c - i]) % mod;
        
    }
    cout << (ans % mod + mod) % mod;
    return 0;
}