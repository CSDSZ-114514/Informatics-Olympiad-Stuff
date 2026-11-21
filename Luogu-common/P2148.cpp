#include <bits/stdc++.h>
using namespace std;
long long n;
long long s[2000005];
long long T;
long long sg[2005][2005];
long long getSG(long long u, long long v) {
    if (sg[u][v] != -1) {
        return sg[u][v];
    }

    set<int> s;
    for (int i = 1; i < v; i++) {
        s.insert(getSG(i, v - i));
    }
    for (int i = 1; i < u; i++) {
        s.insert(getSG(u - i, i));
    }

    for (int i = 0;; i++) {
        if (!s.count(i)) {
            return sg[u][v] = i;
        }
    }
}
int main() {
    cin >> T;
    memset(sg, -1, sizeof(sg));
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        long long ss = 0;
        for (int i = 1; i <= n / 2; i++) {
            ss ^= getSG(s[2 * i], s[2 * i - 1]);
        }
        if (ss) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}