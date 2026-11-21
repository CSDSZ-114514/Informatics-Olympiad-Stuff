#include <bits/stdc++.h>
using namespace std;
long long l, r;
long long f[25][15];
long long ans[15][15], a[15];
void dp(long long p, long long e) {
    long long cnt = 0;
    long long tmp = e;
    while (tmp) {
        a[++cnt] = tmp % 10;
        tmp /= 10;
    }
    for (int i = cnt; i >= 1; i--) {
        for (int j = 0; j <= a[i] - 1; j++) {
            ans[p][j] += pow(10, i - 1);
            for (int k = 0; k <= 9; k++) {
                ans[p][k] += f[i - 1][k];
            }
        }
        ans[p][a[i]] += e % (long long)pow(10, i - 1) + 1;
        ans[p][0] -= pow(10, i - 1);
    }
}
int main() {
    cin >> l >> r;
    for (int i = 0; i <= 9; i++) {
        f[1][i] = 1;
    }
    for (int i = 2; i <= 13; i++) {
        for (int j = 0; j <= 9; j++) {
            f[i][j] += 10 * f[i - 1][j] + pow(10, i - 1);
        }
    }
    dp(1, r);
    dp(0, l-1);
    for (int i = 0; i <= 9; i++) {
        cout << ans[1][i] - ans[0][i] << " ";
    }

    return 0;
}