#include "segment.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int C;
void init(int c, int t) {
    C = c;
    return;
}

struct XD {
    long long l, r;
    bool operator<(const XD p) const { return l < p.l; }
} xd[30005];
ll mod = 998244353;
long long f[3005][3005];
std::vector<int> segment(int n, int m, int k, std::vector<int> l, std::vector<int> r) {
    vector<int> res(n, 0);
    for (int i = 1; i <= n; i++) {
        xd[i].l = l[i];
        xd[i].r = r[i];
    }
    res[1] = n;
    sort(xd + 1, xd + 1 + n);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (xd[i].r > xd[j].l&&) {
                f[j][i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j++) {
        }
    }

    return res;
}
