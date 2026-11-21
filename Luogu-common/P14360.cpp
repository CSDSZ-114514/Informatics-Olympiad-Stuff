#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[10000005], f[5005][5005], pw[1000005], ans[1000005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pw[0] = 1;
    for (int i = 1; i <= n - 1; ++i)
        pw[i] = pw[i - 1] * 2 % 998244353;
    sort(a + 1, a + 1 + n);
    for (int i = 0; i <= n; ++i)
        f[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5001; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i]) {
                f[i][j] = (f[i][j] + f[i-1][j - a[i]]) % 998244353;
            }
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += pw[i - 1];
        res%=998244353;
        for (int k = 0; k <= a[i]; k++) {
            ans[i] += f[i - 1][k];
            ans[i] %= 998244353;
        }
    }
    for (int i = 1; i <= n; ++i) {
        res = (res - ans[i]) % 998244353;
    }
    cout << (res % 998244353 + 998244353) % 998244353;
}