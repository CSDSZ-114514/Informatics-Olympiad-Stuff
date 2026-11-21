#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll X[100010] = {0}, Y[100010] = {0};
int main () {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    int n;
    ll m;
    scanf("%d%lld", &n, &m);
    ll minX = 0x3f3f3f3f3f3f3f3fll, minS = 0x3f3f3f3f3f3f3f3fll;
    for (int i = 1; i <= n; i ++) {
        scanf("%lld%lld", &X[i], &Y[i]);
        minS = min(minS, X[i] + Y[i]);
        minX = min(minX, X[i]);
    }
    // printf("mins %lld minx %lld\n", minS, minX);
    sort(X + 1, X + 1 + n);
    ll res = (m / minS) * 2ll, m_ = m;
    for (int i = 1; i <= n; i ++) {
        m_ -= X[i];
        res = max(res, i + (m_ / minS) * 2ll);
    }
    printf("%lld\n", res);
    return 0;
}