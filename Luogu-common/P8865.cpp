#include <bits/stdc++.h>
using namespace std;
long long T, id;
long long n, m, c, f;
int a[1005][1005], len[1005][1005];
const long long mod = 998244353;
int main() {
    cin >> T >> id;
    while (T--) {
        memset(len, 0, sizeof(len));
        cin >> n >> m >> c >> f;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char s;
                cin >> s;
                a[i][j] = s - '0';
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (a[i][j])
                    len[i][j] = 0;
                else
                    len[i][j] = len[i][j + 1] + 1;
            }
        }

        long long ans = 0, ans2 = 0;
        for (int j = 1; j <= m; j++) {
            long long lsth = 0, lsthf = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i][j]) {
                    lsth = 0;
                    lsthf = 0;
                    continue;
                }
                ans = (ans + lsth * (len[i][j] - 1)) % mod;
                ans2 = (ans2 + lsthf) % mod;
                lsthf += (len[i][j] - 1) * lsth;
                lsth += max(0, len[i - 1][j] - 1);
            }
        }
        cout << c * ans % mod << ' ' << f * ans2 % mod << '\n';
    }
    return 0;
}