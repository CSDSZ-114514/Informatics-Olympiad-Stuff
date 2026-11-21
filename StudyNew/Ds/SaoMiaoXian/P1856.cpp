#include <bits/stdc++.h>
using namespace std;
long long n, b[1000005];
struct SMX {
    long long x1, x2, y, tag;
};
SMX a[1000005];
struct XDS {
    long long l, r, len, cnt, sum;
    bool lcover, rcover;
};
XDS tr[20000005];
void build(long long p, long long l, long long r) {
    tr[p] = {l, r, 0, 0};
    if (l == r) {
        return;
    }
    long long mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    return;
}
void pushup(long long p) {
    if (tr[p].cnt > 0) {
        tr[p].len = b[tr[p].r + 1] - b[tr[p].l];
        tr[p].sum = 2;
        tr[p].lcover = 1;
        tr[p].rcover = 1;
    } else {
        tr[p].len = tr[2 * p].len + tr[2 * p + 1].len;
        tr[p].sum = tr[2 * p].sum + tr[2 * p + 1].sum;
        tr[p].lcover = tr[2 * p].lcover;
        tr[p].rcover = tr[2 * p + 1].rcover;
        if (tr[2 * p].rcover == 1 && tr[2 * p + 1].lcover == 1) {
            tr[p].sum -= 2;
        }
    }
}
void update(long long p, long long x, long long y, long long k) {
    if (x <= tr[p].l && tr[p].r <= y) {
        tr[p].cnt += k;
        pushup(p);
        return;
    }
    long long mid = (tr[p].l + tr[p].r) >> 1;
    if (x <= mid) {
        update(2 * p, x, y, k);
    }
    if (y > mid) {
        update(2 * p + 1, x, y, k);
    }
    pushup(p);
    return;
}
bool cmp(SMX x, SMX y) {
    if(x.y!=y.y)
        return x.y < y.y;
    else
        return x.tag > y.tag;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[2 * i] = {x1, x2, y1, 1};
        a[2 * i - 1] = {x1, x2, y2, -1};
        b[2 * i] = x1;
        b[2 * i - 1] = x2;
    }
    sort(a + 1, a + 1 + 2 * n, cmp);
    sort(b + 1, b + 1 + 2 * n);
    long long m = unique(b + 1, b + 1 + 2 * n) - (b + 1);
    build(1, 1, m - 1);
    //cout << "1" << endl;
    long long ans = 0, lastlen = 0;
    for (int i = 1; i <= 2 * n; i++) {
        long long l = lower_bound(b + 1, b + 1 + m, a[i].x1) - b;
        long long r = lower_bound(b + 1, b + 1 + m, a[i].x2) - b;
        update(1, l, r - 1, a[i].tag);
        ans += abs(tr[1].len - lastlen);
        lastlen = tr[1].len;
        ans += (a[i+1].y - a[i].y)*tr[1].sum;
         
    }
    cout << ans;
    return 0;
}
