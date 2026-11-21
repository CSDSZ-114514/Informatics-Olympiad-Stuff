#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 50010;
const ll inf = 1e18;
ll a[maxn] = {0}, s[maxn] = {0};
ll st[20][maxn] = {0}, mylg[maxn] = {0};
ll ask(int l, int r) {
    if (l > r) {
        return -inf;
    }
    int len = r - l + 1;
    return max(st[mylg[len]][l], st[mylg[len]][r - (1 << mylg[len]) + 1]);
}
ll val[maxn] = {0};
int main () {
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    int n;
    scanf("%d", &n);
    mylg[0] = 0;
    memset(st, 0x80, sizeof(st));
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
        s[i] = s[i - 1] + a[i];
        st[0][i] = s[i];
    }
    mylg[1] = 0;
    for (int i = 2; i <= n; i ++) {
        mylg[i] = mylg[i >> 1] + 1;
    }
    for (int i = 1; i <= 18; i ++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j ++) {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    int q;
    scanf("%d", &q);
    while(q --) {
        int L, R;
        scanf("%d%d", &L, &R);
        for (int i = 1; i <= n; i ++) {
            val[i] = -inf;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = max(i - R + 1, 1); j <= i; j ++) {
                if (j + L - 1 > n) {
                    break;
                }
                // for (int k = j + L - 1; k <= min(n, j + R - 1); k ++) {
                //     if (k < i) {
                //         continue;
                //     }
                //     // val[i] = max(val[i], s[k] - s[j - 1]);
                // }
                // printf("%d %d %lld\n", max(j + L - 1, i), min(j + R - 1, n), ask(max(j + L - 1, i), min(j + R - 1, n)));
                val[i] = max(val[i], ask(max(j + L - 1, i), min(j + R - 1, n)) - s[j - 1]);
            }
        }
        ull res = 0;
        for (int i = 1; i <= n; i ++) {
            res ^= 1llu * i * val[i];
            // printf("%lld ", val[i]);
        }
        printf("%llu\n", res);
    }
    return 0;
}