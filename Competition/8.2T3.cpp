#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long xs[100005], ys[100005];
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        long long x, y;
        cin >> x >> y;
        xs[i] = x;
        ys[i] = y;
    }
    sort(xs + 1, xs + 1 + k);
    long long rcnt = 0, ccnt = 0;
    for (int i = 0; i < k;) {
        long long j = i;
        while (j < k && xs[j] == xs[i])
            ++j;
        if ((j - i) & 1)
            ++rcnt;
        i = j;
    }

    sort(ys + 1, ys + 1 + k);
    for (int i = 0; i < k;) {
        long long j = i;
        while (j < k && ys[j] == ys[i])
            ++j;
        if ((j - i) & 1)
            ++ccnt;
        i = j;
    }
    cout << n * m - max(rcnt, ccnt);
    return 0;
}