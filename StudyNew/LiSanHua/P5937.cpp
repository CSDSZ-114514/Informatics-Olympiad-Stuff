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
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        string eo;
        cin >> a[i] >> b[i];
        cin >> eo;
        if (eo == "odd") {
            e[i] = 0;
        } else {
            e[i] = 1;
        }
        // cout << e[i] << " ";
        c[i] = a[i] - 1;
        c[m + i] = b[i];
    }
    for (int i = 1; i <= 2 * m; i++) {
        d[i] = c[i];
    }
    sort(d + 1, d + 2 * m + 1);
    long long p = unique(d + 1, d + 2 * m + 1) - (d + 1);
    for (int i = 1; i <= m; i++) {
        a1[i] = lower_bound(d + 1, d + 1 + p, a[i]-1) - (d + 1);
        b1[i] = lower_bound(d + 1, d + 1 + p, b[i]) - (d + 1);
    }
    for (int i = 0; i <= 2 * p; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        if (e[i] == 1) {
            if (find(a1[i]) == find(b1[i] + p)) {
                cout << i - 1;
                // cout << 222222;
                return 0;
            }
            unionset(a1[i], b1[i]);
            unionset(a1[i] + p, b1[i] + p);
        } else {
            // for (int i = 1; i <= m;i++){
            //     cout << fa[i] << " ";
            // }
            // cout << endl;
            if (find(a1[i]) == find(b1[i])) {
                cout << i - 1;
                // cout << 222222;
                return 0;
            }
            unionset(a1[i], b1[i] + p);
            unionset(a1[i] + p, b1[i]);
        }
    }
    cout << m;
    return 0;
}