#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> e[1000005];
long long dfn[1000005], siz[1000005];
long long idx = 0;
void dfs(long long fa, long long u) {
    siz[u] = 1;
    dfn[u] = ++idx;
    for (auto t : e[u]) {
        if (t == fa)
            continue;
        dfs(u, t);
        siz[u] += siz[t];
    }
}
struct XDS {
    long long l, r, add, sum;
} tr[10000005];
void pushup(long long p) { tr[p].sum = tr[2 * p].sum + tr[2 * p + 1].sum; }
void pushdown(long long p) {
    if (tr[p].add) {
        tr[2 * p].sum += (tr[2 * p].r - tr[2 * p].l + 1) * tr[p].add;
        tr[2 * p].add += tr[p].add;
        tr[2 * p + 1].sum += (tr[2 * p + 1].r - tr[2 * p + 1].l + 1) * tr[p].add;
        tr[2 * p + 1].add += tr[p].add;
        tr[p].add = 0;
    }
}
void build(long long p, long long l, long long r) {
    tr[p] = {l, r, 0, 0};
    if (l == r) {
        return;
    }
    long long mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
}
void update(long long p, long long x, long long y, long long k) {
    if (x <= tr[p].l && tr[p].r <= y) {
        tr[p].sum += k * (tr[p].r - tr[p].l + 1);
        tr[p].add += k;
        return;
    }
    pushdown(p);
    long long mid = (tr[p].l + tr[p].r) >> 1;
    if (x <= mid) {
        update(2 * p, x, y, k);
    }
    if (y > mid) {
        update(2 * p + 1, x, y, k);
    }
    pushup(p);
}
long long query(long long p, long long x, long long y) {
    if (x <= tr[p].l && tr[p].r <= y) {
        return tr[p].sum;
    }
    pushdown(p);
    long long sm = 0;
    long long mid = (tr[p].l + tr[p].r) >> 1;
    if (x <= mid) {
        sm += query(2 * p, x, y);
    }
    if (y > mid) {
        sm += query(2 * p + 1, x, y);
    }
    return sm;
}
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(0, 1);
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        long long p;
        cin >> p;
        cout << query(1, dfn[p],  dfn[p])<<endl;
        update(1, dfn[p] + 1, dfn[p] + siz[p] - 1, 1);
    }
        return 0;
}