#include <bits/stdc++.h>
using namespace std;
long long n, m;
struct qj {
    long long l, r;
};
qj q[10000005];
long long c[10000005];
bool cmp(qj x, qj y) {
    return x.r < y.r;
}
struct XS {
    long long l, r, minn;
    long long add;
};
XS f[10000005];
void pushup(long long p) { f[p].minn = min(f[2 * p].minn, f[2 * p + 1].minn); }
void pushdown(long long p) {
    if (f[p].add) {
        f[2 * p].add += f[p].add;
        f[2 * p].minn += f[p].add;
        f[2 * p + 1].add += f[p].add;
        f[2 * p + 1].minn += f[p].add;
        f[p].add = 0;
    }
}
void build(long long p, long long l, long long r) {
    f[p] = {l, r, (long long)1e18, 0};
    if (l == r) {
        f[p].minn = c[l];
        return;
    }
    long long mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    pushup(p);
}
void update(long long p, long long l, long long r, long long k) {
    if (l <= f[p].l && r >= f[p].r) {
        f[p].add += k;
        f[p].minn += k;
        return;
    }
    pushdown(p);
    long long mid = (f[p].l + f[p].r) >> 1;
    if (l <= mid) {
        update(2 * p, l, r, k);
    }
    if (r > mid) {
        update(2 * p + 1, l, r, k);
    }
    pushup(p);
}
long long query(long long p, long long l, long long r) {
    long long mins = 1e18;
    if (l <= f[p].l && f[p].r <= r) {
        return f[p].minn;
    }
    pushdown(p);
    long long mid = (f[p].l + f[p].r) >> 1;
    if (l <= mid) {
        mins = min(mins, query(2 * p, l, r));
    }
    if (r > mid) {
        mins = min(mins, query(2 * p + 1, l, r));
    }
    return mins;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
    }
    long long cnt = 0;
    sort(q + 1, q + 1 + m, cmp);
    build(1, 1, n);
    for (int i = 1; i<= m;i++){
        if(query(1,q[i].l,q[i].r)>0){
            update(1, q[i].l, q[i].r, -1);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}