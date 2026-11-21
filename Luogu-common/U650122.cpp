#include <bits/stdc++.h>
using namespace std;
long long k;
long long s[1000005], sg[1000005];
long long getSG(long long u) {
    if (sg[u] != -1) {
        return sg[u];
    }
    set<long long> ss;
    for (int i = 1; i <= k; i++) {
        long long move = s[i];
        if (move > u)
            continue;
        ss.insert(getSG(u - move));
    }
    for (long long i = 0;; i++) {
        if (!ss.count(i)) {
            return sg[u] = i;
        }
    }
}
int main() {
    while (true) {
        long long m = 0;
        cin >> k;
        if (!k) {
            return 0;
        }
        for (int i = 1; i <= k; i++) {
            cin >> s[i];
        }
        memset(sg, -1, sizeof(sg));
        sg[0] = 0;
        for (int i = 1; i <= 1e4 + 5; i++) {
            getSG(i);
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            long long n;
            cin >> n;
            long long xsm = 0, a;
            for (int i = 1; i <= n; i++) {
                cin >> a;
                xsm ^= sg[a];
            }
            cout << (xsm ? 'W' : 'L');
        }
        cout << endl;
    }
    return 0;
}