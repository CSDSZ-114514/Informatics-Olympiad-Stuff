#include <bits/stdc++.h>
using namespace std;
long long n, l, c[1000005], qzh[100005], a[100005], b[100005], f[1000005], q[1000005];
double x(long long i) { return b[i]; }
double y(long long i) { return f[i] + b[i] * b[i]; }
double slope(double i, double j) { return 1.0 * (y(j) - y(i)) / (x(j) - x(i)); }
int main() {
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        qzh[i] = qzh[i - 1] + c[i];
        b[i] = qzh[i] + i;
        a[i] = qzh[i] + i - l - 1;
    }
    int h = 1, t = 0;
    for (int i = 1; i <= n; i++) {
        while (h < t && slope(i - 1, q[t]) <= slope(q[t], q[t - 1])) {
            t--;
        }
        q[++t] = i - 1;
        while (h < t && slope(q[h + 1], q[h]) <= 2 * a[i]) {
            h++;
        }
        int j = q[h];
        f[i] = f[j] + (a[i] - b[j]) * (a[i] - b[j]);
    }
    cout << f[n];
    return 0;
}