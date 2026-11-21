#include <bits/stdc++.h>
using namespace std;
long long T, cd[1000005];
unordered_map<long long, long long> mp;
long long qpow(long long a, long long b, long long m) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ans * a % m;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}
int main() {
    cin >> T;
    while (T--) {
        mp.clear();
        bool flag = false;
        long long n, m, v;
        cin >> n >> m >> v;
        for (int i = 1; i <= m; i++) {
            long long c, d;
            cin >> c >> d;
            cd[i] = c;
            if (mp[c] && mp[c] != d)
                flag = true;
            mp[c] = d;
        }
        if (flag) {
            cout << 0 << endl;
            continue;
        }
        sort(cd + 1, cd + 1 + m);
        long long ans = 1;
        for (int i = 2; i <= m; i++) {
            if (cd[i] == cd[i - 1])
                continue;
            ans = ans * ((qpow(v, 2 * cd[i] - 2 * cd[i - 1], (long long)(1e9+7)) - qpow(v, (cd[i] - cd[i - 1] - 1), (long long)(1e9+7)) * (v - 1) % (long long)(1e9+7) + (long long)(1e9+7)) % (long long)(1e9+7)) % (long long)(1e9+7);
        }
        ans = ans * (qpow(v, 2 * cd[1] - 2, (long long)(1e9+7))) % (long long)(1e9+7);
        ans = ans * qpow(v, 2 * n - 2 * cd[m], (long long)(1e9+7)) % (long long)(long long)(1e9+7);
        cout << (ans + (long long)(1e9+7)) % (long long)(1e9+7) << endl;
    }
    return 0;
}