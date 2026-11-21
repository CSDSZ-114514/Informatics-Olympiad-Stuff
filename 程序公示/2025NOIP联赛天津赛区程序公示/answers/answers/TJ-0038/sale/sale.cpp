#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int mod = 998244353;

const int N = 5010;

int a[N];

int qpow(int b, int k) {
    LL res = 1;
    while (k) {
        if (k & 1) res = res * b % mod;
        b = (LL)b * b % mod;
        k >>= 1;
    }
    return res % mod;
}

int main() {
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);

    int c, t;
    int n, m;

    scanf("%d%d", &c, &t);

    while (t -- ) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
        printf("%d\n", qpow(2, n));
    }

    return 0;
}
