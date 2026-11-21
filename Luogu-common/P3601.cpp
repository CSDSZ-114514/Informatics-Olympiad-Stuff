#include <bits/stdc++.h>
using namespace std;
long long l, r;
long long  cnt, p[1000005];
bool isp[1000005];
void seo(long long n) {
    memset(isp, 1, sizeof(isp));
    isp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (isp[i])
            p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
            isp[i * p[j]] = 0;
            if (i % p[j] == 0)
                break;
        }
    }
}
long long vis[10000005], phi[10000005];
int main() {
    cin >> l >> r;
    seo(sqrt(r)+1);
    for (int i = 0; i <= r-l; i++) {
        vis[i] = l+i;
        phi[i] = l+i;
    }
    for (int i = 1; i <= cnt && p[i] * p[i] <= r; i++) {
        for (int j = (p[i] - l % p[i]) % p[i]; j <= r - l; j += p[i]) {
            phi[j] = phi[j] / p[i] * (p[i] - 1);
            while (!(vis[j] % p[i]))
                vis[j] /= p[i];
        }
    }
    long long ans = 0;
    for (int i = 0; i <= r-l; i++) {
        if (vis[i] != 1)
            phi[i] = phi[i] / vis[i] * (vis[i] - 1);
        ans = (1 * (ans + i + l - phi[i])+666623333) % 666623333;
    }
    cout << ans;
    return 0;
}