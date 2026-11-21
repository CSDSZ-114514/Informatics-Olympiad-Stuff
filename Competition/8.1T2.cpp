#include <bits/stdc++.h>
using namespace std;
unsigned long long n;
unsigned long long d[1000005], p[100005];
bool t[1000005];
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> d[i];
    }
    p[1] = 0;
    for (int i = 2; i <= n; i++)
        p[i] = p[i - 1] + d[i - 1];
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    unsigned long long ans = 0;
    for (int i = 1; i < n;) {
        if (!t[i]) {
            i++;
            continue;
        }
        unsigned long long l = i;
        while (i <= n - 1 && t[i] == 1)
            i++;
        unsigned long long r = i - 1;
        unsigned long long L = l - 1, R = r + 1;
        for (int j = l; j <= r; j++) {
            if ((p[j] - p[L]) * (R - L) != (p[R] - p[L]) * (j - L))
                ans++;
        }
    }
    cout << ans << endl;
}