#include <bits/stdc++.h>
using namespace std;
struct QJ {
    long long l, r;
};

bool cmp(QJ x, QJ y) {
    if (x.l != y.l)
        return x.l < y.l;
    else
        return x.r < y.r;
}
int main() {
    long long t;
    cin >> t;
    while (t--) {
        QJ a[1000005];
        long long n, m;
        long long maxl = -1e18, minr = 1e18;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {

            cin >> a[i].l >> a[i].r;
            maxl = max(maxl, a[i].l);
            minr = min(minr, a[i].r);
        }
        if (maxl <= minr) {
            cout << 0 << endl;
            continue;
        }
        sort(a + 1, a + 1 + n, cmp);
        long long cmp = 0;
        long long rr = -1;
        for (int i = 1; i <= n; i++) {
            if (cmp == 0 || a[i].l > rr) {
                cmp++;
                rr = a[i].r;
            } else {
                rr = max(rr, a[i].r);
            }
        }
        cout<<(cmp == 1 ? "3" : "2")<<endl;
    }
    return 0;
}