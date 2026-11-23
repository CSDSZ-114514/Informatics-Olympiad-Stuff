#include <bits/stdc++.h>
using namespace std;
#define ll long long
int C;
void init(int c, int t) {
    C = c;
    return;
}
ll mod = 998244353;
std::vector<int> segment(int n, int m, int k, std::vector<int> l, std::vector<int> r) {
    vector<int> res(k + 1, 0);
    vector<vector<long long>> f(m + 1, vector<long long>(m + 1));
    if (k >= 1)
        res[1] = n;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (max(l[i], l[j]) <= min(r[i], r[j])) {
                ++cnt;
            }
        }
    }
    if (k >= 2)
        res[2] = cnt % mod;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (max(l[i], l[j]) <= min(r[i], r[j])) {
                long long maxx = max(r[i], r[j]);
                long long minx = min(r[i], r[j]);
                f[maxx][minx] = f[maxx][minx] + 1;
            }
        }
    }
    for (int s = 3; s <= k; s++) {
        vector<vector<long long>> tmp(m + 1, vector<long long>(m + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = (f[i][j] + f[i][j - 1]) % mod;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int x = l[i]; x <= m; x++) {
                if (r[i] > x) {
                    tmp[r[i]][x] = (tmp[r[i]][x] + f[x][l[i] - 1]) % mod;
                } else {
                    tmp[x][r[i]] = (tmp[x][r[i]] + f[x][l[i] - 1]) % mod;
                }
            }
        }
        f = tmp;
        for (int x = 1; x <= m; x++) {
            for (int y = 1; y <= m; y++) {
                res[s] = (res[s] + f[x][y]) % mod;
            }
        }
    }

    return res;
}