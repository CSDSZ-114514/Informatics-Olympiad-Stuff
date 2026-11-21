#include <bits/stdc++.h>
using namespace std;
long long f[65][55], c[1005];
long long qpow(long long a, long long b, long long m) {
    long long ans = 1;
    while (b) {
        if (b % 2 == 1) {
            ans = ans * a % m;
        }
        b /= 2;
        a = a * a % m;
    }
    return ans;
}
long long cnt;
long long dp(long long n) {
    long long a[100005];
    while (n) {
        a[++cnt] = n % 2;
        n /= 2;
    }
    long long cnt2 = 0;
    for (int i = cnt; i >= 1; i--) {
        if (a[i] != 1)
            continue;
        for (int j = 1; j < cnt; j++) {
            if (j - cnt2 >= 0 && i - 1 >= 0) {
                c[j] += f[i - 1][j - cnt2];
            }
        }
        cnt2++;
    }
    c[cnt2]++;
}
int main() {
    long long n;
    cin >> n;
    for (int i = 0; i <= 50; i++) {
        f[i][0] = 1;
    }
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }
    }
    dp(n);
    long long ans = 1;
    for (int i = 1; i <= 50; i++) {
        ans = (ans * qpow(i, c[i], 10000007)) % 10000007;
    }
    cout << ans;
    return 0;
}