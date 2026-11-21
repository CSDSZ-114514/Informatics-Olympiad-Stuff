#include <bits/stdc++.h>
using namespace std;
long long t, x[1000005];
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long x1, y1;
    long long d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

int main() {
    cin >> t;
    for (int q = 1; q <= t;q++) {
        long long w, n, d;
        cin >> w >> n >> d;
        for (int i = 1; i <= w; i++) {
            cin >> x[i];
        }
        long long ans2 = 0;
        for (int i = 1; i <= w / 2; i++) {
            long long x1 = x[i], x2 = x[w - i + 1];
            long long p = 0, z = 0;
            long long dd = exgcd(d, n, p, z);
            //cout << (x2 - x1)<<"   ";
            if ((x2 - x1) % dd == 0) {
                p *= ((x2 - x1) / dd);
                z *= ((x2 - x1) / dd);
            }else{
                cout << "Case #" << q << ": " << "IMPOSSIBLE"<<endl;
                goto aaa;
            }
            long long minp = (p % (n / dd) + n / dd) % (n / dd);
            ans2 += min(abs(minp),abs(minp-n/dd));
        }
        cout << "Case #" << q << ": " << ans2<<endl;
        aaa:
            w = 1;
    }
}