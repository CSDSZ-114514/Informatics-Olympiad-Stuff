#include <bits/stdc++.h>
using namespace std;
long long n, m, a[25000005];
struct XDS {
    long long l, r, ls, rs, val;
} tr[25000005];
long long cnt,root[25000005];
void build(long long &p, long long l, long long r) {
    p = ++cnt;
    tr[p] = {l, r, 0, 0, 0};
    if (l == r) {
        tr[p].val = a[l];
        return;
    }
    long long mid = (l + r) >> 1;
    if (l <= mid) {
        build(tr[p].ls, l, mid);
    }
    if (r > mid) {
        build(tr[p].rs, mid + 1, r);
    }
}
void update(long long &p, long long v, long long x, long long k) {
    p = ++cnt;
    tr[p] = tr[v];
    if (tr[p].l == tr[p].r) {
        tr[p].val = k;
        return;
    }
    long long mid = (tr[p].l + tr[p].r) >> 1;
    if (x <= mid) {
        update(tr[p].ls, tr[v].ls, x, k);
    } else {
        update(tr[p].rs, tr[v].rs, x, k);
    }
}
long long query(long long p, long long x) {
    if (tr[p].l == tr[p].r) {
        return tr[p].val;
    }
    long long mid = (tr[p].l + tr[p].r) >> 1;
    if (x <= mid) {
        return query(tr[p].ls, x);
    } else {
        return query(tr[p].rs, x);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(root[0], 1, n);
    for (int i = 1; i <= m; i++) {
        long long v, md, p, c;
        cin >> v >> md >> p ;
        if(md==1){
            cin >> c;
            update(root[i],root[v], p, c);
        }else{
            cout << query(root[v], p)<<'\n';
            root[i] = root[v];
        }
    }
    return 0;
}