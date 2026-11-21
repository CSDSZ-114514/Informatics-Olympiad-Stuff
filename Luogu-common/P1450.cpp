#include <bits/stdc++.h>
using namespace std;
long long c[10], n, d[10], s;
long long f[10000005];
int main() {
    for (int i = 1; i <= 4; i++) {
        cin >> c[i];
    }
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 1e5 + 5; j++) {
            if (j - c[i] >= 0) {
                f[j] += f[j - c[i]];
            }
        }
    }
    //cout << f[3];
    for (int i = 1; i <= n; i++) {
        long long ans = 0;
        for (int j = 1; j <= 4; j++) {
            cin >> d[j];
        }
        cin >> s;
        for (int j = 0; j <= (1 << 4) - 1; j++) {
           //cout << 00000;
            long long e = j, a = 0, fas = 0;
            for (int k = 1; k <= 4; k++) {
                if (e & 1) {
                    a++;
                    fas += c[k] * (d[k] + 1);
                }
                e >>= 1;
            }
            if(s - fas<0)
                continue;
            //cout << fas;
            ans += pow(-1, a % 2) * f[s - fas];
        }
        cout << ans << endl;
    }
    return 0;
}