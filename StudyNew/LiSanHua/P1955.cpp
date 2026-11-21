#include <bits/stdc++.h>
using namespace std;
long long fa[1000005], a[1000005], b[1000005], c[1000005], d[1000005], e[1000005];
long long a1[1000005], b1[1000005];
int find(long long x) {
    if (x == fa[x]) {
        return x;
    } else {
        return fa[x] = find(fa[x]);
    }
}
void unionset(long long x, long long y) { fa[find(x)] = find(y); }
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> e[i];
            c[i] = a[i];
            c[n + i] = b[i];
        }
        for (int i = 1; i <= 2 * n; i++) {
            d[i] = c[i];
        }
        sort(d + 1, d + 2 * n + 1);
        long long m = unique(d + 1, d + 2 * n + 1) - (d + 1);
        for (int i = 1; i <= n; i++) {
            a1[i] = lower_bound(d + 1, d + 1 + m, a[i]) - (d + 1);
            b1[i] = lower_bound(d + 1, d + 1 + m, b[i]) - (d + 1);
        }
        for (int i = 0; i <= m; i++) {
            fa[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (e[i] == 1) {
                unionset(a1[i], b1[i]);
            }
        }
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            if (e[i] == 0) {
                if (find(a1[i]) == find(b1[i])) {
                    flag = 0;
                }
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}