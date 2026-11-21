#include <bits/stdc++.h>
using namespace std;
long long  n, m, l;
__int128 exgcd(__int128 a, __int128 b, __int128 &x, __int128 &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    __int128 x1, y1;
    __int128 d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

__int128 qpow(__int128 a, __int128 b, __int128 m) {
    __int128 ans = 1;
    while (b) {
        if (b % 2 == 1) {
            ans = ans * a % m;
        }
        b /= 2;
        a = a * a % m;
    }
    return ans;
}
int main() {
    cin >> n >> m >> l;
    __int128 x = 0, y = 0;
    __int128 d = exgcd(qpow(2, m, n + 1), n + 1, x, y);
    cout << (((x * (l / d) % (n + 1) + n + 1) % (n + 1)==0)?n:(long long)((x * (l / d) % (n + 1) + n + 1) % (n + 1)));
}