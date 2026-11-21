#include <bits/stdc++.h>
using namespace std;
struct TR {
    long long l, r, val, flg;
} f[4000005];
long long a[10000005];
void pushdown(long long p) {
    f[2 * p].val += f[p].flg * (f[2 * p].r - f[2 * p].l + 1);
    f[2 * p].flg += f[p].flg;
    f[2 * p + 1].val += f[p].flg * (f[2 * p + 1].r - f[2 * p + 1].l + 1);
    f[2 * p + 1].flg += f[p].flg;
    f[p].flg = 0;
}
void pushup(long long p) { f[p].val = f[2 * p].val + f[2 * p + 1].val; }
void build(long long p, long long l, long long r) {
    f[p] = {l, r, 0, 0};
    if (l == r) {
        f[p].val = a[l];
        return;
    }
    long long mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    pushup(p);
}
void update(long long p, long long l, long long r, long long k) {
    if (l <= f[p].l && f[p].r <= r) {
        f[p].val += k * (f[p].r - f[p].l + 1);
        f[p].flg += k;
        return;
    }
    long long mid = (f[p].l + f[p].r) >> 1;
    pushdown(p);
    if (l <= mid) {
        update(2 * p, l, r, k);
    }
    if (mid < r) {
        update(2 * p + 1, l, r, k);
    }
    pushup(p);
}
long long query(long long p, long long l, long long r) {
    if (l <= f[p].l && f[p].r <= r) {
        return f[p].val;
    }
    long long mid = (f[p].l + f[p].r) >> 1;
    pushdown(p);
    long long ans = 0;
    if (l <= mid) {
        ans += query(2 * p, l, r);
    }
    if (mid < r) {
        ans += query(2 * p + 1, l, r);
    }
    return ans;
}
long long phi[40000005], cnt, p[40000005];
void getPhi() {
    phi[1] = 1;
    for (int i = 2; i <= 2e7 + 5; i++) {
        if (phi[i] == 0) {
            phi[i] = i - 1;
            p[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * p[j] <= 2e7 + 5; j++) {
            if (i % p[j] == 0) {
                phi[i * p[j]] = p[j] * phi[i];
                break;
            } else {
                phi[i * p[j]] = (p[j] - 1) * phi[i];
            }
        }
    }
}
long long qpow(long long a, long long b, long long m) {
    if (a >= m) {
        a %= m;
        a += m;
    }
    long long ans = 1;
    while (b) {
        if (b % 2 == 1) {
            ans = ans * a;
            if (ans >= m) {
                ans %= m;
                ans += m;
            }
        }
        b /= 2;
        a = a * a;
        if (a >= m) {
            a %= m;
            a += m;
        }
    }
    return ans;
}
long long solve(long long a, long long b, long long p) {
    if (p == 1)
        return 1;
    if (a > b) {
        return 1;
    }
    return qpow(query(1, a, a), solve(a + 1, b, phi[p]), p);
}
long long n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    getPhi();

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        long long md, l, r, x;
        cin >> md >> l >> r >> x;
        if (md == 1) {
            update(1, l, r, x);
        } else {
            cout << solve(l, r, x)%x<<endl;
        }
    }
    return 0;
}