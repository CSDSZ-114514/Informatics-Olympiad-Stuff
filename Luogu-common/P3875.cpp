#include <bits/stdc++.h>
using namespace std;
long long n;
struct XDS {
    long long l, r, cnt, len;
} tr[81000005];
struct SMX {
    long long x1, x2, y, flg;
} a[1000005];
bool cmp(SMX a, SMX b) { return a.y < b.y; }
void pushup(long long p) {
    if (tr[p].cnt) {
        tr[p].len = tr[p].r + 1 - tr[p].l;
    } else {
        tr[p].len = tr[2 * p].len + tr[2 * p + 1].len;
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
    pushup(p);
}
void update(long long p,long long l,long long r,long long k){
    if(l<=tr[p].l&&tr[p].r<=r){
        tr[p].cnt += k;
        pushup(p);
        return;
    }
    long long mid = (tr[p].l + tr[p].r) >> 1;
    if(l<=mid){
        update(2 * p, l, r, k);
    }
    if(r>mid){
        update(2 * p+1, l, r, k);
    }
    pushup(p);
    return;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        long long tx1, tx2, ty1, ty2;
        if(y1>y2)
            swap(y1, y2);
        if(x1>x2)
            swap(x1, x2);
        if (x1 == x2) {
            tx1 = x1 - 1, tx2 = x1 + 1, ty1 = y1, ty2 = y2;
        } else {
            tx1 = x1, tx2 = x2, ty1 = y1 - 1, ty2 = y2 + 1;
        }
        a[2 * i - 1] = {tx1, tx2, ty1, 1};
        a[2 * i] = {tx1, tx2, ty2, -1};
    }
    n *= 2;
    sort(a + 1, a + 1 + n, cmp);
    build(1, 0, 1e5 + 5);
    long long ans = 0;
    for (int i = 1; i < n;i++){
        update(1, a[i].x1, a[i].x2 - 1, a[i].flg);
        ans += (a[i + 1].y - a[i].y) * tr[1].len;
    }
    cout << ans;
    return 0;
}