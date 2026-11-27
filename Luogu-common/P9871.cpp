#include <bits/stdc++.h>
using namespace std;
long long c, t;
long long n, m, k, d;
struct QZ {
    long long x, y, v, l;
    bool operator<(const QZ p) const { return x < p.x; }
} qz[1000005];
struct SEG {
    long long p, l, r, mxv = -1e18, laz;
} sg[1000005];
void pushup(long long p) { sg[p].mxv = max(sg[p << 1].mxv, sg[p << 1 | 1].mxv); }
void pushdown(long long p) {
    if (sg[p].l == sg[p].r)
        return;
    if (sg[p].laz) {
        sg[p << 1].mxv += sg[p].laz;
        sg[p << 1].laz += sg[p].laz;
        sg[p << 1 | 1].mxv += sg[p].laz;
        sg[p << 1 | 1].laz += sg[p].laz;
        sg[p].laz = 0;
    }
}
void build(long long p, long long l, long long r) {
    sg[p].l = l;
    sg[p].r = r;
    sg[p].laz = 0;
    sg[p].mxv = 0;
    if (l == r) {
        return;
    }
    long long mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void upd(long long p, long long l, long long r, long long k) {
    if (l <= sg[p].l && sg[p].r <= r) {
        sg[p].mxv += k;
        sg[p].laz += k;
        return;
    }
    pushdown(p);
    long long mid = (sg[p].l + sg[p].r) >> 1;
    if (l <= mid) {
        upd(p << 1, l, r, k);
    }
    if (r > mid) {
        upd(p << 1 | 1, l, r, k);
    }
    pushup(p);
}
long long query(long long p, long long l, long long r) {
    if (l <= sg[p].l && r >= sg[p].r) {
        return sg[p].mxv;
    }
    pushdown(p);
    long long ans = -1e18, mid = (sg[p].l + sg[p].r) >> 1;
    if (l <= mid)
        ans = max(ans,query(p << 1, l, r));
    if (mid < r)
        ans = max(ans,query(p << 1 | 1, l, r));
    return ans;
}
long long f[1000005];
long long lsh[1000005], cnt;
long long id(long long x) { return upper_bound(lsh + 1, lsh + 1 + cnt, x) - lsh - 1; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    cin >> c >> t;
    while (t--) {
        cnt = 0;
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= m; i++) {
            cin >> qz[i].x >> qz[i].y >> qz[i].v;
            qz[i].l = qz[i].x - qz[i].y + 1;
            lsh[++cnt] = qz[i].x;
            lsh[++cnt] = qz[i].l;
        }
        sort(lsh + 1, lsh + cnt + 1);
        sort(qz + 1, qz + 1 + m);
        cnt = unique(lsh + 1, lsh + 1 + cnt) - lsh - 1;

        build(1, 1, cnt);
        f[0] = 0;

        long long lsj = 1, lat = 0;
        for (int i = 1; i <= cnt; i++) {
            if (i == 1)
                lat = 0;
            else if (lsh[i - 1] == lsh[i] - 1)
                lat = f[i - 2];
            else
                lat = f[i - 1];
            upd(1, i, i,lat + d * lsh[i]);
            while(lsj<=m&&qz[lsj].x<=lsh[i]){
                long long j = upper_bound(lsh + 1, lsh + 1 + cnt, qz[lsj].l) - lsh - 1;
                if(j>=1)
                    upd(1, 1, j, qz[lsj].v);
                lsj++;
            }
            long long len = lower_bound(lsh + 1, lsh + 1 + cnt, lsh[i] - k + 1) - lsh;
            long long bl = query(1, len, i) - d * (lsh[i] + 1);
            f[i] = max(i > 1 ? f[i - 1] : 0LL, bl);
        }
        cout << f[cnt] << '\n';
    }
    return 0;
}