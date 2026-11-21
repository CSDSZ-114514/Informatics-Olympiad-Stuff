#include <bits/stdc++.h>

using namespace std;

const int N = 8010;

int p[N];

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t -- ) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i < n; i ++ ) scanf("%d", &p[i]);
        printf("%d\n", (n + 1) * n / 2);
    }

    return 0;
}
