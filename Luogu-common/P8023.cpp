#include <bits/stdc++.h>
using namespace std;
const unsigned long long P = 131;
long long n, a[3000005], m, b[3000005];
unsigned long long ha[3000005], hb[3000005], p[3000005];
void initP(int len) {
    p[0] = 1;
    for (int i = 1; i <= len; i++) {
        p[i] = p[i - 1] * P;
    }
}
unsigned long long getha(long long l, long long r) { return ha[r] - ha[l - 1] * p[r - l + 1]; }
unsigned long long gethb(long long l, long long r) { return hb[r] - hb[l - 1] * p[r - l + 1]; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ha[i] = ha[i - 1] * P + a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        hb[i] = hb[i - 1] * P + b[i];
    }
    b[m + 1] = 1e18+1;
    a[n + 1] = 1e18;
    initP(max(n, m) + 1);
    long long i = 1, j = 1;
    while (i <= n && j <= m) {
        if (a[i] < b[j]) {
            cout << a[i] << " ";
            i++;
        } else if (a[i] > b[j]) {
            cout << b[j] << " ";
            j++;
        } else {
            long long l = 1;
            long long r = min(n - i + 1, m - j + 1);
            long long mid = (l + r) >> 1;
            while (l < r) {
                mid = (l + r + 1) >> 1;   
                if (getha(i, i + mid - 1) == gethb(j, j + mid - 1)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (a[i + l] >= b[j + l]) {
                cout << b[j] << " ";
                j++;
            } else if (a[i + l] < b[j + l]) {
                cout << a[i] << " ";
                i++;
            }
        }
    }
    if (i <= n) {
        for (; i <= n; i++) {
            cout << a[i] << " ";
        }
    }
    if (j <= m) {
        for (; j <= m; j++) {
            cout << b[j] << " ";
        }
    }
}