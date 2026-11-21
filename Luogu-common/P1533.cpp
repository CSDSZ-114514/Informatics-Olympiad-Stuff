#include <bits/stdc++.h>
using namespace std;
int n, m, a[400005], d[400005],root[400005];
int cnt;
struct XDS {
    int ls, rs, val;
} tr[6000005];
void pushup(int p) { tr[p].val = tr[tr[p].ls].val + tr[tr[p].rs].val; }
void update(int &p, int v, int x, int l, int r, int k) {
    p = ++cnt;
    tr[p] = tr[v];
    if (l == r) {
        tr[p].val++;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        update(tr[p].ls, tr[v].ls, x, l, mid, k);
    } else {
        update(tr[p].rs, tr[v].rs, x, mid + 1, r, k);
    }
    pushup(p);
}
int query(int p1, int p2, int l, long r, int k) {
    int mid = (l + r) >> 1;
    if (l == r) {
        return l;
    }
    if (tr[tr[p2].ls].val - tr[tr[p1].ls].val >= k) {
        return query(tr[p1].ls, tr[p2].ls, l, mid, k);
    } else {
        return query(tr[p1].rs, tr[p2].rs, mid + 1, r, k - (tr[tr[p2].ls].val - tr[tr[p1].ls].val));
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    sort(d + 1, d + 1 + n);
    int nn = unique(d + 1, d + 1 + n) - (d + 1);
    for (int i = 1; i <= n; i++) {
        int p = lower_bound(d + 1, d + 1 + nn, a[i]) - (d);
        update(root[i], root[i - 1], p, 1, nn, 1);
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << d[query(root[a - 1], root[b], 1, nn, c)]<<endl;
    }

    return 0;
}