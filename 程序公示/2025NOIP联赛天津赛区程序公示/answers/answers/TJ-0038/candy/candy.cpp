#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
LL m;
int a[N], b[N];
LL c[N];

int main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);

    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d%d", &a[i], &b[i]);

    for (int i = 1; i <= n; i ++ ) c[i] = (LL)a[i] + b[i];

    sort(c + 1, c + n + 1);
    sort(a + 1, a + n + 1);

    LL res = 0;
    res += m / c[1] * 2;

    m -= m / c[1] * c[1];

    for (int i = 1; i <= n; i ++ ) {
        if (m - a[i] < 0) break;
        res ++ ;
        m -= a[i];
    }

    printf("%lld\n", res);

    return 0;
}
