#include <bits/stdc++.h>
using namespace std;
long long m[5] = {0, 2, 3, 4679, 35617};
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
long long f[10000005], g[10000005];
void init(long long p) {
    f[0] = g[0] = 1;
    for (int i = 1; i < p; i++) {
        f[i] = f[i - 1] * i % p;
    }
    g[p - 1] = qpow(f[p - 1], p - 2, p);
    for (int i = p - 2; i >= 1; i--) {
        g[i] = g[i + 1] * (i + 1) % p;
    }
}
long long getC(long long n, long long m, long long p) {
    if (n < m)
        return 0;
    return f[n] * g[n - m] % p * g[m] % p;
}
long long lucas(long long n, long long m, long long p) {
    if (m == 0)
        return 1;
    return lucas(n / p, m / p, p) * getC(n % p, m % p, p) % p;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long x1, y1;
    long long d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}
long long crt(long long m[], long long r[]) {
    long long ans = 0, M = 1;
    for (int i = 1; i <= 4; i++) {
        M = M * m[i];
    }
    for (int i = 1; i <= 4; i++) {
        long long c = M / m[i];
        long long x, y;
        exgcd(c, m[i], x, y);
        ans = (ans + (__int128)r[i] * c * x % M) % M;
    }
    return (ans % M + M) % M;
}
long long n, gg;
long long d[1000005], dcnt;
long long r[5];
int main() {
    cin >> n >> gg;
    if (gg % 999911659 == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            d[++dcnt] = i;
            if (i * i != n)
                d[++dcnt] = n / i;
        }
    }
    for (int i = 1; i <= 4; i++) {
        init(m[i]);
        long long ans = 0;
        for (int j = 1; j <= dcnt; j++) {
            ans += lucas(n, d[j], m[i]);
        }
        r[i] = ans % m[i];
    }
    long long x = crt(m, r);
    cout << qpow(gg, x, 999911659);
    return 0;
}