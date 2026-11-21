#include <bits/stdc++.h>
using namespace std;
struct XDS {
    long long l, r, sum, add;
};
XDS tr[1000005];
void pushdown(long long p) {
    if (tr[p].add) {
        tr[2 * p].sum += ((tr[2 * p].r - tr[2 * p].l + 1) * tr[p].add);
        tr[2 * p + 1].sum += ((tr[2 * p + 1].r - tr[2 * p + 1].l + 1) * tr[p].add);
        tr[2 * p].add += tr[p].add;
        tr[2 * p + 1].add += tr[p].add;
        tr[p].add = 0;
    }
}
void pushup(long long p) { tr[p].sum = tr[2 * p].sum + tr[2 * p + 1].sum; }
void build(long long p, long long l, long long r) {
    tr[p].l = l;
    tr[p].r = r;
    if (l == r) {
        tr[p].sum = l;
        return;
    }
    long long mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    pushup(p);
}
void update(long long p, long long l, long long r, long long k) {
    if (tr[p].l >= l && tr[p].r <= r) {
        tr[p].add += k;
        tr[p].sum += (k * (tr[p].r - tr[p].l + 1));
        return;
    }
    pushdown(p);
    long long mid = (tr[p].r + tr[p].l) >> 1;
    if (l <= mid)
        update(2 * p, l, r, k);
    if (r > mid)
        update(2 * p, l, r, k);
    pushup(p);
}
long long query(long long p, long long l, long long r) {
    if (tr[p].l >= l && tr[p].r <= r) {
        return tr[p].sum;
    }
    pushdown(p);
    long long mid = (tr[p].r + tr[p].l) >> 1, ans = 0;
    if (l <= mid)
        ans += query(2 * p, l, r);
    if (r > mid)
        ans += query(2 * p + 1, l, r);
    return ans;
}
int main() {}